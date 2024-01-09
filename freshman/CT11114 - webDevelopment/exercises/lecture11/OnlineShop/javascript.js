// Array of news
var news = [
  {
    title: "Quantum Computing Breakthrough Unveiled",
    description:
      "In a groundbreaking development, researchers at TechHub's Innovation Department have achieved a significant milestone in quantum computing. This breakthrough brings us one step closer to unlocking the immense computing power of quantum systems, potentially revolutionizing various industries. Stay tuned for an in-depth analysis of this cutting-edge advancement.",
    date: "2024-01-01",
  },
  {
    title: "Augmented Reality Glasses Set to Redefine User Experience",
    description:
      "TechHub is excited to announce the upcoming launch of our exclusive augmented reality glasses. Providing an immersive and interactive experience, these AR glasses promise to change the way we perceive and interact with the digital world. Pre-orders will be available soon, so keep an eye out for a sneak peek into the future of augmented reality.",
    date: "2024-01-02",
  },
  // Add more news here
];

// Array of updates
var updates = [
  {
    title: "TechHub App Version 2.0 Now Available!",
    description:
      "We're thrilled to announce the release of TechHub App Version 2.0! Packed with enhanced features, improved performance, and a sleek new interface, this update is designed to elevate your TechHub experience. Download the update now to access exclusive content, personalized recommendations, and seamless navigation.",
    date: "2024-01-03",
  },
  {
    title: "TechHub Partners with Leading AI Startup",
    description:
      "TechHub is proud to announce a strategic partnership with a cutting-edge AI startup. This collaboration aims to integrate advanced artificial intelligence technologies into our products, offering users a smarter and more intuitive tech experience. As we continue to push the boundaries of innovation, stay tuned for exciting developments arising from this dynamic partnership.    ",
    date: "2024-01-04",
  },
  // Add more updates here
];

// Function to create cards
function createCards(array, containerId) {
  // Get the container where the cards will be added
  var container = document.getElementById(containerId);

  // Loop through the array
  for (var i = 0; i < array.length; i++) {
    // Create a new div element for the card
    var card = document.createElement("div");
    card.className = "news-updates-card";

    // Create a new h3 element for the title
    var title = document.createElement("h3");
    title.textContent = array[i].title;

    // Create a new p element for the description
    var description = document.createElement("p");
    description.textContent = array[i].description;

    // Create a new p element for the date
    var date = document.createElement("p");
    date.textContent = array[i].date;
    date.className = "date"; // Add a class for styling

    // Append the title, description, and date to the card
    card.appendChild(title);
    card.appendChild(description);
    card.appendChild(date);

    // Append the card to the container
    container.appendChild(card);
  }
}

// Create news cards
createCards(news, "news-container");

// Create updates cards
createCards(updates, "updates-container");
