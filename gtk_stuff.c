/*window setup*/

#include "gtk_stuff.h"
#include "sirted.h"

GtkWidget *window = NULL, *grid = NULL, *button = NULL, *drawing_area = NULL;
static cairo_surface_t *surface = NULL;

extern void create_window(void)
{
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title( GTK_WINDOW (window), "Window" );
	gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER );

	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_widget_show(window);

	return;
}

extern void create_grid(void)
{
	grid = gtk_grid_new();
	gtk_widget_show(grid);
	return;
}

extern void create_button(void)
{
	button = gtk_button_new();

	gtk_button_set_label( GTK_BUTTON(button), "Button!" );

	gtk_widget_show(button);

	return;
}

extern void create_drawing_area(void)
{
	drawing_area = gtk_drawing_area_new();

	gtk_widget_set_size_request( drawing_area, GAMEWIDTH*BASE, GAMEHEIGHT*BASE );

	return;
}

extern void populate_window(void)
{
	gtk_container_add( GTK_CONTAINER(window), grid );

	gtk_grid_attach( GTK_GRID(grid), drawing_area, 0, 0, 10, 10 );
	gtk_grid_attach( GTK_GRID(grid), button, 1, 0, 1, 1 );

	return;
}

/*callback functions and event handles*/

static void clear_surface(void)
{
	cairo_t *cr;

	cr = cairo_create(surface);

	cairo_set_source_rgb( cr, 1, 1, 1 );
	cairo_paint(cr);

	cairo_destroy(cr);

	return;
}

extern gboolean configure_drawing_area( GtkWidget *widget, GdkEventConfigure *event, gpointer data )
{
	//useless, but it's in the tutorial so I do it!
	if(surface)
	{
		cairo_surface_destroy(surface);
	}

	surface = gdk_window_create_similar_surface( gtk_widget_get_window(widget),
							CAIRO_CONTENT_COLOR,
							gtk_widget_get_allocated_width(widget),
							gtk_widget_get_allocated_height(widget) );

	clear_surface();

	//event handled, remove source
	return TRUE;
}

//will return FALSE if ready_to_draw has not been called yet
extern gboolean draw_falling_block(struct block falling)
{
	cairo_t *cr;

	double x = falling.pos[X] * GAMEWIDTH;
	double y = falling.pos[Y] * GAMEHEIGHT;
	double width = BASE;
	int height = BASE;

	//in case configure event did not happen yet
	if( surface == NULL )
	{
		return FALSE;
	}

	cr = cairo_create(surface);
	cairo_set_source_rgb( cr, 0, 0, 0 );
	cairo_rectangle( cr, x, y, width, height );

	cairo_destroy(cr);

	return TRUE;
}

extern gboolean erase_falling_block(struct block falling)
{
	cairo_t *cr;

	double x = falling.pos[X] * GAMEWIDTH;
	double y = falling.pos[Y] * GAMEHEIGHT;
	double width = BASE;
	int height = BASE;

	//in case configure event did not happen yet
	if( surface == NULL )
	{
		return FALSE;
	}

	cr = cairo_create(surface);
	cairo_set_source_rgb( cr, 1, 1, 1 );
	cairo_rectangle( cr, x, y, width, height );

	cairo_destroy(cr);

	return TRUE;
}
