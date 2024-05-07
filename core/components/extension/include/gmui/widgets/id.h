#ifndef IDENTITY_CLASS_H
#define IDENTITY_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref_counted.hpp>
#include <type_traits>

using namespace godot;

class Identity : public RefCounted {
	GDCLASS(Identity, RefCounted);

public:
	Identity();
	virtual ~Identity();

protected:
	static void _bind_methods();
};

class LocalId : public Identity {
	GDCLASS(LocalId, Identity);

protected:
	static void _bind_methods();
};

class GlobalId : public Identity {
	GDCLASS(GlobalId, Identity);

protected:
	static void _bind_methods();
};

class UniqueId : public LocalId {
	GDCLASS(UniqueId, LocalId);

protected:
	static void _bind_methods();
};

class ValueId : public LocalId {
	GDCLASS(ValueId, LocalId);

	Variant value;

public:
	bool operator==(Identity &id);
	Variant get_value();

protected:
	static void _bind_methods();
};

#endif