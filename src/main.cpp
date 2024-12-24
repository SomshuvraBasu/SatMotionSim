#include <iostream>
#include <vector>
#include "vector3D.h"
#include "environment.h"
#include "satellite.h"
#include "render.h"

#define MASS_EARTH 5.972e24

int main() {
    // Initialize OpenGL
    GLFWwindow* window = initOpenGL();
    if (!window) return -1;

    // Define environment and satellite
    Environment GEO(MASS_EARTH, Vector3D(0, 0, 0), 0);
    Satellite gsat11(47000, Vector3D(7313.7, 41525.1, 0), Vector3D(-3.04, 0.535, 0), Vector3D(0, 0, 0), GEO);

    double timeStep = 1.0; // 1 second
    std::vector<Vector3D> orbit;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Update satellite position
        gsat11.update(timeStep);

        // Map satellite position to NDC
        Vector3D ndcPosition = mapToNDC(gsat11.position, 47000.0); // Assume 42,000 km max range
        orbit.push_back(ndcPosition);

        // Render the satellite and its orbit
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
        renderSatellite(orbit);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
