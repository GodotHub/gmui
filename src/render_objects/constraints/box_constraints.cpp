#include "render_objects/constraints/box_constraints.hpp"
#include <godot_cpp/variant/utility_functions.hpp>

BoxContraints::BoxContraints() {
	min_width = 0;
	min_heigth = 0;
	max_width = std::numeric_limits<double>::infinity();
	max_height = std::numeric_limits<double>::infinity();
}

double BoxContraints::constrain_width(double width) const {
	return UtilityFunctions::clampf(width, min_width, max_width);
}

double BoxContraints::constrain_height(double height) const {
	return UtilityFunctions::clampf(height, min_heigth, max_height);
}

BoxContraints BoxContraints::loose(Size size) {
	return BoxContraints(0, 0, size.x, size.y);
}

Size BoxContraints::constrain(Size size) {
	double width = constrain_width(size.x);
	double height = constrain_height(size.y);
	return Size(width, height);
}

bool BoxContraints::has_bounded_width() const {
	return max_width < std::numeric_limits<double>::infinity();
}

bool BoxContraints::has_bounded_height() const {
	return max_height < std::numeric_limits<double>::infinity();
}

Size BoxContraints::get_max_size() const {
	return Size(max_width, max_height);
}

Size BoxContraints::get_min_size() const {
	return Size(min_width, min_heigth);
}