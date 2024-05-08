#ifndef BUILD_CONTEXT_CLASS_H
#define BUILD_CONTEXT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/elements/build_owner.h"
#include "gmui/elements/element.h"
#include "gmui/widgets/widget.h"
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class BuildOwner;
class Widget;

class BuildContext : public RefCounted {
	GDCLASS(BuildContext, RefCounted);

	Ref<Element> element;

public:
	BuildContext(Ref<Element> element = nullptr);
	~BuildContext();
	Widget *get_widget();
	BuildOwner *get_owner();

protected:
	static void _bind_methods();
};

inline BuildContext::BuildContext(Ref<Element> element) {
	this->element = element;
}

inline BuildContext::~BuildContext() {
}
#endif
