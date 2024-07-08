#include <iostream>
#include <vector>
#include "Raycasting3D.h"

void printPoint(const Point3D& point) {
    if (point.x == std::numeric_limits<float>::infinity()) {
        std::cout << "No intersection\n";
    } else {
        std::cout << "Intersection at (" << point.x << ", " << point.y << ", " << point.z << ")\n";
    }
}

int main() {
    // Define planes
    std::vector<Plane3D> planes = {
        {{0, 0, 0}, {0, 1, 0}},
        {{0, 0, 10}, {0, 1, 0}},
        {{10, 0, 0}, {0, 1, 0}},
        {{10, 0, 10}, {0, 1, 0}},
    };

    // Define a ray
    Ray3D ray = {{5, 5, 5}, {0, -1, 0}};

    // Cast the ray
    Raycasting3D raycaster;
    auto intersections = raycaster.castRay(ray, planes);

    // Print the intersections
    for (const auto& intersection : intersections) {
        printPoint(intersection);
    }

    return 0;
}
