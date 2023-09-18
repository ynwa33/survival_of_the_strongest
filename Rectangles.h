#pragma once
#include "Circle.h"
#include "player.h"

class Rectangles {

public:
float l;
float w;

float speedX;
float speedY;

Rectangles();
ofVec2f position;
ofColor colorrect;

void set(float w_in, float l_in);
void setup(float speedmin, float speedmax, float w_in, float l_in);
void colorand();
void display();
void reverse();

bool circlecollision(Circle circ);
bool rectcollision(Rectangles other);
bool circlecollision(Player circ);

bool Fill;

33

bool collision;

void Fillset(string label);
void update();

};
