import React, { Component } from 'react';
import '../css/Login.css';
import 'bootstrap/dist/css/bootstrap.min.css'
import axios from 'axios';
import md5 from 'md5';
import Cookies from 'universal-cookie'

const baseURL = "http://localhost:3001/usuarios";
const cookies = new Cookies();

class Register extends Component {
    state = {
        form: {
            username: '',
            password: ''
        }
    }

    handleChange = async e => {
        await this.setState({
            form: {
                ...this.state.form,
                [e.target.name]: e.target.value
            }
        });
        
    }
    guardar = async () => {
        window.location.href = "./"; //Aqui iría la logica para guardar el nuevo usuario
    }
    volver = async () => {
        window.location.href = "./";
    }
    componentDidMount() {
        if (cookies.get('username')) {
            window.location.href = "./menu";
        }
    }

    render() {
        return (
            <div className="containerPrincipal">
                <div className="containerSecundario">
                    <div className="form-group">
                        <label>Usuario: </label>
                        <br />
                        <input
                            type="text"
                            className="form-control"
                            name="username"
                            onChange={this.handleChange}
                        />
                        <br />
                        <label>Contraseña: </label>
                        <br />
                        <input
                            type="password"
                            className="form-control"
                            name="password"
                            onChange={this.handleChange}
                        />
                        <br />
                        <button className="btn btn-primary" onClick={() => this.guardar()}>Guardar</button>
                        <button className="btn btn-primary" onClick={() => this.volver()}>Volver a inicio de sesión</button>
                    </div>
                </div>
            </div>
        );
    }
}

export default Register;