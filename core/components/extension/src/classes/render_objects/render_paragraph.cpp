#include "render_paragraph.h"

RenderParagraph::RenderParagraph(String &text, TextAlign &align, TextStyle &style) {
	_text = text;
	_align = align;
	_style = style;
}