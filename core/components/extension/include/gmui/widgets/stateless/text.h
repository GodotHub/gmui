#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "gmui/widgets/stateless/rich_text.h"
#include "gmui/widgets/stateless/stateless_widget.h"

using namespace godot;

class Text : public StatelessWidget {
	GDCLASS(Text, StatelessWidget);
	String _text;
	TextAlign _align;
	TextStyle *_style;

public:
	Text(String text = "", TextAlign align = LEFT, TextStyle *style = nullptr);
	virtual Widget *_build(Ref<Element>context) override;

protected:
	static void _bind_methods();
};

#endif