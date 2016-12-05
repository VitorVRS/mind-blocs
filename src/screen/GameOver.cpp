#include "GameOver.h"

Screen::GameOver::GameOver() {
    this->message = new Render::Text("GAME OVER", 350, 310);
}

Screen::GameOver::~GameOver() {
    delete this->message;
}


void Screen::GameOver::show(double time) {
    this->message->render();
}

void Screen::GameOver::keypress(int key, int scancode, int mods) {

    switch (key) {
        case GLFW_KEY_ENTER:
            Screen::Manager::getInstance()->change(Screen::Manager::Start);
        break;
    }

};

void Screen::GameOver::click(double x, double y, int mods) {};