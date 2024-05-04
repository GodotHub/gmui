#include "root_element.h"

using namespace godot;

void RootElement::set_child(Element *child) {
	_child = child;
}

void RootElement::mount(Element *parent) {
	DEV_ASSERT(parent == nullptr);
	Element::mount(parent);
	_rebuild();
	DEV_ASSERT(_child);
	Element::perform_rebuild();
}

void RootElement::_rebuild() {
	try {
		_child = update_child(_child, ((RootWidget *)_widget)->get_child());
	} catch (const std::exception &e) {
		ERR_FAIL_EDMSG("update_child fail!\n" + *(e.what()));
		_child = nullptr;
	}
}

void RootElement::perform_rebuild() {}