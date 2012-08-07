#include "string.h"

namespace mbdev {

const std::string string::emptyStdStr = std::string();

const string string::emptyStr = string();

string::string() : std::string() {
}

//string::string(size_t capacity)
//   : std::string(capacity) {
//}

string::string(const char source) : std::string(&source, 1) {
}

string::string(const char* source) : std::string(source) {
}

string::string(const std::string& source) : std::string(source) {
}

string::string(const string& source) : std::string(source) {
}

bool string::equals(const string& s) const {
   return ( this->compare( (const std::string&)s ) ) == 0;
}

string_vector string::toVector(const char separator) const {
   int len = length();
   if (len == 0)
      return string_vector::empty;
   int options = 1;
   for (int i = 0; i < len; i++)
      if (this->at(i) == separator)
         options++;
   string_vector vec;
   for(int i=0; i < options; i++)
      vec.push_back(string::emptyStr);
   options = 0;
   int localLen = 0;
   for (int i = 0; i < len; i++) {
      if (at(i) != separator && i != len - 1) {
         localLen++;
         continue;
      }
      if (localLen == 0) {
         vec[options] = string::emptyStr;
         options++;
         continue;
      }
      int start = i - localLen;
      if (i == len - 1 && at(i) != separator) {
         vec[options] = substr(start, i + 1 - start);
         localLen = 0;
         options++;
         continue;
      }
      vec[options] = substr(start, i - start);
      localLen = 0;
      options++;

   }
   if (at(len - 1) == separator)
      vec[options] = string::emptyStr;

   return vec;
}

std::ostream& operator<<(std::ostream& os, const string& s) {
   return os << (std::string)s;
}

}
