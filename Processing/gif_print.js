let gif_loadImg, gif_createImg;

function preload() {
  gif_loadImg = loadImage("https://1.bp.blogspot.com/-aG0IGsqR3co/X18pyHHnsQI/AAAAAAAAHmE/EwadiMgRdg4alnVnO0onGUliMx0TTVI-gCLcBGAsYHQ/s1600/%25EB%2598%2598%25EB%259F%25AC%25EC%25BD%2594%25EC%258A%25A4%25ED%2584%25B02.gif");
  gif_createImg = createImg("https://1.bp.blogspot.com/-aG0IGsqR3co/X18pyHHnsQI/AAAAAAAAHmE/EwadiMgRdg4alnVnO0onGUliMx0TTVI-gCLcBGAsYHQ/s1600/%25EB%2598%2598%25EB%259F%25AC%25EC%25BD%2594%25EC%258A%25A4%25ED%2584%25B02.gif");
}

function setup() {
  createCanvas(gir_loadImg.width, gif_loadImg.height);
  background(0);
}

function draw() {
  image(gif_createImg);
}
