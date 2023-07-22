import { NavLink } from 'react-router-dom';
import styled, {css} from 'styled-components';

const SNavBar = styled.div`
  display : flex;
  flex-direction: row;
  justify-content: space-around;
  border : 1px solid black;
`;

const SButton = styled(NavLink)`
  width : 100px;
  display: flex;
  justify-content: center;
  align-items: center;
  cursor: pointer;
  text-decoration: none;

  color : black;
  background-color: whitesmoke;
  
  a:visited {
    color: inherit;
  }

  &:hover {
    background-color: lightgray; 
  }

  &.active {
    background-color: gray;
  }
`;

export { SButton, SNavBar };