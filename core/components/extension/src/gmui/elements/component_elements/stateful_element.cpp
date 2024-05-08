#include "gmui/elements/component_elements/stateful_element.h"
#include "gmui/elements/build_context.h"
#include "gmui/widgets/stateful/stateful_widget.h"
#include <godot_cpp/core/memory.hpp>

StatefulElement::~StatefulElement() {
}

Widget *StatefulElement::build() {
	return ((StatefulWidget *)_widget)->_build(memnew(BuildContext(this)));
}

void StatefulElement::_bind_methods() {
}
