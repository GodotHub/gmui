#include <gmui/elements/root_element.h>

using namespace godot;

RootElement::~RootElement() {
}

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
	_child = update_child(_child, ((RootWidget *)_widget)->get_child());
}

void RootElement::perform_rebuild() {}

void RootElement::visit_children(const std::function<void(Element *child)> &visitor) {
}

void RootElement::_bind_methods() {
}