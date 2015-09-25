/*
 * main.c
 *
 *  Created on: Sep 18, 2015
 *      Author: i_fly_gliders
 */

#include "gtk_stuff.h"

#define GAMEWIDTH 10
#define GAMEHEIGHT 18

typedef enum
{
	BLOCK_t,
	BLOCK_square,
	BLOCK_l_normal,
	BLOCK_line,
	BLOCK_s,
	BLOCK_z,
	BLOCK_l_mirror
}BLOCK;

struct block
{
	BLOCK type;
	unsigned short int pos[2];
	unsigned short int rotation;
};

int game_area[GAMEWIDTH][GAMEHEIGHT];
struct block falling;
struct block next;

GtkWidget *window = NULL, *grid = NULL, *button = NULL;

gboolean drop_control(gpointer data)
{
	printf("Controlling drop!\n");

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
