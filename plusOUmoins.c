#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#ifdef WIN32
    #define clear() system("cls")
#else
    #ifdef UNIX
        #define clear() system("clear")
    #else
 
        #ifndef NBLIGCLS
            #define NBLIGCLS 30
        #endif
        
void clear()
{
    int i;
    for(i = 0; i < NBLIGCLS; i++)
    {
        printf("\n");
    }
}
  #endif
#endif

void viderBuffer(void)
{
  int c;
  while((c=getchar()) != EOF && c != '\n');
}


void ft_more_less(int n)
{
    int nbre;
    const int nbreEssaisMax = 8;
    int nbreEssais = 0;
    int nbreEssaisRestant = nbreEssaisMax;

    while (++nbreEssais <= nbreEssaisMax)
    {
        printf("-----------------------\n");
        printf("quel est le nombre ? \n");
        scanf("%d", &nbre);
        printf("-----------------------\n");
        nbreEssaisRestant--;
        if (nbre == n)
        {
            printf("Bravo ! \n");
            return;
        }
        if (nbreEssais < nbreEssaisMax)
        {
            if (nbre < n)
                 printf("c'est plus !\n");
            else
                 printf("c'est moins !\n");
            printf("nombre d'essais restant : %d\n", nbreEssaisRestant);
        }
    }
    printf("Le nombre à trouver etait %d ! \n", n);
}

void onePlayer()
{
    clear();
    srand(time(NULL));
    int nombreMystere;
    int numDifficulte;
    int max;
    int min; 

    do
    {
        printf("Quelle difficultée (1, 2 ou 3)\n");
    scanf("%d", &numDifficulte);
        switch (numDifficulte)
        {
        case 1:
            min = 1;
            max = 100;
            break;
        case 2:
            min = 1;
            max = 1000;
            break;
        case 3:
            min = 1;
            max = 10000;
            break;
        default:
            printf("Erreur de frappe\n");
            break;
    }
    }while (numDifficulte < 1 || numDifficulte > 3);
    
    nombreMystere = (rand() % (max - min + 1)) + min;
    ft_more_less(nombreMystere); 
}

void twoPlayer()
{
    clear();
    int nombreMystere;
    int numeroJoueur = 1;

    while (numeroJoueur <=2)
    {
        printf("Joueur %d : entrez un nombre mystère\n",numeroJoueur);
        viderBuffer();
        scanf("%d", &nombreMystere);
        clear();
        ft_more_less(nombreMystere);
        numeroJoueur++; 
    }
}

void menu(void)
{
    int nbreJoueur = 0;
    char continuerPartie = 111;

    while (continuerPartie==111) {
    clear();
    printf("-----------------------\n");
    printf("nombre de joueur ? (1 ou 2) \n");
    scanf("%d",&nbreJoueur);
    while (nbreJoueur != 1 && nbreJoueur != 2)
        {   
            printf("Erreur de frappe !\n");
            printf("nombre de joueur ? (1 ou 2) \n");
            viderBuffer();
            scanf("%d", &nbreJoueur);   
        }
    if (nbreJoueur == 1)
        onePlayer();
    else
        twoPlayer();
    viderBuffer();
    printf("Souhaitez-vous continuer ? (o/n)\n");
    scanf("%c", &continuerPartie);
    while (continuerPartie != 111 && continuerPartie != 110)
        {   
            printf("Erreur de frappe !\n");
            printf("souhaitez-vous continuer ? (o/n)\n");
            viderBuffer();
            scanf("%c", &continuerPartie);   
        }
        viderBuffer();
    }
}

int main()
{
    menu();
    return 0;
}