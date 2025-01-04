#ifndef __COMPONENT_ELEMENT_H__
#define __COMPONENT_ELEMENT_H__

#include "context/build_context.hpp"
#include "elements/element.hpp"
#include "widgets/widget.hpp"

class ComponentElement : public Element {
	GDCLASS(ComponentElement, Element);

	Element *_child;

protected:
	void first_build();

public:
	virtual void mount(Element *child);
	virtual Widget *build(BuildContext *context) = 0;
};

#endif // __COMPONENT_ELEMENT_H__