#include "EquipmentDoublyLinkedList.h"

EquipmentDoublyLinkedList::EquipmentDoublyLinkedList()
{
}

EquipmentDoublyLinkedList::~EquipmentDoublyLinkedList()
{
}

EquipmentDoublyLinkedList::EquipmentDoublyLinkedList(const string type)
{
    noEduEq = FIRST_ID_NO;
    noLabEq = FIRST_ID_NO;

    this->TYPE = type;

    if(TYPE == "EducationEquipment")
    {
        TYPE_TR = "OGRETIM EKIPMANI";  //ekrana yazdirma islemlerinde kullanmak icin
        header  = new EducationEquipment();
        trailer = new EducationEquipment();
    }else
    if(TYPE == "LaboratoryEquipment")
    {
        TYPE_TR = "LABORATUAR EKIPMANI";
        header  = new LaboratoryEquipment();
        trailer = new LaboratoryEquipment();
    }else
    programmingError("EquipmentDoublyLinkedList sinifindan nesne olusturulurken tip belirten string parametre yanlis verildi.");

    header->next  = trailer;
    trailer->prev = header;
}

void EquipmentDoublyLinkedList::add(Person*)
{
    
}

void EquipmentDoublyLinkedList::add(Equipment* equipment)
{
    equipment->eqID=idCreator();

    equipment->next     = trailer;
    equipment->prev     = trailer->prev;
    trailer->prev->next = equipment;
    trailer->prev       = equipment;
}


void EquipmentDoublyLinkedList::print()
{
    if(empty_())
        cout<<"Sisteme kayitli hicbir "<<TYPE_TR<<" yok! \n\n";
    else
    {
        printTitle(TYPE_TR+" LISTESI");
        Equipment *active=header->next;
        int i;
        for(i=1;active!=trailer;++i)
        {
            active->print(i);
            active = active->next;
        }
        cout<<"\nToplam "<<i-1<<" "<<TYPE_TR<<" listelendi.\n\n";
    }
}


bool EquipmentDoublyLinkedList::empty_()
{
	return (header->next == trailer);
}

int EquipmentDoublyLinkedList::delete_(const string ID)
{
    Equipment *active=header->next;
    while(active->next != trailer)
    {
        if (active->eqID == ID)
        {
            active->deleteEq();
            //delete_(active);
            return 1;
        }
        active = active->next;
    }
    return 0;
}

int EquipmentDoublyLinkedList::delete_(const int no)
{

    Equipment *willDeleted = getEquipment(no);

    if(willDeleted != NULL)
    {
        willDeleted->deleteEq();
        return 1;
    }else
        return 0;
}

int EquipmentDoublyLinkedList::update(const string ID)
{
    Equipment *active=header->next;
    while(active!=trailer)
    {
        if (active->eqID == ID)
        {
            active->updateEq();
            return 1;
        }
        active = active->next;
    }
    return 0;
}


int EquipmentDoublyLinkedList::update(const int no)
{
    Equipment *wanted = getEquipment(no);
    if(wanted != NULL)
    {
        wanted->updateEq();
        return 1;
    }else
        return 0;

}

Equipment *EquipmentDoublyLinkedList::getEquipment(const string ID) const
{
    Equipment *active = header->next;
    while(active != trailer)
    {
        if (active->eqID == ID)
            return active;
        active = active->next;
    }
    return NULL;
}



Equipment *EquipmentDoublyLinkedList::getEquipment(const int no) const
{
    Equipment *active = header->next;
    int i;
    for(i=1 ; i<no && active!=trailer ; i++)
        active=active->next;

    if(active==trailer)
        return NULL;

    return active;
}

int EquipmentDoublyLinkedList::save(const char fileName[]) const
{

    ofstream write(fileName);

    Equipment *active = header->next;

    int saveCount;

    if(TYPE=="EducationEquipment")
    {
        for(saveCount=1 ; active!=trailer ; saveCount++)
        {
            write<<active->eqID<<" | "<<active->desc<<" | "<<active->who<<" | "<<active->buyYear<<endl;
            active = active->next;
            }
        }
    else if(TYPE=="LaboratoryEquipment")
    {
        for(saveCount=1 ; active!=trailer ; saveCount++)
        {
            write<<active->eqID<<" | "<<active->desc<<" | "<<active->buyYear<<" | "<<active->lifeTime<<" | "<<active->where<<" | "<<endl;
            active = active->next;
        }
    }
    write.close();
    return saveCount;
}

