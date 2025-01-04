#ifndef __ROOT_WIDGET_H__
#define __ROOT_WIDGET_H__

#include "elements/root_element.hpp"
#include "widgets/multi_child_render_object_widget.hpp"

class RootWidget : public MultiChildRenderObjectWidget {
	GDCLASS(RootWidget, MultiChildRenderObjectWidget);

protected:
	virtual RenderObject *create_render_object() override;

public:
	virtual Widget *build() override;
	virtual RootElement *create_element() override;
};

#endif // __ROOT_WIDGET_H__