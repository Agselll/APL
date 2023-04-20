#include <iostream>
#include <conio.h>

using namespace std;

struct mahasiswa { //untuk menyimpan variabel
	string nama_mahasiswa;
	int nim_mahasiswa;
};

int kode, pilih;
int banyak = 0;                 // untuk ngatur ukuran indeks
mahasiswa mhs;                  // menentukan variabel struct
mahasiswa *ptrmahasiswa = &mhs; // deklarasi pointer
mahasiswa jumlahdata[100];      // array

void lihat() {
	int nomor;
	for (int indeks = 0; indeks < banyak; indeks++) {
		mahasiswa mhs = jumlahdata[indeks];
		mahasiswa *ptrmahasiswa = &mhs;

		nomor = indeks + 1;
		cout << "\nData Mahasiswa Ke- " << nomor << endl;
		cout << "Nama Mahasiswa : " << ptrmahasiswa->nama_mahasiswa << endl;
		cout << "Nim Mahasiswa : " << ptrmahasiswa->nim_mahasiswa << endl;
	}
}

void swap(mahasiswa *data1, mahasiswa *data2) {
	mahasiswa temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

int partition(mahasiswa arr[], int low, int high) {
	mahasiswa pivot = arr[high];
	int i = (low-1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j].nama_mahasiswa <= pivot.nama_mahasiswa) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSort(mahasiswa arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
		lihat();
	}
}

void shellsort() {
	cout << "Data Sebelum Di Sorting" << endl;
	lihat();
	int i, j;
	// int n = 2;
	int n = banyak;
	// fungsi shell
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i += 1) {
			mahasiswa temp = jumlahdata[i];
			for (j = i; j >= gap && jumlahdata[j - gap].nim_mahasiswa > temp.nim_mahasiswa; j -= gap) {
				jumlahdata[j] = jumlahdata[j - gap];
			}
			jumlahdata[j] = temp;
		}
	}
	cout << "Data Sesudah Di Sorting Secara Ascending " << endl;
	lihat();
}

void ubah() {
	cout << "" << endl;
	lihat();

	int target; // variabel pilihan yg mau diubah
	int indeks; // variabel indeks yang mau diubah
	cout << "" << endl;
	cout << "Masukkan data mahasiswa yang ingin diubah datanya : ";
	cin >> target;
	cin.ignore();
	indeks = target - 1;
	cout << "Masukkan Nama Baru : ";
	getline(cin, ptrmahasiswa->nama_mahasiswa);
	cout << "Masukkan Nim Mahasiswa : ";
	cin >> ptrmahasiswa->nim_mahasiswa;
	cin.ignore();

	jumlahdata[target - 1] = mhs;
	lihat();
}

int tambah() {
	// lihat();
	cout << "" << endl;
	cin.ignore();
	cout << "Masukkan Nama Mahasiswa : ";
	getline(cin, ptrmahasiswa->nama_mahasiswa);
	cout << "Masukkan Nim Mahasiswa : ";
	cin >> ptrmahasiswa->nim_mahasiswa;
	cin.ignore();

	jumlahdata[banyak] = mhs;
	banyak++;
	return banyak;
}

void hapus() {
	cout << "" << endl;
	lihat();

	int target, indeks; // variabel yg ingin dihapus
	cin.ignore();
	cout << "\nMasukkan data mahasiswa yang ingin dihapus: ";
	cin >> target;
	indeks = target - 1;
	banyak--;
	for (int i = indeks; i < banyak; i++) {
		jumlahdata[i].nama_mahasiswa = jumlahdata[i + 1].nama_mahasiswa;
		jumlahdata[i].nama_mahasiswa = jumlahdata[i + 1].nim_mahasiswa;
	}
}

void sorting() {
	cout << "===========================================" << endl;
	cout << "|               MENU SORTING              |" << endl;
	cout << "===========================================" << endl;
	cout << "| [1] Quick Sort                          |" << endl;
	cout << "| [2] Shell Sort                          |" << endl;
	cout << "| [3] Kembali	                           |" << endl;
	cout << "===========================================" << endl;
	cout << "Masukkan kode yang dipilih : ";
	cin >> kode;
	switch (kode) {
		case 1:
			quickSort(jumlahdata, 0, banyak - 1);
			break;
		case 2:
			shellsort();
			break;
		case 3:
			break;
		default:
			cout << "Kode tersebut tidak ada dalam menu" << endl;
	}
}


void sequentialSearchNama(string cari_nama) {
	int indeks = -1;
	for (int i = 0; i < banyak; i++) {
		if (jumlahdata[i].nama_mahasiswa == cari_nama) {
			indeks = i;
			break;
		}
	}
	if (indeks != -1) {
		cout << "Data mahasiswa dengan nama \"" << cari_nama << "\" ditemukan pada indeks ke-" << indeks << endl;
	} else {
		cout << "Data mahasiswa dengan nama \"" << cari_nama << "\" tidak ditemukan" << endl;
	}
}

void interpolationSearchNIM(int cari_nim) {
	int low = 0, high = banyak - 1, pos = -1;
	while (low <= high && cari_nim >= jumlahdata[low].nim_mahasiswa && cari_nim <= jumlahdata[high].nim_mahasiswa) {
		float fraction = ((float)(cari_nim - jumlahdata[low].nim_mahasiswa) / (jumlahdata[high].nim_mahasiswa - jumlahdata[low].nim_mahasiswa));
		pos = low + (int)((high - low) * fraction);
		if (jumlahdata[pos].nim_mahasiswa == cari_nim) {
			break;
		} else if (jumlahdata[pos].nim_mahasiswa < cari_nim) {
			low = pos + 1;
		} else {
			high = pos - 1;
		}
	}
	if (pos != -1 && jumlahdata[pos].nim_mahasiswa == cari_nim) {
		cout << "Data mahasiswa dengan NIM \"" << cari_nim << "\" ditemukan pada indeks ke-" << pos << endl;
	} else {
		cout << "Data mahasiswa dengan NIM \"" << cari_nim << "\" tidak ditemukan" << endl;
	}
}


