#include "../../include/classes/render.h"

using namespace godot;

Render::Render() {
}

Render::~Render() {
}

void Render::add_child(Node *node, bool force_readable_name, Node::InternalMode internal) {
	CanvasItem::add_child(node, force_readable_name, internal);
	get_app()->register_render_obj(node);
}

App *Render::get_app() {
	if (app) {
		return app;
	}

	Node *cur = this->get_parent();
	while (cur) {
		if (std::is_same<decltype(*cur), App>::value) {
			return app = (App *)cur;
		}
		cur = cur->get_parent();
	}
	return nullptr;
}

void Render::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_app"), &Render::get_app);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "app"), "", "");
}

void App::register_render_obj(Node *node) {
	_lazy_init_render_nodes();
	// 判断node是否为Render,并注册进render_nodes
	if (std::is_same<decltype(*node), Render>::value) {
		(*render_nodes)[reinterpret_cast<uintptr_t>(node)] = &(node->get_path());
	}
}

void App::_lazy_init_render_nodes() {
	if (!render_nodes) {
		render_nodes = &Dictionary();
	}
}

void App::_bind_methods() {
}