#include "component_element.h"

using namespace godot;

void ComponentElement::mount(Element *parent) {
	Element::mount(parent);
	DEV_ASSERT(_child == nullptr);
	DEV_ASSERT(_lifecycle == ACTIVE);
	_first_build();
	DEV_ASSERT(_child);
}

void ComponentElement::perform_rebuild() {
	Widget *built;
	try {
		built = build();
	} catch (const std::exception &e) {
	}
	Element::perform_rebuild();
	try {
		_child = update_child(_child, built);
		DEV_ASSERT(_child);
	} catch (const std::exception &e) {
		ERR_FAIL_EDMSG(e.what());
	}
}

void ComponentElement::_first_build() {
	rebuild();
}
