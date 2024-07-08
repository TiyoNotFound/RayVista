#include <iostream>
#include <vector>
#include "Raycasting2D.h"

void printPoint(const Point2D& point) {
    if (point.x == std::numeric_limits<float>::infinity()) {
        std::cout << "No intersection\n";
    } else {
        std::cout << "Intersection at (" << point.x << ", " << point.y << ")\n";
    }
}

int main() {
    // Define walls
    std::vector<Wall2D> walls = {
        {{0, 0}, {10, 0}},
        {{10, 0}, {10, 10}},
        {{10, 10}, {0, 10}},
        {{0, 10}, {0, 0}},
    };

    // Define a ray
    Ray2D ray = {{5, 5}, 0};

    // Cast the ray
    Raycasting2D raycaster;
    auto intersections = raycaster.castRay(ray, walls);

    // Print the intersections
    for (const auto& intersection : intersections) {
        printPoint(intersection);
    }

    return 0;
}
