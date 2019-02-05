//
// Created by totog1nger on 26/10/18.
//

#include "case.hh"
#include <iostream>
#include <string>

// ### class case :

// ## constructeur
caseGrille::caseGrille(indice ligne, indice colonne, valCase v)
    :_ligne(ligne), _colonne(colonne), _valeur(v), _valeurPossible(){};

// ## getteurs
indice caseGrille::getLigne(){
    return _ligne;
}

indice caseGrille::getColonne(){
    return _colonne;
}

valCase caseGrille::getValeur(){
    return _valeur;
}

std::vector<valCase> caseGrille::getValeursPossibles(){
    return _valeurPossible;
}

void caseGrille::afficherValeursPossibles(){
    std::cout << "case(" << _ligne << ", " << _colonne << "), valeur possibles : ";
    for(auto & i : _valeurPossible){
        switch (i) {
            case valCase::un:
                std::cout << "1, ";
                break;
            case valCase::deux:
                std::cout << "2, ";
                break;
            case valCase::trois:
                std::cout << "3, ";
                break;
            case valCase::quatre:
                std::cout << "4, ";
                break;
            case valCase::cinq:
                std::cout << "5, ";
                break;
            case valCase::six:
                std::cout << "6, ";
                break;
            case valCase::sept:
                std::cout << "7, ";
                break;
            case valCase::huit:
                std::cout << "8, ";
                break;
            case valCase::neuf:
                std::cout << "9, ";
                break;
            case valCase::inconnue:
                std::cout << "x, ";
                break;
        }
    }
    std::cout << std::endl;
}


// ## setteurs
void caseGrille::setValeur(valCase v){
    _valeur = v;
}

void caseGrille::clearValeurPossibles(){
    _valeurPossible.clear();
}

// ## methodes
bool caseGrille::aUneValeur(){
    return _valeur != valCase::inconnue;
}

void caseGrille::addValeurPossible(valCase v){
    _valeurPossible.push_back(v);
}
