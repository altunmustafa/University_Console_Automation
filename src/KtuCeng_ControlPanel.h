#ifndef KTUCENG_CONTROLPANEL_H
#define KTUCENG_CONTROLPANEL_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "EquipmentDoublyLinkedList.h"
#include "PersonDoublyLinkedList.h"

#include <cstdlib>

using namespace std;

//from main
void setErrorQuit();

void KtuCeng_ControlPanel(EquipmentDoublyLinkedList *,EquipmentDoublyLinkedList *,PersonDoublyLinkedList *,PersonDoublyLinkedList *, PersonDoublyLinkedList *);

void mainMenu();

void menuEquipment();
void menuPerson();
void menuEducationEquipment();
void menuLaboratoryEquipment();
void menuStudent();
void menuStaff();
void menuSupportPersonnel();

void backMenu();
void againMenu();

void setErrorEntry();
void setWrongPass();
void setNewPageNotice(const string);

void newPage();
void newPage(const string);
void programmingError(const string);

void newEducationEquipment(const string,const int, const string,EquipmentDoublyLinkedList *);
void newLaboratoryEquipment(const string,const int, const int, const string, EquipmentDoublyLinkedList *);
void newStudent(const string, const int, const double, const string, PersonDoublyLinkedList *);
void newStaff(const string, const string, const string, const string, PersonDoublyLinkedList *);
void newSupportPersonnel(const string, const string, const int, PersonDoublyLinkedList *);

void createPerson();

void printTitle(const string);

void selectForPersons();

void createObject();
void menuDeleteObject();
void updateObject();
void deleteObject();

void selectForObjects();

void getDetailObject();

void setModifiy();


#endif // KTUCENG_CONTROLPANEL_H
