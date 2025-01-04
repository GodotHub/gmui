#ifndef __MULTI_CHILD_RENDER_OBJECT_ELEMENT_H__
#define __MULTI_CHILD_RENDER_OBJECT_ELEMENT_H__

#include "elements/render_object_element.hpp"

class MultiChildRenderObjectElement : public RenderObjectElement {
	GDCLASS(MultiChildRenderObjectElement, RenderObjectElement);

public:
	using RenderObjectElement::RenderObjectElement;

	virtual void mount(Element *parent);
};

#endif // __MULTI_CHILD_RENDER_OBJECT_ELEMENT_H__