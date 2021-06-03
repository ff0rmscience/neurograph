

int main(int argc, char **argv)
{
	reset();
	set_up_graphics();
	
	//display_key();
	int x_index = 0;
	double x = 0, y=0;
	double error = 0;
	double error_sum = 0;

	
	// neurons_in_layer[3] = 10 ;layer_transfer[3] = 0;
	
	rate = .05;
	install_connections();
	initialize_weights(-.7, .7);
	batch_size = 100;
	amplify = 1.0;

	install_structure(structure_W,structure_H);


	load_new_data();
	while (1)
	{
		//erase_structure();
		plot_structure(structure_L,structure_D,5,3);
		if (data_mode) batch_size = data_points;
		for (int j = 0; j < batch_size; j++)
		{
			if (key_pressed())
			{
				
				
				respond_to_input();
				al_clear_to_color(al_map_rgb(0, 0, 0));
				//al_flip_display();
				//erase_settings();
				display_settings();
				//erase_functions(left,right,image_size);
				if (display_mode == 0 || display_mode == 1)
				{
					if (data_mode) plot_function_against_data(left, right, image_size);
					else plot_functions(left, right, image_size);
				}
				//al_flip_display();
				//erase_structure();
				if (display_mode == 0 || display_mode == 2)
				{
					plot_structure(structure_L,structure_D,5,3);
				}
			}

			if (data_mode)
			{
				x_index =  rand()%data_points;
				x = data[x_index][0];
				y = data[x_index][1];
				error = f(x) - y;
			}
			else
			{
				x = random_double(left, right);
				error = f(x) - F(F_code,x);
			}
			error_sum += fabs(error);
			backpropagate(error);
			

		}
		mean_error = error_sum/batch_size;
		error_sum = 0;
		update_parameters();

		if (1)
		{
			
			al_clear_to_color(al_map_rgb(0, 0, 0));
			//erase_functions(left,right,image_size);
			if (display_mode == 0 || display_mode == 1)
			{
			if (data_mode) plot_function_against_data(left, right, image_size);
			else plot_functions(left, right, image_size);
			}
			if (hide_menu == 0 ) display_settings();
			if (display_mode == 0 || display_mode == 2)
			{
				plot_structure(structure_L,structure_D,5,3);
			}
			//if (menu_flag == 1) show_menu();
			
			//plot_functions(left, right, image_size);
			al_flip_display();
			//al_clear_to_color(black);
			//erase_state();
			//display_state();
			//erase_settings();
			//display_settings();
			//display_mean_error();
			//display_key();
			//update_stats();
		}
		
	}
}	
