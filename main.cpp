/*
 * main.c
 *
 *  Created on: Sep 18, 2015
 *      Author: i_fly_gliders & Schwarzes Kaeffchen
 */
#include <iostream>
#include "SirtedWindow.h"
#include "Block.h"

using namespace std; 
using namespace Block;
using namespace gamewindow;

int game_area[GAMEWIDTH][GAMEHEIGHT];
class block falling;
BLOCK next;

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
	Block block_type; 
	static gboolean first_call = TRUE;
	int i = 0;  
	if(falling.pos[1] != 0) 
	{ 
		if(first_call == TRUE)
		{
			falling.type = rand()%BLOCK_number;		
			falling.pos[0] = 5;
			falling.pos[1] = 0; 
			falling.rotation = 0;
			first_call = FALSE;  	
		}
		else
		{
			falling.type = next; 
			falling.pos[X] = 5;
			falling.pos[Y] = 0; 
			falling.rotation = 0; 	
		}	
		next = block_type.BlockType();  
	}
	
	if (draw_falling_block (falling) == FALSE)
	{
		return G_SOURCE_CONTINUE;
	} 
	
	if (game_area[falling.pos[X]][i+1] == 0)			//Check below Block, if empty drop Block
	{
		falling.pos[Y]++;					
 
		erase_falling_block(falling);

		if (draw_falling_block(falling) == FALSE) 
		{
			return G_SOURCE_CONTINUE; 
		}
		i++; 
	} 
	
	return G_SOURCE_CONTINUE;
}

int check_for_full_rows () 
{
	int single_block_counter = 0, row_counter = 0; 
	for(int i=GAMEHEIGHT - 1; i>=0; i--)
	{
		for(int j=0; j<GAMEWiDTH; j++)
		{
			single_block_counter++; 
			if(a[i][j] == 0) 
			{
				single_block_counter = 0; 
				break; 
			}
			else if(a[i][j] != 0 && single_block_counter == GAMEWIDTH) 
			{
				for(int k = 0; k < GAMEWIDTH; k++) 
				{
					a[i][k] = 0; 
					row_counter++; 
				} 
			}
		}
	}
	return row_counter;
}

int score(int row_counter)
{
	switch (row_counter) 
	{
		case 1: return 1; break; 
		case 2: return 4; break; 
		case 3: return 8; break; 
		case 4: return 10;break;
		default: cout << "An error occured" << endl;  
	}
	return 0; 
}

int check_if_game_is_over () 
{
	for(int i = 0; i < GAMEWIDTH; i++)
	{
		if(game_area[i][GAMEHEIGHT] != 0) 
		{
			return TRUE; 
		}
	}
        //Häääääääääääääääääääääääääää :.(
	return FALSE; 
}

int main (int argc, char *argv[])
{
	Gtk::Main main_obj(argc, argv);

	init_game_area(); 

	SirtedWindow sirtedwindow;
	sirtedwindow.create_window();
	sirtedwindow.create_grid();
	sirtedwindow.create_drawing_area();
	sirtedwindow.populate_window();
	
	connect_drawing_area_events();
		
	g_timeout_add( 750, drop_control, NULL );
	main_obj.run();

	return 0;
}

