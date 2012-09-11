REM Copies most recently compiled executables to /bin directory

REM Console
COPY /Y /B ..\bin_console_qt481_msvc2010_release\release\grafonto.exe ..\bin\windows\grafonto_console.exe
REM Console x64
COPY /Y /B ..\bin_console_qt481_msvc2010_x64_release\release\grafonto.exe ..\bin\windows\grafonto_x64_console.exe

REM GUI
COPY /Y /B ..\bin_qt481_msvc2010_release\release\grafonto.exe ..\bin\windows\grafonto.exe
REM GUI x64
COPY /Y /B ..\bin_qt481_msvc2010_x64_release\release\grafonto.exe ..\bin\windows\grafonto_x64.exe
