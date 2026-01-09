# OpenCV C++ Installation Guide for Windows (MinGW)

This directory is set up with a local, pre-built version of OpenCV for C++ development using MinGW-w64.

## 1. What was done (Installation Steps)
The following steps were taken to set up this environment. You can follow these if you need to replicate this in another folder.

1.  **Prerequisites**:
    *   **MinGW-w64**: A C++ compiler for Windows (gcc/g++).
    *   **CMake**: A build tool to generate Makefiles.
    *   **Git**: To clone the repository.

2.  **Downloading OpenCV**:
    Instead of building OpenCV from source (which is time-consuming), we used a community-maintained pre-built version for MinGW.
    *   Command: `git clone https://github.com/huihut/OpenCV-MinGW-Build.git opencv`
    *   **Important**: We checked out a specific version (e.g., OpenCV-4.5.5-x64) to ensure valid binary files are present, as the master branch only contains documentation.
    *   Command: `cd opencv && git checkout OpenCV-4.5.5-x64`

3.  **Project Configuration**:
    *   Created a `CMakeLists.txt` file in the root.
    *   Set `OpenCV_DIR` to point to the local `opencv` folder: `set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/opencv")`.
    *   Used `find_package(OpenCV REQUIRED)` to load the libraries.

## 2. How to Compile and Run Your Code

### Step 1: Create a Build Directory
Open a terminal in this folder and run:
```sh
mkdir build
cd build
```

### Step 2: Generate Makefiles
Run CMake to configure the project. We specify "MinGW Makefiles" as the generator.
```sh
cmake -G "MinGW Makefiles" ..
```
*If this command fails finding the generator, ensure MinGW is in your system PATH.*

### Step 3: Compile
Build the executable:
```sh
cmake --build .
```

### Step 4: Run
Running the executable requires the OpenCV DLLs to be accessible.
The DLLs are located in `../opencv/x64/mingw/bin`.

**Option A (Temporary Environment Variable):**
Running in PowerShell:
```powershell
$env:PATH += ";$PWD/../opencv/x64/mingw/bin"
./main.exe
```

**Option B (Copy DLLs):**
Copy all `.dll` files from `../opencv/x64/mingw/bin` into your `build` folder where `main.exe` is located.
```powershell
cp ../opencv/x64/mingw/bin/*.dll .
./main.exe
```

## Troubleshooting
- **"libstdc++-6.dll not found"**: Ensure your MinGW `bin` directory is in your system PATH.
- **CMake Error**: Ensure `cmake` is installed and valid.
