var cols, rows;
var scl = 20;
var w = 2000;
var h = 1600;
var flying = 0.0;
var redColor = 0;
var greenColor = 0;
var blueColor = 0;
var alpha;
var terrain = [];
var font;

function setup() {
  createCanvas(650, 650, WEBGL);
  cols = w / scl;
  rows = h / scl;

  for (var x = 0; x < cols; x++) {
    // 2차원 배열 생성 후 초기화 
    terrain[x] = [];
    for (var y = 0; y < rows; y++) {
      terrain[x][y] = 0; //specify a default value for now
    }
  }
  textSize(50);
  // 자바 스크립트는 텍스트 폰트 지정
  font = loadFont('NEXON_Bold.otf');
  textFont(font);
}

function draw() {
  background(0);
  noStroke();
  fill(255);
  redColor = abs(mouseX)%256;
  greenColor = abs(mouseY)%256;
  // 자바 스크립트는 텍스트 폰트 지정
  text("X: " + redColor, -300, -250);
  text("Y: " + greenColor, -80, -250);
  text("Z: " + blueColor, 150, -250);
  
  flying -= 0.1;
  var yoff = flying;
  for (var y = 0; y < rows; y++) {
    var xoff = 0;
    for (var x = 0; x < cols; x++) {
      terrain[x][y] = map(noise(xoff, yoff), 0, 1, -100, 100);
      xoff += 0.2;
    }
    yoff += 0.2;
  }
  
  translate(width/2, height/2);
  rotateX(PI / 3);
  translate(-w / 2, -h / 2);
  for (var y = 0; y < rows - 1; y++) {
    beginShape(TRIANGLE_STRIP);
    for (var x = 0; x < cols; x++) {
      alpha = abs(terrain[x][y] * 5);
      fill(redColor, greenColor, blueColor, alpha);
      vertex(x * scl, y * scl, terrain[x][y]);
      vertex(x * scl, (y + 1) * scl, terrain[x][y + 1]);
    }
    endShape();
  }
}


function mouseWheel() {
  blueColor = (blueColor + 1) % 256;
  print(blueColor);
}
