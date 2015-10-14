#include <iostream>
#include <fstream>
#include <cstdio>


#ifndef CELLAUT_H
#define CELLAUT_H

class Cellaut
{
public:
    Cellaut();


    void Setreg (); /* cree une regle de CA */
    void Settab(); /*rempli la ligne initiale du CA*/
    void presentreg () const;/*montre la regle*/
    void presenttab () const;/*presente une ligne de CA*/
    void celltest (); /*transforme une ligne selon une regle CA*/
    void cf2d ();/* cree un fichier dans le quel est ecrit une table CA*/
    void remplitab2d ();/* rempli une ligne dans une table*/
    void presentab2d ()const;/* presente une table*/
    void tab2dfi();/* presente une table dans un fichier*/
    void tab2dtst ();/* rempli une table CA */
    int menu() const; /*presente les choix */
    void copytab();
    void Setrowc();

private:
   int tail;
   int tail2;
    int rowc;
    int tab2[100];
    int tab1[100];
    int reg[8];

    int tab2d[100][100];
    int choice;
};

#endif // CELLAUT_H
