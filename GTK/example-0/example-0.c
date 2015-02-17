/*
 * In The Name Of God
 * ========================================
 * [] File Name : example-0.c
 *
 * [] Creation Date : 03-02-2015
 *
 * [] Last Modified : Tue 17 Feb 2015 07:46:23 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <gtk/gtk.h>

/*
 * https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
 * Basics: example-0
*/

int main(int argc, char *argv[])
{
	GtkWidget *label;
	GtkWidget *window;

	gtk_init(&argc, &argv);

	/*
	 * The type of the window is GTK_WINDOW_TOPLEVEL, which means that
	 * the GtkWindow will be managed by the windowing system: it will
	 * have a frame, a title bar and window controls,
	 * depending on the platform.
	*/
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello Window");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_widget_set_size_request(window, 200, 200);

	/*
	 * In order to terminate the application when the GtkWindow is destroyed,
	 * we connect the “destroy” signal to the gtk_main_quit() function.
	 * This function will terminate the GTK+ main loop started by calling gtk_main()
	 * later. The “destroy” signal is emitted when a widget is destroyed, either by
	 * explicitly calling gtk_widget_destroy() or when the widget is unparented.
	 * Top-level GtkWindows are also destroyed when the Close window control
	 * button is clicked.
	 *
	 * If you comment following line then there is no way of exiting the application
	 * except to kill in the terminal where it was lunched.
	*/
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


	label = gtk_label_new("Hello world");
	gtk_label_set_selectable(GTK_LABEL(label), TRUE);
	gtk_container_add(GTK_CONTAINER(window), label);

	gtk_widget_show_all(window);

	gtk_main();
}
