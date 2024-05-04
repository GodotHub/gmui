#include "../../include/register/register_types.h"
// #include "../../include/classes/summator.h"
#include "../../include/classes/box_render.h"
#include "../../include/classes/render.h"
#include "../../include/classes/text.h"
#include "../../include/classes/widget.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gmui_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	// ClassDB::register_class<Summator>();
	ClassDB::register_class<BoxRender>();
	ClassDB::register_class<Render>();
	ClassDB::register_class<App>();
	// ClassDB::register_class<Widget>();
	ClassDB::register_class<Text>();
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

	// init_obj.register_initializer(initialize_summator_types);
	// init_obj.register_terminator(uninitialize_summator_types);
	init_obj.register_initializer(initialize_gmui_types);
	init_obj.register_terminator(uninitialize_gmui_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
