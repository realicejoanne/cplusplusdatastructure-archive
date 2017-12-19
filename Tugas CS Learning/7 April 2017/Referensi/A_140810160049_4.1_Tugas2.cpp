/**************************************************************
Nama Program	: Data Pegawai
Nama			: Adryan Luthfi Faiz
NPM				: 140810160049
Tanggal Buat	: 5 April 2017
Deskripsi		: Menginput Maupun Menghapus Suatu Elemen
***************************************************************/


#include <iostream>
#include <Windows.h>
using namespace std;

// Tugas 4.1 Latihan 2

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

void DeleteFirst (List& First , pointer& pHapus){
	
	if (First == NULL){					// kosong
		pHapus = NULL;
		cout<<"List Kosong , Tidak ada yang dihapus"<<endl;
	}
	else if ( First -> next == NULL ){	// isi 1 elemen
		pHapus=First;
		First=NULL;
	}
	else {			 					// isi > 1 elemen
		pHapus=First;	
		First=First->next; 	
		pHapus->next=NULL; 
	}
}

void InsertLast(List& First, pointer pBaru){
	
	pointer last; 				//last untuk mencatat elemen terakhir
	cout<<"Insert Last"<<endl;
	if (First==NULL){ 			//kosong
		First=pBaru;
	}
	else { 						// Berisi
		last=First; 			// menemukan elemen terakhir
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;		// sambungkan
	}
}

void DeleteLast(List& First, pointer& pHapus){

	pointer last,precLast;
	cout<<"Delete Last"<<endl;
	if (First==NULL){				// kosong
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){ 	//isi 1 elemen
		pHapus=First;
		First=NULL; 				// list jadi kosong
	}
	else { 							// isi > 1 elemen
		last=First; 				// menemukan elemen terakhir
		precLast=NULL;
		while (last->next!=NULL){
		precLast=last; 				// preclast mencatat yg akan ditinggalkan Last
		last=last->next; 			// last berpindah
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

void ListEdit(){
	cout<<"=== LIST EDIT ==="<<endl;
	cout<<"1. Insert First"<<endl;
	cout<<"2. Delete First"<<endl;
	cout<<"3. Insert Last"<<endl;
	cout<<"4. Delete Last"<<endl;
}

main(){
	pointer p;
	List Pegawai;
	int n;
	int x;
	char pilih='y';
	
	CreateList (Pegawai);		// Element kosong
	
	cout<<"Masukkan Banyak Data : "; cin>>n;
	cout<<endl;
	
	for (int i = 0 ; i < n ; i++){
		cout<<"Data ke-"<< i+1 <<endl;
		CreateElement (p);		
		InsertFirst ( Pegawai , p );
		cout<<endl;
	}
	do{
		system("cls");
		cout<<endl;
		cout<<"==== DATA ===="<<endl;
		traversal ( Pegawai );		// Menayangkan dari Last ke First
		cout<<endl<<endl;
		ListEdit();
		cout<<endl;
		
		cout<<"Ketik y jika ingin mengedit List :";
		cin>> pilih;

		if (pilih != 'y' && pilih != 'Y') break; // keluar jika tidak ingin mengedit
		cout<<endl ;
		
		do{
			cout<<"Masukkan Pilihan Edit : " ; cin >>x;
			if (x<1 || x>4) cout<<"ERROR , Masukkan pilihan antara 1-4";
			cout<<endl<<endl;
		} while (x<1 || x>4);
		
		
		if ( x==1 ){
			CreateElement (p);	InsertFirst ( Pegawai , p ) ;
		}
		if ( x==2 ){
			DeleteFirst ( Pegawai , p ) ;
		}
		if ( x==3 ){
			CreateElement (p);	InsertLast ( Pegawai , p ) ;
		}
		if ( x==4 ){
			DeleteLast ( Pegawai , p ) ; 
		}
		
	} while (pilih == 'y' || pilih == 'Y');
	
	system("cls");
	cout<<endl;
	cout<<"==== DATA ===="<<endl;
	traversal ( Pegawai );
	
}


