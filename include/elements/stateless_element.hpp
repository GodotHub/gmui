#ifndef __STATELESS_ELEMENT_H__
#define __STATELESS_ELEMENT_H__

#include "elements/component_element.hpp"

class StatelessElement : public ComponentElement {
	GDCLASS(StatelessElement, ComponentElement);

public:
	virtual Widget *build(BuildContext *context) override;
	virtual void mount(Element *child);
};

#endif // __STATELESS_ELEMENT_H__