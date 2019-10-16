#include "Globals.h"

std::vector<std::shared_ptr<Shape>> SHAPES;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;
const double SPEED_CUTOFF = 1e-9;
double FPS_COUNTER_REFRESH_INTERVAL = 1;
int CIRCLE_SPLIT_MULT = 2;
double GRAVITY = 100;
const double BENCHMARK_TIME_STEP = 1.0/60;

const int DEFAULT_SCREEN_WIDTH = 1280;
const int DEFAULT_SCREEN_HEIGHT = 720;
const int BENCHMARK_DEFAULT_SCREEN_WIDTH = 1024;
const int BENCHMARK_DEFAULT_SCREEN_HEIGHT = 576;