#ifndef EDUCATIONEQUIPMENT_H
#define EDUCATIONEQUIPMENT_H

#include "Equipment.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class EducationEquipment : public Equipment
{
    public:
        EducationEquipment();
        EducationEquipment(const string description,const int bYear, const string debitStaffID);
        virtual ~EducationEquipment();

        void create(); //Kullanıcıyla etkileşimli ekipman üretir.
        void updateEq();
        void print(const int) const;    //parametre olarak sira numarasini aliyor. 1se baslik atiyor.
        void detail() const;
    protected:
    private:
};

#endif // EDUCATIONEQUIPMENT_H
