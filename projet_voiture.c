#define LINUX // Pour compilez pour un ordi fonctionnant sous un systeme linux
// #define WINDOW // Pour compilez pour un ordi fonctionnant sous un système window 

#ifdef LINUX
#define COMMAND "clear"
#endif

#ifdef WINDOW
#define COMMAND "clr"
#endif

#define TAILLE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vehicule
{
  char marque[TAILLE];
  double kilometrage;
  char type[TAILLE];
  int volume; // nombre maximum de siège
  int prix_jour;
};
typedef struct vehicule vehicule;

struct client
{
  char nom[TAILLE];
  char prenom[TAILLE];
  char adresse[TAILLE];
  char voiture[TAILLE];;
};
typedef struct client client;

struct facture
{
  char nom[TAILLE];
  char prenom[TAILLE];
  char voiture[TAILLE];
  char date[TAILLE];
  char somme[TAILLE];
};
typedef struct facture facture;

struct reserv
{
  char nom[TAILLE];
  char prenom[TAILLE];
  char voiture[TAILLE];
};
typedef struct reserv reserv;

void menu(int *bool);

void add_vehi();
void save_vehi(vehicule voiture);
void tmp_vehi(vehicule voiture);
vehicule *vehi_tab(int *taille);
void del_vehi();
void show_vehi(vehicule *tab,int taille);
void info_vehi();
void show_clientvehi();
void view_vehi(vehicule voiture);

void add_client();
void save_client(client cli);
void tmp_client(client cli);
void del_client();
void modify_client();
void show_client(client cli);
void info_client();

void add_fact();
void save_fact(facture fact);
void show_fact(facture fact);
void info_fact();
void tmp_fact(facture fact);
void del_fact();
void show_clientfact();

void add_reserv();
void save_reserv(reserv voiture);
void show_reserv(reserv voiture);
void info_reserv();
void tmp_resev();
void del_reserv();

void delRet(char *chaine); // fonction pour supprimer le retour à la ligne de la fonction fgets()

char *cryptage(char *password,int pas_char,int pas_int);
char *decrypt(char *password,int pas_char,int pas_int);
void verf_passFile();
int verf_pass();

void menu(int *bool)
{
  static int choix1=0,choix2=0,verf=0;

  verf_passFile(); // verification du fichier de mot de passe
  if(choix1==0)
    {
      printf("**********************************\n");
      printf("*      GESTION DE VEHICULES      *\n");
      printf("**********************************\n");
      printf("\n");
      printf("1.Modifier le mot de passe\n2.Personnels\n3.clients\n4.Quitter\nChoix:");
      scanf("%d",&choix1);
      getchar();
      printf("\n");
    }
  else if(choix1>4)
    choix1=0;

  switch(choix1)
    {
    case 1:
      system(COMMAND);
      if(verf_pass())
	{
	  remove("passwd.dat");
	  verf_passFile();
	}
      printf("\n");
      choix1=0;
      break;
    case 2:
      if(verf==0)
	{
	  system(COMMAND);
	  verf=verf_pass();
	}
      if(verf)
	{
	  printf("*---> Personnel:\n");
	  printf("\t1.Ajouter un vehicule\n\t2.Supprimer un vehicule\n\t3.Ajouter un client\n\t4.Modifier un client\n\t5.Supprimer un client\n\t6.Ajouter une facture\n\t7.Supprimer une facture\n\t8.Reserver un vehicule pour un client\n\t9.Afficher les informations des clients\n\t10.Afficher les vehicules disponibles\n\t11.Afficher les reservations\n\t12.Afficher les factures\n\t13.Supprimer des reservations\n\t14.Retour\nChoix:");
	  scanf("%d",&choix2);
	  getchar();
	  printf("\n");
      
	  switch(choix2)
	    {
	    case 1:
	      system(COMMAND);
	      add_vehi();
	      break;
	    case 2:
	      system(COMMAND);
	      del_vehi();
	      break;
	    case 3:
	      system(COMMAND);
	      add_client();
	      break;
	    case 4:
	      system(COMMAND);
	      modify_client();
	      break;
	    case 5:
	      system(COMMAND);
	      del_client();
	      break;
	    case 6:
	      system(COMMAND);
	      add_fact();
	      break;
	    case 7:
	      system(COMMAND);
	      del_fact();
	      break;
	    case 8:
	      system(COMMAND);
	      add_reserv();
	      break;
	    case 9:
	      system(COMMAND);
	      info_client();
	      break;
	    case 10:
	      system(COMMAND);
	      info_vehi();
	      printf("\n");
	      break;
	    case 11:
	      system(COMMAND);
	      info_reserv();
	      break;
	    case 12:
	      system(COMMAND);
	      info_fact();
	      break;
	    case 13:
	      system(COMMAND);
	      del_reserv();
	      break;
	    case 14:
	      verf=0;
	      choix1=0;
	      system(COMMAND);
	      break;
	    }
	}
      else
	choix1=0;
      break;
    case 3:
      printf("*---> Clients:\n");
      printf("\t1.Mes factures\n\t2.Informations sur un vehicule\n\t3.Liste des vehicules disponibles\n\t4.Retour\n\tChoix:");
      scanf("%d",&choix2);
      getchar();

      switch(choix2)
	{
	case 1:
	  system(COMMAND);
	  show_clientfact();
	  printf("\n");
	  break;
	case 2:
	  system(COMMAND);
	  show_clientvehi();
	  break;
	case 3:
	  system(COMMAND);
	  info_vehi();
	  break;
	case 4:
	  system(COMMAND);
	  choix1=0;
	  break;
	}
      break;
    case 4:
      *bool=0;
      break;
    }
}

