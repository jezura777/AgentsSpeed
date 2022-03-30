#include "game.hpp"

// init
game::game(ALLEGRO_TIMER* time, ALLEGRO_EVENT_QUEUE* que, ALLEGRO_DISPLAY* dis, ALLEGRO_FONT* fon) {

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();

    al_install_keyboard();

    timer = time;
    queue = que;
    disp = dis;
    font = fon;

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    redraw = true;
    ALLEGRO_EVENT ev;
    event = ev;

}

// deinit
game::~game() {

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

}

// update
void game::update() {

    al_wait_for_event(queue, &event);

    if(event.type == ALLEGRO_EVENT_TIMER)
        redraw = true;
    else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
        break;

    if(redraw && al_is_event_queue_empty(queue))
    {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
        al_flip_display();

        redraw = false;
    }

}