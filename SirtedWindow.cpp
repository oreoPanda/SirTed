/*
 * SirtedWindow.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: i_fly_gliders
 */

#include "sirted.h"
#include "SirtedWindow.h"

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

} /* namespace gamewindow */
