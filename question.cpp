#include "question.h"

using namespace std;

Question::Question(const string &q)
    : question(q)
{

}

void Question::ajouter(const Reponse &r) {
    choix.push_back(r);
}

string Question::getTexte() const {
    return question;
}

const Reponse Question::operator[](size_t i) const {
    return choix[i];
}

Reponse &Question::operator[](size_t i) {
    return choix[i];
}

 size_t Question::getSize() const {
    return choix.size();
}
