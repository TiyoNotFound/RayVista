#pragma once
#include <vector>
#include <cmath>
#include <limits>

struct Point2D {
    float x, y;
};

struct Wall2D {
    Point2D start, end;
};

struct Ray2D {
    Point2D origin;
    float angle;
};

class Raycasting2D {
public:
    std::vector<Point2D> castRay(const Ray2D& ray, const std::vector<Wall2D>& walls);

private:
    Point2D getIntersection(const Ray2D& ray, const Wall2D& wall);
};
