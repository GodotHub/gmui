#include "../../include/classes/text.h"

using namespace godot;

#define TS TextServerManager::get_singleton()->get_primary_interface()

Text::Text(String &text) {
	text_rid = TS->create_shaped_text();
	font_rid = TS->create_font();
	set_text(text);
}

Text::~Text() {
	TS->free_rid(text_rid);
	TS->free_rid(font_rid);
}

void Text::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_DRAW: {
			if (dirty) {
				const TypedArray<Dictionary> glyphs = TS->shaped_text_get_glyphs(text_rid);
				const RID ci = get_canvas_item();
				normal_style->draw(ci, Rect2(Point2(0, 0), Vector2(100, 100)));
				for (int i = 0; i < glyphs.size(); i++) {
					const Dictionary glyph = glyphs[i];
					const uint8_t repeat = glyph["repeat"];
					Vector2 style_offset = normal_style->get_offset();
					Vector2 offset = { style_offset.x, (real_t)TS->shaped_text_get_ascent(text_rid) + style_offset.y };
					for (uint8_t j = 0; j < repeat; j++) {
						TS->font_draw_glyph(font_rid, ci, glyph["font_size"], offset + Vector2(glyph["x_off"], glyph["y_off"]), glyph["index"]);
					}
					offset.x += glyphs[i]["advance"];
				}
				dirty = false;
			}
		} break;

		default:
			break;
	}
}
void Text::set_text(String text) {
	dirty = true;
	this->text = text;
	queue_redraw();
}

String Text::get_text() { return text; }

void Text::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_text", "text"), &Text::set_text);
	ClassDB::bind_method(D_METHOD("get_text"), &Text::get_text);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "text"), "set_text", "get_text");
}