#ifndef REPONSE_H
#define REPONSE_H

#include <string>

class Reponse
{
public:
    Reponse(const std::string & texte, bool correct = false);

    std::string getTexte() const;
    bool isCorrect() const;

private:
    std::string texte;
    bool correct;
};

#endif // REPONSE_H
