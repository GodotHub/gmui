#include "gmui/widgets/stateless/stateless_widget.h"

StatelessWidget::StatelessWidget() {
}

StatelessWidget::~StatelessWidget() {
}

Widget *StatelessWidget::_build(Ref<Element> context) {
	return nullptr;
}

void StatelessWidget::_bind_methods() {
	BIND_VIRTUAL_METHOD(StatelessWidget, _build);
}