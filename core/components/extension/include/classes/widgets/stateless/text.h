#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "rich_text.h"
#include "stateless_widget.h"

using namespace godot;

class Text : public StatelessWidget {
	GDCLASS(Text, StatelessWidget);
	String _text;
	TextAlign _align;
	TextStyle _style;

public:
	Text(String &text, TextAlign &align, TextStyle &style);
	virtual Widget *build(BuildContext &context) override;

protected:
	static void _bind_methods();
};

#endif