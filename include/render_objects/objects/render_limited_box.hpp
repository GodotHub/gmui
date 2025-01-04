#ifndef __RENDER_LIMITED_BOX_H__
#define __RENDER_LIMITED_BOX_H__

#include "render_objects/helpers/render_proxy_box.hpp"

class RenderLimitedBox : public RenderProxyBox {
	GDCLASS(RenderLimitedBox, RenderProxyBox);

private:
	BoxContraints *limit_contraints(const BoxContraints &constraints);

protected:
	virtual void perform_layout() override;

public:
	using RenderProxyBox::RenderProxyBox;
};

#endif // __RENDER_LIMITED_BOX_H__