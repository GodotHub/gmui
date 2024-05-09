#include "gmui/elements/component_elements/component_element.h"

ComponentElement::~ComponentElement() {
}

void ComponentElement::mount(Element *parent) {
	Element::mount(parent);
	DEV_ASSERT(_child == nullptr);
	DEV_ASSERT(_lifecycle == ACTIVE);
	_first_build();
	DEV_ASSERT(_child);
}

void ComponentElement::perform_rebuild() {
	Widget *built;
	built = build();
	ERR_FAIL_NULL(built);
	Element::perform_rebuild();
	_child = update_child(_child, built);
	ERR_FAIL_NULL(_child);
}

void ComponentElement::_first_build() {
	rebuild();
}

void ComponentElement::_bind_methods() {
}
