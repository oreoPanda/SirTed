/*
 * main.c
 *
 *  Created on: Sep 18, 2015
 *      Author: i_fly_gliders
 */

#include <gtk/gtk.h>

GtkWidget *window = NULL, *grid = NULL, *button = NULL;

void create_window(void)
{
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title( GTK_WINDOW (window), "Window" );
	gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER );

	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_widget_show(window);

	return;
}

void create_grid(void)
{
	grid = gtk_grid_new();
	gtk_widget_show(grid);
	return;
}

void create_button(void)
{
	button = gtk_button_new();

	gtk_button_set_label( GTK_BUTTON(button), "Button!" );

	gtk_widget_show(button);

	return;
}

void populate_window(void)
{
	gtk_container_add( GTK_CONTAINER(window), grid );

	gtk_grid_attach( GTK_GRID(grid), button, 0, 0, 1, 1 );
}

int
main (int   argc,
      char *argv[])
{
	gtk_init (&argc, &argv);

	create_window();
	create_grid();
	create_button();
	populate_window();

	gtk_main();

	return 0;
}
