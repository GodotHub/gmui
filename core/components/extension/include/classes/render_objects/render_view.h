#ifndef RENDER_VIEW_CLASS_H
#define RENDER_VIEW_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render_object.h"

using namespace godot;

class RenderView : public RenderObject {
	GDCLASS(RenderView, RenderObject);

public:
	void set_child(RenderObject *child);

protected:
	RenderObject *_child;
	static void _bind_methods();
};

#endif