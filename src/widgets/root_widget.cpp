#include "widgets/root_widget.hpp"

RenderObject *RootWidget::create_render_object() {
	return nullptr;
}

Widget *RootWidget::build() {
	return nullptr;
}

RootElement *RootWidget::create_element() {
	return memnew(RootElement(this));
}