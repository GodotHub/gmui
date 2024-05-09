#include "gmui/render_objects/render_box.h"

RenderBox::RenderBox() {
}

RenderBox::~RenderBox() {
}

void RenderBox::set_size(const Vector2 &size) {
	this->size = size;
}

Vector2 RenderBox::get_size() {
	return size;
}

void RenderBox::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_size"), &RenderBox::get_size);
	ClassDB::bind_method(D_METHOD("set_size", "size"), &RenderBox::set_size);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "size"), "set_size", "get_size");
}
