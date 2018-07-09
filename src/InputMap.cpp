#include <Mojagame.h>

InputMap::InputMap() {
    memset(_keys, 0, sizeof(bool) * KEYBOARD_KEY_LAST);
}

void InputMap::onKeyDown(int keyCode) {
    _keys[keyCode] = true;
}

void InputMap::onKeyUp(int keyCode) {
    _keys[keyCode] = false;
}

bool InputMap::isKeyDown(int keyCode) {
    return _keys[keyCode];
}