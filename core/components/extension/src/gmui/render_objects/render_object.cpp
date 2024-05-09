#include "gmui/render_objects/render_object.h"

using namespace godot;

RenderObject::RenderObject() {
}

RenderObject::~RenderObject() {
}
void RenderObject::mark_needs_layout() {
	if (_relayout_boundary == nullptr) {
		_needs_layout = true;
		if (parent) {
			mark_parent_needs_layout();
		}
	} else if (_relayout_boundary == this) {
		_needs_layout = true;
	}
}

void RenderObject::mark_parent_needs_layout() {
	parent->mark_needs_layout();
}

void RenderObject::_bind_methods() {
}
