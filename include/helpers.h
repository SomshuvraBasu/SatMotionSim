#pragma once
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "vector3D.h"
#include "satellite.h"

struct SatelliteData {
    int id;
    std::string satelliteName;
    Satellite satellite;
    std::vector<Vector3D> orbit;
};

// Class to handle getting the refresh rate of the primary monitor
class RefreshRateHelper {
public:
    RefreshRateHelper();             // Constructor
    ~RefreshRateHelper();            // Destructor
    int getRefreshRate();      // Get refresh rate of the primary monitor

private:
    bool m_initialized;        // Flag to check if GLFW is initialized
};
