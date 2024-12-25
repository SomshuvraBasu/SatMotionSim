echo "Initializing build process"

BUILD_DIR=$(pwd)/build/dev #output of pwd command is inserted into the variable BUILD_DIR
CMAKE_FILE=$(pwd)/CMakeLists.txt
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
    cmake $(pwd)
    touch "$TIMESTAMP_FILE"
else
    echo "CMakeLists.txt has not changed. Skipping cmake"
fi
echo "====================================================="
echo "Running make"
make
echo "Build complete"
echo "====================================================="
echo "Executable: $BUILD_DIR/SatMotionSim"
echo "====================================================="
$BUILD_DIR/SatMotionSim
#if the executable is not found, the script will exit with an error code of 1
if [ $? -ne 0 ]; then
    echo "Executable not found. Error in build process."
    exit 1
fi
echo "====================================================="
echo "Done"