#ifndef RENDER_OBJECT_WIDGET_CLASS_H
#define RENDER_OBJECT_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render_object_element.h"
#include "widget.h"

using namespace godot;

class RenderObjectWidget : public Widget {
	GDCLASS(RenderObjectWidget, Widget);

public:
	RenderObjectWidget();
	~RenderObjectWidget();
	virtual RenderObjectElement *create_element() override = 0;
	virtual RenderObject *create_render_object() = 0;

protected:
	static void _bind_methods();
};

#endif // WIDGET_CLASS_H