#pragma once 
#include "HPSocket.h"
#include "SocketInterface.h"
#include  <cassert>
#include "BufferPtr.h"
using namespace std;

//Test 
struct TPkgHeader 
{
	DWORD seq;
	int body_len;
};
//Test 
struct TPkgBody 
{
	char name[30];
	short age;
	char desc[1];
};

struct TPkgInfo
{
	bool is_header;
	int length;

	TPkgInfo(bool header = true, int len = sizeof(TPkgHeader)) : is_header(header), length(len) {}
	void Reset() {is_header = true, length = sizeof(TPkgHeader);}
	~TPkgInfo() {}
};

inline TPkgInfo* ConstructPkgInfo()
{
	return new TPkgInfo(true, sizeof(TPkgHeader));
}

inline void DestructPkgInfo(TPkgInfo* pInfo)
{
	delete pInfo;
}

template<class T, typename = enable_if_t<!is_void<decay_t<T>>::value>>
inline TPkgInfo* CreatePkgInfo(T* pSender, CONNID dwConnID)
{
	TPkgInfo* pInfo = ConstructPkgInfo();
	pSender->SetConnectionExtra(dwConnID, pInfo);

	return pInfo;
}

template<class T, typename = enable_if_t<!is_void<decay_t<T>>::value>>
inline TPkgInfo* FindPkgInfo(T* pSender, CONNID dwConnID)
{
	PVOID pInfo = nullptr;
	pSender->GetConnectionExtra(dwConnID, &pInfo);

	return (TPkgInfo*)pInfo;
}

template<class T, typename = enable_if_t<!is_void<decay_t<T>>::value>>
inline void RemovePkgInfo(T* pSender, CONNID dwConnID)
{
	TPkgInfo* pInfo = FindPkgInfo(pSender, dwConnID);
	assert(pInfo != nullptr);
	DestructPkgInfo(pInfo);
}