int main()
{
  int bool=1;
  
  while(bool)
    {
      menu(&bool);
    }
  
  return 0;
}

void add_vehi()
{
  int i,choix;
  vehicule voiture;

  printf("Combien de vehicule voulez ajouter:\n");
  scanf("%d",&choix);
  getchar();

  for(i=0;i<choix;i++)
    {
      
      printf("Entrez la marque de la voiture:\n");
      fgets(voiture.marque,TAILLE,stdin);
      delRet(voiture.marque);

      printf("Entrez le kilometrage:\n");
      scanf("%lf",&voiture.kilometrage);
      getchar();

      printf("Entrez le type:\n");
      fgets(voiture.type,TAILLE,stdin);
      delRet(voiture.type);

      printf("Entrez le nombre limite de passagers:\n");
      scanf("%d",&voiture.volume);
      getchar();

      printf("Entrez le prix de location du vehicule:\n");
      scanf("%d",&voiture.prix_jour);
      getchar();

      save_vehi(voiture);
    }
}

void delRet(char *chaine)
{
  char *caract=NULL;
  caract=strchr(chaine,'\n');
  
  if(caract!=NULL)
    *caract='\0';
}

void save_vehi(vehicule voiture)
{
  FILE *file=NULL;

  file=fopen("vehi.dat","a");

  fprintf(file,"%s,%lf,%s,%d,%d\n",voiture.marque,voiture.kilometrage,voiture.type,voiture.volume,voiture.prix_jour);

  fclose(file);
}

