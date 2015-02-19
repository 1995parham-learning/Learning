/*
 * In The Name Of God
 * ========================================
 * [] File Name : boxes.c
 *
 * [] Creation Date : 19-02-2015
 *
 * [] Last Modified : Thu 19 Feb 2015 10:11:24 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <gtk/gtk.h>

#define NUM_NAMES 4
const gchar* names[] = {"Parham", "Navid", "Mohammad", "Nothing"};

int main(int argc, char *argv[])
{
	int i;
	GtkWidget *window, *vbox;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Boxes");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_widget_set_size_request(window, 200, -1);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	/* Add four buttons to the vertical box */
	for (i = 0; i < NUM_NAMES; i++) {
		GtkWidget *button = gtk_button_new_with_label(names[i]);
		gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
		g_signal_connect_swapped(button, "clicked",
				G_CALLBACK(gtk_widget_destroy), button);
	}

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}
