# Graphics Editor

## 0. Build Requirements

如果你想自己编译此项目，你需要：

- QT version 5.9+
- OpenCV 3.2.0 （with `OpenCV_contrib`）

所需的人脸识别的训练好的模型因为文件过大无法传到github，可于http://osawfig85.bkt.clouddn.com/MyFacePCAModel.xml 下载。

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