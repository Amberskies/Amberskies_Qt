VS Code 
run from Developer Powershell for Visual Studio 2019

power shell may block .bat files 
use command :
    Set-ExecutionPolicy Unrestricted -Scope CurrentUser -Force

Try without -Force to begin with ( may not be needed )

eveything should now work from a bat file
eg :

build.bat :

cd build
REM nmake clean
C:/Qt/5.14.2/msvc2017_64/bin/qmake.exe ../
nmake -debug
