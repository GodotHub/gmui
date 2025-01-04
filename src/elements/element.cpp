#include "elements/element.hpp"
#include "widgets/widget.hpp"

Element::Element(Widget *widget) {
}

Widget *Element::get_widget() {
	return _widget;
}

void Element::rebuild(bool force) {
}

void Element::mount(Element *parent) {
}