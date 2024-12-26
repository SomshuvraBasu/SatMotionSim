#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

// Class to handle getting the refresh rate of the primary monitor
class RefreshRateHelper {
public:
    RefreshRateHelper();             // Constructor
    ~RefreshRateHelper();            // Destructor
    int getRefreshRate();      // Get refresh rate of the primary monitor

private:
    bool m_initialized;        // Flag to check if GLFW is initialized
};
