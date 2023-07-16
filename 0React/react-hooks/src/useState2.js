import { useState, useEffect } from "react";

const Info = () => {
  const [name, setName] = useState("");
  const [comment, setComment] = useState("");
  const [comments, setComments] = useState([]);

  useEffect(() => {
    const savedComments = localStorage.getItem("comments");
    if (savedComments) {
      setComments(JSON.parse(savedComments));
    }
    console.log(localStorage.getItem("comments"));
  }, []);

  useEffect(() => {
    localStorage.setItem("comments", JSON.stringify(comments));
  }, [comments]);

  const handleNameChange = (e) => {
    setName(e.target.value);
  };

  const handleCommentChange = (e) => {
    setComment(e.target.value);
  };

  const handleAddComment = () => {
    const newComment = { name, comment };
    setComments([...comments, newComment]);
    setName("");
    setComment("");
  };

  return (
    <div style={{ marginTop: "40px" }}>
      <b>Comment List</b>
      <p>
        <input
          type="text"
          style={{ width: "50px" }}
          value={name}
          onChange={handleNameChange}
        />{" "}
        <input type="text" value={comment} onChange={handleCommentChange} />
      </p>
      <button onClick={handleAddComment}>Write</button>
      {comments.map((c, index) => (
        <p key={index}>
          {c.name}: {c.comment}
        </p>
      ))}
    </div>
  );
};

export default Info;
