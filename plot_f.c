void plot_function_against_data(float x0, float x1, int ppu)
{
	real FF = 0, ff = 0;
	float x;
	float Down = DOWN-(max_f-1)*ppu-10;
	float Down2 = DOWN+(max_f+1)*ppu + 10;
	float Left = LEFT + ppu*(x1-x0) + 10;
	
	//current_color = al_map_rgb(rand()%256,rand()%256,rand()%256);     //(transfer_color[rand()%5];
	al_draw_rectangle(LEFT-10, Down, Left, Down2,white,1);
	if (hide_menu == 0) for (int i = 0; i < data_points; i++)
	{
		//al_draw_filled_rectangle(LEFT + ppu*(data[i][0] - x0), DOWN + ppu * (1 - data[i][1]), LEFT + ppu*(data[i][0] - x0) + pixel_width,
		 //DOWN + ppu * (1 - data[i][1])+pixel_height, gray  );
		 al_draw_circle(LEFT+ppu*(data[i][0] - x0),DOWN + ppu * (1 - data[i][1]),3, i%2==0?red:blue,2);
	}
	for (int i = 0; i < (ppu * (x1 - x0)); i++)
	{
		
		x = x0 + (float)i / ppu;
		FF = F(F_code,x);
		ff = f(x);
		/*
		if (show_F_flag == 1)
		{
		al_draw_filled_rectangle(LEFT + i, DOWN + ppu * (1 - FF), LEFT + i + pixel_width,
		 DOWN + ppu * (1 - FF)  + pixel_height, gray  );
		}
		*/
		
		al_draw_filled_rectangle(LEFT + i, DOWN + ppu * (1 - ff), LEFT + i + pixel_width+2,
		 DOWN + ppu * (1 - ff)  + pixel_height+2, al_map_rgb(rand()%255,rand()%255,rand()%255));
		 
		 //white);
		 
		 //al_map_rgb(rand()%255,rand()%255,rand()%255));
		 //al_map_rgb(rand()%128+128,rand()%128+128,rand()%128+128));

		
		
		
		//al_put_pixel(LEFT + i, DOWN + ppu * (1 - f(x)), white);
		//al_put_pixel(LEFT + i, DOWN + ppu * (1 - f(x)) + 1, white);
				}

}

void plot_functions(float x0, float x1, int ppu)
{
	real FF = 0, ff = 0;
	float x;
	float Down = DOWN-(max_f-1)*ppu-10;
	float Down2 = DOWN+(max_f+1)*ppu + 10;
	float Left = LEFT + ppu*(x1-x0) + 10;
	
	//current_color = al_map_rgb(rand()%256,rand()%256,rand()%256);     //(transfer_color[rand()%5];
	al_draw_rectangle(LEFT-10, Down, Left, Down2,gray,1);
	
	//if (rand()%2 == 0) current_color = blue; else current_color = red;
	for (int i = 0; i < (ppu * (x1 - x0)); i++)
	{
		
		x = x0 + (float)i / ppu;
		FF = F(F_code,x);
		ff = f(x);
		if (show_F_flag == 1)
		{
		al_draw_filled_rectangle(LEFT + i, DOWN + ppu * (1 - FF), LEFT + i + pixel_width,
		 DOWN + ppu * (1 - FF)  + pixel_height, blue  );
		}
		
		al_draw_filled_rectangle(LEFT + i, DOWN + ppu * (1 - ff), LEFT + i + pixel_width+2,
		 DOWN + ppu * (1 - ff)  + pixel_height+2, red);
		 // al_map_rgb(rand()%255,rand()%255,rand()%255));
		 //al_map_rgb(rand()%128+128,rand()%128+128,rand()%128+128));

		
		
		
		//al_put_pixel(LEFT + i, DOWN + ppu * (1 - f(x)), white);
		//al_put_pixel(LEFT + i, DOWN + ppu * (1 - f(x)) + 1, white);
				}

}
