#include "render_object_element.h"

void RenderObjectElement::mount(Element *parent) {
	Element::mount(parent);
	_render_object = ((RenderObjectWidget *)_widget)->create_render_object();
	attach_render_object();
	Element::perform_rebuild();
}

void RenderObjectElement::attach_render_object() {
	_ancestor_render_object_rlement = find_ancestor_render_object_element();
	_ancestor_render_object_rlement->insert_render_object_child(_render_object);
}

RenderObjectElement *RenderObjectElement::find_ancestor_render_object_element() {
	Element *ancestor = _parent;
	while (ancestor && typeid(ancestor) != typeid(RenderObjectElement)) {
		ancestor = ancestor->get_parent();
	}
	return (RenderObjectElement *)ancestor;
}
