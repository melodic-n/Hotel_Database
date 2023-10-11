#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <windows.h>



struct client {
    int id;
    char prenom[200];
    char nom[200];
    char CIN[20];
    int num_chbre;
    char date[100];
};

 struct employe {
    int id;
    char prenom[200];
    char nom[200];
    char CIN[20];
    char service[100];
    char position[100];
};



// changer le nom et apparence de la console
void title(){
    SetConsoleTitle("Hotel Database.");
    system("COLOR f9");
}



void loading(){
int i ;
system("cls"); // effacer le text existant avant
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t \t \t \t loading");
    for(i=0;i<3;i++){
        printf(".");
        sleep(1); // blocker l'instruction suivante pour une seconde
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}


// log in
void login(){

    char password[20]="vichycelestin", pass[20];
    ps:
        system("COLOR f9");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t");
        printf("entrer le mot de pass : \n");
         printf("\t\t\t\t\t\t");
          printf("----->   ");
          scanf("%s",pass);

        if (strcmp(pass, password) == 0) {
            printf("\n\n\t\t\t\t\t\t\t\t\Access granted.\n");
            getch();

        }
        else {
         system("COLOR f4");
            printf("\t\t\t\t\t\taccess denied \n");
            getch();
            system("cls");
            goto ps; //loop
        }
    }



void showlistclient(){
FILE*fp=fopen("clientDB.txt","r");

if (fp == NULL){
    printf("error ,fichier n'est pas ouvert.");
    return;
}
char list[100];
system("cls");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t\t5. Liste des clients \n");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t    | ID   |    Nom     |       Prenom      |       CIN   |  Numero de chambre |  Date de reservation  |\n");
printf("\t\t  ____________________________________________________________________________________________________________________\n");
while(fgets(list,sizeof(list),fp)!= NULL){
    printf("\n");
    printf("\t\t\t%s",list);
}
fclose(fp);
getch();
}


////////////////////////////////////////////////////////////////////////////


void showlistemploye(){
FILE*fp=fopen("employeDB.txt","r");

if (fp == NULL){
    printf("error ,fichier n'est pas ouvert.");
    return;
}
char list[100];
system("cls");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t\t6. Liste des employes \n");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t    | ID    |    Nom      |     Prenom         |       CIN   |       Service   |      Position     |\n");
printf("\t\t_______________________________________________________________________________________________\n");
while(fgets(list,sizeof(list),fp)!= NULL){
    printf("\n");
    printf("\t\t\t%s",list);
}
getch();
fclose(fp);
}


void Add(){
char choix[50];
system("cls");
printf("\n\n\n\n\n\n");
 printf("\t\t\t\t\t\t");
printf("Client ou employe :\n");
        printf("\t\t\t\t\t\t---->");
scanf("%s",choix);

if (strcmp(choix, "client") == 0){
    FILE * fp=fopen("clientDB.txt","a");
    if (fp == NULL){
            printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t");
    system("COLOR f4");
        printf("fichier n'est pas ouvert");
        getch();
        return;
    }
    else{

    struct client * clt;
    clt=calloc(1,sizeof(*clt));
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t 1.Ajouter un client \n");
    printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t\t");
    printf("entrer ID du client \n");
        printf("\t\t\t\t");
    scanf("%d",&clt->id);
        printf("\t\t\t\t");
    printf("entrer le nom du client\n");
        printf("\t\t\t\t");
    scanf("%s",clt->nom);
        printf("\t\t\t\t");
    printf("entrer le prenom du client \n");
        printf("\t\t\t\t");
    scanf("%s",clt->prenom);
        printf("\t\t\t\t");
    printf("entrer la CIN du client \n");
        printf("\t\t\t\t");
    scanf("%s",clt->CIN);
        printf("\t\t\t\t");
    printf("entrer le numero de la chambre reservee \n");
        printf("\t\t\t\t");
    scanf("%d",&clt->num_chbre);
        printf("\t\t\t\t");
    printf("entrer la date de reservation \n");
        printf("\t\t\t\t");
    scanf("%s",clt->date);

    fprintf(fp,"%d\t ",clt->id);
     fprintf(fp,"%s\t\t",clt->nom);
   fprintf(fp,"%s\t\t   ",clt->prenom);
    fprintf(fp,"%s\t    ",clt->CIN);
     fprintf(fp,"%d\t\t",clt->num_chbre);
      fprintf(fp,"%s\t \n ",clt->date);
      fclose(fp);
      printf("\n \t\t\t\t\tClient ajoute.");
      getch();
}
}
else if (strcmp(choix, "employe") == 0){//0 if the two strings are equal

        FILE * fp=fopen("employeDB.txt","a");
    struct employe * emp;
     if (fp == NULL){
            printf("\n\n\n\n\n\n");
                   printf("\t\t\t\t");
                     system("COLOR f4");
        printf("fichier n'est pas ouvert");
        getch();
        return;
    }
    else{
    emp=calloc(1,sizeof(*emp));
        system("cls");
    printf("\n\n\n\n\n\n");
printf("\t\t\t\t 1.Ajouter un employe \n");
printf("\t\t\t---------------------------------------------------------------\n");
       printf("\t\t\t\t");
    printf("entrer ID de l'employe \n");
           printf("\t\t\t\t");
    scanf("%d",&emp->id);
           printf("\t\t\t\t");
    printf("entrer le nom de l'employe \n");
           printf("\t\t\t\t");
    scanf("%s",emp->nom);
           printf("\t\t\t\t");
    printf("entrer le prenom de l'employe \n");
           printf("\t\t\t\t");
    scanf("%s",emp->prenom);
           printf("\t\t\t\t");
    printf("entrer la CIN de l'employe  \n");
           printf("\t\t\t\t");
    scanf("%s",emp->CIN);
           printf("\t\t\t\t");
    printf("entrer son service \n");
           printf("\t\t\t\t");
    scanf("%s",&emp->service);
           printf("\t\t\t\t");
    printf("entrer sa position \n");
           printf("\t\t\t\t");
    scanf("%s",emp->position);

    fprintf(fp,"%d\t ",emp->id);
     fprintf(fp,"%s\t\t",emp->nom);
   fprintf(fp,"%s\t\t   ",emp->prenom);
    fprintf(fp,"%s\t    ",emp->CIN);
     fprintf(fp,"%s\t\t",emp->service);
      fprintf(fp,"%s\t   ",emp->position);
      fprintf(fp,"\n");
      fclose(fp);

      printf("\n \t\t\t\t\t employe ajoute.");
      getch();

}
}
else{
        system("cls");
        printf("\n\n\n\n\n\n");
printf("\t\t\t\t");
  system("COLOR f4");
    printf("Error : choix inconnu");
    getch();
    return;
}
}



