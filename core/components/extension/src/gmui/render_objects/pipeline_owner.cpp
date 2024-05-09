#include "gmui/render_objects/pipeline_owner.h"

void PipelineOwner::add_need_layout_node(const Ref<RenderObject> &node) {
	_node_needs_layout.append(Object::cast_to<Object>(*node));
}

TypedArray<RenderObject> PipelineOwner::get_need_layout_nodes() const {
	return _node_needs_layout;
}

void PipelineOwner::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add_need_layout_node", "node"), &PipelineOwner::add_need_layout_node);
	ClassDB::bind_method(D_METHOD("get_need_layout_nodes"), &PipelineOwner::get_need_layout_nodes);
}
