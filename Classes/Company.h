#ifndef PROJETO_COMPANY_H
#define PROJETO_COMPANY_H
#include<string>
#include "Base.h"
using namespace std;


class Company{
private:
    string boss;
    int boss_nif;
    Base Porto;
    Base Lisboa;
    Base Faro;
public:
    Company(){};
    Company(string Boss, int boss_nif, Base Porto, Base Lisboa, Base Faro);
    void setBoss(string boss);
    string getBoss()const;
    int getBossNif() const;
};


#endif //PROJETO_COMPANY_H
