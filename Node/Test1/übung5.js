var fs = require('fs');

fs.open('mynewtextfile2.txt', 'w', function(err, file)
{
    if (err) throw err;
    console.log('saved!');
    
}
);