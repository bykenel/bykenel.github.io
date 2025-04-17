let apiKey = localStorage.getItem("crudcrud_api_key") || "";

document.addEventListener("DOMContentLoaded", () => {
  const apiKeyInput = document.getElementById("apiKey");
  if (apiKeyInput) {
    apiKeyInput.value = apiKey;
  }

  if (document.getElementById("characterList")) {
    listCharacters();
  }

  if (document.getElementById("characterForm")) {
    document
      .getElementById("characterForm")
      .addEventListener("submit", addCharacter);
  }

  if (document.getElementById("saveApiKeyBtn")) {
    document
      .getElementById("saveApiKeyBtn")
      .addEventListener("click", saveApiKey);
  }
});

function getApiUrl() {
  apiKey = localStorage.getItem("crudcrud_api_key") || "";
  if (!apiKey) {
    alert("Por favor, insira sua chave da API.");
    return null;
  }
  return `https://crudcrud.com/api/${apiKey}/personagens`;
}

function saveApiKey() {
  const input = document.getElementById("apiKey");
  if (!input) return;

  const newKey = input.value.trim();
  if (newKey) {
    localStorage.setItem("crudcrud_api_key", newKey);
    apiKey = newKey;
    alert("Chave da API salva com sucesso!");
    listCharacters();
  } else {
    alert("Por favor, insira uma chave de API válida.");
  }
}

const baseCharacters = [
  { nome: "Thalion", classe: "Patrulheiro", nivel: 5 },
  { nome: "Morgana", classe: "Feiticeira", nivel: 7 },
  { nome: "Brog Ironfist", classe: "Guerreiro", nivel: 4 },
  { nome: "Elowyn", classe: "Druida", nivel: 6 },
  { nome: "Finn Teel", classe: "Bardo", nivel: 3 },
];

async function populateInitialDatabase() {
  const url = getApiUrl();
  if (!url) return;
  try {
    for (const character of baseCharacters) {
      const response = await fetch(url, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(character),
      });
      if (!response.ok) {
        throw new Error(`Erro ao adicionar ${character.nome}`);
      }
    }
    localStorage.setItem("databasePopulated", "true");
    listCharacters();
  } catch (error) {
    alert("Erro ao popular o banco de dados: " + error.message);
  }
}

async function listCharacters() {
  const url = getApiUrl();
  if (!url) return;

  try {
    const response = await fetch(url);
    if (!response.ok) throw new Error("Erro ao buscar lendas.");

    const characters = await response.json();

    if (characters.length === 0 && !localStorage.getItem("databasePopulated")) {
      await populateInitialDatabase();
      return;
    }

    const listElement = document.getElementById("characterList");
    if (!listElement) return;

    listElement.innerHTML = "";

    characters.forEach((character) => {
      const card = document.createElement("div");
      card.className = "card";

      const name = document.createElement("h3");
      name.textContent = character.nome;

      const classElement = document.createElement("p");
      classElement.textContent = `Classe: ${character.classe}`;

      const level = document.createElement("p");
      level.textContent = `Nível: `;
      const levelSpan = document.createElement("span");
      levelSpan.className = "nivel";
      levelSpan.textContent = character.nivel;
      level.appendChild(levelSpan);

      card.appendChild(name);
      card.appendChild(classElement);
      card.appendChild(level);

      listElement.appendChild(card);
    });
  } catch (error) {
    alert(error.message);
  }
}

async function addCharacter(event) {
  event.preventDefault();

  const url = getApiUrl();
  if (!url) return;

  const name = document.getElementById("nome").value.trim();
  const className = document.getElementById("classe").value.trim();
  const level = parseInt(document.getElementById("nivel").value);

  if (!name || !className || isNaN(level)) {
    alert("Preencha todos os campos corretamente.");
    return;
  }

  const newCharacter = { nome: name, classe: className, nivel: level };

  try {
    const response = await fetch(url, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(newCharacter),
    });
    if (!response.ok) throw new Error("Erro ao adicionar lenda.");

    alert("Lenda criada com sucesso!");
    document.getElementById("characterForm").reset();
    listCharacters();
  } catch (error) {
    alert(error.message);
  }
}
