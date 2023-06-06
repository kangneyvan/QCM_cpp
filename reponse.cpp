#include "reponse.h"

using namespace std;

Reponse::Reponse(const std::string &texte, bool correct)
    : texte(texte), correct(correct)
{

}

string Reponse::getTexte() const {
    return texte;
}

bool Reponse::isCorrect() const {
    return correct;
}
