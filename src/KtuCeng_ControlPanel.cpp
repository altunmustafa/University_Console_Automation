#include "KtuCeng_ControlPanel.h"


Equipment *equipment;
Person    *person;

DoublyLinkedList *activeList;

EquipmentDoublyLinkedList *listEducationEquipment;
EquipmentDoublyLinkedList *listLaboratoryEquipment;
PersonDoublyLinkedList    *listStudent;
PersonDoublyLinkedList    *listStaff;
PersonDoublyLinkedList    *listSupportPersonnel;

string TYPE; // menu icinde hangi sinifla islem yapilacagina karar vermek icin
string BACK; // geriye dönülecek menuye karar vermek icin

int pageNo=1;
bool errorEntry=0;          // newPage() fonksiyonunda "hatalı giriş" uyarısı yapıp yapmayacağına karar verir.
bool wrongPass=0;           // newPage() fonksiyonunda "yanlis sifre" uyarısı yapıp yapmayacağına karar verir.
string NOTICE="";   // newPage() fonksiyonunda ozel mesaj yayinlar. Her yeni sayfada sifirlanir.

void KtuCeng_ControlPanel(EquipmentDoublyLinkedList *listEducationEquipment_,EquipmentDoublyLinkedList *listLaboratoryEquipment_,PersonDoublyLinkedList *listStudent_,PersonDoublyLinkedList *listStaff_, PersonDoublyLinkedList *listSupportPersonnel_)
{
    listEducationEquipment  = listEducationEquipment_;
    listLaboratoryEquipment = listLaboratoryEquipment_;
    listStudent             = listStudent_;
    listStaff               = listStaff_;
    listSupportPersonnel    = listSupportPersonnel_;

    mainMenu();
}

void mainMenu()
{
    newPage("ANA SAYFA");
    cout<<"1. Ekipman Sayfasi\n2. Kisi Sayfasi\n3. Tüm ekipman ve kisileri listele\n\n0. Çıkış\n\n-->Giriş (1/2/3/0): ";

    int tic;
    cin>>tic;
    cin.ignore();

    switch(tic)
    {
        case 1:
            menuEquipment();
            return;
        case 2:
            menuPerson();
            return;
        case 3:
            listEducationEquipment  ->print();
            listLaboratoryEquipment ->print();
            listStudent             ->print();
            listStaff               ->print();
            listSupportPersonnel    ->print();
            cin.get();
            againMenu();
            return;
        case 0:
            return;
        default:
            errorEntry=1;
            mainMenu();
    }
}

void menuEquipment()
{
    TYPE="EQUIPMENT";
    BACK="MAIN";

    newPage("EKIPMAN SAYFASI");
    cout<<"1. Ogretim Ekipmanlari\n2. Laboratuar Ekipmanlari\n3. Tum ekipmanlari listele.\n\n0. Geri(Anasayfa)\n\n-->Secim(1/2/3/0): ";

    int tic;
    cin>>tic;
    cin.ignore();

    switch(tic)
    {
        case 1:
            menuEducationEquipment();
            return;
        case 2:
            menuLaboratoryEquipment();
            return;
        case 3:
            listEducationEquipment  ->print();
            listLaboratoryEquipment ->print();
            cin.get();
            againMenu();
            return;
        case 0:
            mainMenu();
            return;
        default:
            errorEntry=1;
            againMenu();
            return;
    }
}

void menuPerson()
{
    TYPE="PERSON";
    BACK="MAIN";

    newPage("KISI SAYFASI");
    cout<<"1. Ogreciler\n2. Ogretim Gorevlileri\n3. Destek Personel\n4. Tüm kisileri listele\n0. Geri\n-->Secim(1/2/3/4/0): ";

    int tic;
    cin>>tic;
    cin.ignore();

    switch(tic)
    {
        case 1:
            menuStudent();
            return;
        case 2:
            menuStaff();
            return;
        case 3:
            menuSupportPersonnel();
            return;
        case 4:
            listStudent          ->print();
            listStaff            ->print();
            listSupportPersonnel ->print();
            cin.get();
            againMenu();
            return;

        case 0:
            mainMenu();
            return;
        default:
            errorEntry=1;
            againMenu();
            return;

    }
}

