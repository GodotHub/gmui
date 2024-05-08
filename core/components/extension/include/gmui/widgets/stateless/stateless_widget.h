#ifndef STATELESS_WIDGET_CLASS_H
#define STATELESS_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/build_context.h"
#include "gmui/elements/component_elements/stateless_element.h"
#include "gmui/widgets/widget.h"

using namespace godot;

class BuildContext;
class Widget;

class StatelessWidget : public Widget {
	GDCLASS(StatelessWidget, Widget);

public:
	StatelessWidget();
	virtual ~StatelessWidget() override;
	virtual Widget *_build(Ref<BuildContext> context) = 0;

protected:
	static void _bind_methods();
};

#endif // WIDGET_CLASS_H