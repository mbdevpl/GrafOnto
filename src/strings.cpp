#include "strings.h"

const std::string Strings::EmptyString = std::string();

const std::vector<std::string> Strings::EmptyStringArray = std::vector<std::string>();

void Strings::trimVector(std::vector<std::string>& vec) {
   int len = vec.size();
   if(len == 0)
      return;
   for(int i=0; i<len; i++) {
      //std::string& s = parsed[i];
      //parsed[i] = Strings::trim(s);
      if(vec[i].length() == 0)
         continue;
      Strings::trim(vec[i]);
   }
}

void Strings::cleanseVector(std::vector<std::string>& vec) {
   int len = vec.size();
   if(len == 0)
      return;
   for(int i=0; i<len; i++) {
      if(vec[i].compare(""))
         continue;
      vec.erase(vec.begin()+i);
      i--;
   }
}

std::vector<std::string> Strings::stringToArray(const std::string& longString, char separator) {
   int len = longString.length();
   if (len == 0)
      return EmptyStringArray;
   int options = 1;
   for (int i = 0; i < len; i++)
      if (longString.at(i) == separator)
         options++;
   std::vector<std::string> array;
   for(int i=0; i < options; i++)
      array.push_back(EmptyString);
   options = 0;
   int localLen = 0;
   for (int i = 0; i < len; i++) {
      if (longString.at(i) != separator && i != len - 1) {
         localLen++;
         continue;
      }
      if (localLen == 0) {
         array[options] = EmptyString;
         options++;
         continue;
      }
      int start = i - localLen;
      if (i == len - 1 && longString.at(i) != separator) {
         array[options] = longString.substr(start, i + 1 - start);
         localLen = 0;
         options++;
         continue;
      }
      array[options] = longString.substr(start, i - start);
      localLen = 0;
      options++;

   }
   if (longString.at(len - 1) == separator)
      array[options] = EmptyString;

   return array;
}
