#include <iostream>
#include <stdlib.h>
#include <ctime>
#define max 100
using namespace std;

//variable global
int id1[1000];								//deklarasi array 
int (*hasil)[1000];							//deklarasi pointer ke array
int opsimenu1, i, j,o, menu = 0, temp = 0, counter = 0, ketemu = 0, cari, k,ulang1=1, idadmin; 
bool ulang = 1;

struct tumpukan
{
    string namabuku[max];
    string peminjam[max];
    int nomorbuku[max];
    int atas;
}T;

struct Node{
    int idadmin;
    Node *next;
};

Node *headNode = NULL;
Node *currentNode = NULL;

void awal();
int kosong();
int penuh();
void input();
void tampil();
void bersih();
void daftarpengunjung();
void jumlahkunjungan();
void informasi();
void submain();
bool isEmpty();
void insertNode(int data);
void printNode();

int main() 
{
	hasil = &id1;								//menunjukan bahwa pointer menunju ke array id1
    int nomorbuku;
	string judulbuku, peminjam;
    awal();
	//program catat pengunjung perpustakaan
	while(ulang = 1)							//perulangan program
	{
		system("cls");
		cout << "|=================================================================|\n";
		cout << "|                 Selamat Datang Di Perpustakaan                  |\n";
		cout << "|=================================================================|\n";
		cout << "|Silahkan Masukkan Nomor Identitas                                |\n";
		cout << "|atau: 99 Masuk Ke Menu Admin                                     |\n";
		cout << "|      0  Melihat Informasi Aplikasi                              |\n";
		cout << "|      1  Keluar Dari Aplikasi                                    |\n";
		cout << "|=================================================================|\n";
		cout << "Nomor ID : ";
		cin >> menu;
		cout << "\n";
		system("cls");
		
		if(menu == 99)
		{
			submain();

		} else if(menu == 0){
			informasi();								//akses fungsi informasi program
		}
		else if(menu == 1){
			exit(0);  									//untuk keluar dari program
		}else{
			
			id1[counter] = menu;
			cout << "|================================================|\n";
			cout << "|Terima kasih! Silahkan Melanjutkan Kegiatan Anda|\n";
			cout << "|================================================|\n";
			counter++;
			system("pause");
			system("cls");
		}
	}
}

//awal code stack
void awal()
{
    T.atas=-1;
} 
int kosong(){
    if(T.atas==-1){
        return 1;
    }else{
        return 0;
    }
}
int penuh(){
    if(T.atas==max-1){
        return 1;
    }else{
        return 0;
    }
}

//code untuk push(input)
void input()
{    
    if(kosong()==1){
        T.atas++;
		system("cls");
		cout << "|========================|\n";
		cout << "|Input Data Buku Pinjaman|\n";
        cout << "|========================|\n";
		cout << "Nomor Buku : ";
		cin >> T.nomorbuku[T.atas];
        cin.ignore(1, '\n');
        cout << "Judul Buku : "; getline(cin,T.namabuku[T.atas]);
        cout << "Peminjam   : "; getline(cin,T.peminjam[T.atas]);
		
    }else if(penuh()==0){
        T.atas++;
		system("cls");
		cout << "|========================|\n";
		cout << "|Input Data Buku Pinjaman|\n";
        cout << "|========================|\n";
        cout << "Nomor Buku : ";
		cin >> T.nomorbuku[T.atas];
        cin.ignore(1, '\n');
        cout << "Judul Buku : "; getline(cin,T.namabuku[T.atas]);
        cout << "Peminjam   : "; getline(cin,T.peminjam[T.atas]); 
		
    }else{
        cout << "|================================================|\n";
		cout << "|    Peminjaman Buku Mencapai Batas Maksimal     |\n";
		cout << "|================================================|\n";
    }
    system("pause");
    system("cls");
}

//code untuk tampil
void tampil(){
    system("cls");
	cout << "|====================|\n";
	cout << "|Daftar Buku Pinjaman|\n";
	cout << "|====================|\n";
	
    if(kosong()==0){
        for( o=T.atas;o>=0;o--){
            cout << "* Nomor Buku : " << T.nomorbuku[o] << " | Judul Buku : " << T.namabuku[o] << "\t" << "| Peminjam : " << T.peminjam[o] << endl;
        }
        cout << endl;
    }else{
		system("cls");
        cout << "|================================================|\n";
		cout << "|      Daftar Peminjaman Buku Masih Kosong       |\n";
		cout << "|================================================|\n";
    }
    system("pause");
    system("cls");
}

void bersih(){
    system("cls");
    T.atas=-1;
    cout << "|================================================|\n";
	cout << "|   Daftar Pinjaman Buku Berhasil Dikosongkan    |\n";
	cout << "|================================================|\n";
    system("pause");
    system("cls");
}
//akhir code stack

