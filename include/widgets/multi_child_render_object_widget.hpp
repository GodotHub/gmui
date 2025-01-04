#ifndef __MULTI_CHILD_RENDER_OBJECT_WIDGET_H__
#define __MULTI_CHILD_RENDER_OBJECT_WIDGET_H__

#include "elements/multi_child_render_object_element.hpp"
#include "widgets/render_object_widget.hpp"
#include <godot_cpp/templates/list.hpp>

using namespace godot;

class MultiChildRenderObjectWidget : public RenderObjectWidget {
	GDCLASS(MultiChildRenderObjectWidget, RenderObjectWidget);

	List<Widget *> _children;

public:
	List<Widget *> get_children();

	virtual MultiChildRenderObjectElement *create_element() override;
};

#endif // __MULTI_CHILD_RENDER_OBJECT_WIDGET_H__