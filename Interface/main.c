#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <math.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "matrice.h"
#include "PrintMain.h"
#include "syst.h"
#include "interpolation.h"
#include "interpole.h"
#include "interpolation_newton.h"
#include "complex.h"

//#include "quatrieme_interface.h"

typedef struct
{
        GtkBuilder *builder;
        gpointer user_data;
} SGlobalData;

#define taille_max 1000 
static SGlobalData data;  

//EQUATION

static const gchar *X4cste =NULL;
static const gchar *X3cste= NULL;
static const gchar *X2cste= NULL;
static const gchar *Xcste= NULL;
static const gchar *cste= NULL;
static const gchar *DX4cste =NULL;
static const gchar *DX3cste= NULL;
static const gchar *DX2cste= NULL;
static const gchar *DXcste= NULL;
static const gchar *Dcste= NULL;

//INTEPOLATION LAGRANGE

		//LINEAIRE

static const gchar *lineairex1 =NULL;
static const gchar *lineairex2=NULL;
static const gchar *lineairey1=NULL;
static const gchar *lineairey2=NULL;
		
		//RECUP DEGRE

static const gchar *degre = NULL;

		//POLYNOMIALE DEGRE 
		static const gchar *un =NULL;
		static const gchar *deux=NULL;
		static const gchar *trois =NULL;
		static const gchar *quatre =NULL;
		static const gchar *cinq=NULL;
		static const gchar *unf =NULL;
		static const gchar *deuf =NULL;
		static const gchar *troif =NULL;
		static const gchar *quatref =NULL;
		static const gchar *cinqf=NULL;

//Matrice

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

//SYSTEM

static const gchar *X1 =NULL;
static const gchar *X2 =NULL;
static const gchar *X3 =NULL;
static const gchar *Y1 =NULL;
static const gchar *Y2 =NULL;
static const gchar *Y3 =NULL;
static const gchar *C1 =NULL;
static const gchar *C2 =NULL;
static const gchar *C3 =NULL;
static const gchar *Z1 =NULL;
static const gchar *Z2 =NULL;
static const gchar *Z3 =NULL;

//COMPLEX

static const gchar *a = NULL;
static const gchar *b = NULL;
static const gchar *c = NULL;
static const gchar *d = NULL;

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

static gchar *contents =NULL;
static gchar *contents_matrice =NULL;
static gchar *contents_syst =NULL;
static GtkEntry *Degre =NULL;
//static gchar *error =NULL;
static gchar *name_of_file_equation="équation.txt";
static gchar *name_of_file_system="systeme.txt";
static gchar *name_of_file="matrice.txt";
static gchar *name_of_fileC="complex.txt";  
static gchar *name_of_file_interpolationL ="interpolation_lineaire.txt";
static gchar *name_of_file_interpolationP ="interpolation_polynomiale.txt";
static gchar *name_of_file_interpolationN ="interpolation_newton.txt";
static gchar *name_of_file_interpolationNL ="interpolation_newtonl.txt";
static GtkWidget *fenetre_matrice = NULL;
static GtkWidget *fenetre_system= NULL;
static GtkWidget *fenetre_d = NULL;
static GtkWidget *fenetre_interpolation = NULL;
static GtkWidget *fenetre_interpolationLP = NULL;
static GtkWidget *fenetre_interpolationPoly2 = NULL;
static GtkWidget *fenetre_interpolationPoly3= NULL;
static GtkWidget *fenetre_interpolationPoly4 = NULL;
static GtkWidget *fenetre_polynom = NULL;
//static GtkWidget *fenetre_calculatrice = NULL;
static GtkWidget *fenetre_complex = NULL;


/*char* cmd[]={"rm","équation.txt",NULL};
	execvp(cmd[0],cmd);*/

//FENETRE PRINCIPALE

G_MODULE_EXPORT void on_MainWindow_clicked(){
	gtk_main_quit();
}

G_MODULE_EXPORT void on_polynom_clicked(){
	fenetre_polynom = GTK_WIDGET(gtk_builder_get_object(data.builder,"polynome"));
 	gtk_widget_show_all (fenetre_polynom);
	gtk_window_set_title(GTK_WINDOW(fenetre_polynom),"polynom");
}
G_MODULE_EXPORT void on_Interpolation_clicked(){
			fenetre_interpolation= GTK_WIDGET(gtk_builder_get_object(data.builder,"Interpole"));
			 gtk_widget_show_all (fenetre_interpolation);
			 gtk_window_set_title(GTK_WINDOW(fenetre_interpolation),"Interpolation");
}

