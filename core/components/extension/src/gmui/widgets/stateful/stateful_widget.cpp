#include "gmui/widgets/stateful/stateful_widget.h"

Widget *StatefulWidget::_build(Ref<Element> context) {
	return nullptr;
}

void StatefulWidget::_bind_methods() {
	BIND_VIRTUAL_METHOD(StatefulWidget, _build);
}