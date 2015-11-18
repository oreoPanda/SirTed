/*
 * SirtedWindow.h
 *
 *  Created on: Nov 18, 2015
 *      Author: i_fly_gliders
 */

#ifndef SIRTEDWINDOW_H_
#define SIRTEDWINDOW_H_

#include <gtkmm.h>
#include "Block.h"

#define BASE 20

using namespace Gtk;
using namespace Cairo;

namespace gamewindow
{

	class SirtedWindow
	{

	public:

		SirtedWindow();
		virtual ~SirtedWindow();

		void create_window(void);
		void create_grid(void);
		void create_button(void);
		void create_drawing_area(void);
		void populate_window(void);
		void connect_drawing_area_events(void);

		gboolean configure_drawing_area( GtkWidget *widget, GdkEventConfigure *event, gpointer data );
		gboolean draw_falling_block(Block block);
		gboolean erase_falling_block(Block block);

	private:

		Window window;
		Grid grid;
		Button button;
		DrawingArea drawing_area;
		Surface surface;


	};

} /* namespace gamewindow */

#endif /* SIRTEDWINDOW_H_ */
