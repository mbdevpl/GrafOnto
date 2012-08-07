#pragma once
#include <sstream>
#include "mbdev/string.h"
#include "mbdev/vector.h"
#include "mbdev/toolkit.h"

namespace mbdev {

class string; // for dependancies

class string_vector : public vector<string> {
public:
   /*!
     \brief STL vector with no elements.
     */
   static const string_vector empty;
   string_vector();
   int indexContains(const string& str);
   inline void push_back(const string& str);
   void push_back(int argc, const char** argv);
   string_vector& trim();
   string_vector& cleanse();
   string str(const string& separator, int pos = 0, size_t n = std::string::npos) const;
   string str(const char separator, int pos = 0, size_t n = std::string::npos) const;
   string str(int pos = 0, size_t n = std::string::npos) const;
};

inline void string_vector::push_back(const string& str) {
   ((vector<string>*)this)->push_back(str);
}

}
