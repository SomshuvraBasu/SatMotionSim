#include <iostream>
#include <vector>
#include "vector3D.h"
#include "helpers.h"
#include "environment.h"
#include "satellite.h"
#include "render.h"

#define MASS_EARTH 5.972e24
#define MAX_RANGE 100000.0
#define SPEEDUP_FACTOR 1000

int main() {
    // Get refresh rate of the primary monitor
    int refreshRate = RefreshRateHelper().getRefreshRate();
    std::cout<<"Refresh rate: "<<refreshRate<<std::endl;

    // Initialize OpenGL
    GLFWwindow* window = initOpenGL();
    if (!window) return -1;

    // Define environment
    Environment GEO(MASS_EARTH, Vector3D(0, 0, 0), 0);

    // Define tracked satellites
    std::vector<SatelliteData> trackedSatellites = {
        {1101, "GSAT11", Satellite(47000, Vector3D(7313.7, 41525.1, 500), Vector3D(-3.04 * SPEEDUP_FACTOR, 0.535 * SPEEDUP_FACTOR, 0), Vector3D(0, 0, 0), GEO), {}},
        {1201, "GSAT10", Satellite(40000, Vector3D(7313.7, 42000.0, 0), Vector3D(3.04 * SPEEDUP_FACTOR, 0.535 * SPEEDUP_FACTOR, 0), Vector3D(0, 0, 0), GEO), {}}
    };

    double timeStep = 1.0 / refreshRate; // 1 second per total refreshRate frames

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

        // Update and map satellite positions
        for (auto& satData : trackedSatellites) {
            // Update satellite position
            satData.satellite.update(timeStep);

            // Map satellite position to NDC
            Vector3D satOnscreenCurrPosition = getNDC(satData.satellite.position, MAX_RANGE);

            // Update orbit if position is unique
            if (std::find(satData.orbit.begin(), satData.orbit.end(), satOnscreenCurrPosition) == satData.orbit.end()) {
                satData.orbit.push_back(satOnscreenCurrPosition);
            }
        }

        // Render all satellites
        renderSatellites(trackedSatellites);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
