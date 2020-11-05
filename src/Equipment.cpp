#include "Equipment.h"

Equipment::Equipment()
{
    next = NULL;
    prev = NULL;
}

Equipment::~Equipment()
{

}

void Equipment::deleteEq()
{
    next->prev = prev;
    prev->next = next;
    delete this;
}
