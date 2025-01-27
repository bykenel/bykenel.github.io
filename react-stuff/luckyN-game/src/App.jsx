import "./App.css";
import { sum } from "./utils.js";
import LuckyN from "./LuckyN";

function lessThan4(dice) {
  return sum(dice) < 4;
}

function allSameValue(dice) {
  return dice.every((v) => v === dice[0]);
}

function App() {
  return (
    <div className="App">
      <h1>Lucky N</h1>
      <LuckyN winCheck={lessThan4} title="Roll less than 4!" />
      <LuckyN winCheck={allSameValue} title="Roll the same!" />
    </div>
  );
}

export default App;
