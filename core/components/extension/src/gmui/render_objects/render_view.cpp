#include <gmui/render_objects/render_view.h>

void RenderView::set_child(RenderBox *child) {
	if (_child) {
		drop_child(_child);
	}
	_child = child;
	if (_child) {
		adopt_child(child);
	}
}

void RenderView::adopt_child(RenderBox *child) {
}

void RenderView::drop_child(RenderBox *child) {
}
