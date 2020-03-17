const path = require('path');
const express = require('express');
const hbs = require('hbs');

const app = express();

//Paths for express
const publicDircertoryPath = path.join(__dirname, '../public');
const viewsPath = path.join(__dirname, '../templates/views');
const partialsPath = path.join(__dirname, '../templates/partials')
//const partialsPath = path.join(__dirname, '../templates/partials');
console.log(partialsPath);

//Setup handlebars engine and views location
app.set('view engine', 'hbs')
app.set('views', viewsPath);
hbs.registerPartials(partialsPath);

// Setup static directory to serve
app.use(express.static(publicDircertoryPath));

app.get('', (req, res) => {
    res.render('index', {
        title: 'Weather App',
        name: 'Martin Gratt'
    })
})

app.get('/about', (req, res) => {
    res.render('about', {
        title: 'About me',
        name: 'Martin Gratt'  
    })
})

app.get('/help', (req, res) => {
    res.render('help', {
        name: 'Martin Gratt',
        message: 'How can I help you?'
    })
})

app.get('*', function(req, res){
    res.status(404);
    res.sendFile(publicDircertoryPath + '/404.html');
  });

app.listen(3000, ()=> {
    console.log('Server running');
})