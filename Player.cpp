#include <stdio.h>
#include "Player.h"

Player::Player(){
size = 5;
position.x = 200;
position.y = 500;

}
void Player::setup(int size_in){
// Player location
position.x = ofGetWidth() / 2;
position.y = ofGetHeight() / 2;

// player size
size = size_in;

}

void Player::draw() {

27

// display Player
ofSetColor(0, 255, 0);
ofSetLineWidth(4);
ofFill();
ofDrawCircle(position.x, position.y, size);
}

void Player::update(float x, float y){
// player locations update
position.x = x;
position.y = y;

// keep player in the screen
position.x = ofClamp(position.x, 0, ofGetWidth());
position.y = ofClamp(position.y, 0, ofGetHeight());

}

bool Player::intersect(Circle circles) {

if (ofDist(position.x, position.y, circles.position.x, circles.position.y) <
(size + circles.size)) return true;
else return false;

}
