#include "render_objects/objects/render_limited_box.hpp"

BoxContraints *RenderLimitedBox::limit_contraints(const BoxContraints &constraints) {
	Size min_size = constraints.get_min_size();
	Size max_size = constraints.get_max_size();
	return new BoxContraints(
			min_size.x,
			min_size.y,
			constraints.has_bounded_width() ? max_size.x : constraints.constrain_width(max_size.x),
			constraints.has_bounded_height() ? max_size.y : constraints.constrain_height(max_size.y));
}

void RenderLimitedBox::perform_layout() {
	if (_child) {
		_child->layout(get_constraints(), true);
		Size child_size = _child->get_size();
		Size size = get_constraints()->constrain(child_size);
		set_size(size);
	} else {
		Size size = limit_contraints(*get_constraints())->constrain(Size());
		set_size(size);
	}
}