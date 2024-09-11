#include <stdio.h>
#include <string.h>

int choix;
char T1[100][100], T2[100][100], T3[100][100];
int I1[100], I2[100], I3[100], NG[100];
int count = 0;

void supprimer()
{

    if (count > 0)
    {
        printf("\n\n+-----------------------------------------------+\n");
        printf("|          Suppression d'un etudiant            |\n");
        printf("+-----------------------------------------------+\n");

        int n;
        printf("Saisir le numero de l'eleve a supprimer: ");
        scanf("%d", &n);
        if (n > 0)
        {
            for (int i = n - 1; i < count; i++)
            {
                I1[i] = I1[i + 1];
                I2[i] = I2[i + 1];
                I3[i] = I3[i + 1];
                NG[i] = NG[i + 1];
                strcpy(T1[i], T1[i + 1]);
                strcpy(T2[i], T2[i + 1]);
                strcpy(T3[i], T3[i + 1]);
            }
            count--;

            printf("L'etudiant a bien ete supprimer !");
        }
    }
    else

        printf("La liste est vide !");
}

void Afficher()
{

    if (count > 0)
    {
        int ch2;

        printf("\n\n+-----------------------------------------------+\n");
        printf("|            Affichage des etudiants            |\n");
        printf("+-----------------------------------------------+\n");

        printf("1. Afficher tous les etudiants sans filtre\n");
        printf("2. Afficher tous les etudiants par Ordre alphabetique\n");
        printf("3. Afficher tous les etudiants par la moyenne generale\n");
        printf("4. Afficher tous les etudiants selon le statut de reussite\n");
        printf("5. Retour\n");
        printf("==> ");
        scanf("%d", &ch2);
        getchar();

        switch (ch2)
        {
        case 1:
            for (int i = 0; i < count; i++)
            {
                printf("Nom: %s\n", T1[i]);
                printf("Prenom: %s\n", T2[i]);
                printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                printf("Departement: %s\n", T3[i]);
                printf("Note generale: %d\n", NG[i]);
                printf("\n");
            }
        case 2:
            int ch3;

            printf("↳  1. Par ordre alphabetique de A a Z\n");
            printf("   2. Par ordre alphabetique de Z a A\n");

            printf("==> ");
            scanf("%d", &ch3);
            getchar();

            if (ch3 == 1)
            {
                char temp[100];
                int j;
                for (int i = 0; i < count - 1; i++)
                {
                    for (j = i + 1; j < count; j++)
                    {
                        if (strcmp(T1[i], T1[j]) > 0)
                        {
                            strcpy(temp, T1[i]);
                            strcpy(T1[i], T1[j]);
                            strcpy(T1[j], temp);

                            strcpy(temp, T2[i]);
                            strcpy(T2[i], T2[j]);
                            strcpy(T2[j], temp);

                            int aux = I1[i];
                            I1[i] = I1[j];
                            I1[j] = aux;

                            aux = I2[i];
                            I2[i] = I2[j];
                            I2[j] = aux;

                            aux = I3[i];
                            I3[i] = I3[j];
                            I3[j] = aux;

                            aux = NG[i];
                            NG[i] = NG[j];
                            NG[j] = aux;

                            strcpy(temp, T3[i]);
                            strcpy(T3[i], T3[j]);
                            strcpy(T3[j], temp);
                        }
                    }

                    printf("\n");

                    for (int i = 0; i < count; i++)
                    {
                        printf("Nom: %s\n", T1[i]);
                        printf("Prenom: %s\n", T2[i]);
                        printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                        printf("Departement: %s\n", T3[i]);
                        printf("Note generale: %d\n", NG[i]);
                        printf("\n");
                    }
                }
            }

            else if (ch3 == 2)
            {
                char temp[100];
                for (int i = 0; i < count - 1; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (strcmp(T1[i], T1[j]) < 0)
                        {
                            char temp[100];
                            strcpy(temp, T1[i]);
                            strcpy(T1[i], T1[j]);
                            strcpy(T1[j], temp);

                            strcpy(temp, T2[i]);
                            strcpy(T2[i], T2[j]);
                            strcpy(T2[j], temp);

                            int aux = I1[i];
                            I1[i] = I1[j];
                            I1[j] = aux;

                            aux = I2[i];
                            I2[i] = I2[j];
                            I2[j] = aux;

                            aux = I3[i];
                            I3[i] = I3[j];
                            I3[j] = aux;

                            aux = NG[i];
                            NG[i] = NG[j];
                            NG[j] = aux;

                            strcpy(temp, T3[i]);
                            strcpy(T3[i], T3[j]);
                            strcpy(T3[j], temp);
                        }
                    }
                }

                printf("\n");

                for (int i = 0; i < count; i++)
                {
                    printf("Nom: %s\n", T1[i]);
                    printf("Prenom: %s\n", T2[i]);
                    printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                    printf("Departement: %s\n", T3[i]);
                    printf("Note generale: %d\n", NG[i]);
                    printf("\n");
                }
            }

            break;
        case 3:

            int ch4;

            printf("↳  1. Par La moyenne generale croissante\n");
            printf("   2. Par La moyenne generale decroissante\n");

            printf("==> ");
            scanf("%d", &ch4);
            getchar();

            if (ch4 == 1)
            {

                char temp[100];
                for (int i = 0; i < count - 1; i++)
                    for (int j = i + 1; j < count; j++)
                        if (NG[i] > NG[j])
                        {
                            int aux;
                            aux = I1[i];
                            I1[i] = I1[j];
                            I1[j] = aux;

                            aux = I2[i];
                            I2[i] = I2[j];
                            I2[j] = aux;

                            aux = I3[i];
                            I3[i] = I3[j];
                            I3[j] = aux;

                            aux = NG[i];
                            NG[i] = NG[j];
                            NG[j] = aux;

                            strcpy(temp, T3[i]);
                            strcpy(T3[i], T3[j]);
                            strcpy(T3[j], temp);

                            strcpy(temp, T1[i]);
                            strcpy(T1[i], T1[j]);
                            strcpy(T1[j], temp);

                            strcpy(temp, T2[i]);
                            strcpy(T2[i], T2[j]);
                            strcpy(T2[j], temp);
                        }

                printf("\n");

                for (int i = 0; i < count; i++)
                {
                    printf("Nom: %s\n", T1[i]);
                    printf("Prenom: %s\n", T2[i]);
                    printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                    printf("Departement: %s\n", T3[i]);
                    printf("Note generale: %d\n", NG[i]);
                    printf("\n");
                }
            }

            else if (ch4 == 2)
            {

                for (int i = 0; i < count - 1; i++)
                {
                    int j;
                    for (j = i + 1; j < count; j++)
                    {
                        if (NG[i] < NG[j])
                        {
                            int aux;
                            aux = I1[i];
                            I1[i] = I1[j];
                            I1[j] = aux;

                            aux = I2[i];
                            I2[i] = I2[j];
                            I2[j] = aux;

                            aux = I3[i];
                            I3[i] = I3[j];
                            I3[j] = aux;

                            aux = NG[i];
                            NG[i] = NG[j];
                            NG[j] = aux;

                            char temp[100];
                            strcpy(temp, T1[i]);
                            strcpy(T1[i], T1[j]);
                            strcpy(T1[j], temp);

                            strcpy(temp, T2[i]);
                            strcpy(T2[i], T2[j]);
                            strcpy(T2[j], temp);

                            strcpy(temp, T3[i]);
                            strcpy(T3[i], T3[j]);
                            strcpy(T3[j], temp);
                        }
                    }
                }
            }

            printf("\n");

            for (int i = 0; i < count; i++)
            {
                printf("Nom: %s\n", T1[i]);
                printf("Prenom: %s\n", T2[i]);
                printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                printf("Departement: %s\n", T3[i]);
                printf("Note generale: %d\n", NG[i]);
                printf("\n");
            }

            break;
        case 4:

            int tresbien = 0, bien = 0, assbien = 0, passable = 0;
            for (int i = 0; i < count; i++)
            {
                if (NG[i] >= 16)
                {
                    printf(" Nom: %s, Trie bien\n", T1[i]);
                    tresbien++;
                }

                else if (NG[i] >= 14)
                {
                    printf("Nom: %s\n, Bien", T1[i]);
                    bien++;
                }

                else if (NG[i] >= 12)
                {
                    printf("Nom: %s\n, Assez bien", T1[i]);
                    assbien++;
                }

                else if (NG[i] >= 10)
                {
                    printf("Nom: %s\nPassable", T1[i]);
                    passable++;
                }
            }

            printf("\n");
            printf("Resultat : \n");
            printf("Tres bien: %d\n", tresbien);
            printf("Bien: %d\n", bien);
            printf("Assez bien: %d\n", assbien);
            printf("Passable: %d\n", passable);
            printf("\n\n");

            break;
        case 5:

            break;
        }
    }
    else

        printf("La liste est vide !");
}

