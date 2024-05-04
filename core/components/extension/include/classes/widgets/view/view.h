#ifndef VIEW_CLASS_H
#define VIEW_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gd_view.h"
#include "stateless_widget.h"
#include "view_element.h"

using namespace godot;

class View : public StatelessWidget {
	GDCLASS(View, StatelessWidget);

	Widget *_child;
	GDView *_gd_view;

public:
	View(Viewport *viewport, Widget *root_widget);
	virtual Widget *build(BuildContext &context) override;
	virtual Element *create_element() override;

protected:
	static void _bind_methods();
};

#endif