#ifndef GD_VIEW_CLASS_H
#define GD_VIEW_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/world2d.hpp>
#include <godot_cpp/variant/callable_method_pointer.hpp>

using namespace godot;

#define RS RenderingServer::get_singleton()

class GDView : public Object {
	GDCLASS(GDView, Object);

	RID viewport;
	RID canvas;

public:
	GDView(Viewport *viewport);
	~GDView();
	void render();

protected:
	static void _bind_methods();
};

#endif