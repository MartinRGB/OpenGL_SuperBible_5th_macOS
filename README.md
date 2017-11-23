# OpenGL_SuperBible_5th_macOS
Get a environment of opengl learning(tutorial from spweau_me)


## How to

1.Open XCode,create `macOS Cocoa Application`

2.Add `GLUT.framework` && `OpenGL.framework` in `Target -> Build Phases -> Link Binary With Libraries`

3.in `Build Settings -> Header Search Path` , add `${thisprojectpath}/OpenGlShare/include` (I use `../OpenGlShare/include`) 

4.Drag `libGLTools.a` into `Frameworks` Folder

5.Delete `AppDelegate.h` | `AppDelegate.m` | `main.m`(in Supporting Files) | `ViewController.h` | `ViewController.m`

6.Create a file named main.cpp

7.Begin learning OpenGL SuperBible,enjoy!

**三篇关于 MacOS 下 OGL 环境配置文章：**

[OpenGL 在Mac 上的配置（根据OpenGL超级宝典第五版）](http://www.jianshu.com/p/002e1845bfa6)

这个解决了 GLTools 和 GLEW

[OSX 10.11.3 下编译安装 GLFW-3.2](https://my.oschina.net/freeblues/blog/687630)

这个解决了 GLFW，但 Mac OS X 10.12后会有窗口创建问题，参考这个 [Issue](https://github.com/glfw/glfw/issues/908)

[在Xcode中配置GLEW+GLFW环境](http://blog.csdn.net/longzh_cn/article/details/55001345)

Header | Lib | Framerwork

## What I learned:

### Project 2.6

简单的 `碰撞检测`

使用同一组顶点数据，在 `键盘控制` 和 `绘制` 回调函数中，先检测顶点的实时位置，然后检测和屏幕碰撞情况

#### TODO

- [ ] 加入 GL 版本 Easing Cpp Library

- [ ] 研究以下资料：

[Improved Easing Functions](https://joshondesign.com/2013/03/01/improvedEasingEquations)

[Robert Penner's Easing Functions](http://robertpenner.com/easing/)

[Choreograph](https://github.com/sansumbrella/Choreograph)
           
[Claw](http://libclaw.sourceforge.net/tweeners.html)
           
[CppTweener](https://code.google.com/archive/p/cpptweener/)
