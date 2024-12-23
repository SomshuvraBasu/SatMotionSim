// Description : This file defines the environment class.
#pragma once
#include "vector3D.h"

class Environment {
public:
    const double G = 6.674010551359e-11; // Gravitational constant
    double M; //Mass of the central body
    Vector3D central_position; // Position of the central body
    double air_density; 

    Environment(const double& M, const Vector3D& central_position, const double& air_density) 
        : M(M), central_position(central_position), air_density(air_density) {}

    Vector3D computeDistance(const Vector3D& position) {
        return position - central_position;
    }

    Vector3D computeGravitationalForce(const Vector3D& position, const double& mass) {
        Vector3D distance = computeDistance(position);
        double r = distance.magnitude();
        Vector3D grav_force = distance * (-G * M * mass / (r * r * r));
        return grav_force;
    }

    Vector3D computeDragForce(const Vector3D& velocity, const double& drag_coefficient) {
        double v = velocity.magnitude();
        Vector3D drag_force = velocity * (-0.5 * air_density * drag_coefficient * v * v);
        return drag_force;
    }

    Vector3D computeTotalForce(const Vector3D& position, const Vector3D& velocity, const double& mass, const double& drag_coefficient) {
        Vector3D grav_force = computeGravitationalForce(position, mass);
        Vector3D drag_force = computeDragForce(velocity, drag_coefficient);
        Vector3D total_force = grav_force + drag_force;
        return total_force;
    }

};