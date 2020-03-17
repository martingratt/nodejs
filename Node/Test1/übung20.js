var mysql = require("mysql");
var sql = "SELECT * FROM customers where address = 'Highway 37'";

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
        console.log(result);
    })
}
);