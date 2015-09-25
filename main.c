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

#define TRUE 1
#define FALSE 0 

typedef enum
{
	BLOCK_t,
	BLOCK_square,
	BLOCK_l_normal,
	BLOCK_line,
	BLOCK_s,
	BLOCK_z,
	BLOCK_l_mirror,
	BLOCK_max
}BLOCK;

struct block
{
	BLOCK type;
	unsigned short int pos[2];
	unsigned short int rotation;
};

int stuff_that_reached_the_bottom[GAMEWIDTH][GAMEHEIGHT];
int block_next;
struct block falling;


GtkWidget *window = NULL, *grid = NULL, *button = NULL;

gboolean drop_control(gpointer data)
{
	static gboolean first_call = TRUE; 
	time_t t; 
	time (&t); 
	srand ((unsigned int) t); 
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
		falling.pos[0] = {5};
		falling.pos[1] = {0}; 
		falling.rotation = 0; 	
	}	

	
	draw_falling_block (); 
	

	return G_SOURCE_CONTINUE;
}

int main (int argc, char *argv[])
{
	gtk_init (&argc, &argv);

	create_window();
	create_grid();
	create_button();
	populate_window();

	g_timeout_add( 750, drop_control, NULL );

	gtk_main();

	return 0;
}
