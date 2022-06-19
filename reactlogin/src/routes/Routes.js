import React from 'react';
import {BrowserRouter, Switch, Route} from 'react-router-dom';
import Login from '../pages/Login';
import Menu from '../pages/Menu';
import Register from '../pages/Register';
import fileDownloader from '../pages/fileDownloader';
import fileUploader from '../pages/fileUploader';
import App from '../pages/App';
import FileUpload from '../pages/FileUpload';

function Routes() {
  return (
    <BrowserRouter>
      <Switch>
        <Route exact path="/" component={Login}/>
        <Route exact path="/menu" component={Menu}/>
        <Route exact path="/register" component={Register}/>
        <Route exact path="/App" component={App}/>
        <Route exact path="/download" component={fileDownloader}/>
        <Route exact path="/upload" component={fileUploader}/>
      </Switch>
    </BrowserRouter>
    
  );
}

export default Routes;