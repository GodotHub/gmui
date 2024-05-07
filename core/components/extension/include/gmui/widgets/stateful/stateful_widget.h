#ifndef STATEFUL_WIDGET_CLASS_H
#define STATEFUL_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/widgets/widget.h"

using namespace godot;

class StatefulWidget : public Widget {
	GDCLASS(StatefulWidget, Widget);

protected:
	static void _bind_methods();

public:
	virtual Widget *_build(Ref<Element> context) = 0;
};

#endif // WIDGET_CLASS_H