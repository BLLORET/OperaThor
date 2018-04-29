

void Main(void)
{
	FILE *ok=fopen("test.txt","w");
	if(ok !=NULL){
		for(int j=1; j<5; j++)
			SaveX(ok,x,j);
		
	}
	fclose(ok);
	int res =0, j=0;
	int polyfinal[100];
	int dex =0;
	int p1[2];
	int p2[2];
	int p3[2];
	int p4[2];
	int second_degre[3];
	int troisieme_degre[4];
	int quatrieme_degre[5];
	ok = fopen("test.txt","r");
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		int res1[2];
		MULTIPLIER(2,diff[1],p1,res1);
		REMPLISTRUCT(2,PARTIE1,res1);
	}
	long position = ftell(ok);
	fseek(ok,position,SEEK_SET);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		dev2(p1,p2,second_degre);
		int res2[3];
		MULTIPLIER(3,diff[2],second_degre,res2);
		REMPLISTRUCT(3,PARTIE2,res2);
	}
	position = ftell(ok);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);	
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		REMPLIR(0,5,4,NUMBER,p3);
		dev2(p1,p2,second_degre);
		dev3(second_degre,p3,troisieme_degre);
		int res3[4];
		MULTIPLIER(4,diff[3],troisieme_degre,res3);
		REMPLISTRUCT(4,PARTIE3,res3);
	}
	fclose(ok);
	position = ftell(ok);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);	
		REMPLIR(0,1,0,NUMBER,p1);
		PRINT_PART(p1,2,1);
		REMPLIR(0,3,2,NUMBER,p2);
		PRINT_PART(p2,2,2);
		REMPLIR(0,5,4,NUMBER,p3);
		PRINT_PART(p3,2,3);
		REMPLIR(0,7,6,NUMBER,p4);
		PRINT_PART(p4,2,2);
		dev2(p1,p2,second_degre);
		dev3(second_degre,p3,troisieme_degre);
		dev4(troisieme_degre,p4,quatrieme_degre);
		int res4[5];
		MULTIPLIER(5,diff[4],quatrieme_degre,res4);
		REMPLISTRUCT(5,PARTIE4,res4);
	}
	fclose(ok);
}