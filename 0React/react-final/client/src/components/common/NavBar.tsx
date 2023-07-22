import { SNavBar } from "./style";
import Button from "./Button";
import { MicIcon } from './Icons';
import logo from '../../assets/logo.png';

const NavBar = () => {
  return (
    <SNavBar>
      <Button to="/">
        <img src={logo} alt="logo" style={{ width: '100%', height: '100%', objectFit: 'contain' }}/>
      </Button>
      <Button to="/post">게시판</Button>
      <Button to="/login">로그인</Button>
      <Button to="/register"><MicIcon/>회원가입</Button>
    </SNavBar>
  );
};

export default NavBar;