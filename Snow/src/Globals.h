#pragma once
#include <vector>
#include <memory>
struct Shape;
extern std::vector<std::shared_ptr<Shape>> SHAPES;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern const int DEFAULT_SCREEN_WIDTH;
extern const int DEFAULT_SCREEN_HEIGHT;

extern const double SPEED_CUTOFF;
extern double FPS_COUNTER_REFRESH_INTERVAL;
extern int CIRCLE_SPLIT_MULT;
extern double GRAVITY;
extern const double BENCHMARK_TIME_STEP;
extern const int BENCHMARK_DEFAULT_SCREEN_WIDTH;
extern const int BENCHMARK_DEFAULT_SCREEN_HEIGHT;