#ifndef APP_CLASS_H
#define APP_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "root_widget.h"
#include "view.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/callable_method_pointer.hpp>

using namespace godot;

class App : public Node {
	GDCLASS(App, Node);

	Widget *_view;
	BuildOwner *_owner;
	RootElement *_root_element;

public:
	App();
	~App();
	virtual Widget *_run_app() { return nullptr; }

protected:
	static void _bind_methods();

private:
	void _run_app_internal();
	Widget *_wrap_app_with_view(Widget *app);
	void _attach_root_widget(Widget *app);
	void _attach_to_build_owner(RootWidget *root);
	void _schedule_warm_up_frame();
};
#endif