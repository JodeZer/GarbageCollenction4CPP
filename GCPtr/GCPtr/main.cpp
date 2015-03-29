#include <iostream>
#include "GCPtr.h"
#include "GCPInfo.h"

using namespace std;

void main(void)
{
	list<int> l;
	list<int>::iterator it;
	it=l.begin();
	/*int *p=new int(2);
	int *p2=p;
	GCPInfo<int> a(p,0);
	GCPInfo<int> b(p2);
	cout<<(int)(a==b);
	p2=new int(2);
	GCPInfo<int> c(p2);
	cout<<(int)(a==c);*/
	
	return;
}