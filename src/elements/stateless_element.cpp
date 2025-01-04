#include "elements/stateless_element.hpp"
#include "widgets/stateless_widget.hpp"

Widget *StatelessElement::build(BuildContext *context) {
	return static_cast<StatelessWidget *>(get_widget());
}

void StatelessElement::mount(Element *child) {
	first_build();
}