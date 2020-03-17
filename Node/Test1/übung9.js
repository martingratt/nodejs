var fs = require('fs');

fs.rename('mynewfile3.txt', 'myverynewfile3.txt', function (err) {
    if (err) throw err;
});