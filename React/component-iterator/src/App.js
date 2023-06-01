import logo from "./logo.svg";
import "./App.css";
import IterationSample from "./IterationSample";

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <IterationSample />
      </header>
    </div>
  );
}

export default App;
