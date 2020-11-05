#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>

using namespace std;

class Equipment;
class Person;

void newPage();
void setErrorEntry();
void programmingError(const string);
void printTitle(const string);

class DoublyLinkedList
{
    friend class PersonDoublyLinkedList;
    friend class EquipmentDoublyLinkedList;
    public:
        DoublyLinkedList();
        virtual ~DoublyLinkedList();

        virtual void add(Equipment*)=0;
        virtual void add(Person*)=0;
        virtual int delete_(const string)=0;    // for ID
        virtual int delete_(const int)=0;       // for Order No
        virtual int update(const string)=0;
        virtual int update(const int)=0;
        virtual void print()=0;
        virtual bool empty_()=0;
        virtual int getDetail(const int) const=0;
        virtual int save(const char[] ) const=0;
        virtual int load(const char[] )=0 ;
        virtual string idCreator()=0;
        virtual void create()=0;


    protected:
        string TYPE,TYPE_TR;

    private:
};

#endif // DOUBLYLINKEDLIST_H
