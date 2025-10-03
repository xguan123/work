#ifndef FUN_HPP
#define FUN_HPP

#include<iostream>
#include<cstdlib>

class map {
public:
    int place[15][10];
    int x = 0, y = 0, health = 2, h0 = 2;
    void sign(int t[15][10]);
    void reset();
};

enum class cell {
    start = 0,
    empty = 1,
    trap = 2,
    wall = 3,
    win = 4
};

extern int tmap1[15][10];
extern int tmap2[15][10];

void print(map &m0);
bool judge(int x, int y, map& m0);
void move(char c, map& m0);

#endif