G_MODULE_EXPORT void on_Matrice_clicked(){
			fenetre_matrice = GTK_WIDGET(gtk_builder_get_object(data.builder,"Matrix"));
			 gtk_widget_show_all (fenetre_matrice);
			 gtk_window_set_title(GTK_WINDOW(fenetre_matrice),"Matrix");
}
G_MODULE_EXPORT void on_quit_clicked(){
	gtk_main_quit();
}

G_MODULE_EXPORT void on_Systeme_clicked(){
			fenetre_system = GTK_WIDGET(gtk_builder_get_object(data.builder,"System"));
			 gtk_widget_show_all (fenetre_system);
			 gtk_window_set_title(GTK_WINDOW(fenetre_system),"linear system");
}
G_MODULE_EXPORT void on_complex_clicked()
{
	fenetre_complex = GTK_WIDGET(gtk_builder_get_object(data.builder,"Complex"));
			 gtk_widget_show_all (fenetre_complex);
			 gtk_window_set_title(GTK_WINDOW(fenetre_complex),"Complex");
}

//EQUATION

G_MODULE_EXPORT void on_Qui_clicked(){		
	gtk_widget_destroy(fenetre_polynom);
}
G_MODULE_EXPORT void on_treatment_equation_clicked(){
	//GtkLabel *texte = GTK_LABEL(
	//gtk_builder_get_object(data.builder, "resolution"));
	
	GtkEntry *saisie4 = GTK_ENTRY(gtk_builder_get_object(data.builder,"4cste"));
	GtkEntry *saisie3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"3cste"));
	GtkEntry *saisie2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"2cste"));
	GtkEntry *saisie1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"1cste"));
	GtkEntry *saisie = GTK_ENTRY(gtk_builder_get_object(data.builder,"cste"));
	GtkEntry *saisieD4 = GTK_ENTRY(gtk_builder_get_object(data.builder,"D4cste"));
	GtkEntry *saisieD3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"D3cste"));
	GtkEntry *saisieD2= GTK_ENTRY(gtk_builder_get_object(data.builder,"D2cste"));
	GtkEntry *saisieD1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"D1cste"));
	GtkEntry *saisieD = GTK_ENTRY(gtk_builder_get_object(data.builder,"Dcste"));
	
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
	/*if(NULL == texte)
	{
		fprintf(stderr,"label do not exist");
	}*/
	if(X3cste==NULL||X2cste==NULL||Xcste==NULL||cste==NULL)
	{
		fprintf(stderr,"NULL");
	}
	if(DX3cste==NULL||DX2cste==NULL||DXcste==NULL||Dcste==NULL)
	{
		fprintf(stderr,"NULL");
	}
	struct coeff *cf = malloc(sizeof(struct coeff));
  	cf->left = calloc(5, sizeof(int));
  	cf->right = calloc(5, sizeof(int));
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
	FILE* file = NULL;
	file = fopen("équation.txt","w");
	if(file != NULL){
  	Printmain(file,cf,degre);
      	fclose(file);
	}
  FreeCoeff(cf);
	fenetre_d = GTK_WIDGET(gtk_builder_get_object(data.builder,"display"));
	gtk_widget_show_all (fenetre_d);
	gtk_window_set_title(GTK_WINDOW(fenetre_d),"Résolution de l'équation");
	gtk_window_set_default_size(GTK_WINDOW(fenetre_d),100,2000);
	GtkLabel *texte_equation = GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution"));
	if(NULL == texte_equation)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file_equation,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_equation,contents);
	}
}

//INTERPOLATION LAGRANGE ET NEWTON

G_MODULE_EXPORT void on_quitte_clicked(){
	gtk_widget_destroy(fenetre_interpolation);
}

