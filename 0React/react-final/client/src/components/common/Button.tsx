import { SButton } from "./style";
import { ReactNode } from "react";
import { useNavigate, useLocation } from "react-router-dom";

interface ButtonProps {
  to?: string;
  children: ReactNode;
  onClick?: () => void;
}

const Button = ({ to, children, onClick }: ButtonProps) => {
  const navigate = useNavigate();
  const location = useLocation();
  const isActive = location.pathname === to;

  const handleClick = () => {
    if (to) {
      navigate(to);
    }
    if (onClick) {
      onClick();
    }
  };

  return (
    <SButton onClick={handleClick} className={isActive ? "active" : ""}>
      {children}
    </SButton>
  );
};

export default Button;
