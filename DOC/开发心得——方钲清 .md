# View层开发心得
## Summary
### 收获
参与本次开发，收获颇丰。主要收获之一在大程序框架的认识，之前只会一些简单的MVC架构，经过指导和联系，认识并实践了一下MVVM框架，认识了其中的难点重点，也体会到了其带来的好处——高效的并行开发。主要收获之二便是学会了利用git加jenkins进行团队合作开发与持续集成，通过这次的训练，感觉自己对工程项目的理解更加深入，对自己编写大程序的能力有了足够的信心

### 负责部分

本次我负责的程序界面的编写，借助此机会，将Qt库熟悉了一下，开发过程中，在View层主要遇到的困难有，槽函数的链接，QTgraphicsView中鼠标的监听，以及下拉槽界面的设计。

### 难点

在View层之外，和viewmodel的通信和传参也可谓是另一个难点，针对每一个新功能，我们都需要设计一条新命令，这就我需要与王大鑫同学事先商量好接口，参数类型等，然后绑定共享指针以便model修改之后将通知通过viewmodel传送到View做相应的update。


### 展望
个人还值得进一步探究的点有，qtwidget的内部实现机制，界面美化等等，还有模块化设计，框架优化等内容还需改进，有机会想试一试不同的实现。

## View类结构

1.Qobject 声明（从QWidget继承)

2.私有成员：ui界面,Canvas类，指令集

3.槽函数集合

4.公有方法：绑定函数，更新


##  GUI组件及其实现的注意点
### Menu
直接通过designer添加菜单，对每一个条目都添加QAction，对于每一个QACtion，修改其名字，转到槽函数，即可得到一个声明为on_#name_triggerd的函数，实现函数体即可。

### button
用Qtdesigner设计了button之后，一定要记得更改button的名字，以及button上显示的文本

### Canvas
从QGraphicsView继承而来，新增几个point以响应鼠标，可以在收到notification的时候即时响应。

在收到鼠标信号的时候实时更新里面point的值，以便能够保持数据的一致性

### SliderBar
在designer中添加了sliderbar之后，需要设置最大最小值，使用的触发条件为valuechanged

## 参数打包
View层通过界面得到参数，类型有int， String，double等，什么基类Parameters，派生出PathParameters，MouseParameters和IntParameters，在槽函数中new一个，通过shared_ptr进行静态转换之后，传入viewmodel

