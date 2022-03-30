#pragma once
#include "main.hpp"

class game {

private:

    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* disp;
    ALLEGRO_FONT* font;
    ALLEGRO_EVENT event;
    bool redraw;

public:

    game(ALLEGRO_TIMER* time, ALLEGRO_EVENT_QUEUE* que, ALLEGRO_DISPLAY* dis, ALLEGRO_FONT* fon); // init
    ~game(); // deinit
    update(); // update


}