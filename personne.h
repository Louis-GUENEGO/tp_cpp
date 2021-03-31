#include <iostream>
#include <string>
#include <string.h>
#include <time.h>

#ifndef _PERSONNE_H_
#define _PERSONNE_H_

    #define TAILLE_PRENOM 15
    #define TAILLE_NOM 15
    #define TAILLE_SITUATION 15


    class personne {
        private:
            char genre; // 0 -> H, 1 -> F, etc.
            char prenom [TAILLE_PRENOM];
            char nom [TAILLE_NOM];
            int date_naissance;
            int age;
            char situation[TAILLE_SITUATION];

        public:
            personne(void); //constructeur
            void setGenre(const char);
            char setPrenom(const char *);
            char setNom(const char *);
            void setDate(const int);
            void calcAge(void);
            char setSituation(const char *);

            void afficheInformation(void);
    };

#endif
