#ifndef __BOX_CONSTRAINTS_H__
#define __BOX_CONSTRAINTS_H__

#include "render_objects/constraints/constraints.hpp"
#include <godot_cpp/variant/vector2.hpp>
#include <limits>

using namespace godot;

class BoxContraints : public Constraints {
	double min_width, max_width,
			min_heigth, max_height;

protected:
	static void _bind_methods();

public:
	static BoxContraints loose(Size size);

	BoxContraints();
	BoxContraints(double min_width, double min_heigth, double max_width, double max_height) :
			min_width(min_width), min_heigth(min_heigth), max_width(max_width), max_height(max_height) {};

	double constrain_width(double width) const;
	double constrain_height(double height) const;
	Size get_max_size() const;
	Size get_min_size() const;
	Size constrain(Size size);
	bool has_bounded_width() const;
	bool has_bounded_height() const;
};

#endif // __BOX_CONSTRAINTS_H__