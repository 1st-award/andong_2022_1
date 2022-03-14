void setup() {
  size(1200, 400);
  strokeWeight(16);  // 획의 굵기 설정
  stroke(0, 255, 0);  // 획의 색상 설정 
}

void draw() {
  if(mousePressed) {
    line(pmouseX, pmouseY, mouseX, mouseY);
  }
}
