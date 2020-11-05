#include "PersonDoublyLinkedList.h"

PersonDoublyLinkedList::PersonDoublyLinkedList(const string type)
{
    noStaff=FIRST_ID_NO;
    noStudent=FIRST_ID_NO;
    noSupportPer=FIRST_ID_NO;

    this->TYPE=type;

    if(TYPE=="Student")
    {
        TYPE_TR="OGRENCI";  //ekrana yazdirma islemlerinde kullanmak icin
        header = new Student();
        trailer = new Student();
    }
    else if(TYPE=="Staff")
    {
        TYPE_TR="OGRETIM GOREVLISI";
        header = new Staff();
        trailer = new Staff();
    }
    else if(TYPE=="SupportPersonnel")
    {
        TYPE_TR="DESTEK PERSONEL";
        header = new SupportPersonnel();
        trailer = new SupportPersonnel();
    }else
    programmingError("PersonDoublyLinkedList sinifindan nesne olustururken verilen parametre yanlis.");

    header->next = trailer;
    trailer->prev = header;
}

PersonDoublyLinkedList::~PersonDoublyLinkedList()
{
    //dtor
}

void PersonDoublyLinkedList::add(Person* person)
{
    person->ID=idCreator();
    person->next=trailer;
    person->prev=trailer->prev;
    trailer->prev->next=person;
    trailer->prev=person;
}

void PersonDoublyLinkedList::print()
{
    if(empty_())
        cout<<"Sisteme kayitli hicbir "<<TYPE_TR<<" yok! \n\n";
    else
    {
        printTitle(TYPE_TR+" LISTESI");
        Person *active=header->next;
        int i;
        for(i=1;active!=trailer;++i)
        {
            active->print(i);
            active = active->next;
        }
        cout<<"\nToplam "<<i-1<<" "<<TYPE_TR<<" listelendi.\n\n";
    }
}

bool PersonDoublyLinkedList::empty_()
{
	return (header->next==trailer);
}

int PersonDoublyLinkedList::delete_(const string ID)
{
    Person *active=header->next;
    while(active->next!=trailer)
    {
        if (active->ID==ID)
        {
            active->deletePerson();
            //delete_(active);
            return 1;
        }
        active=active->next;
    }
    return 0;
}

int PersonDoublyLinkedList::delete_(const int no)
{

    Person *willDeleted=getPerson(no);

    if(willDeleted!=NULL)
    {
        willDeleted->deletePerson();
        return 1;
    }else
        return 0;
}

string PersonDoublyLinkedList::idCreator()
{

    if(TYPE=="Student")
    {
        stringstream no;
        no<<noStudent;
        string newID="stu"+no.str();
        noStudent++;
        return newID;
    }else
    if(TYPE=="Staff")
    {
        stringstream no;
        no<<noStaff;
        string newID="sta"+no.str();
        noStaff++;
        return newID;
    }else
    if(TYPE=="SupportPersonnel")
    {
        stringstream no;
        no<<noSupportPer;
        string newID="sup"+no.str();
        noSupportPer++;
        return newID;
    }else
    return "errorID";
}

Person *PersonDoublyLinkedList::getPerson(const string ID) const
{
    Person *active=header->next;
    while(active!=trailer)
    {
        if (active->ID==ID)
            return active;
        active=active->next;
    }
    return NULL;
}

Person *PersonDoublyLinkedList::getPerson(const int no) const
{
    Person *active=header->next;
    int i;
    for(i=1;i<no && active!=trailer;i++)
        active=active->next;

    if(active==trailer)
        return NULL;

    return active;
}

int PersonDoublyLinkedList::getDetail(const int no) const
{
    if(getPerson(no)!=NULL)
        getPerson(no)->detail();
    else
        return 0;
}

int PersonDoublyLinkedList::update(const string ID)
{
    Person *active=header->next;
    while(active!=trailer)
    {
        if (active->ID==ID)
        {
            active->updatePerson();
            return 1;
        }
        active=active->next;
    }
    return 0;
}
int PersonDoublyLinkedList::update(const int no)
{
    Person *wanted=getPerson(no);
    if(wanted!=NULL)
    {
        wanted->updatePerson();
        return 1;
    }else
        return 0;
}

int PersonDoublyLinkedList::save(const char fileName[] ) const
{
    ofstream write(fileName);

    Person *active=header->next;

    int saveCount;

    if(TYPE=="Student")
    {
        for(saveCount=1 ; active!=trailer ; saveCount++)
        {
            write<<active->ID<<" | "<<active->nameSurname<<" | "<<active->startYear<<" | "<<active->gradeAve<<" | "<<active->callNumber<<" | "<<endl;
            active=active->next;
        }
    }
    else if(TYPE=="Staff")
    {
        for(saveCount=1 ; active!=trailer ; saveCount++)
        {
            write<<active->ID<<" | "<<active->nameSurname<<" | "<<active->status<<" | "<<active->callNumber<<" | "<<active->foreignLang<<" | "<<endl;
            active=active->next;
        }
    }
    else if(TYPE=="SupportPersonnel")
    {
        for(saveCount=1 ; active!=trailer ; saveCount++)
        {
            write<<active->ID<<" | "<<active->nameSurname<<" | "<<active->callNumber<<" | "<<active->startYear<<" | "<<endl;
            active=active->next;
        }
    }
    write.close();
    return saveCount;
}

