#ifndef __RENDER_OBJECT_WIDGET_H__
#define __RENDER_OBJECT_WIDGET_H__

#include "elements/render_object_element.hpp"
#include "render_objects/objects/render_object.hpp"
#include "widgets/widget.hpp"

using namespace godot;

class RenderObjectWidget : public Widget {
protected:
	virtual RenderObject *create_render_object() = 0;

public:
	virtual RenderObjectElement *create_element() override = 0;
};

#endif // __RENDER_OBJECT_WIDGET_H__