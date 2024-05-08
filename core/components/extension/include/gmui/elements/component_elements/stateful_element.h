#ifndef STATEFUL_ELEMENT_CLASS_H
#define STATEFUL_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/component_elements/component_element.h"
#include "gmui/widgets/widget.h"

using namespace godot;

class BuildContext;
class Widget;

class StatefulElement : public ComponentElement {
	GDCLASS(StatefulElement, ComponentElement);

public:
	virtual ~StatefulElement() override;
	virtual Widget *build() override;

protected:
	static void _bind_methods();
};

#endif