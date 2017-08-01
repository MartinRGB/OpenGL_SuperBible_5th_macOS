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


Original chinese tutorial from [here](http://www.jianshu.com/p/002e1845bfa6),thanks!

## What I learned:

### Project 2.6

简单的 `碰撞检测`

使用同一组顶点数据，在 `键盘控制` 和 `绘制` 回调函数中，先检测顶点的实时位置，然后检测和屏幕碰撞情况

- [ ] 加入 GL 版本 Easing Cpp Library

- [ ] 阅读 [Improved Easing Functions](https://joshondesign.com/2013/03/01/improvedEasingEquations)

