/*  글로벌 변수 초기화
s: 뱀 객체 담는 변수(클래스?)
scl: 크기 조절
food: 먹이 담는 변수(백터)
playfield: 움직일 수 있는 범위
*/
var s;
var scl = 20;
var food;
playfield = 600;
var play_button;
var restart_button;
var exit_button;

const GAME_MODE_TITLE = 0;
const GAME_MODE_PLAY = 1;
const GAME_MODE_OVER = 2;

function setup() {
  /* 초기 작업 
    배경과 뱀 객체와 먹이 생성
    프레임 제한 10fps
  */
  createCanvas(playfield, 640);
  background(51);
  s = new Snake();
  frameRate (10);
  pickLocation();
  
  GAME_MODE = GAME_MODE_TITLE;
  
  play_button = createButton("시작");
  play_button.style("font-size", "32px");
  play_button.size(200, 100);
  play_button.position(width/2-100, height-300);
  play_button.mouseClicked(startGame);
  play_button.hide();

  exit_button = createButton("종료");
  exit_button.style("font-size", "32px");
  exit_button.size(200, 100);
  exit_button.position(width/2-100, height-150);
  exit_button.mouseClicked(exitGame);
  exit_button.hide();
  
  restart_button = createButton("다시하기");
  restart_button.style("font-size", "32px");
  restart_button.size(200, 100);
  restart_button.position(width/2-100, height-300);
  restart_button.mouseClicked(restartGame);
  restart_button.hide();
}

function draw() {
  /*  동작 함수
     스코어 보드 출력
     뱀의 먹이 섭취 유무
     뱀의 죽음, 움직임, 출력
     먹이 출력
  */
  background(51);
  if (GAME_MODE == GAME_MODE_TITLE) {
    text("TEST", width/2-120, 150);
    play_button.show();
    exit_button.show();
  } 
  else if (GAME_MODE == GAME_MODE_OVER) {
    fill(0);
    textSize(80);
    text("GAME OVER", width/2-235, 150);
    textSize(50);
    text("점수: " + last_score, width/2 - 100, 250);
    restart_button.show();
    exit_button.show();
  } 
  else {
  // 뱀 움직이는거 넣어 주시면 됩니다. 수정하셨을까봐 따로 안올렸습니다.
    scoreboard();
    if (s.eat(food)) {
      // 뱀이 먹이를 먹엇으면 먹이 생성
      pickLocation();
    }
    s.death();  // 뱀 죽음 확인
    s.update();  // 뱀 위치 업데이트
    s.show();  // 뱀 출력
  
    // 먹이 색 및 생성
    fill (255, 0, 100);
    rect(food.x, food.y, scl, scl);
  }
}

 
function pickLocation() {
  /* 먹이 생성 함수
    playfield/scl을 하여 가로 세로 전체 길이 구하여 cols rows에 각각 넣기
    food에  0 ~ rows, 0 ~ cols하여 x, y 좌표 구하여 food에 넣기
    food에 scl만큼 x, y에 곱하기
    만약 먹이가 뱀의 꼬리와 겹친다면 함수 재호출
  */
  var cols = floor(playfield/scl);
  var rows = floor(playfield/scl);
  food = createVector(floor(random(cols)), floor(random(rows)));
  food.mult(scl);

  // 뱀이랑 먹이랑 겹치는지 확인
  for (var i = 0; i < s.tail.length; i++) {
    var pos = s.tail[i];
    var d = dist(food.x, food.y, pos.x, pos.y);
    if (d < 1) {
      // 겹치면 다시 생성
      pickLocation();
    }
  }
}


function scoreboard() {
  /* 스코어 보드
    제목, 점수, 최고점수 출력
  */
  fill(0);
  rect(0, 600, 600, 40);
  fill(255);
  textFont("Georgia");
  textSize(18);
  text("Score: ", 10, 625);
  text("Highscore: ", 450, 625)
    text(s.score, 70, 625);
  text(s.highscore, 540, 625)
}


function keyPressed() {
  /* 사용자 입력 화살표 방향키
    뱀 객체의 dir함수를 호출하여 xspeed, yspeed 수정
  */
  if (keyCode === UP_ARROW) {
    s.dir(0, -1);
  } else if (keyCode === DOWN_ARROW) {
    s.dir(0, 1);
  } else if (keyCode === RIGHT_ARROW) {
    s.dir (1, 0);
  } else if (keyCode === LEFT_ARROW) {
    s.dir (-1, 0);
  }
}

