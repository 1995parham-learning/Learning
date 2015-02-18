/*
 * In The Name Of God
 * ========================================
 * [] File Name : example-4.c
 *
 * [] Creation Date : 18-02-2015
 *
 * [] Last Modified : Wed 18 Feb 2015 10:56:10 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello World\n");
}

int main(int argc, char *argv[])
{
	GtkBuilder *builder;
	GObject *window;
	GObject *button;

	gtk_init(&argc, &argv);

	/* Construct a GtkBuilder instance and load our UI description */
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "builder.ui", NULL);

	/* Connect signal handlers to the constructed widgets. */
	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	button = gtk_builder_get_object(builder, "button1");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

	button = gtk_builder_get_object(builder, "button2");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

	button = gtk_builder_get_object(builder, "quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

	gtk_main();

	return 0;
}

