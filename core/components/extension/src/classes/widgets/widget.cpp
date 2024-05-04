#include "../../../include/classes/widgets/widget.h"
#include "widget.h"

using namespace godot;

Widget::Widget() {
}

Widget::~Widget() {
	delete id;
}

bool Widget::operator==(const Widget &widget) {
	return this == &widget;
}

bool Widget::can_update(const Widget &old_widget, const Widget &new_widget) {
	return typeid(old_widget) == typeid(new_widget) && old_widget.get_identity() == new_widget.get_identity();
}

Identity *Widget::get_identity() const {
	return id;
}

int Widget::_debug_concrete_subtype(Widget *widget) {
	return typeid(*widget) == typeid(StatefulWidget) ? 1 : typeid(*widget) == typeid(StatelessWidget) ? 2
																									  : 0;
}

void Widget::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("add", "value"), &Widget::add, DEFVAL(1));
}