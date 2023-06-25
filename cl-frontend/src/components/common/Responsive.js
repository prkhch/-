import React from 'react';
import './Responsive.scss';

const Responsive = ({ children, ...rest }) => {
  return (
    <div className="ResponsiveBlock" {...rest}>
      {children}
    </div>
  );
};

export default Responsive;
