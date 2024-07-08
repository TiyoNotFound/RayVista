
# RayVista

RayVista is an open-source C++ library providing powerful 2D and 3D raycasting capabilities. Designed with performance and ease-of-use in mind, RayVista is suitable for a wide range of applications, from game development to simulation systems.

## Features

- **2D Raycasting**: Efficiently cast rays in a 2D environment and detect intersections with walls.
- **3D Raycasting**: Perform accurate 3D raycasting and detect intersections with planes.
- Highly optimized for performance.
- Scalable and maintainable codebase.

## Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or higher.
- CMake version 3.10 or higher.

### Building the Project

1. **Clone the repository:**
    ```sh
    git clone https://github.com/TiyoNotFound/RayVista.git
    cd RayVista
    ```

2. **Create a build directory and run CMake:**
    ```sh
    mkdir build
    cd build
    cmake ..
    ```

3. **Build the project:**
    ```sh
    make
    ```

### Running the Examples

After building the project, you can run the example applications:

- **2D Raycasting Example:**
    ```sh
    ./main2D
    ```

- **3D Raycasting Example:**
    ```sh
    ./main3D
    ```

## Library Usage

### 2D Raycasting

Include the `Raycasting2D.h` header and use the `Raycasting2D` class to cast rays in a 2D environment:

```cpp
#include "Raycasting2D.h"

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

// Process the intersections
for (const auto& intersection : intersections) {
    if (intersection.x != std::numeric_limits<float>::infinity()) {
        std::cout << "Intersection at (" << intersection.x << ", " << intersection.y << ")\n";
    } else {
        std::cout << "No intersection\n";
    }
}
```

### 3D Raycasting

Include the `Raycasting3D.h` header and use the `Raycasting3D` class to cast rays in a 3D environment:

```cpp
#include "Raycasting3D.h"

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

// Process the intersections
for (const auto& intersection : intersections) {
    if (intersection.x != std::numeric_limits<float>::infinity()) {
        std::cout << "Intersection at (" << intersection.x << ", " << intersection.y << ", " << intersection.z << ")\n";
    } else {
        std::cout << "No intersection\n";
    }
}
```

## API Reference

### 2D Raycasting

- **`Point2D`**: Represents a point in 2D space.
  - `float x`: X-coordinate.
  - `float y`: Y-coordinate.

- **`Wall2D`**: Represents a wall in 2D space.
  - `Point2D start`: Start point of the wall.
  - `Point2D end`: End point of the wall.

- **`Ray2D`**: Represents a ray in 2D space.
  - `Point2D origin`: Origin of the ray.
  - `float angle`: Angle of the ray in radians.

- **`Raycasting2D`**: Class for performing 2D raycasting.
  - `std::vector<Point2D> castRay(const Ray2D& ray, const std::vector<Wall2D>& walls)`: Casts a ray and returns the intersection points.

### 3D Raycasting

- **`Point3D`**: Represents a point in 3D space.
  - `float x`: X-coordinate.
  - `float y`: Y-coordinate.
  - `float z`: Z-coordinate.

- **`Plane3D`**: Represents a plane in 3D space.
  - `Point3D point`: A point on the plane.
  - `Point3D normal`: Normal vector of the plane.

- **`Ray3D`**: Represents a ray in 3D space.
  - `Point3D origin`: Origin of the ray.
  - `Point3D direction`: Direction vector of the ray.

- **`Raycasting3D`**: Class for performing 3D raycasting.
  - `std::vector<Point3D> castRay(const Ray3D& ray, const std::vector<Plane3D>& planes)`: Casts a ray and returns the intersection points.

## Contributing

We welcome contributions! To contribute to RayVista, please follow these steps:

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

My Gmail- [tiyonotfound@gmail.com](mailto:tiyonotfound@gmail.com)

Project Link: [https://github.com/TiyoNotFound/RayVista](https://github.com/TiyoNotFound/RayVista)
