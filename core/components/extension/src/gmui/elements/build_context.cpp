#include "gmui/elements/build_context.h"

inline Widget *BuildContext::get_widget() {
	return element->get_widget();
}

inline BuildOwner *BuildContext::get_owner() {
	return element->get_owner();
}

inline void BuildContext::_bind_methods() {
}