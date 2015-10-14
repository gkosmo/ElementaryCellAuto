#include <iostream>
#include <fstream>
#include <cstdio>
#include<cellaut.h>
using namespace std;



// Je ne connais pas de référence francophone pour le "cellular aumota", néanmoins voici la référence anglaise: http://en.wikipedia.org/wiki/Elementary_cellular_automaton
//le programme écrit ici propose a l'utilisateur d'entrer une regle, entrer une ligne et faire le test sur cette ligne pour en constituer un tableau enregistrable.Ceci est un résultat pratique du cours de programmation algorithmique. George Kosmopoulos








    int main () {

        Cellaut a;
        int choice =1 ;
        while(choice != 0) {
            choice = a.menu();
            switch(choice) {
                case 1:
                    a.remplireg();
                    break;
                case 2:
                    a.remplili();
                    break;

                case 3:
                     a.tab2dtst();
                     break;
                 case 4:
                    a.cf2d();
                    break;
                case 5:
                    a.tab2dfi();
                    cout << " and for the tryl " << endl;

                    break;
        case 6:
                     a.presentab2d();
                     break;
        case 7:
                a.presentreg();
                break;
            case 8:
            a.presenttab();
            break;
            case 9:
            a.celltest();
            break;
        case 0:
                     break;
            default:
                    cout << "ce n'est pas dans le menu"
                        << endl;
            }
        }
     return 0;

}



