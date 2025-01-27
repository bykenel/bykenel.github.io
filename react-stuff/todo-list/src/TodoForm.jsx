import { useState } from "react";
import TextField from "@mui/material/TextField";
import ListItem from "@mui/material/ListItem";
import { InputAdornment } from "@mui/material";
import { IconButton } from "@mui/material";
import { Create } from "@mui/icons-material";

export default function TodoForm({ addItem }) {
  const [text, setText] = useState("");
  const handleChange = (evt) => {
    setText(evt.target.value);
  };

  const handleSubmit = (evt) => {
    evt.preventDefault();
    addItem(text);
    setText("");
  };

  return (
    <ListItem>
      <form onSubmit={handleSubmit}>
        <TextField
          id="standard-basic"
          label="New Task"
          variant="standard"
          onChange={handleChange}
          value={text}
          InputProps={{
            endAdornment: (
              <InputAdornment position="end">
                <IconButton aria-label={"create todo"} edge="end" type="submit">
                  <Create />
                </IconButton>
              </InputAdornment>
            ),
          }}
        />
      </form>
    </ListItem>
  );
}
