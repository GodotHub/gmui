#ifndef BUILD_OWNER_CLASS_H
#define BUILD_OWNER_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class BuildOwner : public RefCounted {
	GDCLASS(BuildOwner, RefCounted);

protected:
	static void _bind_methods();
};

#endif