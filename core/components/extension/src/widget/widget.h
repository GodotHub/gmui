//© Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community (CC-BY 3.0)
#ifndef WIDGET_CLASS_H
#define WIDGET_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/canvas_item.hpp>

using namespace godot;

class Widget : public CanvasItem
{
    GDCLASS(Widget, CanvasItem);

    int count;

protected:
    static void _bind_methods();

public:
    Widget();
    ~Widget();
};

#endif // WIDGET_CLASS_H