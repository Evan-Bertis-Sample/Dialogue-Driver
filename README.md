# Dialogue-Driver
**Empowering Creativity.**  The development of branching dialogues is a notorious challenge due to its complexity, often leading developers to compromise functionality for usability. Dialogue-Driver upends this by offering a user-friendly, node-based system that enables writers and developers to craft intricate character dialogues without sacrificing tool accessibility or functionality.

## Features
- Craft intricate, branching dialogues effortlessly for any interactive software.
- Design intelligent interactions that dynamically adapt to the context.
- Utilize a user-friendly API compatible with any programming language supporting dynamically linked libraries.

## Repository Contents
This repository holds the "core" of the ```Dianode```, a tool that powers dialogue interactions. This "black box" orchestrates the magic of Dianode, although it does not generate branching dialogue itself, nor does it manage the dialogue's presentation or interaction in the target medium. Instead, the core forms the foundation upon which all driver implementations are built, acting as the backbone for the tools that generate branching dialogues.

If you aim to add new features to the Driver's core, develop GUIs for creating branching dialogue, or implement the dynamically linked library interface in a particular language, this repository is for you.

If you're looking for pre-existing implementations of the GUI or driver in a specific language (e.g., for use in software like Unity), you should look elsewhere. Below are some recommended repositories or tools:
### GUIs
- [Dianode (WIP)](https://github.com/Evan-Bertis-Sample/Dianode-Editor): A node-based GUI that was created alongside Dialogue-Driver.
### Implementations
- Currently, no implementations are available as the core is still under development.

## Building
### Prerequisites
To utilize this library, please ensure you have:
- A C++ compiler that supports C++17.
- CMake installed on your system.

### Quick Start
To begin, clone the repository:

In your target directory, execute the following command

```bash

git clone https://github.com/Evan-Bertis-Sample/Dialogue-Driver.git
```
If you plan on using the project as a library in a CMake project, there is no need to build via the command line. Just make sure that the library is added through your CMake.

If you wish to build the project as a .dll, you should use the command line. Ensure you have CMake and a C++17 compatible compiler installed on your system.

After cloning this repository, start the build process with these commands:

```bash

cd Dialogue-Driver
mkdir build
cd build
cmake ..
cmake --DBUILD_DLL=ON .
cmake --build .
```

The output will be `libdialogue_driver.dll` in the `Dialogue-Driver/bin/lib` directory.

If you are on the development branch and wish to build the tests, run this command in the build directory:

```bash

cmake --DBUILD_TEST=ON .
```

## Credits
If you decide to incorporate Dialogue-Driver into your project, kindly credit the original tool author.

Dialogue-Driver is versatile and can be used across various media types, including video games, websites, and other tools. Please credit the tool in a manner appropriate for your chosen medium.

The credit should contain the following details:

```makefile

Tool: Dialogue-Driver
Author: Evan Bertis-Sample
```

While crediting is not mandatory, it's much appreciated if you enjoyed using the tool. Please consider doing so!
