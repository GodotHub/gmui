#ifndef VIEW_CLASS_H
#define VIEW_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "./gd_view.h"
#include "gmui/elements/render_object_elements/view_element/view_element.h"
#include "gmui/widgets/stateless/stateless_widget.h"

using namespace godot;

class View : public StatelessWidget {
	GDCLASS(View, StatelessWidget);

	Widget *_child;
	GDView *_gd_view;

public:
	View(Viewport *viewport = nullptr, Widget *root_widget = nullptr);
	virtual Widget *_build(Ref<BuildContext> context) override;
	virtual Element *create_element() override;

protected:
	static void _bind_methods();
};

#endif