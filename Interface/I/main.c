#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "matrice.h"
/*#include "identification.h"
#include "fonction_interface.h"
#include "troisieme_interface.h"*/

typedef struct
{
        GtkBuilder *builder;
        gpointer user_data;
} SGlobalData;

#define taille_max 1000 
static SGlobalData data;  
/*static const gchar *X4cste =NULL;
static const gchar *X3cste= NULL;
static const gchar *X2cste= NULL;
static const gchar *Xcste= NULL;
static const gchar *cste= NULL;
static const gchar *DX4cste =NULL;
static const gchar *DX3cste= NULL;
static const gchar *DX2cste= NULL;
static const gchar *DXcste= NULL;
static const gchar *Dcste= NULL;*/
static const gchar *Ma11 =NULL;
static const gchar *Ma12 =NULL;
static const gchar *Ma13 =NULL;
static const gchar *Ma21 =NULL;
static const gchar *Ma22 =NULL;
static const gchar *Ma23 =NULL;
static const gchar *Ma31 =NULL;
static const gchar *Ma32 =NULL;
static const gchar *Ma33 =NULL;
static const gchar *Mb11 =NULL;
static const gchar *Mb12 =NULL;
static const gchar *Mb13 =NULL;
static const gchar *Mb21 =NULL;
static const gchar *Mb22 =NULL;
static const gchar *Mb23 =NULL;
static const gchar *Mb31 =NULL;
static const gchar *Mb32 =NULL;
static const gchar *Mb33 =NULL;
static const gchar* choice =NULL;
static int MatriceA[]= {
  0, 0, 0,
  0, 0, 0,
  0, 0, 0
};
static int MatriceB[]= {
  0, 0, 0,
  0, 0, 0,
  0, 0, 0
};
/*static int res[]= {
  0, 0, 0,
  0, 0, 0,
  0, 0, 0
};*/

//static gchar *contents =NULL;
static gchar *contents_matrice =NULL;
//static gchar *error =NULL;
//static gchar *name_of_file_equation="équation.txt";
static gchar *name_of_file="matrice.txt";  
static GtkWidget *fenetre_matrice = NULL;

G_MODULE_EXPORT void on_quit_clicked(){
	gtk_main_quit();
}
G_MODULE_EXPORT void on_MainWindow_clicked(){
	gtk_main_quit();
}
/*G_MODULE_EXPORT void on_Display_text_clicked(){
	GtkLabel *texte_equation = GTK_LABEL(
			gtk_builder_get_object(data.builder, "label"));
	if(NULL == texte)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte,contents);
	}
}*/
G_MODULE_EXPORT void on_Matrice_Display_text_clicked(){
	GtkLabel *texte_matrice = GTK_LABEL(
			gtk_builder_get_object(data.builder, "matrice"));
	if(NULL == texte_matrice)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file,&contents_matrice,NULL,NULL))
	{
		gtk_label_set_text(texte_matrice,contents_matrice);
	}
}
void Make_matrix(int Matrice[], int elm[])
{
	for(int i =0; i <9;i++)
	{
				Matrice[i]=elm[i];
	}
}

