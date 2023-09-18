bool Rectangles::circlecollision(Circle circ) {
float sumw;
float suml;

float dist;
float sumx;
float sumy;
float xmax, xmin;
float ymax, ymin;

xmin = position.x;
xmax = position.x + w;

ymin = position.y;
ymax = position.y + l;

34

sumw = w / 2 + circ.size;
suml = l / 2 + circ.size;

sumx = position.x + w / 2 - circ.position.x;
sumy = position.y + l / 2 - circ.position.y;
dist = sqrt(sumx * sumx + sumy * sumy);

while ((circ.position.x < xmax && circ.position.x >xmin) || (circ.position.y <
ymax && circ.position.y > ymin)) {
if (dist <= suml) return true;
else if (dist <= sumw) return true;
else return false;
}

}
bool Rectangles::circlecollision(Player circ) {
float sumw;
float suml;

float dist;
float sumx;
float sumy;
float xmax, xmin;
float ymax, ymin;

xmin = position.x ;

35

xmax = position.x + w ;

ymin = position.y ;
ymax = position.y + l;

sumw = w / 2 + circ.size;
suml = l / 2 + circ.size;

sumx = position.x + w / 2 - circ.position.x;
sumy = position.y + l / 2 - circ.position.y;
dist = sqrt(sumx * sumx + sumy * sumy);

while ((circ.position.x < xmax && circ.position.x >xmin)|| (circ.position.y <
ymax && circ.position.y > ymin)) {
if (dist <=suml) return true;
else if (dist <= sumw) return true;
else return false;
}

}

bool Rectangles::rectcollision(Rectangles other) {

float wsum, lsum;
wsum = w / 2 + other.w / 2;
lsum = l / 2 + other.l / 2;
if (ofDist(position.x+w/2, position.y+l/2, other.position.x+w/2,
other.position.y+l/2) < wsum|| ofDist(position.x + w / 2, position.y + l /
2, other.position.x + w / 2, other.position.y + l / 2) < lsum) {

36

return true;

}

else return false;

}
void Rectangles::reverse() {
speedX = -speedX;
speedY = -speedY;

}
void Rectangles::setup(float speedmin, float speedmax, float w_in, float l_in) {

speedX = ofRandom(speedmin, speedmax);
speedY = ofRandom(speedmin, speedmax);

l = l_in;
w = w_in;
position.x = ofRandom(ofGetWidth()-w) ;
position.y = ofRandom(ofGetHeight()-l);

}
