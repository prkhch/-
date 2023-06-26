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
  // console.log('form : ', form);
  return (
    <div className="AuthFormBlock">
      <h3>{text}</h3>
      <form onSubmit={onSubmit}>
        <input
          className="StyledInput"
          autoComplete="username"
          name="username"
          placeholder="Username"
          onChange={onChange}
          value={form.username}
        />
        <input
          className="StyledInput"
          autoComplete="new-password"
          name="password"
          placeholder="Password"
          type="password"
          onChange={onChange}
          value={form.password}
        />
        {type === 'register' && (
          <input
            className="StyledInput"
            autoComplete="new-password"
            name="passwordConfirm"
            placeholder="Confirm Password"
            type="password"
            onChange={onChange}
            value={form.passwordConfirm}
          />
        )}
        {error && <div className="ErrorMessage">{error}</div>}
        {type === 'login' ? (
          <Button className="cyan fullWidth mt">Continue</Button>
        ) : (
          <Button className="cyan fullWidth mt">Create an account</Button>
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
