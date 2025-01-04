#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "elements/element.hpp"
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class Widget : public RefCounted {
	GDCLASS(Widget, RefCounted);

protected:
	static void _bind_methods();

public:
	Widget();
	virtual Element *create_element() = 0;
	virtual Widget *build() = 0;
};

#endif // __WIDGET_H__