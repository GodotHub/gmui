#ifndef RENDER_CLASS_H
#define RENDER_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/canvas_item.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/wrapped.hpp>
#include <type_traits>

using namespace godot;

class App;

class Render : public CanvasItem {
	GDCLASS(Render, CanvasItem);
	App *app;

public:
	Render();
	~Render();
	void add_child(Node *node, bool force_readable_name = false,
			Node::InternalMode internal = (Node::InternalMode)0);

protected:
	static void _bind_methods();
	App *get_app();
};

class App : public Render {
	GDCLASS(App, Render);
	Dictionary *render_nodes;

public:
	void register_render_obj(Node *node);

protected:
	void _notification(int p_what);
	static void _bind_methods();

private:
	void _lazy_init_render_nodes();
};

#endif