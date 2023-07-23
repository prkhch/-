import { SNavBar } from "./style";
import Button from "./Button";
import logo from "assets/logo/logo.png";
import { Link, useNavigate } from "react-router-dom";
import { useSelector, useDispatch } from "react-redux";
import { RootState, AppDispatch } from "redux/store";
import { logout } from "redux/user";

const NavBar = () => {
  const { user } = useSelector(({ user }) => ({ user: user.user }));
  const dispatch = useDispatch<AppDispatch>();
  const onLogout = () => {
    dispatch(logout());
  };

  return (
    <SNavBar>
      <Link to="/">
        <img src={logo} alt="logo" style={{ height: 30, marginTop: 4 }} />
      </Link>

      <Button to="/post">게시판</Button>
      <Button to="/mypage">마이페이지</Button>

      {user ? (
        <>
          <Button>{user}</Button>
          <Button onClick={onLogout}>로그아웃</Button>
        </>
      ) : (
        <>
          <Button to="/login">로그인</Button>
          <Button to="/register">회원가입</Button>
        </>
      )}
    </SNavBar>
  );
};

export default NavBar;
