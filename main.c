#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    float seuil_min, seuil_max;
    int nb_mesures;
    int alerte = 0;

    // Variables for Step 4 stats
    float somme_temp = 0;
    float temp_min = 100.0;
    float temp_max = -100.0;

    printf("Minimum safe temperature = ");
    scanf("%f", &seuil_min);

    printf("Maximum safe temperature = ");
    scanf("%f", &seuil_max);

    printf("Nombre de mesures = ");
    scanf("%d", &nb_mesures);

    for (int i = 0; i < nb_mesures; i++) {
        float temp = 10 + (rand() % 36);
        printf("\nMesure %d : %.1f C -> ", i + 1, temp);

        // Update statistics
        somme_temp += temp;
        if (temp < temp_min) temp_min = temp;
        if (temp > temp_max) temp_max = temp;

        // 3-Level Alert Engine
        if (temp >= seuil_min && temp <= seuil_max) {
            printf("[OK]");
            alerte = 0;
        } else if (temp >= seuil_min - 3 && temp <= seuil_max + 3) {
            printf("[NIVEAU 1: Avertissement]");
            alerte++;
        } else if (temp >= seuil_min - 7 && temp <= seuil_max + 7) {
            printf("[NIVEAU 2: Alerte Moderee]");
            alerte++;
        } else {
            printf("[NIVEAU 3: DANGER CRITIQUE]");
            alerte++;
        }

        // Check consecutive alerts on every reading
        if (alerte >= 3) {
            printf("\n>>> SYSTEME INSTABLE: %d alertes consecutives!", alerte);
        }
    }

    // Final daily summary
    if (nb_mesures > 0) {
        printf("\n\n--- RAPPORT ---\n");
        printf("Moyenne : %.2f C | Min : %.1f C | Max : %.1f C\n",
               somme_temp / nb_mesures, temp_min, temp_max);
    }

    return 0;
}


