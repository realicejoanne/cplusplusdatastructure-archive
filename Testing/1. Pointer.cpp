#include<iostream.h>
main(){
	/*
	int n=33;
	cout<<"n = "<<n<<endl;
	cout<<"&n = "<<&n<<endl;
	*/
	/*
	int n=3;
	int& r=n;
	cout<<"n = "<<n<<", r = "<<r<<endl;
	cout<<"n = "<<n<<", r = "<<r<<endl;
	cout<<"n = "<<n<<", r = "<<r<<endl;
	cout<<"&n = "<<&n<<", &r = "<<&r<<endl;
	*/
	/*
	int n=5;
	int* p=&n;
	cout<<"n = "<<n<<", &n = "<<&n<<endl;
	cout<<"p = "<<n<<", &p = "<<&p<<endl;
	*/
	/*
	int n=5;
	int* p=&n;
	int& r=p;
	cout<<"n = "<<n<<", &n = "<<&n<<endl;
	cout<<"p = "<<p<<", &p = "<<&p<<endl;
	cout<<"r = "<<r<<", &r = "<<&r<<endl;
	
	delete &n;
	cout<<n;
	*/
	int n=1;
	int*p=&n;
	int* q;
	int* r;
	int* s;
	
	cout<<"n = "<<n<<", &n = "<<&n<<endl;
	cout<<"p = "<<p<<", *p = "<<*p<<endl;
	cout<<"&p = "<<&p<<", &(*p) = "<<&(*p)<<endl;

	q=new int;
	*q=2;
	cout<<"q = "<<q<<", *q = "<<*q<<endl;
	cout<<"&q = "<<&q<<", &(*q) = "<<&(*q)<<endl;
	delete (q);
	
	r=new int;
	*r=3;
	cout<<"r = "<<r<<", *r = "<<*r<<endl;
	cout<<"&r = "<<&r<<", &(*r) = "<<&(*r)<<endl;
	s=q;
	*s=4;
	cout<<"q = "<<q<<", *q = "<<*q<<endl;
	cout<<"s = "<<s<<", *s = "<<*s<<endl;
	cout<<"&q = "<<&q<<", &s = "<<&s<<endl;
}








