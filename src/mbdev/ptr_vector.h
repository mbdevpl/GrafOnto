#pragma once
#include <sstream>
#include "mbdev/toolkit.h"
#include "mbdev/vector.h"
#include "mbdev/string.h"

using namespace mbdev;

namespace mbdev {

template<typename T>
class ptr_vector : public vector<T*>
{
public:

   ptr_vector<T>() : vector<T*>() {
   }

//   ptr_vector<T> cleanse() {
//      return *this;
//   }

   virtual std::string toString() {
      std::stringstream ss;
      int size = this->size() - 1;
      ss << '[';
      for(int i = 0; i <= size ; i++) {
         ss << *(this->at(i));
         if(i < size)
            ss << ',';
      }
      ss << ']';
      return ss.str();
   }

};

}
