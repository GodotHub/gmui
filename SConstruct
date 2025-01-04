#!/usr/bin/env python
import os 

env = SConscript("godot-cpp/SConstruct")

def get_sources(path):
    sources = []
    for root, dirs, files in os.walk(path):
        sources += Glob(os.path.join(root, '*.cpp'))
    for root, dirs, files in os.walk(path):
        sources += Glob(os.path.join(root, '*.c'))
    return sources

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["include"])
sources = get_sources("src")

# if env["target"] in ["editor", "template_debug"]:
#     doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
#     sources.append(doc_data)

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "project/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "project/bin/libgdexample.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "project/bin/libgdexample.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "project/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

env.NoCache(library)
Default(library)
