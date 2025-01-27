import "./Die.css";

export default function Die({ val, color = "slategrey" }) {
  return (
    <div className="Die" style={{ backgroundColor: color }}>
      {val}
    </div>
  );
}
