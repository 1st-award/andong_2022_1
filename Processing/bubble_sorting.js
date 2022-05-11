let values = [];
let retryButton;
let slider;
let frameSlider;
let sliderValue;
let frameSliderValue;
let i = 0;
let j = 0;
let moveCount = 0;
let temp;
let loop_state;
const NO_LOOP = 0;
const LOOP = 1;

// setup() 함수 속 명령문들은
// 프로그램 시작시 한 번 실행됩니다.
// 배열은 setup()함수를 통해 임의의 값들로 채워집니다.
function setup() {
  createCanvas(windowWidth, windowHeight-250);
  textSize(20);

  createP("총 개수");
  slider = createSlider(10, width, 10, 10);
  slider.size(300);
  createP("프레임");
  frameSlider = createSlider(1, 144, 60, 10);
  frameSlider.size(300);
  sliderValue = slider.value();
  frameSliderValue = frameSlider.value();
  retryButton = createButton("다시하기");
  retryButton.mousePressed(retrySort);
  retryButton.position(width/2-20, 20);
  retryButton.hide();

  setValues(sliderValue);
  frameRate(frameSliderValue);
  loop_state = LOOP;
}

function windowResized() {
  resizeCanvas(windowWidth, windowHeight-250);
}

// draw() 함수 속 명령문들은
// 프로그램이 멈출 때까지 실행됩니다.
// 각 명령문은 순차적으로 실행되며,
// 마지막 명령문 실행한 후에는 첫 명령문으로 돌아가 실행합니다.
function draw() {
  background(220);
  bubbleSort();
  simulateSorting();
  push();
  fill(0);
  text("총 개수: " + sliderValue, 0, 20);
  text("움직인 횟수: " + moveCount, 0, 45);
  text("프레임: " + int(frameRate()), 0, 70);
  pop();
}

// _number 만큼 배열 초기화
function setValues(_number) {
  values = [];
  for (let i = 0; i<=_number; i++) {
    values[i] = ((height-50)/_number)*(i+1);
  }
  values = shuffle(values);
}

// 마우스를 드래그 할 때 마다 슬라이더에서 입력값이 변하면
// 그에 맞게 움직입니다.
function mouseDragged() {
  updateList();
}

function mouseClicked() {
  updateList();
}

function updateList() {
  if (sliderValue != slider.value()) {
    // 정렬할 개수를 늘립니다.
    sliderValue = slider.value();
    setValues(sliderValue);
    loop_state = LOOP;
    retryButton.hide();
    i = 0;
    j = 0;
    moveCount = 0;
    loop();
  }
  if (frameSliderValue != frameSlider.value()) {
    // 프레임을 조절합니다.
    frameSliderValue = frameSlider.value();
    frameRate(frameSliderValue);
  }
}


function retrySort() {
  setValues(sliderValue);
  loop_state = LOOP;
  i = 0;
  j = 0;
  moveCount = 0;
  retryButton.hide();
  loop();
}

// bubbleSort() 함수는 매 프레임마다
// 8개의 배열 요소를 가져옵니다.
// 이 함수가 사용하는 알고리즘은 버블 정렬입니다.
function bubbleSort() {
  for (let k = 0; k<8; k++) {
    if (i<values.length) {
      temp = values[j];
      if (values[j] > values[j+1]) {
        values[j] = values[j+1];
        values[j+1] = temp;
        moveCount++;
      }
      j++;

      if (j>=values.length-i-1) {
        j = 0;
        i++;
      }
    } else {
      loop_state = NO_LOOP;
      retryButton.show();
      noLoop();
    }
  }
}

// simulateSorting() 함수는 버블 정렬 알고리즘에
// 애니메이션을 적용합니다.
// 이 함수는 배열의 값을 사각형 길이로 치환해
// 사각형을 그립니다.
function simulateSorting() {
  dynamicArraySize = width/values.length;
  for (let i = 0; i<values.length; i++) {
    if (loop_state != NO_LOOP) {
      if (temp != values[i]) {
        fill(200);
      } else {
        fill(255, 0, 0);
      }
    } else {
      fill(0, 200, 0);
    }
    push();
    fill(0);
    rect(i*dynamicArraySize, height, dynamicArraySize, -values[i]);
    pop();
    rect(i*dynamicArraySize, height, dynamicArraySize, -values[i]+8);
  }
}