void menuEducationEquipment()
{
    activeList=listEducationEquipment;

    TYPE="EducationEquipment";
    BACK="Equipment";

    newPage("OGRETIM EKIPMANLARI SAYFASI");
    //cout<<"-----Ogretim Ekipmanlari Sayfasi-----\n";

    selectForObjects();

}

void menuLaboratoryEquipment()
{
    activeList=listLaboratoryEquipment;

    TYPE="LaboratoryEquipment";
    BACK="Equipment";

    newPage("LABORATUAR EKIPMANLARI SAYFASI");
    //cout<<"-----Laboratuar Ekipmanlari Sayfasi-----\n";

    selectForObjects();
}

void menuStudent()
{
    activeList=listStudent;

    TYPE="Student";
    BACK="Person";

    newPage("OGRENCILER SAYFASI");
    //cout<<"-----Ogrenciler Sayfasi-----\n";

    selectForObjects();
}

void menuStaff()
{
    activeList=listStaff;

    TYPE="Staff";
    BACK="Person";

    newPage("OGRETIM GOREVLILERI SAYFASI");
    //cout<<"-----Ogretim Gorevlileri Sayfasi-----\n";

    selectForObjects();
}

void menuSupportPersonnel()
{
    activeList=listSupportPersonnel;

    TYPE="SupportPersonnel";
    BACK="Person";

    newPage("DESTEK PERSONELLERI SAYFASI");
    //cout<<"-----Destek Personelleri Sayfasi-----\n";

    selectForObjects();
}

void selectForObjects()
{
    cout<<"1. Tumunu listele\n2. Yeni kayit\n3. Kayit sil\n4. Kayit güncelle\n5. Kayit detay bilgisi\n\n9. Anasayfa\n0. Geri\n\n-->Secim(1/2/3/4/5/9/0): ";
    int tic;
    cin>>tic;
    cin.ignore();

    switch(tic)
    {
        case 1:
            newPage();
            activeList->print();
            cout<<"Devam etmek icin enter'a basin.";
            cin.get();
            againMenu();
            return;
        case 2:
            createObject();
            againMenu();
            return;
        case 3:
            deleteObject();
            return;
        case 4:
            updateObject();
            return;
        case 5:
            getDetailObject();
            return;
        case 9:
            mainMenu();
            return;
        case 0:
            backMenu();
            return;
        default:
            errorEntry=1;
            againMenu();
    }
}

void createObject() //Kullanici etkilesimli nesne uretir.
{
    newPage("YENI KAYIT");
    activeList->create();
    setNewPageNotice("Kayit sisteme kaydedildi.");
    setModifiy();

    againMenu();
}

void getDetailObject()
{
    BACK=TYPE;  //geri dönecegi menu oradan geldigi tip

    tryagain:   //secim basarisizsa buraya dönecek
    newPage("Detayini gormek istediginiz kaydi nasil belirleyeceksiniz?");
    cout<<"1. ID'ye gore\n2. Listeden secerek\n9. Anasayfa\n0. Geri\n\n-->Secim(1/2/9/0): ";

    int tic;
    cin>>tic;
    cin.ignore();

    int confirm;
    string getDetailID;
    int getDetailNo;

    continueDetail: // islem basariliysa islem sonunda tekrar buraya donecek
    switch(tic)
    {
        case 1: //IDye gore
        {
            newPage();
            cout<<"Detayini istediginiz kaydin ID'sini girin (İptal=0): ";
            cin>>getDetailID;

            if(getDetailID=="0")
            {
                backMenu();
                return;
            }
            newPage("Kayit Bilgisi");
            if(activeList->getDetail(getDetailNo)==0)
                cout<<"Kayit bulunamadi!";

            cin.ignore();
            cin.get();
            break;
        }
        case 2: //Sira namarasina gore
            newPage();
            activeList->print();
            cout<<"Detayini istediginiz kaydin sira numarasini girin (İptal=0): ";

            cin>>getDetailNo;

            if(getDetailNo==0)
            {
                backMenu();
                return;
            }
            newPage("Kayit Bilgisi");
            if(activeList->getDetail(getDetailNo)==0)
                cout<<"Kayit bulunamadi!";

            cin.ignore();
            cin.get();
            break;
        case 9:
            mainMenu();
            return;
        case 0:
            backMenu();
            return;
        default:
            errorEntry=1;
            goto tryagain;
    }
    goto continueDetail;
}


