#include <iostream.h>
using namespace std;

const int maxElmt=255;

struct elmtList{
	char isi;
	elmtList*next;
};

typedef elmtList* pointer;
typedef pointer list;

void createStack(list&top){
	top=NULL;
}

void createElmt(pointer&pBaru,char k){
	pBaru=new elmtList;
	pBaru->isi=k;
	cout<<pBaru->isi;
	pBaru->next=NULL;
}

void push(list&top, pointer pBaru){
	if (top==NULL)
		top=pBaru;
	else{
		pBaru->next=top;
		top=pBaru;
	}
}

void pop(list&top, pointer&pHapus){
	if (top==NULL){
		pHapus=NULL;
		cout<<"stack kosong, tidak ada yang dihapus"<<endl;
	}
	else if(top->next==NULL){
		pHapus=top;
		top=NULL;
	}
	else{
		pHapus=top;
		top=top->next;
		pHapus->next=NULL;
	}
	cout<<pHapus->isi;
}

main(){
	list top;
	pointer s,pHapus;
	char kalimat[maxElmt];
	
	cout<<"Program pembalik kalimat dengan List Berkait"<<endl;
	cout<<"============================================"<<endl<<endl;
	
	cout<<"Masukkan kalimat yang akan dibalik: ";
	gets(kalimat);
	
	createStack(top);
	
	cout<<endl<<"Sebelum dibalik: ";
	for (int i=0; i<strlen(kalimat); i++){
		createElmt(s,kalimat[i]);
		push(top,s);
	}
	cout<<endl<<"Sesudah dibalik: ";
	for (int i=0; i<strlen(kalimat); i++){
		pop(top,pHapus);
	}
}