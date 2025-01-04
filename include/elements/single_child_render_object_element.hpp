#ifndef __SINGLE_CHILD_RENDER_OBJECT_ELEMENT_H__
#define __SINGLE_CHILD_RENDER_OBJECT_ELEMENT_H__

#include "elements/render_object_element.hpp"

using namespace godot;

class SingleChildRenderObjectElement : public RenderObjectElement {
	Element *_child;
};

#endif // __SINGLE_CHILD_RENDER_OBJECT_ELEMENT_H__