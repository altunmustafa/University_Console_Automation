#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
using namespace std;

class EquipmentDoublyLinkedList;

class Equipment
{
    friend class EquipmentDoublyLinkedList;
    friend class EducationEquipment;
    friend class LaboratoryEquipment;

    public:
        Equipment();
        virtual ~Equipment();

        virtual void print(const int) const=0;
        virtual void create()=0;
        virtual void updateEq()=0;
        virtual void detail() const=0;

        void deleteEq();
       // virtual string getID()=0;
    protected:
        string eqID,desc,who,where;
        int buyYear,lifeTime;
        Equipment *next,*prev;
    private:
};



#endif // EQUIPMENT_H
