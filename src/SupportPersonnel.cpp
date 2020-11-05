#include "SupportPersonnel.h"

SupportPersonnel::SupportPersonnel()
{
}

SupportPersonnel::~SupportPersonnel()
{
}

SupportPersonnel::SupportPersonnel(const string nameSurname, const string callNumber, const int startYear)
{
    this->nameSurname   = nameSurname;
    this->callNumber    = callNumber;
    this->startYear     = startYear;
}

void SupportPersonnel::create()
{
    cout<<"\nYeni destek personel...\nAd Soyad: ";
    cin.ignore();
    getline(cin,nameSurname);
    cin.ignore();
    cout<<"Tel. No: ";
    getline(cin, callNumber);
    cin.ignore();
    cout<<"Basladigi yil: ";
    cin>>startYear;
}

void SupportPersonnel::updatePerson()
{
    cout<<"\nDestek personel kaydi guncelle...\nID: "<<ID<<"\nAd Soyad: ";
    cin.ignore();
    getline(cin,nameSurname);
    cin.ignore();
    cout<<"Tel. No: ";
    getline(cin, callNumber);
    cin.ignore();
    cout<<"Basladigi yil: ";
    cin>>startYear;
}

void SupportPersonnel::print(const int orderNo) const
{
    if(orderNo==1)
    {
        cout<<"S.No"<<setw(10)<<"ID"<<setw(30)<<"Ad Soyad"<<setw(18)<<"Tel. No"<<setw(16)<<"Basladigi yil"<<endl;
        cout<<"----  "<<"--------  "<<"----------------------------  "<<"----------------  "<<"--------------"<<endl;
    }

    cout<<setw(4)<<orderNo<<setw(10)<<ID<<setw(30)<<nameSurname<<setw(18)<<callNumber<<setw(16)<<startYear<<endl;

}

void SupportPersonnel::detail() const
{
    cout<<"ID: "<<ID<<"\nAd Soyad: "<<nameSurname<<"\nBasladigi yil: "<<startYear<<"\nTel. No: "<<callNumber<<endl;
}


