//
// Created by totog1nger on 26/10/18.
//

#include "grille.hh"
#include "case.hh"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// ### class grille
// ## constructeur
grille::grille()
    :_grille(){

    // # i fait reference a la ligne
    for(indice i(0); i <= 8 ; ++i){
        std::vector<caseGrille> v;

        // # j fait reference a la colonne
        for(indice j(0); j <= 8 ; ++j){
            caseGrille c(i, j, valCase::inconnue);
            v.push_back(c);
        }
        _grille.push_back(v);
    }
}


// ## getteurs
std::vector<valCase> grille::getCarre(caseGrille & c){

    std::vector<valCase > v;
    indice ligne = c.getLigne();
    indice colonne = c.getColonne();

/* A faire :
    cette methode retourne l'ensemble des cases du carre de la case en parametre sauf elle-meme

    les coordonnée du carré sont le quotient de ligne/3 et colonne/3
    la case en haut a gauche du carre a des coordonnees fait de 0, 3, 6

    ligne : si quotient < 1 carre.pointHautGauche.ligne = 0
                        > 1                               = 6
                        reste                             = 3

    colonne : si quotient < 1 carre.pointHaucheGauche.colonne = 0
                            > 1                             = 6
                            reste                           = 3
*/

    int quotientLigne = ligne/3;
    int quotientColonne = colonne/3;
    indice caseHautGauche_ligne = 0;
    indice caseHautGauche_colonne = 0;


    if(quotientLigne < 1){
        caseHautGauche_ligne = 0;
    }else{
        if(quotientLigne > 1) {
            caseHautGauche_ligne = 6;
        }else{
            caseHautGauche_ligne = 3;
        }
    }

    if(quotientColonne < 1){
        caseHautGauche_colonne = 0;
    }else{
        if(quotientColonne > 1) {
            caseHautGauche_colonne = 6;
        }else{
            caseHautGauche_colonne = 3;
        }
    }

    /* Maintenant qu'on a la case en haut a gauche du carre dans lequel se trouve notre case,
     * on va pouvoir avoir toutes les autres cases plus facilement.
     */

    //std::cout << "TEST : getCarre : ";

    for(indice i = caseHautGauche_ligne; i < caseHautGauche_ligne + 3; ++i){ // parcourir les 3 lignes du carre
        for(indice j = caseHautGauche_colonne; j < caseHautGauche_colonne + 3; ++j){ // parcour les 3 colonnes du carre
            if(_grille.at(i).at(j).aUneValeur()){
                v.push_back(_grille.at(i).at(j).getValeur());
                //std::cout << getCharOfValCase(_grille.at(i).at(j).getValeur()) << ", ";
            }
        }
    }
    //std::cout << std::endl;

    return v;
}

std::vector<valCase> grille::getLigne(caseGrille & c){
    std::vector<valCase> v;
    indice ligne = c.getLigne();

    //std::cout << "TEST : getLigne : ";

    for(indice i(0); i <= 8 ; ++i){
        if(_grille.at(ligne).at(i).aUneValeur()){
            v.push_back(_grille.at(ligne).at(i).getValeur());
            //std::cout << getCharOfValCase(_grille.at(ligne).at(i).getValeur()) << ", ";
        }
    }
    //std::cout << std::endl;
    return v;
}

std::vector<valCase> grille::getColonne(caseGrille & c){
    std::vector<valCase> v;
    indice colonne = c.getColonne();

    //std::cout << "TEST : getColonne : ";

    for(indice i(0); i <= 8 ; ++i){
        if(_grille.at(i).at(colonne).aUneValeur()){
            v.push_back(_grille.at(i).at(colonne).getValeur());
            //std::cout << getCharOfValCase(_grille.at(i).at(colonne).getValeur()) << ", ";
        }
    }
    //std::cout << std::endl;
    return v;
}

