#ifndef FLEX_CLASS_H
#define FLEX_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "render.h"

using namespace godot;

class Flex;
enum Axis {
	ROW,
	COLUMN
};

class Flex : public Render {
	GDCLASS(Flex, CanvasItem);
	Axis direction;

public:
	Flex(Axis direction = ROW);
	~Flex();

protected:
	static void _bind_methods();
};

#endif