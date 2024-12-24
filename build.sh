echo "Initializing build process"

BUILD_DIR="/Users/som/Projects/SatMotionSim/build/dev"
CMAKE_FILE="/Users/som/Projects/SatMotionSim/CMakeLists.txt"
TIMESTAMP_FILE="$BUILD_DIR/.cmake_timestamp"

if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

cd "$BUILD_DIR"

echo "Build directory: $BUILD_DIR"
echo "====================================================="

# Check if the CMakeLists.txt file has changed
if [ ! -f "$TIMESTAMP_FILE" ] || [ "$CMAKE_FILE" -nt "$TIMESTAMP_FILE" ]; then
    rm -rf "$BUILD_DIR/*"
    echo "CMakeLists.txt has changed or no previous build timestamp found."
    echo "Cleaning DIR and Running cmake"
    cmake /Users/som/Projects/SatMotionSim
    touch "$TIMESTAMP_FILE"
else
    echo "CMakeLists.txt has not changed. Skipping cmake"
fi
echo "====================================================="
echo "Running make"
make
echo "Build complete"
echo "====================================================="
./SatMotionSim
