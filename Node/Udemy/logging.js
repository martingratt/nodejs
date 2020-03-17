const chalk = require('chalk');

function error (a, b) {

    console.log(chalk.red("This is an error!"));

}
function warning () {
    console.log(chalk.yellow("This is a warning!"));

}

module.exports.error = error();

module.exports.warning = warning();
