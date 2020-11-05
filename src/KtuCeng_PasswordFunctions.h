#ifndef KTUCENG_PASSWORDFUNCTIONS_H
#define KTUCENG_PASSWORDFUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

void passLock();

bool checkPass(const string);
bool checkPass();
bool editPass();

void newPage();
void setErrorEntry();
void setWrongPass();

void savePass(const string);
string getPass();

void updatePassDatabase(string,int);
void saveLastLockTime(const int);
int getLastLockTime();

int main();




#endif // KTUCENG_PASSWORDFUNCTIONS_H
