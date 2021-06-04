void load_setting_content()
{
	setting_content[0].floating = rate;
	setting_content[1].floating = amplify;
	setting_content[2].integer = batch_size;
	setting_content[3].integer = neurons_in_layer[0];
	setting_content[4].integer = neurons_in_layer[1];
	setting_content[5].integer = neurons_in_layer[2];
	setting_content[6].integer = neurons_in_layer[3];
	setting_content[7].integer = neurons_in_layer[4];
	setting_content[8].integer = neurons_in_layer[5];
	strcpy(setting_content[9].str, trans_desc[layer_transfer[0]]);
	strcpy(setting_content[10].str, trans_desc[layer_transfer[1]]);
	strcpy(setting_content[11].str, trans_desc[layer_transfer[2]]);
	strcpy(setting_content[12].str, trans_desc[layer_transfer[3]]);
	strcpy(setting_content[13].str, trans_desc[layer_transfer[4]]);
	strcpy(setting_content[14].str, trans_desc[layer_transfer[5]]);
	setting_content[15].integer = F_code;
	setting_content[16].integer = data_points;
	setting_content[17].floating = noise;
	setting_content[18].integer = data_mode;
	setting_content[19].integer = menu_flag;
	setting_content[20].integer = LEFT;
	setting_content[21].integer = DOWN;
	setting_content[22].integer = structure_W;
	setting_content[23].integer = structure_H;
	setting_content[24].integer = structure_L;
	setting_content[25].integer = structure_D;
	setting_content[26].integer = image_size;
	setting_content[27].integer = stats_left;
	setting_content[28].integer = stats_down;
	setting_content[29].integer = display_mode;
	setting_content[30].integer = struct_mode;
	setting_content[31].integer = pixel_height;
	setting_content[32].integer = pixel_width;
	setting_content[33].integer = thickness;
	setting_content[34].integer = threshold;
	setting_content[35].integer = data_size;
	setting_content[36].integer = font_number;



}

void erase_settings()
{
	al_draw_filled_rectangle(0, stats_down,300, stats_down+number_of_settings*s_height+200,black);
	//al_flip_display();
}


void display_setting(nat setting_number)
{
  if (setting_number != current_setting) current_color = white; else current_color = yellow;
  switch(setting_code[setting_number])
    {
    case 0:
        al_draw_textf(font, current_color, stats_left, stats_down +setting_number*s_height,
        ALLEGRO_ALIGN_LEFT, "%s%5d",setting_desc[setting_number], setting_content[setting_number].integer);
        break;
    case 1:
        al_draw_textf(font, current_color, stats_left, stats_down +setting_number*s_height,
        ALLEGRO_ALIGN_LEFT, "%s%5.2f",setting_desc[setting_number], setting_content[setting_number].floating);
        break;
    case 2:
        al_draw_textf(font, current_color, stats_left, stats_down +setting_number*s_height,
        ALLEGRO_ALIGN_LEFT, "%s%s",setting_desc[setting_number], setting_content[setting_number].str);
        break;

    }
}

