import fs from 'fs/promises';
import path from 'path';

let descriptors = [];

async function processDir(dirName) {
  const dirContent = await fs.readdir(dirName, { withFileTypes: true });
  for (const item of dirContent) {
    const childPath = path.join(item.parentPath, item.name);
    if (item.isDirectory()) {
      await processDir(childPath)
    } else if (item.isFile()) {
      await processFile(childPath)
    }
  }
}

/**
 * 
 * @param {string} filePath 
 */
function isSource(filePath) {
  if (filePath.endsWith('index.inc')) {
    return false;
  }
  if (filePath.endsWith('.bmi2.inc')) {
    return false;
  }
  if (filePath.endsWith('.basic.inc')) {
    return false;
  }
  if (filePath.endsWith(".inc")) {
    return true;
  }
  return false;
}

function getMinIndex() {
  let res = -1;
  for (const arg of arguments) {
    if (arg < 0) continue;
    if (res < 0) {
      res = arg;
    } else if (arg < res) {
      res = arg;
    }
  }
  return res;
}

/**
 * 
 * @param {string} filePath 
 */
function getFunctionName(filePath) {
  const dotIndex = filePath.lastIndexOf('.');
  const slash1Index = filePath.lastIndexOf('/');
  const slash2Index = filePath.lastIndexOf('\\');
  const slashIndex = getMinIndex(slash1Index, slash2Index);
  return filePath.substring(slashIndex + 1, dotIndex);
}

function isWhitespace(ch) {
  if (ch === '\r') return true;
  if (ch === '\n') return true;
  if (ch === ' ') return true;
  if (ch === '\t') return true;
  return false;
}

function isDigit(ch) {
  return ch >= '0' && ch <= '9';
}


/**
 * 
 * @param {string} filePath 
 */
async function processFile(filePath) {
  if (isSource(filePath)) {
    const content = await fs.readFile(filePath, 'utf8');

    const descriptor = {
      funcName: getFunctionName(filePath),
      summary: '',
      inputs: [],
      outputs: []
    };

    let index = 0;
    const lines = [];
    while (true) {
      const char = content.charAt(index++);
      if (isWhitespace(char)) continue;

      if (char === ';') {
        const crIndex = content.indexOf('\r', index);
        const lfIndex = content.indexOf('\n', index);
        const eolIndex = getMinIndex(crIndex, lfIndex);
        const line = eolIndex >= 0 ? content.substring(index, eolIndex) : content.substring(index);
        index += line.length;
        lines.push(line.trim());
      } else {
        break;
      }
    }
    if (lines.length && lines[0].trim() === '@docs-ignore') {
      return;
    }

    let state = 'start';
    for (const line of lines) {
      switch (state) {
        case 'start':
          if (line.startsWith('input:')) {
            state = 'input';
          } else if (line.startsWith('output:')) {
            state = 'output';
          } else {
            descriptor.summary = `${descriptor.summary}\r\n${line}`.trim();
          }
          break;
        case 'input':
          if (line.startsWith('output:')) {
            state = 'output';
          } else {
            descriptor.inputs.push({
              summary: line
            })
          }
          break;
        case 'output':
          descriptor.outputs.push({
            summary: line
          })
          break;
      }
    }

    descriptors.push(descriptor);
  }
}

await processDir('../src');

/**
 * 
 * @param {string} a 
 * @param {string} b 
 */
function compareFunctionNames(a, b) {
  const aparts = a.split('_');
  const bparts = b.split('_');

  if (aparts.length === bparts.length) {
    for (let index = 0; index < aparts.length; index++) {
      const apart = aparts[index];
      const bpart = bparts[index];
      const adigit = isDigit(apart);
      const bdigit = isDigit(bpart);
      if (adigit !== bdigit) {
        break;
      }
      if (adigit && bdigit) {
        const aval = parseFloat(apart);
        const bval = parseFloat(bpart);
        if (aval > bval) {
          return 1;
        }
        if (aval < bval) {
          return -1;
        }
      } else {
        if (apart > bpart) {
          return 1;
        }
        if (apart < bpart) {
          return -1;
        }
      }
    }
  }
  if (a > b) {
    return 1;
  }
  if (a < b) {
    return -1;
  }
  return 0;
}

descriptors.sort((a, b) => {
  return compareFunctionNames(a.funcName, b.funcName);
});

const keywords = [
  'rax', 'rbx', 'rcx', 'rdx', 'r8', 'r9',
  'ZF', 'CF',
  'bi64', 'bi128', 'bi192', 'bi256', 'bi320', 'bi384', 'bi448', 'bi512', 'bi576', 'bi640', 'bi768', 'bi1024',
  'ECAffinePoint256',
  'ECProjectivePoint256',
  'ECProjectiveMontgomeryPoint256'
];

/**
 * 
 * @param {string} source 
 * @param {string} keyword 
 * @returns {string}
 */
function formatKeyword(source, keyword) {
  let result = '';
  let index = 0;
  while (true) {
    const newIndex = source.indexOf(keyword, index);
    if (newIndex < 0) {
      result += source.substring(index);
      break;
    }
    const nextIndex = newIndex + keyword.length;
    if (nextIndex < source.length) {
      const nextChar = source.charAt(nextIndex);
      if (!isWhitespace(nextChar) && nextChar !== ',') {
        result += source.substring(index, newIndex + keyword.length);
        index = newIndex + keyword.length;
        continue;
      }
    }

    result += source.substring(index, newIndex);
    result += `\`${keyword}\``;
    index = newIndex + keyword.length;
  }

  return result;
}

/**
 * 
 * @param {string} source 
 * @returns {string}
 */
function formatKeywords(source) {
  for (const keyword of keywords) {
    source = formatKeyword(source, keyword);
  }

  return source;
}

const emitEmptySummary = true;
const nameWidth = 70;
const summaryWidth = 80;

function padRight(source, width) {
  while (source.length < width) {
    source += ' ';
  }
  return source;
}

function writeTOC() {
  console.log(`| Name                                                                   | Description                                                                      |
|------------------------------------------------------------------------|----------------------------------------------------------------------------------|`);
  for (const descriptor of descriptors) {
    if (!emitEmptySummary && !descriptor.summary.trim()) {
      continue;
    }

    const summary = formatKeywords(descriptor.summary);
    const nameContent = padRight(`[${descriptor.funcName}](#${descriptor.funcName})`, nameWidth);
    const summaryContent = padRight(summary, summaryWidth);
    console.log(`| ${nameContent} | ${summaryContent} |`);
  }
  console.log(`\r\nTotal ${descriptors.length} functions\r\n`);

}

console.log("# ecc.asm")
console.log('Full list of methods:\r\n');

writeTOC();

for (const descriptor of descriptors) {
  if (!emitEmptySummary && !descriptor.summary.trim()) {
    continue;
  }
  const summary = formatKeywords(descriptor.summary);
  console.log(`## ${descriptor.funcName}\r\n\r\n${summary}\r\n`);
  if (descriptor.inputs.length) {
    console.log('Inputs: \r\n');
    for (const input of descriptor.inputs) {
      var outputSummary = formatKeywords(input.summary);
      console.log(`${outputSummary}\r\n`);
    }
  }
  if (descriptor.outputs.length) {
    console.log('Outputs: \r\n');
    for (const output of descriptor.outputs) {
      var outputSummary = formatKeywords(output.summary);
      console.log(`${outputSummary}\r\n`);
    }
  }
  console.log('\r\n');
}