REM Copies most recently compiled executables to /bin directory

REM Release
COPY /Y /B build_console_release\release\grafonto.exe bin\windows\grafonto_console.exe
COPY /Y /B build_gui_release\release\grafonto.exe bin\windows\grafonto.exe

REM Debug
REM COPY /Y /B build_console_debug\debug\grafonto.exe bin\windows_debug\grafonto_console.exe
REM COPY /Y /B build_gui_debug\debug\grafonto.exe bin\windows_debug\grafonto.exe
