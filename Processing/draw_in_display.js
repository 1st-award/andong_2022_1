let pg;
let pg1;

function setup() {
  createCanvas(710, 400);
  pg = createGraphics(200, 250);
  pg1 = createGraphics(200, 250);
}


function draw() {
  fill(0, 10);
  rect(0, 0, width, height);
  fill(255);
  noStroke();
  ellipse(mouseX, mouseY, 60, 60);
  pg.background(0, 255, 0);
  pg.fill(255, 0, 255);
  pg.ellipse(mouseX-75, mouseY-75, 60, 60);
  image(pg, 75, 75);
  pg1.background(0, 255, 0);
  pg1.fill(255, 0, 255);
  pg1.ellipse(mouseX-(width/4+150), mouseY-75, 60, 60);
  image(pg1, width/4+150, 75);
}
