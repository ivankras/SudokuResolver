#include <iostream>
#include "grille.hh"

bool lineIsCorrect(std::string str){
    if(str.length() != 9)
        return false;

    for(char c : str){
        if(c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != 'x')
            return false;
    }

    return  true;
}

void remplirGrille(grille & g){
    std::cout << "Entrer la valeur de la case ou x quand inconnue : " << std::endl;
    indice nbLigneEntrees = 0;
    std::string entree;

    while(nbLigneEntrees < 9){
        std::cout << "ligne " << nbLigneEntrees + 1 << " : " << std::endl;
        std::cin >> entree;
        if(lineIsCorrect(entree)){
            for(indice i(0); i < 9; ++i){
                g.setValCase(nbLigneEntrees, i, g.getValCaseOfChar(entree.at(i)));
            }

            nbLigneEntrees++;
        }else{
            std::cout << "ERREUR ! Veuillez entrer a nouveau la ligne." << std::endl;
        }
    }
}

void testGrille(grille & g){
    // trois premieres lignes
    g.setValCase(0, 3, valCase::six);
    g.setValCase(0, 6, valCase::un);
    g.setValCase(0, 8, valCase::sept);

    g.setValCase(1, 0, valCase::six);
    g.setValCase(1, 1, valCase::huit);
    g.setValCase(1, 3, valCase::neuf);
    g.setValCase(1, 4, valCase::cinq);
    g.setValCase(1, 5, valCase::un);
    g.setValCase(1, 6, valCase::trois);

    g.setValCase(2, 2, g.getValCaseOfChar('3'));
    g.setValCase(2, 5, g.getValCaseOfChar('2'));
    g.setValCase(2, 6, g.getValCaseOfChar('5'));
    g.setValCase(2, 7, g.getValCaseOfChar('6'));
    g.setValCase(2, 8, g.getValCaseOfChar('8'));

    // les trois lignes du milieu
    g.setValCase(3, 1, g.getValCaseOfChar('4'));
    g.setValCase(3, 3, g.getValCaseOfChar('8'));
    g.setValCase(3, 4, g.getValCaseOfChar('1'));
    g.setValCase(3, 7, g.getValCaseOfChar('2'));

    g.setValCase(4, 6, g.getValCaseOfChar('8'));
    g.setValCase(4, 7, g.getValCaseOfChar('5'));

    g.setValCase(5, 1, g.getValCaseOfChar('9'));
    g.setValCase(5, 4, g.getValCaseOfChar('6'));
    g.setValCase(5, 5, g.getValCaseOfChar('5'));
    g.setValCase(5, 7, g.getValCaseOfChar('7'));
    g.setValCase(5, 8, g.getValCaseOfChar('3'));

    // les trois dernieres lignes
    g.setValCase(6, 0, g.getValCaseOfChar('4'));
    g.setValCase(6, 2, g.getValCaseOfChar('9'));
    g.setValCase(6, 5, g.getValCaseOfChar('3'));
    g.setValCase(6, 7, g.getValCaseOfChar('8'));
    g.setValCase(6, 8, g.getValCaseOfChar('5'));

    g.setValCase(7, 0, g.getValCaseOfChar('1'));
    g.setValCase(7, 1, g.getValCaseOfChar('6'));
    g.setValCase(7, 2, g.getValCaseOfChar('2'));
    g.setValCase(7, 5, g.getValCaseOfChar('9'));
    g.setValCase(7, 7, g.getValCaseOfChar('3'));

    g.setValCase(8, 0, g.getValCaseOfChar('5'));
    g.setValCase(8, 3, g.getValCaseOfChar('7'));
    g.setValCase(8, 5, g.getValCaseOfChar('6'));
}

void testGrille2(grille & g){
    // trois premieres lignes
    g.setValCase(1, 0, g.getValCaseOfChar('2'));
    g.setValCase(2, 0, g.getValCaseOfChar('3'));

    // les trois lignes du milieu
    g.setValCase(3, 1, g.getValCaseOfChar('1'));

    // les trois dernieres lignes
    g.setValCase(6, 2, g.getValCaseOfChar('1'));
}

void testGrille3(grille & g){
    // trois premieres lignes
    g.setValCase(0, 2, g.getValCaseOfChar('7'));
    g.setValCase(0, 6, g.getValCaseOfChar('8'));

    g.setValCase(1, 0, g.getValCaseOfChar('3'));
    g.setValCase(1, 2, g.getValCaseOfChar('6'));
    g.setValCase(1, 3, g.getValCaseOfChar('1'));
    g.setValCase(1, 4, g.getValCaseOfChar('8'));
    g.setValCase(1, 5, g.getValCaseOfChar('2'));
    g.setValCase(1, 6, g.getValCaseOfChar('7'));
    g.setValCase(1, 7, g.getValCaseOfChar('4'));
    g.setValCase(1, 8, g.getValCaseOfChar('5'));

    g.setValCase(2, 1, g.getValCaseOfChar('8'));
    g.setValCase(2, 3, g.getValCaseOfChar('5'));
    g.setValCase(2, 4, g.getValCaseOfChar('3'));
    g.setValCase(2, 5, g.getValCaseOfChar('7'));

    // les trois lignes du milieu
    g.setValCase(3, 0, g.getValCaseOfChar('6'));
    g.setValCase(3, 1, g.getValCaseOfChar('7'));
    g.setValCase(3, 2, g.getValCaseOfChar('2'));
    g.setValCase(3, 5, g.getValCaseOfChar('5'));
    g.setValCase(3, 6, g.getValCaseOfChar('9'));

    g.setValCase(4, 1, g.getValCaseOfChar('4'));
    g.setValCase(4, 2, g.getValCaseOfChar('9'));
    g.setValCase(4, 3, g.getValCaseOfChar('2'));
    g.setValCase(4, 5, g.getValCaseOfChar('8'));
    g.setValCase(4, 7, g.getValCaseOfChar('1'));

    g.setValCase(5, 1, g.getValCaseOfChar('3'));
    g.setValCase(5, 3, g.getValCaseOfChar('4'));
    g.setValCase(5, 5, g.getValCaseOfChar('6'));
    g.setValCase(5, 8, g.getValCaseOfChar('7'));

    // les trois dernieres lignes
    g.setValCase(6, 0, g.getValCaseOfChar('7'));
    g.setValCase(6, 1, g.getValCaseOfChar('6'));
    g.setValCase(6, 3, g.getValCaseOfChar('8'));
    g.setValCase(6, 6, g.getValCaseOfChar('4'));
    g.setValCase(6, 8, g.getValCaseOfChar('9'));

    g.setValCase(7, 0, g.getValCaseOfChar('9'));
    g.setValCase(7, 2, g.getValCaseOfChar('8'));
    g.setValCase(7, 5, g.getValCaseOfChar('3'));

    g.setValCase(8, 3, g.getValCaseOfChar('6'));
    g.setValCase(8, 6, g.getValCaseOfChar('3'));
}

int main() {

    grille g;
    std::string grilleCorrect = "n";

    //testGrille(g); // test de base
    //testGrille2(g); // test de la methode 2 de resolution
    //testGrille3(g);

    while (grilleCorrect.at(0) != 'y' && grilleCorrect.at(0) != 'Y') {
        remplirGrille(g);
        g.afficherGrille();

        std::cout << "Est ce bien votre grille ? (y/n) : ";
        std::cin >> grilleCorrect;
    }


    g.resoudreTotalement();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TABLE FINALE ... " << std::endl << std::endl;
    g.afficherGrille();


    return 0;
}