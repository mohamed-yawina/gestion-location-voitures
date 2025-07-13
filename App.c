#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char marque[50];
    char matricule[20];
    float kilometrage;
    int disponibilite;
} Voiture;

typedef struct {
    char nom[50];
    char cin[20];
    char telephone[20];
    char matriculeVoiture[20];
    float avance;
    float prixAPayer;
} Client;

Voiture voitures[100];
int nbVoitures = 0;

Client clients[100];
int nbClients = 0;

void ajouterVoiture() {
    if (nbVoitures >= 100) {
        printf("Le parc de voitures est plein. Impossible d'ajouter une nouvelle voiture.\n");
        return;
    }

    Voiture nouvelleVoiture;

    printf("Marque: ");
    scanf("%s", nouvelleVoiture.marque);
    printf("Matricule: ");
    scanf("%s", nouvelleVoiture.matricule);
    printf("Kilometrage: ");
    scanf("%f", &nouvelleVoiture.kilometrage);
    printf("Disponibilite (0 = non disponible, 1 = disponible): ");
    scanf("%d", &nouvelleVoiture.disponibilite);

    voitures[nbVoitures++] = nouvelleVoiture;

    printf("La voiture a été ajoutée avec succès.\n");
}

void afficherVoiture() {
    char matricule[20];
    printf("Matricule de la voiture a afficher: ");
    scanf("%s", matricule);

    int i;
    for (i = 0; i < nbVoitures; i++) {
        if (strcmp(voitures[i].matricule, matricule) == 0) {
            printf("Marque: %s\n", voitures[i].marque);
            printf("Matricule: %s\n", voitures[i].matricule);
            printf("Kilometrage: %.2f\n", voitures[i].kilometrage);
            printf("Disponibilite: %s\n", voitures[i].disponibilite ? "Disponible" : "Non disponible");
            return;
        }
    }

    printf("Aucune voiture avec ce matricule n'a été trouvée.\n");
}

void modifierVoiture() {
    char matricule[20];
    printf("Matricule de la voiture à modifier: ");
    scanf("%s", matricule);

    int i;
    for (i = 0; i < nbVoitures; i++) {
        if (strcmp(voitures[i].matricule, matricule) == 0) {
            printf("Nouvelle marque: ");
            scanf("%s", voitures[i].marque);
            printf("Nouveau matricule: ");
            scanf("%s", voitures[i].matricule);
            printf("Nouveau kilometrage: ");
            scanf("%f", &voitures[i].kilometrage);
            printf("Nouvelle disponibilite (0 = non disponible, 1 = disponible): ");
            scanf("%d", &voitures[i].disponibilite);

            printf("Les informations de la voiture ont été modifiées avec succès.\n");
            return;
        }
    }

    printf("Aucune voiture avec ce matricule n'a été trouvée.\n");
}

void supprimerVoiture() {
    char matricule[20];
    printf("Matricule de la voiture à supprimer: ");
    scanf("%s", matricule);

    int i;
    for (i = 0; i < nbVoitures; i++) {
        if (strcmp(voitures[i].matricule, matricule) == 0) {
            int j;
            for (j = i; j < nbVoitures - 1; j++) {
                voitures[j] = voitures[j + 1];
            }
            nbVoitures--;

            printf("Les informations de la voiture ont été supprimées avec succès.\n");
            return;
        }
    }

    printf("Aucune voiture avec ce matricule n'a été trouvée.\n");
}

void ajouterClient() {
    if (nbClients >= 100) {
        printf("Le nombre maximum de clients a été atteint. Impossible d'ajouter un nouveau client.\n");
        return;
    }

    Client nouveauClient;

    printf("Nom: ");
    scanf("%s", nouveauClient.nom);
    printf("CIN: ");
    scanf("%s", nouveauClient.cin);
    printf("Telephone: ");
    scanf("%s", nouveauClient.telephone);
    printf("Matricule de la voiture désirée: ");
    scanf("%s", nouveauClient.matriculeVoiture);
    printf("Avance: ");
    scanf("%f", &nouveauClient.avance);
    printf("Prix à payer: ");
    scanf("%f", &nouveauClient.prixAPayer);

    clients[nbClients++] = nouveauClient;

    printf("Le client a été ajouté avec succès.\n");
}

