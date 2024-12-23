// Satellite.cpp
#include "satellite.h"

// Constructor implementation
Satellite::Satellite(const double& mass, const Vector3D& pos, const Vector3D& vel, const Vector3D& thrust, const Environment& env)
    : mass(mass), position(pos), velocity(vel), thrust(thrust), environment(env) {}

// Compute orbital velocity (in km/s)
Vector3D Satellite::computeOrbitalVelocity() {
    double r = position.magnitude();
    double v = std::sqrt(environment.G * environment.M / r);
    Vector3D orbital_velocity = position.cross(Vector3D(0, 0, 1)) * (v / r);
    return orbital_velocity;
}

// Compute gravitational acceleration (in km/s^2)
Vector3D Satellite::computeGravitationalAcceleration() {
    Vector3D grav_force = environment.computeGravitationalForce(position, mass);
    Vector3D grav_acceleration = grav_force * (1 / mass);
    Vector3D grav_acceleration_kmpss = grav_acceleration * 1e-3; // Convert to km/s^2
    return grav_acceleration_kmpss;
}

// Compute centripetal acceleration (in km/s^2)
Vector3D Satellite::computeCentripetalAcceleration() {
    double r = position.magnitude();
    double v = velocity.magnitude();
    double centripetal_acceleration = v * v / r;
    Vector3D centripetal_acceleration_vector = position * (-centripetal_acceleration / r);
    return centripetal_acceleration_vector;
}

// Check if the satellite is at orbital velocity (gravity equals centripetal acceleration)
bool Satellite::atOrbitalVelocity() {
    Vector3D grav_acceleration = computeGravitationalAcceleration();
    Vector3D centripetal_acceleration = computeCentripetalAcceleration();
    return grav_acceleration == centripetal_acceleration;
}

// Compute the total acceleration considering thrust and centripetal acceleration
Vector3D Satellite::computeAcceleration(const Vector3D& thrust) {
    Vector3D centripetal_acceleration = computeCentripetalAcceleration();
    Vector3D acceleration = (thrust * (1 / mass)) + centripetal_acceleration;
    return acceleration;
}

// Update the satellite's position and velocity using the acceleration and time step dt
void Satellite::update(const double& dt) {
    Vector3D acceleration = computeAcceleration(thrust);
    velocity = velocity + acceleration * dt;
    position = position + velocity * dt;
}