G_MODULE_EXPORT void on_treatment_interpole_clicked()
{
		fenetre_interpolationLP = GTK_WIDGET(gtk_builder_get_object(data.builder,"interpoleLP"));
		gtk_widget_show_all (fenetre_interpolationLP);
	    gtk_window_set_title(GTK_WINDOW(fenetre_interpolationLP),"Lagrange_&_Newton_Interpolation");	 
}
G_MODULE_EXPORT void on_treatment_newton1_clicked()
{
	GtkEntry *X1l = GTK_ENTRY(gtk_builder_get_object(data.builder,"x1cst"));
	GtkEntry *X2l = GTK_ENTRY(gtk_builder_get_object(data.builder,"x2cst"));
	GtkEntry *Y1l = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx1cste"));
	GtkEntry *Y2l = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx2cste"));
	lineairex1 =gtk_entry_get_text(X1l);
 	lineairex2 =gtk_entry_get_text(X2l);
	lineairey1 =gtk_entry_get_text(Y1l);
	lineairey2 =gtk_entry_get_text(Y2l);
	int x[2];
	int fx[2];
	x[0] = atoi(lineairex1);
	x[1] =atoi(lineairex2);
	fx[0] =atoi(lineairey1);
	fx[1]=atoi(lineairey2);
	FILE *file = fopen("interpolation_newtonl.txt","w");
	if(file !=NULL){
		interpolation_newton(1,file,x,fx);
		fclose(file);
	}
	fenetre_d = GTK_WIDGET(gtk_builder_get_object(data.builder,"display"));
	gtk_widget_show_all (fenetre_d);
	gtk_window_set_title(GTK_WINDOW(fenetre_d),"Résolution interpolation Newton degré 1");
	gtk_window_set_default_size(GTK_WINDOW(fenetre_d),100,2000);
	GtkLabel *texte_interpolationnl= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution"));
	if(NULL == texte_interpolationnl)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file_interpolationNL,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_interpolationnl,contents);
	}
}
G_MODULE_EXPORT void on_treatment_interpole_linear_clicked()
{
	GtkEntry *X1l = GTK_ENTRY(gtk_builder_get_object(data.builder,"x1cst"));
	GtkEntry *X2l = GTK_ENTRY(gtk_builder_get_object(data.builder,"x2cst"));
	GtkEntry *Y1l = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx1cste"));
	GtkEntry *Y2l = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx2cste"));
	lineairex1 =gtk_entry_get_text(X1l);
 	lineairex2 =gtk_entry_get_text(X2l);
	lineairey1 =gtk_entry_get_text(Y1l);
	lineairey2 =gtk_entry_get_text(Y2l);
	int x[2];
	int fx[2];
	x[0] = atoi(lineairex1);
	x[1] =atoi(lineairex2);
	fx[0] =atoi(lineairey1);
	fx[1]=atoi(lineairey2);
	FILE *file = fopen("interpolation_lineaire.txt","w");
	if(file !=NULL){
		interpole_lineaire(file,x,fx);
		fclose(file);
	}
	fenetre_d = GTK_WIDGET(gtk_builder_get_object(data.builder,"display"));
	gtk_widget_show_all (fenetre_d);
	gtk_window_set_title(GTK_WINDOW(fenetre_d),"Résolution interpolation linéaire");
	gtk_window_set_default_size(GTK_WINDOW(fenetre_d),100,2000);
	GtkLabel *texte_interpolationl= GTK_LABEL(gtk_builder_get_object(data.builder, "resolution"));
	if(NULL == texte_interpolationl)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file_interpolationL,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_interpolationl,contents);
	}
}
G_MODULE_EXPORT void on_treatment_interpole_poly_clicked()
{
		
		Degre = GTK_ENTRY(gtk_builder_get_object(data.builder,"degree"));
		degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
		if(d==2){
			fenetre_interpolationPoly2 = GTK_WIDGET(gtk_builder_get_object(data.builder,"interpoleP2"));
			gtk_widget_show_all (fenetre_interpolationPoly2);
			gtk_window_set_title(GTK_WINDOW(fenetre_interpolationPoly2),"Lagrange_polynome2");
		}
		else if(d ==3)
		{
			fenetre_interpolationPoly3 = GTK_WIDGET(gtk_builder_get_object(data.builder,"interpoleP3"));
			gtk_widget_show_all (fenetre_interpolationPoly3);
			gtk_window_set_title(GTK_WINDOW(fenetre_interpolationPoly3),"Lagrange_polynome3");
		
		}
		else if(d == 4)
		{
			fenetre_interpolationPoly4 = GTK_WIDGET(gtk_builder_get_object(data.builder,"interpoleP4"));
			gtk_widget_show_all (fenetre_interpolationPoly4);
			gtk_window_set_title(GTK_WINDOW(fenetre_interpolationPoly4),"Lagrange_polynome4");	 
			
		}
}
G_MODULE_EXPORT void on_treatment_poly2_clicked()
{
		degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
		FILE *file = fopen("interpolation_polynomiale.txt","w");
			GtkEntry *X1p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x1"));
			GtkEntry *X2p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x2"));
			GtkEntry *X3p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x3"));
			GtkEntry *Y1p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx1"));
			GtkEntry *Y2p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx2"));
			GtkEntry *Y3p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx3"));
			un =gtk_entry_get_text(X1p1);
			deux =gtk_entry_get_text(X2p1);
			trois =gtk_entry_get_text(X3p1);
			unf =gtk_entry_get_text(Y1p1);
			deuf=gtk_entry_get_text(Y2p1);
			troif =gtk_entry_get_text(Y3p1);
			int x[3] ={atoi(un),atoi(deux),atoi(trois)};
			int fx[3] ={atoi(unf),atoi(deuf),atoi(troif)};
			if(file !=NULL){
				interpolation_polynomiale_2(file,x,fx,d);
				fclose(file);
			}
			GtkLabel *texte_interpolationp1= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution_interpolation"));
			if(NULL == texte_interpolationp1)
			{
				fprintf(stderr,"label do not exist");
			}
			if(g_file_get_contents(name_of_file_interpolationP,&contents,NULL,NULL))
			{
				gtk_label_set_text(texte_interpolationp1,contents);
			}
}
G_MODULE_EXPORT void on_treatment_poly3_clicked()
{
	degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
	FILE *file = fopen("interpolation_polynomiale.txt","w");
		GtkEntry *X1p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x4"));
			GtkEntry *X2p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x5"));
			GtkEntry *X3p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x6"));
			GtkEntry *X4p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x7"));
			GtkEntry *Y1p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx4"));
			GtkEntry *Y2p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx5"));
			GtkEntry *Y3p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx6"));
			GtkEntry *Y4p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx7"));
			un =gtk_entry_get_text(X1p);
			deux =gtk_entry_get_text(X2p);
			trois =gtk_entry_get_text(X3p);
			quatre =gtk_entry_get_text(X4p);
			unf =gtk_entry_get_text(Y1p);
			deuf =gtk_entry_get_text(Y2p);
			troif =gtk_entry_get_text(Y3p);
			quatref =gtk_entry_get_text(Y4p);
			int x[4] ={atoi(un),atoi(deux),atoi(trois),atoi(quatre)};
			int fx[4]={atoi(unf),atoi(deuf),atoi(troif),atoi(quatref)};
			
			if(file !=NULL){
				interpolation_polynomiale_3(file,x,fx,d);
				fclose(file);
			}
			GtkLabel *texte_interpolationp2= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution_interpolation1"));
			if(NULL == texte_interpolationp2)
			{
				fprintf(stderr,"label do not exist");
			}
			if(g_file_get_contents(name_of_file_interpolationP,&contents,NULL,NULL))
			{
				gtk_label_set_text(texte_interpolationp2,contents);
			}
}
G_MODULE_EXPORT void on_treatment_poly4_clicked()
{
	degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
	FILE *file = fopen("interpolation_polynomiale.txt","w");
			GtkEntry *X1p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x8"));
			GtkEntry *X2p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x9"));
			GtkEntry *X3p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x10"));
			GtkEntry *X4p2= GTK_ENTRY(gtk_builder_get_object(data.builder,"x11"));
			GtkEntry *X5p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x12"));
			GtkEntry *Y1p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx8"));
			GtkEntry *Y2p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx9"));
			GtkEntry *Y3p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx10"));
			GtkEntry *Y4p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx11"));
			GtkEntry *Y5p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx12"));
			un =gtk_entry_get_text(X1p2);
			deux =gtk_entry_get_text(X2p2);
			trois =gtk_entry_get_text(X3p2);
			quatre =gtk_entry_get_text(X4p2);
			cinq=gtk_entry_get_text(X5p2);
			unf =gtk_entry_get_text(Y1p2);
			deuf =gtk_entry_get_text(Y2p2);
			troif =gtk_entry_get_text(Y3p2);
			quatref =gtk_entry_get_text(Y4p2);
			cinqf =gtk_entry_get_text(Y5p2);
			int x[5];
			x[0]=atoi(un);
			x[1] = atoi(deux);
			x[2] =atoi(trois);
			x[3] = atoi(quatre);
			x[4] = atoi(cinq);
			int fx[5];
			fx[0]= atoi(unf);
			fx[1]=atoi(deuf);
			fx[2] = atoi(troif);
			fx[3]=atoi(quatref);
			fx[4]=atoi(cinqf);
			if(file != NULL){
				interpolation_polynomiale_4(file,x,fx,d);
				fclose(file);
			}
	GtkLabel *texte_interpolationp3= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution_interpolation2"));
			if(NULL == texte_interpolationp3)
			{
				fprintf(stderr,"label do not exist");
			}
			if(g_file_get_contents(name_of_file_interpolationP,&contents,NULL,NULL))
			{
				gtk_label_set_text(texte_interpolationp3,contents);
			}	
}
G_MODULE_EXPORT void on_treatmentpoly2_clicked()
{
	degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
			FILE *file = fopen("interpolation_newton.txt","w");
			GtkEntry *X1p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x1"));
			GtkEntry *X2p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x2"));
			GtkEntry *X3p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x3"));
			GtkEntry *Y1p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx1"));
			GtkEntry *Y2p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx2"));
			GtkEntry *Y3p1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx3"));
			un =gtk_entry_get_text(X1p1);
			deux =gtk_entry_get_text(X2p1);
			trois =gtk_entry_get_text(X3p1);
			unf =gtk_entry_get_text(Y1p1);
			deuf=gtk_entry_get_text(Y2p1);
			troif =gtk_entry_get_text(Y3p1);
			int x[3] ={atoi(un),atoi(deux),atoi(trois)};
			int fx[3] ={atoi(unf),atoi(deuf),atoi(troif)};
			if(file != NULL){
				interpolation_newton(d,file,x,fx);
				fclose(file);
			}
			GtkLabel *texte_interpolationp5= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution_interpolation"));
			if(NULL == texte_interpolationp5)
			{
				fprintf(stderr,"label do not exist");
			}
			if(g_file_get_contents(name_of_file_interpolationN,&contents,NULL,NULL))
			{
				gtk_label_set_text(texte_interpolationp5,contents);
			}	
}
G_MODULE_EXPORT void on_treatmentpoly3_clicked()
{
	degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
	FILE *file = fopen("interpolation_newton.txt","w");
		GtkEntry *X1p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x4"));
			GtkEntry *X2p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x5"));
			GtkEntry *X3p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x6"));
			GtkEntry *X4p = GTK_ENTRY(gtk_builder_get_object(data.builder,"x7"));
			GtkEntry *Y1p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx4"));
			GtkEntry *Y2p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx5"));
			GtkEntry *Y3p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx6"));
			GtkEntry *Y4p = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx7"));
			un =gtk_entry_get_text(X1p);
			deux =gtk_entry_get_text(X2p);
			trois =gtk_entry_get_text(X3p);
			quatre =gtk_entry_get_text(X4p);
			unf =gtk_entry_get_text(Y1p);
			deuf =gtk_entry_get_text(Y2p);
			troif =gtk_entry_get_text(Y3p);
			quatref =gtk_entry_get_text(Y4p);
			int x[4] ={atoi(un),atoi(deux),atoi(trois),atoi(quatre)};
			int fx[4]={atoi(unf),atoi(deuf),atoi(troif),atoi(quatref)};
			if(file !=NULL){
				interpolation_newton(d,file,x,fx);
				fclose(file);
			}
			GtkLabel *texte_interpolationp6= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution_interpolation1"));
			if(NULL == texte_interpolationp6)
			{
				fprintf(stderr,"label do not exist");
			}
			if(g_file_get_contents(name_of_file_interpolationN,&contents,NULL,NULL))
			{
				gtk_label_set_text(texte_interpolationp6,contents);
			}
}
G_MODULE_EXPORT void on_treatmentpoly4_clicked()
{
	degre = gtk_entry_get_text(Degre);
		int d = atoi(degre);
	FILE *file = fopen("interpolation_newton.txt","w");
			GtkEntry *X1p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x8"));
			GtkEntry *X2p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x9"));
			GtkEntry *X3p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x10"));
			GtkEntry *X4p2= GTK_ENTRY(gtk_builder_get_object(data.builder,"x11"));
			GtkEntry *X5p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x12"));
			GtkEntry *Y1p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx8"));
			GtkEntry *Y2p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx9"));
			GtkEntry *Y3p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx10"));
			GtkEntry *Y4p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx11"));
			GtkEntry *Y5p2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"fx12"));
			un =gtk_entry_get_text(X1p2);
			deux =gtk_entry_get_text(X2p2);
			trois =gtk_entry_get_text(X3p2);
			quatre =gtk_entry_get_text(X4p2);
			cinq=gtk_entry_get_text(X5p2);
			unf =gtk_entry_get_text(Y1p2);
			deuf =gtk_entry_get_text(Y2p2);
			troif =gtk_entry_get_text(Y3p2);
			quatref =gtk_entry_get_text(Y4p2);
			cinqf =gtk_entry_get_text(Y5p2);
			int x[5];
			x[0]=atoi(un);
			x[1] = atoi(deux);
			x[2] =atoi(trois);
			x[3] = atoi(quatre);
			x[4] = atoi(cinq);
			int fx[5];
			fx[0]= atoi(unf);
			fx[1]=atoi(deuf);
			fx[2] = atoi(troif);
			fx[3]=atoi(quatref);
			fx[4]=atoi(cinqf);
			if(file != NULL){
				interpolation_newton(d,file,x,fx);
				fclose(file);
			}
		
	GtkLabel *texte_interpolationp7= GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution_interpolation2"));
			if(NULL == texte_interpolationp7)
			{
				fprintf(stderr,"label do not exist");
			}
			if(g_file_get_contents(name_of_file_interpolationN,&contents,NULL,NULL))
			{
				gtk_label_set_text(texte_interpolationp7,contents);
			}	
}
G_MODULE_EXPORT void on_Sortir_clicked()
{
	gtk_widget_destroy(fenetre_interpolationLP);
}
G_MODULE_EXPORT void on_Sortie2_clicked()
{
	gtk_widget_destroy(fenetre_interpolationPoly4);
}
G_MODULE_EXPORT void on_Sortie1_clicked()
{
	gtk_widget_destroy(fenetre_interpolationPoly3);
}
G_MODULE_EXPORT void on_Sortie_clicked()
{
	gtk_widget_destroy(fenetre_interpolationPoly2);
}



