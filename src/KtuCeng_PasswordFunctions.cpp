#include "KtuCeng_PasswordFunctions.h"

#define LOCKTIME 30     // sifre üst üste yanlis girildiginde kilitlenme süresi
#define TRYCOUNT 5      // kilitlenme icin gereken yanlis sifre sayisi

//string password;


char passAdress[13]="password.dat";
ofstream writeFile;
ifstream readFile;


bool checkPass()
{
    return checkPass("");
}

bool checkPass(const string message)
{
    if(getLastLockTime()+LOCKTIME>time(0))
    {
        newPage();
        cout<<"                              PROGRAM KILITLI!!!\n\n";
        cout<<"Kilidin kalkmasi icin kalan sure: "<<getLastLockTime()+LOCKTIME-time(0)<<" saniye.\n\n";
        cin.get();
        return 0;
    }else
    {
        string enteredPass;
        int i;
        for(i=0;i<TRYCOUNT;i++)
        {
            newPage();

            if(message!="" && i==0)
                cout<<message<<"\n\n";

            if(i!=0)
                cout<<"Kalan deneme sayisi: "<<TRYCOUNT-i<<"\n\n";

            cout<<"--> Sifre (Cikis=0):";
            getline(cin,enteredPass);
            if(enteredPass==getPass())
                return 1;
            else if(enteredPass=="0")
                return 0;
            else if(i!=4)           //Ekran duzeni icin. Son yanlis girisden sonraki sayfanin üstünde "hatali sifre tekrar deneyin" ...
                setWrongPass();     //...yazmayacagı icin setWrongPass() yapmiyor. Çünkü program kilitlenmistir uyarisi verecek.
        }

        newPage();
        passLock();

        return 0;
    }
}



void passLock()
{
    int nowTime=time(0);
    string pass=getPass();
    updatePassDatabase(pass,nowTime);

    cout<<"PROGRAM KILITLENDI!\n\n";
    cout<<TRYCOUNT<<" defa ust uste yanlis sifre girildi."<<LOCKTIME<<" saniye boyunca giris yapamayacaksiniz.\n\n";
    cin.get();
}

bool editPass()
{
    if(checkPass("Eski sifrenizi girin."))
    {
        pointNewPass:   //Yeni sifre uygun olmayan karakter iceriyorsa tekrar bu noktaya donmek icin.
        cout<<"Yeni sifreyi girin: ";
        string enteredPass;
        getline(cin,enteredPass);

        int i;
        for(i=0;enteredPass[i]!=NULL;i++)
        {
            if(enteredPass[i]==' ')
            {
                cout<<"\nUYARI: Sifre bosluk iceremez !!! Tekrar deneyin.\n";
                goto pointNewPass;
            }
        }

        savePass(enteredPass);
        return 1;

    }else
    {
        cout<<"\nSifre değistirme islemi basarisiz.\n";
        return 0;
    }
}

void savePass(const string newPass)
{
    int lockTime=getLastLockTime();
    updatePassDatabase(newPass,lockTime);

}

void updatePassDatabase(string pass,int lockTime)
{
    writeFile.open(passAdress);
    writeFile<<pass<<" | "<<lockTime;
    writeFile.close();
}

int startupSetPass()
{

    if(getPass()=="")
    {
        cout<<"Sifre belirlenmemis veya tutuldugu dosya bulanamiyor. Bir sifre belirleyin.\n";
        pointNewPass:
        cout<<"Yeni sifreyi girin: ";
        string enteredPass;
        getline(cin,enteredPass);

        int i;
        for(i=0;enteredPass[i]!=NULL;i++)
        {
            if(enteredPass[i]==' ')
            {
                cout<<"\nUYARI: Sifre bosluk icermemeli !!! Tekrar deneyin.\n";
                goto pointNewPass;
            }
        }

        savePass(enteredPass);
        return 1;

    }
}

string getPass()
{
    readFile.open(passAdress);
    string pass;

    if(readFile)
        readFile>>pass;

    readFile.close();

    if(pass=="|" || pass=="")
        return "";
    else
        return pass;

}

int getLastLockTime()
{
    readFile.open(passAdress);
    int i,lockTime;
    string temp;


    for(i=0;i<3 && readFile;i++)    // Dosyada ucuncu okunacak veri konumunda
    {
        if(readFile)
            readFile>>temp;
        else
        {
            readFile.close();
            return 0;
        }
    }

    istringstream(temp)>>lockTime;
    readFile.close();
    return lockTime;
}

void saveLastLockTime(const int lockTime)
{
    writeFile.open(passAdress);
    string pass=getPass();
    writeFile<<pass<<" "<<lockTime;
    writeFile.close();

}


