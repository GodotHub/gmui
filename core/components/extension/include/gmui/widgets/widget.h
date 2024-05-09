#ifndef WIDGET_CLASS_H
#define WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/element.h"
#include "gmui/widgets/id.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <type_traits>

using namespace godot;

class Element;

class Widget : public RefCounted {
	GDCLASS(Widget, RefCounted);

public:
	Widget();
	virtual ~Widget();
	static bool can_update(const Ref<Widget> old_widget, const Ref<Widget> new_widget);
	Identity *get_identity() const;
	virtual Element *create_element() = 0;

protected:
	Identity *id;
	static void _bind_methods();

private:
	static int _debug_concrete_subtype(Widget *widget);
};

#endif // WIDGET_CLASS_H