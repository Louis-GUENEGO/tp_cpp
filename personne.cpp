#include "personne.h"

personne::personne(void){
    std::cout << "Une personne a été créé" << std::endl;
    return;
}

char personne::setGenre(const char * _genre){
    if (strlen(_genre) < TAILLE_PRENOM) {
        strcpy (genre, _genre);
        return 0;
    } else {
        return -1;
    }
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
    calcAge();
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

    std::cout << genre << " " << prenom << " " << nom << " est né en "
        << date_naissance << " (" << age << " ans), il est " << situation
        << std::endl;

    return;
}

char personne::loadFromFile(const char * fileName){
    std::string STRING;
    char _attribut[LIGNE_MAX_FICHIER];
    char _valeur[LIGNE_MAX_FICHIER];
    int i;
    int j;
    std::ifstream infile;
    infile.open(fileName);
    while(!infile.eof()){
        getline(infile, STRING);
        if (STRING.length() < LIGNE_MAX_FICHIER){
            strcpy(_attribut, STRING.c_str());
        }
        for (i = 0; (i < LIGNE_MAX_FICHIER-1) && (_attribut[i]!='='); i++);
        if (_attribut[i]=='=') {
            for (j = 0 ; _attribut[j+i+1] != 0 ; j++){
                _valeur[j] = _attribut[j+i+1];
            }
            _attribut[i] = 0;
            _valeur[j] = 0;
            if (strcmp (_attribut, "genre") == 0) {
                if (strlen(_valeur) < TAILLE_GENRE){
                    strcpy (genre, _valeur);
                }
            } else if (strcmp (_attribut, "prenom") == 0) {
                if (strlen(_valeur) < TAILLE_PRENOM){
                    strcpy (prenom, _valeur);
                }
            } else if (strcmp (_attribut, "nom") == 0) {
                if (strlen(_valeur) < TAILLE_NOM) {
                    strcpy (nom, _valeur);
                }
            } else if (strcmp (_attribut, "date_naissance") == 0) {
                date_naissance = atoi(_valeur);
            } else if (strcmp (_attribut, "situation") == 0) {
                if (strlen(_valeur) < TAILLE_SITUATION) {
                    strcpy (situation, _valeur);
                }
            }
        }


    }
    infile.close();

    return 0;
}
