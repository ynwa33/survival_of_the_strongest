#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
// start the game
State = "start";

numcirc = 1;
size = 20;

numrect = 4;

speedmin = -4;
speedmax = 4;

initializeGame(circles, numcirc, rectangles, numrect, speedmin, speedmax,
size, State);

Fill = true;

eat.load("C:/Users/husse/Downloads/eat.mp3");
lose.load("C:/Users/husse/Downloads/lose.mp3");
win.load("C:/Users/husse/Downloads/win.mp3");
start.load("C:/Users/husse/Downloads/start.mp3");

for (int i = 0; i < 4; i++) {
start.play();
}

17

}

//--------------------------------------------------------------
void ofApp::update() {
if (State =="start") {

}
if (State == "play") {
// update player according to mouse positions
player.update(ofGetMouseX(), ofGetMouseY());

start.stop();

for (int i = 0; i < numrect; i++) {
rectangles[i].update();

for (int j = 0; j < numrect; j++) {
if (i != j) {
rectcollision = rectangles[i].rectcollision(rectangles[j]);
if (rectcollision == true) {
rectangles[i].reverse();
rectangles[j].reverse();

}

}
}

18

for (int j = 0; j < numcirc; j++) {

rectcirccollision = rectangles[i].circlecollision(circles[j]);
if (rectcirccollision == true) {
rectangles[i].reverse();
circles[j].reverse();
}

}

rectplayercollision = rectangles[i].circlecollision(player);
if (rectplayercollision == true) {

State = "L";
lose.play();
}

}

for (int i = 0; i < numcirc; i++) {
// check if the play is active
if (circles[i].playon == true) {

// update circle and rect speeds
circles[i].update();
playercirccollision = player.intersect(circles[i]);
if (playercirccollision == true) {
19

if (player.size > circles[i].size) {
player.size = player.size + 1;
circles[i].playon = false;
eat.play();

}

// if player eats bigger circle

else {

State = "L";
lose.play();
}
}

// check collision of other circles
for (int j = 0; j < numcirc; j++) {
if (i != j && circles[j].playon==true) {

// check collision between the circles
circcollision = circles[i].circcollision(circles[j]);

// if circles collided change their direction on x & y axis

20

if (circcollision == true) {

circles[i].reverse();
circles[j].reverse();
}
}
}
}
}

// after updating all the objects check is there any active circles on the
screen
GameOver = true;

for (int i = 0; i < numcirc; i++) {
if (circles[i].playon == true) {
GameOver = false;
break;
}
}
// if no set the game state to win
if (GameOver == true) {
State = "W";
win.play();
}
}

}

21

//--------------------------------------------------------------
void ofApp::draw() {
ofSetBackgroundColor(153, 251, 255);
// start screen
if (State == "start") {
ofSetColor(0, 0, 0);

ofDrawBitmapString("Click anywhere to start!", ofGetWidth() / 3,
ofGetHeight() * 0.5);
}
else if (State == "play") {
// display player
player.draw();

for (int i = 0; i < numcirc; i++) {
if (circles[i].playon) {
// if player is active then display the circles
circles[i].display(Fill, 3);
}

}

for (int i = 0; i < numrect; i++) {
rectangles[i].display();

}

22

}

// lost screen

else if (State == "L") {
ofSetColor(0, 0, 0);
ofDrawBitmapString("You lost...", ofGetWidth() / 2, ofGetHeight() / 2);
ofDrawBitmapString("Your score: " + ofToString(int(player.size - 20)),
ofGetWidth() / 2, ofGetHeight() * 0.3);
ofDrawBitmapString("Click to restart the game", ofGetWidth() / 2.1,
ofGetHeight() * 0.7);
}
else if (State == "W") { // win screen

ofSetColor(0, 0, 0);
ofDrawBitmapString("You win!", ofGetWidth() / 2, ofGetHeight() / 2);
ofDrawBitmapString("Your score: " + ofToString(int(player.size)),
ofGetWidth() / 2, ofGetHeight() * 0.3);
ofDrawBitmapString("Click to restart the game", ofGetWidth() / 2,
ofGetHeight() * 0.9);
}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

23

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
if (State == "start") {
initializeGame(circles,
numcirc,rectangles,numrect,speedmin,speedmax,size,"play");
}
else if (State == "L" || State == "W") {
initializeGame(circles, numcirc, rectangles,numrect,speedmin,
speedmax,size, "play");
24

}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
void ofApp::initializeGame(Circle circ[], int numcirc, Rectangles rect[],int
numrect, float speedmin, float speedmax, float size, string state) {

25

for (int i = 0; i < numcirc; i++) {
State = state;
// setup player
player.setup(size);
circ[i].setup(speedmin, speedmax);
}
for (int i = 0; i < numrect; i++){
rectangles[i].setup(speedmin, speedmax,30,30);

}

}
