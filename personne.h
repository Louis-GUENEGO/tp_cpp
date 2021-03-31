#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
#include <fstream>

#ifndef _PERSONNE_H_
#define _PERSONNE_H_

    #define TAILLE_GENRE 5
    #define TAILLE_PRENOM 15
    #define TAILLE_NOM 15
    #define TAILLE_SITUATION 64
    #define LIGNE_MAX_FICHIER 128


    class personne {
        private:
            char genre [TAILLE_GENRE]; // 0 -> H, 1 -> F, etc.
            char prenom [TAILLE_PRENOM];
            char nom [TAILLE_NOM];
            int date_naissance;
            int age;
            char situation[TAILLE_SITUATION];

        public:
            personne(void); //constructeur
            char setGenre(const char *);
            char setPrenom(const char *);
            char setNom(const char *);
            void setDate(const int);
            void calcAge(void);
            char setSituation(const char *);

            char loadFromFile(const char *);

            void afficheInformation(void);
    };

#endif