void increase_setting(int setting)
{
	switch(setting)
	{
		case 0: rate += rate_increment;break;
		case 1: amplify += amplify_increment;break;
		case 2: batch_size += batch_size_increment;break;
		case 3: neurons_in_layer[0]++;set_up_network();break;
		case 4: neurons_in_layer[1]++;set_up_network();break;
		case 5: neurons_in_layer[2]++;set_up_network();break;
		case 6: neurons_in_layer[3]++;set_up_network();break;
		case 7: neurons_in_layer[4]++;set_up_network();break;
		case 8: neurons_in_layer[5]++;set_up_network();break;
		case 9: layer_transfer[0]++; if (layer_transfer[0] > transfer_types - 1) layer_transfer[0] = 0;break;
		case 10: layer_transfer[1]++; if (layer_transfer[1] > transfer_types - 1) layer_transfer[1] = 0;break;
		case 11: layer_transfer[2]++; if (layer_transfer[2] > transfer_types - 1) layer_transfer[2] = 0;break;
		case 12: layer_transfer[3]++; if (layer_transfer[3] > transfer_types - 1) layer_transfer[3] = 0;break;
		case 13: layer_transfer[4]++; if (layer_transfer[4] > transfer_types - 1) layer_transfer[4] = 0;break;
		case 14: layer_transfer[5]++; if (layer_transfer[5] > transfer_types - 1) layer_transfer[5] = 0;break;
		case 15: F_code++; load_new_data();if (F_code > num_F_codes-1) F_code = 0;break;
		case 16: data_points += 10; if (data_points > MAX_DATA) data_points = MAX_DATA; load_new_data();break;
		case 17: noise += 0.01;load_new_data();break;
		case 18: if (data_mode==0) data_mode =1; else data_mode = 0; break;
		case 19: if (menu_flag ==0) menu_flag =1; else menu_flag =0; 
			if (menu_flag==1) number_of_settings = number_of_extended_settings;
			else number_of_settings = number_of_basic_settings; break;
		
		case 20: LEFT += 5;if (LEFT > SCREEN_W-1) LEFT = SCREEN_W - 1;break;
		case 21: DOWN += 5; if (DOWN > SCREEN_H-1) DOWN = SCREEN_H -1; break;
		case 22: structure_W += 5; if (structure_W > 10000) structure_W = 10000;install_structure(structure_W,structure_H);break;
		case 23: structure_H += 5; if (structure_H > 10000) structure_H = 10000;install_structure(structure_W,structure_H);break;
		case 24: structure_L += 5; if (structure_L > 10000) structure_L = 10000;install_structure(structure_W,structure_H);break;
		case 25: structure_D += 5; if (structure_D > 10000) structure_D = 10000;install_structure(structure_W,structure_H);break;
		case 26: image_size += 5; if (image_size > 1000) image_size = 1000;break;
		case 27: stats_left += 10; break;
		case 28: stats_down += 10; break;
		case 29: display_mode++; if (display_mode > 2) display_mode = 0;break;
		case 30: struct_mode++; if (struct_mode > struct_modes -1) struct_mode = 0; break;
		case 31: pixel_height++;break;
		case 32: pixel_width++;break;
		case 33: thickness++;break;
		case 34: threshold++; if (threshold > 255) threshold = 255;break;
		case 35: data_size++; if (data_size> 255) data_size = 255;break;
		case 36: font_number++; if (font_number> number_of_fonts - 1) font_number = 0;
				 font = fonts[font_number];break;

	
	}
		
}
void decrease_setting(int setting)
{
	switch(setting)
	{
		case 0: rate -= rate_increment;break;
		case 1:amplify -= amplify_increment;break;
		case 2: batch_size -= batch_size_increment;if (batch_size < 1) batch_size =1 ;break;
		case 3: neurons_in_layer[0]--;if (neurons_in_layer[0] < 1) neurons_in_layer[0] = 1;set_up_network();break;
		case 4: neurons_in_layer[1]--;if (neurons_in_layer[1] < 1) neurons_in_layer[1] = 1;set_up_network();break;
		case 5: neurons_in_layer[2]--;if (neurons_in_layer[2] < 1) neurons_in_layer[2] = 1;set_up_network();break;
		case 6: neurons_in_layer[3]--;if (neurons_in_layer[3] < 0) neurons_in_layer[3] = 0;set_up_network();break;
		case 7: neurons_in_layer[4]--;if (neurons_in_layer[4] < 0) neurons_in_layer[4] = 0;set_up_network();break;
		case 8: neurons_in_layer[5]--;if (neurons_in_layer[5] < 0) neurons_in_layer[5] = 0;set_up_network();break;
		case 9: layer_transfer[0]--; if (layer_transfer[0] < 0) layer_transfer[0] = transfer_types-1;break;
		case 10: layer_transfer[1]--; if (layer_transfer[1] < 0) layer_transfer[1] = transfer_types-1;break;
		case 11: layer_transfer[2]--; if (layer_transfer[2] < 0) layer_transfer[2] = transfer_types-1;break;
		case 12: layer_transfer[3]--; if (layer_transfer[3] < 0) layer_transfer[3] = transfer_types-1;break;
		case 13: layer_transfer[4]--; if (layer_transfer[4] < 0) layer_transfer[4] = transfer_types-1;break;
		case 14: layer_transfer[5]--; if (layer_transfer[5] < 0) layer_transfer[5] = transfer_types-1;break;
		case 15:  load_new_data();if (F_code == 0) F_code = num_F_codes-1; else F_code--;break;
		case 16: data_points -= 10; if (data_points < 1) data_points = 1; load_new_data();break;
		case 17: noise -= 0.01;if (noise < 0) noise = 0.0;load_new_data();break;
		case 18: if (data_mode==0) data_mode =1; else data_mode = 0; break;
		case 19: if (menu_flag ==0) menu_flag =1; else menu_flag =0; 
			if (menu_flag==1) number_of_settings = number_of_extended_settings;
			else number_of_settings = number_of_basic_settings; break;
		case 20: LEFT -= 5;if (LEFT <0) LEFT = SCREEN_W-1;break;
		case 21: DOWN -= 5; if (DOWN < 0) DOWN =SCREEN_H-1; break;
		case 22: structure_W -= 5; if (structure_W < 1) structure_W = 1;install_structure(structure_W,structure_H);break;
		case 23: structure_H -= 5; if (structure_H < 1) structure_H = 1;install_structure(structure_W,structure_H);break;
		case 24: structure_L -= 5; if (structure_L < 0) structure_L = 0;install_structure(structure_W,structure_H);;break;
		case 25: structure_D -= 5; if (structure_D < 0) structure_D = 0;install_structure(structure_W,structure_H);;break;
		case 26: image_size -= 5; if (image_size < 0) image_size = 0;break;
		case 27: stats_left -= 10; break;
		case 28: stats_down -= 10; break;
		case 29: display_mode--; if (display_mode < 0) display_mode =2 ;break;
		case 30: struct_mode--; if (struct_mode <0) struct_mode = struct_modes -1; break;
		case 31: pixel_height--;if (pixel_height <1) pixel_height = 1;break; 
		case 32: pixel_width--;if (pixel_width <1) pixel_width = 1;break; 
		case 33: thickness--; if (thickness <1) thickness =1;break;
		case 34: threshold--; if (threshold < 0) threshold = 0;break;
		case 35: data_size--; if (data_size < 1) data_size = 1;break;
		case 36: font_number--; if (font_number< 0) font_number = number_of_fonts-1;
				 font = fonts[font_number];break;
		
	}
	
	
}

void display_settings()
{
	load_setting_content();
	for (int i = 0; i < number_of_settings; i++) display_setting(i);
}