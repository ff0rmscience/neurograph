void respond_to_input()
{
	keyboard_input = getch();
	switch (keyboard_input)
	{
	case ALLEGRO_KEY_Q:
		exit(0);
		break;
	case ALLEGRO_KEY_RIGHT:
		increase_setting(current_setting);
		break;
		//rate += rate_increment;
		break;
	case ALLEGRO_KEY_LEFT:
		decrease_setting(current_setting);
		break;
		//rate -= rate_increment;
	case ALLEGRO_KEY_UP:
		if (current_setting > 0) current_setting--; else current_setting = number_of_settings - 1;
		break;
	case ALLEGRO_KEY_DOWN:
		if (current_setting < number_of_settings - 1) current_setting++; else current_setting = 0;
		break;
		
	case ALLEGRO_KEY_W:
		initialize_weights(-.7,.7);
		//set_up_network();
		break;
	case ALLEGRO_KEY_F:
		if (show_F_flag == 1) show_F_flag = 0; else show_F_flag =1;
		break;
	case ALLEGRO_KEY_M:
		image_size += 20;
		break;
	case ALLEGRO_KEY_N:
		image_size -= 20;
		break;
	case ALLEGRO_KEY_C:
		al_clear_to_color(black);
		break;
	case ALLEGRO_KEY_R:
		reset();
		al_clear_to_color(black);
		break;
		
	case ALLEGRO_KEY_H:
		if (hide_menu == 1) hide_menu= 0; else hide_menu =1;
		break;
	}
}