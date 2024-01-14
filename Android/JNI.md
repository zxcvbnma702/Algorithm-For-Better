# JNI

## 运行流程介绍

对于一般的JNI工程，编译、安装、运行的流程大致如下：
编译：

配置工程
编译动态库
将动态库打包进apk

安装：

系统将根据设备支持的ABI，首选主ABI的动态库进行安装，如果以主ABI找动态库找不到，就会继续以次ABI进行安装，如果还是找不到，就不拿动态库了，这一点在Android开发者官网中也有说明

运行：

在运行时，需要先加载动态库，我们一般会在一个类的静态代码块中使用System.loadLibrary进行加载动态库，解析其中的符号
若找不到库，则会提示java.lang.UnsatisfiedLinkError，并在日志中打印相关信息
若加载成功，会进行函数解析，首先会使用dlsym函数检查是否重写了JNI_OnLoad函数，如果重写了该函数，则执行该函数
在运行时，对于已经在JNI_OnLoad函数中进行动态注册的函数，则可以直接找到对应的函数运行；对于未进行动态注册的函数，会按照Java_包名_类名_函数名的规则去寻找native函数，当然了，函数的参数、回传值也是要进行验证的

以上大致就是使用的一个流程，接下来回到工程，对这个默认的工程的一些细节进行解释。

作者：省油的灯
链接：https://juejin.cn/post/6844904025662586888
来源：稀土掘金
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。