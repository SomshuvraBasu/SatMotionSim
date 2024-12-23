// Description: This file contains the definition of the Satellite class.
#pragma once
#include "vector3D.h"

class Satellite{
public:
    double mass;
    Vector3D position; 
    Vector3D velocity; // velocity of the satellite in km/s
    Vector3D thrust; // thrust of the satellite in kN

    Satellite(const double& mass, const Vector3D& pos, const Vector3D& vel, const Vector3D& thrust) 
        : mass(mass), position(pos), velocity(vel), thrust(thrust) {}
    
    Vector3D computeAcceleration(const Vector3D& thrust) {
        Vector3D acceleration = thrust * (1 / mass);
        return acceleration;
    }

    void update(const double& dt) {
        if(thrust.magnitude() > 0) {
            Vector3D acceleration = computeAcceleration(thrust);
            velocity = velocity + acceleration * dt;
        }
        position = position + velocity * dt;
    }

};