#include "gmui/ui/ui.h"

TextStyle::TextStyle(Color color) {
	this->color = color;
}

TextStyle::~TextStyle() {
}

void TextStyle::set_color(const Color &color) {
	this->color = color;
}

Color TextStyle::get_color() {
	return this->color;
}

void TextStyle::_bind_methods() {
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "color"), "set_color", "get_color");
}