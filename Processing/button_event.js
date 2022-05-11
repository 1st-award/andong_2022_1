function setup() {
  createCanvas(400, 400);
  button = createButton("Click Me");
  button.mousePressed(pressedMe);
}


function pressedMe() {
   circleSize = random(0, width/2);
   bright = map(circleSize, 0, width/2, 0, 255);
   background(bright);
   ellipse(width/2, height/2, circleSize, circleSize);
}
