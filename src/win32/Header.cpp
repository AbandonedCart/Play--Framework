#include <assert.h>
#include "win32/Header.h"

using namespace Framework;
using namespace Framework::Win32;

CHeader::CHeader(HWND hParent, RECT* pRect, unsigned long nStyle, unsigned long nExStyle)
{
	InitCommonControls();
	Create(nExStyle, WC_HEADER, _T(""), WS_CHILD | WS_VISIBLE | nStyle, pRect, hParent, NULL);
}

int CHeader::InsertItem(const TCHAR* sText)
{
	HDITEM Item;

	memset(&Item, 0, sizeof(HDITEM));
	Item.mask		= HDI_TEXT;
	Item.pszText	= const_cast<TCHAR*>(sText);

	return InsertItem(GetItemCount(), &Item);
}

int CHeader::InsertItem(const TCHAR* sText, unsigned int nSize)
{
	HDITEM Item;
	
	memset(&Item, 0, sizeof(HDITEM));
	Item.mask		= HDI_TEXT | HDI_WIDTH;
	Item.pszText	= const_cast<TCHAR*>(sText);
	Item.cxy		= nSize;

	return InsertItem(GetItemCount(), &Item);
}

int CHeader::InsertItem(unsigned int nIndex, HDITEM* pItem)
{
	return Header_InsertItem(m_hWnd, nIndex, pItem);
}

void CHeader::GetItemRect(unsigned int nIndex, RECT* pRect)
{
	assert(pRect != NULL);
	Header_GetItemRect(m_hWnd, nIndex, pRect);
}

int CHeader::GetItemCount()
{
	return Header_GetItemCount(m_hWnd);
}
