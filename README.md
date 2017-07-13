本项目主要编写了一款能对图像进行处理的软件，其中软件图形界面的开发由Qt5实现，而对图像的处理部分则使用了OpenCV3.2进行图像编辑。

这款图像编辑器主要实现了对图片亮度、对比度、尺寸、格式的修改，同时能通过各种滤波修改图像的像素值，形成特定的图像风格

整个软件架构基于Model–view–viewmodel(MVVM)实现，将view层和model层分离，只通过viewmodel连接，使得整个开发更加独立，设计人员可以只专注于自己所负责的领域


---------------------------------------------------
In this project, we wrote a software which can edit pictures. This GUI of this GraphicsEditor was developed by Qt5 in QtCreator, and
the part of image processing was implemented by using OpenCV3.2.

There are some basic functions in this GraphicsEditor. We can use the GraphicsEditor to adjust the brightness, contrast, size or format
of a digit image. Besides, we can change the style of a photo by using filters.

The architectural pattern of this software is Model–view–viewmodel(MVVM). We separate view layer development and application development
to make the efficiency of our team better because each programmer can focus on his own field. 
