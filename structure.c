void install_structure(int W, int H)
{
	real in_fit = 30;
	real dx = (W-in_fit)/(L-1);
	real dy;
	int c = 0;
	int adjust = 1;
	for (int i = 0; i < L; i++)
	{
		dy = H/neurons_in_layer[i]-10;
		adjust = 0;
		for (int j = 0; j < neurons_in_layer[i]; j++)
		{
			p[c][0] = in_fit/2+i*dx;
			p[c][1] = H/2 + adjust*dy;
			if (j%2 == 0) adjust = abs(adjust) + 1; else adjust *= -1;
			c++;
		}
	}
}

void plot_structure(real left, real down, real r, real t)
{
	//current_color = white;
	int brightness = 0;
	for (int i= 0; i < N; i++)
	{
		for(int j = 0; j< N; j++)
		{
			if (C[i][j])
			{
				
				switch(struct_mode)
				{
					case 0:
						brightness = (int) (( fabs(W[i][j]) / WEIGHT_LIMIT )*256);
						if (W[i][j] < 0) current_color = blue; // al_map_rgb(0,0,brightness);
						else current_color = red; //al_map_rgb(brightness, 0,0);
						if (brightness > threshold) al_draw_line(left+p[i][0],down+ p[i][1],left+p[j][0],down+ p[j][1], current_color,thickness);	
						break;
					case 1:
						brightness = (int) (( fabs(W[i][j]) / WEIGHT_LIMIT )*256);
						if (W[i][j] < 0) current_color = al_map_rgb(0,0,brightness);
						else current_color = al_map_rgb(brightness, 0,0);
						al_draw_line(left+p[i][0],down+ p[i][1],left+p[j][0],down+ p[j][1], current_color,thickness);
						break;
					case 2:
						brightness = (int) (( fabs(W[i][j]) / WEIGHT_LIMIT )*256);
						if (brightness >threshold)
						{

						current_color = al_map_rgb(brightness, brightness, brightness);
						al_draw_line(left+p[i][0],down+ p[i][1],left+p[j][0],down+ p[j][1], current_color,thickness);
						}
						break;
					case 3:
						brightness = (int) (( fabs(W[i][j]) / WEIGHT_LIMIT )*256);
						if (brightness >threshold)
						{
							current_color =  random_color();
							al_draw_line(left+p[i][0],down+ p[i][1],left+p[j][0],down+ p[j][1], current_color,thickness);
						}
						break;



				}


			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		//current_color = transfer_color[layer_transfer[d[i]]];
		current_color = white;
		if (struct_mode == 2) current_color = yellow;
		al_draw_circle(left+p[i][0],down+ p[i][1], r, current_color, t);
	}
	current_color=gray;
	//al_draw_rectangle(left-10, down-10,left+structure_W+10, down+structure_H+10,gray,1);
	//al_draw_line(left-10, down-10, left-10,down+structure_H+10, current_color, 2);
	//al_draw_rectangle(structure_L-10, structure_D-10,structure_L+structure_W+10, structure_D+structure_H+10,gray,1);
	//al_draw_line(structure_L-10, structure_D-10, structure_L+structure_W+10,structure_D-10, current_color, 2);
	//al_draw_line(structure_L-10, structure_D+10+structure_H, structure_L+structure_W+10,structure_D+structure_H+10, current_color, 2);
	//al_draw_line(structure_L+structure_W+10, structure_D-10,structure_L+structure_W+10, structure_D+structure_H+10,current_color,2);
	//al_draw_line(LEFT-2*pixel_width, Down, LEFT-2*pixel_width, Down2, white, 2);
	//al_draw_line(Left, Down, Left, Down2, white, 2);adasdasdasda
	
}

void reset()
{
	
	neurons_in_layer[0] = 1; layer_transfer[0] = 0;
	neurons_in_layer[1] = 7; layer_transfer[1] = 2;
	neurons_in_layer[2] = 7; layer_transfer[2] = 2;
	neurons_in_layer[3] = 7; layer_transfer[3] = 2;
	neurons_in_layer[4] = 7; layer_transfer[4] = 2;
	neurons_in_layer[5] = 1; layer_transfer[5] = 0;
	set_up_network();
}