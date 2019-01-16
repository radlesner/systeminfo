#include "gui.h"

using namespace std;

void gui(int argc, char** argv) {
    GtkWidget *okno;
    GtkWidget *etykieta1;
    GtkWidget *statusbar;
    GtkWidget *vbox;

    gtk_init(&argc, &argv);

    okno = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(okno), 280, 150);
    gtk_window_set_title(GTK_WINDOW(okno), "Kurs GTK+");

    vbox = gtk_vbox_new(FALSE, 2);
    gtk_container_add(GTK_CONTAINER(okno), vbox);

    etykieta1 = gtk_label_new("Lorem ipsum dolor sit amet.");
    gtk_label_set_line_wrap(GTK_LABEL(etykieta1), TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), etykieta1, TRUE, TRUE, 10);

    statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), statusbar, FALSE, TRUE, 1);

    gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "Bezczynny"), "Bezczynny");

    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(okno);

    gtk_main();

    return 0;
}