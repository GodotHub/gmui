#include "render_objects/constraints/constraints.hpp"

void Constraints::_bind_methods() {
}

bool Constraints::is_tight() const {
	return _is_tight;
}

bool Constraints::is_normalized() const {
	return _is_normalized;
}
