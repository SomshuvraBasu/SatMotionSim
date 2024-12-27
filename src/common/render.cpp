#include "render.h"
#include <iostream>

// Initialize OpenGL
GLFWwindow* initOpenGL() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n"; //cerr is used to print error messages, not stored in buffer
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Satellite Simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    return window;
}

// Map position to Normalized Device Coordinates (NDC)
Vector3D mapToNDC(const Vector3D& position, double maxRange) {
    return Vector3D(
        position.x / maxRange,  // Normalize x
        position.y / maxRange,  // Normalize y
        position.z / maxRange   // Normalize z
    );
}

void renderSatellites(const std::vector<SatelliteData>& satellites) {
    for (const auto& satData : satellites) {
        // Render each satellite's orbit
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); // Green for orbit
        for (const auto& point : satData.orbit) {
            glVertex3f(point.x, point.y, point.z);
        }
        glEnd();
        
        // Render the satellite as a red point
        glPointSize(5.0f);
        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red for satellite
        if (!satData.orbit.empty()) {
            const auto& last = satData.orbit.back();
            glVertex3f(last.x, last.y, last.z);
        }
        glEnd();
    }
}