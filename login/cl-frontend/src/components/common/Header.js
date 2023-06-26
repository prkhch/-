import React from 'react';
import './Header.scss';
import { Link } from 'react-router-dom';
import Responsive from './Responsive';
import Button from './Button';

const Header = ({ user, onLogout }) => {
  return (
    <>
      <div className="HeaderBlock">
        <Responsive>
          <div className="Wrapper">
            <div className="logo">
              <Link to="/">ColorLector</Link>
            </div>
            {user ? (
              <div className="right">
                <div className="UserInfo">{user.username}</div>
                <Button className="cyan" onClick={onLogout}>
                  Logout
                </Button>
              </div>
            ) : (
              <div className="right">
                <Link to="/login">
                  <Button className="cyan">Login</Button>
                </Link>
              </div>
            )}
          </div>
        </Responsive>
      </div>
      <div className="Spacer" />
    </>
  );
};

export default Header;
