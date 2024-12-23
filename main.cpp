#include <iostream>
#include "vector3D.h"
#include "environment.h"
#include "satellite.h"

int main(){
    //deine the environment
    Environment env(5.972e24, Vector3D(0, 0, 0), 1.225);

    //define the satellite
    Satellite gsat11(47000, Vector3D(0, 0, 6378), Vector3D(0, 7.5, 0), Vector3D(0, 0, 0));

    double timeStep = 1.0; // 1 second
    for (int i = 0; i < 10; ++i) {
        gsat11.update(timeStep);
        std::cout << "Time: " << (i + 1) * timeStep 
                  << "s, Position: (" << gsat11.position.x << ", "
                  << gsat11.position.y << ", " << gsat11.position.z << ")\n";
    }

    return 0;
}