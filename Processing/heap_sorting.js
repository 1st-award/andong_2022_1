let items = [];
let init = false;
let i;
let finished = false;
let colors = [];
let numSwaps = 0;
let p;
let s;
let sliderValue;
let slider;
let frameSlider;
let frameSliderValue;
let retryButton;

function setup() {
    createCanvas(1200, 600);
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
    
    frameRate(frameSliderValue);
    setValues(sliderValue);
}

function mouseDragged() {
  updateList();
}

function mouseClicked() {
  updateList();
}

function updateList() {
  if(sliderValue != slider.value()) {
    sliderValue = slider.value();
    setValues(sliderValue);
    finished = false;  init = false;
    i = sliderValue;  numSwaps = 0;
    retryButton.hide();
    loop();
  }
  if (frameSliderValue != frameSlider.value()) {
    // 프레임을 조절합니다.
    frameSliderValue = frameSlider.value();
    frameRate(frameSliderValue);
  }
}

function setValues(i) {
  items = [];  colors = [];
  for (let j = 0; j <= ceil(Math.log2(i)); j++) {
        colors[j] = {
            r: random(0, 255), g: random(0, 200), b: random(0, 255)
        };
    }
    for (let j = 0; j < i; j++) {
        items[j] = ((height-50)/i)*(j+1);
    }
    items = shuffle(items);
    s = floor((items.length / 2));
}
   
function retrySort() {
  setValues(sliderValue);
  finished = false;  init = false;
  i = sliderValue;  numSwaps = 0;
  retryButton.hide();
  loop();
}

function swap(i, j) {
    const temp = items[i];
    items[i] = items[j];
    items[j] = temp;
    numSwaps++;
}

async function makeHeap(j) {
    if (j >= 0) {
        maxHeapify(j);
        s--;
    } else {
        init = true;
        i = items.length - 1;
    }
}

async function sortHeap(size) {
    swap(size, 0);
    maxHeapify(0);
    i--;
}

function maxHeapify(index) {
    const l = index * 2;
    const r = index * 2 + 1;
    let largest = -1;
    if ((l < i) && (items[l] > items[index])) {
        largest = l;
    } else {
        largest = index;
    }
    if ((r < i) && (items[r] > items[largest])) {
        largest = r;
    }
    if (largest != index) {
        swap(largest, index);
        maxHeapify(largest);
    }
}

async function draw() {
    background(0);
    if (!init) {
        makeHeap(s);
    } else if (!finished && init) {
        await sortHeap(i);
    }
    if (i < 0) {
        finished = true;
        retryButton.show();
        noLoop();
    }
    let xresolution = (width / (items.length));
    for (let j = 0; j < items.length; j++) {
        const item = items[j];
        if (j == 0) {
            const col = colors[0];
            fill(col.r, col.g, col.b);
        } else if (j < i) {
            const level = floor(Math.log2(j) + 1);
            const col = colors[level];
            fill(col.r, col.g, col.b);
        } else {
            fill(0, 255, 0);
        }
        stroke(255);
        strokeWeight(0.01);
        rect((j * xresolution), height, xresolution, -1 * item);
    }
    push();
    fill(255);
    text("총 개수: " + sliderValue,0, 20);
    text("움직인 횟수: " + numSwaps, 0, 45);
    text("프레임: " + int(frameRate()), 0, 70);
    pop();
    
    p.remove();
    p = createP("number of swaps is: " + numSwaps);
}
