import { SButton } from "./style";
import { ReactNode} from 'react'

interface ButtonProps {
  to:string;
  children : ReactNode;
}

const Button = ({to, children} : ButtonProps ) => {

  return (
    <SButton to={to} className={({isActive}) => (isActive ? 'active' : undefined)}>
      {children}
    </SButton> 
  )
};

export default Button;