var fs = require('fs');

fs.unlink('mynewtextfile2.txt', function (err){
    if (err) throw err;
    
})