#ifndef APP_CLASS_H
#define APP_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/widgets/root_widget.h"
#include "gmui/widgets/view/view.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>
#include <godot_cpp/variant/callable_method_pointer.hpp>

using namespace godot;

class App : public Node {
	GDCLASS(App, Node);

	Widget *_view;
	BuildOwner *_builder;
	RootElement *_root_element;

public:
	App();
	~App();
	void _run_app_internal();
	GDVIRTUAL0R(Ref<Widget>, _run_app);
	// virtual Widget *_run_app() { return nullptr; };

protected:
	static void _bind_methods();
	void _notification(int p_notification);

private:
	Widget *_wrap_app_with_view(Widget *app);
	void _attach_root_widget(Widget *app);
	void _attach_to_build_owner(RootWidget *root);
	void _draw_frame();
	void _flush_layout();
};
#endif