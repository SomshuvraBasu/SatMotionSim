#include <iostream>
#include <vector>
#include <unordered_set>
#include "vector3D.h"
#include "environment.h"
#include "satellite.h"
#include "render.h"

#define MASS_EARTH 5.972e24
#define MAX_RANGE 100000.0
#define SPEEDUP_FACTOR 1

int main() {
    // Initialize OpenGL
    GLFWwindow* window = initOpenGL();
    if (!window) return -1;

    // Define environment and satellite
    Environment GEO(MASS_EARTH, Vector3D(0, 0, 0), 0);
    Satellite gsat11(47000, Vector3D(7313.7, 41525.1, 0), Vector3D(-3.04*SPEEDUP_FACTOR, 0.535*SPEEDUP_FACTOR, 0*SPEEDUP_FACTOR), Vector3D(0, 0, 0), GEO);

    double timeStep = 1.0; // 1 second
    std::unordered_set<Vector3D> uniquePositions;
    std::vector<Vector3D> onscreenOrbit;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Update satellite position
        gsat11.update(timeStep);

        // Map satellite position to NDC
        Vector3D satOnscreenCurrPosition = mapToNDC(gsat11.position, MAX_RANGE); // Assume 42,000 km max range
        
        if(uniquePositions.find(satOnscreenCurrPosition) == uniquePositions.end()) {
            uniquePositions.insert(satOnscreenCurrPosition);
            onscreenOrbit.push_back(satOnscreenCurrPosition);
        }

        // Render the satellite and its onscreenOrbit
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
        renderSatellite(onscreenOrbit, satOnscreenCurrPosition);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
