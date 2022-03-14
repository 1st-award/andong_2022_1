void setup() {
  size(400, 400);
}

int i, speed = 1;
void draw() {
  background(0);
  
  textSize(64 + 10 * speed);
  text("Andong", i, 200);
  i += speed;
  
  if(width < i)  i = 0;
}

void keyPressed() {
  if (key >= '0' && key <= '9')
    speed = key - '0';
}
