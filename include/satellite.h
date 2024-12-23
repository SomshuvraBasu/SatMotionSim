// Satellite.h
#pragma once
#include <cassert>
#include "vector3D.h"
#include "environment.h"

class Satellite {
public:
    double mass;
    Vector3D position; 
    Vector3D velocity;  // Velocity of the satellite in km/s
    Vector3D thrust;    // Thrust of the satellite in kN
    Environment environment;

    // Constructor
    Satellite(const double& mass, const Vector3D& pos, const Vector3D& vel, const Vector3D& thrust, const Environment& env);

    // Compute orbital velocity
    Vector3D computeOrbitalVelocity();

    // Compute gravitational acceleration
    Vector3D computeGravitationalAcceleration();

    // Compute centripetal acceleration
    Vector3D computeCentripetalAcceleration();

    // Check if the satellite is at orbital velocity
    bool atOrbitalVelocity();

    // Compute the total acceleration (including thrust)
    Vector3D computeAcceleration(const Vector3D& thrust);

    // Update the satellite's position and velocity over time step dt
    void update(const double& dt);
};
