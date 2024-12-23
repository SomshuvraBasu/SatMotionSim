// Environment.h
#pragma once
#include "vector3D.h"

class Environment {
public:
    const double G = 6.674010551359e-20; // Gravitational constant in km^3 kg^-1 s^-2
    double M; // Mass of the central body
    Vector3D central_position; // Position of the central body
    double air_density; // Air density

    // Constructor
    Environment(const double& M, const Vector3D& central_position, const double& air_density);

    // Method to compute gravitational force
    Vector3D computeGravitationalForce(const Vector3D& position, const double& mass);

    // Method to compute drag force
    Vector3D computeDragForce(const Vector3D& velocity, const double& drag_coefficient);
};
