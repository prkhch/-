import logo from "./logo.svg";
import "./App.css";
import { Component } from "react";
import LifeCycleSample from "./LifeCycleSample";

function getRandomColor() {
  return "#" + Math.floor(Math.random() * 16777215).toString(16);
}

class App extends Component {
  state = {
    color: "#000000",
  };

  handleClick = () => {
    this.setState({
      color: getRandomColor(),
    });
  };

  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <button onClick={this.handleClick}>랜덤 색상</button>
          <LifeCycleSample color={this.state.color} />
        </header>
      </div>
    );
  }
}

export default App;
