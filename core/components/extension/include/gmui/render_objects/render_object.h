#ifndef RENDER_CLASS_H
#define RENDER_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/render_objects/render_object.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <type_traits>

using namespace godot;

#define RS RenderingServer::get_singleton()

class RenderObject : public RefCounted {
	GDCLASS(RenderObject, RefCounted);

	bool _needs_layout = false;
	RenderObject *_relayout_boundary;

public:
	RenderObject();
	virtual ~RenderObject();
	void mark_needs_layout();
	void mark_parent_needs_layout();

protected:
	RenderObject *parent;
	static void _bind_methods();
};
#endif