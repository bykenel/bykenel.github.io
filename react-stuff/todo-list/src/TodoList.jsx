import { useState } from "react";
import { useEffect } from "react";
import List from "@mui/material/List";
import TodoItem from "./TodoItem";
import TodoForm from "./TodoForm";
import { Box, Typography } from "@mui/material";

const getInitialData = () => {
  const data = JSON.parse(localStorage.getItem("todos"));
  if (!data)
    return [
      { id: crypto.randomUUID(), text: "Make the to-do app", completed: true },
      { id: crypto.randomUUID(), text: "Explore the app", completed: false },
    ];
  return data;
};

export default function TodoList() {
  const [todos, setTodos] = useState(getInitialData);
  useEffect(() => {
    localStorage.setItem("todos", JSON.stringify(todos));
  }, [todos]);

  const removeTodo = (id) => {
    setTodos((prevTodos) => {
      return prevTodos.filter((i) => i.id !== id);
    });
  };

  const toggleTodo = (id) => {
    setTodos((prevTodos) => {
      return prevTodos.map((todo) => {
        if (todo.id === id) {
          return { ...todo, completed: !todo.completed };
        }
        return todo;
      });
    });
  };

  const addTodo = (text) => {
    setTodos((prevTodos) => {
      return [
        ...prevTodos,
        { text: text, id: crypto.randomUUID(), completed: false },
      ];
    });
  };

  return (
    <Box
      sx={{
        display: "flex",
        justifyContent: "center",
        flexDirection: "column",
        alignItems: "center",
        m: 3,
      }}
    >
      <Typography variant="h3" component="div" sx={{ flexGrow: 1 }}>
        To Do List
      </Typography>
      <List sx={{ width: "100%", maxWidth: 360, bgcolor: "background.paper" }}>
        {todos.map((todo) => (
          <TodoItem
            todo={todo}
            key={todo.id}
            removeItem={() => removeTodo(todo.id)}
            toggleItem={() => toggleTodo(todo.id)}
          />
        ))}
        <TodoForm addItem={addTodo} />
      </List>
    </Box>
  );
}
