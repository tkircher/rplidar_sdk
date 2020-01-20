/*
 *  RPLIDAR
 *  Win32 Demo Application
 *
 *  Copyright (c) 2016 - 2020 Shanghai Slamtec Co., Ltd.
 *  http://www.slamtec.com
 *
 */
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// IpConfigDlg.cpp : implementation of the CIpConfigDlg class
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"
#include "drvlogic\lidarmgr.h"
#include "IpConfigDlg.h"

unsigned char CIpConfigDlg::ip_[32] = {0};
unsigned char CIpConfigDlg::mask_[32] = {0};
unsigned char CIpConfigDlg::gw_[32] = {0};

CIpConfigDlg::CIpConfigDlg()
{

}

LRESULT CIpConfigDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
    CenterWindow(GetParent());
    this->DoDataExchange();
    m_ip.SetWindowTextA(CString(ip_));
    m_mask.SetWindowTextA(CString(mask_));
    m_gw.SetWindowTextA(CString(gw_));
    return TRUE;
}

LRESULT CIpConfigDlg::OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

    unsigned char sel[4];
    m_ip.GetAddress((LPDWORD)sel);
    sprintf((char *)ip_, "%u.%u.%u.%u", sel[3], sel[2], sel[1], sel[0]);

    m_mask.GetAddress((LPDWORD)sel);
    sprintf((char*)mask_, "%u.%u.%u.%u", sel[3], sel[2], sel[1], sel[0]);

    m_gw.GetAddress((LPDWORD)sel);
    sprintf((char*)gw_, "%u.%u.%u.%u", sel[3], sel[2], sel[1], sel[0]);

    EndDialog(wID);
    return 0;
}

LRESULT CIpConfigDlg::OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    EndDialog(wID);
    return 0;
}
