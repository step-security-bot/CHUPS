let express = require('express');
let app = express();
let bodyParser = require('body-parser');

const port = process.env.PORT || 80

app.engine('html', require('ejs').renderFile);
app.set('view engine', 'ejs');

app.use(express.static('public'));
app.use(bodyParser.urlencoded({extend: false}));
app.use(bodyParser.json());

app.get('/', (req, resp) => {
    resp.render('index');
});

let getLastestFiles = () => {
    fs.readdir("../logs/", (err, files) => {
        if (err) {
            throw err;
        }
    
        files = []
        files.forEach(file => {
            file = file.split('.');
            if(file[file.length -1] == "lastest") {
                files.append(file);            }
        });
    });

    return files;
};

app.listen(port)
