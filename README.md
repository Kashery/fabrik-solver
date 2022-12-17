# Simple Fabrik Solver
## Fabrik inverse kinematics method
The Fabrik method for inverse kinematics is a heuristic approach to solving the IK task. It iteratively approximates the links positions in 2D or 3D space by going back and forth through the links.

For more info about the method and algorithm involved visit one of below mentioned sources:
- [General introduction to FABRIK by Dr. Andreas Aristidou](http://andreasaristidou.com/FABRIK.html)
- [Very informative video explaining the method](https://www.youtube.com/watch?v=UNoX65PRehA)

## Build locally
### Unix
on any linux distro with cmake and gcc installed
```bash
mkdir build
cd build
cmake ..
make
cd ..
./bin/fabrik-solver <options>
```
or simply run the script
```bash
sh build.sh
```
### Windows
figure it out yourself, I can't be bothered
## Running the solver
After building from source there will be a test robotic arm hardcoded you can check it out and tweak it to your liking, in near future there will be an option to define it at runtime.

the executable takes three doubles as coordinates of an end effector it will attempt to approximate the solution to the IK and spit it out as well as every step it took in order to achieve it. the solution has a margin of error set to the double epsilon defined in float.h lib in C.

### Example

```bash
./bin/fabrik-solver 2.0 1.0 4.0 
```
output:
```
-- (0.00000,0.00000,0.00000) -- 5.19615 -- (3.00000,3.00000,3.00000) -- 3.16228 -- (6.00000,3.00000,2.00000) -- 2.23607 -- (6.00000,5.00000,1.00000)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.77213,4.09175,2.66780) -- 3.16228 -- (3.92011,1.81275,3.10640) -- 2.23607 -- (2.02742,1.01160,3.98724)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76576,4.09603,2.66545) -- 3.16228 -- (3.89310,1.80070,3.11924) -- 2.23607 -- (2.00013,1.00006,3.99994)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
finished after 8 passes
 -- (0.00000,0.00000,0.00000) -- 5.19615 -- (1.76573,4.09605,2.66544) -- 3.16228 -- (3.89297,1.80065,3.11930) -- 2.23607 -- (2.00000,1.00000,4.00000)
```
