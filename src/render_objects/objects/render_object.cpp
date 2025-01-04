#include "render_objects/objects/render_object.hpp"

void RenderObject::_bind_methods() {
}

void RenderObject::layout(const Ref<Constraints> &constraints, bool parent_uses_size) {
	_constraints = constraints.ptr();
	// perform_resize();
	perform_layout();
	_needs_layout = false;
	// markNeedsPaint();
}