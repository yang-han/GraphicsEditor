# Graphics Editor

## 0. Build Requirements

如果你想自己编译此项目，你需要：

- QT version 5.9+
- OpenCV 3.2.0 （with `OpenCV_contrib`）

所需的人脸识别的训练好的模型因为文件过大无法传到github，可于http://osawfig85.bkt.clouddn.com/MyFacePCAModel.xml 以及http://osawfig85.bkt.clouddn.com/lbpcascade_frontalface.xml下载。

编译后注意`model.cpp`中关于模型路径要正确才能正确使用。

## 1. 需求分析

本项目实现了一个图片编辑器。

对于一张并不满意图片，通常要进行的基本调整有亮度/对比度的调整、旋转/裁剪、滤镜等操作。如果使用`Photoshop`打开则显得过于臃肿，加载缓慢切使用门槛较高。

本项目的目的在于事先一个轻量级的图像调整工具，具有图像编辑的所有基本操作，能让用户在快速轻量简易的体验中完成自己的编辑需求。

## 2. 功能实现

- [x] 导入打开图片
- [x] 调整对比度
- [x] 调整亮度
- [x] 裁剪
- [x] 旋转
- [x] 滤镜
- [x] 人脸检测

## 3. 项目概况

本项目基于`QT5.9`和`OpenCV3.2`实现。

整体架构基于`MVVM`(`Model-View-ViewModel`)实现。

在开发过程中，使用了`jenkins-CI`工具实现了持续交互。

整体代码相对干净，如果你有意进行二次开发，可以看下面的介绍。

## 4. 二次开发

每实现一个新功能需要增加一个对应的`command`类，command本身存在于ViewModel中，并提供get方法给View层进行set方法实现绑定，从而事先View->ViewModel的通信。

ViewModel执行Command的过程是调用Model中对应方法进行数据操作的过程。

在Model层完成数据操作之后，通过一个通知（绑定方式类似于command）来实现model与ViewModel的通信。

在此之后，ViewModel通过通知告诉View更新显示窗口。

二次开发只需增加相应的Command类并在model中实现功能，并讲command和notification绑定好即可。

## 5. 项目目录

```
.
├── app.cpp
├── app.h
├── command.cpp
├── command.h
├── Commands
│   ├── alter_bright_command.cpp
│   ├── alter_bright_command.h
│   ├── crop_command.cpp
│   ├── crop_command.h
│   ├── detect_face_command.cpp
│   ├── detect_face_command.h
│   ├── filter_command.cpp
│   ├── filter_command.h
│   ├── open_file_command.cpp
│   ├── open_file_command.h
│   ├── reset_command.cpp
│   ├── reset_command.h
│   ├── rotate_command.cpp
│   ├── rotate_command.h
│   ├── save_bmp_command.cpp
│   ├── save_bmp_command.h
│   ├── save_file_command.cpp
│   └── save_file_command.h
├── common.cpp
├── common.h
├── GraphicsEditor.pro
├── GraphicsEditor.pro.user
├── LICENSE
├── main.cpp
├── model.cpp
├── model.h
├── MyView.cpp
├── MyView.h
├── notification.cpp
├── notification.h
├── parameters.cpp
├── parameters.h
├── README.md
├── test.pro
├── test.pro.user
├── view.cpp
├── view.h
├── viewmodel.cpp
├── viewmodel.h
└── view.ui
```

## 6. 框架介绍

较详细介绍在[博客](https://sleeepyy.github.io/2017/07/12/%E7%94%A8C-%E5%AE%9E%E7%8E%B0MVVM/)中。

#### 整体流程

在`View`层进行操作之后，会触发对应槽函数，该槽函数会准备好参数`Parameter`交给对应的`Command`，然后执行`exec()`这个command，exec会解出参数交给`ViewModel`层，`ViewModel`调用`Model`里对应的方法，进行数据操作，`Model`操作完之后会通知`ViewModel`更新显示数据，`ViewModel`会通知`View`刷新显示。

## 7. 小组成员

- 组长： 
  - 杨晗  `MVVM`框架搭建  人脸检测功能实现


- 组员：
  - 王大鑫： jenkins环境搭建   Model层各项基本功能实现
  - 方钲清： QT界面绘制编写
  - 孙健： 功能测试