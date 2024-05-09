#include "gmui/widgets/view/gd_view.h"

using namespace godot;

GDView::GDView(Viewport *viewport) {
	this->viewport = viewport->get_viewport_rid();
	this->canvas = viewport->get_world_2d()->get_canvas();
}

GDView::~GDView() {
}

void GDView::render() {
}

void GDView::_bind_methods() {
}
