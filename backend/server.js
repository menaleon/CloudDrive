const express = require("express");
const fileupload = require("express-fileupload");
const cors = require("cors");
//const cookieParser = require('cookie-parser');
const path = require('path');
const mongoose = require('mongoose');
const dbConfig = require('./data/db');
const bodyParser = require('body-parser');
const api = require('./routes/routes');

// MongoDB Configuration
mongoose.Promise = global.Promise;
mongoose.connect(dbConfig.db, {
    useNewUrlParser: true
}).then(() => {
    console.log('Database sucessfully connected')
},
    error => {
        console.log('Database could not be connected: ' + error)
    }
)
 
const app = express();

app.use(cors());
app.use(fileupload());
app.use(express.static("files"));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use('/api', api)

app.post("/upload", (req, res) => {
  const newpath = __dirname + "/public/";
  const file = req.files.file;
  const filename = file.name;
  file.mv(newpath+filename, (err) => {
    if (err) {
      res.status(500).send({ message: "File upload failed", code: 500 });
    }
    res.status(200).send({ message: "File Uploaded", code: 200 });
  });
});


app.listen(3002, () => {
  console.log("Server running successfully on 3002");
});