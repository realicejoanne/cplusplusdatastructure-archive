/*	Nama Program	: ID Card - DeletePCari
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 7 April 2017
	Deskripsi		: Singly List 2
********************************************/

#include<iostream>
using namespace std;

struct idcard{
	char id[6];
	char nama[20];
	idcard* next;
};

typedef idcard* pointer;
typedef pointer list;

void createlist(list& first){
	first=NULL;
}
void createelement(pointer& idc){
	idc=new idcard;
	cout<<"Masukkan ID (10xxxx)\t: ";
	cin>>idc->id;
	cout<<"Masukkan nama anggota\t: ";
	cin.ignore(20,'\n');
	cin.getline(idc->nama,20);
	idc->next=NULL;
}
void insertfirst(list& first, pointer idc){
	if(first==NULL) first=idc;
		else idc->next=first;
		first=idc;
}
void traversal(list& first){
	pointer bantu;
	if(first==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		bantu=first;
		cout<<endl<<"ID\tNama User";
		cout<<endl<<"-------------------------------------------------------"<<endl;
		do{
			cout<<bantu->id<<"\t"<<bantu->nama<<endl;
			bantu=bantu->next;
		} 
		while(bantu!=NULL);
	}
}
void linearsearch(list& first,char key[12],int& found, pointer& cari){
	cout<<"Masukkan ID yang ingin didelete: ";
	cin>>key;
	
	found=0;
	cari=first;
	while(found==0&&cari!=NULL){
		if(strcmp(cari->id,key)==0) found=1;
		else cari=cari->next;
	}
}
void deletePCari(list& first, pointer& cari){
	if(first->next==NULL){
		cari=first;
		first=NULL;
	}
	else if(cari==first){
		first=first->next;
		cari->next=NULL;
		
	}
	else if(cari->next==NULL){
		pointer before;
		before=first;
		while(before->next!=cari) before=before->next;
		before->next=NULL;
	}
	else{
		pointer before;
		before=first ;
		while(before->next!=cari) before=before->next;
		before->next=cari->next;
		cari->next=NULL;
	}
}

int main(){
	int found;
	list first;
	pointer idc,cari;
	char cek,key[12];
	
	cout<<"Pembuatan ID Card Anggota Himatif 2016"<<endl;
	cout<<"======================================"<<endl<<endl;
	
	createlist(first);
	do{
		createelement(idc);
		insertfirst(first,idc);
		cout<<"(Y/N)\t: ";
		cin>>cek;
	}
	while(cek=='Y'||cek=='y');
	traversal(first);
	cout<<endl<<endl;
	
	cout<<"Pengaturan ID Card Anggota Himatif 2016"<<endl;
	cout<<"======================================="<<endl;
	
	linearsearch(first,key,found,cari);
	if(found==1) deletePCari(first,cari);
	else cout<<"ID tidak ditemukan."<<endl<<endl;
	
	traversal(first);
}
	