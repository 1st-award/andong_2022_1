let b_list = [];
const MAX_BALL = 100;

function setup() {
  createCanvas(720, 480);
  for(let i = 0; i < MAX_BALL; i++) {
    b_list[i] = new Ball();
  }
}


function draw() {
  background(0);
  for(let i = 0; i < MAX_BALL; i++) {
    b_list[i].move();
    b_list[i].display();
  }
}

class Ball {
  constructor() {
    this.x = random(5, width-5);
    this.y = random(5, height-5);
    this.d = random(5, 40);
    this.s = 2;
  }
  
  move() {
    this.x += random(-this.s, this.s);
    this.y += random(-this.s, this.s);
  }
  
  display() {
    ellipse(this.x, this.y, this.d, this.d);
  }
}
