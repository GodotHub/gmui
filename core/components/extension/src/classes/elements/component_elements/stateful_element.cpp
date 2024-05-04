#include "stateful_element.h"

using namespace godot;

Widget *StatefulElement::build() {
	return ((StatefulWidget *)_widget)->build(*this);
}