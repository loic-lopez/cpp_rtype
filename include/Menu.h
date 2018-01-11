//
// Created by Zakelis on 09/01/2018.
//

#ifndef R_TYPE_MENU_H
#define R_TYPE_MENU_H

#include <SFML/Audio.hpp>
#include "Parsing.h"
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"
#include "Button.h"

class Menu {
private:
    sf::Sprite menuBackgroundSprite;
    sf::Texture backgroundTexture;
    sf::Music music;

    //TODO : RAJOUTER UN VECTEUR DE STRING QUI SERVIRA A CREER DES BOUTONS (REMPLIR LE VECTEUR DANS LA LAMBDA POUR LES BOUTONS)

    std::vector<std::string> buttonEffectsPaths;

    // TODO : COMMENT CA MARCHE ? METTRE TROIS BOUTONS IDENTIQUES MAIS AVEC TROIS EFFETS DIFFERENTS
    // TODO (SUITE) : PARSER 3 PAR 3 DANS LA LAMBDA (CHANGER LE SYSTEME DU COMPTEUR), ET REMPLIR LE VECTEUR DE STRING
    // TODO (SUITE) : ET CREER UN BOUTON UNE FOIS QUE LE VECTEUR CONTIENT 3 SPRITES

    std::vector<Button *> menuButtons;

public:
    Menu();
    ~Menu();
    void initMenu(const std::string &path);
    void drawMenu(sf::RenderWindow &App);
    void updateMenuButtons(sf::Event& e, sf::RenderWindow& window); // TODO : A APPELLER DANS LA BOUCLE DE JEU AVANT LE DRAW
    void determineButtonsPosition();
};


#endif //R_TYPE_MENU_H
