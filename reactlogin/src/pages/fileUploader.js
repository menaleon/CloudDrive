import React, { Component } from 'react';
import '../css/fileUploader.css';
import 'bootstrap/dist/css/bootstrap.min.css'
import Cookies from 'universal-cookie'

const cookies = new Cookies();

class fileUploader extends Component {
    state = {
        form: {
            username: ''
        }
    }

    constructor(props) {
        super(props);
        this.state = {
          imageURL: '',
        };
        this.handleUploadFile = this.handleUploadFile.bind(this);
    }
    
    handleUploadFile(ev) {
        //ev.preventDefault();
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
    }

    handleChange = async e => {
        await this.setState({
            form: {
                ...this.state.form,
                [e.target.name]: e.target.value
            }
        });
        //console.log(this.state.form);
    }

    render() {
        return (
            <div className="containerPrincipal">
                <label>Nombre archivo: </label>
                        <br />
                        <input ref={(ref) => { this.uploadInput = ref; }} type="file" className="form-control"/>
                        <button className="btn btn-primary" onClick={() => this.handleUploadFile()}>Subir archivo</button>
            </div>
        );
    }
}

export default fileUploader;