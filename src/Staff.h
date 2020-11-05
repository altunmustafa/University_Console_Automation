#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

#include <iostream>
#include <iomanip>

#include <fstream>
#include <sstream>

using namespace std;

class Staff : public Person
{
    public:
        Staff();
        Staff(const string nameSurname, const string status, const string callNumber, const string foreignLang);
        virtual ~Staff();

        void create();
        void print(const int) const;
        void updatePerson();
        void detail() const;

    protected:
    private:
};

#endif // STAFF_H
