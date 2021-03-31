#include "personne.h"

personne::personne(void){
    std::cout << "Une personne a été créé" << std::endl;
    return;
}

void personne::setGenre(const char _genre){
    genre = _genre;
    return;
}

char personne::setPrenom(const char * _prenom){
    if (strlen(_prenom) < TAILLE_PRENOM) {
        strcpy (prenom, _prenom);
        return 0;
    } else {
        return -1;
    }
}

char personne::setNom(const char * _nom){
    if (strlen(_nom) < TAILLE_NOM) {
        strcpy (nom, _nom);
        return 0;
    } else {
        return -1;
    }
}

void personne::setDate(const int _date_naissance){
    date_naissance = _date_naissance;
}

void personne::calcAge(void){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    age = tm.tm_year + 1900 - date_naissance;
}

char personne::setSituation(const char * _situation){
    if (strlen(_situation) < TAILLE_SITUATION) {
        strcpy (situation, _situation);
        return 0;
    } else {
        return -1;
    }
}

void personne::afficheInformation(void){
    if (genre == 0){
        std::cout << "M ";
    } else {
        std::cout << "Mme ";
    }

    std::cout << prenom << " " << nom << " est né en " << date_naissance <<
        " (" << age << " ans), il est " << situation << std::endl;

    return;
}
