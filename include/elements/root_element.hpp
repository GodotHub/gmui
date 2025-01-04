#ifndef __ROOT_ELEMENT_H__
#define __ROOT_ELEMENT_H__

#include "elements/multi_child_render_object_element.hpp"

class RootElement : public MultiChildRenderObjectElement {
	GDCLASS(RootElement, MultiChildRenderObjectElement);

public:
	using MultiChildRenderObjectElement::MultiChildRenderObjectElement;
};

#endif // __ROOT_ELEMENT_H__