void daftarpengunjung()							//fungsi untuk melihat daftar pengunjung
{
	system("cls");
	if (counter == 0)
	{
		cout << "|================================================|\n";
		cout << "|     Belum Ada Pengunjung Hingga Saat Ini       |\n";
		cout << "|================================================|\n";
		system("pause");
		system("cls");

	}else{
		cout << "|================================================|\n";
		cout << "       Jumlah Pengunjung Hingga Saat Ini : " << counter << endl;
		cout << "|================================================|\n";
		
		for(i=0; i<counter-1; i++)							//proses sorting
			{
				for(j=0; j<counter-1; j++)
				{
					if(id1[j]>id1[j+1])
					{
						temp = id1[j+1];
						id1[j+1] = id1[j];
						id1[j] = temp;
					}
				}
			}
				
		cout << "ID Pengunjung Yang Terdaftar : " << endl;
		for(i=0; i<counter; i++)							//menampilkan daftar
		{
			cout << (*hasil)[i]<<endl;
		}
		system("pause");
		system("cls");
	}
}

void jumlahkunjungan()										//fungsi untuk melihat jumlah kunjungan
{
	system("cls");
	cout << "|=====================================|\n";
	cout << "|     Jumlah Kunjungan Pengunjung     |\n";
	cout << "|=====================================|\n";
	cout << "Masukkan ID : ";
	cin >> cari;
				
	for(k=0; k<1000; k++)
		{
			if((*hasil)[k] == cari)
			{
				ketemu++;
			}
		}
	cout << "Pengunjung dengan ID " << cari << " berkunjung " << ketemu << " kali \n";
	ketemu = 0;
	system("pause");
	system("cls");
}

void informasi()											//fungsi informasi program
{
	cout << "|================================================|\n";
	cout << "|                 FINAL PROJECT                  |\n";
	cout << "|             Aplikasi Perpustakaan              |\n";
	cout << "|================================================|\n";
	
	cout << "Pengembang : \n";
	cout << "1. Ahmad Faqih Hidayat\t\t 20.11.3603\n";
	cout << "2. Hafid Kurniadi\t\t 20.11.3604\n";
	cout << "3. William Bagus Setiawan\t 20.11.3605\n";
	system("pause");
	system("cls");
}

void submain(){
	do{
		system("cls");
		cout << "|==========================================================|\n";
		cout << "|                      Daftar Menu                         |\n";
		cout << "|==========================================================|\n";
		cout << "|1. Melihat Daftar Pengunjung                              |\n";
		cout << "|2. Mengetahui Jumlah Kunjungan Pengunjung Tertentu        |\n";
		cout << "|3. Menginput Buku Pinjaman                                |\n";
		cout << "|4. Menampilkan Buku Pinjaman                              |\n";
		cout << "|5. Mengosongkan Daftar Pinjaman                           |\n";
		cout << "|6. Memasukan Data Admin                                   |\n";
		cout << "|7. Menampilkan Data Admin                                 |\n";
		cout << "|8. Kembali ke Menu Utama                                  |\n";
		cout << "|==========================================================|\n";
		cout << "Masukkan Pilihan Anda : ";
		cin >> opsimenu1;
		
				if(opsimenu1 == 1)
			{
				daftarpengunjung();						//akses fungsi daftar pengunjung
			} else if (opsimenu1 == 2){
				jumlahkunjungan();						//akses fungsi jumlah kunjungan
			} else if (opsimenu1 == 3){
				input();
			}else if (opsimenu1 == 4){
				tampil();
			}else if(opsimenu1 == 5){
				bersih();
			}else if(opsimenu1 ==6){
				system("cls");
				cout << "|==================|\n";
				cout << "|    Data Admin    |\n";
				cout << "|==================|\n";
				cout << "Masukkan Data : "; 
				cin >> idadmin;
                insertNode(idadmin);
			}else if(opsimenu1 == 7){
				printNode();
			}else if(opsimenu1 == 8){
				ulang1 == 0;
				break;
			}
	
	}while(ulang1==1);
}

bool isEmpty(){
    return(headNode == NULL);
}

void insertNode(int idadmin)
{
    Node *newNode = NULL;
    newNode = new Node;
    newNode->idadmin = idadmin;
    if(isEmpty()){
        headNode = newNode;
    }else{
        currentNode->next = newNode;
    }
    currentNode = newNode;
    currentNode->next = NULL;	
    cout << "ID Admin Berhasil Diinputkan.." << endl << endl;
	system("pause");
	system("cls");
}

void printNode(){
    Node *awalNode = headNode;
    int i = 1;
    while(awalNode != NULL){
		system("cls");
		cout << "|==================|\n";
		cout << "|    Data Admin    |\n";
		cout << "|==================|\n";
        cout << "ID Admin pada jam ke - " << i <<" = " << awalNode->idadmin << endl;
        awalNode = awalNode->next;
        i++;
    }
    cout << endl;
	system("pause");
	system("cls");
}