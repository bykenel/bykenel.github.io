import "./Dice.css";
import Die from "./Die";

export default function Dice({ dice, color }) {
  return (
    <section className="Dice">
      {dice.map((val, i) => (
        <Die key={i} val={val} color={color} />
      ))}
    </section>
  );
}
