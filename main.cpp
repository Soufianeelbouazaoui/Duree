#include <iostream>
#include "Duree.hpp"


using namespace std;



int main()
{
    Duree resulte, duree1(5, 20, 10), duree2(0, 54, 54), duree3(1, 50, 0);
    resulte = duree1 + duree2 + duree3;
    duree1.printout();
    duree2.printout();
    resulte.printout();
    duree1 += duree2;
    cout << "and"<<endl;
    duree1.printout();
    cout << compare(duree1,duree2) <<endl; 
    cout << resulte;
    return 0;
}