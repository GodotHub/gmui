#ifndef __CONSTRAINTS_H__
#define __CONSTRAINTS_H__

#include "utils/types.hpp"
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class Constraints : public RefCounted {
	GDCLASS(Constraints, RefCounted);

	bool _is_tight;
	bool _is_normalized;

protected:
	static void _bind_methods();

public:
	bool is_tight() const;
	bool is_normalized() const;
};

#endif // __CONSTRAINTS_H__