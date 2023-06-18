import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import App from "./App";
import { BrowserRouter } from "react-router-dom";

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  // 리액트 라우터 적용
  <BrowserRouter>
    <App />
  </BrowserRouter>
);
