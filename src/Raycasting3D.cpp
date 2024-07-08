#include "Raycasting3D.h"

Point3D Raycasting3D::getIntersection(const Ray3D& ray, const Plane3D& plane) {
    float denom = plane.normal.x * ray.direction.x + plane.normal.y * ray.direction.y + plane.normal.z * ray.direction.z;

    if (fabs(denom) > 1e-6) {
        Point3D diff = {plane.point.x - ray.origin.x, plane.point.y - ray.origin.y, plane.point.z - ray.origin.z};
        float t = (diff.x * plane.normal.x + diff.y * plane.normal.y + diff.z * plane.normal.z) / denom;
        if (t >= 0) {
            return {ray.origin.x + t * ray.direction.x, ray.origin.y + t * ray.direction.y, ray.origin.z + t * ray.direction.z};
        }
    }

    return {std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity()};
}

std::vector<Point3D> Raycasting3D::castRay(const Ray3D& ray, const std::vector<Plane3D>& planes) {
    std::vector<Point3D> intersections;
    for (const auto& plane : planes) {
        Point3D intersection = getIntersection(ray, plane);
        if (intersection.x != std::numeric_limits<float>::infinity()) {
            intersections.push_back(intersection);
        }
    }
    return intersections;
}
