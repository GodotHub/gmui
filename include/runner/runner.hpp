#ifndef __RUNNER_H__
#define __RUNNER_H__

#include "elements/element.hpp"
#include "elements/root_element.hpp"
#include "widgets/widget.hpp"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class Runner : public Node {
	GDCLASS(Runner, Node);

	Element *root_element;

protected:
	static void _bind_methods();

public:
	Runner();
	GDVIRTUAL0R(Widget *, _run_app);
	void run_app();
};

#endif // __RUNNER_H__