#ifndef RENDER_CLASS_H
#define RENDER_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <type_traits>

using namespace godot;

#define RS RenderingServer::get_singleton()

class App;

class RenderObject : public RefCounted {
	GDCLASS(RenderObject, RefCounted);

public:
	RenderObject();
	~RenderObject();

protected:
	static void _bind_methods();
};
#endif