import React from 'react';
import logo from './unnamed.jpg';
import './App.css';

function App() {
  return (
    <div className="App">
      {hello}
      {getAge}
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <br/>
        <br/>
        <p>
          테스트입니다.
        </p>
      </header>
    </div>
  );
}
// ============================================

function formatName(user) { // 유저의 이름과 나이 형식으로 반환
  return user.name + ' ' + user.age;
}
// ============================================

function checkAge(user) {
  if(user.age === 27) { // 나이가 27이면 출력
    return <>27입니다.</>
  }
  return <>27이 아니다.</>
}
// ============================================

const user = { // 객체
  name : "React",
  age : 27
};
// ============================================

const hello = (
  <h1>
    안녕, {formatName(user)}!
  </h1>
);
// ============================================

const getAge = (<h1>{checkAge(user)}</h1>);
// ============================================

export default App;