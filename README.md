## What is this?

This is a setup in mujoco for tactile sensing using artificial whiskers, integrated with ROS.

This is not an iteration of MuJoCo or a kind of repo to be pushed upstream.

## Building

### Requirements

To compile this program ROS2 Iron is needed, along with my [interfaces package](https://github.com/nonbinary-duck/ros2-interfaces).

### Script

```bash
# Execute cmake
mkdir build && cd build && cmake ..

# Compile the code
# It is not necessarily a bad thing for make to be assigned more jobs than there are virtual cores
make -j40

# Install locally (into ./build/install)
cmake --install . --prefix ./install

# Make plugins directory in local install bin & copy relevant plugins
# This directory is what the `simulate` application expects (we don't change this behaviour)
mkdir ./install/bin/mujoco_plugin

# Make a symbolic link to the four default plugins
ln -sr ./lib/libactuator.so   ./install/bin/mujoco_plugin/.
ln -sr ./lib/libelasticity.so ./install/bin/mujoco_plugin/.
ln -sr ./lib/libsdf.so        ./install/bin/mujoco_plugin/.
ln -sr ./lib/libsensor.so     ./install/bin/mujoco_plugin/.

# CD back to project root
cd ..

# Uncomment below to run simulate application with whisker model (from project root after running above command)
# ./build/install/bin/simulate ./whisker-model/whisker_model.xml
```

## What is MuJoCo

See the [original readme](./MJREADME.md) or [Google Deepmind's MuJoCo GitHub Repo](https://github.com/google-deepmind/mujoco)