void afficherClient() {
    char cin[20];
    printf("CIN du client à afficher: ");
    scanf("%s", cin);

    int i;
    for (i = 0; i < nbClients; i++) {
        if (strcmp(clients[i].cin, cin) == 0) {
            printf("Nom: %s\n", clients[i].nom);
            printf("CIN: %s\n", clients[i].cin);
            printf("Telephone: %s\n", clients[i].telephone);
            printf("Matricule de la voiture: %s\n", clients[i].matriculeVoiture);
            printf("Avance: %.2f\n", clients[i].avance);
            printf("Prix à payer: %.2f\n", clients[i].prixAPayer);
            return;
        }
    }

    printf("Aucun client avec ce CIN n'a été trouvé.\n");
}

void modifierClient() {
    char cin[20];
    printf("CIN du client à modifier: ");
    scanf("%s", cin);

    int i;
    for (i = 0; i < nbClients; i++) {
        if (strcmp(clients[i].cin, cin) == 0) {
            printf("Nouveau nom: ");
            scanf("%s", clients[i].nom);
            printf("Nouveau CIN: ");
            scanf("%s", clients[i].cin);
            printf("Nouveau téléphone: ");
            scanf("%s", clients[i].telephone);
            printf("Nouveau matricule de la voiture: ");
            scanf("%s", clients[i].matriculeVoiture);
            printf("Nouvelle avance: ");
            scanf("%f", &clients[i].avance);
            printf("Nouveau prix à payer: ");
            scanf("%f", &clients[i].prixAPayer);

            printf("Les informations du client ont été modifiées avec succès.\n");
            return;
        }
    }

    printf("Aucun client avec ce CIN n'a été trouvé.\n");
}

void supprimerClient() {
    char cin[20];
    printf("CIN du client à supprimer: ");
    scanf("%s", cin);

    int i;
    for (i = 0; i < nbClients; i++) {
        if (strcmp(clients[i].cin, cin) == 0) {
            int j;
            for (j = i; j < nbClients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            nbClients--;

            printf("Les informations du client ont été supprimées avec succès.\n");
            return;
        }
    }

    printf("Aucun client avec ce CIN n'a été trouvé.\n");
}

void afficherMenuPrincipal() {
    printf("----- Menu principal -----\n");
    printf("1. Gestion des voitures\n");
    printf("2. Gestion des clients\n");
    printf("3. Quitter\n");
    printf("Choix: ");
}

void afficherMenuVoitures() {
    printf("----- Gestion des voitures -----\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher une voiture\n");
    printf("3. Modifier une voiture\n");
    printf("4. Supprimer une voiture\n");
    printf("5. Retour au menu principal\n");
    printf("Choix: ");
}

void afficherMenuClients() {
    printf("----- Gestion des clients -----\n");
    printf("1. Ajouter un client\n");
    printf("2. Afficher un client\n");
    printf("3. Modifier un client\n");
    printf("4. Supprimer un client\n");
    printf("5. Retour au menu principal\n");
    printf("Choix: ");
}

int main() {
    int choixPrincipal = 0;

    while (choixPrincipal != 3) {
        afficherMenuPrincipal();
        scanf("%d", &choixPrincipal);

        switch (choixPrincipal) {
            case 1:
                // Gestion des voitures
                {
                    int choixVoitures = 0;
                    while (choixVoitures != 5) {
                        afficherMenuVoitures();
                        scanf("%d", &choixVoitures);

                        switch (choixVoitures) {
                            case 1:
                                ajouterVoiture();
                                break;
                            case 2:
                                afficherVoiture();
                                break;
                            case 3:
                                modifierVoiture();
                                break;
                            case 4:
                                supprimerVoiture();
                                break;
                            case 5:
                                break;
                            default:
                                printf("Choix invalide. Veuillez choisir une option valide.\n");
                        }
                    }
                }
                break;
            case 2:
                // Gestion des clients
                {
                    int choixClients = 0;
                    while (choixClients != 5) {
                        afficherMenuClients();
                        scanf("%d", &choixClients);

                        switch (choixClients) {
                            case 1:
                                ajouterClient();
                                break;
                            case 2:
                                afficherClient();
                                break;
                            case 3:
                                modifierClient();
                                break;
                            case 4:
                                supprimerClient();
                                break;
                            case 5:
                                break;
                            default:
                                printf("Choix invalide. Veuillez choisir une option valide.\n");
                        }
                    }
                }
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    }

    return 0;
}

