/*	Nama Program	: Mahasiswa
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 5 April 2017
	Deskripsi		: Singly List 1
*****************************************/

#include<iostream>
using namespace std;

struct mahasiswa{
	char npm[12];
	char nama[20];
	int nilai;
	mahasiswa* next;
};

typedef mahasiswa* pointer;
typedef pointer list;

void createlist(list& first){
	first=NULL;
}
void createelement(pointer& mhs){
	mhs=new mahasiswa;
	cout<<"Masukkan NPM\t: ";
	cin>>mhs->npm;
	cout<<"Masukkan nama\t: ";
	cin.ignore(20,'\n');
	cin.getline(mhs->nama,20);
	cout<<"Masukkan nilai\t: ";
	cin>>mhs->nilai;
	mhs->next=NULL;
}
void insertfirst(list& first, pointer& mhs){
	if(first==NULL) first=mhs;
		else mhs->next=first;
		first=mhs;
}
void traversal(list& first){
	pointer bantu;
	if(first==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		bantu=first;
		cout<<endl<<"NPM\t\tNama\tNilai\tKeterangan";
		cout<<endl<<"--------------------------------------------"<<endl;
		do{
			cout<<bantu->npm<<"\t"<<bantu->nama<<"\t"<<bantu->nilai<<"\t";
			if(bantu->nilai>=60&&bantu->nilai<=100) cout<<"Lulus"<<endl;
			else if(bantu->nilai>=0&&bantu->nilai<60) cout<<"Gagal"<<endl;
			bantu=bantu->next;
		} 
		while(bantu!=NULL);
	}
}
int main(){
	list first;
	pointer mhs;
	char cek;
	
	cout<<"Rekap Nilai Mahasiswa Teknik Informatika 2016"<<endl;
	cout<<"============================================="<<endl<<endl;
	
	createlist(first);
	do{
		createelement(mhs);
		insertfirst(first,mhs);
		cout<<"(Y/N)\t: ";
		cin>>cek;
	}
	while(cek=='Y'||cek=='y');
	traversal(first);
}
