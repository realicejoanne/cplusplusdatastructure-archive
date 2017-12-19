#include <iostream.h>
using namespace std;

const int maxElmt=255;
struct stack{
	char info;
	stack*next;
};
typedef stack* pointer;
typedef pointer list;

void createStack(list&top){
	top=NULL;
}

void createElmt(pointer&pBaru, char k){
	pBaru=new stack;
	pBaru->info=k;
	pBaru->next=NULL;
}

void push(list&top, pointer &pBaru){
	if (top==NULL)
		top=pBaru;
	else{
		pBaru->next=top;
		top=pBaru;
	}
}

void pop(list&top, pointer &pHapus){
	if(top==NULL){
		pHapus==NULL;
		cout<<"tidak ada yg dihapus"<<endl;
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
}

main(){
	list top;
	pointer p;
	char kalimat[maxElmt];
	
	createStack(top);
	cout<<"masukkan kalimat:"<<endl;
	gets(kalimat);
	//panjang=strlen(kalimat);
	for (int i=0;i<strlen(kalimat);i++){
		createElmt(p,kalimat[i]);
		push(top,p);
	}
	pointer cek;
	cek=top;
	do{
		cout<<cek->info;
		cek=cek->next;
	}while(cek!=NULL);
	
	//pop(top,h);
	
}