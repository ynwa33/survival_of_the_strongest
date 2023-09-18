#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Circle.h"
#include "Rectangles.h"

#define N_MAX 1000

class ofApp : public ofBaseApp {

public:
void setup();
void update();
void draw();

void keyPressed(int key);
void keyReleased(int key);
void mouseMoved(int x, int y);
void mouseDragged(int x, int y, int button);
void mousePressed(int x, int y, int button);
void mouseReleased(int x, int y, int button);
void mouseEntered(int x, int y);
void mouseExited(int x, int y);

15

void windowResized(int w, int h);
void dragEvent(ofDragInfo dragInfo);
void gotMessage(ofMessage msg);

void initializeGame(Circle circ[], int numcirc, Rectangles rect[], int
numrect, float speedmin, float speedmax, float size, string state);

string State;
Player player;
Circle circles[N_MAX];
Rectangles rectangles[N_MAX];

ofSoundPlayer start,eat, win, lose;

int numcirc;
int numrect;

float speedmin, speedmax,size;

bool GameOver;
bool Fill;
bool playercirccollision,circcollision, rectcollision,rectcirccollision,
rectplayercollision;

};
