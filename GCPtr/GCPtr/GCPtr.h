#pragma once
#include <list>
#include "GCPInfo.h"
using namespace std;
template<class T>
class GCPtr
{
public:
	static list<GCPInfo<T>> sm_GCPList;//c++11�±�׼
public:
	GCPtr(void);
	virtual ~GCPtr(void);
};

