# Dialogue-Driver
**Let writers write.** Building branching dialogue is infamously difficult, both to implement, and to use. Often times, developers must sacrifice features to make dialogue tools writer friendly. This is not the case with this dialogue driver. Using a node-based, simple to use system, writers and developers are able to curate complex character interactions without sacrificing easy-to-use tools or features.

## Features
- Easily create branching dialogue for any interactive software
- Create intelligent interactions that change depending on the context
- Use an intuitive API that is in any programming language that supports dynamically linked libraries


## What is in this Repo?
This repo contains the "core" of Dialogue Driver. The core is responsible for handling dialogue interactions, and is a "black box" that makes the handles the magic of Dialogue-Driver. The core *is not* responsible for building branching dialogue, nor is it responsible for display and handling of dialogue in the target medium. The core *is*, however, is where implementations for the driver can be built upon, and is the backbone of tools that create the branching dialogue.

Individuals who seek to add core features to the Driver, build GUI's to build branching dialogue, or implement the dynamically linked library interface in a given language should use this repository.

If you are searching for an existing implementation of the GUI or driver in a language (to use this tool in software like Unity, for example), you should look elsewhere. Here are some recommended repos/tools to checkout:

### GUIs
- There are no GUIs at the moment, as the core is still under development

### Implementations
- There are no implementations at the moment, as the core is still under development

## Building
This project is build with CMake. Before building the project, ensure that you have CMake installed on your system, and a compiler compatible with at least C++17 features.

In your target directory, run the command
```
git clone https://github.com/Evan-Bertis-Sample/Dialogue-Driver.git
```

This will clone this repo onto your computer. Then, we can commence the build process. Run the following commands:
```
cd Dialogue-Driver
mkdir build
cd build
cmake .
make
```

If you are building the development version, you can ensure that the build was successful by running:
```
ctest
```
All tests should pass, meaning it should be safe for you to continue development.

## Credits
If you choose to use Dialogue-Driver as a part of your project, please give credit to the original author of the tool.

As Dialogue-Driver can be used in many forms of media, including video games, websites and other tools, please give credit in whatever form makes sense for the medium.

In your credit, please include the following information:
```
Tool: Dialogue-Driver
Author: Evan Bertis-Sample
```
Do not feel obliged to give credit to the tool. However, if you enjoyed using it, please consider giving credit!