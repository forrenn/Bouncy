#include "Globals.h"

std::vector<std::shared_ptr<Shape>> SHAPES;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;
const double SPEED_CUTOFF = 1e-9;
double FPS_COUNTER_REFRESH_INTERVAL = 1;
int CIRCLE_SPLIT_MULT = 2;
double GRAVITY = 100;