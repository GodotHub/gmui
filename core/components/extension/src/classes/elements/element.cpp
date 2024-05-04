#include "element.h"

using namespace godot;

Element::Element(Widget *widget) {
	_widget = widget;
}

Element::~Element() {
}

Element *Element::get_parent() {
	return _parent;
}

Widget *Element::get_widget() {
	return _widget;
}

BuildOwner *Element::get_owner() {
	return _owner;
}

int Element::_debug_concrete_subtype(Element *element) {
	typeid(*element) == typeid(StatefulElement) ? 1 : typeid(*element) == typeid(StatelessWidget) ? 2
																								  : 0;
}

void Element::mount(Element *parent) {
	DEV_ASSERT(_lifecycle == INITIAL);
	DEV_ASSERT(_parent == nullptr);
	DEV_ASSERT(parent == nullptr || parent->_lifecycle == ACTIVE);
	_parent = parent;
	_lifecycle = ACTIVE;
	_owner = _parent ? _parent->get_owner() : nullptr;
	DEV_ASSERT(_owner);
	Identity *id = _widget->get_identity();
	if (typeid(*id).name() == "class GlobalId") {
	}
}

void Element::rebuild() {
	DEV_ASSERT(_lifecycle != INITIAL);
	if (_lifecycle != ACTIVE || (!_dirty)) {
		return;
	}
	perform_rebuild();
	DEV_ASSERT(!_dirty);
}

void Element::mount() {
	mount(nullptr);
}

void Element::perform_rebuild() {
	_dirty = false;
}

void Element::deactive_child(Element *element) {
	delete element->_parent;
	element->_parent = nullptr;
	/* child.detachRenderObject(); */
}

Element *Element::update_child(Element *child, Widget *new_widget) {
	if (!new_widget) {
		if (child) {
			deactive_child(child);
		}
		return nullptr;
	}
	Element *new_child;
	if (child) {
		if (child->_widget == new_widget) { /* widget相同,不需要更新 */
			new_child = child;
		} else if (Widget::can_update(*(child->_widget), *new_widget)) { /* widget不同,判断是否需要更新 */
			child->update(new_widget);
			new_child = child;
		} else { /* 无法更新,替换节点 */
			/* deactive(e) */
			deactive_child(child);
			DEV_ASSERT(child->_parent == nullptr);
			new_child = inflact_widget(new_widget);
		}
	} else { /* 没有child_element,递归创建 */
		new_child = inflact_widget(new_widget);
	}
	return nullptr;
}

Element *Element::inflact_widget(Widget *widget) {
	Element *new_child = widget->create_element();
	new_child->mount(this);
	return new_child;
}

void Element::attach_render_object() {
	/*slot*/
	visit_children([](Element *child) {
		child->attach_render_object();
	});
}

void Element::_bind_methods() {
}