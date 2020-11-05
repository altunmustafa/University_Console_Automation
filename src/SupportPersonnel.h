#ifndef SUPPORTPERSONNEL_H
#define SUPPORTPERSONNEL_H

#include "Person.h"

#include <iostream>
#include <iomanip>
using namespace std;

class SupportPersonnel : public Person
{
    public:
        SupportPersonnel();
        SupportPersonnel(const string nameSurname, const string callNumber, const int startYear);
        virtual ~SupportPersonnel();

        void create();
        void print(const int) const;
        void updatePerson();
        void detail() const;

    protected:
    private:
};

#endif // SUPPORTPERSONNEL_H
