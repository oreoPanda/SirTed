/*gtk_stuff.h*/

#ifndef GTK_STUFF_H
#define GTK_STUFF_H

#include <gtk/gtk.h>

#define BASE 20

extern void create_window(void);
extern void create_grid(void);
extern void create_button(void);
extern void create_frame(void);

extern gboolean configure_drawing_area( GtkWidget *widget, GdkEventConfigure *event, gpointer data );
extern gboolean ready_to_draw( GtkWidget *widget, cairo_t *cr, gpointer data );
extern gboolean draw_falling_block(void);
extern gboolean redraw_falling_block(void);

#endif	//GTK_STUFF_H
