#ifndef RICH_TEXT_CLASS_H
#define RICH_TEXT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "multi_child_render_object_widget.h"
#include "render_paragraph.h"
#include "ui.h"
#include <godot_cpp/variant/color.hpp>

using namespace godot;

class RichText : public MultiChildRenderObjectWidget {
	GDCLASS(RichText, MultiChildRenderObjectWidget);

public:
	RichText(String &text, TextAlign &align, TextStyle &style);
	virtual MultiChildRenderObjectElement *create_element() override;
	virtual RenderParagraph *create_render_object() override;

protected:
	String _text;
	TextAlign _align;
	TextStyle _style;
	static void _bind_methods();
};
#endif