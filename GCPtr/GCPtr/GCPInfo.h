#pragma once
template<class T>
class GCPInfo
{
public:
	T* m_menPtr;//ָ���ѷ����ڴ�
	int m_refCount;//���޷��ţ���һ�ĸ��ط��ֶ��ǲ�������
	bool m_isArray;//�Ƿ�����
	unsigned int m_arraySize;//�����С
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