void moyennegen()
{

    int sum = 0;
    float moyenne;
    for (int i = 0; i < count; i++)
    {
        sum += NG[i];
    }
    moyenne = (float)sum / count;
    printf("La moyenne generale de l'universite est : %.2f\n", moyenne);
}

void Statistiques()
{
    int nbDepart[100] = {0}, nbReussite[100] = {0};
    int max[3] = {0, 0, 0}, indMax[3] = {0, 0, 0};
    float seuil;
    printf("\n\n+-----------------------------------------------+\n");
    printf("|           Statistiques de l'universite        |\n");
    printf("+-----------------------------------------------+\n");

    printf("Nombre total d'etudiants : %d\n", count);

    for (int i = 0; i < count; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (strcmp(T3[i], T3[j]) == 0)
                break;
        if (j == i)
            nbDepart[i] = 1;
        else
            nbDepart[j]++;
    }
    for (int i = 0; i < count; i++)
        if (nbDepart[i] > 0)
            printf("Nombre d'etudiants dans le departement %s : %d\n", T3[i], nbDepart[i]);

    printf("Saisir le seuil de moyenne generale : ");
    scanf("%f", &seuil);
    int nbsup = 0;
    for (int i = 0; i < count; i++)
        if (NG[i] > seuil)
        {
            nbsup++;
            printf("Etudiant %s %s a une moyenne generale de %d\n", T1[i], T2[i], NG[i]);
        }
    printf("Nombre d'etudiants ayant une moyenne generale superieure a %.2f : %d\n", seuil, nbsup);

    for (int i = 0; i < count; i++)
        for (int j = 0; j < 3; j++)
            if (NG[i] > max[j])
            {
                for (int k = 2; k > j; k--)
                {
                    max[k] = max[k - 1];
                    indMax[k] = indMax[k - 1];
                }
                max[j] = NG[i];
                indMax[j] = i;
                break;
            }
    for (int i = 0; i < count; i++)
        printf("Etudiant %s %s a une moyenne generale de %d\n", T1[indMax[i]], T2[indMax[i]], max[i]);

    for (int i = 0; i < count; i++)
        if (NG[i] >= 10)
            nbReussite[i]++;
    for (int i = 0; i < count; i++)
        if (nbReussite[i] > 0)
        {
            printf("Nombre d'etudiants ayant reussi dans le departement %s : %d\n", T3[i], nbReussite[i]);
        }
}

