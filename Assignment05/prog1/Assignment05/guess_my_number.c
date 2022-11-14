#include "base.h"

int main(void) {
    int secret_number = i_rnd(100);
    bool found = false;
    int guess = 0;
    int tries = 0;
    printf("Spiele das Spiel 'Rate meine Zahl'!\n");
    while (!found) {
        printf("---------------------------------------\n");
        printf("Geben Sie eine Zahl zwischen 0 und 100 ein: ");
        guess = i_input();
        if (tries >= 10) {
            printsln("Sie haben zu oft geraten. Sie haben verloren.");
            break;
        }
        if (guess == secret_number) {
            printsln("Sie haben die Zahl erraten!");
            found = true;
        } else if (guess < secret_number) {
            printsln("Die gesuchte Zahl ist größer.");
        } else {
            printsln("Die gesuchte Zahl ist kleiner.");
        }
        tries++;
        printf("Used tries: %d \n", tries);
    }
    return 0;
}