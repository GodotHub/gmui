#ifndef UI_H
#define UI_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/color.hpp>

using namespace godot;

class TextStyle : public RefCounted {
	GDCLASS(TextStyle, RefCounted);

	Color color;

public:
	TextStyle(Color color = Color());
	~TextStyle();
	void set_color(const Color &color);
	Color get_color();

protected:
	static void _bind_methods();
};

enum TextAlign {
	LEFT,
	CENTER,
	RIGHT
};

VARIANT_ENUM_CAST(TextAlign);

#endif