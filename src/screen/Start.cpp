#include "Start.h"

Screen::Start::Start() {
    this->message = new Render::Text("Mind Blocs", 350, 310);
}

Screen::Start::~Start() {
    delete this->message;
}

void Screen::Start::show(double time) {
    this->message->render();
};

void Screen::Start::keypress(int key, int scancode, int mods) {

    switch (key) {
        case GLFW_KEY_ENTER:
            Screen::Manager::getInstance()->change(Screen::Manager::Play);
        break;
    }
};

void Screen::Start::click(double x, double y, int mods) {};