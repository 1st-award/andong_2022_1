void setup() {
  size(600, 600);
  fill(0, 255, 0);
}

int posY = 0;
void draw() {
  background(0);
  ellipse(width/2, posY, 80, 80);
  posY += 15;
  if(posY == 600)
    posY = 0;
}
