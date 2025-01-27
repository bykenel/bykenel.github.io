import { useState, useEffect } from "react";
import "./QuoteFetcher.css";
const RANDOM_QUOTE_URL = "https://inspo-quotes-api.herokuapp.com/quotes/random";

export default function QuoteFetcher() {
  const [quote, setQuote] = useState({
    text: "",
    author: "",
    isLoading: false,
  });
  useEffect(() => {
    fetchQuote();
  }, []);

  async function fetchQuote() {
    const response = await fetch(RANDOM_QUOTE_URL);
    const jsonResponse = await response.json();
    const randomQuote = jsonResponse.quote;
    setQuote(randomQuote);
    quote.isLoading = true;
  }

  return (
    <div>
      <button onClick={fetchQuote}>Get Quote</button>
      <h1>{quote.text}</h1>
      <h4>{quote.author}</h4>
      <p className="Loader" style={{ opacity: quote.isLoading ? 1 : 0 }}>
        Loading...
      </p>
    </div>
  );
}