void recherche()
{
    int rech;
    char nom[100];
    printf("Rechercher un etudiant par:\n  1. Son nom\n  2. Son departement\n");
    printf("==> ");
    scanf("%d", &rech);
    getchar();
    if (rech == 1)
    {
        printf("Saisir le nom de l'etudiant: ");
        scanf("%[^\n]", nom);
        getchar();
        for (int i = 0; i < count; i++)
            if (strcmp(T1[i], nom) == 0)
            {
                printf("Nom: %s\n", T1[i]);
                printf("Prenom: %s\n", T2[i]);
                printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                printf("Departement: %s\n", T3[i]);
                printf("Note generale: %d\n", NG[i]);
                return;
            }
    }
    else if (rech == 2)
    {
        char depart[100];
        printf("Saisir le departement: ");
        scanf("%[^\n]", depart);
        getchar();
        for (int i = 0; i < count; i++)
            if (strcmp(T3[i], depart) == 0)
            {
                printf("Nom: %s\n", T1[i]);
                printf("Prenom: %s\n", T2[i]);
                printf("Date de naissance: %d-%d-%d\n", I1[i], I2[i], I3[i]);
                printf("Departement: %s\n", T3[i]);
                printf("Note generale: %d\n", NG[i]);
            }
    }
    else
        printf("Erreur de saisie !");
}

