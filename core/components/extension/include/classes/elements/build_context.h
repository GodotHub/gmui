#ifndef BUILD_CONTEXT_CLASS_H
#define BUILD_CONTEXT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "build_owner.h"
#include "widget.h"

class BuildContext {
public:
	virtual Widget *get_widget() = 0;
	virtual BuildOwner *get_owner() = 0;
};

#endif