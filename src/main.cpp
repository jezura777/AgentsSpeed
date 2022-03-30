#include "main.hpp"

int main()
{
	
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();

    al_install_keyboard();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    ALLEGRO_FONT* ikaros = al_load_ttf_font("ikaros.ttf", 20, 0);
    ALLEGRO_FONT* cynax = al_load_ttf_font("cynax.ttf", 20, 0);

    const char title[ALLEGRO_NEW_WINDOW_TITLE_MAX_SIZE] = "AgentsSpeed";
    void al_set_window_title(disp, title);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while(1)
    {
        // game::update();
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(ikaros, al_map_rgb(255, 255, 255), 0, 0, 0, "abcdefghijklmnopqrstuvwxyz!@#$%^&_+\\/-?><\';\":()");
            al_draw_text(cynax, al_map_rgb(255, 255, 255), 0, 40, 0, "abcdefghijklmnopqrstuvwxyz!@#$%^&_+\\/-?><\';\":()");
            al_flip_display();

            redraw = false;
        }
    }

    // game::~game();

    al_destroy_font(ikaros);
    al_destroy_font(cynax);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}