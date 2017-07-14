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

摘其内容如下：

各个类以及之间关系如下：

### App

```c++
class App
{
private:
    std::shared_ptr<View> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;

public:
    App();
    void run();
};
```

在构造函数中，对各项需要初始化和绑定的数据进行绑定：

```c++

App::App():view(new View),model(new Model), viewmodel(new ViewModel)
{

    viewmodel->bind(model);

    view->set_img(viewmodel->get());

    view->set_open_file_command(viewmodel->get_open_file_command());
    view->set_alter_bright_command(viewmodel->get_alter_bright_command());
    view->set_filter_rem_command(viewmodel->get_filter_rem_command());
    view->set_reset_command(viewmodel->get_reset_command());
    view->set_detect_face_command(viewmodel->get_detect_face_command());
    view->set_save_file_command(viewmodel->get_save_file_command());
    view->set_save_bmp_file_command(viewmodel->get_save_bmp_file_command());
    view->set_rotate_command(viewmodel->get_rotate_command());
    view->set_crop_command(viewmodel->get_crop_command());

    viewmodel->set_update_view_notification(view->get_update_view_notification());
    model->set_update_display_data_notification(viewmodel->get_update_display_data_notification());

}
```



### View

```c++
class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

    void update();
    void set_img(std::shared_ptr<QImage> image);
    void set_open_file_command(std::shared_ptr<Command>);
    void set_alter_bright_command(std::shared_ptr<Command>);
    void set_filter_rem_command(std::shared_ptr<Command>);
    void set_reset_command(std::shared_ptr<Command>);
    void set_detect_face_command(std::shared_ptr<Command>);
    void set_save_file_command(std::shared_ptr<Command>);
    void set_save_bmp_file_command(std::shared_ptr<Command>);
    void set_rotate_command(std::shared_ptr<Command>);
    void set_crop_command(std::shared_ptr<Command>);
    std::shared_ptr<Notification> get_update_view_notification();

private slots:
    void on_button_open_clicked();
    void on_brightSlider_valueChanged(int value);
    void on_contrastSlider_valueChanged(int value);
    void on_filter_1_clicked();
    void on_reset_clicked();
	void on_actionOpen_File_triggered();
    void on_button_detect_face_clicked();
    void on_actionSave_triggered();
    void on_action_bmp_triggered();
    void on_action_png_triggered();
    void on_action_jpeg_triggered();
    void on_rotateSlider_valueChanged(int value);

private:
    Ui::View *ui;
    MyView* canvas;
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Command> open_file_command;
    std::shared_ptr<Command> alter_bright_command;
    std::shared_ptr<Command> filter_rem_command;
    std::shared_ptr<Command> reset_command;
    std::shared_ptr<Command> detect_face_command;
    std::shared_ptr<Command> save_file_command;
    std::shared_ptr<Command> save_bmp_file_command;
    std::shared_ptr<Command> rotate_command;
    std::shared_ptr<Command> crop_command;

    std::shared_ptr<Notification> update_view_notification;
};
```

本身提供一个用于更新的`notification`, 并提供`get()`方法交给`ViewModel`层进行绑定，如此可以实现`ViewModel`通知`View`进行更新。

同时，本身提供很多`Command`的成员变量，这些变量本省并不属于`View`层，本身属于`ViewModel`层，并在`ViewModel`层提供`get`方法给`View`层进行`set`绑定，这样就实现了`View`发送`command`给`ViewModel`层，`View`就可以在不知道Command具体派生类的情况下写代码。

### ViewModel

