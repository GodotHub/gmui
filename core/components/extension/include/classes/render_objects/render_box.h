#ifndef RENDER_BOX_CLASS_H
#define RENDER_BOX_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render_object.h"

using namespace godot;

class RenderBox : public RenderObject {
	GDCLASS(RenderBox, RenderObject);

	Vector2 size;

public:
	RenderBox();
	~RenderBox();
	void set_size(Vector2 size);
	Vector2 get_size();

protected:
	static void _bind_methods();
};

#endif