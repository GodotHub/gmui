#include "view_element.h"

Element::~Element() {}

void ViewElement::mount(Element *parent) {
}

void ViewElement::perform_rebuild() {
}

void ViewElement::insert_render_object_child(RenderObject *child) {
	((RenderView *)_render_object)->set_child(child);
}

void ViewElement::visit_children(const std::function<void(Element *child)> &visitor) {
	visitor(_child);
}

void ViewElement::_bind_methods() {
}