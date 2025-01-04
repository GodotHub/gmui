#ifndef __RENDER_BOX_H__
#define __RENDER_BOX_H__

#include "render_objects/constraints/box_constraints.hpp"
#include "render_objects/helpers/render_object_with_child_mixin.hpp"
#include "render_objects/objects/render_object.hpp"
#include <godot_cpp/variant/vector2.hpp>

class RenderBox : public RenderObject {
	GDCLASS(RenderBox, RenderObject);

	Vector2 _size;
	Vector2 _offset;
	Constraints *_constraints;

protected:
	virtual void perform_layout() override = 0;
	virtual void perform_resize() override = 0;

public:
	Size get_size();
	void set_size(const Size &size);

	BoxContraints *get_constraints();
};
#endif // __RENDER_BOX_H__