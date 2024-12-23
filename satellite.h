// Description: This file contains the definition of the Satellite class.
#pragma once
#include <cassert>
#include "vector3D.h"
#include "environment.h"

class Satellite{
public:
    double mass;
    Vector3D position; 
    Vector3D velocity; // velocity of the satellite in km/s
    Vector3D thrust; // thrust of the satellite in kN
    Environment environment;

    Satellite(const double& mass, const Vector3D& pos, const Vector3D& vel, const Vector3D& thrust, const Environment& env) 
        : mass(mass), position(pos), velocity(vel), thrust(thrust), environment(env) {}

    Vector3D computeOrbitalVelocity() {
        double r = position.magnitude();
        double v = std::sqrt(environment.G * environment.M / r);
        Vector3D orbital_velocity = position.cross(Vector3D(0, 0, 1)) * (v / r);
        return orbital_velocity;
    }

    Vector3D computeGravitationalAcceleration() {
        Vector3D grav_force = environment.computeGravitationalForce(position, mass);
        Vector3D grav_acceleration = grav_force * (1/mass);
        Vector3D grav_acceleration_kmpss = grav_acceleration * 1e-3; // Convert to km/s^2
        return grav_acceleration_kmpss;
    }

    Vector3D computeCentripetalAcceleration() {
        double r = position.magnitude();
        double v = velocity.magnitude();
        double centripetal_acceleration = v * v / r;
        Vector3D centripetal_acceleration_vector = position * (-centripetal_acceleration / r);
        return centripetal_acceleration_vector;
    }

    bool atOrbitalVelocity() {
        Vector3D grav_acceleration = computeGravitationalAcceleration();
        Vector3D centripetal_acceleration = computeCentripetalAcceleration();
        return grav_acceleration == centripetal_acceleration;
    }
    
    Vector3D computeAcceleration(const Vector3D& thrust) {
        Vector3D centripetal_acceleration = computeCentripetalAcceleration();
        Vector3D acceleration = (thrust * (1/mass)) + centripetal_acceleration; 
        return acceleration;
    }

    void update(const double& dt) {
        Vector3D acceleration = computeAcceleration(thrust);
        velocity = velocity + acceleration * dt;
        position = position + velocity * dt;
    }

};