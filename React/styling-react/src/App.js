import { Component } from "react";
import logo from "./logo.svg";
import "./App.css";
import SassComponent from "./SassComponent";

class App extends Component {
  render() {
    return (
      <div className="App">
        <SassComponent />
        <header>
          <img src={logo} className="logo" alt="logo" />
          <p>
            Edit <code>src/App.js</code> and save to reload.
          </p>
        </header>
      </div>
    );
  }
}

export default App;
