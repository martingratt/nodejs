const chalk = require('chalk');

const logging = require('./logging');

console.log(chalk.yellow('This should be green!'));

console.log(chalk.bgBlue.green('This should be not green!'));
console.log(process.argv[2]);

const command = process.argv[2];
const command = process.argv[3];



if (command == 'add'){
    console.log('Additing new note');
} else {
    console.log('Remove Note');
}
logging.error;
logging.warning;
