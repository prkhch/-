import React from 'react';
import { Link } from 'react-router-dom';
import './AuthTemplate.scss';

const AuthTemplate = ({ children }) => {
  return (
    <div className="auth-template">
      <div className="white-box">
        <div className="logo-area">
          <Link to="/">React</Link>
        </div>
        {children}
      </div>
    </div>
  );
};

export default AuthTemplate;
