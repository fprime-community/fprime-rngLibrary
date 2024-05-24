# RNG Library - An Example of Subtopologies within F'

This repository is a working build of an F Prime subtopology, per its related documentation. The library itself is located in the [RNGLibrary](/RNGLibrary/) folder, while the main deployment using the subtopology is [MainDeployment](/MainDeployment/).

## Using this project

Everything internally has been wired together, so it works right out of the box.

```bash
# clone this repository
git clone https://github.com/mosa11aei/fprime-rngLibrary.git
cd fprime-rngLibrary

# clone the fprime submodule
git submodule init && git submodule update

# build the deployment, and run F Prime GDS.
cd MainDeployment
fprime-util generate && fprime-util build --all -j4
fprime-gds
```