#ifndef STATEFUL_WIDGET_CLASS_H
#define STATEFUL_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/build_context.h"
#include "gmui/elements/component_elements/stateful_element.h"
#include "gmui/widgets/widget.h"

using namespace godot;

class BuildContext;
class Widget;

class StatefulWidget : public Widget {
	GDCLASS(StatefulWidget, Widget);

protected:
	static void _bind_methods();

public:
	virtual Widget *_build(Ref<BuildContext> context) = 0;
};

#endif // WIDGET_CLASS_H