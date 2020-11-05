#ifndef EQUIPMENTDOUBLYLINKEDLIST_H
#define EQUIPMENTDOUBLYLINKEDLIST_H

#include "DoublyLinkedList.h"
#include "EducationEquipment.h"
#include "LaboratoryEquipment.h"

#include <fstream>
#include <sstream>

#define FIRST_ID_NO 100

class Equipment;

class EquipmentDoublyLinkedList : public DoublyLinkedList
{
    public:
        EquipmentDoublyLinkedList();
        EquipmentDoublyLinkedList(const string);
        virtual ~EquipmentDoublyLinkedList();

        virtual void add(Person*);  //kullanilmiyor, polimorfizm için
        void add(Equipment*);
        int delete_(const string);
        int delete_(const int);
        int update(const string); // for ID
        int update(const int); // for Order No
        void print();
        bool empty_();

        int save(const char[] ) const;
        int load(const char[] ) ;

        void create();
        int getDetail(const int) const;

    protected:


    private:
        Equipment *getEquipment(const string) const;
        Equipment *getEquipment(const int) const;
        string idCreator();

        Equipment *header,*trailer;
        int noEduEq, noLabEq;



};

#endif // EQUIPMENTDOUBLYLINKEDLIST_H
