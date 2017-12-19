#include <iostream>
using namespace std;

struct elqueue{
	char info;
	int prior;
	elqueue* next;
};
typedef elqueue* pointer;
typedef pointer list;

struct queue{
	list Head;
	list Tail;
};
queue Q;

void createList(queue& Q){
	Q.Head = NULL;
	Q.Tail = NULL;
}

void createElement(pointer& pBaru){
	pBaru = new elqueue;
	cout<<"Masukkan karakter: ";
	cin>>pBaru->info;
	do{
		cout<<"Masukkan prioritas: ";
		cin>>pBaru->prior;
		if (pBaru->prior<1||pBaru->prior>= 10){
			cout<<"ERROR Masukkan Angka 1-10"<<endl<<endl;
		}
	}
	while(pBaru->prior<=1||pBaru->prior>=10);
	pBaru->next=NULL;
}

void insertQueue(queue& Q,pointer pBaru){
	if (Q.Head==NULL && Q.Tail==NULL){
		Q.Head= pBaru;
	}
	else if (Q.Head->next == NULL){
		if (pBaru->prior>Q.Head->prior){
			pBaru->next=Q.Head;
			Q.Head=pBaru;
		}
		else{
			Q.Head->next = pBaru;
			Q.Tail = pBaru;
		}
	}
	else{
		pointer pBantu;
		pointer pBefore;
		pBantu=Q.Head;
		while(pBantu->prior>=pBaru->prior&&pBantu->next!=NULL){
			pBefore=pBantu;
			pBantu=pBantu->next;
		}
		if (pBantu==Q.Head){
			pBaru->next=pBantu;
			Q.Head=pBaru;
		}
		else if(Q.Tail->prior>=pBaru->prior){
			Q.Tail->next=pBaru;
			Q.Tail=pBaru;
		}
		else{
			pBaru->next=pBefore->next;
			pBefore->next=pBaru;
		}
	}
}

void deleteQueue(queue& Q, pointer& pHapus){
	if (Q.Head==NULL && Q.Tail==NULL){
		pHapus=NULL;
		cout<<"List Queue kosong"<<endl;
	}
	else if (Q.Head->next==NULL) {
		pHapus=Q.Head;
		Q.Head=NULL;
		Q.Tail=NULL;
	}
	else{
		pHapus=Q.Head;
		Q.Head=Q.Head->next;
		pHapus->next=NULL;
	}
}

void traversal(queue Q){
	if (Q.Head==NULL){
		"Data kosong tidak ada yang dihapus";
	}
	else{
		pointer pBantu;
		pBantu=Q.Head;
		cout<<"Info\tPrioritas"<<endl;
		cout<<"=================="<<endl;
		do{
			cout<<pBantu->info;
			cout<<"\t";
			cout<<pBantu->prior<<endl;
			pBantu=pBantu->next;
		}while(pBantu!=NULL);
	}
}

int main(){
	queue Q;
	pointer p;
	int n;
	char pilih;
	
	cout<<"P R I O R I T Y  Q U E U E"<<endl;
	cout<<"--------------------------"<<endl;
	
	createList(Q);
	cout<<"Masukkan banyak data: ";
	cin>>n;
	cout<<endl;
	
	for (int i=0;i<n;i++){
		createElement(p);
		insertQueue(Q,p);
	}
	cout<<endl;
	traversal(Q);
	
	cout<<endl<<endl;
	do{
		cout<<"Setelah Delete Queue :"<<endl;
		deleteQueue(Q,p);
		traversal(Q);
		cout<<endl;
		cout<<"Apakah ingin melakukan Delete Queue lagi (y/n)?";
		cin>>pilih;
		
	} while(pilih=='y'||pilih=='Y');
}