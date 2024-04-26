#ifndef WIDGET_CLASS_H
#define WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render.h"

using namespace godot;

class Widget : public Render {
	GDCLASS(Widget, Render);

protected:
	static void _bind_methods();

public:
	Widget();
	~Widget();
};

#endif // WIDGET_CLASS_H