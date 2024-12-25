echo "Running executable"
EXECUTABLE=$(pwd)/build/dev/SatMotionSim
if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable not found. Run build.sh first."
    exit 1
fi
$EXECUTABLE