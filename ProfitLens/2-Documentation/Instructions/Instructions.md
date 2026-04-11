# ProfitLens – Setup & Usage Instructions

This document provides step-by-step instructions to clone, configure, and run the **ProfitLens** project on a new machine using Visual Studio 2026. The setup is designed so that the project runs immediately after cloning, with no external installations required.

## Prerequisites

The following must already be available on the system:

- Windows OS (x64)
- Visual Studio 2026 installed with:
  - Desktop Development with C++ workload
  - MSVC toolset (latest available)

No additional installations (like SFML) are required, as all dependencies are included in the repository.

## 1. Clone the Repository

```bash
git clone <your-repository-link> "Directory to save cloned repo"
```

Or download as ZIP and extract.

## 2. Open the Project in Visual Studio

1. Navigate to:
   ```
   ProfitLens/Program Files/
   ```
2. Open the `.sln` file

If no solution file is present:

- Create an Empty C++ Project
- Add all `.cpp` and `.hpp` files from `Program Files/`

## 3. Configuration (IMPORTANT)

Set:
```
Configuration: Debug
Platform: x64
```

## 4. Required Project Settings

### 4.1 Include Directories

Go to:
```
Project Properties → C/C++ → General → Additional Include Directories
```

Add:
```
$(ProjectDir)Header Files\External Headers\SFML\include
$(ProjectDir)Header Files\Internal Headers
```

### 4.2 Library Directory

Go to:
```
Project Properties → Linker → General → Additional Library Directories
```

Add:
```
$(ProjectDir)Header Files\External Headers\SFML\lib
```

### 4.3 Linker Input

Go to:
```
Project Properties → Linker → Input → Additional Dependencies
```

Add:
```
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
```

## 5. DLL Setup (IMPORTANT – PRECONFIGURED)

The required SFML `.dll` files for Debug mode are already provided in the repository.

Ensure that the following files exist in:
```
ProfitLens/x64/Debug/
```

Required DLLs:
```
sfml-graphics-d-3.dll
sfml-window-d-3.dll
sfml-system-d-3.dll
```

No Post-Build Event is required.

## 6. Optimization & Linking Settings

To ensure compatibility and prevent build/link issues, verify the following settings:

### Disable Optimization

```
C/C++ → Optimization → Optimization = Disabled (/Od)
```

### Disable Whole Program Optimization

```
Linker → Optimization → Whole Program Optimization = No
```

### Disable Incremental Linking

```
Linker → General → Enable Incremental Linking = No
```

### Disable Link Time Code Generation

```
Linker → Optimization → Link Time Code Generation = Default
```

## 7. Folder Structure Verification

Ensure the following structure exists or similar to the one in the ProfitLens ReadMe.md file:

```
ProfitLens/
├─ 1-Program Files/
├─ 2-Documentation/
├─ 3-SystemDatabase/
│  └─ Database.csv
├─ 4-TestCases/
│  └─ ReplayTest.csv
├─ 5-Assets/
│  └─ Fonts/
│     └─ DMSans.ttf
├─ x64/
│  └─ Debug/
│     ├─ sfml-graphics-d-3.dll
│     ├─ sfml-window-d-3.dll
│     └─ sfml-system-d-3.dll
```

## 8. Running the Project

1. Set `ProfitLens.cpp` as startup file
2. Build the solution (Ctrl + Shift + B)
3. Run (F5)

Expected behavior:

- SFML window opens
- Application runs without missing DLL errors

## 9. File Paths Used in Project

All paths are relative:
```cpp
"Assets/Fonts/DMSans.ttf"
"SystemDatabase/Database.csv"
"TestCases/ReplayTest.csv"
```
Do NOT use absolute paths.

## 10. Troubleshooting

### Headers not found

- Ensure both include paths are added

### Linker errors

- Ensure `.lib` files are added correctly

### Runtime DLL error

- Ensure DLLs exist in `x64/Debug/`

### Font not loading

- Ensure:
```
assets/fonts/DMSans.ttf
```
exists. You may add other fonts if necessary.

## 11. Notes for Contributors

- Do not modify SFML files
- Do not change folder structure
- Keep paths relative
- Maintain separation of logic and UI

## Summary

This setup ensures:
- Zero external dependency installation
- Pre-bundled runtime libraries
- Immediate execution after cloning
- Consistent behavior across systems

The project is fully self-contained and ready for development upon setup.