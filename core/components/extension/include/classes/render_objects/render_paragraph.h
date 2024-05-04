#ifndef RENDER_PARAGRAPH_CLASS_H
#define RENDER_PARAGRAPH_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render_box.h"
#include "ui.h"

using namespace godot;

class RenderParagraph : public RenderBox {
public:
	RenderParagraph(String &text, TextAlign &align, TextStyle &style);
	~RenderParagraph();

protected:
	String _text;
	TextAlign _align;
	TextStyle _style;
	static void _bind_methods();

private:
	/* data */
};

#endif