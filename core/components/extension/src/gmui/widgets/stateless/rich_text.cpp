#include "gmui/widgets/stateless/rich_text.h"

RichText::RichText(String text, TextAlign align, TextStyle *style) {
	_text = text;
	_align = align;
	_style = style;
}

MultiChildRenderObjectElement *RichText::create_element() {
	return nullptr;
}

RenderParagraph *RichText::create_render_object() {
	return new RenderParagraph(_text, _align, _style);
}

void RichText::_bind_methods() {
}