void modifier_info(){

char choix[30];
system("cls");
   printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t");
printf("Client ou employe :\n");
        printf("\t\t\t\t\t\t---->");
scanf("%s",choix);

if (strcmp(choix,"client")==0){
        char buffer[2000];
        struct client * clt;
    clt=calloc(1,sizeof(*clt));

    FILE * pt=fopen("clientDB.txt","r");
     if (pt == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        getch();
        return;
    }
    FILE * tp=fopen("clientDB2.tmp","w");
     if (tp == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        fclose(pt);
        getch();
        return;
    }

    int i;
    char id[5],line[5];
        system("cls");
    printf("\n\n\n\n\n\n");
printf("\t\t\t\t 2.Modifier les informations  d'un client \n");
printf("\t\t\t---------------------------------------------------------------\n");
       printf("\t\t\t\t");
            printf("entrer ID de l'employe :\n");
            printf("\t\t\t\t");
    scanf("%s",line);
         printf("\t\t\t\t");
        printf("entrer ID :\n");
        printf("\t\t\t\t");
        scanf("%d",&clt->id);
         printf("\t\t\t\t");
        printf("entrer le nom de client : \n");
         printf("\t\t\t\t");
         scanf("%s",clt->nom);
         printf("\t\t\t\t");
        printf("entrer le prenom de client :\n");
         printf("\t\t\t\t");
         scanf("%s",clt->prenom);
         printf("\t\t\t\t");
        printf("entrer la CIN de client :\n");
         printf("\t\t\t\t");
         scanf("%s",clt->CIN);
         printf("\t\t\t\t");
        printf("entrer le chmbare : \n");
         printf("\t\t\t\t");
         scanf("%d",&clt->num_chbre);
         printf("\t\t\t\t");
        printf("entrer date : \n");
        printf("\t\t\t\t");
        scanf("%s",clt->date);

   while(fgets(buffer,sizeof(buffer),pt) != NULL){
            i=0;
       while ( buffer[i] != '\t' )
	{
       id[i]=buffer[i];
            i++;
              if(buffer[i] == '\t')
                id[i]='\0';
        }

        if(strcmp(line,id) == 0){
        fprintf(tp,"%d\t ",clt->id);
            fprintf(tp,"%s\t\t",clt->nom);
            fprintf(tp,"%s\t\t   ",clt->prenom);
            fprintf(tp,"%s\t    ",clt->CIN);
            fprintf(tp,"%d\t\t",clt->num_chbre);
            fprintf(tp,"%s\t  ",clt->date);
            fprintf(tp,"\n");

        }
        else{

            fputs(buffer,tp);
		}
//
       }



    fclose(tp);
    fclose(pt);
	if( remove("clientDB.txt")==0 &&  rename("clientDB2.tmp","clientDB.txt") == 0){

        printf("\n\t\t\t\t Modified succesfully\n");
	}

	else {
            perror("Error");
            fclose(pt);
        fclose(tp);
        remove("clientDB2.tmp");
        }


   getch();

}

else if (strcmp(choix,"employe")==0){
         char buffer[200];
        struct employe *emp;
        emp=calloc(1,sizeof(*emp));

       FILE * pt=fopen("employeDB.txt","r");
     if (pt == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        getch();
        return;
    }
    FILE * tp=fopen("employeDB2.tmp","w");
     if (tp == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        fclose(pt);
        getch();
        return;
    }
     int i;
    char id[5],line[5];
        system("cls");
    printf("\n\n\n\n\n\n");
printf("\t\t\t\t 2.Modifier les informations  d'un employe \n");
printf("\t\t\t---------------------------------------------------------------\n");
       printf("\t\t\t\t");
            printf("entrer ID de l'employe :\n");
            printf("\t\t\t\t");
    scanf("%s",line);
         printf("\t\t\t\t");
        printf("entrer ID :\n");
        printf("\t\t\t\t");
        scanf("%d",&emp->id);
         printf("\t\t\t\t");
        printf("entrer le nom de l'employe : \n");
         printf("\t\t\t\t");
         scanf("%s",emp->nom);
         printf("\t\t\t\t");
        printf("entrer le prenom de l'employe :\n");
         printf("\t\t\t\t");
         scanf("%s",emp->prenom);
         printf("\t\t\t\t");
        printf("entrer la CIN de l'employe :\n");
         printf("\t\t\t\t");
         scanf("%s",emp->CIN);
         printf("\t\t\t\t");
        printf("entrer le service : \n");
         printf("\t\t\t\t");
         scanf("%s",emp->service);
         printf("\t\t\t\t");
        printf("entrer position : \n");
        printf("\t\t\t\t");
        scanf("%s",emp->position);

   while(fgets(buffer,sizeof(buffer),pt) != NULL){
            i=0;
       while ( buffer[i] != '\t' )
	{
       id[i]=buffer[i];
            i++;
        if(buffer[i] == '\t')
            id[i]='\0';


        }


        if(strcmp(line,id) == 0){
 fprintf(tp,"%d\t ",emp->id);
            fprintf(tp,"%s\t\t",emp->nom);
            fprintf(tp,"%s\t\t   ",emp->prenom);
            fprintf(tp,"%s\t    ",emp->CIN);
            fprintf(tp,"%s\t\t",emp->service);
            fprintf(tp,"%s\t  ",emp->position);
            fprintf(tp,"\n");

        }
        else{

 fputs(buffer,tp);
		}
//
       }



    fclose(tp);
    fclose(pt);
	if( remove("employeDB.txt")==0 &&  rename("employeDB2.tmp","employeDB.txt") == 0){

        printf("\n\t\t\t\t Modified succesfully\n");
	}

	else {
            perror("Error");
            fclose(pt);
        fclose(tp);
        remove("employeDB2.tmp");
        }


   getch();

}


    }


