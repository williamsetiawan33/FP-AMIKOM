//Program Perpustakaan digital oleh kelompok 7 20-S1IF-05

//Definisi header library
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;

//Deklarasi variabel Global
string no, judul, penulis;
int i=0;
vector<string> nb;
vector<string> jdl;
vector<string> pnl;
string tmpn, tmpjd, tmppnl;
//Fungsi Halaman login
void login(){
  //Deklarasi variabe lokal
    string nim, pw;
    int b = 0;
    //perulangan untuk mencari nim dan password yang benar
    while (b == 0)
    {
        cout << "===========================================" << endl;
        cout << "Perpustakaan Digital Amikom" << endl;
        cout << "===========================================" << endl;
        cout << "HALAMAN LOGIN" << endl;
        cout << "NIM\t\t: ";
        cin >> nim;
        cout << "Password\t: ";
        cin >> pw;
        if (nim == "20.11.1111")//Memverifikasi apakah NIM Benar
        {
            if (pw == "test123")//Memverifikasi apakah password Benar
            {
                system("cls");
                cout << "Login Berhasil !!!" << endl;//Tampilkan pesan jika login berhasil
                b = 1;
            }
            else
                cout << "\nPassword anda salah\n\n";//Tampilkan pesan jika password salah
        }
        else
            cout << "\nNIM tidak ditemukan\n\n";//Tampilkan pesan jika NIM salah
    }
}
//Fungsi untuk Menampilkan buku
void baca(){
  ifstream buku1("buku1.txt");//Menginisiai file txt yang akan digunakan
  string garis;//mendeklarasikan string baris pertama
  getline(buku1, garis);//Melewati baris pertama pada file txt
  if (buku1.is_open())//Percabangan untuk jika buku sukses dimuat
  {
    while(!buku1.eof()){ /* perulangan dimana !buku.eof() = selama buku tidak mencapai end of line
                            (eof) atau akhir dari baris makan perintah akan terus berulang */
      getline(buku1, no, '\t');//mengambil string dari buku1.txt dan menyimpannya ke string no dan menggunakan \t sebagai tanda akhir dari string
      nb.push_back(no);//mengambil string dari string no dan memasukannya ke vector/array nb
      getline(buku1, judul, '\t');//mengambil string dari buku1.txt dan menyimpannya ke string judul dan menggunakan \t sebagai tanda akhir dari string
      jdl.push_back(judul);//mengambil string dari string no dan memasukannya ke vector/array jdl
      getline(buku1, penulis, '\n');//mengambil string dari buku1.txt dan menyimpannya ke string penulis dan menggunakan \n sebagai tanda akhir dari string
      pnl.push_back(penulis);//mengambil string dari string no dan memasukannya ke vector/array pnl
      i+=1;//setiap akhir dari baris (/n) maka akan ditambahkan 1 ke variabe i sebagai tanda banyaknya baris
    }
    buku1.close();//menetup koneksi dengan file txt
    cout<<"Jumlah baris yang ditampilkan: "<<i-1<<endl;//menampilkan jumlah baris sesuai jumlah i -1(baris 1 dari file txt)
  } else {//jika file txt tidak bisa dibuka
    cout<<"File tidak bisa dibuka";//menampilkan pesan gagal
  }
  cout<<"No"<<"\t\t"<<"Judul Buku"<<"\t\t\t\t"<<"Penulis Buku"<<endl;//menampilkan judul tiap kolom
  for (int a=0; a<i-1; a++){
    cout<<nb[a]<<"\t\t"<<jdl[a]<<"\t\t"<<pnl[a]<<endl;//perulangan untuk menampilkan data dari file txt ke dalam bertuk baris dan kolom
  }
  //mengembalikan semua variabe ke default awal setalah data ditampilkan
  i=0;
  nb.clear();
  jdl.clear();
  pnl.clear();
}
//Fungsi untuk Menambahkan buku
void tulis(){
  //Input Data buku yang ingin dimasukan
  cout<<"Masukan Nomor buku yang ingin ditambahkan : ";
  cin>>tmpn;
  cout<<"Masukan judul buku yang ingin ditambahkan : ";
  cin>>tmpjd;
  cout<<"Masukan nama penulis : ";
  cin>>tmppnl;

  string ub("buku1.txt");//inisiasi file txt yang ini dibuka sebagai string
  ofstream ubah1;// deklarasikan ofstream sebagai ubah1 ; ofstream adalah out file stream
  ubah1.open(ub, ios::app);//buka ubah1 dengan file txt ub(buku1.txt), dan ios::app/append yang berarti mengubah file yang sudah ada
  ubah1<<tmpn<<"\t";//masukan data dari variabel tmpn ke buku1.txt dan menambahkan /t(tab)
  ubah1<<tmpjd<<"\t";//masukan data dari variabel tmpjd ke buku1.txt dan menambahkan /t(tab)
  ubah1<<tmppnl<<"\n";//masukan data dari variabel tmpn ke buku1.txt dan menambahkan /n(end of line)
  cout<<"Buku Berhasil ditambahkan"<<endl;//pesan jika buku berhasil dimasukan
  cout<<"Silahkan masukan file e-book pdf anda ke folder data buku dan ganti nama sesuai nomor buku";
  ubah1.close();//menetup koneksi dengan file(buku1.txt)
}
//Fungsi Utama
int main(){
    //deklarasi variabel-variabel lokal
    int pilih, nobuku;
    //memanggil fungsi login
    login();
	//menu
menu:
	cout << "===========================================" << endl;
    cout << "Perpustakaan Digital Amikom" << endl;
    cout << "===========================================" << endl;
    cout << "Daftar Menu :\n";
    cout << "1. Baca Buku\n";
    cout << "2. Tambah Buku\n";
    cout << "3. Informasi\n";
    cout << "4. Keluar\n\n";
	cout << "Masukan Pilihan Anda : ";
	cin >> pilih;

    system("cls");//menghapus layar commandline sebelumnya
    //Percabangan untuk memilih menu
        switch(pilih){
        case 1:
        baca();
        cout << "\n\n99. Kembali ke menu" << endl;
        cout << "\nMasukan Pilihan Anda : ";
        cin >> nobuku;
        //Percabangan untuk memilih buku
        while (nobuku != 99)//selam nobuku tidak sama dengan 99 maka switch akan terus berulang
        {
            switch (nobuku)
            {
            case 1:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\1.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10)
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";//Memasukan pilihan lain ( sama untuk case 1-10)
                cin >> nobuku; //Memasukan pilihan lain ( sama untuk case 1-10)
                break;//mengakhiri blok program

            case 2:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\2.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

            case 3:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\3.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

            case 4:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\4.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

            case 5:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\5.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

			case 6:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\6.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;
			case 7:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\7.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

			case 8:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\8.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

			case 9:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\9.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

			case 10:
                //Perintah untuk membuka file pdf
                ShellExecute(GetDesktopWindow(), "open", "databuku\\10.pdf", NULL, NULL, SW_SHOWNORMAL);//membuka file pdf sesuai direktori ( sama untuk case 1-10
                cout << "E-book Telah terbuka" << endl;
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
                break;

            default:
                cout << "Pilihan Anda Salah atau Buku Tersebut sedang tidak tersedia" << endl;//jika input nobuku tidak ada yang sesuai
                cout << "Masukan Pilihan Anda Selanjutnya : ";
                cin >> nobuku;
            }
        }
        if (nobuku = 99)
        {

            //kembali ke menu utama
            system("cls");
            goto menu;
        }
      break;

      case 2 ://menu untuk menambah buku
      //memanggi fungsi void tulis
        tulis();
        cout<<endl;
        system("pause");//menunggu respon untuk melanjutkan program
        system("cls");//menghapus layar commandline sebelumnya
        goto menu;
        break;

    case 3 :
    //Layar yang berisikan informasi kelompok
        cout << "=======================================================================" << endl;
        cout << "| Final Project -*Perpustakaan Digital*-                              |"<< endl;
        cout << "| Dalam Rangka Pemenuhan Ujian Akhir Semester                         |" << endl;
        cout << "| Mata Kuliah \t\t : Algoritma Pemrograman Teori dan Praktikum  |" << endl;
        cout << "| Dosen Pengampu\t : Majid Rahardi, S.KOM., M.Eng.              |" <<endl;
        cout << "======================================================================" << endl;

        cout << "=============Ketua dan Anggota dari Kelompok 7=========================" << endl;
        cout << "Ketua Kelompok : " << endl;
        cout << "Nama\t : William Bagus Setiawan\nNIM\t : 20.11.3605\n" << endl;

        cout << "Tim Pengembangan Program :" << endl;
        cout << "Nama\t : Farid Nugroho\nNIM\t : 20.11.3600\n" << endl;
        cout << "Nama\t : Ahmad Faqih Hidayat\nNIM\t : 20.11.3603\n" << endl;
        cout << "Nama\t : William Bagus Setiawan\nNIM\t : 20.11.3605\n" << endl;
        cout << "Nama\t : Riefkyanov Surya Adia Pratama\nNIM\t : 20.11.3606\n" << endl;

        cout << "Tim Perencanaan dan Flowchart : " << endl;
        cout << "Nama\t : Danang Eko Nuryanto\nNIM\t : 20.11.3601\n" << endl;
        cout << "Nama\t : Rismawati Nurul Ikhsani\nNIM\t : 20.11.3602\n" << endl;

        cout << "Tim Dokumentasi dan Laporan : " << endl;
        cout << "Nama\t : Hafid Kurniadi\nNIM\t : 20.11.3604\n" << endl;
        cout << "Nama\t : Riki Adi Santoso\nNIM\t : 20.11.3607\n" << endl;
        cout << "=======================================================================" << endl;
        cout << "\nTekan enter untuk kembali ke menu" << endl;
        system("pause");//menunggu respon untuk melanjutkan program
        system("cls");//menghapus layar commandline sebelumnya
        goto menu;
        break;

    case 4 :
        exit(EXIT_SUCCESS);//keluar dari program

      default :
      //jika menu yang dipilih tidak sesua, dilembalikan ke menu Utama
        cout << "Pilihan anda salah !!!" << endl;
        system("pause");
        system("cls");
        goto menu;
}
}
