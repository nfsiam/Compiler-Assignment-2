#ifndef SIAM_H_INCLUDED
#define SIAM_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct token
{
    string name;
    int value;
    bool op=true;
};


void readCharStream(char*);

void setToken(token);

void requestToken();

void decideLexeme();
void E();

#endif // SIAM_H_INCLUDED
