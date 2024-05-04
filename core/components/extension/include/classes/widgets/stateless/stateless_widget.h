#ifndef STATELESS_WIDGET_CLASS_H
#define STATELESS_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "widget.h"
#include <build_context.h>

using namespace godot;

class StatelessWidget : public Widget {
	GDCLASS(StatelessWidget, Widget);

protected:
	static void _bind_methods();

public:
	virtual Widget *build(BuildContext &context) = 0;
};

#endif // WIDGET_CLASS_H