echo "Initialising build process"

BUILD_DIR=$(pwd)/build/dev #output of pwd command is inserted into the variable BUILD_DIR
CMAKE_FILE=$(pwd)/CMakeLists.txt

if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

echo "Build directory: $BUILD_DIR"
echo "====================================================="

rm -rf "$BUILD_DIR/*"
echo "Cleaning DIR and Running cmake"
cmake -S $(pwd) -B "$BUILD_DIR"

echo "====================================================="
echo "Running make"
make -C "$BUILD_DIR"
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