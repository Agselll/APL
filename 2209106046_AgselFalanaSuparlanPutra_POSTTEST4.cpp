#include <iostream>
#include<conio.h>

using namespace std;

struct mahasiswa{
    string nama_mahasiswa;
    int nim_mahasiswa;
};

int banyak = 0; //untuk ngatur ukuran indeks
mahasiswa mhs; //menentukan variabel struct
mahasiswa* ptrmahasiswa= &mhs; //deklarasi pointer
mahasiswa jumlahdata[100]; //array

void lihat(){
    int nomor;
    for (int indeks=0; indeks<banyak; indeks++){
        mahasiswa mhs=jumlahdata[indeks];
        mahasiswa* ptrmahasiswa = &mhs;

        nomor = indeks + 1;
        cout<<"\nData Mahasiswa Ke- "<<nomor<<"\n"<<endl;
        cout<<"Nama Mahasiswa : "<<ptrmahasiswa->nama_mahasiswa<<endl;
        cout<<"Nim Mahasiswa : "<<ptrmahasiswa->nim_mahasiswa<<endl;

    }
}

void ubah(){
    cout<<""<<endl;
    lihat();

    int target; //variabel pilihan yg mau diubah
    int indeks; //variabel indeks yang mau diubah
    cout<<""<<endl;
    cout<<"Masukkan data mahasiswa yang ingin diubah datanya : "; cin>>target;cin.ignore();
    indeks = target - 1;
    cout<<"Masukkan Nama Baru : ";getline(cin,ptrmahasiswa->nama_mahasiswa);
    cout<<"Masukkan Nim Mahasiswa : ";cin>>ptrmahasiswa->nim_mahasiswa;
    cin.ignore();

    jumlahdata[target-1] = mhs;
    lihat();
    }

int tambah(){
    lihat();
    cout<<""<<endl;
    cin.ignore();
    cout<<"Masukkan Nama Mahasiswa : ";getline(cin,ptrmahasiswa->nama_mahasiswa);
    cout<<"Masukkan Nim Mahasiswa : ";cin>>ptrmahasiswa->nim_mahasiswa;
    cin.ignore();

    jumlahdata[banyak]=mhs;
    banyak++;
    return banyak;
}

void hapus(){
    cout<<""<<endl;
    lihat();

    int target,indeks; // variabel yg ingin dihapus
    cin.ignore();
    cout<<"\nMasukkan data mahasiswa yang ingin dihapus: "; cin>>target; 
    indeks = target - 1;
    banyak --;
    for (int i=indeks; i<banyak; i++ ){
        jumlahdata[i].nama_mahasiswa = jumlahdata[i+1].nama_mahasiswa;
        jumlahdata[i].nama_mahasiswa = jumlahdata[i+1].nim_mahasiswa;
    }
}


int main(){
//    system("cls");
   struct mahasiswa mhs;
   int i;  
   string pass_input, user_input;       
   cout << "==========================================="<< endl;    
   cout << "|                 POSTTEST 4              |"<< endl;    
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
       cout << "Username = ";getline (cin,user_input);        
       cout << "Password = "; getline(cin,pass_input);  

       if (user_input == username && pass_input == password) {  
        // system("cls");  
           cout << "\n==========================================="<< endl;    
           cout << "|              Login Berhasil             |" << endl;            
           cout << "===========================================\n"<< endl;       
           i = 4;
           login = "berhasil";} 
       else if(user_input != username && pass_input == password)
       {
           cout << "\n=========================================="<< endl;            
           cout << "|   Username Yang Anda Masukkan Salah!   |"<< endl;      // ERROR HANDLING USERNAME
		   cout << "==========================================\n"<< endl;            
           i = i +1;
       }
        else if (user_input == username && pass_input != password)
        {
           cout << "\n=========================================="<< endl;            
           cout << "|    Password Yang Anda Masukkan Salah!    |"<< endl;   // ERROR HANDLING PASSWORD
		   cout << "==========================================\n"<< endl;            
           i = i +1;
        } 
        else{
           cout << "\n=========================================="<< endl;            
           cout << "|      Username / Password Anda Salah!   |"<< endl;
		   cout << "==========================================\n"<< endl;            
           i = i +1;
        }
   }while (i <= 3);
    if(login != "berhasil"){
        // system("cls");
    cout << "\n==========================================="<< endl;            
    cout << "| Kamu sudah terblokir karena salah terus |"<< endl;
    cout << "|           YAHAHAHAHAHHAYYYYYUK          |"<< endl;
	cout << "===========================================\n"<< endl;            
    return 0;
    }

    
    char lagi;
    int kode, pilih;
    awal:
    cout<<"=================================================="<<endl;
    cout<<"|          SELAMAT DATANG DI POSTTEST 4          |"<<endl;
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
     cout << "\n-----------------------------------------------\n";    
    cout<<"Apakah anda ingin melanjutkan? (Y/N)";
    cin>>lagi;
        if (lagi=='y' || lagi=='Y'){
            // system("cls");
                goto awal;
        }
        if (lagi=='n' || lagi=='N'){
            // system("cls");
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