int main()
{

    while (1)
    {
        printf("+-----------------------------------------------+\n");
        printf("|   Gestion des Etudiants dans une Université   |\n");
        printf("+-----------------------------------------------+\n");
        printf("| 1. Ajouter un étudiant                        |\n");
        printf("| 2. Modifier un étudiant                       |\n");
        printf("| 3. Supprimer un étudiant                      |\n");
        printf("| 4. Afficher un étudiant                       |\n");
        printf("| 5. Calculer la moyenne générale               |\n");
        printf("| 6. Statistiques                               |\n");
        printf("| 7. Rechercher un étudiant                     |\n");
        printf("| 8. Quitter                                    |\n");
        printf("+-----------------------------------------------+\n");
        printf("Entrez votre choix : ");

        scanf("%d", &choix);
        getchar();

        if (choix < 0)
        {
            printf("On dirait que vous essayez de voyager dans le passe ! Malheureusement, notre menu ne supporte que le futur.");
            return 0;
        }

        switch (choix)
        {
        case 1:

            printf("\n\n+-----------------------------------------------+\n");
            printf("|             Ajouter un etudiant               |\n");
            printf("+-----------------------------------------------+\n");

            for (int i = count; i < count + 1; i++)
            {
                printf("N.unique de l'etudiant: %d\n", i + 1);

                printf("Le nom de l'etudiant: ");
                scanf("%[^\n]", &T1[i]);
                getchar();

                printf("Le prenom de l'etudiant: ");
                scanf("%[^\n]", &T2[i]);
                getchar();

                printf("La date de naissance de l'etudiant: \n");
                printf("↳  le jour : ");
                scanf("%d", &I1[i]);
                getchar();
                printf("   le mois : ");
                scanf("%d", &I2[i]);
                getchar();
                printf("   l'annee : ");
                scanf("%d", &I3[i]);
                getchar();

                printf("Le departement de l'etudiant: ");
                scanf("%[^\n]", &T3[i]);
                getchar();

                printf("La note generale de l'etudiant: ");
                scanf("%d", &NG[i]);
                getchar();

                if (NG[i] < 0 || NG[i] > 20)
                {
                    printf("La note generale doit etre un nombre entre 0 et 20, ni plus ni moins..\n");
                    return 0;
                }

                if (I1[i] < 1 || I1[i] > 31)
                {
                    printf("meme les calendriers ont des limites ! \nChoisissez un nombre entre 1 et 31.\n");
                    return 0;
                }

                if (I2[i] < 1 || I2[i] > 12)
                {
                    printf("Ce mois semble venir d'une autre galaxie ! \nChoisissez un nombre entre 1 et 12.");
                    return 0;
                }

                if (I3[i] < 1990 || I3[i] > 2006)
                {
                    printf("Les annees 1990 à 2006 sont les seules annees disponibles ici. \nEssayez une annee dans cette plage");
                    return 0;
                }
            }

            count++;

            break;
        case 2:

            int modifier;

            printf("\n\n+-----------------------------------------------+\n");
            printf("|             Modifier un etudiant              |\n");
            printf("+-----------------------------------------------+\n");

            if (count == 0)
            {

                printf("Il n'y a aucun etudiant dans la base de donnée.");
            }

            else
            {

                printf("N.unique de l'etudiant: ");
                scanf("%d", &modifier);
                getchar();

                int un = modifier - 1;

                printf("Le nom de l'etudiant: ");
                scanf("%[^\n]", &T1[un]);
                getchar();

                printf("Le prenom de l'etudiant: ");
                scanf("%[^\n]", &T2[un]);
                getchar();

                printf("La date de naissance de l'etudiant: ");
                printf("le jour : ");
                scanf("%d", &I1[un]);
                getchar();
                printf("le mois : ");
                scanf("%d", &I2[un]);
                getchar();
                printf("l'annee : ");
                scanf("%d", &I3[un]);
                getchar();

                printf("Le departement de l'etudiant: ");
                scanf("%[^\n]", &T3[un]);
                getchar();

                printf("La note generale de l'etudiant: ");
                scanf("%d", &NG[un]);
            }

            break;
        case 3:
            supprimer();
            break;
        case 4:
            Afficher();
            break;
        case 5:
            moyennegen();
            break;
        case 6:
            Statistiques();
            break;
        case 7:
            recherche();
            break;
        case 8:
            printf("Merci d'avoir utiliser notre application\n");
            printf("Au revoir");
            return 0;
            break;
        default:
            printf("Choix invalide");
            break;
        }
    }
}