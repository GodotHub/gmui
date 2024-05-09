#include "gmui/elements/component_elements/stateless_element.h"
#include "gmui/elements/build_context.h"
#include "gmui/widgets/stateless/stateless_widget.h"
#include <godot_cpp/core/memory.hpp>

StatelessElement::~StatelessElement() {
}

Widget *StatelessElement::build() {
	return ((StatelessWidget *)_widget)->_build(memnew(BuildContext(this)));
}

void StatelessElement::_bind_methods() {
}
