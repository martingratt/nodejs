var express = require('express');

const app = express();

app.get('', (req, res) =>
{
    res.send('Hello express by Martin!');
}
)

app.get('/help', (req, res) =>
{
    res.send('This is the help page')
})

app.get('/about', (req, res) => {
    res.sendFile('C:/Users/PC/Git/Node/Udemy/Web-Server/public/about.html');
})

app.get('/weather', (req, res) => {
    res.sendFile('C:/Users/PC/Git/Node/Udemy/Web-Server/public/weather.html');
})

app.listen(3000, ()=> 
{
    console.log('Server is up at port 3000');
}
)