std::vector<valCase> grille::getValeursPossiblesPourLeCarre(caseGrille & c){
    std::vector<valCase> v;
    indice ligne = c.getLigne();
    indice colonne = c.getColonne();

    // voir getCarre pour explication
    // get Carre :

    int quotientLigne = ligne/3;
    int quotientColonne = colonne/3;
    indice caseHautGauche_ligne = 0;
    indice caseHautGauche_colonne = 0;


    if(quotientLigne < 1){
        caseHautGauche_ligne = 0;
    }else{
        if(quotientLigne > 1) {
            caseHautGauche_ligne = 6;
        }else{
            caseHautGauche_ligne = 3;
        }
    }

    if(quotientColonne < 1){
        caseHautGauche_colonne = 0;
    }else{
        if(quotientColonne > 1) {
            caseHautGauche_colonne = 6;
        }else{
            caseHautGauche_colonne = 3;
        }
    }

    //std::cout << "carre : " << std::endl;
    for(indice i = caseHautGauche_ligne; i < caseHautGauche_ligne + 3; ++i){ // parcourir les 3 lignes du carre
        for(indice j = caseHautGauche_colonne; j < caseHautGauche_colonne + 3; ++j){ // parcour les 3 colonnes du carre
            if( ! _grille.at(i).at(j).aUneValeur() && (i != c.getLigne() || j != c.getColonne())){
                //_grille.at(i).at(j).afficherValeursPossibles();
                for(auto & k : _grille.at(i).at(j).getValeursPossibles()) {
                    if (std::find(v.begin(), v.end(), k) == v.end()) // s'il n'y a pas deja cette valeurs on l'ajoutes
                        v.push_back(k);
                }
            }
        }
    }

    return v;
}
std::vector<valCase> grille::getValeursPossiblesPourLaColonne(caseGrille &c) {
    std::vector<valCase> v;
    indice colonne = c.getColonne();

    //std::cout << "colonne : " << std::endl;
    for(indice i(0); i <= 8 ; ++i){
        if( ! _grille.at(i).at(colonne).aUneValeur() && i != c.getLigne()){
            //_grille.at(i).at(colonne).afficherValeursPossibles();
            for(auto & k : _grille.at(i).at(colonne).getValeursPossibles()) {
                if(std::find(v.begin(), v.end(), k) == v.end()) // s'il n'y a pas deja cette valeurs on l'ajoutes
                    v.push_back(k);
            }
        }
    }

    return v;
}

std::vector<valCase> grille::getValeursPossiblesPourLaLigne(caseGrille &c) {
    std::vector<valCase> v;
    indice ligne = c.getLigne();

    //std::cout << "ligne : " << std::endl;
    for(indice i(0); i <= 8 ; ++i){
        if( ! _grille.at(ligne).at(i).aUneValeur() && i != c.getColonne()){
            //_grille.at(ligne).at(i).afficherValeursPossibles();
            for(auto & k : _grille.at(ligne).at(i).getValeursPossibles()) {
                if (std::find(v.begin(), v.end(), k) == v.end()) // s'il n'y a pas deja cette valeurs on l'ajoutes
                    v.push_back(k);
            }
        }
    }

    return v;
}


// ## methodes

// Il faut passer tout les nombres possibles pour cette case
// si cette case a deja une ensemble de valeurs possibles, il ne faut tester que ces dernieres.
// sinon il faut tester toutes les valeurs.
void grille::setValeurPossibles(caseGrille & c){
    //std::cout << "Set Valeurs Possibles de la case (" << c.getLigne() << ", " << c.getColonne() << ")" << std::endl;

    std::vector<valCase > vectCarre = getCarre(c);
    std::vector<valCase > vectLigne = getLigne(c);
    std::vector<valCase > vectColonne = getColonne(c);
    if(c.getValeursPossibles().empty()) {
        for (int i(0); i < 9; ++i) {
            valCase valCase_i = getValCaseOfChar(std::to_string(i + 1).at(0));
            if (std::find(vectCarre.begin(), vectCarre.end(), valCase_i) == vectCarre.end() &&
                std::find(vectLigne.begin(), vectLigne.end(), valCase_i) == vectLigne.end() &&
                std::find(vectColonne.begin(), vectColonne.end(), valCase_i) == vectColonne.end()) {
                c.addValeurPossible(valCase_i);
                //std::cout << "valeur possible : " << getCharOfValCase(valCase_i) << std::endl;
            }
        }
    }else{
        std::vector<valCase > vectValeursPossibles = c.getValeursPossibles();
        c.clearValeurPossibles();
        for(auto i : vectValeursPossibles){
            if (std::find(vectCarre.begin(), vectCarre.end(), i) == vectCarre.end() &&
                std::find(vectLigne.begin(), vectLigne.end(), i) == vectLigne.end() &&
                std::find(vectColonne.begin(), vectColonne.end(), i) == vectColonne.end()) {
                c.addValeurPossible(i);
                //std::cout << "valeur possible : " << getCharOfValCase(i) << std::endl;
            }
        }
    }
}

void grille::setValCase(indice ligne, indice colonne, valCase v){
    _grille.at(ligne).at(colonne).setValeur(v);
}

bool grille::iterer() {
    for (auto &i : _grille) {
        for (auto &j : i) {
            if (!j.aUneValeur())
                setValeurPossibles(j);
        }
    }
    return resoudre();
}

