# 🖼️ OpenGL Image Renderer

A simple C++ project that loads and renders images using OpenGL and `stb_image.h`. This project demonstrates how to bind images as textures on quads using OpenGL and display them on the screen.

---

## 📌 Features

- 🔍 Load JPEG/PNG images with `stb_image`
- 🎮 Render image as texture on a quad
- 💡 Learn OpenGL basics: VAO, VBO, shaders, and textures
- 🖥️ Cross-platform (Windows/Linux)

---

## 🧰 Tech Stack

- C++
- OpenGL (Modern, 3.3+ Core)
- GLFW – Window creation and input
- GLAD – OpenGL function loader
- stb_image – Image loading



## 📂 Project Structure

opengl-image-renderer/
├── include/
│ └── stb_image.h
├── shaders/
│ ├── vertex.glsl
│ └── fragment.glsl
├── textures/
│ └── image.jpg
├── main.cpp
├── CMakeLists.txt
└── README.md




## 🛠️ Getting Started

### 1. Clone the Repository

git clone https://github.com/your-username/opengl-image-renderer.git
cd opengl-image-renderer

2. Install Dependencies

Make sure you have the following installed:

    CMake

    g++ or MSVC

    GLFW

    GLAD

    stb_image (included)

You can install dependencies via vcpkg or manually.
3. Build the Project

mkdir build
cd build
cmake ..
cmake --build .

4. Run the Executable

./OpenGLImageRenderer

📸 Screenshot


Rendered image mapped on a quad using OpenGL
🧠 Concepts Covered

    Initializing OpenGL context

    Using Vertex Array Object (VAO), Vertex Buffer Object (VBO), and Element Buffer Object (EBO)

    Writing and compiling GLSL shaders

    Loading images with stb_image.h

    Creating and binding textures in OpenGL

    Texture parameters (wrapping, filtering)

📝 License

This project is licensed under the MIT License.
rajaryan
