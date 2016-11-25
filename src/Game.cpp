//
// Created by fredrb on 9/24/16.
//

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "Game.h"
#include <iostream>


void Game::setSize(int width, int height) {
    this->window_height = height;
    this->window_width = width;
}

void Game::setPosition(int x, int y) {
    this->window_pos_x = x;
    this->window_pos_y = y;

}

void Game::setTitle(char *title) {
    this->title = title;
}

void Game::init() {

    if ( !glfwInit() ) {
        printf("%s\n", "Initialization failed");
        return;
    }

    this->initGLDisplay();

    GLFWwindow * window = glfwCreateWindow(this->window_width, this->window_height, this->title, NULL, NULL);
    glfwSetWindowPos(window, this->window_pos_x, this->window_pos_y);
    glfwMakeContextCurrent(window);

    if (!window) {
        printf("%s\n", "Window or OpenGL context creation failed");
        return;
    }


    // change to start screen
    Screen::Manager::getInstance()->change(Screen::Manager::Start);

    while ( !glfwWindowShouldClose(window) ) {

        // printf("%s\n", "Running");

        // Screen::Manager::getInstance()->getCurrent()->execute();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    printf("%s\n", "Destroying window");
    glfwDestroyWindow(window);

    printf("%s\n", "Teriminating application");
    glfwTerminate();


}

void Game::initGLDisplay() {
    glClearColor (0.0, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glOrtho(0, this->window_width, 0, this->window_height, 0.0f, 1.0f);
}
