#ifndef __RENDER_PROXY_BOX_H__
#define __RENDER_PROXY_BOX_H__

#include "render_objects/helpers/render_object_with_child_mixin.hpp"
#include "render_objects/objects/render_box.hpp"

class RenderProxyBox : public RenderBox, public RenderObjectWithChildMixin<RenderBox> {
public:
	RenderProxyBox(RenderBox *child);
};

#endif // __RENDER_PROXY_BOX_H__