import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';

const root = ReactDOM.createRoot(document.getElementById('root'));

function tick() {
  const getTime = (
    <div style={{textAlign: 'center', color:'red', fontSize:'20px'}}>
      <h2>실시간 {new Date().toLocaleTimeString()}</h2>
    </div>
  );
  root.render(
    <React.StrictMode>
    {getTime}
    <App />
  </React.StrictMode>
    )
}

setInterval(tick, 1000);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
