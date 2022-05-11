var yPos_red = 0;
var yPos_green = 0;
var yPos_blue = 0;
var speed = 1;

function setup() {
  createCanvas(400, 400);
}


function draw() {
  background(0);
  
  fill(255, 0, 0);
  ellipse(width/2-100, yPos_red, 80, 80);
  fill(0, 255, 0);
  ellipse(width/2, yPos_green, 80, 80);
  fill(0, 0, 255);
  ellipse(width/2+100, yPos_blue, 80, 80);
  
   yPos_red += speed;  yPos_green += speed;  yPos_blue += speed;
  if (yPos_red > height+80) {
    yPos_red = random(0, height);  // random(start, end);
  }
  if (yPos_green > height+80) {
    yPos_green = random(0, height);  // random(start, end);
  }
  if (yPos_blue > height+80) {
    yPos_blue = random(0, height);  // random(start, end);
  }
}

function keyPressed() {
  speed = key - '0';
}
