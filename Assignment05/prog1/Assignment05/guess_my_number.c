<<<<<<< HEAD
#include "base.h"

int main(void) {
    int secret_number = i_rnd(100);
    bool found = false;
    int guess = 0;
    int tries = 0;
    printf("Spiele das Spiel 'Rate meine Zahl'!\n");
    printf("Ich habe mir eine Zahl zwischen 0 und 100 ausgedacht. Kannst du sie erraten?\n");
    printf("---------------------------------------\n");
    while (!found) {
        guess = i_input();
        if (tries >= 10) {
            printf("Sie haben zu oft geraten. Sie haben verloren.\n");
            break;
        }
        if (guess > 100) {
            printf("🤯 Big brain time\n");
        } else if (guess == secret_number) {
            printf("Match!\n");
            found = true;
        } else if (guess < secret_number) {
            printf("Too Small!\n");
        } else {
            printf("Too Large!\n");
        }
        tries++;
        printf("Used tries: %d \n", tries);
    }
    return 0;
=======
/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

int main(void){
    int random_number = i_rnd(101);
    printsln("Guess my number:");
    int guess = i_input();
    while (guess != random_number) {
        if (guess < random_number){
            printsln("Too Small!");
        } else if (guess > random_number) {
            printsln("Too Large!");
        }
        guess = i_input();
    }
    printsln("Match!");
>>>>>>> d0c02ad8a49113f835b449f0074b7d510f131094
}