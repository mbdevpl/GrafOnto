#pragma once
#ifdef LINUX
//for getch:
#include <cstdio>
#include <unistd.h>
#include <termios.h>
#endif

#ifdef WINDOWS
#include <conio.h>
#endif

#ifndef nullptr
#define nullptr NULL
#endif

namespace mbdev {

//template <typename T, size_t N>
//char (&array(T(&)[N]))[N];

char getch();

}
