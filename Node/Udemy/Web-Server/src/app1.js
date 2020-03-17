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
    res.send('<h1>About</h1>')
})

app.get('/weather', (req, res) => {
    res.send([
        {
            forecast: 'rainy',
            location: 'madrid'
        },
        {
            forecast: 'sunny',
            location: 'innsbruck'

        }
    ])
})

app.listen(3000, ()=> 
{
    console.log('Server is up at port 3000');
}
)