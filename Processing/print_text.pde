PFont f;
void setup() {
  size(800, 400);
  textSize(128);  // 글자 크기를 조정 
  f = createFont("굴림",  128);  // 폰트와 크기를 설정
  textFont(f);  // 변경한 폰트를 설정
}

int i;
void draw() {
  background(0);
  text("안녕",  i+=5, 200);
  if (i > width) {
    i = 0;
  }
}
