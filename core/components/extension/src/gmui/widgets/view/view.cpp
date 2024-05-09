#include "gmui/widgets/view/view.h"

using namespace godot;

View::View(Viewport *viewport, Widget *root_widget) {
	_gd_view = new GDView(viewport);
	_child = root_widget;
}

Widget *View::_build(Ref<BuildContext> context) {
	return this;
}

Element *View::create_element() {
	return new ViewElement(this);
}

void View::_bind_methods() {
}
