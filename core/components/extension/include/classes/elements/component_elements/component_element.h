#ifndef COMPONENT_ELEMENT_CLASS_H
#define COMPONENT_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "build_owner.h"
#include "element.h"
#include "widget.h"

using namespace godot;

class ComponentElement : public Element {
	GDCLASS(ComponentElement, Element);

public:
	virtual Widget *build();
	void mount(Element *parent) override;
	void perform_rebuild() override;

protected:
	Element *_child;
	static void _bind_methods();

private:
	void _first_build();
};

#endif