void del_vehi()
{
  FILE *file=NULL,*tmp_file=NULL;
  vehicule voiture;
  char mark[TAILLE]="",chaine[TAILLE]="";
  int caract=0,bool=0,i;

  printf("Entrez la marque du vehicule à supprimer\n");
  fgets(mark,TAILLE,stdin);
  delRet(mark);

  file=fopen("vehi.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier vehi.dat n'existe pas ou n'a pas encore ete créer\n");
      exit(-1);
    }
  caract=fgetc(file);
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  voiture.marque[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.marque[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    chaine[i+1]='\0';
	}
      caract=fgetc(file);
      voiture.kilometrage=strtod(chaine,NULL);
      for(i=0;caract!=',';i++)
	{
	  voiture.type[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.type[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    chaine[i+1]='\0';
	}
      caract=fgetc(file);
      voiture.volume=strtol(chaine,NULL,10);
      for(i=0;caract!='\n';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    chaine[i+1]='\0';
	}
      voiture.prix_jour=strtol(chaine,NULL,10);
      if(strcmp(mark,voiture.marque)!=0) // Les chaines sont differentes
	tmp_vehi(voiture);
      else
	bool=1;
      caract=fgetc(file);
    }
  if(bool)
    {
      fclose(file);
      file=fopen("vehi.dat","w+"); // Ouvrir le fichier en le nettoyant au prealable
      tmp_file=fopen("tmp_vehi.dat","r"); // Ouvrir le fichier contenant les informations utiles
      if(tmp_file!=NULL)
	{
	  caract=fgetc(tmp_file);
	  while(caract!=EOF)
	    {
	      fputc(caract,file);
	      caract=fgetc(tmp_file);
	    }
	  fclose(tmp_file);
	  fclose(file);
	  remove("tmp_vehi.dat");
	  printf("La voiture de marque \"%s\" à bien été supprimer\n",mark);
	}
      else
	printf("La voiture de marque \"%s\" à bien été supprimer\n",mark);
    }
  else
    {
      printf("Aucune voiture de la marque \"%s\" n'a été trouvée\n",mark);
    }
}

vehicule *vehi_tab(int *taille)
{
  FILE *file=NULL;
  int caract=0,nbr=0,i,j;
  vehicule *voiture=NULL;
  char chaine[TAILLE]="";

  file=fopen("vehi.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier \"vehi.dat\" n'existe pas ou n'a pas encore ete créer\n");
      exit(-1);
    }
  
  caract=fgetc(file);
  while(caract!=EOF)
    {
      if(caract=='\n')
	nbr++;
      caract=fgetc(file);
    }
  voiture=calloc(nbr,sizeof(vehicule)); // Creation d'un tableau de taille nbr
  *taille=nbr;
  rewind(file);
  
  caract=fgetc(file);
  for(j=0;j<nbr;j++)
    {
      for(i=0;caract!=',';i++)
	{
	  voiture[j].marque[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture[j].marque[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    chaine[i+1]='\0';
	}
      caract=fgetc(file);
      voiture[j].kilometrage=strtod(chaine,NULL);
      for(i=0;caract!=',';i++)
	{
	  voiture[j].type[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture[j].type[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    chaine[i+1]='\0';
	}
      caract=fgetc(file);
      voiture[j].volume=strtol(chaine,NULL,10);
      for(i=0;caract!='\n';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    chaine[i+1]='\0';
	}
      voiture[j].prix_jour=strtol(chaine,NULL,10);
      caract=fgetc(file);
    }
  
  return voiture;
}

void show_vehi(vehicule *tab,int nbr)
{
  int i;
  
  printf("<--- MARQUES DE VEHICULES DISPONIBLES --->\n\n");
  for(i=0;i<nbr;i++)
    {
      printf("\t\t\"%s\"\n",tab[i].marque);
    }
}

void info_vehi()
{
  int taille=0;
  vehicule *tab=NULL;

  tab=vehi_tab(&taille);
  show_vehi(tab,taille);
}

void add_client()
{
  int nbr=0,i,bool=1;
  client cli;
  vehicule *tab=NULL;

  printf("*---> Ajout de clients:\n");
  printf("\tNom:");
  fgets(cli.nom,TAILLE,stdin);
  delRet(cli.nom);
  printf("\tPrenom:");
  fgets(cli.prenom,TAILLE,stdin);
  delRet(cli.prenom);
  printf("\tAdresse:");
  fgets(cli.adresse,TAILLE,stdin);
  delRet(cli.adresse);

  printf("\tMarque de vehicules disponibles:\n\n");
  tab=vehi_tab(&nbr);
  show_vehi(tab,nbr);
  printf("\n\tMarque du vehicule louer par le client:");
  fgets(cli.voiture,TAILLE,stdin);
  delRet(cli.voiture);

  for(i=0;i<nbr;i++)
    {
      if(!strcmp(cli.voiture,tab[i].marque))
	bool=0;
    }
  if(bool)
    printf("\n\t<*** La marque du vehicule entrée n'est pas repertoriée ***>\n");
  else
    {
     save_client(cli);
     printf("\n\t<*** Les informations du client ont bien été enregistrées ***>\n");
    }
}

void save_client(client cli)
{
  FILE *file=NULL;

  file=fopen("client.dat","a");
  if(!file)
    {
      fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
      exit(EXIT_FAILURE);
    }
  fprintf(file,"%s,%s,%s,%s\n",cli.nom,cli.prenom,cli.adresse,cli.voiture);

  fclose(file);
}

void del_client()
{
  FILE *file=NULL,*tmp_file=NULL;
  client cli;
  char nom[TAILLE]="",prenom[TAILLE]="";
  int caract=0,bool=0,i;
  
  printf("Entrez le nom du client à supprimer:");
  fgets(nom,TAILLE,stdin);
  delRet(nom);
  printf("Entrez le prenom du client à supprimer:");
  fgets(prenom,TAILLE,stdin);
  delRet(prenom);
  file=fopen("client.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier client.dat n'existe pas ou n'a pas encore ete créer\n");
      exit(-1);
    }
  caract=fgetc(file);
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  cli.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  cli.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  cli.adresse[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.adresse[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  cli.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    cli.voiture[i+1]='\0';
	}
      if(strcmp(nom,cli.nom)==0&&strcmp(prenom,cli.prenom)==0) // Les chaines sont differentes
	{
	  bool=1;
	}
      else
	tmp_client(cli);
      caract=fgetc(file);
    }
  if(bool)
    {
      fclose(file);
      file=fopen("client.dat","w+"); // Ouvrir le fichier en le nettoyant au prealable
      tmp_file=fopen("tmp_client.dat","r"); // Ouvrir le fichier contenant les informations utiles
      if(tmp_file!=NULL)
	{
	  caract=fgetc(tmp_file);
	  while(caract!=EOF)
	    {
	      fputc(caract,file);
	      caract=fgetc(tmp_file);
	    }
	  fclose(tmp_file);
	  fclose(file);
	  remove("tmp_client.dat");
	  printf("<*** Le client du nom de \"%s %s\" à bien été supprimer ***>\n",nom,prenom);
	}
      else
	printf("<*** Le client du nom de \"%s %s\" à bien été supprimer ***>\n",nom,prenom);
    }
  else
    {
      fclose(file);
      remove("tmp_client.dat");
      printf("<*** Aucun client du nom de \"%s %s\" n'a été trouvée ***>\n",nom,prenom);
    }
}

void modify_client()
{
  FILE *file=NULL,*tmp_file=NULL;
  client cli;
  char nom[TAILLE]="",prenom[TAILLE]="";
  int caract=0,bool=0,boolean=1,i,nbr;
  vehicule *tab=NULL;
 
  printf("Entrez le nom du client à modifié:");
  fgets(nom,TAILLE,stdin);
  delRet(nom);
  printf("Entrez le prenom du client à modifié:");
  fgets(prenom,TAILLE,stdin);
  delRet(prenom);
  file=fopen("client.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier client.dat n'existe pas ou n'a pas encore ete créer\n");
      exit(-1);
    }
  caract=fgetc(file);
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  cli.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  cli.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  cli.adresse[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.adresse[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  cli.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    cli.voiture[i+1]='\0';
	}
      if(strcmp(nom,cli.nom)==0&&strcmp(prenom,cli.prenom)==0) // Les chaines sont differentes
	{	  
	  printf("*---> Modification du client \"%s %s\":\n",nom,prenom);
	  printf("\tNom:");
	  fgets(cli.nom,TAILLE,stdin);
	  delRet(cli.nom);
	  printf("\tPrenom:");
	  fgets(cli.prenom,TAILLE,stdin);
	  delRet(cli.prenom);
	  printf("\tAdresse:");
	  fgets(cli.adresse,TAILLE,stdin);
	  delRet(cli.adresse);

	  printf("\tMarque de vehicules disponibles:\n\n");
	  tab=vehi_tab(&nbr);
	  show_vehi(tab,nbr);
	  printf("\n\tMarque du vehicule louer par le client:");
	  fgets(cli.voiture,TAILLE,stdin);
	  delRet(cli.voiture);

	  for(i=0;i<nbr;i++)
	    {
	      if(!strcmp(cli.voiture,tab[i].marque))
		boolean=0;
	    }
	  if(boolean)
	    printf("\n\t<*** La marque du vehicule entrée n'est pas repertoriée ***>\n");
	  bool=1;
	  tmp_client(cli);
	}
      else
	tmp_client(cli);
      caract=fgetc(file);
    }
  if(!bool)
    {
      fclose(file);
      remove("tmp_client.dat");
      printf("<*** Aucun client du nom de \"%s %s\" n'a été trouvée ***>\n",nom,prenom);
    }
  else
    {
      fclose(file);
      file=fopen("client.dat","w+"); // Ouvrir le fichier en le nettoyant au prealable
      tmp_file=fopen("tmp_client.dat","r"); // Ouvrir le fichier contenant les informations utiles
      if(tmp_file!=NULL)
	{
	  caract=fgetc(tmp_file);
	  while(caract!=EOF)
	    {
	      fputc(caract,file);
	      caract=fgetc(tmp_file);
	    }
	  fclose(tmp_file);
	  fclose(file);
	  remove("tmp_client.dat");
      
	  printf("\n\t<*** Les informations du client\"%s %s\" ont bien été modifiées ***>\n",nom,prenom);
	}
      else
	printf("\n\t<*** Les informations du client\"%s %s\" ont bien été modifiées ***>\n",nom,prenom);
    }
}

void show_client(client cli)
{
  printf("<--- INFORMATIONS CLIENTS --->");
  printf("\n\n");
  printf("\tNom: %s",cli.nom);
  printf("\n\tPrenom: %s",cli.prenom);
  printf("\n\tAdresse: %s",cli.adresse);
  printf("\n\tMarque de voiture louer: %s",cli.voiture);
  printf("\n\n");
}

void info_client()
{  
  FILE *file=NULL;
  client cli;
  int caract=0,i;

  file=fopen("client.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier client.dat n'existe pas ou n'a pas encore ete créer\n");
      exit(-1);
    }
  caract=fgetc(file);
  if(caract==EOF)
    printf("Il n'y a aucun client dans votre liste\n");
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  cli.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  cli.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  cli.adresse[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    cli.adresse[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  cli.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    cli.voiture[i+1]='\0';
	}
      show_client(cli);
      caract=fgetc(file);
    }
}

void tmp_vehi(vehicule voiture)
{
  FILE *file=NULL;

  file=fopen("tmp_vehi.dat","a");
  if(file==NULL)
    {
      fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
      exit(-1);
    }

  fprintf(file,"%s,%lf,%s,%d,%d\n",voiture.marque,voiture.kilometrage,voiture.type,voiture.volume,voiture.prix_jour);

  fclose(file);
}

void tmp_client(client cli)
{
  FILE *file=NULL;

  file=fopen("tmp_client.dat","a");
  if(file==NULL)
    {
      fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
      exit(-1);
    }

  fprintf(file,"%s,%s,%s,%s\n",cli.nom,cli.prenom,cli.adresse,cli.voiture);

  fclose(file);
}

void add_fact()
{
  int nbr,i;
  facture fact;
 
  printf("*---> Ajouter une facture:\n");
  printf("\tCombien de facture voulez vous enregistrer?:");
  scanf("%d",&nbr);
  getchar();
  for(i=0;i<nbr;i++)
    { 
      printf("\n\t<--- facture N°%d: --->",nbr+1);
      printf("\n\tNom du client:");
      fgets(fact.nom,TAILLE,stdin);
      delRet(fact.nom);
      printf("\n\tPrenom du client:");
      fgets(fact.prenom,TAILLE,stdin);
      delRet(fact.prenom);
      printf("\n\tVoiture louée:");
      fgets(fact.voiture,TAILLE,stdin);
      delRet(fact.voiture);
      printf("\n\tDate de location:");
      fgets(fact.date,TAILLE,stdin);
      delRet(fact.date);
      printf("\n\tSomme:");
      fgets(fact.somme,TAILLE,stdin);
      delRet(fact.somme);

      save_fact(fact);
    }
  printf("<--- FACTURE(S) ENREGISTREE AVEC SUCCESS --->\n\n");
}

void save_fact(facture fact)
{
  FILE *file=NULL;

  file=fopen("factures.dat","a");

  fprintf(file,"%s,%s,%s,%s,%s\n",fact.nom,fact.prenom,fact.voiture,fact.date,fact.somme);

  fclose(file);
}

void show_fact(facture fact)
{
  printf("*---> Liste des factures:");
  printf("\n");
  printf("\tNom: %s",fact.nom);
  printf("\n\tPrenom: %s",fact.prenom);
  printf("\n\tVoiture: %s",fact.voiture);
  printf("\n\tDate: %s",fact.date);
  printf("\n\tSomme: %s",fact.somme);
  printf("\n\n");
}

void info_fact()
{
  FILE *file=NULL;
  facture fact;
  int caract=0,i;

  file=fopen("factures.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier factures.dat n'existe pas ou a été supprimé\n");
      exit(-1);
    }
  caract=fgetc(file);
  if(caract==EOF)
    printf("Il n'y a aucune factures dans votre liste\n");
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  fact.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.voiture[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.date[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.date[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  fact.somme[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    fact.somme[i+1]='\0';
	}
      show_fact(fact);
      caract=fgetc(file);
    }
  fclose(file);
}

void tmp_fact(facture fact)
{  
  FILE *file=NULL;

  file=fopen("tmp_factures.dat","a");
  if(file==NULL)
    {
      fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
      exit(-1);
    }

  fprintf(file,"%s,%s,%s,%s,%s\n",fact.nom,fact.prenom,fact.voiture,fact.date,fact.somme);

  fclose(file);

}

void del_fact()
{
  FILE *file=NULL,*tmp_file=NULL;
  facture fact;
  char nom[TAILLE]="",prenom[TAILLE]="";
  int caract=0,bool=0,i;
 
  printf("Entrez le nom du client dont vous voulez supprimer la facture:");
  fgets(nom,TAILLE,stdin);
  delRet(nom);
  printf("Entrez son prenom:");
  fgets(prenom,TAILLE,stdin);
  delRet(prenom);
  file=fopen("factures.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier factures.dat n'existe pas ou a été supprimé\n");
      exit(-1);
    }
  caract=fgetc(file);
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  fact.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.voiture[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.date[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.date[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  fact.somme[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    fact.somme[i+1]='\0';
	} 
      if(strcmp(nom,fact.nom)==0&&strcmp(prenom,fact.prenom)==0) // Les chaines sont differentes
	{
	  bool=1;
	}
      else
	tmp_fact(fact);
      caract=fgetc(file);
    }
  if(bool)
    {
      fclose(file);
      file=fopen("factures.dat","w+"); // Ouvrir le fichier en le nettoyant au prealable
      tmp_file=fopen("tmp_factures.dat","r"); // Ouvrir le fichier contenant les informations utiles
      if(tmp_file!=NULL)
	{
	  caract=fgetc(tmp_file);
	  while(caract!=EOF)
	    {
	      fputc(caract,file);
	      caract=fgetc(tmp_file);
	    }
	  fclose(tmp_file);
	  fclose(file);
	  remove("tmp_factures.dat");
	  printf("<*** Les factures du client \"%s %s\" ont bien été supprimées ***>\n",nom,prenom);
	}
      else
	printf("<*** Les factures du client \"%s %s\" ont bien été supprimées ***>\n",nom,prenom);
    }
  else
    {
      fclose(file);
      remove("tmp_factures.dat");
      printf("<*** Aucune facture pour le client \"%s %s\" ***>\n",nom,prenom);
    } 
}

void add_reserv()
{ 
  int nbr,i;
  reserv voiture;
  
  printf("*---> Ajouter une reservation:\n");
  printf("\tCombien de reservation voulez vous enregistrer?:");
  scanf("%d",&nbr);
  getchar();
  for(i=0;i<nbr;i++)
    {      
      printf("\n\t<--- reservation N°%d: --->",nbr+1);
      printf("\n\tNom du client:");
      fgets(voiture.nom,TAILLE,stdin);
      delRet(voiture.nom);
      printf("\n\tPrenom du client:");
      fgets(voiture.prenom,TAILLE,stdin);
      delRet(voiture.prenom);
      printf("\n\tVoiture à reservée:");
      fgets(voiture.voiture,TAILLE,stdin);
      delRet(voiture.voiture);
      
      save_reserv(voiture);
    }
  printf("<--- RESERVATION(S) EFFECTUEE AVEC SUCCESS --->\n\n");
}

void save_reserv(reserv voiture)
{
  FILE *file=NULL;

  file=fopen("reservations.dat","a");

  fprintf(file,"%s,%s,%s\n",voiture.nom,voiture.prenom,voiture.voiture);

  fclose(file);
}

void show_reserv(reserv voiture)
{
  printf("*---> Liste des reservations:");
  printf("\n");
  printf("\tNom: %s",voiture.nom);
  printf("\n\tPrenom: %s",voiture.prenom);
  printf("\n\tVoiture reservé: %s",voiture.voiture);
  printf("\n\n");
}

void info_reserv()
{
  FILE *file=NULL;
  reserv voiture;
  int caract=0,i;

  file=fopen("reservations.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier reservations.dat n'existe pas ou a été supprimé\n");
      exit(-1);
    }
  caract=fgetc(file);
  if(caract==EOF)
    printf("Il n'y a aucune reservations dans votre liste\n");
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  voiture.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  voiture.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  voiture.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    voiture.voiture[i+1]='\0';
	}
      show_reserv(voiture);
      caract=fgetc(file);
    }
  fclose(file);
}

