GrafOnto uses Qt4. To run the application, QtCore4.dll and QtGui4.dll are needed. Application is compiled with dynamic linking, therefore version of Qt installed in the system does not matter unless PATH variable is modified so that it contains directory with those libraries. Executables with all needed libraries are provided, so changing PATH variable is not necessary.

If you would like to use Qt libraries installed in your system, add directory in which they are placed to the PATH system variable, and remove both provided .dll files.
