#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "context/build_context.hpp"
#include "render_objects/objects/render_object.hpp"

using namespace godot;

class Widget;

class Element : public BuildContext {
	GDCLASS(Element, BuildContext);

	Widget *_widget;

public:
	Element(Widget *widget);
	Widget *get_widget();
	void rebuild(bool force = false);
	virtual void mount(Element *parent);
};

#endif // __ELEMENT_H__