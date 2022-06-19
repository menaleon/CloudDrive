const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const userSchema = new Schema({
    _id: mongoose.Schema.Types.ObjectId,
    apellido_paterno: {type: String},
    apellido_materno:{type: String},
    nombre:{type: String},
    username:{type: String},
    password:{type: String}
}, {
    collection: 'users'
})

module.exports = mongoose.model('User', userSchema)