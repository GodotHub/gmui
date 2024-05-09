#include "gmui/boost/app.h"

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
		} break;
		default:
			break;
	}
}

void App::_run_app_internal() {
	Ref<Widget> app;
	if (GDVIRTUAL_CALL(_run_app, app)) {
		if (!app.ptr()) {
			return;
		}
		_attach_root_widget(app.ptr());
		_draw_frame();
	}
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
	GDVIRTUAL_BIND(_run_app);
}