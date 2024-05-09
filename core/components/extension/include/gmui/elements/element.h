#ifndef ELEMENT_CLASS_H
#define ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/build_owner.h"
#include "gmui/widgets/widget.h"
#include <functional>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class Element;
class Widget;

/// @brief 连接widget树和render树的桥梁.

class Element : public RefCounted {
	GDCLASS(Element, RefCounted);

public:
	enum ElementLifecycle {
		INITIAL,
		ACTIVE,
		INACTIVE,
		DEFUNCT,
	};

	Element(Widget *widget = nullptr);
	virtual ~Element();
	Element *get_parent();
	virtual Widget *get_widget();
	virtual BuildOwner *get_owner();
	void mount();
	virtual void mount(Element *parent) = 0;
	void rebuild();
	virtual void perform_rebuild() = 0;
	void update(Widget *widget);
	void deactive_child(Element *element);
	Element *update_child(Element *child, Widget *new_widget);
	Element *inflact_widget(Widget *widget);
	virtual void attach_render_object();
	virtual void visit_children(const std::function<void(Element *child)> &visitor) = 0;

protected:
	Widget *_widget;
	Element *_parent;
	ElementLifecycle _lifecycle = INITIAL;
	BuildOwner *_builder;
	bool _dirty = false;
	static void _bind_methods();

private:
	static int _debug_concrete_subtype(Element *element);
};

VARIANT_ENUM_CAST(Element::ElementLifecycle);
#endif