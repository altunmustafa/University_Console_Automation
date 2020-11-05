#ifndef LABORATORYEQUIPMENT_H
#define LABORATORYEQUIPMENT_H

#include <iostream>
#include "Equipment.h"
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

class EquipmentDoublyLinkedList;


class LaboratoryEquipment : public Equipment{
    friend class EquipmentDoublyLinkedList;

    public:
        LaboratoryEquipment(const string description,const int bYear, const int lTime, const string labName);
        LaboratoryEquipment();
        virtual ~LaboratoryEquipment();

        void create(); //Kullanıcıyla etkileşimli ekipman üretir.
        void updateEq();
        void print(const int) const;
        int availability() const;
        void detail() const;
        //string getID();
    protected:
    private:
};


#endif // LABORATORYEQUIPMENT_H
