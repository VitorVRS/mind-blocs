//
// Created by fredrb on 9/24/16.
//

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "Game.h"
#include <iostream>

#include "tiles/TileMap.h"
#include "tiles/TileSet.h"
#include "tiles/Tile.h"
#include "render/Diamond.h"

// GLFW FUNCTIONS
void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    if (action == GLFW_PRESS) {
        Screen::Manager::getInstance()->getCurrent()->keypress(key, scancode, mods);
    }

}

// END GLFW FUNCTIONS


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


    GLFWwindow * window = glfwCreateWindow(this->window_width, this->window_height, this->title, NULL, NULL);
    glfwSetWindowPos(window, this->window_pos_x, this->window_pos_y);
    glfwMakeContextCurrent(window);

    if (!window) {
        printf("%s\n", "Window or OpenGL context creation failed");
        return;
    }

    this->initGLDisplay();

    glfwSetKeyCallback(window, keyboardCallback);

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();
    tileSet->addTile(new Tiles::Tile(1));
    tileSet->addTile(new Tiles::Tile(2));
    tileSet->addTile(new Tiles::Tile(3));
    tileSet->addTile(new Tiles::Tile(4));
    tileSet->addTile(new Tiles::Tile(5));
    tileSet->addTile(new Tiles::Tile(6));


    // change to start screen
    Screen::Manager::getInstance()->change(Screen::Manager::Play);

    while ( !glfwWindowShouldClose(window) ) {

        glClear(GL_COLOR_BUFFER_BIT);

        Screen::Manager::getInstance()->getCurrent()->show();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    printf("%s\n", "Destroying window");
    glfwDestroyWindow(window);

    printf("%s\n", "Teriminating application");
    glfwTerminate();


}

void Game::initGLDisplay() {
    glClearColor (0.6, 0.6f, 0.6f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
    // glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glOrtho(0, this->window_width, 0, this->window_height, 0.0f, 1.0f);
}