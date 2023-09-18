#pragma once
#define Circle_h

#include "ofMain.h"

class Circle{
public:
Circle();

ofVec2f position;
float size;
ofColor colorcirc;

float speedX;
float speedY;
int r;
int g;
int b;

bool playon;

void setup(float speedmin, float speedmax);
void display( bool fill, int linewidth);
void update();
void colorsetrand();
void reverse();

29

bool circcollision(Circle other);

};
