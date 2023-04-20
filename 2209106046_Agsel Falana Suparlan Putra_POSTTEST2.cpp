#include <iostream>

//setiap variabel i untuk indeks dan looping

using namespace std;

string datamahasiswa[100] = {"Dimas 2209106027 ", "Yoga 2209106028"};
void lihat(){
    string *p = &datamahasiswa[0];  // pointer buat akses array
    cout<<""<<endl;
    if(*p == ""){
        cout << "Data tersebut tidak ada"<<endl;
    }
    else {
        for (int i=0; 1<100; i++){
            if (*p == ""){
                break;
            }
        cout<< 1+i << ". "<<*p<< endl;
        p++;
        }
    }
}

void ubah(){
    cout<<""<<endl;
    lihat();

    int target; //variabel pilihan yg mau diubah
    string namabaru; //variabel nama baru
    cout<<""<<endl;
    cout<<"Masukkan kode angka yang ingin diubah datanya : "; cin>>target;cin.ignore();
    cout<<"Masukkan Nama dan Nim baru : "; getline(cin, namabaru);

    datamahasiswa[target-1] = namabaru;
    lihat();
    }

void tambah(){
    string namamahasiswa; //variabel nama
    lihat();
    cout<<""<<endl;
    cin.ignore();
    cout<<"Masukkan Nama dan Nim Mahasiswa : "; getline(cin, namamahasiswa);
    
    int index=0;
    for (int i=0; i<100; i++){
        if (datamahasiswa[i] == ""){
            index = 1;
            break;
        }
    }
}

void hapus(){
    cout<<""<<endl;
    lihat();

    int target; // variabel yg ingin dihapus
    cin.ignore();
    cout<<"Masukkan kode angka yang ingin dihapus: "; cin>>target; 

    for (int i=target-1; i<100; i++ ){
        if (datamahasiswa[i] == ""){
            break;
        }
        datamahasiswa[i] = datamahasiswa[i+1];
    }
}


int main(){
   int i;  
   string pass_input, user_input;       
   cout << "==========================================="<< endl;    
   cout << "|                 POSTTEST 2              |"<< endl;    
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
    int kode, pilih;
    awal:
    cout<<"=================================================="<<endl;
    cout<<"|          SELAMAT DATANG DI POSTTEST 2          |"<<endl;
    cout<<"|================================================="<<endl;
    cout<<"| [1] Lihat data mahasiswa                       |"<<endl;
    cout<<"| [2] Ubah data mahasiswa                        |"<<endl;
    cout<<"| [3] Hapus data mahasiswa                       |"<<endl;
    cout<<"| [4] Tambah data mahasiwa                       |"<<endl;
    cout<<"=================================================="<<endl;
    cout<<"Masukkan kode angka yang ingin dipilih = ";
    cin>>kode;
    switch (kode)
    {
    case 1:
        lihat();
        break;
    case 2:
        ubah();
        break;
    case 3:
        hapus();
        break;
    case 4:
        tambah();
        break;
        default:
        cout<<"Kode tersebut tidak ada dalam menu"<<endl;
    }
     cout << "-----------------------------------------------\n";    
    cout<<"Apakah anda ingin melanjutkan? (Y/N)";
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