void deleteObject()
{
    BACK=TYPE;

    tryagain:   //secim basarisizsa buraya dönecek
    newPage("Sileceginiz kaydi nasil belirlemek istersiniz?");
    cout<<"1. ID'ye gore\n2. Listeden secerek\n9. Anasayfa\n0. Geri\n\n-->Secim(1/2/9/0): ";

    int tic;
    cin>>tic;
    cin.ignore();

    int confirm;

    continueDelete: // silme islemi basariliysa islem sonunda tekrar buraya donecek
    switch(tic)
    {
        case 1: //IDye gore
        {
            newPage();
            cout<<"Silinecek kaydin ID'sini girin (İptal=0): ";
            string willDeletedID;
            cin>>willDeletedID;

            if(willDeletedID=="0")
            {
                backMenu();
                return;
            }

            confirm=activeList->delete_(willDeletedID);
            break;
        }
        case 2: //Sira namarasina gore
            newPage();
            activeList->print();
            cout<<"Silinecek kaydin sira numarasini girin (İptal=0): ";
            int willDeletedNo;
            cin>>willDeletedNo;

            if(willDeletedNo==0)
            {
                backMenu();
                return;
            }

            confirm=activeList->delete_(willDeletedNo);
            break;
        case 9:
            mainMenu();
            return;
        case 0:
            backMenu();
            return;
        default:
            errorEntry=1;
            goto tryagain;
    }

    if(confirm==1)
    {
        newPage("Basarili... Kayit silindi. Silme islemine davam edebilirsiniz.");
        setModifiy();
    }else
        newPage("Basarisiz!!! Kayit bulunamadi. Tekrar deneyin.");

    cin.ignore();
    cin.get();

    goto continueDelete;
}

void updateObject()
{
    BACK=TYPE;

    tryagain:   //secim basarisizsa buraya donecek.
    newPage("Guncellenecek kaydi nasil belirlemek istersiniz?");
    cout<<"1. ID'ye gore\n2. Listeden secerek\n9. Anasayfa\n0. Geri\n\n-->Secim(1/2/9/0): ";

    int tic;
    cin>>tic;

    int confirm;
    continueUpdate: //guncelleme basariliysa buraya donup yeni bir guncelleme baslayacak.
    switch (tic)
    {
        case 1: //ID'ye gore guncelle
        {
            newPage();
            cout<<"Guncellenecek kaydin ID'sini girin (Iptal=0): ";
            string willUpdatedID;
            cin>>willUpdatedID;
            cin.ignore();
            if(willUpdatedID=="0")
            {
                backMenu();
                return;
            }
            confirm=activeList->update(willUpdatedID);
            break;
        }
        case 2: //Sira numarasina gore guncelle
        {
            newPage();
            activeList->print();
            cout<<"Guncellenecek kaydin sira numarasini girin (İptal=0): ";
            int willUpdated;
            cin>>willUpdated;
            cin.ignore();
            if(willUpdated==0)
            {
                backMenu();
                return;
            }
            confirm=activeList->update(willUpdated);
            break;
        }
        case 9:
            mainMenu();
            return;

        case 0:
            backMenu();
            return;

        default:
            errorEntry=1;
            goto tryagain;
    }

    if(confirm==1)
    {
        newPage("Basarili... Guncelleme islemine devam edebilirsiniz.");
        setModifiy();
    }else
        newPage("Basarisiz!!! Kayit bulunamadi. Tekrar deneyin.");

    cin.get();

    goto continueUpdate;
}

