#include "gmui/render_objects/pipeline_owner.h"

void PipelineOwner::add_need_layout_node(const RenderObject &node) {
	_node_needs_layout.append(Object::cast_to<Object>(&node));
}

TypedArray<RenderObject> PipelineOwner::get_need_layout_nodes() const {
	return _node_needs_layout;
}
