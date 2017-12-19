#include<iostream>
using namespace std;

const int maxElemen = 255;

struct stack{
	int isi[maxElemen];
	int top;
};
stack s;

void createStack(stack& s){
	s.top=-1;
}

void push(stack& s, char elemenBaru){
	if (s.top==maxElemen-1){
		cout<<"Tumpukan sudah penuh"<<endl;
	}
	
	else{
		s.top=s.top+1;
		s.isi[s.top]=elemenBaru;
	}
}

void pop(stack& s, char elemenHsl){
	if (s.top<0){
		cout<<"Tumpukan sudah kosong"<<endl;
	}
	else{
		elemenHsl=s.isi[s.top];
		s.top=s.top-1;
	}
}

void cetak(stack& s){
	for(int i=s.top;i>=0;i--){
		cout<<s.isi[i]<<endl;
	}
}
	
int main(){
	stack s;
	int a;
	
	createStack(s);
	push(s,10);
	push(s,12);
	push(s,19);
	push(s,20);
	cout<<"Stack awal: "<<endl;
	cetak(s);
	cout<<endl;
	
	pop(s,a);
	cout<<"Stack akhir: "<<endl;
	cetak(s);
}
	
	
	