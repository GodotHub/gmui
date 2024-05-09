#ifndef MULTI_CHILD_RENDER_OBJECT_ELEMENT_CLASS_H
#define MULTI_CHILD_RENDER_OBJECT_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/render_object_elements/render_object_element.h"

using namespace godot;

class MultiChildRenderObjectElement : public RenderObjectElement {
	GDCLASS(MultiChildRenderObjectElement, RenderObjectElement);

public:
	void mount(Element *parent) override;

protected:
	TypedArray<Element> _children;
	static void _bind_methods();
};

#endif