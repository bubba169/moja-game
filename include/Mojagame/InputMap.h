#pragma once

class InputMap {

    public:
        InputMap();
        void onKeyUp(int keyCode);
        void onKeyDown(int keyCode);

        bool isKeyDown(int keyCode);

    private:
        bool _keys[KEYBOARD_KEY_LAST];

};