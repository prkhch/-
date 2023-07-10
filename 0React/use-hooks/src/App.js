import "./App.css";
import Average from "./Average";
import Counter from "./Counter";
import Info from "./Info";
import { useState } from "react";

const App = () => {
  const [visible, setVisible] = useState(false);
  return (
    <div>
      <button
        onClick={() => {
          setVisible(!visible);
        }}
      >
        {visible ? "숨기기" : "보이기"}
      </button>
      {visible && <Info />}
      <hr />
      <Counter />
      <hr />
      <Average />
    </div>
  );
};

export default App;
