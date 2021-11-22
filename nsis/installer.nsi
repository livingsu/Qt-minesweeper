; installer.nsi

;--------------------------------

; The name of the installer
Name "Qt-Minesweeper"

; The file to write
OutFile "qtm.exe"

; The default installation directory
InstallDir $PROGRAMFILES\QtM

; The text to prompt the user to enter a directory
DirText "This will install Qt-Minesweeper on your computer. Choose a directory"

;--------------------------------

; The stuff to install
Section "" ;No components page, name is not important

; Set output path to the installation directory.
SetOutPath $INSTDIR

; Put file there
File qtm.exe

; Tell the compiler to write an uninstaller and to look for a "Uninstall" section
WriteUninstaller $INSTDIR\uninstall.exe

SectionEnd ; end the section

; The uninstall section
Section "Uninstall"

Delete $INSTDIR\uninstall.exe
Delete $INSTDIR\qtm.exe
RMDir $INSTDIR

SectionEnd 