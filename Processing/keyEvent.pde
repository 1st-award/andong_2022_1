PFont f;
void setup() {
  size(800, 400);
  textSize(128);  // 글자 크기를 조정 
  f = createFont("굴림",  128);  // 폰트와 크기를 설정
  textFont(f);  // 변경한 폰트를 설정
}

int i, dir = 1, sp = 1;
void draw() {
  background(0);
  text("안녕",  i, 200);
  i = i + dir * sp;
  if (i > width- 315) {
    dir = -1;
  }
  if(i < 0) {
    dir = 1;
  }
}

void keyPressed() {
  sp = key - '0';
}
