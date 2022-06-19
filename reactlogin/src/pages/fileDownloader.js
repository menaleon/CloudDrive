import React, { Component } from 'react';
import '../css/fileDownloader.css';
import 'bootstrap/dist/css/bootstrap.min.css'
import Cookies from 'universal-cookie'

const cookies = new Cookies();

class fileDownloader extends Component {
    state = {
        form: {
            username: ''
        }
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
                <label>Nomber de archivo: </label>
                        <br />
                        <input
                            type="text"
                            className="form-control"
                            name="username"
                            onChange={this.handleChange}
                        />                        
                        <button className="btn btn-primary" onClick={() => this.download()}>Descargar archivo</button>
            </div>
        );
    }
}

export default fileDownloader;