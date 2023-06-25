import React from 'react';
import { Link } from 'react-router-dom';
import './AuthForm.scss';
import Button from '../common/Button';

const textMap = {
  login: 'Login',
  register: 'Sign Up',
};

const AuthForm = ({ type, form, onChange, onSubmit, error }) => {
  const text = textMap[type];
  return (
    <div className="AuthFormBlock">
      <h3>{text}</h3>
      <form>
        <input
          className="StyledInput"
          autoComplete="username"
          name="username"
          placeholder="Username"
        />
        <input
          className="StyledInput"
          autoComplete="new-password"
          name="password"
          placeholder="Password"
          type="password"
        />
        {type === 'register' && (
          <input
            className="StyledInput"
            autoComplete="new-password"
            name="password"
            placeholder="Confirm Password"
            type="password"
          />
        )}
        {type === 'login' ? (
          <Button className="cyan fullWidth">Continue</Button>
        ) : (
          <Button className="cyan fullWidth">Create an account</Button>
        )}
      </form>
      <div className="Footer">
        {type === 'login' ? (
          <Link to="/register">Sign up</Link>
        ) : (
          <Link to="/login">Login</Link>
        )}
      </div>
    </div>
  );
};

export default AuthForm;
