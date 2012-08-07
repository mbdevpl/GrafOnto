#include "category.h"

namespace mbdev_ontology {

category::category(string& name)
   : node(name) {
}

category::category(string& name, string& friendlyName)
   : node(name, friendlyName) {
}

}
