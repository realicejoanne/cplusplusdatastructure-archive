//kodingan yang belum selesai :")

#include<iostream>
using namespace std;

const int maxElemen = 255;

struct queue{
	char isi[maxElemen];
	int head;
	int tail;
};

void createQueue(queue& q){
	q.head = -1;
	q.tail = -1;
}

void insertQueue(queue& q, char elemen){
	int posisiTemp;
	if(q.tail==-1){
		q.head=0;
		q.tail=0;
		q.isi[q.tail] = elemen;
	}
	else {
		posisiTemp = q.tail;
		if(q.tail<maxElemen-1) q.tail=q.tail+1;
		else {
			q.tail=0;
		}
		if(q.tail==q.head){
			cout<<"antrian sudah penuh"<<endl;
			q.tail=posisiTemp;
		}
		else {
			q.isi[q.tail] = elemen;
		}
	}
}

void deleteQueue(queue& q,char& elemenHapus){
	if(q.head==-1) cout<<"antrian kosong"<<endl;
	else if(q.head==q.tail){
		elemenHapus=q.isi[q.head];
		q.isi[q.head]=' ';
		q.head=-1;
		q.tail=-1;
	}
	else {
		elemenHapus=q.isi[q.head];
		q.isi[q.head]=' ';
		if(q.head<maxElemen-1) q.head=q.head+1;
		else q.head=0;
	}
}