/**************************************************************
Nama Program	: Pegawai Edit List
Nama			: Adryan Luthfi Faiz
NPM				: 140810160049
Tanggal Buat	: 6 April 2017
Deskripsi		: Menambah atau Menghapus Setelah Data yang dicari
***************************************************************/

#include <iostream>
#include <Windows.h>
#include <String.h>
using namespace std;

// Tugas 4.2 Latihan 2

struct pegawai {
	char nip [12];
	char nama [15];
	char alamat [30];
	int gol ;
	pegawai* next ;			// pointer next sebagai pengait
};

typedef pegawai* pointer;
typedef pointer List;

void CreateList (List& First){
	First = NULL;
}

void CreateElement (pointer& pBaru){
	pBaru = new pegawai;
	cout<<"NIP\t\t: ";cin >> pBaru -> nip;
	cout<<"Nama\t\t: ";cin >> pBaru -> nama;
	cout<<"Alamat\t\t: ";cin >> pBaru -> alamat;
	do {
		cout<<"Golongan\t: ";cin >> pBaru -> gol;
		if (pBaru -> gol < 0 || pBaru -> gol > 4 )
			cout<<"ERROR , Masukkan Gol Antara 1-4 "<<endl<<endl;
	} while (pBaru -> gol < 0 || pBaru -> gol > 4 );
	pBaru -> next = NULL;
}

int gaji (int n){
	switch (n){
		case 1 : return 2000000 ; break;
		case 2 : return 3000000 ; break;
		case 3 : return 5000000 ; break;
		case 4 : return 8000000 ; break;
	}
}

void traversal (List First){
	pointer pBantu;
	if (First == NULL)			// Kasus kosong
		cout<<"List Kosong"<<endl;
	else {
		pBantu = First ;
		do {
			cout<<"NIP\t\t: "<< pBantu -> nip <<endl;
			cout<<"Nama\t\t: "<< pBantu -> nama <<endl;
			cout<<"Alamat\t\t: "<< pBantu -> alamat <<endl;
			cout<<"Golongan\t: "<< pBantu -> gol <<endl;
			cout<<"Gaji\t\t: "<< gaji (pBantu -> gol) <<endl;
			cout<<endl;
			pBantu = pBantu -> next;
		} while (pBantu != NULL);
	}
}

void InsertFirst (List& First , pointer pBaru ){
	
	if ( First == NULL)			// List Kosong
		First = pBaru ;
	else {						// Kasus ada isi
		pBaru -> next = First;
		First = pBaru;
	}
}

void linearSearch (List& First, char key [12] , int& found, pointer& pCari ){
	cout<<" Masukkan NIP : "; cin >> key ;
	found=0; 				// belum ditemukan
	pCari=First; 			// Mencari NIP
	while (found==0 && pCari!=NULL) {
		if ( strcmp (pCari-> nip , key ) == 0 ) // Membandingkan , jika sama maka bernilai 0
			found=1;
		else
			pCari=pCari->next;
	}
}

void insertAfter(List& First, pointer pCari,pointer pBaru){
	if (pCari->next==NULL)			// elementerakhir
		pCari->next=pBaru;
	else {							// bukanterakhir
		pBaru->next=pCari->next;
		pCari->next=pBaru;
	}
}

void deleteAfter(List& First , pointer pCari , int& found ){
	pointer pHapus;
	if (pCari->next==NULL){					// Last
		pHapus= NULL;
		cout << "Tidakadayang dihapus"<<endl;
		found = 0;
	}
	else {
		pHapus= pCari->next;
		pCari->next = pHapus->next; 		// NULL jika pHapus di belakang
		pHapus->next = NULL;
	}
}



main(){
	pointer p , cari ;
	List Pegawai;
	int n;
	char key [12];
	int found ;
	int list;
	
	CreateList (Pegawai);		// Element kosong
	
	cout<<"Masukkan Banyak Data : "; cin>>n;
	cout<<endl;
	
	for (int i = 0 ; i < n ; i++){
		cout<<"Data ke-"<< i+1 <<endl;
		CreateElement (p);		
		InsertFirst ( Pegawai , p );
		cout<<endl;
	}
	
	system("cls");
	cout<<endl;
	cout<<"==== DATA ===="<<endl;
	traversal ( Pegawai );		// Menayangkan dari Last ke First
	cout<<endl<<endl;
	// List
	cout<<endl<<"== LIST EDIT ==="<<endl;
	cout<<endl<<"1. Insert After"<<endl;
	cout<<"2. Delete After"<<endl;
	
	do {
		cout<<endl<<"Pilih List : "; cin >> list;
		if ( list < 1 || list > 2)
			cout<<"ERROR , Masukkan Angka 1 atau 2"<<endl;
	} while ( list < 1 || list > 2);
	linearSearch ( Pegawai , key , found, cari );
	if (found == 1 ){
		if (list == 1){
			system("cls");
			cout<<endl;
			CreateElement (p);
			insertAfter ( Pegawai , cari , p) ;
			
		}
		else deleteAfter ( Pegawai , cari , found );		// List = 2
		
		if ( found == 1 ){
			system("cls");
			cout<<endl;
			cout<<"==== DATA ===="<<endl;
			traversal ( Pegawai );
		}
	}
	else cout<<endl<<" Data Tidak Ditemukan " <<endl<<endl; // Found = 0
	

	
}