#pragma once
#include <list>
#include "GCPInfo.h"
using namespace std;
template<class T>
class GCPtr
{
public:
	static list<GCPInfo<T>> sm_GCPList;//c++11ÐÂ±ê×¼
public:
	GCPtr(void);
	virtual ~GCPtr(void);
};

