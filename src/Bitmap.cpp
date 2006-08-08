#include <malloc.h>
#include "PtrMacro.h"
#include "Bitmap.h"

using namespace Framework;

CBitmap::CBitmap(unsigned int nWidth, unsigned int nHeight, unsigned int nBPP)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
	m_nBPP = nBPP;
	m_pData = (uint8*)malloc(GetDataSize());
}

CBitmap::~CBitmap()
{
	FREEPTR(m_pData);
}

uint8* CBitmap::GetData()
{
	return m_pData;
}

unsigned int CBitmap::GetWidth()
{
	return m_nWidth;
}

unsigned int CBitmap::GetHeight()
{
	return m_nHeight;
}

unsigned int CBitmap::GetBitsPerPixel()
{
	return m_nBPP;
}

unsigned int CBitmap::GetDataSize()
{
	unsigned int nSize;
	nSize = m_nWidth * m_nHeight * m_nBPP;
	if(nSize % 8)
	{
		return (nSize / 8) + 1;
	}
	else
	{
		return (nSize / 8);
	}
}