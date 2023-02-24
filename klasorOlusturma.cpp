#include <iostream>
#include <sys/stat.h>
#include <cstring>

using namespace std;

int main(){
    //Klasor Olusturma

    struct stat sb;
    char *yeniKlasorAdi = NULL;
    yeniKlasorAdi = new char[20];
    cout << "Kisinin Adini Giriniz: ";
    cin >> yeniKlasorAdi;

    const char *klasor = "/home/zeobora/Desktop/dataset/";
    size_t uzunluk1 = strlen(yeniKlasorAdi);
    size_t uzunluk2 = strlen(klasor);
    char *kisininKlasoru = NULL;
    kisininKlasoru = new char[uzunluk1+uzunluk2+2];
    strncpy(kisininKlasoru, klasor, uzunluk2+1);
    strncat(kisininKlasoru, yeniKlasorAdi, uzunluk1+1);   

    if (stat (kisininKlasoru, &sb) == 0){
        cout << "Bu Isimde Klasor Daha Once Olusturulmus!" << endl;
    }
    else{
        cout << "Yeni Klasor Olusturuluyor!" << endl;
        cout << kisininKlasoru << endl;
        if (mkdir(kisininKlasoru, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0){ 
            cout << "Klasor Basariyla Olusturuldu!" << endl;
        }
        else{
            cout << "Klasor Olusturulamadi!" << endl;
        }
    }
    delete yeniKlasorAdi;
    delete kisininKlasoru;
    return 0;
}