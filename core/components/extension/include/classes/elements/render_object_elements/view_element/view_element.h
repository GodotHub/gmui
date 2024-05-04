#ifndef VIEW_ELEMENT_CLASS_H
#define VIEW_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render_object_element.h"
#include "render_view.h"

using namespace godot;

class ViewElement : public RenderObjectElement {
	GDCLASS(ViewElement, RenderObjectElement);

public:
	using RenderObjectElement::RenderObjectElement;
	virtual void mount(Element *parent) override;
	virtual void perform_rebuild() override;
	virtual void insert_render_object_child(RenderObject *child) override;
	virtual void visit_children(const std::function<void(Element *child)> &visitor);

protected:
	Widget *_widget;
	Element *_child;
	static void _bind_methods();
};

#endif