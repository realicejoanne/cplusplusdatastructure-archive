#include<iostream>
using namespace std;

void insertfirst(list& pBaru, pointer pBaru){
	if(first=NULL) first=pBaru;
	else {
		pBaru->next=first;
		first->prev=pBaru;
	}
}

void insertlast(list& first, pointer pBaru){
	pointer last=first;
	if(first==NULL) first=pBaru;
	else {
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
		first=pBaru;
	}
}