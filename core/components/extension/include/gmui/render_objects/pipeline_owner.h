#ifndef PIPELINE_OWNER_CLASS_H
#define PIPELINE_OWNER_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/render_objects/render_object.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/typed_array.hpp>

using namespace godot;

class PipelineOwner : public RefCounted {
	GDCLASS(PipelineOwner, RefCounted);

	TypedArray<RenderObject> _node_needs_layout = {};

public:
	void add_need_layout_node(const Ref<RenderObject> &node);
	TypedArray<RenderObject> get_need_layout_nodes() const;

protected:
	static void _bind_methods();

private:
};

#endif
