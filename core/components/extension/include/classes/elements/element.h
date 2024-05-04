#ifndef ELEMENT_CLASS_H
#define ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "build_owner.h"
#include "stateful_element.h"
#include "stateless_element.h"
#include "widget.h"
#include <render_object.h>
#include <functional>
#include <godot_cpp/classes/ref_counted.hpp>
#include <type_traits>

using namespace godot;

class Element;
/// @brief 连接widget树和render树的桥梁.

class Element : public RefCounted, public BuildContext {
	GDCLASS(Element, RefCounted);

public:
	Element(Widget *widget);
	virtual ~Element();
	Element *get_parent();
	virtual Widget *get_widget() override;
	virtual BuildOwner *get_owner() override;
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
	BuildOwner *_owner;
	bool _dirty = false;
	static void _bind_methods();

private:
	static int _debug_concrete_subtype(Element *element);
};

enum ElementLifecycle {
	INITIAL,
	ACTIVE,
	INACTIVE,
	DEFUNCT,
};
#endif