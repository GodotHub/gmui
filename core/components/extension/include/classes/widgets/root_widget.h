#ifndef ROOT_WIDGET_CLASS_H
#define ROOT_WIDGET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "build_owner.h"
#include "root_element.h"
#include "view_element.h"
#include "widget.h"

using namespace godot;

class RootWidget : public Widget {
	GDCLASS(RootWidget, Widget);
	Widget *_child;

public:
	RootWidget(Widget *child);
	void set_child(Widget *child);
	Widget *get_child();
	Element *attach(BuildOwner *owner, Element *element);
	Element *attach(BuildOwner *owner);
	virtual Element *create_element() override;

protected:
	static void _bind_methods();
};
#endif