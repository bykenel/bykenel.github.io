import "./Button.css";

export default function Button({ doThis, label = "Click Me" }) {
  return (
    <button className="Button" onClick={doThis}>
      {label}
    </button>
  );
}
