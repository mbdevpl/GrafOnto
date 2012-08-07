#include "string_vector.h"

namespace mbdev {

const string_vector string_vector::empty = string_vector();

string_vector::string_vector() : vector<string>() {
}

int string_vector::indexContains(const string& str) {
   size_t size = this->size();
   if(size == 0)
      return -1;
   for(size_t i=0; i<size; i++) {
      string& s = at(i);
      size_type index = s.find_first_of(str);
      if(index == string::npos)
         continue;
      return i;
   }
   return -1;
}

void string_vector::push_back(int argc, const char** argv) {
   //int a = 0;
   //a = sizeof(array(argv));
   for(int i=0; i<argc; i++)
      this->push_back(argv[i]);
}

string_vector& string_vector::trim() {
   size_t size = this->size();
   if(size == 0)
      return *this;
   for(size_t i=0; i<size; i++) {
      //std::string& s = parsed[i];
      //parsed[i] = Strings::trim(s);
      if(at(i).length() == 0)
         continue;
      at(i).trim();
   }
   return *this;
}

string_vector& string_vector::cleanse() {
   int len = size();
   if(len == 0)
      return *this;
   for(int i=len-1; i>=0; i--) {
      if(!at(i).empty())
         continue;
      erase(begin() + i);
      //vec.erase(vec.begin() + i, vec.begin() + i + 1);
   }
   return *this;
}

string string_vector::str(const string& separator, int pos, size_t n) const {
   std::stringstream ss;
   size_t size = this->size();
   if(size == 0)
      return string::emptyStr;
   int beg = 0;
   if(pos > 0 && (size_t)pos < size)
      beg = pos;
   int end = size;
   if(n != std::string::npos && beg + n < size)
      end = pos+n;
   if(!separator.compare(string::emptyStr)) {
      for(int i=beg; i<end; i++) {
         ss << at(i);
      }
   } else {
      for(int i=beg; i<end; i++) {
         if(i > beg)
            ss << separator;
         ss << at(i);
      }
   }
   return string(ss.str());
}

string string_vector::str(const char separator, int pos, size_t n) const {
   return str(string(separator), pos, n);
}

string string_vector::str(int pos, size_t n) const {
   return str(string::emptyStr, pos, n);
}

}
