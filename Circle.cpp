#include <stdio.h>
#include "Circle.h"

Circle::Circle(){
size = 10;
position.x = 10;
position.y = 10;
speedX = 0;
speedY = 0;
}
void Circle::setup(float speedmin, float speedmax){
// Circle location
position.x = ofRandom(ofGetWidth());
position.y = ofRandom(ofGetHeight());

// random size between 10 25
size = ofRandom(10, 25);
// active
playon = true;

// random circle speed

30

speedX = ofRandom(speedmin, speedmax);
speedY = ofRandom(speedmin, speedmax);
// random color
colorcirc = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Circle::update(){

// add speed to location
position.x =position.x+ speedX;
position.y = position.y+speedY;

// if hit the walls turn back
if(position.x-size < 0|| position.x+size > ofGetWidth()) {
speedX = -speedX;
}

if(position.y-size < 0|| position.y +size> ofGetHeight()) {
speedY = -speedY;
}

// increase size of the circle with a small amount
size =size+ 0.0125;
}

void Circle::display( bool fill , int linewidth){
// display circle
ofSetColor(colorcirc);
ofSetLineWidth(linewidth);

31

if( fill==true) ofFill();
if (fill == false) ofNoFill();

ofDrawCircle(position.x, position.y, size);
}

// collision
bool Circle::circcollision(Circle other){
if (ofDist(position.x, position.y, other.position.x, other.position.y) < (size +
other.size)) {
return true;
}
else return false;

}
void Circle::colorsetrand() {
colorcirc = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

}

void Circle::reverse() {
speedX = -speedX;
speedY = -speedY;

}
