#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;



// Je ne connais pas de référence francophone pour le "cellular aumota", néanmoins voici la référence anglaise: http://en.wikipedia.org/wiki/Elementary_cellular_automaton
//le programme écrit ici propose a l'utilisateur d'entrer une regle, entrer une ligne et faire le test sur cette ligne pour en constituer un tableau enregistrable.Ceci est un résultat pratique du cours de programmation algorithmique. George Kosmopoulos








    void remplireg (int reg[8], int taille); /* cree une regle de CA */
    void remplili (int tabl[8], int &taille); /*rempli la ligne initiale du CA*/
    void presentreg (int reg[8], int taille);/*montre la regle*/
    void presenttab (int tabl[8], int tail);/*presente une ligne de CA*/
    void celltest (int tab1[8],int tab2[8],int reg[8],int tail); /*transforme une ligne selon une regle CA*/
    void cf2d (int tab2d[10][8], int rowc);/* cree un fichier dans le quel est ecrit une table CA*/
    void remplitab2d ( int tab2d[10][8], int tab1[8], int &rowc);/* rempli une ligne dans une table*/
    void presentab2d (int tab2d[10][8], int  rowc);/* presente une table*/
    void tab2dfi(int tryl[10][8]);/* presente une table dans un fichier*/
    void tab2dtst (int tab2d[10][8],int reg[8], int tail, int tab1[8], int &rowc );/* rempli une table CA */
    int menu(); /*presente les choix */


    int main () {


     int tab1[8], reg[8];
     int tail, rowc;
     int tab2d[10][8];
     int choice;

        while(choice != 0) {
            choice = menu();
            switch(choice) {
                case 1:
                    remplireg(reg, tail);
                    break;
                case 2:
                    remplili(tab1,tail);
                    break;

                case 3:
                     tab2dtst(tab2d, reg, tail, tab1,rowc);
                     break;
                 case 4:
                    cf2d(tab2d, rowc);
                    break;
                case 5:
                    tab2dfi(tab2d);
                    cout << " and for the tryl " << endl;

                    break;
        case 6:
                     presentab2d(tab2d,rowc);
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


void tab2dfi(int tryl[10][8]) {
    fstream inFile;
    string fi;
    int  d = 0;
    cout << "tab in file, entrez le fichier" << endl << endl;
    cin >> fi;
    int number = 1;
    int p[8];
    string line;
    inFile.open(fi.c_str(), ios::in);
    if(!inFile) {
        cout << "File not found." << endl;
    }
    getline(inFile, line);
    while (!inFile.eof()) {
        for (int i=0; line[i];++i){
          p[i] = (int(line[i]))%48;

          cout << line[i]<<endl;
        }
        remplitab2d (tryl,p,d);
        presenttab (p, 8);
        cout << number << ". " << line
                     << endl;

                ++number;
                getline(inFile, line);
    }
    inFile.close();
    cout << endl << endl << endl;
}





 void presentab2d (int tab2d[10][8], int rowc){
            int i, j;
            for ( i=0; i<rowc; i++){
            for(j=0; j < 8 ; j++){
            cout << tab2d[i][j];
            }
            cout << endl;
        }
}


void cf2d (int tab2d[10][8], int rowc){
            int i, j;
            string fi;
            cout << "entre le fichier dans lequel vous voulez sauvez votre 			table "<< endl;
            cin >> fi;
            ofstream ceatf(fi.c_str(),ios::out);

            for ( i=0; i<rowc; i++){
            for(j=0; j < 8 ; j++){
            ceatf << tab2d[i][j];
             }
            ceatf << endl;
        }
          ceatf.close();

}



void remplitab2d ( int tab2d[10][8], int tab1[8], int &rowc){
          int i;
         for (i=0; i < 8; i++){
            tab2d[rowc][i]=tab1[i];
        }
            rowc++;
}



void remplireg (int reg[8], int taille){

    int i, j;
    taille = 8 ;
    j=0;
    cout<<"entre 0 ou 1, une cellule à la fois; pour la tab1 ";
    for (i=0; i < taille; i++){

       cout << " entrez le resultat voulu pour l'état suivant" << endl;
        cout << ( j / 4) << (j / 2 % 2 ) << (j % 2 ) <<endl;
        cin >> reg[i];
        j= j + 1;
        cout << endl;
         cout << j;
    }
}


void remplili (int tabl[8], int &taille){

    int i;
    cout << "Taille de la table est à 8 ou moins mais modulable dans le script ";
    taille = 8;

    cout <<"entre 0 ou 1 pour la tab1 le nombre de fois de votre taille ";
    for (i=0; i < taille; i++){
        cout << "pour case " << i << endl;
        cin >> tabl[i]; }
}




void presentreg (int tab[8], int taille) {
    int i;
    for (i=0; i < taille;i ++) {
    cout << " voici la regle choisie " << endl;
    cout << tab[i];
    }
}



void presenttab (int tabl[8], int tail) {
    int i;
    for (i=0; i < tail;i ++) {
    cout << tabl[i];
    }
}



void celltest (int tab1[8],int tab2[8],int reg[8],int tail){
    int i;
    int p;
        for ( i=0; i < tail; i++) {
        p=tab1[(i-1+tail)%tail]*4+tab1[i]*2+tab1[(i+1)%tail]*1;
        tab2[i]=reg[p];
    }
}


void tab2dtst (int tab2d[10][8],int reg[8], int tail, int tab1[8], int &rowc)
{
  int tab2[8];
  int i;
  rowc = 0;
       for ( i=0; i < 5; i++) {
    remplitab2d(tab2d,tab1, rowc);
    celltest(tab1, tab2, reg, tail);
    remplitab2d(tab2d,tab2, rowc);
    celltest(tab2, tab1, reg, tail);
     }
}


int menu() {
    int choice;
    cout << " Menu Principal" << endl << endl;
    cout << "0. Sort du menu" << endl;
    cout << "1. Creer une regle" << endl;
    cout << "2. Creer une ligne" << endl;
    cout << " 3. Creer un tableau" <<endl;
    cout << "4. Enregistrer un tableau dans un fichier"<<endl;
    cout << "5. Lire un tableau d'un fichier "<<endl;
    cout << "6. presente le tableau en travail " << endl;
    cout << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    return choice;
}






