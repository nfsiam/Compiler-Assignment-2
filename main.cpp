#include "siam.h"

int main()
{
    char input[] = "(2/88)-97+(61/7500)-(((5*21)/(7+(50*24)))/29)+(59*23)";

    readCharStream(input);


    cout<<"\nAfter Parsing the token stream to postfix: \n\n";
    E();
    cout<<endl;

    return 0;
}