void tmp_reserv(reserv voiture)
{
  FILE *file=NULL;

  file=fopen("tmp_reservations.dat","a");
  if(file==NULL)
    {
      fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
      exit(-1);
    }

  fprintf(file,"%s,%s,%s\n",voiture.nom,voiture.prenom,voiture.voiture);

  fclose(file);
}

void del_reserv()
{
  FILE *file=NULL,*tmp_file=NULL;
  reserv voiture;
  char nom[TAILLE]="",prenom[TAILLE]="";
  int caract=0,bool=0,i;

  printf("Entrez le nom du client dont vous voulez supprimer la reservation:");
  fgets(nom,TAILLE,stdin);
  delRet(nom);
  printf("Entrez son prenom:");
  fgets(prenom,TAILLE,stdin);
  delRet(prenom);
  file=fopen("reservations.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier reservation.dat n'existe pas ou a été supprimé\n");
      exit(-1);
    }
  caract=fgetc(file);
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  voiture.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  voiture.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  voiture.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    voiture.voiture[i+1]='\0';
	}
      if(strcmp(nom,voiture.nom)==0&&strcmp(prenom,voiture.prenom)==0) // Les chaines sont differentes
	{
	  bool=1;
	}
      else
	tmp_reserv(voiture);
      caract=fgetc(file);
    }
  if(bool)
    {
      fclose(file);
      file=fopen("reservations.dat","w+"); // Ouvrir le fichier en le nettoyant au prealable
      tmp_file=fopen("tmp_reservations.dat","r"); // Ouvrir le fichier contenant les informations utiles
      if(tmp_file!=NULL)
	{
	  caract=fgetc(tmp_file);
	  while(caract!=EOF)
	    {
	      fputc(caract,file);
	      caract=fgetc(tmp_file);
	    }
	  fclose(tmp_file);
	  fclose(file);
	  remove("tmp_reservations.dat");
	  printf("<*** Les reservations du client \"%s %s\" ont bien été supprimées ***>\n",nom,prenom);
	}
      else
	printf("<*** Les reservations du client \"%s %s\" ont bien été supprimées ***>\n",nom,prenom);
    }
  else
    {
      fclose(file);
      remove("tmp_reservations.dat");
      printf("<*** Aucune reservation(s) pour le client \"%s %s\" ***>\n",nom,prenom);
    }
}

