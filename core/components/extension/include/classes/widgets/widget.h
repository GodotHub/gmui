#ifndef WIDGET_CLASS_H
#define WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "element.h"
#include "id.h"
#include "stateful_widget.h"
#include "stateless_widget.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <type_traits>

using namespace godot;

class Widget : public RefCounted {
	GDCLASS(Widget, RefCounted);

public:
	Widget();
	virtual ~Widget();
	bool operator==(const Widget &widget);
	static bool can_update(const Widget &old_widget, const Widget &new_widget);
	Identity *get_identity() const;
	virtual Element *create_element() = 0;

protected:
	Identity *id;
	static void _bind_methods();

private:
	static int _debug_concrete_subtype(Widget *widget);
};

#endif // WIDGET_CLASS_H