//DISPLAY

/*G_MODULE_EXPORT void on_Display_text_clicked(){
	fenetre_d = GTK_WIDGET(gtk_builder_get_object(data.builder,"display"));
	gtk_widget_show_all (fenetre_d);
	gtk_window_set_title(GTK_WINDOW(fenetre_d),"Résolution de l'équation");
	gtk_window_set_default_size(GTK_WINDOW(fenetre_d),100,2000);
	GtkLabel *texte_equation = GTK_LABEL(
			gtk_builder_get_object(data.builder, "resolution"));
	if(NULL == texte_equation)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file_equation,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_equation,contents);
	}
}*/
G_MODULE_EXPORT void on_quitt_clicked(){		
gtk_widget_destroy(fenetre_d);
}

//MATRICE

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

G_MODULE_EXPORT void on_Matrice_quit_clicked(){
	gtk_widget_destroy(fenetre_matrice);
}

//SYSTEMs

G_MODULE_EXPORT void on_qUIT_clicked(){
	gtk_widget_destroy(fenetre_system);
}
G_MODULE_EXPORT void on_treat2_clicked()
{
	GtkEntry *x1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x13"));
	GtkEntry *x2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x23"));
	GtkEntry *x3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x33"));

	GtkEntry *y1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"y13"));
	GtkEntry *y2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"y23"));
	GtkEntry *y3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"y33"));
	
	GtkEntry *c1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"3c"));
	GtkEntry *c2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"23c"));
	GtkEntry *c3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"3c3"));
	
	GtkEntry *z1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"z13"));
	GtkEntry *z2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"z23"));
	GtkEntry *z3 = GTK_ENTRY(gtk_builder_get_object(data.builder,"z33"));
	X1 =  gtk_entry_get_text(x1);
	X2 =  gtk_entry_get_text(x2);
	X3 =  gtk_entry_get_text(x3);
  	Y1 =  gtk_entry_get_text(y1);
	Y2 =  gtk_entry_get_text(y2);
	Y3 =  gtk_entry_get_text(y3);
	C1 =  gtk_entry_get_text(c1);
	C2 =  gtk_entry_get_text(c2);
	C3 =  gtk_entry_get_text(c3);
	Z1 =  gtk_entry_get_text(z1);
	Z2 =  gtk_entry_get_text(z2);
	Z3 =  gtk_entry_get_text(z3);
	float inco[12];
	inco[0] = atof(X1); 
	inco[1] = atof(Y1);  
	inco[2] = atof(Z1); 
	inco[3] = atof(C1);  
	inco[4] = atof(X2);  
	inco[5] = atof(Y2);  
	inco[6] = atof(Z2);  
	inco[7] = atof(C2);
	inco[8] = atof(X3);
	inco[9] = atof(Y3);
	inco[10] = atof(Z3);
	inco[11] = atof(C3);

	//float M[8]={atof(X1),atof(Y1),atof(Z1),atof(C1),atof(X2),atof(Y2),atof(Z2),atof(C2)};
	FILE *file= fopen("systeme.txt","w");
	if(file !=NULL)
	{
		solveur_3_inconnu(file,inco);
		fclose(file);
	}
	GtkLabel *texte_systeme3 = GTK_LABEL(gtk_builder_get_object(data.builder, "solver"));
	if(NULL == texte_systeme3)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file_system,&contents_syst,NULL,NULL))
	{
		gtk_label_set_text(texte_systeme3,contents_syst);
	}

}
G_MODULE_EXPORT void on_treatment_system_clicked()
{
	GtkEntry *x1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x1cste"));
	GtkEntry *x2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"x2cste"));
	GtkEntry *y1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"y1cste"));
	GtkEntry *y2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"y2cste"));
	GtkEntry *c1= GTK_ENTRY(gtk_builder_get_object(data.builder,"1cst"));
	GtkEntry *c2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"2cst"));
	X1 =  gtk_entry_get_text(x1);
	X2 =  gtk_entry_get_text(x2);
  	Y1 =  gtk_entry_get_text(y1);
	Y2 =  gtk_entry_get_text(y2);
	C1 =  gtk_entry_get_text(c1);
	C2 =  gtk_entry_get_text(c2);
	//size_t column = 3;
	float inco[1 * 3 + 3];
	inco[0 * 3 + 0] = atof(X1); // 0
	inco[0 * 3 + 1] = atof(Y1);  // 1
	inco[0 * 3 + 2] = atof(C1);  // 2
	inco[1 * 3 + 0] = atof(X2);  // 3
	inco[1 * 3 + 1] = atof(Y2);  // 4
	inco[1 * 3 + 2] = atof(C2);  // 5
	FILE *file =fopen("systeme.txt","w");
	if(file != NULL){
	solveur_2_inconnu(file,inco);
	fclose(file);}
		GtkLabel *texte_systeme = GTK_LABEL(
			gtk_builder_get_object(data.builder, "solver"));
	if(NULL == texte_systeme)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_file_system,&contents_syst,NULL,NULL))
	{
		gtk_label_set_text(texte_systeme,contents_syst);
	}
}

