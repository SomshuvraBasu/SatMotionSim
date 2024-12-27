#pragma once
#define GL_SILENCE_DEPRECATION 
#include <vector>
#include <GLFW/glfw3.h>
#include "vector3D.h"
#include "helpers.h"

GLFWwindow* initOpenGL();  // Initialize OpenGL
Vector3D mapToNDC(const Vector3D& position, double maxRange);  // Map position to NDC
void renderSatellites(const std::vector<SatelliteData>& satellites);
