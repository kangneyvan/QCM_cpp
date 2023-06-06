#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include "reponse.h"

class Question
{
public:
    Question(const std::string & q);

    void ajouter(const Reponse & r);

    std::string getTexte() const;

    size_t getSize() const ;

    const Reponse operator[] (size_t i) const;

    Reponse & operator[] (size_t i);

private:
    std::string question;
    std::vector<Reponse> choix;
};



#endif // QUESTION_H
