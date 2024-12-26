// Vector3D.cpp
#include "vector3D.h"

// Default constructor: initializes vector to (0, 0, 0)
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Constructor that initializes vector with given x, y, z values
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Overload addition for vectors
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

// Overload subtraction for vectors
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

// Overload multiplication for scalar multiplication
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

// Equality check with tolerance (to compare vectors)
bool Vector3D::operator==(const Vector3D& other) const {
    return std::abs(x - other.x) < tolerance && 
           std::abs(y - other.y) < tolerance && 
           std::abs(z - other.z) < tolerance;
}

// Cross product of two vectors
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y, // x-component
        z * other.x - x * other.z, // y-component
        x * other.y - y * other.x  // z-component
    );
}

// Magnitude of the vector
double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}