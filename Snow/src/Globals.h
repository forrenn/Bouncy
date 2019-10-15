#pragma once
#include <vector>
#include <memory>
struct Shape;
extern std::vector<std::shared_ptr<Shape>> SHAPES;
extern std::vector<size_t> SHAPES_TO_DELETE;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;