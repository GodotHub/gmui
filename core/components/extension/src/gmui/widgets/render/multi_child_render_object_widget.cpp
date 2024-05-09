#include "gmui/widgets/render/multi_child_render_object_widget.h"

TypedArray<Widget> MultiChildRenderObjectWidget::get_children() const {
	return _children;
}

void MultiChildRenderObjectWidget::_bind_methods() {
}

MultiChildRenderObjectWidget::MultiChildRenderObjectWidget() {
}

MultiChildRenderObjectWidget::~MultiChildRenderObjectWidget() {
}