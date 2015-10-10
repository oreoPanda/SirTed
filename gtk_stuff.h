/*gtk_stuff.h*/

#ifndef GTK_STUFF_H
#define GTK_STUFF_H

#include <gtk/gtk.h>
#include "sirted.h"

#define BASE 20

extern void create_window(void);
extern void create_grid(void);
extern void create_button(void);
extern void create_drawing_area(void);
extern void populate_window(void);
extern void connect_drawing_area_events(void);

extern gboolean configure_drawing_area( GtkWidget *widget, GdkEventConfigure *event, gpointer data );
extern gboolean draw_falling_block(struct block falling);
extern gboolean erase_falling_block(struct block falling);

#endif	//GTK_STUFF_H
