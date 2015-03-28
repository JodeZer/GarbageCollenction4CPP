#pragma once
template<class T>
class GCPInfo
{
public:
	T* m_menPtr;//指向已分配内存
	int m_refCount;//用无符号，万一哪个地方手抖那不是虚了
	bool m_isArray;//是否数组
	unsigned int m_arraySize;//数组大小
public:
	GCPInfo<T>(T* mptr,int size=0):m_refCount(1),m_menPtr(mptr)
	  {
		  if(0==size)
			  m_isArray=false;
		  else 
			  m_isArray=true;
      }

	bool operator==(const GCPInfo<T> &obj1)
	{
		return m_menPtr==obj1.m_menPtr;
	}
	GCPInfo &operator=(const GCPInfo<T> &obj)
	{

	}
	virtual ~GCPInfo(void)
	{
	}

};

