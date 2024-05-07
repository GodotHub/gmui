#include "gmui/boost/app.h"

using namespace godot;

App::App() {
}

App::~App() {
	queue_free();
}

void App::_notification(int p_notification) {
	switch (p_notification) {
		case NOTIFICATION_READY: {
			_builder = new BuildOwner();
			_run_app_internal();
			// connect("ready", callable_mp(this, &App::_run_app_internal));
		} break;
		// case NOTIFICATION_EXIT_TREE: {
		// 	disconnect("ready", callable_mp(this, &App::_run_app_internal));
		// } break;
		default:
			break;
	}
}

void App::_run_app_internal() {
	Widget *app = (Widget *)(call("_run_app")._native_ptr());
	if (!app) {
		return;
	}
	_attach_root_widget(app);
	_draw_frame();
}

Widget *App::_wrap_app_with_view(Widget *app) {
	return new View(this->get_viewport(), app);
}

void App::_attach_root_widget(Widget *app) {
	_attach_to_build_owner(new RootWidget(_wrap_app_with_view(app)));
}

void App::_attach_to_build_owner(RootWidget *widget) {
	widget->attach(_builder, _root_element);
}

void App::_draw_frame() {
	_flush_layout();
}

void App::_flush_layout() {
}

void App::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_run_app"), &App::_run_app);
}