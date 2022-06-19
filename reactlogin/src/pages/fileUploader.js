import React, { Component } from 'react';
import '../css/fileUploader.css';
import Select from 'react-select';
import 'bootstrap/dist/css/bootstrap.min.css'
import Cookies from 'universal-cookie'

const cookies = new Cookies();

const opciones = [
    { label: "Ninguno", value: 0 },
    { label: "LZ77", value: 1 },
    { label: "LZ88", value: 2 },
    { label: "HUFFMAN", value: 3 },
    { label: "LZW", value: 4 },
  ];

class fileUploader extends Component {
    constructor(props) {
        super(props);
        this.state = {
            value : 0,
        }
        this.updateSelect = this.updateSelect.bind(this);
        this.handleUploadFile = this.handleUploadFile.bind(this);
    }

    updateSelect(option){
        this.setState({value: option});
    }

    handleUploadFile() {
        const data = new FormData();
        data.append('file', this.uploadInput.files[0]);
        fetch('http://localhost:3002/api/file-upload', {
            method: 'POST',
            body: data,
        }).then((response) => {
            response.json().then((body) => {
                this.setState({ imageURL: `http://localhost:3002/${body.file}` });
            });
        });
        window.location.href = "./menu";
    }

    render() {
        return (
            <div className="containerPrincipal">
                <label>Nombre archivo: </label>
                        <br />
                        <input ref={(ref) => { this.uploadInput = ref; }} type="file" className="form-control"/>
                        <Select options={opciones} onChange={this.updateSelect} placeholder="Modo compresion:"/>
                        <button className="btn btn-primary" onClick={() => this.handleUploadFile()}>Subir archivo</button>
            </div>
        );
    }
}

export default fileUploader;