// COMPLEX

G_MODULE_EXPORT void on_out_clicked()
{
	gtk_widget_destroy(fenetre_complex);
}
G_MODULE_EXPORT void on_egalP_clicked()
{
	FILE *file =fopen("complex.txt","w");
	GtkEntry *Iplus1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"iplus1"));
	GtkEntry *Plus1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"plus1"));
	GtkEntry *Iplus2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"iplus2"));
	GtkEntry *Plus2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"plus2"));
	a = gtk_entry_get_text(Iplus1);
	b= gtk_entry_get_text(Plus1);
	c =gtk_entry_get_text(Iplus2);
	d =gtk_entry_get_text(Plus2);
	struct Complex *A = malloc(sizeof(struct Complex));
	struct Complex *B = malloc(sizeof(struct Complex));
	A->real = atof(a);
	A->img = atof(b);
	B->real = atof(c);
	B->img = atof(d);
	if(file !=NULL)
	{
		Addition(file,A,B);
		fclose(file);
	}
	GtkLabel *texte_complex = GTK_LABEL(gtk_builder_get_object(data.builder, "explication"));
	if(NULL == texte_complex)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_fileC,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_complex,contents);
	}
	//free(A);
	//free(B);
}
G_MODULE_EXPORT void on_egalMult_clicked()
{
	FILE *file =fopen("complex.txt","w");
	GtkEntry *Imult1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"imult1"));
	GtkEntry *Mult1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"mult1"));
	GtkEntry *Imult2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"imult2"));
	GtkEntry *Mult2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"mult2"));
	a = gtk_entry_get_text(Imult1);
	b= gtk_entry_get_text(Mult1);
	c =gtk_entry_get_text(Imult2);
	d =gtk_entry_get_text(Mult2);
	struct Complex *A = malloc(sizeof(struct Complex));
	struct Complex *B = malloc(sizeof(struct Complex));
	A->real = atof(a);
	A->img = atof(b);
	B->real = atof(c);
	B->img = atof(d);
	if(file !=NULL)
	{
		Multiplication(file,A,B);
		fclose(file);
	}
	GtkLabel *texte_complex = GTK_LABEL(gtk_builder_get_object(data.builder, "explication"));
	if(NULL == texte_complex)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_fileC,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_complex,contents);
	}
}
G_MODULE_EXPORT void on_egalD_clicked()
{
	FILE *file =fopen("complex.txt","w");
	GtkEntry *Idiv1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"idiv1"));
	GtkEntry *Div1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"div1"));
	GtkEntry *Idiv2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"idiv2"));
	GtkEntry *Div2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"div2"));
	a = gtk_entry_get_text(Idiv1);
	b= gtk_entry_get_text(Div1);
	c =gtk_entry_get_text(Idiv2);
	d =gtk_entry_get_text(Div2);
	struct Complex *A = malloc(sizeof(struct Complex));
	struct Complex *B = malloc(sizeof(struct Complex));
	A->real = atof(a);
	A->img = atof(b);
	B->real = atof(c);
	B->img = atof(d);
	if(file !=NULL)
	{
		Division(file,A,B);
		fclose(file);
	}
	GtkLabel *texte_complex = GTK_LABEL(gtk_builder_get_object(data.builder, "explication"));
	if(NULL == texte_complex)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_fileC,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_complex,contents);
	}
}
G_MODULE_EXPORT void on_conjugue_clicked()
{
		GtkEntry *Iconj = GTK_ENTRY(gtk_builder_get_object(data.builder,"iconj"));
		GtkEntry *Conj = GTK_ENTRY(gtk_builder_get_object(data.builder,"conj"));
		struct Complex *C= malloc(sizeof(struct Complex));
		a = gtk_entry_get_text(Iconj);
		b = gtk_entry_get_text(Conj);
		C->real = atof(a);
		C->img = atof(b);
		FILE *file=fopen("complex.txt","w");
		if(file !=NULL)
		{
			Conjuguer(file,C);
			fclose(file);
		}
		GtkLabel *texte_complex2 = GTK_LABEL(gtk_builder_get_object(data.builder, "explication"));
		if(NULL == texte_complex2)
		{
			fprintf(stderr,"label do not exist");
		}
		if(g_file_get_contents(name_of_fileC,&contents,NULL,NULL))
		{
			gtk_label_set_text(texte_complex2,contents);
		}		
		//free(C);
}

