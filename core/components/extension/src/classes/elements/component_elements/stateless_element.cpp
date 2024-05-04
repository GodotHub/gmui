#include "stateless_element.h"

using namespace godot;

Widget *StatelessElement::build() {
	return ((StatelessWidget *)_widget)->build(*this);
}