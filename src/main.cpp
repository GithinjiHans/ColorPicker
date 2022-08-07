#include "../include/glad/src/glad.c"
#include <GLFW/glfw3.h>
#include "../include/imgui/imgui.h"
#include <cstdlib>
#include <iostream>

void glfwSetErrorCallback(int error, const char *description) {
  fprintf(stderr, "Err no %d :%s\n", error, description);
};
float a, b, c;
float &d = a;
float &e = b;
float &f = c;
int col = 0;
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
    d = (rand() % 100 + 10) / 100.0;
    e = (rand() % 100 + 10) / 100.0;
    f = (rand() % 100 + 20) / 100.0;
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    glClearColor(a, b, c, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    std::cout << "Pressed\n";
  }
}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  GLFWwindow *window = glfwCreateWindow(400, 700, "Test", NULL, NULL);
  if (!window) {
    std::cout << "Couldn't create window\n";
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  gladLoadGL();
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);
  while (!glfwWindowShouldClose(window)) {
    glfwSetKeyCallback(window, key_callback);

    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}