#include "fun.hpp"

int tmap1[15][10] = {
    {0, 3, 1, 1, 1, 1, 3, 1, 1, 1},
    {1, 3, 1, 3, 1, 1, 3, 1, 3, 1},
    {1, 3, 1, 3, 1, 3, 3, 1, 3, 1},
    {1, 3, 1, 3, 1, 1, 1, 1, 3, 1},
    {1, 3, 1, 3, 2, 3, 3, 1, 3, 1},
    {1, 3, 1, 3, 3, 3, 3, 3, 3, 1},
    {1, 1, 1, 3, 1, 1, 1, 2, 3, 1},
    {3, 3, 1, 3, 1, 1, 1, 1, 3, 1},
    {1, 3, 1, 3, 1, 3, 1, 1, 3, 1},
    {1, 1, 1, 2, 1, 3, 3, 1, 3, 1},
    {1, 3, 3, 3, 1, 3, 3, 1, 3, 1},
    {1, 3, 3, 3, 1, 3, 1, 1, 3, 3},
    {1, 1, 1, 3, 1, 3, 1, 2, 3, 1},
    {1, 3, 1, 3, 1, 3, 1, 3, 3, 1},
    {3, 3, 1, 1, 1, 3, 1, 1, 1, 4}
};

int tmap2[15][10] = {
    {0, 1, 1, 1, 1, 1, 1, 3, 3, 1},
    {1, 3, 3, 1, 1, 1, 1, 3, 1, 2},
    {1, 1, 3, 3, 3, 3, 1, 3, 1, 3},
    {3, 1, 2, 1, 1, 1, 1, 3, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 3, 1, 3},
    {3, 1, 3, 3, 1, 1, 1, 3, 1, 3},
    {3, 1, 1, 3, 3, 3, 1, 3, 1, 3},
    {3, 1, 2, 3, 1, 3, 1, 1, 1, 3},
    {3, 1, 1, 3, 1, 3, 1, 1, 1, 3},
    {2, 1, 1, 3, 1, 3, 3, 3, 3, 3},
    {1, 1, 1, 3, 1, 3, 1, 1, 1, 1},
    {1, 3, 1, 1, 1, 3, 1, 3, 1, 3},
    {1, 3, 1, 1, 1, 2, 1, 3, 1, 1},
    {1, 3, 3, 3, 3, 3, 1, 3, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 3, 3, 4}
};

void map::sign(int t[15][10]) {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            place[i][j] = t[i][j];
        }
    }
}

void map::reset() {
    x = 0;
    y = 0;
    health = 2;
}

void print(map &m0) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    int i, k;
    for (i = 0; i < 15; i++) {
        for (k = 0; k < 10; k++) {
            if (m0.y == i && m0.x == k) {
                printf("▲");
            } else {
                switch (m0.place[i][k]) {
                case 0:printf("s");break;
                case 1:printf("□");break;
                case 2:printf("x");break;
                case 3:printf("■");break;
                case 4:printf("e");break;
                }
            }
        }
        printf("\n");
    }
    if (m0.place[m0.y][m0.x] == 2) {
        printf("Trap!\n");
        m0.place[m0.y][m0.x] = 1;
    }
    printf("your health:%d\n", m0.health);
}

bool judge(int x, int y, map& m0) {
    if (x < 0 || x >= 10 || y < 0 || y >= 15) return 0;
    switch (m0.place[y][x]) {
    case 2:
        m0.health--;
        return 1;
        break;
    case 3:return 0;break;
    case 4:return 1;break;
    default:return 1;break;
    }
}

void move(char c, map& m0) {
    int x0 = m0.x;
    int y0 = m0.y;
    if (c == 'w' || c == 'a' || c == 'd' || c == 's') {
        switch (c) {
        case 'w':y0--;break;
        case 's':y0++;break;
        case 'a':x0--;break;
        case 'd':x0++;
        }
        if (judge(x0, y0, m0)) {
            m0.x = x0;
            m0.y = y0;
        }
    }
}