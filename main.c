/*
 * main.c
 *
 *  Created on: Sep 18, 2015
 *      Author: i_fly_gliders & Schwarzes Kaeffchen
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gtk_stuff.h"
#include "sirted.h"

void init_game_area()
{
	int x, y;
	for( x = 0; x < GAMEWIDTH; x++ )
	{
		for( y = 0; y < GAMEHEIGHT; y++ )
		{
			game_area[x][y] = 0;
		}
	}

	return;
}

gboolean drop_control(gpointer data)
{
	static gboolean first_call = TRUE;
	int i = 0;  
	time_t t; 
	time (&t); 
	srand ((unsigned int) t);
	if(falling.pos[1] != 0) 
	{ 
		if(first_call == TRUE)
		{
			falling.type = rand()%BLOCK_max; 
			falling.pos[0] = {5};
			falling.pos[1] = {0}; 
			falling.rotation = 0;
			first_call = FALSE;  	
		}
		else
		{
			falling.type = block_next; 
			falling.pos[X] = {5};
			falling.pos[Y] = {0}; 
			falling.rotation = 0; 	
		}	
		block_next = rand()%BLOCK_number; 
	}
	
	if (draw_falling_block () == FALSE)
	{
		return G_SOURCE_CONTINUE;
	} 
	
	if (game_area[x_pos][i+1] == 0)
	{
		falling.pos[Y]++; 
		redraw();
		i++; 
	} 
	
	return G_SOURCE_CONTINUE;
}

int main (int argc, char *argv[])
{
	gtk_init (&argc, &argv);

	init_game_area(); 

	create_window();
	create_grid();
	create_button();
	create_drawing_area();
	populate_window();
	
	g_signal_connect (drawing_area, "draw", G_CALLBACK(ready_to_draw), NULL );
	g_signal_connect ( drawing_area, "configure-event", G_CALLBACK(configure_drawing_area), NULL );
		
	g_timeout_add( 750, drop_control, NULL );

	gtk_main();

	return 0;
}
