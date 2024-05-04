#ifndef STATESTATEFUL_WIDGET_CLASS_H
#define STATESTATEFUL_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "widget.h"
#include <build_context.h>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class StatefulWidget : public Widget {
	GDCLASS(StatefulWidget, Widget);

protected:
	static void _bind_methods();

public:
	virtual Widget *build(BuildContext context);
};

#endif // WIDGET_CLASS_H