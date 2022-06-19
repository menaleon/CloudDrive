import React, {useState} from 'react';
import axios from 'axios';

class FileUpload extends React.Component{

  constructor(props) {
    super(props);
    this.state = {
      imageURL: '',
    };
    this.handleUploadFile = this.handleUploadFile.bind(this);
  }

  handleUploadFile(ev) {
    ev.preventDefault();
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
  
  render(){
    return (
      <form onSubmit={this.handleUploadFile}>
        <div>
          <input ref={(ref) => { this.uploadInput = ref; }} type="file" />
        </div>
        <div>
          <button>Upload</button>
        </div>
      </form>
    );
  }
}

export default FileUpload;