bool grille::resoudre(){
    bool res = false;

    for(auto & i : _grille){
        for(auto & j : i) {
            // si c'est la seul valeur possible alors on modifie
            if( ! j.aUneValeur() && j.getValeursPossibles().size() == 1) {
                std::cout << "methode 1 : modification case (" << j.getLigne() << ", " << j.getColonne() << "), avec " << getCharOfValCase(j.getValeursPossibles()[0]) << std::endl;
                j.setValeur(j.getValeursPossibles()[0]);
                j.clearValeurPossibles();
                res = true;
            }else{
                // sinon on regarde si cette valeur n'est possible qu'a cet endroit dans la ligne, la colonne ou le carre
                std::vector<valCase> cgCarre = getValeursPossiblesPourLeCarre(j);
                std::vector<valCase> cgColonne = getValeursPossiblesPourLaColonne(j);
                std::vector<valCase> cgLigne = getValeursPossiblesPourLaLigne(j);

                setValeurPossibles(j);
/*
                std::cout << "cgCarre : " << std::endl;
                for(auto m : cgCarre)
                    std::cout << getCharOfValCase(m) << ", ";
                std::cout << std::endl;

                std::cout << "cgColonne : " << std::endl;
                for(auto m : cgColonne)
                    std::cout << getCharOfValCase(m) << ", ";
                std::cout << std::endl;

                std::cout << "cgLigne : " << std::endl;
                for(auto m : cgLigne)
                    std::cout << getCharOfValCase(m) << ", ";
                std::cout << std::endl;
*/

                //exit(2);

                for(auto & k : j.getValeursPossibles()){
                    if(std::find(cgCarre.begin(), cgCarre.end(), k) == cgCarre.end() || // si ici est le seul endroit du carre ou ce nombre peut aller
                        std::find(cgColonne.begin(), cgColonne.end(), k) == cgColonne.end() || // ou si ici est le seul endroit de la colonne ou ce nb peut aller
                        std::find(cgLigne.begin(), cgLigne.end(), k) == cgLigne.end()) { // ou ici est le seul endroit de la ligne ou ce nb peut aller
                        std::cout << "methode 2 : modification case (" << j.getLigne() << ", " << j.getColonne() << "), avec " << getCharOfValCase(k) << std::endl;
                        j.setValeur(k);
                        j.clearValeurPossibles();
                        res = true;
                    }
                }
            }
        }
    }
    return res;
}

void grille::resoudreTotalement() {
    int nbIteration = 0;
    bool modification = true; // pour forcer le while

    while(nbIteration < 20 && modification){
        std::cout << "Iteration " << nbIteration+1 << ") : " << std::endl;
        modification = iterer();
        //afficherGrille();
        nbIteration++;
    }
}

void grille::afficherGrille(){
    std::string separateur = " ";
    for(indice i(0); i <= 8 ; ++i){
        for(indice j(0); j <= 8 ; ++j){
            if(j == 2 || j == 5){
                separateur = "   ";
            }else{
                separateur = " ";
            }
            valCase v = _grille.at(i).at(j).getValeur();
            if(v == valCase::inconnue)
                std::cout << " " << separateur;
            else
                std::cout << getCharOfValCase(v) << separateur;
        }
        if(i == 2 || i == 5){
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

char grille::getCharOfValCase(valCase v){
    switch (v){
        case valCase::un:
            return '1';
        case valCase::deux:
            return '2';
        case valCase::trois:
            return '3';
        case valCase::quatre:
            return '4';
        case valCase::cinq:
            return '5';
        case valCase::six:
            return '6';
        case valCase::sept:
            return '7';
        case valCase::huit:
            return '8';
        case valCase::neuf:
            return '9';
        case valCase::inconnue:
            return 'x';

        default:
            std::cout << "grille::remplirGrille [ switch wrong value entered ] !";
            return '0';
    }
}

valCase grille::getValCaseOfChar(char c){
    switch (c){
        case '1':
            return valCase::un;
        case '2':
            return valCase::deux;
        case '3':
            return valCase::trois;
        case '4':
            return valCase::quatre;
        case '5':
            return valCase::cinq;
        case '6':
            return valCase::six;
        case '7':
            return valCase::sept;
        case '8':
            return valCase::huit;
        case '9':
            return valCase::neuf;
        case 'x':
            return valCase::inconnue;

        default:
            std::cout << "grille::remplirGrille switch wrong value entered : " << c << std::endl;
            return valCase ::inconnue;
    }
}