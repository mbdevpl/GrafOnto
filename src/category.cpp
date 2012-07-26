#include "category.h"

Category::Category(std::string& name)
   : Node(name) {
}

Category::Category(std::string& name, std::string& friendlyName)
   : Node(name, friendlyName) {
}
