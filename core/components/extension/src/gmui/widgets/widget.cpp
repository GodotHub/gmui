#include "gmui/widgets/widget.h"
#include "gmui/widgets/stateful/stateful_widget.h"
#include "gmui/widgets/stateless/stateless_widget.h"

using namespace godot;

Widget::Widget() {
}

Widget::~Widget() {
	delete id;
}

bool Widget::operator==(const Widget &widget) {
	return this == &widget;
}

bool Widget::can_update(const Ref<Widget> old_widget, const Ref<Widget> new_widget) {
	return typeid(*(old_widget.ptr())) == typeid(*(new_widget.ptr())) && old_widget->get_identity() == new_widget->get_identity();
}

Identity *Widget::get_identity() const {
	return id;
}

int Widget::_debug_concrete_subtype(Widget *widget) {
	return typeid(*widget) == typeid(StatefulWidget) ? 1 : typeid(*widget) == typeid(StatelessWidget) ? 2
																									  : 0;
}

void Widget::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_identity"), &Widget::get_identity);
	ClassDB::bind_static_method("Widget", D_METHOD("can_update", "old_widget", "new_widget"), &Widget::can_update);
}