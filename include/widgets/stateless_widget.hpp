#ifndef __STATELESS_WIDGET_H__
#define __STATELESS_WIDGET_H__

#include "context/build_context.hpp"
#include "widgets/widget.hpp"

class StatelessWidget : public Widget {
	GDCLASS(StatelessWidget, Widget);

protected:
	Widget *build(BuildContext *context);
};

#endif // __STATELESS_WIDGET_H__