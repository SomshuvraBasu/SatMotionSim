// Vector3D.h
#pragma once
#include <cmath>

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
