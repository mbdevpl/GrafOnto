#pragma once
#include <algorithm>
#include <cctype>
#include <functional>
#include <locale>
#include <string>
#include <vector>

/*!
  \brief name that is easier to use
  */
typedef std::vector<std::string> StringVector;

/*!
  \brief Utility class used to handle strings and vectors of strings.
  */
class Strings {
public:
   /*!
     \brief String of length zero.
     */
   static const std::string EmptyString;
   /*!
     \brief STL vector with no elements.
     */
   static const StringVector EmptyStringArray;

   static void trimVector(std::vector<std::string>& vector);

   static void cleanseVector(std::vector<std::string>& vector);
   /*!
     \brief Makes a string vector out of string with separators and a sample
         of a separator. If a symbol is a separator it can't be at the same time
         used as a symbol in any member string.

     \param longString given string
     \param separator the separator
     \return long string parsed using a given separator
     */
   static std::vector<std::string> stringToArray(const std::string& longString, char separator);
   /*!
     \brief Trims a given string from start.

     \param s string to be trimmed, in-out argument
     \return reference to the same string
     */
   static inline std::string& ltrim(std::string &s);
   /*!
     \brief Trims a given string from end.

     \param s string to be trimmed, in-out argument
     \return reference to the same string
     */
   static inline std::string& rtrim(std::string &s);
   /*!
     \brief Trims a given string from both ends.

     \param s string to be trimmed, in-out argument
     \return reference to the same string
     */
   static inline std::string& trim(std::string &s);
};

inline std::string& Strings::ltrim(std::string &s) {
   s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
   return s;
}

inline std::string& Strings::rtrim(std::string &s) {
   s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
   return s;
}

inline std::string& Strings::trim(std::string &s) {
   return ltrim(rtrim(s));
}