void show_clientfact()
{
  FILE *file=NULL;
  facture fact;
  int caract=0,i,bool=1;
  char nom[TAILLE]="",prenom[TAILLE]="";

  file=fopen("factures.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier factures.dat n'existe pas ou a été supprimé\n");
      exit(-1);
    }
  
  printf("\n*---> Informations sur les factures:");
  printf("\n\tEntrez votre nom:");
  fgets(nom,TAILLE,stdin);
  delRet(nom);
  printf("\n\tEntrez votre prenom:");
  fgets(prenom,TAILLE,stdin);
  delRet(prenom);
  
  caract=fgetc(file);
  if(caract==EOF)
    printf("Aucune facture n'a été enregistrer\n");
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  fact.nom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.nom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.prenom[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.prenom[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.voiture[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.voiture[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  fact.date[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    fact.date[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!='\n';i++)
	{
	  fact.somme[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    fact.somme[i+1]='\0';
	}
      if(strcmp(nom,fact.nom)==0&&strcmp(prenom,fact.prenom)==0)
	{
	 show_fact(fact);
	 bool=0;
	}
      caract=fgetc(file);
    }
  if(bool)
    printf("Il n'y a aucune de vos factures dans notre liste\n");
  
  fclose(file);
}

void show_clientvehi()
{ 
  FILE *file=NULL;
  vehicule voiture;
  char mark[TAILLE]="",chaine[TAILLE]="";
  int caract=0,bool=1,i;
  
  printf("*---> Informations vehicule:\n");
  printf("Entrez la marque du vehicule:");
  fgets(mark,TAILLE,stdin);
  delRet(mark);

  file=fopen("vehi.dat","r");
  if(file==NULL)
    {
      fprintf(stderr,"Le fichier vehi.dat n'existe pas ou a été supprimé\n");
      exit(-1);
    }
  caract=fgetc(file);
  
  while(caract!=EOF)
    {
      for(i=0;caract!=',';i++)
	{
	  voiture.marque[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.marque[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    chaine[i+1]='\0';
	}
      caract=fgetc(file);
      voiture.kilometrage=strtod(chaine,NULL);
      for(i=0;caract!=',';i++)
	{
	  voiture.type[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    voiture.type[i+1]='\0';
	}
      caract=fgetc(file);
      for(i=0;caract!=',';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract==',')
	    chaine[i+1]='\0';
	}
      caract=fgetc(file);
      voiture.volume=strtol(chaine,NULL,10);
      for(i=0;caract!='\n';i++)
	{
	  chaine[i]=caract;
	  caract=fgetc(file);
	  if(caract=='\n')
	    chaine[i+1]='\0';
	}
      voiture.prix_jour=strtol(chaine,NULL,10);
      if(strcmp(mark,voiture.marque)==0) // Les chaines sont differentes
	{
	  view_vehi(voiture);
	  bool=0;
	}
      caract=fgetc(file);
    }
  if(bool)
    printf("Il n'y aucun vehicule de la marque \"%s\" dans notre catalogue\n",mark);
}

void view_vehi(vehicule voiture)
{  
  printf("\n\tMarque: %s",voiture.marque);
  printf("\n\tkilométrage: %lf",voiture.kilometrage);
  printf("\n\tType de voiture: %s",voiture.type);
  printf("\n\tNombre de passagers: %d",voiture.volume);
  printf("\n\tPrix journalier de location: %d",voiture.prix_jour);
  printf("\n\n");
}

char *cryptage(char *password,int pas_char,int pas_int)
{
  int i;

  for(i=0;password[i]!='\0';i++)
    {
      if(password[i]<='Z'&&password[i]>='A')
	{
	  password[i]=password[i]+32+pas_char;
	  if(password[i]>'z')
	    {	      
	      password[i]='a'-1+password[i]-'z';
	    }
	}
      else if(password[i]<='z'&&password[i]>='a')
	{
	  password[i]=password[i]-32+pas_char;
	  if(password[i]>'Z')
	    {
	      password[i]='A'-1+password[i]-'Z';
     	    }
	}
      else if(password[i]<='9'&&password[i]>='0')
	{
	  password[i]=password[i]+pas_int;
	  if(password[i]>'9')
	    {
	      password[i]='0'-1+password[i]-'9';
	    }
	}
    }
  
  return password;
}

char *decrypt(char *password,int pas_char,int pas_int)
{
  int i;

  for(i=0;password[i]!='\0';i++)
    {
      if(password[i]<='Z'&&password[i]>='A')
	{
	  password[i]=password[i]+32-pas_char;
	  if(password[i]<'a')
	    {
	      password[i]='z'+1-('a'-password[i]);
	    }
	}
      else if(password[i]<='z'&&password[i]>='a')
	{
	  password[i]=password[i]-32-pas_char;
	  if(password[i]<'A')
	    {
	      password[i]='Z'+1-('A'-password[i]);
	    }
	}
      else if(password[i]<='9'&&password[i]>='0')
	{
	  password[i]=password[i]-pas_int;
	  if(password[i]<'0')
	    {
	      password[i]='9'+1-('0'-password[i]);
	    }
	}
    }
  
  return password;
}

void verf_passFile()
{
  char pass[TAILLE]="";
  FILE *file=NULL;

  file=fopen("passwd.dat","r");
  if(!file)
    {
      while(strlen(pass)<4)
	{
	  printf("Entrez un mot de passe pour protéger l'acces aux ressources du personnel(minimum 4 caractères):");
	  file=fopen("passwd.dat","w");
	  fgets(pass,TAILLE,stdin);
	  delRet(pass);
	  system(COMMAND);
	}
      fprintf(file,"%s\n",cryptage(pass,7,4));
    }
  fclose(file);
}

int verf_pass()
{
  int caract=0,i;
  char pass[TAILLE]="",hash[TAILLE]="";
  FILE *file=NULL;

  printf("Entrez le mot de passe:");
  fgets(pass,TAILLE,stdin);
  delRet(pass);

  file=fopen("passwd.dat","r");
  if(!file)
    {
      fprintf(stderr,"Erreur lors de manipulation du fichier de mot de passe\n");
      exit(-1);
    }
  caract=fgetc(file);
  i=0;
  if(caract==EOF)
    {
      remove("passwd.dat");
      verf_passFile();
    }
  while(caract!='\n')
    {
      hash[i]=caract;
      caract=fgetc(file);
      if(caract=='\n')
	hash[i+1]='\0';
      i++;
    }
  if(strcmp(decrypt(hash,7,4),pass)!=0)
    {
      printf("Attention le mot de passe entré est incorrecte!\n");

      fclose(file);
      return 0;
    }
  printf("\n<*** BIENVENUE !! ***>\n");

  fclose(file);
  return 1;
}
