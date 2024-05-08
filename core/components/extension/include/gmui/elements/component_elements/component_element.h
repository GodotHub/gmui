#ifndef COMPONENT_ELEMENT_CLASS_H
#define COMPONENT_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/build_owner.h"
#include "gmui/elements/element.h"
#include "gmui/widgets/widget.h"

using namespace godot;

class Element;
class Widget;

class ComponentElement : public Element {
	GDCLASS(ComponentElement, Element);

public:
	using Element::Element;
	using Element::get_owner;
	using Element::get_widget;
	virtual ~ComponentElement() override;
	virtual Widget *build() = 0;
	void mount(Element *parent) override;
	void perform_rebuild() override;

protected:
	Element *_child;
	static void _bind_methods();

private:
	void _first_build();
};
#endif