void searching () {
	int kode_search, nim_search;
	string nama_search;
	do {
		cout << "===========================================" << endl;
		cout << "|              MENU SEARCHING              |" << endl;
		cout << "===========================================" << endl;
		cout << "| [1] Sequential Search - Nama Mahasiswa   |" << endl;
		cout << "| [2] Interpolation Search - NIM Mahasiswa |" << endl;
		cout << "| [3] Kembali                              |" << endl;
		cout << "===========================================" << endl;
		cout << "Masukkan kode metode searching yang dipilih : ";
		cin >> kode_search;
		switch (kode_search) {
			case 1:
				cout << "Masukkan Nama yang ingin dicari : ";
				cin.ignore();
				getline(cin, nama_search);
				sequentialSearchNama(nama_search);
				break;
			case 2:
				cout << "Masukkan NIM yang ingin dicari : ";
				cin >> nim_search;
				interpolationSearchNIM(nim_search);
				break;
			case 3:
				return;
			default:
				cout << "Kode yang dimasukkan tidak sesuai" << endl;
				break;
		}
	} while (true);
}


int main() {
	//    system("cls");
	struct mahasiswa mhs;
	int i;
	string pass_input, user_input;
	cout << "===========================================" << endl;
	cout << "|                 POSTTEST 6              |" << endl;
	cout << "===========================================" << endl;
	cout << "|        AGSEL FALANA SUPARLAN PUTRA      |" << endl;
	cout << "|             INFORMATIKA A'2022          |" << endl;
	cout << "|                 2209106046              |" << endl;
	cout << "===========================================\n"
	     << endl;
	cout << "Silahkan Login jika ingin menggunakan nya..\n";
	cout << "===========================================\n"
	     << endl;
	string username = "agsel"; // variabel untuk username login
	string password = "46";    // variabel untuk password login
	string login = "block";    // variabel untuk login
	i = 1;

	do {
		cout << "Username = ";
		getline(cin, user_input);
		cout << "Password = ";
		getline(cin, pass_input);

		if (user_input == username && pass_input == password) {
			// system("cls");
			cout << "\n===========================================" << endl;
			cout << "|              Login Berhasil             |" << endl;
			cout << "===========================================\n"
			     << endl;
			i = 4;
			login = "berhasil";
		} else if (user_input != username && pass_input == password) {
			cout << "\n==========================================" << endl;
			cout << "|   Username Yang Anda Masukkan Salah!   |" << endl; // ERROR HANDLING USERNAME
			cout << "==========================================\n"
			     << endl;
			i = i + 1;
		} else if (user_input == username && pass_input != password) {
			cout << "\n==========================================" << endl;
			cout << "|    Password Yang Anda Masukkan Salah!    |" << endl; // ERROR HANDLING PASSWORD
			cout << "==========================================\n"
			     << endl;
			i = i + 1;
		} else {
			cout << "\n==========================================" << endl;
			cout << "|      Username / Password Anda Salah!   |" << endl;
			cout << "==========================================\n"
			     << endl;
			i = i + 1;
		}
	} while (i <= 3);
	if (login != "berhasil") {
		// system("cls");
		cout << "\n===========================================" << endl;
		cout << "| Kamu sudah terblokir karena salah terus |" << endl;
		cout << "|           YAHAHAHAHAHHAYYYYYUK          |" << endl;
		cout << "===========================================\n"
		     << endl;
		return 0;
	}

	char lagi = 'y'; // tambahkan variabel `lagi` untuk menentukan apakah ingin melanjutkan atau tidak
	do {
		cout << "==================================================" << endl;
		cout << "|          SELAMAT DATANG DI POSTTEST 6          |" << endl;
		cout << "|=================================================" << endl;
		cout << "| [1] Lihat data mahasiswa                       |" << endl;
		cout << "| [2] Ubah data mahasiswa                        |" << endl;
		cout << "| [3] Hapus data mahasiswa                       |" << endl;
		cout << "| [4] Tambah data mahasiwa                       |" << endl;
		cout << "| [5] Sorting data mahasiwa                      |" << endl;
		cout << "| [6] Searching data mahasiswa                   |" << endl;
		cout << "==================================================" << endl;
		cout << "Masukkan kode angka yang ingin dipilih = ";
		cin >> kode;
		switch (kode) {
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
			case 5:
				sorting();
				break;
			case 6:
				searching();
				break;
			default:
				cout << "Kode tersebut tidak ada dalam menu" << endl;
		}
		cout << "\n-----------------------------------------------\n";
		cout << "Apakah anda ingin melanjutkan? (Y/N)";
		cin >> lagi;
	} while (lagi == 'y' || lagi == 'Y');
	cout << "===================================================" << endl;
	cout << "|              PROGRAM TELAH SELESAI              |" << endl;
	cout << "===================================================" << endl;
	cout << "| TERIMAKASIH TELAH MENGGUNAKAN PROGRAM SEDERHANA |" << endl;
	cout << "|                YANG DISUSUN OLEH                |" << endl;
	cout << "|           AGSEL FALANA SUPARLAN PUTRA           |" << endl;
	cout << "|                INFORMATIKA A'22                 |" << endl;
	cout << "|                   2209106046                    |" << endl;
	cout << "===================================================" << endl;

	return 0;
}
