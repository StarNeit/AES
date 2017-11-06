; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAESDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AES.h"

ClassCount=3
Class1=CAESApp
Class2=CAESDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AES_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_AES_DIALOG (English (U.S.))

[CLS:CAESApp]
Type=0
HeaderFile=AES.h
ImplementationFile=AES.cpp
Filter=N

[CLS:CAESDlg]
Type=0
HeaderFile=AESDlg.h
ImplementationFile=AESDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=AESDlg.h
ImplementationFile=AESDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_AES_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CAESDlg

[DLG:IDD_AES_DIALOG (English (U.S.))]
Type=1
Class=CAESDlg
ControlCount=4
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

