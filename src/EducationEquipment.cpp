#include "EducationEquipment.h"

EducationEquipment::EducationEquipment()
{
}

EducationEquipment::~EducationEquipment()
{
}

EducationEquipment::EducationEquipment(const string description,const int bYear, const string debitStaffID)
{
    desc    =description;
    buyYear =bYear;
    who     =debitStaffID;
}

void EducationEquipment::create()
{
    cout<<"\nYeni ekipman bilgilerini gir...\nAciklama: ";
    cin.clear();
    getline(cin,desc);
    cin.clear();
    cout<<"Alinan yil: ";
    cin>>buyYear;
    cout<<"Kullanan: ";
    cin.ignore();
    getline(cin,who);
}

void EducationEquipment::updateEq()
{
    cout<<"\nEkipman guncelle...\nID: "<<eqID<<"\nAciklama: ";
    cin.clear();
    getline(cin,desc);
    cin.clear();
    cout<<"Alinan yil: ";
    cin>>buyYear;
    cout<<"Kullanan: ";
    cin.ignore();
    getline(cin,who);
}

void EducationEquipment::print(const int orderNo) const
{
    if(orderNo==1)
    {
        cout<<"S.No"<<setw(11)<<"ID"<<setw(33)<<"Aciklama"<<setw(8)<<"Tarih"<<setw(22)<<"Kullanan"<<endl;
        cout<<"----  "<<"---------  "<<"-------------------------------  "<<"------  "<<"--------------------"<<endl;
    }

    cout<<setw(4)<<orderNo<<setw(11)<<eqID<<setw(33)<<desc<<setw(8)<<buyYear<<setw(22)<<who<<endl;
}

void EducationEquipment::detail() const
{
     cout<<"ID: "<<eqID<<"\nAciklama: "<<desc<<"\nAlinan yil: "<<buyYear<<"\nKullanan: "<<who<<endl;
}
