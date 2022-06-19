import React, { Component } from 'react';
import '../css/fileDownloader.css';
import 'bootstrap/dist/css/bootstrap.min.css'
import Cookies from 'universal-cookie'

const cookies = new Cookies();

class fileDownloader extends Component {

    constructor(props){
        super(props)
        this.state = {
            fileName : ''
        }
        this.updateInput = this.updateInput.bind(this);
    }

    download (path, filename) {
        const anchor = document.createElement('a');
        anchor.href = path;
        anchor.download = filename;
        document.body.appendChild(anchor);
        anchor.click();
        document.body.removeChild(anchor);
    }

    handleDownloadFile() {
        const data = new FormData();
        const filename = this.state.fileName;
        fetch('http://localhost:3002/api/file/'+filename, {
            method: 'GET'
        }).then((response) => {
            response.json().then((body) => {
                this.download(body.files.path, body.files.name);
            });
        });
        window.location.href = "./menu";
    }

    updateInput(ev){
        this.setState({fileName: ev.target.value});
    }

    render() {
        return (
            <div className="containerPrincipal">
                <label>Nomber de archivo: </label>
                        <br />
                        <input type="text" className="form-control" name="txtFileName" onChange={this.updateInput}/> 
                        <button className="btn btn-primary" onClick={() => this.handleDownloadFile()}>Descargar archivo</button>
            </div>
        );
    }
}

export default fileDownloader;