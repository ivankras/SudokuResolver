//
// Created by totog1nger on 26/10/18.
//

#ifndef SUDOKU_CASE_HH
#define SUDOKU_CASE_HH

#include <vector>

using indice = unsigned short int;

enum class valCase {
    inconnue,
    un,
    deux,
    trois,
    quatre,
    cinq,
    six,
    sept,
    huit,
    neuf
} ;

class caseGrille {
public:
    // ## constructeur
    caseGrille(indice _ligne, indice _colonne, valCase v);

    // ## getteurs
    indice getLigne();
    indice getColonne();
    valCase getValeur();
    std::vector<valCase> getValeursPossibles();

    // ## setteurs
    void setValeur(valCase v);
    void clearValeurPossibles();

    // ## methodes
    void afficherValeursPossibles();
    bool aUneValeur();
    void addValeurPossible(valCase v);

private:
    indice _ligne;
    indice _colonne;
    valCase _valeur;
    std::vector<valCase> _valeurPossible;
} ;

#endif //SUDOKU_CASE_HH
