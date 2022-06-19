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
                        <input
                            type="text"
                            className="form-control"
                            name="username"
                            onChange={this.handleChange}
                        />                        
                        <button className="btn btn-primary" onClick={() => this.upload()}>Subir archivo</button>
            </div>
        );
    }
}

export default fileUploader;