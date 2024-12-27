#include "helpers.h"

// Constructor
RefreshRateHelper::RefreshRateHelper() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        m_initialized = false;
    } else {
        m_initialized = true;
    }
}

// Destructor
RefreshRateHelper::~RefreshRateHelper() {
    if (m_initialized) {
        glfwTerminate();
    }
}

// Get the refresh rate
int RefreshRateHelper::getRefreshRate() {
    if (!m_initialized) {
        std::cerr << "GLFW not initialized properly!" << std::endl;
        return -1;
    }

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    if (monitor == nullptr) {
        std::cerr << "Failed to get primary monitor!" << std::endl;
        return -1;
    }

    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    if (mode == nullptr) {
        std::cerr << "Failed to get video mode!" << std::endl;
        return -1;
    }

    return mode->refreshRate;
}

// Map position to Normalized Device Coordinates (NDC)
Vector3D getNDC(const Vector3D& position, double maxRange) {
    return Vector3D(
        position.x / maxRange,  // Normalize x
        position.y / maxRange,  // Normalize y
        position.z / maxRange   // Normalize z
    );
}