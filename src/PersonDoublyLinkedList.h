#ifndef PERSONDOUBLYLINKEDLIST_H
#define PERSONDOUBLYLINKEDLIST_H

#include "DoublyLinkedList.h"
#include "Student.h"
#include "Staff.h"
#include "SupportPersonnel.h"

#include <sstream>
#include <fstream>

#define FIRST_ID_NO 100

class Person;

class PersonDoublyLinkedList : public DoublyLinkedList
{
    public:
        PersonDoublyLinkedList(const string);
        virtual ~PersonDoublyLinkedList();

        virtual void add(Equipment*); //kullanilmiyor, polimorfizm için
        void add(Person *person);
        int delete_(const string);
        int delete_(const int);
        int update(const string); // for ID
        int update(const int); // for Order No
        void print();
        bool empty_();

        int save(const char[] ) const;
        int load(const char[] ) ;
        string idCreator();
        void create();
        int getDetail(const int no) const ;

    protected:
    private:
        Person *getPerson(const string) const;
        Person *getPerson(const int) const;

        Person *header,*trailer;
        int noStaff, noStudent, noSupportPer;
};

#endif // PERSONDOUBLYLINKEDLIST_H
