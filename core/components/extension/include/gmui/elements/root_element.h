#ifndef ROOT_ELEMENT_CLASS_H
#define ROOT_ELEMENT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/element.h"
#include "gmui/widgets/root_widget.h"

using namespace godot;

class RootElement : public Element {
	GDCLASS(RootElement, Element);

	Element *_child;

public:
	using Element::Element;
	virtual ~RootElement() override;
	void set_child(Element *child);
	void mount(Element *parent) override;
	void perform_rebuild() override;
	void visit_children(const std::function<void(Element *child)> &visitor) override;

protected:
	static void _bind_methods();

private:
	void _rebuild();
};

#endif