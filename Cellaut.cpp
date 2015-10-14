#include "cellaut.h"
#include<iostream>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;
Cellaut::Cellaut()
{
};

void Cellaut::copytab(){
   int i=0;
   for (;i<tail;i++){
       tab1[i]=tab2[i];
   }
};
void Cellaut::celltest (){
    int i;
    int p =0;
        for ( i=0; i < tail; i++) {
        p=tab1[(i-1+tail)%tail]*4+tab1[i]*2+tab1[(i+1)%tail]*1;
        tab2[i]=reg[p];
        cout << endl;
        }
       copytab();

presenttab();
};

void Cellaut::presenttab () const {
    int i;
    for (i=0; i < tail;i ++) {
    cout << tab1[i];
    }
};


void Cellaut::presentreg ()const{
    int i;

    cout << " voici la regle choisie " << endl;
    for (i=0; i < 8;i ++) {
    cout << reg[i];
    }
};


void Cellaut::Settab (){

    int i;
    cout << "tail de la tab1e est à 8 ou moins mais modulable dans le script ";
    cin >> i;
    tail = i;

    cout <<"entre 0 ou 1 pour la tab1 le nombre de fois de votre tail ";
    for (i=0; i < tail; i++){
        cout << "pour case " << i << endl;
        cin >> tab1[i]; }
};



void Cellaut::Setreg (){

    int i, j,q,k,l;
    j=0;

    cout << " entrer 1. pour entrez cellule par cellule, ou 2. pour entrer la regle.";
    cin >> k;
        switch(k) {
            case 1:
            cout<<"entre 0 ou 1, une cellule à la fois; pour la tab1 ";
            for (i=0; i < 8; i++){
               cout << " entrez le resultat voulu pour l'état suivant" << endl;
                cout << ( j / 4) << (j / 2 % 2 ) << (j % 2 ) <<endl;
                cin >> q;
                reg[i]=q;
                j= j + 1;
                cout << endl;
                cout << j;}; break;
            case 2:
            cout <<" entrez le numero de regle " << endl;
            cin >>q;
            j=128;
            for (i=0; i < 8; i++){
            if (q < j){
            reg[i] = 0;}
            else{
                q-=j;
                reg[i]=1;

            }
            j /= 2;
            cout<< j <<endl;
            }
                break;

            default:
            cout << " pas pris en compte";
            break;}

    cout << "regle numero : ";

    for (i=0;i<8;i++){
        cout << reg[i];}
    for(int i=0; i<8; i++){

    q=q*2+reg[i];
}
   cout <<" regle : "<< q;
};


void Cellaut::cf2d (){
            int i, j;
            string fi;
            cout << "entre le fichier dans lequel vous voulez sauvez votre 			tab1e "<< endl;
            cin >> fi;
            ofstream ceatf(fi.c_str(),ios::out);

            for ( i=0; i<tail2; i++){
            for(j=0; j < tail ; j++){
            ceatf << tab2d[i][j];
             }
            ceatf << endl;
        }
          ceatf.close();

};


void Cellaut::presentab2d () const{
           int i, j,k,q;
           q=0;
           for ( i=0; i<tail2; i++){
           for(j=0; j < tail; j++){
           cout << tab2d[i][j];
           }
           cout << "total = " ;
           q=0 ;
           for(int k=0; k<tail; k++){

           q=q*2+tab2d[i][k];
       }
           cout << q<<endl;
       }
};




void Cellaut::tab2dfi() {
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
        remplitab2d ();
        presenttab ();
        cout << number << ". " << line
                     << endl;

                ++number;
                getline(inFile, line);
    }
    inFile.close();
    cout << endl << endl << endl;
};




void Cellaut::remplitab2d (){
          int i;
         for (i=0; i < tail; i++){
            tab2d[rowc][i]=tab1[i];
        }
            rowc++;
};


void Cellaut::tab2dtst ()
{
  int i,a;
  rowc = 0;
  cout << "entrez le nombres de lignes desiré " << endl;
  cin >> a;
  tail2=a;
    for ( i=0; i <tail2; i++) {
    remplitab2d();
    celltest();
     }
};


int Cellaut::menu() const {
    int choice;
    cout << " Menu Principal" << endl << endl;
    cout << "0. Sort du menu" << endl;
    cout << "1. Creer une regle" << endl;
    cout << "2. Creer une ligne" << endl;
    cout << " 3. Creer un tab1eau" <<endl;
    cout << "4. Enregistrer un tab1eau dans un fichier"<<endl;
    cout << "5. Lire un tab1eau d'un fichier "<<endl;
    cout << "6. presente le tab1eau en travail " << endl;
    cout << "7. presente regle "<< endl;
    cout << " 8. Presente ligne "<< endl;
    cout << " 9. Etablier un changement sur la regle et la ligne établie " <<endl;
    cout << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    return choice;
};








