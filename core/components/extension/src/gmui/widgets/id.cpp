#include "gmui/widgets/id.h"

bool ValueId::operator==(Identity &id) {
	return typeid(*this) == typeid(id) && typeid(id) == typeid(ValueId) ? value == ((ValueId &)id).value : false;
}

Variant ValueId::get_value() {
	return value;
}

void ValueId::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_value"), &ValueId::get_value);
}

Identity::Identity() {
}

Identity::~Identity() {
}

void Identity::_bind_methods() {
}

void LocalId::_bind_methods() {
}

void GlobalId::_bind_methods() {
}

void UniqueId::_bind_methods() {
}
