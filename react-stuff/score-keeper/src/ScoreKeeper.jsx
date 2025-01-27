import { useState } from "react";

export default function ScoreKeeper({ numPlayers = 3, target = 5 }) {
  const [scores, setScores] = useState(new Array(numPlayers).fill(0));
  const [hasWinner, setHasWinner] = useState(false);

  const addScore = (i) => {
    setScores((prevScore) => {
      if (hasWinner || prevScore[i] >= target) {
        return prevScore;
      }

      const copy = [...prevScore];
      copy[i] += 1;

      if (copy[i] >= target) {
        setHasWinner(true);
      }

      return copy;
    });
  };

  const reset = () => {
    setScores(new Array(numPlayers).fill(0));
    setHasWinner(false);
  };

  return (
    <div>
      <h1>Score Keeper</h1>
      <ul>
        {scores.map((score, i) => {
          return (
            <li key={i}>
              {score >= target && "WINNER 🏆! "}
              Player {i + 1}: {score} ---
              <button onClick={() => addScore(i)}>+1</button>
            </li>
          );
        })}
      </ul>
      <button onClick={reset}>Reset</button>
    </div>
  );
}
