void set_up_graphics()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	display = al_create_display(SCREEN_W, SCREEN_H);
	
	font = al_load_font("SourceCodePro-Regular.ttf", font_size, 0);
	//font = al_load_font("DroidSansMono.ttf", font_size, 0);
	
	big_font = al_load_font("MonospaceTypewriter.ttf", big_font_size, 0);
	white = al_map_rgb(255, 255, 255);
	black = al_map_rgb(0, 0, 0);
	red = al_map_rgb(255, 0, 0);
	blue = al_map_rgb(0, 0, 255);
	green = al_map_rgb(0, 255, 0);
	yellow = al_map_rgb(255, 255, 0);
	orange = al_map_rgb(255,165,0);
	gray = al_map_rgb(gray_intensity,gray_intensity,gray_intensity);
	transfer_color[0] = white;
	transfer_color[1] = red;
	transfer_color[2] = blue;
	transfer_color[3] = yellow;
	transfer_color[4] = green;
	transfer_color[5] = orange;

}

int key_pressed()
{
	ALLEGRO_EVENT ev;
	while (al_peek_next_event(q, &ev))
	{
		if (ev.type != ALLEGRO_EVENT_KEY_CHAR)
		{
			al_drop_next_event(q);
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int getch()
{
	ALLEGRO_EVENT ev;
	al_get_next_event(q, &ev);
	if (ev.type != ALLEGRO_EVENT_KEY_CHAR)
	{
		return 0;
	}
	return ev.keyboard.keycode;
}


