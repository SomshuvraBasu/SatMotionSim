// Environment.cpp
#include "environment.h"

// Constructor implementation
Environment::Environment(const double& M, const Vector3D& central_position, const double& air_density)
    : M(M), central_position(central_position), air_density(air_density) {}

// Compute gravitational force implementation
Vector3D Environment::computeGravitationalForce(const Vector3D& position, const double& mass) {
    double r = position.magnitude();
    Vector3D grav_force = position * (-G * M * mass / (r * r * r));
    return grav_force;
}

// Compute drag force implementation
Vector3D Environment::computeDragForce(const Vector3D& velocity, const double& drag_coefficient) {
    double v = velocity.magnitude();
    Vector3D drag_force = velocity * (-0.5 * air_density * drag_coefficient * v * v);
    return drag_force;
}
