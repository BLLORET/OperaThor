#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
typedef struct
{
        GtkBuilder *builder;
        gpointer user_data;
} SGlobalData;

#define taille_max 1000 
static SGlobalData data;  
static gchar *X3Cste= NULL;
static gchar *X2cste= NULL;
static gchar *Xcste= NULL;
static gchar *cste= NULL;
static gchar *Dcste= NULL;
static gchar *contents =NULL;
static gchar *name_of_file=NULL;  

G_MODULE_EXPORT void on_quit_clicked(){
	gtk_main_quit();
}
G_MODULE_EXPORT void on_MainWindow_clicked(){
	gtk_main_quit();
}
G_MODULE_EXPORT void on_Display_text_clicked(){
	GtkLabel *texte = GTK_LABEL(
			gtk_builder_get_object(data.builder, "label"));
	if(NULL == texte)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte,contents);
	}
}

G_MODULE_EXPORT void on_treatment_equation_clicked(){
		GtkLabel *texte = GTK_LABEL(
					gtk_builder_get_object(data.builder, "resolution"));
	if(NULL == texte)
	{
		fprintf(stderr,"label do not exist");
	}
	if(X3cste==NULL||X2cste==NULL||Xcste==NULL||cste==NULL)
	{
		fprintf(stderr,"NULL");
	}
}
int main(int argc, char *argv []){
	GtkWidget *fenetre_principale = NULL;
	GError *error = NULL;
    gchar *filename=NULL;
    /* Initializing the Gtk library.*/
    gtk_init(&argc, &argv);
    /* Opening the Glade file from the main Window */
    data.builder = gtk_builder_new();
    /* Creating the full path to access the OCR.glade file */
    /* g_build_filename(); Construct the full path according to the */
    /*  operating system. ( / for Linux and \ for Windows) */
    filename =  g_build_filename ("Solveur.glade", NULL);
    /* Chargement du fichier OCR.glade. */
    gtk_builder_add_from_file (data.builder, filename, &error);
    g_free (filename);
    if (error){
		gint code = error->code;
        g_printerr("%s\n", error->message);
        g_error_free (error);
        return code;
    }
    /* Assignement of interface signals to different Callbacks */
    gtk_builder_connect_signals (data.builder, &data);
    /* Pointer recovery from the main window */
    fenetre_principale = GTK_WIDGET(gtk_builder_get_object (data.builder, "MainWindow"));
    
    /* Showing the main window */
    gtk_widget_show_all (fenetre_principale);
    gtk_main();
    return 0;
}