```c++
class ViewModel
{
private:
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Model> model;


    std::shared_ptr<Command> open_file_command;
    std::shared_ptr<Command> alter_bright_command;
    std::shared_ptr<Command> filter_rem_command;
    std::shared_ptr<Command> reset_command;
    std::shared_ptr<Command> detect_face_command;
    std::shared_ptr<Command> save_file_command;
    std::shared_ptr<Command> save_bmp_file_command;
    std::shared_ptr<Command> rotate_command;
    std::shared_ptr<Command> crop_command;

    std::shared_ptr<Notification> update_display_data_notification;

    std::shared_ptr<Notification> update_view_notification;

public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void exec_open_file_command(std::string path);
    void exec_alter_bright_command(int nBright, int nContrast);
    void exec_filter_rem_command();
    void exec_reset_command();
    void exec_detect_face_command();
    void exec_save_file_command(std::string path);
    void exec_save_bmp_file_command(std::string path);
    void exec_rotate_command(int angle);
    void exec_crop_command(double x_s, double y_s, double x_e, double y_e);

    void set_update_view_notification(std::shared_ptr<Notification> notification);

    std::shared_ptr<Command> get_open_file_command();
    std::shared_ptr<Command> get_alter_bright_command();
    std::shared_ptr<Command> get_filter_rem_command();
    std::shared_ptr<Command> get_reset_command();
    std::shared_ptr<Command> get_detect_face_command();
    std::shared_ptr<Command> get_save_file_command();
    std::shared_ptr<Command> get_save_bmp_file_command();
    std::shared_ptr<Command> get_rotate_command();
    std::shared_ptr<Command> get_crop_command();

    std::shared_ptr<Notification> get_update_display_data_notification();
    std::shared_ptr<QImage> get();

    void notified();
};

```

与`View`层之间的通信在之前已经讲过，在构造函数中初始化具体的命令，然后`get`交给`View`的`set`进行绑定。这其中有一个向基类指针的转换，我是这么写的：

```c++
 open_file_command = std::static_pointer_cast<Command, OpenFileCommand>(std::shared_ptr<OpenFileCommand> (new OpenFileCommand(std::shared_ptr<ViewModel>(this))));
```

然后与`Model`间的通信没有通过`Command`，而是直接获得一个`Model`的指针，调用它的功能函数即可。

### Model

```c++

class Model
{
private:
     cv::Mat image;
     std::shared_ptr<Notification> update_display_data_notification;
public:
    Model(){}
    void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    void open_file(std::string path);
    cv::Mat& get();
    cv::Mat& getOrigin();
    void notify();
    void save_file(std::string path);
    void save_bmp_file(std::string path);

    void alterBrightAndContrast(int nbright, int nContrast);
    void detect_face();
    void filterReminiscence(); //Filter No.1
	void reset();
    void rotate(double angle);
    void crop(int x1, int y1, int x2, int y2);
};


```

`Model`层本身又一个set一个notification的接口，这个notification用于通知`ViewModel`进行更新数据。

其他的就是针对数据的一些功能代码。

### Command

本身可以写为纯虚类，我是写了一个成员变量是一个基类参数的指针，然后所有具体的command都是派生于此，提供`exec()`方法。

```c++

class Command
{
protected:
    std::shared_ptr<Parameters> params;
public:
    Command();
    void set_parameters(std::shared_ptr<Parameters> parameters){
        params = parameters;
    }
    virtual void exec() = 0;
};
```



### Notification

```c++

class Notification
{
public:
    Notification();
    virtual void exec() = 0;
};



class UpdateDisplayDataNotification: public Notification{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    UpdateDisplayDataNotification(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    void exec(){
        viewmodel->notified();
    }
};


class UpdateViewNotification: public Notification{
private:
    std::shared_ptr<View> view;
public:
    UpdateViewNotification(std::shared_ptr<View> v):view(v){}
    void exec(){
        view->update();
    }
};

```



### Parameters

```c++

class Parameters
{
public:
    Parameters();
};


class PathParameters: public Parameters{
private:
    std::string path;
public:
    PathParameters(std::string _path):path(_path){
    }
    std::string get_path(){
        return path;
    }
};
```

以`PathParameters`为例表示了一般的新的参数的派生方法。

### common

实现了`cv::Mat`与`QImage`之间的转换代码。



### 整体流程

在`View`层进行操作之后，会触发对应槽函数，该槽函数会准备好参数`Parameter`交给对应的`Command`，然后执行`exec()`这个command，exec会解出参数交给`ViewModel`层，`ViewModel`调用`Model`里对应的方法，进行数据操作，`Model`操作完之后会通知`ViewModel`更新显示数据，`ViewModel`会通知`View`刷新显示。

## 7. 小组成员

- 组长： 
<<<<<<< HEAD
  - 杨晗  `MVVM`框架搭建  人脸检测功能实现 细节工作的统筹
=======
  - 杨晗  `MVVM`框架搭建  人脸检测功能实现
>>>>>>> 5a39c43329f18343fdd3cb4fc0236a4f13f7e0f2
- 组员：
  - 王大鑫： jenkins环境搭建   Model层各项基本功能实现
  - 方钲清： QT界面绘制编写
  - 孙健： 功能测试