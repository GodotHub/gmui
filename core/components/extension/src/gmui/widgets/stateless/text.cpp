#include "gmui/widgets/stateless/text.h"

using namespace godot;

Text::Text(String text, TextAlign align, TextStyle *style) {
	_text = text;
	_align = align;
	_style = style;
}

Widget *Text::_build(Ref<Element> context) {
	return new RichText(_text, _align, _style);
}

void Text::_bind_methods() {
}
