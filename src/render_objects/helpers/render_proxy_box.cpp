#include "render_objects/helpers/render_proxy_box.hpp"

RenderProxyBox::RenderProxyBox(RenderBox *child) {
	_child = child;
}