#include "gmui/boost/app.h"
#include "gmui/elements/build_owner.h"
#include "gmui/elements/element.h"
#include "gmui/elements/root_element.h"
#include "gmui/render_objects/pipeline_owner.h"
#include "gmui/render_objects/render_box.h"
#include "gmui/render_objects/render_object.h"
#include "gmui/render_objects/render_paragraph.h"
#include "gmui/render_objects/render_view.h"
#include "gmui/ui/ui.h"
#include "gmui/widgets/id.h"
#include "gmui/widgets/root_widget.h"
#include "gmui/widgets/stateful/stateful_widget.h"
#include "gmui/widgets/stateless/rich_text.h"
#include "gmui/widgets/stateless/stateless_widget.h"
#include "gmui/widgets/stateless/text.h"
#include "gmui/widgets/view/gd_view.h"
#include "gmui/widgets/view/view.h"
#include "gmui/widgets/widget.h"
#include <gdextension_interface.h>
#include <register/register_types.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gmui_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	GDREGISTER_CLASS(App);
	GDREGISTER_ABSTRACT_CLASS(Widget);
	GDREGISTER_ABSTRACT_CLASS(StatelessWidget);
	GDREGISTER_ABSTRACT_CLASS(StatefulWidget);
	GDREGISTER_INTERNAL_CLASS(GDView);
	GDREGISTER_INTERNAL_CLASS(View);
	GDREGISTER_INTERNAL_CLASS(RootWidget);
	GDREGISTER_CLASS(RichText);
	// GDREGISTER_CLASS(Text);
	GDREGISTER_CLASS(Identity);
	GDREGISTER_CLASS(TextStyle);

	GDREGISTER_ABSTRACT_CLASS(Element);
	GDREGISTER_INTERNAL_CLASS(BuildOwner);
	GDREGISTER_INTERNAL_CLASS(RootElement);

	GDREGISTER_INTERNAL_CLASS(PipelineOwner);
	GDREGISTER_ABSTRACT_CLASS(RenderObject);
	GDREGISTER_ABSTRACT_CLASS(RenderBox);
	// GDREGISTER_CLASS(RenderParagraph);
	// GDREGISTER_CLASS(RenderView);
}

void uninitialize_gmui_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {

// Initialization.

GDExtensionBool GDE_EXPORT gmui_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_gmui_types);
	init_obj.register_terminator(uninitialize_gmui_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
