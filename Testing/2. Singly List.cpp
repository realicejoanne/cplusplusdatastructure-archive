#include<iostream>
using namespace std;

struct mahasiswa{
	char npm[6];
	char nama[20];
	mahasiswa* next;
};

typedef mahasiswa* pointer;
typedef pointer list;

//create_list, create_element
void createlist(list& first){
	first=NULL;
}
void createelement(pointer& pBaru){
	pBaru=new mahasiswa;
	cout<<"NPM	: ";
	cin>>pBaru->npm;
	cout<<"Nama	: ";
	cin.ignore(20,'\n');
	cin.getline(pBaru->nama,20);
	pBaru->next=NULL;
}

//insertfirst, traversal
void insertfirst(list& first, pointer pBaru){
	if(first==NULL) first=pBaru; //kosong
	else { //ada isi
		pBaru->next=first;
		first=pBaru;
	}
}
void traversal(list first){
	pointer pBantu;
	if(first==NULL) cout<<"List kosong."<<endl; //kosong
	else { //ada isi
		pBantu=first;
		do {
			cout<<pBantu->npm<<"\t"<<pBantu->nama<<endl;
			pBantu=pBantu->next;
		}
		while(pBantu!=NULL);
	}
}

//operasi P1 (minus insertfirst & traversal)
void insertlast(list& first, pointer pBaru){
	if(first==NULL) first=pBaru; //kosong
	else { //ada isi
		pointer last;
		last=first;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}
void deletefirst(list& first, pointer& pHapus){
	if(first==NULL) { //kosong
		pHapus=NULL;
		cout<<"List kosong.";
	}
	else if(first->next==NULL){ //1 elemen
		pHapus=first;
		first=NULL;
	}
	else { //>1 elemen
		pHapus=first;
		first=first->next;
		pHapus->next=NULL;
	}
}
void deletelast(list& first, pointer& pHapus){
	if(first==NULL) { //kosong
		pHapus=NULL;
		cout<<"List kosong.";
	}
	else if(first->next==NULL){ //1 elemen
		pHapus=first;
		first=NULL;
	}
	else { //>1 elemen
		pointer last,preclast;
		last=first;
		preclast=NULL;
		while(last->next!=NULL){
			preclast=last;
			last=last->next;
		}
		pHapus=last;
		preclast->next=NULL;
	}
}

//operasi P2
void searching(list& first, char key[6], int& found, pointer& pCari){
	cout<<"NPM yang dicari: "; cin>>key;
	found=0;
	pCari=first;
	while(found==0&&pCari!=NULL){
		if(pCari->npm==key) found=1;
		else pCari=pCari->next;
	}
}
void insertafter(list& first, pointer pCari, pointer pBaru){
	if(pCari->next==NULL) pCari->next=pBaru; //element terakhir = insert last
	else { //element di tengah
		pBaru->next=pCari->next;
		pCari->next=pBaru;
	}
}
void deleteafter(list& first, pointer pCari, pointer pHapus){
	if(pCari->next==NULL){ //element terakhir
		pHapus= NULL;
		cout<<"Tidak ada yang dihapus"<<endl;
	}
	else { //element di tengah
		pHapus=pCari->next;
		pCari->next=pHapus->next;
		pHapus->next=NULL;
	}
}

//FUNGSI MAIN
int main(){
	//deklarasi
	int x;
	list first;
	pointer pBaru,pCari,pHapus;
	char cek;
		
	//create_list, create_element
	createlist(first);
	do{
		createelement(pBaru);
		insertfirst(first,pBaru);
		cout<<"(Y/N)\t: ";
		cin>>cek;
	}
	while(cek=='Y'||cek=='y');
		
	//menu
	do{
		cout<<endl<<endl;
		cout<<"========================="<<endl;
		cout<<"=  PROGRAM SINGLY LIST  ="<<endl;
		cout<<"========================="<<endl;
		cout<<"= 0. Exit               ="<<endl;
		cout<<"= 1. Traversal          ="<<endl;
		cout<<"= 2. Insert first       ="<<endl;
		cout<<"= 3. Insert last        ="<<endl;
		cout<<"= 4. Delete first       ="<<endl;
		cout<<"= 5. Delete last        ="<<endl;
		cout<<"= 6. Searching          ="<<endl;
		cout<<"= 7. Insert after       ="<<endl;
		cout<<"= 8. Delete after       ="<<endl;
		cout<<"========================="<<endl;
			
		cout<<endl<<"Masukkan Pilihan: ";
		cin>>x;
		switch(x){
			case 0: return 0;
				
			case 1: traversal(first);
				break;
					
			case 2: do{
						createelement(pBaru);
						insertfirst(first,pBaru);
						cout<<"Data baru berhasil ditambah di depan."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
						
			case 3: do{
						createelement(pBaru);
						insertlast(first,pBaru);
						cout<<"Data baru berhasil ditambah di belakang."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
						
			case 4: do{
						deletefirst(first,pHapus);
						traversal(first);
						cout<<"Data pada baris terdepan berhasil dihapus."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
						
			case 5: do{
						deletelast(first,pHapus);
						traversal(first);
						cout<<"Data pada baris terbelakang berhasil dihapus."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
					
			default: cout<<"Maaf, pilihan tidak tersedia!";
		}
	}
	while(x!=0);
}


















