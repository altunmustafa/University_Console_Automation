#ifndef KTUCENG_PERSON_H
#define KTUCENG_PERSON_H

#include <string>
using namespace std;

class KtuCeng_Person
{
    public:
        KtuCeng_Person();
        virtual ~KtuCeng_Person();
        virtual void printf()=0;

        void deletePerson();

    protected:
        string ID, nameSurname, status, callNumber, foreignLang;
        double gradeAve;
        int startYear;
    private:

};

#endif // KTUCENG_PERSON_H
