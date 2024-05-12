# 安装docker
这一步因为各个用户使用的系统不同,不过多介绍,如果不会可以访问下面网站,找到你对应的解决方案

[如果解决不了docker安装请来这里看看](https://www.runoob.com/docker/)

# docker配置ubuntu环境
1. 使用ubuntu18.04作为环境,首先拉取镜像(我这里选择的是ubuntu:18.04,官网也提供其他版本,如有需要,请自己拉取需要的版本)

[官网链接](https://hub.docker.com/_/ubuntu?tab=tags&page=1)

```
sudo docker pull ubuntu:18.04
```
2. 查看镜像

```
sudo docker images
```
结果:
```
REPOSITORY   TAG       IMAGE ID       CREATED         SIZE
ubuntu       18.04     f9a80a55f492   11 months ago   63.2MB
```
3. 启动镜像,并创建一个容器

```
sudo docker run -itd --name cpp ubuntu:18.04
```
4. 使用docker ps查看当前运行容器
```
sudo docker ps
```
结果:
```
CONTAINER ID   IMAGE          COMMAND       CREATED         STATUS         PORTS     NAMES
8bcb15709fc7   ubuntu:18.04   "/bin/bash"   9 seconds ago   Up 9 seconds             cpp
```
5. 使用exec来启动容器
```
sudo docker exec -it 8bcb bash
```
或者
```
sudo docker exec -it cpp bash
```
上面的containerID和name是等价的
接下来我们就进入ubuntu
结果:
```
root@8bcb15709fc7:
```

6. ubuntu一些配置
* 更新
```
apt-get update
```

* 安装vim
```
apt-get install vim
```

7. 安装build-essential
* build-essential 是 Ubuntu 和基于 Debian 的 Linux 发行版中的一个元包（meta-package），它是为了提供基本的软件构建和编译工具而设计的。当你安装 build-essential 包时，它会同时安装多个与编译相关的工具和库，这使得它成为设置基本 C 和 C++ 编译环境的便捷方式。

一句话来说:安装这个包就能运行c++,甚至这些包中一些其他的编译工具你也能使用
```
apt-get install build-essential
```
* 安装成功会出现:
```
root@8bcb15709fc7:/# g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/7/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 7.5.0-3ubuntu1~18.04' --with-bugurl=file:///usr/share/doc/gcc-7/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-7 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04) 
```

如果你还是有点质疑,那么就用我下面的方法:
* 创建一个cpp文件

```
vim test.cpp
```
* 输入以下代码
```
#include<iostream>
using namespace std;
int main(){
        cout<<"cpp env success!";
        return 0;

}
```
* 按下ESC,然后输入:wq(这是vim的用法,这里不过多介绍)
输入:
```
g++ -o test test.cpp
./test
```
结果:
```
cpp env success!
```
恭喜你,完成了整个环境的配置,但是别急着高兴,下面的步骤更加关键

> ## 补充
>>安装gdb
```
apt-get install gdb
```
>>众所周知,代码的调试是很关键的

8. 保存当前配置的环境
首先,退出当前环境(不用担心环境没保存的原因,之前使用的是exec指令,跟着我走就行)
```
exit
```
输入下面代码:
```
sudo docker ps
CONTAINER ID   IMAGE          COMMAND       CREATED          STATUS          PORTS     NAMES
8bcb15709fc7   ubuntu:18.04   "/bin/bash"   35 minutes ago   Up 35 minutes             cpp
```
接着
```
sudo docker commit 8bcb cpp:1.0.0
sha256:db5b9ce4699430ac29095e4dd315605e413fa24bb17c38d323cad4315e0cc44b
```
最后
```
sudo docker images
REPOSITORY   TAG       IMAGE ID       CREATED         SIZE
cpp          1.0.0     db5b9ce46994   5 seconds ago   465MB
```
成功保存!
至此就完成了整个环境的配置,后面我再写如何使用我们创建的镜像