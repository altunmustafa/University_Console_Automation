#include "LaboratoryEquipment.h"


time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int thisYear = aTime->tm_year + 1900;   // Bulunduğumuz yıl.(Ekipman ömrünün tükenip tekenmediğini sınamak için.)

LaboratoryEquipment::LaboratoryEquipment(const string description,const int bYear, const int lTime, const string labName)
{
    desc=description;
    buyYear=bYear;
    lifeTime=lTime;
    where=labName;
}

LaboratoryEquipment::LaboratoryEquipment()
{
    //newEquipment();
}
LaboratoryEquipment::~LaboratoryEquipment()
{
    //dtor
}

void LaboratoryEquipment::create()
{
    cout<<"\nYeni ekipman bilgilerini gir...\n"<<"Aciklama: ";
    getline(cin,desc);
    cin.clear();
    cout<<"Alinan yil: ";
    cin>>buyYear;
    cout<<"Yasam omru: ";
    cin>>lifeTime;
    cout<<"Bulundugu lab: ";
    cin.ignore();
    getline(cin,where);
}

void LaboratoryEquipment::updateEq()
{
    cout<<"\nEkipman guncelle...\nID: "<<eqID<<"\nAciklama: ";
    getline(cin,desc);
    cin.clear();
    cout<<"Alinan yil: ";
    cin>>buyYear;
    cout<<"Yasam omru: ";
    cin>>lifeTime;
    cout<<"Bulundugu lab: ";
    cin.ignore();
    getline(cin,where);
}

void LaboratoryEquipment::print(const int orderNo)const
{
    if(orderNo==1)
    {
        cout<<"S.No"<<setw(11)<<"ID"<<setw(32)<<"Aciklama"<<setw(9)<<"Tarih"<<setw(10)<<"Omru"<<setw(12)<<"Durumu"<<endl;
        cout<<"----  "<<"---------  "<<"------------------------------  "<<"-------  "<<"--------  "<<"----------"<<endl;
    }

    string available=(availability() ? "+":"-");
    cout<<setw(4)<<orderNo<<setw(11)<<eqID<<setw(32)<<desc<<setw(9)<<buyYear<<setw(6)<<lifeTime<<" Yil"<<setw(11)<<available<<endl;
}

int LaboratoryEquipment::availability() const
{
    if(thisYear-buyYear<=lifeTime)
        return 1;
    else
        return 0;
}

void LaboratoryEquipment::detail() const
{
    string available=(availability() ? "+":"-");
    cout<<"ID: "<<eqID<<"\nAciklama: "<<desc<<"\nAlinan yil: "<<buyYear<<"\nYasam omru: "<<lifeTime<<" Yil"<<"\nKullanilabilirlik: "<<available<<"\nBulundugu lab: "<<where<<endl;
}
