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
