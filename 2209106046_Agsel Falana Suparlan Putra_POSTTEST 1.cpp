#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

using namespace std;

int main() {    
   int i;  
   string pass_input, user_input;       
   cout << "==========================================="<< endl;    
   cout << "|                 POSTTEST 1              |"<< endl;    
   cout << "==========================================="<< endl;  
   cout << "|        AGSEL FALANA SUPARLAN PUTRA      |"<< endl;  
   cout << "|             INFORMATIKA A'2022          |"<< endl;  
   cout << "|                 2209106046              |"<< endl;  
   cout << "===========================================\n"<< endl;
   cout << "Silahkan Login jika ingin menggunakan nya..\n";  
   cout << "===========================================\n"<< endl;
   string username ="agsel";    //variabel untuk username login
   string password = "46";    //variabel untuk password login
   string login = "block";    //variabel untuk login
   i = 1;    
   
   do {        
       cout << "Username = "; cin>>user_input;        
       cout << "Password = "; cin>>pass_input;        
       if (user_input == username && pass_input == password) {    
           cout << "\n==========================================="<< endl;    
           cout << "|              Login Berhasil             |" << endl;            
           cout << "===========================================\n"<< endl;       
           i = 4;
           login = "berhasil";        } 
       else {            
           cout << "\n=========================================="<< endl;            
           cout << "|  Username / Password Anda Salah!   |("<<i<<"x)"<< endl;
		   cout << "==========================================\n"<< endl;            
           i = i +1;
       }   
    } while (i <= 3);
	
    if(login != "berhasil"){
       cout<<"Anda telah 3x salah login.\n";       
       cout<<"Silahkan coba 40218 Hari lagi. Terima Kasih..\n"<< endl;  
       return 0;    
	}   
   char lagi;
   int kode,pilih;
   float Celcius, Fahrenheit, Kelvin, Reamur;
   awal:
//    system("cls");        
   cout << "===========================================" <<endl;  
   cout << "|         SILAHKAN KONVERSI SUHU          |" <<endl;    
   cout << "===========================================" <<endl;       
   cout << "|1. Celcius => Fahrenheit, Kelvin, Reamur |" <<endl;
   cout << "|2. Fahrenheit => Celcius, Kelvin, Reamur |" <<endl;
   cout << "|3. Kelvin => Celcius, Fahrenheit, Reamur |" <<endl;
   cout << "|4. Reamur => Celcius, Fahrenheit, Kelvin |" <<endl;
   cout << "===========================================\n";       
   cout<<endl;
   cout<<"Masukkan kode angka yang ingin dipilih = ";
   cin>>kode;
   switch (kode)
   {
    case 1:
            cout<<"Masukkan suhu dalam Celcius = ";
            cin>>Celcius;
            Fahrenheit=Celcius*1.8+32;
            Kelvin=Celcius*273.15;
            Reamur=Celcius*0.8;
            cout<<"Suhu dalam Fahrenheit = "<<Fahrenheit<<endl;
            cout<<"Suhu dalam Kelvin = "<<Kelvin<<endl;
            cout<<"Suhu dalam Reamur = "<<Reamur<<endl;
            break;
    case 2:
            cout<<"Masukkan suhu dalam Fahrenheit = ";
            cin>>Fahrenheit;
            Celcius=5*(Fahrenheit-32)/9;
            Kelvin=Celcius*273.15;
            Reamur=Celcius*0.8;
            cout<<"Suhu dalam Celcius = "<<Celcius<<endl;
            cout<<"Suhu dalam Kelvin = "<<Kelvin<<endl;
            cout<<"Suhu dalam Reamur = "<<Reamur<<endl;
            break;
    case 3:
            cout<<"Masukkan suhu dalam Kelvin = ";
            cin>>Kelvin;
            Celcius=Kelvin-273,15;
            Fahrenheit=Celcius*1.8+32;
            Reamur=Celcius*0.8;
            cout<<"Suhu dalam Fahrenheit = "<<Fahrenheit<<endl;
            cout<<"Suhu dalam Kelvin = "<<Kelvin<<endl;
            cout<<"Suhu dalam Reamur = "<<Reamur<<endl;
            break;
    case 4:
            cout<<"Masukkan suhu dalam Reamur = ";
            cin>>Reamur;
            Celcius=1.25*Reamur;
            Fahrenheit=Celcius*1.8+32;
            Kelvin=Celcius*273.15;
            cout<<"Suhu dalam Fahrenheit = "<<Fahrenheit<<endl;
            cout<<"Suhu dalam Kelvin = "<<Kelvin<<endl;
            cout<<"Suhu dalam Reamur = "<<Reamur<<endl;
            break;
            default:
        cout<<"Kode tersebut tidak ada dalam menu"<<endl;
    }
   cout << "-----------------------------------------------\n";    
    cout<<"Apakah anda ingin mengkonversi yang lain? (Y/N)";
    cin>>lagi;
        if (lagi=='y' || lagi=='Y'){
                goto awal;
        }
        if (lagi=='n' || lagi=='N'){
                goto selesai;
        }
    selesai:
        cout << "==================================================="<< endl;   
        cout << "|              PROGRAM TELAH SELESAI              |"<< endl;   
        cout << "==================================================="<< endl;   
        cout << "| TERIMAKASIH TELAH MENGGUNAKAN PROGRAM SEDERHANA |"<< endl;   
        cout << "|                YANG DISUSUN OLEH                |"<< endl;   
        cout << "|           AGSEL FALANA SUPARLAN PUTRA           |"<< endl;   
        cout << "|                INFORMATIKA A'22                 |"<< endl;   
        cout << "|                   2209106046                    |"<< endl;   
        cout << "==================================================="<< endl;   
    return 0;

}
