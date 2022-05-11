let ballList = []

function setup() {
  for(let i=0; i<100; ++i) {
    ballList[i] = new Ball();
  }
}

function draw() {
  background(255);
  for(let i=0; i<100; ++i) {
    ballList[i].move();
    ballList[i].display();
  }
  frameRate(10);
}

class Ball {
  constructor() {
    this.x = random(width);
    this.y = random(height);
    this.d = random(10, 30);
    this.redColor = random(255);
    this.greenColor = random(255);
    this.blueColor = random(255);
  }
  
  move() {
    this.x += random(-10,10);
    this.y += random(-10,10);
  }
  
  display() {
    fill(this.redColor, this.greenColor, this.blueColor);
    ellipse(this.x, this.y, this.d, this.d);
  }
}
