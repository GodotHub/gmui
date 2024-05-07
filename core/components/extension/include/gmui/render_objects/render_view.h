#ifndef RENDER_VIEW_CLASS_H
#define RENDER_VIEW_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/render_objects/render_box.h"
#include "gmui/render_objects/render_object.h"

using namespace godot;

class RenderView : public RenderObject {
	GDCLASS(RenderView, RenderObject);

public:
	void set_child(RenderBox *child);
	void adopt_child(RenderBox *child);
	void drop_child(RenderBox *child);

protected:
	RenderBox *_child;
	static void _bind_methods();
};

#endif