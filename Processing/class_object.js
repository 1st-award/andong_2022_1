let myBall;

function setup() {
  myBall = new Ball();
}

function draw() {
  background(255);
  myBall.move();
  myBall.display();
}

class Ball {
  constructor() {
    this.x = 50;
    this.y = 50;
    this.distance = 80;
    this.speed = 2;
  }
  
  move() {
    this.x += random(-this.speed, this.speed);
    this.y += random(-this.speed, this.speed);
  }
  
  display() {
    ellipse(this.x, this.y, this.distance, this.distance);
  }
}
  
