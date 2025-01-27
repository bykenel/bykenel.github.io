import "./App.css";
import ColorBoxGrid from "./ColorBoxGrid";

const colors = [
  "red",
  "purple",
  "green",
  "orange",
  "grey",
  "blue",
  "yellow",
  "pink",
  "cyan",
  "brown",
  "teal",
  "magenta",
];

function App() {
  return (
    <div className="App">
      <ColorBoxGrid colors={colors} />
    </div>
  );
}

export default App;
