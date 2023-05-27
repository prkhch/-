// 원래 브라우저에서 모듈을 불러오는 기능은 없다. Node.js에 지원하..
import logo from './logo.svg';
import './App.css';

// 함수 컴포넌트
// 이건 HTML도 문자열 템플릿도 아닌 JSX.
function App() { 
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