void backMenu()
{
    if(BACK=="Main")
        mainMenu();
    else if(BACK=="Equipment")
        menuEquipment();
    else if(BACK=="Person")
        menuPerson();
    else if(BACK=="EducationEquipment")
        menuEducationEquipment();
    else if(BACK=="LaboratoyEquipment")
        menuLaboratoryEquipment();
    else if(BACK=="Student")
        menuStudent();
    else if(BACK=="Staff")
        menuStaff();
    else if(BACK=="SupportPersonnel")
        menuSupportPersonnel();
}

void againMenu()
{
    BACK=TYPE;
    backMenu();
}



//  BUNLAR MANUEL NESNE URETMEK ICIN
void newLaboratoryEquipment(const string description,const int buyYear, const int lifeTime, const string labName, EquipmentDoublyLinkedList *doublyLinkedList)
{
    Equipment *laboratoryEquipment=new LaboratoryEquipment(description,buyYear,lifeTime,labName);
    doublyLinkedList->add(laboratoryEquipment);
}

void newEducationEquipment(const string description,const int buyYear, const string debitStaffID, EquipmentDoublyLinkedList *doublyLinkedList)
{
    equipment=new EducationEquipment(description,buyYear,debitStaffID);
    doublyLinkedList->add(equipment);
}

void newStudent(const string nameSurname, const int startYear, const double gradeAve, const string callNumber, PersonDoublyLinkedList *doublyLinkedList)
{
    person=new Student(nameSurname,startYear,gradeAve,callNumber);
    doublyLinkedList->add(person);
}

void newStaff(const string nameSurname, const string status, const string callNumber, const string foreignLang, PersonDoublyLinkedList *doublyLinkedList)
{
    person=new Staff(nameSurname,status,callNumber,foreignLang);
    doublyLinkedList->add(person);
}

void newSupportPersonnel(const string nameSurname, const string callNumber, const int startYear, PersonDoublyLinkedList *doublyLinkedList)
{
    person=new SupportPersonnel(nameSurname,callNumber,startYear);
    doublyLinkedList->add(person);
}



void programmingError(const string message)
{
    newPage();
    cout<<"\n|||||||||||||||||||||||||PROGRAMMING ERROR|||||||||||||||||||||||||||||||||||\n";
    cout<<"Bu mesaj programci tarafindan olusturulmustur. Derleyicinin tespit edemeyecegi ve herhangi bir hata mesaji yayinlayamayacagi ama programin akisini tehlikeli sekilde bozabilecek bir hatayi tespit etmek icindir. ";
    cout<<"Bu mesajla karsilastiysaniz programin gelistiricisiyle irtibata geciniz.\n";
    cout<<"Ayrinti: "<<message<<endl;
    cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    cin.get();
}

void newPage()
{
    newPage("");
}

void newPage(const string title)
{
    system("cls");

    cout<<"\n                          KARADENIZ TEKNIK UNIVERSITESI\n";
    cout<<"                             BILGISAYAR MUHENDISLIGI\n\n";

    if(errorEntry)
    {
        cout<<"UYARI: Hatali secim. Tekrar deneyin.\n";
        errorEntry=0;
    }else if(wrongPass)
    {
        cout<<"UYARI: Yanlis sifre. Tekrar deneyin.\n";
        wrongPass=0;
    }else if(NOTICE!="")
    {
        cout<<NOTICE<<endl;
        NOTICE="";
    }else
        cout<<"##############################################################################\n";

    cout<<"#################################################################Sayfa no: "<<setw(3)<<pageNo<<"\n\n";

    pageNo++;

    printTitle(title);

}

void printTitle(const string title)
{
    if(title!="")
    {
        int charCount=0;
        while(title[charCount]!=NULL)
            charCount++;

        cout<<title<<endl;

        while(charCount>0)
        {
            cout<<"-";
            charCount--;
        }
        cout<<endl;
    }
}

void setNewPageNotice(const string notice)
{
    NOTICE=notice;
}

void setErrorEntry()
{
    errorEntry=1;
}

void setWrongPass()
{
    wrongPass=1;
}
