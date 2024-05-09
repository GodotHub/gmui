#include "gmui/widgets/stateful/stateful_widget.h"

void StatefulWidget::_bind_methods() {
	BIND_VIRTUAL_METHOD(StatefulWidget, _build);
}