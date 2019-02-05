//
// Created by totog1nger on 26/10/18.
//

#ifndef SUDOKU_GRILLE_HH
#define SUDOKU_GRILLE_HH

#include "case.hh"
#include <vector>

class grille{
public:
    // ## constructeur
    grille();

    // ## getteurs
    std::vector<valCase> getCarre(caseGrille & c);
    std::vector<valCase> getLigne(caseGrille & c);
    std::vector<valCase> getColonne(caseGrille & c);

    std::vector<valCase> getValeursPossiblesPourLeCarre(caseGrille & c);
    std::vector<valCase> getValeursPossiblesPourLaColonne(caseGrille & c);
    std::vector<valCase> getValeursPossiblesPourLaLigne(caseGrille & c);

    // ## methodes
    void setValeurPossibles(caseGrille & c);
    char getCharOfValCase(valCase v);
    valCase getValCaseOfChar(char c);
    void setValCase(indice ligne, indice colonne, valCase v);

    bool iterer();
    bool resoudre();
    void resoudreTotalement();

    void afficherGrille();
private:
    std::vector<std::vector<caseGrille> > _grille;

};

#endif //SUDOKU_GRILLE_HH
