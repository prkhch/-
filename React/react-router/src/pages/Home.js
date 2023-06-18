import logo from "../logo.svg";
import { Link } from "react-router-dom";

const Home = () => {
  return (
    <div>
      <img src={logo} className="App-logo" alt="logo" />
      <h1>홈</h1>
      <p>홈페이지</p>
      <ul>
        <li>
          <Link to="/about">about</Link>
        </li>
        <li>
          <Link to="/profiles/obj1">username:obj1</Link>
        </li>
        <li>
          <Link to="/profiles/obj2">username:obj2</Link>
        </li>
        <li>
          <Link to="/profiles/void">존재하지 않는 사용자</Link>
        </li>
      </ul>
    </div>
  );
};

export default Home;
