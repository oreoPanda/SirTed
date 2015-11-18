/*
 * SirtedWindow.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: i_fly_gliders
 */

#include "sirted.h"
#include "SirtedWindow.h"

using namespace Block;

namespace gamewindow
{

	SirtedWindow::SirtedWindow()
	{

	}

	SirtedWindow::~SirtedWindow()
	{

	}

	void SirtedWindow::create_window(void)
	{

		this->window.set_title("SirTed");
		this->window.set_position(WIN_POS_CENTER);
		//g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
		this->window.show();

		return;
	}

	void SirtedWindow::create_grid(void)
	{
		this->grid.show();
		return;
	}

	void SirtedWindow::create_drawing_area(void)
	{
		this->drawing_area.set_size_request( GAMEWIDTH*BASE, GAMEHEIGHT*BASE );
		this->drawing_area.show();

		return;
	}

	void SirtedWindow::populate_window(void)
	{
		this->window.add(this->grid);
		this->grid.attach( this->drawing_area, 0, 0, 1, 1 );

		return;
	}

	gboolean SirtedWindow::draw_falling_block(Block block)
	{
		switch( block.get_type() )
		{
			case BLOCK_t:
			{
				break;
			}
			case BLOCK_square:
			{
				break;
			}
			case BLOCK_l_normal:
			{
				break;
			}
			case BLOCK_line:
			{
				break;
			}
			case BLOCK_s:
			{
				break;
			}
			case BLOCK_z:
			{
				break;
			}
			case BLOCK_l_mirror:
			{
				break;
			}
			default:
			{
				//should not happen
				break;
			}
		}
	}

} /* namespace gamewindow */
