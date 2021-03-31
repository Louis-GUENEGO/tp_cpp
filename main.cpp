#include "personne.h"

using namespace std;

int main () {
    personne per1;
    per1.setGenre("M");
    per1.setPrenom("Louis");
    per1.setNom("GUENEGO");
    per1.setDate(1999);
    per1.setSituation("trop fort");
    per1.afficheInformation();

    personne per2;
    per2.loadFromFile("personne1.txt");
    per2.calcAge();
    per2.afficheInformation();
}
