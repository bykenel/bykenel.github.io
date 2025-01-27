import { useState } from "react";
import { getRolls } from "./utils.js";
import Dice from "./Dice.jsx";
import Button from "./Button.jsx";

export default function LuckyN({ numDice = 2, winCheck, title = "Lucky!" }) {
  const [dice, setDice] = useState(getRolls(numDice));
  const roll = () => setDice(getRolls(numDice));
  const isWinner = winCheck(dice);

  return (
    <main className="LuckyN">
      <h2>
        {title} {isWinner && "You Win!"}
      </h2>
      <Dice dice={dice} />
      <Button doThis={roll} label="Re-Roll" />
    </main>
  );
}
