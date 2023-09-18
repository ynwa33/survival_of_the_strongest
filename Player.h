#pragma once

#include "ofMain.h"
#include "Circle.h"

class Player{
public:
Player();

int size;
void setup(int size_in);
void draw();

26

ofVec2f position;
void update(float x, float y);

bool intersect(Circle circ);
};
