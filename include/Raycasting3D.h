#pragma once
#include <vector>
#include <cmath>
#include <limits>

struct Point3D {
    float x, y, z;
};

struct Plane3D {
    Point3D point;  // A point on the plane
    Point3D normal; // The normal vector of the plane
};

struct Ray3D {
    Point3D origin;
    Point3D direction;
};

class Raycasting3D {
public:
    std::vector<Point3D> castRay(const Ray3D& ray, const std::vector<Plane3D>& planes);

private:
    Point3D getIntersection(const Ray3D& ray, const Plane3D& plane);
};