G_MODULE_EXPORT void on_egalM_clicked()
{
	FILE *file =fopen("complex.txt","w");
	GtkEntry *Imoins1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"imoins1"));
	GtkEntry *Moins1 = GTK_ENTRY(gtk_builder_get_object(data.builder,"moins1"));
	GtkEntry *Imoins2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"imoins2"));
	GtkEntry *Moins2 = GTK_ENTRY(gtk_builder_get_object(data.builder,"moins2"));
	a = gtk_entry_get_text(Imoins1);
	b= gtk_entry_get_text(Moins1);
	c =gtk_entry_get_text(Imoins2);
	d =gtk_entry_get_text(Moins2);
	struct Complex *D = malloc(sizeof(struct Complex));
	struct Complex *E = malloc(sizeof(struct Complex));
	D->real = atof(a);
	D->img = atof(b);
	E->real = atof(c);
	E->img = atof(d);
	if(file !=NULL)
	{
		Soustration(file,D,E);
		fclose(file);
	}
	GtkLabel *texte_complex3 = GTK_LABEL(gtk_builder_get_object(data.builder, "explication"));
	if(NULL == texte_complex3)
	{
		fprintf(stderr,"label do not exist");
	}
	if(g_file_get_contents(name_of_fileC,&contents,NULL,NULL))
	{
		gtk_label_set_text(texte_complex3,contents);
	}
	//free(D);
	//free(E);
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
    gtk_window_set_title(GTK_WINDOW(fenetre_principale),"Solveur");
    /* Showing the main window */
    gtk_window_set_default_size(GTK_WINDOW(fenetre_principale),100,150);
    gtk_widget_show_all (fenetre_principale);
    gtk_main();
    return 0;
}
