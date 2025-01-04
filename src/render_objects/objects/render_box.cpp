#include "render_objects/objects/render_box.hpp"

void RenderBox::perform_layout() {
}

void RenderBox::perform_resize() {
}

Size RenderBox::get_size() {
	return _size;
}

void RenderBox::set_size(const Size &size) {
	_size = size;
}

BoxContraints *RenderBox::get_constraints() {
	return static_cast<BoxContraints *>(_constraints);
}