static void printx(int mat[], int lines, int cols)
{
	
	for(int i=0; i< lines; i++)
	{ fprintf(stdout,"[");
		for(int j=0; j< cols; j++)
		{
			fprintf(stdout,"%4d", mat[j+i*cols]);
		}
		fprintf(stdout,"]\n");
	}	
}
G_MODULE_EXPORT void on_treatment_matrice_clicked(){
	//Récupération 
	GtkEntry *Matrix11a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma11"));
	GtkEntry *Matrix12a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma12"));
	GtkEntry *Matrix13a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma13"));
	GtkEntry *Matrix21a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma21"));
	GtkEntry *Matrix22a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma22"));
	GtkEntry *Matrix23a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma23"));
	GtkEntry *Matrix31a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma31"));
	GtkEntry *Matrix32a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma32"));
	GtkEntry *Matrix33a = GTK_ENTRY(gtk_builder_get_object(data.builder,"Ma33"));
	GtkEntry *Matrix11b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb11"));
	GtkEntry *Matrix12b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb12"));
	GtkEntry *Matrix13b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb13"));
	GtkEntry *Matrix21b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb21"));
	GtkEntry *Matrix22b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb22"));
	GtkEntry *Matrix23b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb23"));
	GtkEntry *Matrix31b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb31"));
	GtkEntry *Matrix32b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb32"));
	GtkEntry *Matrix33b = GTK_ENTRY(gtk_builder_get_object(data.builder,"Mb33"));
	GtkEntry *Choose = GTK_ENTRY(gtk_builder_get_object(data.builder,"choisir"));
	
	//Initialisation
	 Ma11 =  gtk_entry_get_text(Matrix11a);
	 Ma12 =  gtk_entry_get_text(Matrix12a);
   Ma13 =  gtk_entry_get_text(Matrix13a);
	 Ma21 =  gtk_entry_get_text(Matrix21a);
	 Ma22 =  gtk_entry_get_text(Matrix22a);
	 Ma23 =  gtk_entry_get_text(Matrix23a);
   Ma31 =  gtk_entry_get_text(Matrix31a);
	 Ma32 =  gtk_entry_get_text(Matrix32a);
	 Ma33 =  gtk_entry_get_text(Matrix33a);
	 Mb11 =  gtk_entry_get_text(Matrix11b);
	 Mb12 =  gtk_entry_get_text(Matrix12b);
	 Mb13 =  gtk_entry_get_text(Matrix13b);
	 Mb21 =  gtk_entry_get_text(Matrix21b); 
	 Mb22 =  gtk_entry_get_text(Matrix22b);
	 Mb23 =  gtk_entry_get_text(Matrix23b);
	 Mb31 =  gtk_entry_get_text(Matrix31b);
	 Mb32 =  gtk_entry_get_text(Matrix32b);
	 Mb33 = gtk_entry_get_text(Matrix33b);
	 choice = gtk_entry_get_text(Choose);
	
	 if(Ma11==NULL||Ma12==NULL||Ma13==NULL||Ma21==NULL||Ma22 ==NULL||Ma23==NULL
	 ||Ma31==NULL||Ma32==NULL||Ma33==NULL)
	{
		fprintf(stderr,"NULL");
	}
	if(Mb11==NULL||Mb12==NULL||Mb13==NULL||Mb21==NULL||Mb22==NULL||Mb23==NULL
	||Mb31==NULL||Mb32==NULL||Mb33==NULL)
	{
		fprintf(stderr,"NULL");
	}
	int elmA[9]={atoi(Ma11),atoi(Ma12),atoi(Ma13),atoi(Ma21),atoi(Ma22),atoi(Ma23),
		atoi(Ma31),atoi(Ma32),atoi(Ma33)};
	int elmB[9]={atoi(Mb11),atoi(Mb12),atoi(Mb13),atoi(Mb21),atoi(Mb22),atoi(Mb23),
		atoi(Mb31),atoi(Mb32),atoi(Mb33)};
	Make_matrix(MatriceA,elmA);
	Make_matrix(MatriceB,elmB);
	printx(MatriceB,3,3);
	FILE* file = NULL;
	file = fopen("matrice.txt","w");
	if(file != NULL){
  int res[]= {
  0, 0, 0,
  0, 0, 0,
  0, 0, 0
};
	PMatrix(file,MatriceA,MatriceB,res,(char*)choice);
	fclose(file);}
} 
/*G_MODULE_EXPORT void on_treatment_equation_clicked(){
		//GtkLabel *texte = GTK_LABEL(
	 //gtk_builder_get_object(data.builder, "resolution"));
	GtkEntry *saisie4 = GTK_ENTRY(gtk_builder_get_object(data.builder,"X⁴cste"));
	GtkEntry *saisie3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"X³cste"));
	GtkEntry *saisie2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"X²cste"));
	GtkEntry *saisie1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"Xcste"));
	GtkEntry *saisie = GTK_ENTRY(gtk_builder_get_object(data.builder,"cste"));
	GtkEntry *saisieD4 = GTK_ENTRY(gtk_builder_get_object(data.builder,"DX⁴cste"));
	GtkEntry *saisieD3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"DX³cste"));
	GtkEntry *saisieD2= GTK_ENTRY(gtk_builder_get_object(data.builder,"DX²cste"));
	GtkEntry *saisieD1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"DXcste"));
	GtkEntry *saisieD = GTK_ENTRY(gtk_builder_get_object(data.builder,"Dcste"));
	struct coeff *cf = malloc(sizeof(struct coeff));
  cf->left = calloc(5, sizeof(int));
  cf->right = calloc(5, sizeof(int));
  X4cste =  gtk_entry_get_text(saisie4);
	X3cste =  gtk_entry_get_text(saisie3);
	X2cste =  gtk_entry_get_text(saisie2);
	Xcste =  gtk_entry_get_text(saisie1);
	cste =  gtk_entry_get_text(saisie);
	DX4cste = gtk_entry_get_text(saisieD4);
	DX3cste = gtk_entry_get_text(saisieD3);
	DX2cste =  gtk_entry_get_text(saisieD2);
	DXcste =  gtk_entry_get_text(saisieD1);
	Dcste = gtk_entry_get_text(saisieD);
	if(NULL == texte)
	{
		fprintf(stderr,"label do not exist");
	}
	if(X3cste==NULL||X2cste==NULL||Xcste==NULL||cste==NULL)
	{
		fprintf(stderr,"NULL");
	}
	if(DX3cste==NULL||DX2cste==NULL||DXcste==NULL||Dcste==NULL)
	{
		fprintf(stderr,"NULL");
	}
	cf->left[0]= atoi(cste);
	cf->left[1]= atoi(Xcste);
	cf->left[2] =atoi(X2cste);
	cf->left[3] = atoi(X3cste);
	cf->left[4] = atoi(X4cste);
	cf->right[0] = atoi(Dcste);
	cf->right[1] =atoi(DXcste);
	cf->right[2] = atoi(DX2cste);
	cf->right[3]= atoi(DX3cste);
	cf->right[4] = atoi(DX4cste);
	int degre = FindDegree(cf->left);
  if(degre > 5) {
		if(g_file_get_contents(name_of_file,&contents,NULL,NULL))
		{
			texte = "Désolé ce solveur ne prend pas les équations de degré supérieur à 5. Merci de votre compréhension\n";
			gtk_label_set_text(texte,contents);
		}
  }
  //char* argv = 	Expression();
  //PrintMain(cf,degres,argv);
  FreeCoeff(cf);
}*/


G_MODULE_EXPORT void on_Matrice_clicked(){
			fenetre_matrice = GTK_WIDGET(gtk_builder_get_object(data.builder,"Matrix"));
			 gtk_widget_show_all (fenetre_matrice);
}
G_MODULE_EXPORT void on_Matrice_quit_clicked(){
			gtk_widget_destroy(fenetre_matrice);
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
