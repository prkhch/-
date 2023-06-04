import logo from "./logo.svg";
import "./App.css";
import Counter from "./Counter";
import Info from "./Info";

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <Counter />
        <Info />
      </header>
    </div>
  );
}

export default App;
