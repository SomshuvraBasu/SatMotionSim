#pragma once
#define GL_SILENCE_DEPRECATION
#include <vector>
#include <GLFW/glfw3.h>
#include "vector3D.h"

GLFWwindow* initOpenGL();  // Initialize OpenGL
Vector3D mapToNDC(const Vector3D& position, double maxRange);  // Map position to NDC
void renderSatellite(const std::vector<Vector3D>& orbit, const Vector3D& satOnscreenCurrPosition);  // Render the satellite and its orbit
