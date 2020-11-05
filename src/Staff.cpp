#include "Staff.h"

Staff::Staff()
{
}

Staff::~Staff()
{
}

Staff::Staff(const string nameSurname, const string status, const string callNumber, const string foreignLang)
{
    this->nameSurname   = nameSurname;
    this->status        = status;
    this->callNumber    = callNumber;
    this->foreignLang   = foreignLang;
}

void Staff::create()
{
    cout<<"\nYeni ogretim gorevlisi...\nAd Soyad: ";
    cin.ignore();
    getline(cin,nameSurname);
    cin.ignore();
    cout<<"Unvan: ";
    getline(cin,status);
    cin.ignore();
    cout<<"Tel. No: ";
    getline(cin, callNumber);
    cin.ignore();
    cout<<"Yabanci diller: ";
    getline(cin,foreignLang);
}

void Staff::updatePerson()
{
    cout<<"\nOgretim gorevlisi kaydi guncelle...\nID: "<<ID<<"\nAd Soyad: ";
    //cin.ignore();
    getline(cin,nameSurname);
    //cin.ignore();
    cout<<"Unvan: ";
    getline(cin,status);
    //cin.ignore();
    cout<<"Tel. No: ";
    getline(cin, callNumber);
    //cin.ignore();
    cout<<"Yabanci diller: ";
    getline(cin,foreignLang);
}

void Staff::print(const int orderNo) const
{
    if(orderNo==1)
    {
        cout<<"S.No"<<setw(10)<<"ID"<<setw(25)<<"Ad Soyad"<<setw(16)<<"Unvan"<<setw(22)<<"Yabanci Diller"<<endl;
        cout<<"----  "<<"--------  "<<"-----------------------  "<<"--------------  "<<"--------------------"<<endl;
    }

    cout<<setw(4)<<orderNo<<setw(10)<<ID<<setw(25)<<nameSurname<<setw(16)<<status<<setw(22)<<foreignLang<<endl;

}

void Staff::detail() const
{
    cout<<"ID: "<<ID<<"\nAd Soyad: "<<nameSurname<<"\nUnvan: "<<status<<"\nYabanci Diller: "<<foreignLang<<"\nTel. No: "<<callNumber<<endl;
}
