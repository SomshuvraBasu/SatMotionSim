// Description: This file contains the definition of a 3D vector class.
#pragma once // Include guard
#include <cmath>

const double tolerance = 1e-3;

class Vector3D {
public:
    double x, y, z;

    // Constructors
    Vector3D() : x(0), y(0), z(0) {} // if no args, {} initialise a vector with 0, 0, 0
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {} // initialise a vector with x, y, z

    // Overload addition for vectors
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Overload subtraction for vectors
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Overload multiplication for vectors
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    // equality withing a tolerance of vector
    bool operator==(const Vector3D& other) const {
        return std::abs(x - other.x) < tolerance && std::abs(y - other.y) < tolerance && std::abs(z - other.z) < tolerance;
    }

    // Cross product function
    Vector3D cross(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y, // x-component
            z * other.x - x * other.z, // y-component
            x * other.y - y * other.x  // z-component
        );
    }

    // Magnitude of the vector
    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
};