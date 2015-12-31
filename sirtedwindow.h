#ifndef SIRTEDWINDOW_H
#define SIRTEDWINDOW_H

#include "Block.h"
#include <QMainWindow>

#define BASE 20

namespace Ui
{
    class SirtedWindow;
}

class SirtedWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit SirtedWindow(QWidget *parent = 0);
    ~SirtedWindow();

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

    Ui::SirtedWindow *ui;

    Window window;
    Grid grid;
    Button button;
    DrawingArea drawing_area;
    Surface surface;


};

#endif // SIRTEDWINDOW_H
