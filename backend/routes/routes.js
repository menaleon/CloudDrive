let express = require('express'),
    multer = require('multer'),
    mongoose = require('mongoose'),
    uuidv4 = require('uuid'),
    router = express.Router();

const DIR = './public/';

const storage = multer.diskStorage({
    destination: (req, file, cb) => {
        cb(null, DIR);
    },
    filename: (req, file, cb) => {
        const fileName = file.originalname.toLowerCase().split(' ').join('-');
        cb(null, uuidv4() + '-' + fileName)
    }
});

var upload = multer({
    storage: storage,
    fileFilter: (req, file, cb) => {
        cb(null, true);
    }
});

// User model
let User = require('../models/User');
let File = require('../models/File');

router.post('/user-add', (req, res, next) => {
    const user = new User({
        _id: new mongoose.Types.ObjectId(),
        apellido_paterno: req.body.apellido_paterno,
        apellido_materno: req.body.apellido_materno,
        nombre:req.body.nombre,
        username: req.body.username,
        password: req.body.password,
    });
    user.save().then(result => {
        console.log(result);
        res.status(201).json({
            message: "User registered successfully!",
            userCreated: {
                _id: result._id
            }
        })
    }).catch(err => {
        console.log(err),
            res.status(500).json({
                error: err
            });
    })
})

router.get("/user-list", (req, res, next) => {
    User.find().then(data => {
        res.status(200).json({
            message: "User list retrieved successfully!",
            users: data
        });
    });
});

//router.post('/file-upload', upload.single('path'), (req, res, next) => {
router.post('/file-upload', (req, res, next) => {
    const newpath = __dirname + "/../public/";
    console.log(newpath);
    const reqfile = req.files.file;
    const filename = reqfile.name;
    //const url = req.protocol + '://' + req.get('host')
    const file = new File({
        _id: new mongoose.Types.ObjectId(),
        name: filename,
        path: newpath,
    });

    reqfile.mv(newpath+filename, (err) => {
    });

    file.save().then(result => {
        res.status(201).json({
            message: "File uploaded successfully!",
            fileCreated: {
                _id: result._id,
                name: result.name,
                path: result.path,
            }
        })
    }).catch(err => {
        console.log(err),
            res.status(500).json({
                error: err
            });
    })
})

router.get("/file-list", (req, res, next) => {
    File.find().then(data => {
        res.status(200).json({
            message: "File list retrieved successfully!",
            files: data
        });
    });
});

//router.delete("/file-delete", (req, res, next) => {
//    File.deleteOne().then(data => {
//        res.status(200).json({
//            message: "File deleted successfully!",
//            files: data
//        });
//    });
//});

module.exports = router;