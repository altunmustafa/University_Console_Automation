#include <iostream>
#include <fstream>
#include "src/KtuCeng_ControlPanel.h"

#include <stdio.h>
#include <string>

#include "src/KtuCeng_PasswordFunctions.h"

#include "src/Staff.h"

#define EDU_EQ_FILE_ADRESS "db_edu_eq.dat"
#define LAB_EQ_FILE_ADRESS "db_lab_eq.dat"
#define STUDENT_FILE_ADRESS "db_stu.dat"
#define STAFF_FILE_ADRESS "db_sta.dat"
#define SUPPORT_FILE_ADRESS "db_sup.dat"

using namespace std;

EquipmentDoublyLinkedList *listEducationEquipment_main=new EquipmentDoublyLinkedList("EducationEquipment");
EquipmentDoublyLinkedList *listLaboratoryEquipment_main=new EquipmentDoublyLinkedList("LaboratoryEquipment");
PersonDoublyLinkedList *listStudent_main=new PersonDoublyLinkedList("Student");
PersonDoublyLinkedList *listStaff_main=new PersonDoublyLinkedList("Staff");
PersonDoublyLinkedList *listSupportPersonnel_main=new PersonDoublyLinkedList("SupportPersonnel");

bool modify=0;

void loadAllLists();
void saveAllFiles();
void startMenu();
void startupSetPass();
void modifyControl();

int main()
{
    startupSetPass();

    if(checkPass())
    {
        loadAllLists();;
        startMenu();
    }

    modifyControl();

    newPage("GULE GULE");
    cout<<"Developed by Mustafa Altun...\n\n";
    exit(0);
}


void loadAllLists()
{
    listEducationEquipment_main   ->load(EDU_EQ_FILE_ADRESS);
    listLaboratoryEquipment_main  ->load(LAB_EQ_FILE_ADRESS);
    listStudent_main              ->load(STUDENT_FILE_ADRESS);
    listStaff_main                ->load(STAFF_FILE_ADRESS);
    listSupportPersonnel_main     ->load(SUPPORT_FILE_ADRESS);

    modify=0;
}

void saveAllFiles()
{
    listEducationEquipment_main     ->save(EDU_EQ_FILE_ADRESS);
    listLaboratoryEquipment_main    ->save(LAB_EQ_FILE_ADRESS);
    listStaff_main                  ->save(STAFF_FILE_ADRESS);
    listStudent_main                ->save(STUDENT_FILE_ADRESS);
    listSupportPersonnel_main       ->save(SUPPORT_FILE_ADRESS);

    newPage("Tum degisiklikler kayit edildi.");
    cout<<"Dosyalarin ilk hallerinin yedekleri backupFiles klasoru icersindedir.";
    cin.get();
}

void startMenu()
{
    newPage("GIRIS");
    cout<<"1. Kontrol paneli\n2. Sifre degisikligi\n0. Cikis\n\n--> Secim(1/2/0): ";

    int tic;
    cin>>tic;
    cin.ignore();

    switch(tic)
    {
        case 1:
            KtuCeng_ControlPanel(listEducationEquipment_main,listLaboratoryEquipment_main,listStudent_main, listStaff_main, listSupportPersonnel_main);
            return;
        case 2:
            if(editPass())
            {
                setNewPageNotice("Sifre degistirildi.");
                startMenu();
            }
            else
            {
                setNewPageNotice("Sifre degistirme islemi basarisiz.");
                main();
            }
            return;
        default:
            setErrorEntry();
            startMenu();
    }
}

void setModifiy()   //Kontrol paneli icerisinde degisiklik yapildigi taktirde modifiy=1 olacak.
{
    modify=1;
}

void modifyControl()
{
    if(modify)
    {
        newPage("DIKKAT");
        cout<<"Kaydedilmemis degisiklikler var.\nKaydetmeden cikmak istediginizden emin misiniz?\n\n";
        cout<<"1. Kaydet\n2. Kaydetme\n3. Iptal\n\nSecim (1/2/3): ";

        int tic;
        cin>>tic;
        cin.ignore();

        switch(tic)
        {
            case 1:
                saveAllFiles();
                return;
            case 2:
                return;
            case 3:
                KtuCeng_ControlPanel(listEducationEquipment_main,listLaboratoryEquipment_main,listStudent_main, listStaff_main, listSupportPersonnel_main);
                modifyControl();
                return;
            default:
                setErrorEntry();
                modifyControl();
        }
    }
}
