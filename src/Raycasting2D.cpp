#include "Raycasting2D.h"

Point2D Raycasting2D::getIntersection(const Ray2D& ray, const Wall2D& wall) {
    float x1 = wall.start.x;
    float y1 = wall.start.y;
    float x2 = wall.end.x;
    float y2 = wall.end.y;

    float x3 = ray.origin.x;
    float y3 = ray.origin.y;
    float x4 = ray.origin.x + cos(ray.angle);
    float y4 = ray.origin.y + sin(ray.angle);

    float denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (denom == 0) return {std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity()};

    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denom;
    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denom;

    if (t >= 0 && t <= 1 && u >= 0) {
        return {x1 + t * (x2 - x1), y1 + t * (y2 - y1)};
    }

    return {std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity()};
}

std::vector<Point2D> Raycasting2D::castRay(const Ray2D& ray, const std::vector<Wall2D>& walls) {
    std::vector<Point2D> intersections;
    for (const auto& wall : walls) {
        Point2D intersection = getIntersection(ray, wall);
        if (intersection.x != std::numeric_limits<float>::infinity()) {
            intersections.push_back(intersection);
        }
    }
    return intersections;
}
