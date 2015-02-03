/*
 * In The Name Of God
 * ========================================
 * [] File Name : example-2.c
 *
 * [] Creation Date : 04-02-2015
 *
 * [] Last Modified : Wed 04 Feb 2015 03:01:07 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <gtk/gtk.h>

/*
 * https://developer.gnome.org/gtk3/stable/ch01s02.html
 * Packing: example-2
*/

static void print_hello(GtkWidget *widget,
		gpointer data)
{
	  g_print("Hello World\n");
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button;

	/*
	 * This is called in all GTK applications. Arguments are parsed
	 * from the command line and are returned to the application.
	*/
	gtk_init(&argc, &argv);

	/* create a new window, and set its title */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Grid");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	/* Here we construct the container that is going pack our buttons */
	grid = gtk_grid_new();

	/* Pack the container in the window */
	gtk_container_add(GTK_CONTAINER(window), grid);

	button = gtk_button_new_with_label("Button 1");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

	/*
	 * gtk_grid_attach(x_position, y_position, rows, columns)
	*/

	/*
	 * Place the first button in the grid cell (0, 0), and make it fill
	 * just 1 cell horizontally and vertically (ie no spanning)
	*/
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

	button = gtk_button_new_with_label("Button 2");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

	/*
	 * Place the second button in the grid cell (1, 0), and make it fill
	 * just 1 cell horizontally and vertically (ie no spanning)
	*/
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

	button = gtk_button_new_with_label("Quit");
	g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);

	/*
	 * Place the Quit button in the grid cell (0, 1), and make it
	 * span 2 columns.
	*/
	gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

	/*
	 * Now that we are done packing our widgets, we show them all
	 * in one go, by calling gtk_widget_show_all() on the window.
	 * This call recursively calls gtk_widget_show() on all widgets
	 * that are contained in the window, directly or indirectly.
	*/
	gtk_widget_show_all(window);

	/*
	 * All GTK applications must have a gtk_main(). Control ends here
	 * and waits for an event to occur (like a key press or a mouse event),
	 * until gtk_main_quit() is called.
	*/
	gtk_main ();

	return 0;
}