function Snake() {
  /* 뱀 클래스?
           x: 현재 뱀의 x좌표
           y: 현재 뱀의 y좌포
      xspeed: 뱀의 x좌표 이동 (초기: 1) 
      yspeed: 뱀의 y좌표 이동 (초기: 0)
       total: 꼬리의 총 개수
        tail: 꼬리 백터를 저장하는 배열 ([0]:꼬리의 끝, [length-1]: 꼬리 처음)
       score: 현재 점수 (초기: 1)
   highscore: 최고점수  (초기: 1)
   dir(x, y): 유저가 누른 방향키에 따라 뱀의 이동방향 지정 함수
    eat(pos): pos(백터)를 이용해 먹이를 먹었는지 안먹었는지 확인 함수 
     death(): 뱀이 꼬리나 벽에 닿았을 시 점수 초기화 함수
    update(): 뱀이 이동 작업 함수
      show(): 뱀 출력 함수 
  */
  this.x =0;
  this.y =0;
  this.xspeed = 1;
  this.yspeed = 0;
  this.total = 0;
  this.tail = [];
  this.score = 1;
  this.highscore = 1;

  this.dir = function(x, y) {
    /* 이동 방향 수정 함수
      유저가 누른 방향키에 따라 xspeed, yspeed가 수정 (keyPressed() 참조)
    */
    this.xspeed = x;
    this.yspeed = y;
  };

  this.eat = function(pos) {
    /* 먹이 섭취 유무 함수
       pos: 먹이의 위치를 나타내는 백터 변수
       현재 뱀의 위치와 먹이 위치의 거리가 1보다 작으면 
       점수와 꼬리 개수 +1 이때, 점수가 최고점수보다 높을시 점수를 최고점수에 삽입
       수정된 점수와 최고점수 출력
       true, false로 먹이 섭취 유무 확인(먹었으면: true, 먹지 않았으면: false)
    */
    var d = dist(this.x, this.y, pos.x, pos.y);
    if (d < 1) {
      // 뱀이 먹이를 먹엇으면 점수와 꼬리 +1
      this.total++;
      this.score++;
      text(this.score, 70, 625);
      if (this.score > this.highscore) {
        // 점수가 최고점수보다 높으면 최고점수 업데이트
        this.highscore = this.score;
      }
      text(this.highscore, 540, 625);
      return true;  // 먹엇으면 true
    } else {
      return false;  // 안먹엇으면 flase
    }
  };

  this.death = function() {
    /* 뱀의 죽음 유무 확인 함수
    꼬리 중 머리와의 거리가 1보다 작을 시 점수 초기화
    */
    for (var i = 0; i < this.tail.length; i++) {
      var pos = this.tail[i];
      var d = dist(this.x, this.y, pos.x, pos.y);
      if (d < 1) {
        // 머리가 꼬리 또는 벽에 닿았을시 점수, 꼬리개수, 꼬리 배열 초기화
        this.total = 0;
        this.score = 0;  // 초기엔 1인데 죽으면 0으로 세팅해둠 ㅁㅈ
        this.tail = [];
      }
    }
  };

  this.update = function() {
    /* 뱀의 이동 동작 함수
      뱀의 꼬리 개수와 꼬리 배열의 개수가 같으면 꼬리 배열을 왼쪽으로 이동 시키고 
      머리랑 가장 가까운 꼬리는 머리 좌표를 넣어 생성
      머리는 xspeed, yspeed를 통하여 좌표 계산 후 x, y에 삽입
      만약 머리가 범위를 벗어나려할 시 플래이어가 이동할 수 있는 최대 좌표로 다시 삽입
    */
    if (this.total === this.tail.length) {
      // 뱀의 길이와 꼬리 길이가 같을 시 꼬리 배열 인덱스(벡터)를 왼쪽으로 한칸 씩 이동 
      for (var i = 0; i < this.tail.length-1; i++) {
        this.tail[i] = this.tail[i+1];
      }
    }
    // 머리와 가장 가까운 꼬리 업데이트
    this.tail[this.total-1] = createVector(this.x, this.y);
    // 이동한 만큼 머리 이동
    this.x = this.x + this.xspeed*scl;
    this.y = this.y + this.yspeed*scl;

    this.x = constrain(this.x, 0, playfield-scl);  // 뱀의 이동 범위 제한
    this.y = constrain(this.y, 0, playfield-scl);  // 뱀의 이동 범위 제한
  };
  
  this.show = function() {
    /* 뱀 출력 함수
      뱀의 꼬리 출력 후 머리 출력
    */
    fill(255);
    for (var i = 0; i < this.tail.length; i++) {
      rect(this.tail[i].x, this.tail[i].y, scl, scl);
    }
    rect(this.x, this.y, scl, scl);
  };
}
