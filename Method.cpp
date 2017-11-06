
//Method.cpp
#include "stdafx.h"
#include "Method.h"
#include <strstream>

using namespace std;

//Error Messages
char const* IMethod::sm_szErrorMsg1 = "FileCrypt ERROR: Encryption/Decryption Object not Initialized!";
char const* IMethod::sm_szErrorMsg2 = "FileCrypt ERROR: Illegal Operation Mode!";
char const* IMethod::sm_szErrorMsg3 = "FileCrypt ERROR: Illegal Padding Mode!";
char const* IMethod::sm_szErrorMsg4 = "FileCrypt ERROR: No Key DataSpecified!";
char const* IMethod::sm_szErrorMsg5 = "FileCrypt ERROR: Key Data Length should be > 0!";
char const* IMethod::sm_szErrorMsg6 = "Illegal Block Size!";
char const* IMethod::sm_szErrorMsg7 = "FileCrypt ERROR: Cannot open File ";
char const* IMethod::sm_szErrorMsg8 = "FileCrypt ERROR: The same File for Input and Output ";
char const* IMethod::sm_szErrorMsg9 = "FileCrypt ERROR: File ";
char const* IMethod::sm_szErrorMsg10 = " cannot be Correctly Decrypted!";

//CONSTRUCTOR
IMethod::IMethod() : m_bInit(false)
{
}

//DESTRUCTOR
IMethod::~IMethod()
{
}

//Auxiliary Function
void IMethod::Xor(char* buff, char const* chain)
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	for(int i=0; i<m_blockSize; i++)
		*(buff++) ^= *(chain++);	
}

//Setting the Operation Mode
void IMethod::SetMode(int iMode)
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	if(iMode<ECB || iMode>CFB)
		throw runtime_error(string(sm_szErrorMsg2));
	m_iMode = iMode;
}

//Setting the Padding Mode
void IMethod::SetPadding(int iPadding)
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	if(iPadding<ZEROES || iPadding>PKCS7)
		throw runtime_error(string(sm_szErrorMsg3));
	m_iPadding = iPadding;
}

//Getters
int IMethod::GetKeyLength()
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	return m_keylength;
}

int IMethod::GetBlockSize()
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	return m_blockSize;
}

int IMethod::GetMode()
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	return m_iMode;
}

int IMethod::GetPadding()
{
	if(false==m_bInit)
		throw runtime_error(string(sm_szErrorMsg1));
	return m_iPadding;
}

//Padding the input string before encryption
int IMethod::Pad(char* in, int iLength)
{
// 	if(false==m_bInit)
// 		throw runtime_error(string(sm_szErrorMsg1));
	int iRes = iLength%m_blockSize;
	if(iRes != 0)
	{
		//Is the caller's responsability to ensure that in buffer is large enough
		int iPadded = m_blockSize - iRes;
		char* pin = in+iLength;
		for(int i=0; i<iPadded; i++, pin++)
			*pin = 0;
		return iLength + iPadded;
	}
	return iLength;
}

void IMethod::HelpThrow(string const& rostrFileIn)
{
	ostrstream ostr;
	ostr << "FileCrypt ERROR: Not an FileCrypt Encrypted File " << rostrFileIn << "!" << ends;
	string ostrMsg = ostr.str();
	ostr.freeze(false);
	throw runtime_error(ostrMsg);
}

void IMethod::BytesToWord(unsigned char const* pucBytes, unsigned int& ruiWord)
{
	ruiWord = 0;
	ruiWord |= (*(pucBytes++) & 0xFF) << 24;
	ruiWord |= (*(pucBytes++) & 0xFF) << 16;
	ruiWord |= (*(pucBytes++) & 0xFF) << 8;
	ruiWord |= *pucBytes & 0xFF;
}

void IMethod::WordToBytes(unsigned int uiWord, unsigned char* pucBytes)
{
	*(pucBytes++) = (uiWord>>24) & 0xFF;
	*(pucBytes++) = (uiWord>>16) & 0xFF;
	*(pucBytes++) = (uiWord>>8) & 0xFF;
	*pucBytes = uiWord & 0xFF;
}


