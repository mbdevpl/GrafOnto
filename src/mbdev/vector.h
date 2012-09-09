#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "mbdev/toolkit.h"

namespace mbdev {

template<typename T>
class vector : public std::vector<T> {
public:

   vector<T>() : std::vector<T>() {
   }

   vector<T>(size_t n) : std::vector<T>(n) {
   }

   int indexOf(T element) const {
      size_t size = this->size();
      for(size_t i=0; i<size; i++)
         if(this->at(i) == element)
            return i;
      return -1;
   }

   virtual std::string toString() {
      std::stringstream ss;
      int size = this->size() - 1;
      ss << '[';
      for(int i = 0; i <= size ; i++) {
         ss << this->at(i);
         if(i < size)
            ss << ',';
      }
      ss << ']';
      return ss.str();
   }

   vector<T>& operator+=(const vector<T>& vec) {
      size_t size = vec.size();
      if(size == 0)
         return *this;
      for(size_t i=0; i<size; i++) {
         this->push_back(vec[i]);
      }
      return *this;
   }
};

}
