#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render.h"
#include <godot_cpp/classes/glyph.hpp>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/classes/text_server.hpp>

using namespace godot;

class Text : public Render {
	GDCLASS(Text, Render);

	String text;
	RID text_rid;
	RID font_rid;
	bool dirty = false;
	Ref<StyleBox> normal_style;

public:
	Text(String &text = String());
	~Text();
	void set_text(String text);
	String get_text();

protected:
	static void _bind_methods();
	void _notification(int p_what);
};

#endif