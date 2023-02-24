#include <iostream>
#include <sys/stat.h>
#include <cstring>

using namespace std;

int main(){
    char *yeniKlasorAdi = NULL; //Olusturulacak klasorun ismi aliniyor
    yeniKlasorAdi = new char[20];
    cout << "Kisinin Adini Giriniz: ";
    cin >> yeniKlasorAdi;

    const char *klasor = "/home/zeobora/Desktop/dataset/"; //Klasorun eklenecegi yer belirleniyor.

    size_t uzunluk1 = strlen(yeniKlasorAdi); //Olusturulacak klasorun adi olusturuluyor. Ornek: /home/zeobora/Desktop/dataset/yeniKlasor
    size_t uzunluk2 = strlen(klasor);
    char *kisininKlasoru = NULL;
    kisininKlasoru = new char[uzunluk1+uzunluk2+2];
    strncpy(kisininKlasoru, klasor, uzunluk2+1);
    strncat(kisininKlasoru, yeniKlasorAdi, uzunluk1+1);   

    struct stat sb; //Klasorun eklenecegi yerde, yeni olusturulacak klasorun isminde bir klasor bulunuyor mu kontrol ediliyor.
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