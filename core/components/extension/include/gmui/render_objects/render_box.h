#ifndef RENDER_BOX_CLASS_H
#define RENDER_BOX_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/render_objects/render_object.h"
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

class RenderBox : public RenderObject {
	GDCLASS(RenderBox, RenderObject);

	Vector2 size;

public:
	RenderBox();
	virtual ~RenderBox();
	void set_size(const Vector2 &size);
	Vector2 get_size();

protected:
	static void _bind_methods();
};

#endif