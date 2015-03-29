#pragma once
#include <list>
#include "GCPInfo.h"
using namespace std;
template<class T>
class GCPtr
{
public:
	static list<GCPInfo<T>> sm_GCPList;//c++11新标准
	GCPInfo<T> m_this;
	static bool isFirst;//不知道什么意思，照抄的
public:
	GCPtr(T *p=nullptr,int size=0)
	{
		if(first)
			atexit(shutdown);//不知道什么意思，照抄的
		first=false;
		m_this=new GCPInfo(p,size);
		list<GCPInfo<T>>::iterator it;
		it=find(p);
		if(it==sm_GCPList.end())
			sm_GCPList.push_front(m_this);
		else
			it->m_refCount++;


	}
	virtual ~GCPtr(void)
	{
		list<GCPInfo<T>>::iterator it=find(m_this.m_menPtr);
		it->m_refCount--;
	}

private:
	typename list<GCPInfo<T>>::iterator find(T *ptr)//typename的目的是告诉编译器这是一个类型，否则不能通过语法检查
	{
		list<GCPInfo<T>>::iterator it;

		for(it=sm_GCPList.begin();it!=sm_GCPList.end();it++)
		{
			if(it->m_menPtr==ptr)
				return it;
		}
		return it;

	}

	void collect(void)
	{
		list<GCPInfo<T>>::iterator it;
		for(it=sm_GCPList.begin();it!=sm_GCPList.end();it++)
		{
			if(it->m_refCount<=0)
			{
				delete it->m_menPtr;
				sm_GCPList.erase(it);
			}
		}
	}

};

