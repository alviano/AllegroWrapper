#include "Drawable.h"

#include "Allegro.h"

const Mouse& Drawable::getMouse() const {
    return Allegro::getInstance()->getMouse();
}

const Keyboard& Drawable::getKeyboard() const {
    return Allegro::getInstance()->getKeyboard();
}

