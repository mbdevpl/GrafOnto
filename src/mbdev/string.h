#pragma once
//superclass
#include <string>
//for ostream operator<<
#include <ostream>
//for trim
#include <algorithm>
#include <cctype>
#include <functional>
#include <locale>
//other
#include "mbdev/string_vector.h"

namespace mbdev {

class string_vector;

class string : public std::string {
public:
   /*!
     \brief Std string of length zero.
    */
   static const std::string emptyStdStr;
   /*!
     \brief String of length zero.
     */
   static const string emptyStr;

   string();
   //string(size_t capacity);
   string(const char source);
   string(const char* source);
   string(const std::string& source);
   string(const string& source);
   /*!
     \brief Trims a given string from start.

     \return reference to the same string
     */
   inline string& ltrim();
   /*!
     \brief Trims a given string from end.

     \return reference to the same string
     */
   inline string& rtrim();
   /*!
     \brief Trims a given string from both ends.

     \return reference to the same string
     */
   inline string& trim();
   bool equals(const string& s) const;
   // \param s string to be trimmed, in-out argument
   /*!
     \brief Makes a string vector out of string with separators and a sample
         of a separator. If a symbol is a separator it can't be at the same time
         used as a symbol in any member substring.

     \param separator the separator
     */
   string_vector toVector(const char separator) const;
   //  \param longString given string
   friend std::ostream& operator<<(std::ostream& os, const string& s);

};

inline string& string::ltrim() {
   string& s = *this;
   s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
   return s;
}

inline string& string::rtrim() {
   string& s = *this;
   s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
   return s;
}

inline string& string::trim() {
   return rtrim().ltrim();
}

}
