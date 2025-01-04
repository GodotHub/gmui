#include "widgets/multi_child_render_object_widget.hpp"

List<Widget *> MultiChildRenderObjectWidget::get_children() {
	return _children;
}

MultiChildRenderObjectElement *MultiChildRenderObjectWidget::create_element() {
	return memnew(MultiChildRenderObjectElement(this));
}