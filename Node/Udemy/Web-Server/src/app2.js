const path = require('path');
const express = require('express');
const publicDircertoryPath = path.join(__dirname, '../public');

console.log(__dirname);
console.log(path.join(__dirname, '../public'));

const app = express();

app.use(express.static(publicDircertoryPath));

app.get('*', function(req, res){
    res.status(404);
    res.sendFile(publicDircertoryPath + '/404.html');
  });

/*
app.get('/about', (req, res) => {
    res.sendFile(publicDircertoryPath + '/about.html');
})

app.get('/help', (req, res) => {
    res.sendFile(publicDircertoryPath + '/help.html');
})
*/

app.listen(3000, ()=> {
    console.log('Server running');
})