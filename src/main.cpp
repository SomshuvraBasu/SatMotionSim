#include <iostream>
#include "vector3D.h"
#include "environment.h"
#include "satellite.h"

#define MASS_EARTH 5.972e24

int main(){
    //deine the environment
    Environment GEO(MASS_EARTH, Vector3D(0, 0, 0), 0);

    //define the satellite
    Satellite gsat11(47000, Vector3D(7313.7, 41525.1, 0), Vector3D(-3.04, 0.535, 0), Vector3D(0, 0, 0), GEO);

    double timeStep = 1.0; // 1 second
    for (int i = 0; i < 1000; ++i) {
        if(i%100 == 0){
            std::cout << "Time: " << (i) * timeStep 
                      << "s, Position: " << gsat11.position.magnitude() << ", "
                      << "Orbital Velocity: " << gsat11.computeOrbitalVelocity().magnitude() << ", "
                      << "Velocity: " << gsat11.velocity.magnitude() << ", "
                      << "At Orbital Velocity: " << (gsat11.atOrbitalVelocity() ? "Yes" : "No")<< std::endl;
        }
        gsat11.update(timeStep);
    }

    return 0;
}

