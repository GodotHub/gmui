#ifndef __RENDER_OBJECT_ELEMENT_H__
#define __RENDER_OBJECT_ELEMENT_H__

#include "elements/element.hpp"
#include "render_objects/objects/render_object.hpp"
#include "widgets/widget.hpp"

using namespace godot;

class RenderObjectElement : public Element {
	RenderObject *_render_object;

public:
	using Element::Element;
};

#endif // __RENDER_OBJECT_ELEMENT_H__