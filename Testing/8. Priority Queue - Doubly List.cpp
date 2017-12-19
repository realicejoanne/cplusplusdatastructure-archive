//program belom kelar :(

#include<iostream>
using namespace std;

struct mhs{
	char nama[10];
	int prior;
	mhs* next;
	nhs* prev;
};

typedef mhs* pointer;
typedef pointer list;

struct queue{
	list head;
	list tail;
};
queue q;

void createQueue(queue& q){
	q.head = NULL;
	q.tail = NULL;
}

void createElement(pointer& pBaru){
	pBaru = new mhs;
	cout<<"Nama: ";
	cin>>pBaru->nama;
	do{
		cout<<"Prioritas: ";
		cin>>pBaru->prior;
		if (pBaru->prior<1||pBaru->prior>10){
			cout<<"ERROR! Masukkan Angka 1-10"<<endl<<endl;
		}
	}
	while(pBaru->prior<1||pBaru->prior>10);
	pBaru->next=NULL;
	pBaru->prev=NULL;
}

void insertQueue(queue& q, pointer pBaru){
	if (q.head == NULL && q.tail == NULL){
		q.head = pBaru;
		q.tail = pBaru;
	}
	else {
		pointer pBantu=q.head;
		while (pBantu->next!=NULL){
			if (pBaru->prior > pBantu->prior) break;
			cout<<pBantu->nama<<endl;
			pBantu = pBantu->next;
		}
    }
    if (pBantu->next == NULL){
		q.tail = pBaru;
		pBantu->next = pBaru;
		pBaru->prev = pBantu;
    }
    else {
		pBaru->next = pBantu;
		pBaru->prev = pBantu->prev;
		pBantu->prev = pBantu->prev->next = pBaru;
    }
}

void deleteQueue(queue& q, pointer& pHapus){
	if (q.head != NULL && q.tail != NULL){
		if (q.head->next = NULL) q.head = q.tail = NULL;
		else {
			pHapus = q.head;
			q.head = q.head->next;
		}
	}
}

