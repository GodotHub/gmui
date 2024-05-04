#include "multi_child_render_object_element.h"

void MultiChildRenderObjectElement::mount(Element *parent) {
	RenderObjectElement::mount(parent);
	const MultiChildRenderObjectWidget *widget = (MultiChildRenderObjectWidget *)_widget;
	TypedArray<Widget *> children = {};
	for (int i = 0; i < widget->get_children().size(); i++) {
		Element *new_child = inflact_widget((Widget *)widget->get_children()[i]._native_ptr());
		children.append(new_child);
	}
	_children = children;
}