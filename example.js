// CAUTION: DO NOT RUN THIS CODE 
alphabets = [
  "a",
  "b",
  "c",
  "d",
  "e",
  "f",
  "g",
  "h",
  "i",
  "j",
  "k",
  "l",
  "m",
  "n",
  "o",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
  "v",
  "w",
  "x",
  "y",
  "z",
  " ",
];
goal = "hello world";
buffer = "";

function randomLetter() {
  return alphabets[Math.floor(Math.random() * alphabets.length)];
}

while (1) {
  buffer += randomLetter();
  if (buffer == goal.substring(0, buffer.length)) {
    continue;
  } else {
    buffer = "";
    console.log("reset");
  }
}

// MAXIMUM NUMBER OF ITERATIONS: 3670344500000000 🤯


