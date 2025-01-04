#ifndef __RENDER_OBJECT_H__
#define __RENDER_OBJECT_H__

#include "render_objects/constraints/constraints.hpp"
#include "utils/types.hpp"
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class RenderObject : public RefCounted {
	GDCLASS(RenderObject, RefCounted);

protected:
	bool _needs_layout = false;
	bool _sized_by_parent = false;
	RenderObject *_parent = nullptr;
	Constraints *_constraints = nullptr;
	RenderObject *_relayoutBoundary = nullptr;

	virtual void perform_layout() = 0;
	virtual void perform_resize() = 0;
	static void _bind_methods();

public:
	void layout(const Ref<Constraints> &constraints, bool parent_uses_size);
};

#endif // __RENDER_OBJECT_H__