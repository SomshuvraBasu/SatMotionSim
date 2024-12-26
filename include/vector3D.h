// Vector3D.h
#pragma once
#include <cmath>
#include <functional>

const double tolerance = 1e-3;

class Vector3D {
public:
    double x, y, z;

    // Constructors
    Vector3D();
    Vector3D(double x, double y, double z);

    // Operator overloads
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar) const;
    bool operator==(const Vector3D& other) const;

    // Cross product function
    Vector3D cross(const Vector3D& other) const;

    // Magnitude of the vector
    double magnitude() const;
};

//Hash function for unordered_set
namespace std {
    template<>
    struct hash<Vector3D> {
        size_t operator()(const Vector3D& v) const {
            // Hash each component (x, y, z) and combine them using XOR and bit shifts
            size_t h1 = hash<double>()(v.x);
            size_t h2 = hash<double>()(v.y);
            size_t h3 = hash<double>()(v.z);

            // Combine the hashes using XOR with shifts for better distribution
            return h1 ^ (h2 << 1) ^ (h3 << 2);  // Using shifts to ensure better spreading of the bits
        }
    };
}
