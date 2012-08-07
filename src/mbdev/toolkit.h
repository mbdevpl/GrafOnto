#pragma once
//for getch
#include <cstdio>
#include <unistd.h>
#include <termios.h>

#ifndef nullptr
#define nullptr NULL
#endif

namespace mbdev {

template <typename T, size_t N>
char (&array(T(&)[N]))[N];

char getch();

}
