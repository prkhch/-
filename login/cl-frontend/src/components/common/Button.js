import React from 'react';
import './StyledButton.scss';

const Button = ({ className, ...rest }) => (
  <button className={`StyledButton ${className}`} {...rest} />
);

export default Button;
