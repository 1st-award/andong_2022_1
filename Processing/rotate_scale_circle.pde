void setup() {
  size(400, 400);
  strokeWeight(4);
  stroke(255, 0, 255);
}

float f;  //초기화를 안해줘도 됨
void draw() {
  translate(mouseX, mouseY);
  rotate(f);  // 도형을 회전
  scale(cos(f)+1);  // 도형의 크기를 확대
  f += 0.05;
  fill(255, 0, 0);
  rect(-40, -40, 80, 80);
  fill(0, 255, 0);
  ellipse(0, 0, 80, 80);
}
