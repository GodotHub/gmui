#ifndef RENDER_OBJECT_WIDGET_CLASS_H
#define RENDER_OBJECT_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/render_object_elements/render_object_element.h"
#include "gmui/widgets/widget.h"

class Widget;
class RenderObjectElement;

using namespace godot;

class RenderObjectWidget : public Widget {
	GDCLASS(RenderObjectWidget, Widget);

public:
	RenderObjectWidget();
	virtual ~RenderObjectWidget();
	virtual RenderObjectElement *create_element() override = 0;
	virtual RenderObject *create_render_object() = 0;

protected:
	static void _bind_methods();
};

#endif // WIDGET_CLASS_H