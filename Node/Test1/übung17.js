var nodemailer = require('nodemailer');

var transporter = nodemailer.createTransport(
    {
        service: 'gmail',
        auth: {
            user: 'martin.gratt@gmail.com',
            pass: ''
        }
    }
);

var mailOptions = {
    from: 'marting.ratt@gmail.com',
    to: 'martin_gratt@hotmail.com',
    subject: 'Sending Email using Node.js',
    text: 'That was easy!'
};

transporter.sendMail(mailOptions, function(error, info){
    if (error) {
      console.log(error);
    } else {
      console.log('Email sent: ' + info.response);
    }
  });