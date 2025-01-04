#ifndef __SINGLE_CHILD_RENDER_OBJECT_WIDGET_H__
#define __SINGLE_CHILD_RENDER_OBJECT_WIDGET_H__

#include "elements/single_child_render_object_element.hpp"
#include "widgets/render_object_widget.hpp"

using namespace godot;

class SingleChildRenderObjectWidget : public RenderObjectWidget {
	Widget *child;

protected:
	virtual RenderObject *create_render_object() override;

public:
	virtual SingleChildRenderObjectElement *create_element() override;
};

#endif // __SINGLE_CHILD_RENDER_OBJECT_WIDGET_H__