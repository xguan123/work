#include "fun.hpp"

int main() {
    map m1;
    int choice;
    char c;
    while (1) {
        m1.reset();
        printf("\t\tgame start\ninput 1 or 2 to select map\ninput 0 to exit\n");
        std::cin >> choice;
        if (choice == 1) {
            m1.sign(tmap1);
        } else if (choice == 2) {
            m1.sign(tmap2);
        } else if (choice == 0) {
            return 0;
        } else {
            printf("error\n");
        }

        while (m1.place[m1.y][m1.x] != 4 && m1.health > 0) {
            print(m1);
            std::cin >> c;
            move(c, m1);
        }

        if (m1.place[m1.y][m1.x] == 4) {
            printf("you win!\n\n");
        } else {
            printf("you lose!\n\n");
        }
    }
}