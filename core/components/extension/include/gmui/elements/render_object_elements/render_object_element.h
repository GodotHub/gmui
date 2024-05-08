#ifndef RENDER_OBJECT_ELEMENT_CLASS_H
#define RENDER_OBJECT_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/element.h"
#include "gmui/render_objects/render_object.h"
#include "gmui/widgets/widget.h"

using namespace godot;

class RenderObjectElement : public Element {
	GDCLASS(RenderObjectElement, Element);

public:
	using Element::Element;
	virtual ~RenderObjectElement();
	virtual void mount(Element *parent) override;
	virtual void attach_render_object() override;
	virtual void insert_render_object_child(RenderObject *child) = 0;
	virtual void visit_children(const std::function<void(Element *child)> &visitor) override = 0;

protected:
	RenderObject *_render_object;
	RenderObjectElement *_ancestor_render_object_element;
	static void _bind_methods();

private:
	RenderObjectElement *find_ancestor_render_object_element();
};

#endif