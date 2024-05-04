#include "app.h"

using namespace godot;

App::App() {
	_owner = new BuildOwner();
	connect("ready", callable_mp(this, App::_run_app_internal));
}

App::~App() {}

void App::_run_app_internal() {
	Widget *app = _run_app();
	if (!app) {
		return;
	}
	_attach_root_widget(app);
	_schedule_warm_up_frame();
}

Widget *App::_wrap_app_with_view(Widget *app) {
	return new View(this->get_viewport(), app);
}

void App::_attach_root_widget(Widget *app) {
	_attach_to_build_owner(new RootWidget(_wrap_app_with_view(app)));
}

void App::_attach_to_build_owner(RootWidget *widget) {
	widget->attach(_owner, _root_element);
}

void App::_schedule_warm_up_frame() {
}

void App::_bind_methods() {
	BIND_VIRTUAL_METHOD(App, _run_app);
}