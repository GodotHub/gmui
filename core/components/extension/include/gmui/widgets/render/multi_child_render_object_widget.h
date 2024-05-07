#ifndef MULTI_CHILD_RENDER_OBJECT_WIDGET_CLASS_H
#define MULTI_CHILD_RENDER_OBJECT_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/render_object_elements/multi_child_render_object_element.h"
#include "gmui/widgets/render/render_object_widget.h"

using namespace godot;

class MultiChildRenderObjectWidget : public RenderObjectWidget {
	GDCLASS(MultiChildRenderObjectWidget, RenderObjectWidget);

public:
	MultiChildRenderObjectWidget();
	virtual ~MultiChildRenderObjectWidget();
	TypedArray<Widget> get_children() const;
	virtual MultiChildRenderObjectElement *create_element() override = 0;
	virtual RenderObject *create_render_object() = 0;

protected:
	TypedArray<Widget> _children = {};
	static void _bind_methods();
};

#endif // WIDGET_CLASS_H