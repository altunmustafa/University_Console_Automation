#include "Person.h"

Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}

void Person::deletePerson()
{
    next->prev=prev;
    prev->next=next;
    delete this;
}
