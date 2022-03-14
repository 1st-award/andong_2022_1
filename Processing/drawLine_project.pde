void setup() {
  size(600, 600);
  strokeWeight(16);  // 굵기 16
  stroke(0, 255, 0); // 색상 (0, 255, 0) GREEN
}

void draw() {
  if(mousePressed) {
    ellipse(pmouseX, pmouseY, mouseX, mouseY);
  }
}
