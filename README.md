Obsidian: A modular early stage 2D game & rendering engine using SDL2 for 2D game development.

# Features
- Supports Window
- Fast 2D Rendering(Sprites, Texture)
- Event Handling
- Texture & Asset Manager
- Game Loop & deltaTime intigration
- Animation System
- TileMap System
- Custome Math library
- Engine - Application Architecture

# Getting Started( Installation Guide )
Visual Studio 2019 or 2022 is recommended. We focus on window build.

**1. Downloading the Repository :**

Start by cloning the repository with ```git clone https://github.com/HetLukhi/Obsidian```

**2. Build With CMake :**
- Create build folder : ```mkdir build```
- Go to the folder : ```cd build```
- CMake : ```cmake ..```
- Build CMake : ```cmake --build .```
  
Wait for Few Minutes untill building process finished.

**3. Configuring the dependencies :**

After building the project, you must copy the required SDL2 DLL files to the executable folder.

- Copy the following files :

   - From:
     `build/X64-Debug/_deps/SDL2_image-build/`
     → `SDL2_imaged.dll`

   - From:
     `build/X64-Debug/_deps/SDL2-build/`
     → `SDL2d.dll`
- Paste both files into :
   `build/X64-Debug/`

Without these DLLs, the application will not run.

**4. Run Target :**

Select ```Sandbox.exe``` as run target. ```or``` Run Executable from ```build/X64-Debug/Sandbox.exe```


