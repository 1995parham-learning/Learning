/*
 * In The Name Of God
 * ========================================
 * [] File Name : saisir.c
 *
 * [] Creation Date : 16-02-2015
 *
 * [] Last Modified : Mon 16 Feb 2015 03:20:15 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct emp {
	char nom[20];
	char prenom[20];
	int age;
	float salaire;
};

struct emp *tab;
int  n = 0;
int *p = &n;

/* Fonction de saisie :   */
struct emp *saisir(struct emp *t, int *m)
{
	int i, s;

	printf("\n  Donner le nombre des struct employes a ajouter : ");
	scanf("%d", &s);

	t = malloc(s * sizeof(struct emp));

	for (i = *m; i < *m + s; i++) {
		printf("\n\n\n donner les info de %d eme struct employe\n", i + 1);
		printf("\n le nom : ");
		scanf("%s", (t + i)->nom);
		printf("\n le prenom : ");
		scanf("%s", (t + i)->prenom);
		printf("\n l \' age  : ");
		scanf("%d", &(t + i)->age);
		printf("\n le salaire : ");
		scanf("%f", &(t + i)->salaire);
	}
	*m = *m + s;
	return t;
}

/* Fonction d'affichage :   */
void afficher(struct emp *t, int *m)
{
	int i;

	if (*m == 0)
		printf("\n\n\n Liste vide !!");
	else
		for (i = 0; i < *m; i++) {
			printf("\n les information du %d eme struct employe :", i + 1);
			printf("\n \t Nom     :%s", (t + i)->nom);
			printf("\n \t Prenom  :%s", (t + i)->prenom);
			printf("\n \t Age     :%d", (t + i)->age);
			printf("\n \t Salaire :%.2f", (t + i)->salaire);
		}
}

/* Fonction de recherche :   */
int chercher(struct emp *t, int *m)
{
	int i, posi = -1;
	char cher[20];

	printf("\n\n\n Donner moi le nom a chercher :\n\n ");
	scanf("%s", cher);
	for (i = 0; i < *m; i++) {
		if (strcmp((t+i)->nom, cher) == 0) {
			posi = i;
			break;
		}
	}
	if (posi == -1) {
		printf("\n\n\n le nom n\'existe pas parmi les struct employes  !!!");
	} else {
		printf("\n \t L\' struct employe ayant le nom %s existe et voici ces informations :  ",
				cher);
		printf("\n \t Nom     :%s", (t + posi)->nom);
		printf("\n \t Prenom  :%s", (t + posi)->prenom);
		printf("\n \t Age     :%d", (t + posi)->age);
		printf("\n \t Salaire :%.2f", (t + posi)->salaire);
	}
	return posi;
}

/* Fonction de suppression :   */
void supprimer(struct emp *t, int *m)
{
	int i, pos;

	pos = chercher(t, m);
	if (pos != -1) {
		for (i = pos; i < *m; i++)
			*(t + i) = *(t + (i + 1));
		(*m)--;
		printf("\n\n\n struct employe supprime avec succes !!!");
	}

}

/* Fonction de triage par Nom  :   */
void trier_nom(struct emp *t, int *m)
{
	int i, j;
	struct emp temp;

	for (i = 0; i < *m - 1; i++) {
		for (j = i + 1; j < *m; j++) {
			if (strcmp((t + i)->nom, (t + j)->nom) > 0) {
				temp = *(t + i);
				*(t + i) = *(t + j);
				*(t + j) = temp;
			}
		}
	}
	printf("\n\n\n Tri par nom effectue avec succes !!!");
}

/* Fonction de triage par Age  :   */
void trier_age(struct emp *t, int *m)
{
	int i, j;
	struct emp temp;

	for (i = 0; i < *m - 1; i++) {
		for (j = i + 1; j < *m; j++) {
			if ((t + i)->age > (t + j)->age) {
				temp = *(t + i);
				*(t + i) = *(t + j);
				*(t + j) = temp;
			 }
		 }
	}
	printf("\n\n\n Tri par age effectue avec succes !!!");
}

int main(int argc, char *argv[])
{
	char test;

	do {
		printf("\n  ###        Bienvenu dans votre programme   ###");
		printf("\n  #       Pour Saisir appuyer sur      S   #");
		printf("\n  #       Pour Afficher appuyer sur    A   #");
		printf("\n  #       Pour Chercher appuyer sur    C   #");
		printf("\n  #       Pour Supprimer appuyer sur   D   #");
		printf("\n  #       Pour Trier par nom  appuyer sur  N   #");
		printf("\n  #       Pour Trier par age appuyer sur   G   #");
		printf("\n  #       Pour Quitter appuyer sur     Q   #");
		printf("\n  ##############################################\n\n\n");
		test = getchar();
		getchar();
		switch (test) {
		case 'S':
			tab = saisir(tab, p);
			break;
		case 'A':
			afficher(tab, p);
			break;
		case 'C':
			chercher(tab, p);
			break;
		case 'D':
			supprimer(tab, p);
			break;
		case 'N':
			trier_nom(tab, p);
			break;
		case 'G':
			trier_age(tab, p);
			break;
		case 'Q':
			printf("\n Merci pour votre visite");
			break;
		default:
			printf("\n\n\n\n\n choix errone ! verifier que les lettres en majuscule  !!");
		}
		printf("\n\n\n\n Appuyer sur une touche pour continuer !");
		getchar();
		system("clear");      /* Efface l'écran    */
	} while (test != 'Q');
}


