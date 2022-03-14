PImage img;
void setup() {
  size(400, 400);
  img = loadImage("https://funzinnu.com/stream/cdn/dccon/%ED%8C%8C%EB%88%84%EB%8B%B9%ED%99%A9.png");
  imageMode(CENTER);
}

float f = 45;
void draw() {
  background(255);
  translate(mouseX, mouseY);
  rotate(f);
  f += 0.25;
  image(img, 0, 0, width/2, height/2);
}