int EquipmentDoublyLinkedList::load(const char fileName[])
{
    string trash; // sayilar için ayrac konntolu yapilmayacagindan ayrac cope atilcak.

    ifstream read(fileName);

    Equipment *active;

    int loadCount;

    if(TYPE=="EducationEquipment")
    {
        string tempDesc, tempWho, tempYear;  //eklemeli okuma yapabilmek icin (bosluklari hesaba katmak icin)
        for(loadCount=1 ; read ; loadCount++)
        {
            active=new EducationEquipment();

            read>>active->eqID; //ID yi cek
            read>>trash;    // "|" isaretini cope at.

            while(read)
            {
                read>>tempDesc;     //aciklamayi cek
                if(tempDesc!="|")
                    active->desc+=tempDesc+" "; //ayrac isaretini gorene kadar okuduklarini aciklamaya ekle
                else break;
            }
            while(read)
            {
                read>>tempWho;      //kullanani cek
                if(tempWho!="|")
                    active->who+=tempWho+" ";    //ayrac isaretini gorene kadar okuduklarini kullanana ekle
                else break;
            }
            if(read)
            {
                read>>tempYear;     //yili cek (string)
                istringstream ( tempYear ) >> active->buyYear;  //yili int'e donustur
            }else break;

            add(active);
        }
    }
    else if(TYPE=="LaboratoryEquipment")
    {
        string tempDesc, tempYear, tempLifeTime, tempWhere;  //eklemeli okuma yapabilmek icin (bosluklari hesaba katmak icin)
        for(loadCount=1 ; read ; loadCount++)
        {
            active=new LaboratoryEquipment();

            read>>active->eqID; //ID yi cek
            read>>trash;    // "|" isaretini cope at.

            while(read)
            {
                read>>tempDesc;     //aciklamayi cek
                if(tempDesc!="|")
                    active->desc+=tempDesc+" "; //ayrac isaretini gorene kadar okuduklarini aciklamaya ekle
                else break;
            }

            if(read)
            {
                read>>tempYear;     //yili cek (string)
                istringstream ( tempYear ) >> active->buyYear;  //yili int'e donustur
            }else break;

            read>>trash;

            if(read)
            {
                read>>tempLifeTime;     //yili cek (string)
                istringstream ( tempLifeTime ) >> active->lifeTime;  //yasam omrunu int'e donustur
            }else break;

            read>>trash;

            while(read)
            {
                read>>tempWhere;      //lab adini cek
                if(tempWhere!="|")
                    active->where+=tempWhere+" ";    //ayrac isaretini gorene kadar okuduklarini lab adina ekle
                else break;
            }
            add(active);
        }
    }
    return loadCount;
}

string EquipmentDoublyLinkedList::idCreator()
{
    if(TYPE=="EducationEquipment")
    {
        stringstream no; //bu ve alttaki satır integer'ı string'e dönüştürmek için
        no<<noEduEq;
        string newID="edu"+no.str();
        noEduEq++;
        return newID;
    }else
    if(TYPE=="LaboratoryEquipment")
    {
        stringstream no;
        no<<noLabEq;
        string newID="lab"+no.str();
        noLabEq++;
        return newID;
    }else
        return "errorID";

}

void EquipmentDoublyLinkedList::create()
{
    if(TYPE=="EducationEquipment")
    {
        Equipment *equipment = new EducationEquipment();
        equipment->create();
        add(equipment);
    }else
    if(TYPE=="LaboratoryEquipment")
    {
        Equipment *equipment = new LaboratoryEquipment();
        equipment->create();
        add(equipment);
    }
}

int EquipmentDoublyLinkedList::getDetail(const int no) const
{
    if(getEquipment(no)!=NULL)
        getEquipment(no)->detail();
    else
        return 0;
}
/*
void EquipmentDoublyLinkedList::add(Person*)
{
    //kullanilmiyor
}

*/