void delete_all(){
 char certain[10];
 system("cls");
   printf("\n\n\n\n\n\n");

printf("\t\t\t\t4. Surprimmer Toutes la base de donnees \n");
printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t\t");
 printf("Etes vous sure (oui/non) ?\n");
    printf("\t\t\t\t\t\t");
 scanf("%s",certain);

 if(strcmp(certain,"non") == 0 )
    return;

 else if (strcmp(certain,"oui")==0){
 FILE* cf=fopen("clientDB.txt","w");
 FILE* ef=fopen("employeDB.txt","w");
    fputs("",cf);
    fputs("",ef);

    printf("\t\t\t\t\t\tSupprime avec succes");
    getch();
    fclose(cf);
    fclose(ef);

 }
else{
      printf("\n\n\n\n");
    printf("\t\t\t\t\t\t");
      printf("choix inconnu.\n");
}


}



void delete_info(){
char choix[30];
system("cls");
   printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t");
printf("Client ou employe :\n");
        printf("\t\t\t\t\t\t---->");
scanf("%s",choix);




if (strcmp(choix,"client")==0){
        char buffer[200];
/////////////////////////////////////////////////////////////////
    FILE *pt=fopen("clientDB.txt","r");
  if (pt == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        getch();
        return;
    }
/////////////////////////////////////////////////////////////////
    FILE *tp=fopen("clientDB2.tmp","w");
   if (tp == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        fclose(pt);
        getch();
        return;
    }

/////////////////////////////////////////////////////////////

     int i;
    char id[5],line[5];
        system("cls");
    printf("\n\n\n\n\n\n");
printf("\t\t\t\t 3.Surprimer un client \n");
printf("\t\t\t---------------------------------------------------------------\n");
       printf("\t\t\t\t");
       //////////////////////////////////////////////////////////////////////////////////////
            printf("entrer ID du client:\n");
            printf("\t\t\t\t");
    scanf("%s",line);
///////////////////////////////////////////////////////////////////////////////////////////////
    while(fgets(buffer,sizeof(buffer),pt) != NULL){
            i=0;






       while ( buffer[i] != '\t' )
            {
       id[i]=buffer[i];
            i++;
            if(buffer[i] == '\t')
                id[i]='\0';
                }

        if(strcmp(line,id) == 0){
            fputs("",tp);

              printf("\t\t\t\t");

        }


        else{
                fputs(buffer,tp);

        }


}
///////////////////////////////////////////////////////////////////////////////////////////////

    fclose(tp);
    fclose(pt);
    ///////////////////////////////////////////////////////////////////////////////////////////////

	if( remove("clientDB.txt")==0 &&  rename("clientDB2.tmp","clientDB.txt") == 0){

        printf("\n\t\t\t\toperation termine \n");
	}
	///////////////////////////////////////////////////////////////////////////////////////////////


	else {
            perror("Error");
            fclose(pt);
        fclose(tp);
        remove("clientDB2.tmp");
        }

///////////////////////////////////////////////////////////////////////////////////////////////

   getch();


}
///////////////////////////////////////////////////////////////////////////////////////////////



else if (strcmp(choix,"employe")==0){
         char buffer[200];
        int ligne;
        bool ok = false;
        struct employe *emp;
        emp=calloc(1,sizeof(*emp));

       FILE * pt=fopen("employeDB.txt","r");
     if (pt == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        getch();
        return;
    }
    FILE * tp=fopen("employeDB2.tmp","w");
     if (tp == NULL){
            system("cls");
        printf("fichier n'est pas ouvert");
        fclose(pt);
        getch();
        return;
    }
     int i;
    char id[5],line[5];
        system("cls");
    printf("\n\n\n\n\n\n");

printf("\t\t\t\t3. Surprimmer un employe \n");
printf("\t\t\t---------------------------------------------------------------\n");
       printf("\t\t\t\t");
            printf("entrer ID de l'employe :\n");
            printf("\t\t\t\t");
    scanf("%s",line);

  while(fgets(buffer,sizeof(buffer),pt) != NULL){
            i=0;


       while ( buffer[i] != '\t' )
            {
       id[i]=buffer[i];
            i++;
              if(buffer[i] == '\t')
                id[i]='\0';
                }


        if(strcmp(line,id) == 0){
                   fputs("",tp);

        }


        else{
        fputs(buffer,tp);



        }
       }

    fclose(tp);
    fclose(pt);
	if( remove("employeDB.txt")==0 &&  rename("employeDB2.tmp","employeDB.txt") == 0){

        printf("\n\t\t\t\t Supprime avec succes \n");
	}

	else {
            perror("Error");
            fclose(pt);
        fclose(tp);
        remove("employeDB2.tmp");
        }


   getch();


}
else{
    printf("Error : choix inconnu");
    getch();
    return;
}

}






