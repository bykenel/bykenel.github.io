import ScoreKeeper from "./ScoreKeeper.jsx";
import "./App.css";

function App() {
  return (
    <div className="App">
      <ScoreKeeper numPlayers={5} target={8} />
    </div>
  );
}

export default App;
