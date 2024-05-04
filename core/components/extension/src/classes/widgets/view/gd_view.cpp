#include "gd_view.h"

using namespace godot;

GDView::GDView(Viewport &viewport) {
	this->viewport = viewport.get_viewport_rid();
	this->canvas = viewport.get_world_2d()->get_canvas();
}
