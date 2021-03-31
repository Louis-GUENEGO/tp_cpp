#include "personne.h"

using namespace std;

int main () {
    personne per1;
    per1.setGenre(0);
    per1.setPrenom("Louis");
    per1.setNom("GUENEGO");
    per1.setDate(1999);
    per1.calcAge();
    per1.setSituation("trop fort");

    per1.afficheInformation();
}
