#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuChoix(){
    printf("1: Verificateur password\n");
    printf("2: Compteur de caracteres\n");
    printf("3: Voir si mon password est dans une liste fuiter\n");
    printf("4: Quitter\n");
}

void verificateurPassword(){
    char *password = calloc(100, sizeof(char));
    if (password == NULL)
    {
        printf("ERREUR: Allocation Dynamique password\n");
        return;
    }
    printf("Password : ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';

    int len = strlen(password);
    int compteurLettre = 0;
    int majuscules = 0;
    int minuscules = 0;
    int chiffre = 0;
    int speciale = 0;

    for (int i = 0; i < len; i++)
    {
        compteurLettre++;
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            majuscules ++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            minuscules++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            chiffre++;
        }
        else
        {
            speciale++;
        }  
    }
    printf("Ton password contient : \n");
    printf("%d lettres\n", compteurLettre);
    printf("%d Majuscules\n", majuscules);
    printf("%d minuscules\n", minuscules);
    printf("%d chiffres\n", chiffre);
    printf("%d caracteres speciaux\n", speciale);

    if (compteurLettre >= 12 && majuscules >= 1 && chiffre >= 2 && speciale >1)
        {
            printf("Ton password et fort\n");
        }
        else
        {
            printf("Ton password n'est pas assez fort");
        }
        free(password);
}

void compteurCaracteres(){
    char *phrase = calloc(400, sizeof(char));
    if (phrase == NULL)
    {
        printf("ERREUR: Allocation Dynamique de la phrase\n");
        return;
    }

    printf("Entre ta saisie : ");
    fgets(phrase, 400, stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    int len = strlen(phrase);
    int caracteres = 0;
    for (int i = 0; i < len; i++)
    {
        if (phrase[i] >= 'a' && phrase[i] <= 'z')
        {
            caracteres++;
        }
    }
    printf("Il y a %d caracteres dans ta saisie\n", caracteres);
    
    free(phrase); 
}

void passwordFuiter(){
    char *password = calloc(100, sizeof(char));
    if (password == NULL)
    {
        printf("ERREUR: Allocatio Dynamique de password\n");
        return;
    }

    printf("password : ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';


    char *informationFichier = calloc(50, sizeof(char));
    if (informationFichier == NULL)
    {
        free(password);
        printf("ERREUR: Allocation Dynamique de informationFichier\n");
        return;
    }
    int trouve = 0;
    FILE *fichier = fopen("100k-passwords-NCSC.txt", "r");
    if (fichier == NULL)
    {
        free(password);
        free(informationFichier);
        printf("Fichier introuvable\n");
        return;
    }
    
    while (fgets(informationFichier, 50, fichier) != NULL)
    {
        informationFichier[strcspn(informationFichier, "\n")] = '\0';

        if (strcmp(password, informationFichier) == 0)
        {
            trouve = 1;
            printf("Password sur liste\n");
            break;
        }
    }
    if (trouve == 0)
    {
        printf("Password pas sur liste\n");
    }
    fclose(fichier);

free(password);
free(informationFichier);
}

int main(){
    int choixMenu = 0;

    do
    {
        menuChoix();
        printf(">");
        scanf("%d", &choixMenu);
        getchar();

        if (choixMenu == 1)
        {
            verificateurPassword();
        }
        else if (choixMenu == 2)
        {
            compteurCaracteres();
        }
        else if (choixMenu == 3)
        {
            passwordFuiter();
        }
        
        else if (choixMenu == 4)
        {
            printf("Au Revoir\n");
            break;
        }
        else
        {
            printf("Saisie inconue\n");
        }
    } while (choixMenu != 4);
    
    return 0;
}