void main (){
title();

login();
int input=0;

mn:
    title();
    system("cls");
    printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t\t\t *Hotel Database *");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t-----------------------------------------------------------------------------------\t\t\t\t\t\t");
printf("\n");
printf("\n");
printf("\t\t\t -----> Ajouter un Client/employe (1)\n ");
printf("\t\t\t -----> Modifier les informations d'un Client/employe (2)\n ");
printf("\t\t\t -----> Surprimer un Client/employe (3)\n ");
printf("\t\t\t -----> Surprimer toutes les base de donnees (4)\n ");
printf("\t\t\t -----> Afficher la liste des Clients (5)\n ");
printf("\t\t\t -----> Afficher la liste des employes (6)\n ");
printf("\n");
printf("\t\t-----------------------------------------------------------------------------------\t\t\t\t\t\n");
printf("\t\t\t\tEntrer votre choix :\n");
printf("\t\t\t\t-----> ");
scanf("%d",&input);

switch(input){
case(1):loading();Add();
break;
case(2):loading();modifier_info();
break;
case(3):loading();delete_info();
break;
case(4):loading();delete_all();
break;
case(5):loading();showlistclient();
break;
case(6):loading();showlistemploye();
break;
default:exit(1);

}
fflush(stdin);
input=0;
goto mn;

}
