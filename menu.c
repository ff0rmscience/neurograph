void show_menu()
{
    current_color = white;
    for (int i = 0; i < menu_items; i++)
    {
       al_draw_textf(font, current_color, menu_left, menu_down +i*s_height,
        ALLEGRO_ALIGN_LEFT, "%s",menu_choice[i]); 
    }
}

