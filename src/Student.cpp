#include "Student.h"

Student::Student()
{
}

Student::~Student()
{
}

Student::Student(const string nameSurname,const int  startYear, const double gradeAve, const string callNumber)
{
    this->nameSurname   = nameSurname;
    this->startYear     = startYear;
    this->gradeAve      = gradeAve;
    this->callNumber    = callNumber;
}

void Student::create()
{
    cout<<"\nYeni ogrenci...\nAd Soyad: ";
    cin.ignore();
    getline(cin,nameSurname);
    cin.ignore();
    cout<<"Basladigi yil: ";
    cin>>startYear;
    cin.ignore();
    cout<<"Ortalama: ";
    cin>>gradeAve;
    cin.ignore();
    cout<<"Tel. No: ";
    getline(cin,callNumber);
}

void Student::updatePerson()
{
    cout<<"\nOgrenci kaydi guncelle...\nID: "<<ID<<"\nAd Soyad: ";
    cin.ignore();
    getline(cin,nameSurname);
    cout<<"Basladigi yil: ";
    cin>>startYear;
    cin.ignore();
    cout<<"Ortalama: ";
    cin>>gradeAve;
    cin.ignore();
    cout<<"Tel. No: ";
    getline(cin,callNumber);
}

void Student::print(const int orderNo) const
{
    if(orderNo==1)
    {
        cout<<"S.No"<<setw(10)<<"ID"<<setw(25)<<"Ad Soyad"<<setw(16)<<"Basladigi Yil"<<setw(22)<<"Ortalama"<<endl;
        cout<<"----  "<<"--------  "<<"-----------------------  "<<"--------------  "<<"--------------------"<<endl;
    }

    cout<<setw(4)<<orderNo<<setw(10)<<ID<<setw(25)<<nameSurname<<setw(16)<<startYear<<setw(22)<<gradeAve<<endl;

}

void Student::detail() const
{
    cout<<"ID: "<<ID<<"\nAd Soyad: "<<nameSurname<<"\nBasladigi yil: "<<startYear<<"\nOrtalama: "<<gradeAve<<"\nTel. No: "<<callNumber<<endl;
}

