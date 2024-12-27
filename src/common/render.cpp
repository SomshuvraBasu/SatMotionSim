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

// Render the satellite and its orbit
void renderSatellite(const std::vector<Vector3D>& orbit, const Vector3D& satOnscreenCurrPosition) {
    // Draw orbit as a line strip
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f); // Green for orbit
    for (const auto& point : orbit) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();

    // Draw satellite as a red point
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red for satellite
    if (!orbit.empty()) {
        const auto& last = satOnscreenCurrPosition;
        glVertex3f(last.x, last.y, last.z);
    }
    glEnd();
}
