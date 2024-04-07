#!/bin/bash

# An ugly script to rebuild quickly

# Check if we're (probably) in the build directory
if [ ! -f "./bin/simulate"  ] || [ ! -f "./mujocoConfig.cmake" ]; then
	echo "Execute this script when in an existing MuJoCo build directory"
	exit
fi

cmake ..

make -j40

cmake --install . --prefix ./install

if [ ! -d "./install/bin/mujoco_plugin" ]; then
	mkdir ./install/bin/mujoco_plugin

	ln -sr ./lib/libactuator.so   ./install/bin/mujoco_plugin/.
	ln -sr ./lib/libelasticity.so ./install/bin/mujoco_plugin/.
	ln -sr ./lib/libsdf.so        ./install/bin/mujoco_plugin/.
	ln -sr ./lib/libsensor.so     ./install/bin/mujoco_plugin/.
fi
