// 원래 브라우저에서 모듈을 불러오는 기능은 없다. Node.js에 지원하..
import './App.css';
// import { Component } from 'react';
import MyComponent from './MyComponents';

const App = () => {
  return (
    <>
      <MyComponent name="React" favoriteNumber={1}>
        App에서 왔어요.
      </MyComponent>
    </>
  );
};

// class App extends Component {
//   // 클래스형 컴포넌트
//   render() {
//     const name = 'react';
//     return <div className="react">{name}</div>;
//   }
// }

// 함수 컴포넌트
// 이건 HTML도 문자열 템플릿도 아닌 JSX.d
// function App() {
// 자바스크립트 표현식 가능
// const name = undefined;
// return <div>{ name || '이름을 다시 입력하세요.'}</div>
// const name =     '리액트'
// const style = {
//   backgroundColor : 'black',
//   color : 'aqua',
//   fontSize : '48px',
//   fontWeight : 'bold',
//   padding : 16
// };
// return <div style={style}>{name}</div>
// const name = '리액트';
// return <div className="react">{name}</div>;
//   const name = '리액트';
//   return (
//     <>
//       <div className='react'>{name}</div>
//       <input/>
//       {/* 주석다는법 */}
//       {/* 루트 요소 안에서 주석 */}
//       // 이건 주석이 아니야
//       /* 이것도 */
//     </>
//   );
// }
// const name = "이상 한 들여 쓰 기";
// return (
//   <>
//     <div className="react">{name}</div>
//     <h1>들여쓰기</h1>
//     <h2>이상 </h2>
//     <p>할때는</p>
//     <p>f1 = &gt; code-prettier</p>
//   </>
// );
// }

export default App;