int PersonDoublyLinkedList::load(const char fileName[] )
{
    string trash; // sayilar için ayrac konntolu yapilmayacagindan ayrac cope atilcak.

    ifstream read(fileName);

    Person *active;

    int loadCount;

    if(TYPE=="Student")
    {
        string tempNameSurname, tempCallNumber, tempYear, tempAve;  //eklemeli okuma yapabilmek icin (bosluklari hesaba katmak icin)
        for(loadCount=1 ; read ; loadCount++)
        {
            active=new Student();

            read>>active->ID; //ID yi cek
            read>>trash;    // "|" isaretini cope at.

            while(read)
            {
                read>>tempNameSurname;     //ad soyadi cek
                if(tempNameSurname!="|")
                    active->nameSurname+=tempNameSurname+" "; //ayrac isaretini gorene kadar okuduklarini ekle

                else break;
            }

            if(read)
            {
                read>>tempYear;     //yili cek (string)
                istringstream ( tempYear ) >> active->startYear;  //yili int'e donustur
            }else break;

            read>>trash;    // "|" isaretini cope at.

            if(read)
            {
                read>>tempAve;     //ortalamayi cek (string)
                istringstream ( tempAve ) >> active->gradeAve;  //ortalamayi int'e donustur
            }else break;

            read>>trash;    // "|" isaretini cope at.

            while(read)
            {
                read>>tempCallNumber;      //numarayi  cek
                if(tempCallNumber!="|")
                    active->callNumber+=tempCallNumber+" ";    //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }
            add(active);
        }
    }
    else if(TYPE=="Staff")
    {
        string tempNameSurname, tempStatus, tempCallNumber, tempForeignLang;  //eklemeli okuma yapabilmek icin (bosluklari hesaba katmak icin)
        for(loadCount=1 ; read ; loadCount++)
        {
            active=new Staff();

            read>>active->ID; //ID yi cek

            if(!read)
                break;

            read>>trash;    // "|" isaretini cope at.

            while(read)
            {
                read>>tempNameSurname;     //ad soyadi cek
                if(tempNameSurname!="|")
                    active->nameSurname+=tempNameSurname+" "; //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }

            while(read)
            {
                read>>tempStatus;      //unvani  cek
                if(tempStatus!="|")
                    active->status+=tempStatus+" ";    //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }

            while(read)
            {
                read>>tempCallNumber;      //numarayi  cek
                if(tempCallNumber!="|")
                    active->callNumber+=tempCallNumber+" ";    //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }

            while(read)
            {
                read>>tempForeignLang;      //yabanci dilleri  cek
                if(tempForeignLang!="|")
                    active->foreignLang+=tempForeignLang+" ";    //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }

            add(active);
        }
    }
    else if(TYPE=="SupportPersonnel")
    {
        string tempNameSurname, tempYear, tempCallNumber;  //eklemeli okuma yapabilmek icin (bosluklari hesaba katmak icin)
        for(loadCount=1 ; read ; loadCount++)
        {
            active=new SupportPersonnel();

            read>>active->ID; //ID yi cek
            read>>trash;    // "|" isaretini cope at.

            while(read)
            {
                read>>tempNameSurname;     //ad soyadi cek
                if(tempNameSurname!="|")
                    active->nameSurname+=tempNameSurname+" "; //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }

            while(read)
            {
                read>>tempCallNumber;      //numarayi  cek
                if(tempCallNumber!="|")
                    active->callNumber+=tempCallNumber+" ";    //ayrac isaretini gorene kadar okuduklarini ekle
                else break;
            }

            if(read)
            {
                read>>tempYear;     //yili cek (string)
                istringstream ( tempYear ) >> active->startYear;  //yili int'e donustur
            }else break;

            read>>trash;    // "|" isaretini cope at.

            add(active);
        }
    }

    return loadCount;
}

void PersonDoublyLinkedList::add(Equipment*)
{

}

void PersonDoublyLinkedList::create()
{
    if(TYPE=="Student")
    {
        Person *person = new Student();
        person->create();
        add(person);
    }else
    if(TYPE=="Staff")
    {
        Person *person = new Staff();
        person->create();
        add(person);
    }else
    if(TYPE=="SupportPersonnel")
    {
        Person *person = new SupportPersonnel();
        person->create();
        add(person);
    }
}






