#include "runner/runner.hpp"
#include "widgets/root_widget.hpp"
#include <godot_cpp/variant/callable_method_pointer.hpp>

void Runner::_bind_methods() {
}

Runner::Runner() {
	connect("ready", callable_mp(this, &Runner::run_app));
}

void Runner::run_app() {
	Widget *user_widget;
	if (!GDVIRTUAL_REQUIRED_CALL(_run_app, user_widget)) {
		ERR_FAIL_EDMSG("_run_app not implemented");
	}
	root_element = user_widget->create_element();
	root_element->mount(nullptr);
}