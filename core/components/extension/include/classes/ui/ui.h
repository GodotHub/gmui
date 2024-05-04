#ifndef UI_CLASS_H
#define UI_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/variant/color.hpp>
using namespace godot;

struct TextStyle {
	Color color;
};

enum TextAlign {
	LEFT,
	CENTER,
	RIGHT
};

#endif