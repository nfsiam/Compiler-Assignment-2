#include "siam.h"

int dex=0;

char *point;

void decideLexeme();

token tkn[100];

void D()
{
    while(isdigit(*point))
    {
        int x = (int)*point - 48;

        tkn[dex].value=(tkn[dex].value)*10+x;

        point++;
    }
    tkn[dex].name="num";
    tkn[dex].op=false;
    setToken(tkn[dex]);
    dex++;

}

void OP()
{
    tkn[dex].name+=*point;
    setToken(tkn[dex]);
    dex++;
    point++;
}


void decideLexeme()
{

    while(*point!='\0')
    {
        if(isdigit(*point))
        {
            D();
        }
        else
        {
            OP();
        }
    }
}


void readCharStream(char* in)
{
    point = in;

    decideLexeme();
}
