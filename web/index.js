let express = require('express');
let app = express();
let bodyParser = require('body-parser');
let fs = require('fs');

const port = process.env.PORT || 8080

app.engine('html', require('ejs').renderFile);
app.set('view engine', 'ejs');

app.use(express.static('public'));
app.use(bodyParser.urlencoded({extend: false}));
app.use(bodyParser.json());

app.get('/', (req, resp) => {

    let users = [];
    
    fs.readdir("../", (err, files) => {
        if (err) {
            throw err;
        }
        files.forEach(file => {

            if(file.split('.')[1] === "lastest") {
                let user = fs.readFileSync("../" + file, "utf-8");
                user = user.split(',')
                if(user[3] == 0) user[3] = "Online";
                else user[3] = "Offline";
                users.push(user)
            }
        });
        
        resp.render('index', {users:users});
    });

});

app.listen(port);
