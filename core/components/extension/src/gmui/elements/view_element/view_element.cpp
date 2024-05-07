#include <gmui/elements/render_object_elements/view_element/view_element.h>

ViewElement::~ViewElement() {
}
void ViewElement::mount(Element *parent) {
}

void ViewElement::perform_rebuild() {
}

void ViewElement::insert_render_object_child(RenderObject *child) {
	((RenderView *)_render_object)->set_child((RenderBox *)child);
}

void ViewElement::visit_children(const std::function<void(Element *child)> &visitor) {
	visitor(_child);
}

Widget *ViewElement::get_widget() {
	return _widget;
}

BuildOwner *ViewElement::get_owner() {
	return _builder;
}

void ViewElement::_bind_methods() {
}
