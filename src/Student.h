#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Student : public Person
{
    public:
        Student();
        Student(const string ,const int  , const double , const string );
        virtual ~Student();

        void create();
        void print(const int) const;
        void updatePerson();
        void detail() const;

    protected:
    private:
};

#endif // STUDENT_H
