let s, eyeScale;

function setup() {
  createCanvas(400, 400);
  s = createSlider(0, 255, 127);
  eyeScale = createSlider(0,100, 50);
}

function draw() {
  background(127);
  translate(200,200);
  scale(map(s.value(),0,255,0.2,2.3));
  happyFace(0,0, 170, eyeScale.value());
}

function happyFace (x, y, diam, eyeScale) {
  
      // Face
      fill(255, 255, 0);
      stroke(0);
      strokeWeight(2);
      ellipse(x, y, diam, diam);
      
      // Smile
      var startAng = .1*PI
      var endAng = .9*PI
      var smileDiam = .6*diam;
      arc(x, y, smileDiam, smileDiam, startAng, endAng);
      
      // Eyes
      var offset = .2*diam;
      var eyeDiam = .1*diam;
      fill(0);
      ellipse(x-offset, y-offset, eyeDiam*eyeScale*0.02, eyeDiam*eyeScale*0.02);
      ellipse(x+offset, y-offset, eyeDiam*eyeScale*0.02, eyeDiam*eyeScale*0.02);
}
