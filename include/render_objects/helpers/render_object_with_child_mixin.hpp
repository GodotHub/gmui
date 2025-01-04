#ifndef __RENDER_OBJECT_WITH_CHILD_H__
#define __RENDER_OBJECT_WITH_CHILD_H__

#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

template <typename ChildType>
class RenderObjectWithChildMixin {
protected:
	ChildType *_child;
};

#endif // __RENDER_OBJECT_WITH_CHILD_H__