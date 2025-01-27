import { useState } from "react";
import { CssBaseline } from "@mui/material";
import "./App.css";
import TodoList from "./TodoList";

function App() {
  return (
    <>
      <CssBaseline />

      <TodoList />
    </>
  );
}

export default App;
