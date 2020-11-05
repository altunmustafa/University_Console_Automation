#ifndef PERSON_H
#define PERSON_H

#include <string>

#include <fstream>
#include <sstream>
using namespace std;

class Person    //tamam
{
    friend class PersonDoublyLinkedList;
    friend class Student;
    friend class Staff;
    friend class SupportPersonnel;
    public:
        Person();
        virtual ~Person();

        virtual void print(const int) const=0;
        virtual void create()=0;
        virtual void updatePerson()=0;
        virtual void detail() const=0;

        void deletePerson();


    protected:
        string ID, nameSurname, status, callNumber, foreignLang;
        double gradeAve;
        int startYear;
        Person *next,*prev;
    private:

};

#endif // PERSON_H
