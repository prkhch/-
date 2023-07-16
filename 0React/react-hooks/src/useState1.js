import { useState } from "react";

const Twotwo = () => {
  const [value, setValue] = useState(1);

  return (
    <div>
      <p>{value}</p>
      <button onClick={() => setValue(value * 2)}>× 2</button>
      <button onClick={() => setValue(value / 2)}>÷ 2</button>
    </div>
  );
};

export default Twotwo;
