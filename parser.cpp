#include "siam.h"
int ind=0;

token ptoken[100];

token *lookahead = ptoken;

bool lol = true;

void showTokenStream()
{
    struct token* ptr=ptoken;

    int i=0;
    while(i<ind)
    {
        if(!ptr->op)
            cout <<"<"<<ptr->name<<","<<ptr->value<<">";
        else
            cout <<"<"<<ptr->name<<">";
        ptr++;
        i++;
    }
    cout<<endl<<endl;
}

void setToken(token tmptk)
{
        ptoken[ind]=tmptk;
        ind++;
        cout<<ind-1<<": ";
        showTokenStream();
}



void E();



void num()
{
    cout<<"<"<<lookahead->name<<","<<lookahead->value<<">";
    lookahead++;
}

void match(char ch)
{
    string sc;
    sc+=ch;
    if (lookahead->name == sc)
    {
        lookahead++;
    }
}

void F()
{


    if(lookahead->op==0)
    {
        num();
    }
    else if(lookahead->name=="(")
    {
        match('(');
        E();
        match(')');
    }

}


void TPrime()
{
    if (lookahead->name== "*")
    {
        match('*');
        F();
        cout<<"<*>";
        TPrime();

    }
    else if (lookahead->name == "/")
    {
        match('/');
        F();
        cout<<"</>";
        TPrime();
    }

}

void T()
{
    F();
    TPrime();
}

void EPrime()
{
    if (lookahead->name == "+")
    {
        match('+');
        T();
        cout<<"<+>";
        EPrime();
    }
    else if (lookahead->name == "-")
    {
        match('-');
        T();
        cout<<"<->";
        EPrime();
    }
}

void E()
{
    T();
    EPrime();
}


