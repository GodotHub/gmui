#include "id.h"

bool ValueId::operator==(Identity &id) {
	return typeid(*this) == typeid(id) && typeid(id) == typeid(ValueId) ? value == ((ValueId &)id).value : false;
}
