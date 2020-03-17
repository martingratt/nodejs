var mysql = require("mysql");
var sql = "Create Table customers (name Varchar (255) , address VARCHAR(255))";

var con = mysql.createConnection(
    {
        host: "localhost",
        user: "root",
        password: "",
        database: "mydb"
    }
)

con.connect(function(err)
{
    if (err) throw err;
    console.log("Connected");
    con.query(sql, function(err, result){
        if (err) throw err;
        console.log("Table created!");
    })
}
);