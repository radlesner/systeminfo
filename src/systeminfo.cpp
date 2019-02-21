//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.8.2
// Copyright   : GNU General Public License (GPL)
// Description : systeminfo in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstring>
#include <gtk/gtk.h>

#include "functions_output.h"
#include "functions_output_memory_swap.h"
#include "functions_command.h"

using namespace std;

void output_version() {
	cout << "systeminfo 2018, v0.8.2" << endl;
	cout << "Compiled: " << __DATE__ << " | " << __TIME__ << " | " << __FILE__ << endl;
}

int main(int argc, char** argv) {
	command_check_folder_exist();
	command_activate();
	if(argc > 1) {
		if(argc > 2)
			if(!strcmp(argv[2], "-l") || !strcmp(argv[2], "--logo"))				output_logo();
		if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "--memory"))					output_memory();
		else if(!strcmp(argv[1], "-M") || !strcmp(argv[1], "--memory-megabyte"))	output_memory_megabyte();
		else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--system"))				output_system();
		else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--cpu"))				output_cpu_only();
		else if(!strcmp(argv[1], "-l") || !strcmp(argv[1], "--logo")) {
			output_logo();
			output_all();
		}
		else if(!strcmp(argv[1], "-n") || !strcmp(argv[1], "--network"))			output_network();
		else if(!strcmp(argv[1], "-t") || !strcmp(argv[1], "--monitor"))			output_monitor(argc, argv);
		else if(!strcmp(argv[1], "--check-files"))									output_check_files();
		else if(!strcmp(argv[1], "--gui")) {
			GtkWidget *okno;
			GtkWidget *etykieta1;
			GtkWidget *etykieta2;
			//GtkWidget *statusbar;
			GtkWidget *vbox;

			gtk_init(&argc, &argv);

			okno = gtk_window_new(GTK_WINDOW_TOPLEVEL);
			gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);
			gtk_window_set_default_size(GTK_WINDOW(okno), 250, 250);
			gtk_window_set_title(GTK_WINDOW(okno), "systeminfo");

			vbox = gtk_vbox_new(FALSE, 2);
			gtk_container_add(GTK_CONTAINER(okno), vbox);

			etykieta1 = gtk_label_new("OS Name: Linux\nlll");
			gtk_label_set_line_wrap(GTK_LABEL(etykieta1), TRUE);
			gtk_box_pack_start(GTK_BOX(vbox), etykieta1, TRUE, TRUE, 10);

			etykieta2 = gtk_label_new("Distribution: men\nlll");
			gtk_label_set_line_wrap(GTK_LABEL(etykieta2), TRUE);
			gtk_box_pack_start(GTK_BOX(vbox), etykieta2, TRUE, TRUE, 10);

			//statusbar = gtk_statusbar_new();
			//gtk_box_pack_start(GTK_BOX(vbox), statusbar, FALSE, TRUE, 1);

			//gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "active"), "active");

			g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);

			gtk_widget_show_all(okno);

			gtk_main();

			return 0;
		}
		else if(!strcmp(argv[1], "--version"))										output_version();
		else if(!strcmp(argv[1], "--help"))											output_help();
		else if(!strcmp(argv[1], "--"))												output_all();
		else if(!strcmp(argv[1], "-"))												output_all();
		else {
			if(argc > 3)		cout << "Bad option: " << argv[1] << " " << argv[2] << " " << argv[3] << endl;
			else if(argc > 2)	cout << "Bad option: " << argv[1] << " " << argv[2] << endl;
			else				cout << "Bad option: " << argv[1] << endl;
			output_help();
		}
	}
	else 	output_all();
	command_remove();

	return 0;
}