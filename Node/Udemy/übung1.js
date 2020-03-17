const fs = require('fs');

var path = 'C:/Users/PC/Git/Node/Udemy/notes.txt';

fs.writeFileSync(path, 'My nam is Martin.');

fs.appendFileSync(path, '\nI like Real Madrid so much');