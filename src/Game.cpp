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

void mouseCallback(GLFWwindow* window, int button, int action, int mods) {

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {

        double x, y;
        glfwGetCursorPos(window, &x, &y);

        Screen::Manager::getInstance()->getCurrent()->click(x, y, mods);
    }

}

void errorCallback(int code, const char * msg) {
    std::cout << "GLFW ERROR: " << code << " - " << msg  << "\n";
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
    this->initGLC();
    this->loadTilesFile();

    glfwSetKeyCallback(window, keyboardCallback);
    glfwSetMouseButtonCallback(window, mouseCallback);
    glfwSetErrorCallback(errorCallback);

    Screen::Manager * manager = Screen::Manager::getInstance();
    manager->setScreenWidth(this->window_width);
    manager->setScreenHeight(this->window_height);

    // change to start screen
    Screen::Manager::getInstance()->change(Screen::Manager::Start);

    Timer * timer = new Timer();
    double time = 0;

    while ( !glfwWindowShouldClose(window) ) {

        timer->start();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        manager->getCurrent()->show(time);

        glfwSwapBuffers(window);
        glfwPollEvents();

        timer->stop();
        time = timer->getElapsedTime();
    }

    printf("%s\n", "Destroying window");
    glfwDestroyWindow(window);

    printf("%s\n", "Teriminating application");
    glfwTerminate();


}

void Game::initGLDisplay() {
    glClearColor (0.6, 0.6, 0.6, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glOrtho(0, this->window_width, 0, this->window_height, 0.0f, 1.0f);
}

void Game::initGLC() {
    GLint ctx = glcGenContext();
    glcContext(ctx);

    GLint font = glcGenFontID();
    glcNewFontFromFamily(font, "Ubuntu");

    glcFontFace(font, "Bold");
    glcFont(font);
    glcScale(24.f, 24.f);

}

void Game::loadTilesFile() {

    int nTextures = 3;
    unsigned int * ids = new unsigned int[7];

    glGenTextures(nTextures, ids);

    for (int i = 0; i < nTextures; i++) {

        std::string filename = "resources/tile" + std::to_string(i) + ".ptm";

        File::PTMFileReader reader = File::PTMFileReader();

        File::t_image img = reader.loadImage( (char *) filename.c_str());
        SpriteLoader loader = SpriteLoader(img);

        Render::Image* image = loader.getImage();

        Tiles::Tile * tile;

        glBindTexture(GL_TEXTURE_2D, ids[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getWidth(), image->getHeight(), 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, image->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        tile = new Tiles::Tile(i, ids[i]);
        Tiles::TileSet::getInstance()->addTile(tile);

        delete image;
    }

}
