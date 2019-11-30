# Hexapod

## Installation
* Create catkin workspace in home directory 
```
cd ~
mkdir -a hex_ws/src
cd hex_ws/src
```
* Make a folder for the `hexapod` package
```
mkdir hexapod
cd hexapod
```
* Initialize git and add the remote repo 
```
git init
git remote add hex https://github.com/KirkBoyd/Hexapod2020.git
git pull hex master
```
* Build, Reload ROS package list and Source Workspace
```
cd ~/hex_ws
catkin build
rospack profile
source devel/setup.bash
```
* Add and append aliases for changing directories and sourcing workspace; Reload Terminal
```
echo 'alias cdx = "cd ~/hex_ws/src/hexapod/"' >> ~/.bashrc
echo 'alias swsx = "source ~/hex_ws/devel/setup.bash"' >> ~/.bashrc
# Reload Terminal
source ~/.bashrc 
```
## Usage
Always make sure to source the workspace manually or by using the above alias **`swsx`**

### Launch Simulation
```
roslaunch hexapod hexapod.launch
```
