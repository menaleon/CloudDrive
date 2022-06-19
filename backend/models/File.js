const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const userSchema = new Schema({
    _id: mongoose.Schema.Types.ObjectId,
    name: { type: String },
    path: { type: String },
}, {
    collection: 'files'
})

module.exports = mongoose.model('File', userSchema)