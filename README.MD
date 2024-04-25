### 拉取项目
git clone --recurse-submodules -b 2.0 https://github.com/JustDooooIt/GMUI.git

### 初始化godot-cpp
vscode进入core/components,按下ctrl+shift+p,输入>run task,执行initial-build-extension进行初始化.
打开.vscode/c_cpp_properties.json,编辑compilerPath为合适的编译器

### 开发
创建目录时,需要在根目录下的SConstruct文件内修改配置
``` python 
env.Append(CPPPATH=["extension/src/classes/", "extension/src/register/"]) 
```

### 构建
后续构建只需要执行build-extension,dll文件在game/bin
