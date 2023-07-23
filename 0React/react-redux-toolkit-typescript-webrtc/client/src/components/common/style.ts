import styled, {css} from 'styled-components';

const SPageLayout = styled.div`
  display: flex;
  flex-direction: column;
  height: 100vh;
  background-color: white;
`;

const SGlobal = styled.div`
  display: flex;
  flex-direction: column;
  /* justify-content: center; */
  align-items: center;
  flex-grow: 1;
  margin-top: 20px;
  `
const SNavBar = styled.nav`
  display : flex;
  flex-direction: row;
  justify-content: space-around;
  border : 1px solid black;
`;

const SButton = styled.button`
  border: none;
  border-radius: 4px;
  font-size: 1rem;
  font-weight: bold;
  padding: 0.25rem 1rem;
  color: black;
  outline: none;
  cursor: pointer;
  background-color: white;
  
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

const SInput = styled.input`
  font-size: 1rem;
  border: none;
  border-bottom: 1px solid lightgray;
  padding-bottom: 0.5rem;
  outline: none;
  width: 100%;
  &:focus {
    color: $oc-teal-7;
    border-bottom: 1px solid gray;
  }
  & + & {
    margin-top: 1rem;
  }
`;

export { SPageLayout, SGlobal, SNavBar, SButton, SInput, };