; installer.nsi

;--------------------------------

!pragma warning error all

;--------------------------------
;Include Modern UI

  !include "MUI2.nsh"

;--------------------------------
;General

  ;Properly display all languages (Installer will not work on Windows 95, 98 or ME!)
  Unicode true

  ;Name and file
  Name "Qt-Minesweeper"
  OutFile "QtM-1.0-win64-x64.exe"

  ;Default installation folder
  InstallDir "C:\QtM"

  ;Request application privileges for Windows Vista
  RequestExecutionLevel user

;--------------------------------
;Interface Settings

  !define MUI_ABORTWARNING

  ;Show all languages, despite user's codepage
  !define MUI_LANGDLL_ALLLANGUAGES

;--------------------------------
;Pages

  !insertmacro MUI_PAGE_WELCOME
  !insertmacro MUI_PAGE_LICENSE "files\license.txt"
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  !insertmacro MUI_PAGE_FINISH
  
  !insertmacro MUI_UNPAGE_WELCOME
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_LICENSE "files\license.txt"
  !insertmacro MUI_UNPAGE_DIRECTORY
  !insertmacro MUI_UNPAGE_INSTFILES
  !insertmacro MUI_UNPAGE_FINISH

;--------------------------------
;Language Selection Dialog Settings

;--------------------------------
;Languages

  !insertmacro MUI_LANGUAGE "English" ; The first language is the default language
  !insertmacro MUI_LANGUAGE "SimpChinese"
  !insertmacro MUI_LANGUAGE "Czech"

;--------------------------------
;Reserve Files
  
  ;If you are using solid compression, files that are required before
  ;the actual installation should be stored first in the data block,
  ;because this will make your installer start faster.
  
  !insertmacro MUI_RESERVEFILE_LANGDLL

;--------------------------------
;Installer Sections

Section "Main Section" SecMain

  ; Set output path to the installation directory.
  SetOutPath $INSTDIR

  ; Put file there
  File qtm.exe
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\uninstall.exe"

SectionEnd

;--------------------------------
;Installer Functions

Function .onInit

  !insertmacro MUI_LANGDLL_DISPLAY

FunctionEnd
 
;--------------------------------
;Uninstaller Section

Section "uninstall"

  Delete $INSTDIR\uninstall.exe
  Delete $INSTDIR\qtm.exe
  RMDir $INSTDIR

SectionEnd

;--------------------------------
;Uninstaller Functions

Function un.onInit

  !insertmacro MUI_UNGETLANGUAGE
  
FunctionEnd