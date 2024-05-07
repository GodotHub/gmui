#ifndef STATELESS_ELEMENT_CLASS_H
#define STATELESS_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/component_elements/component_element.h"
#include "gmui/widgets/widget.h"

using namespace godot;

class StatelessElement : public ComponentElement {
	GDCLASS(StatelessElement, ComponentElement);

public:
	virtual ~StatelessElement() override = default;
	virtual Widget *build() override;

protected:
	static void _bind_methods();
};

#endif