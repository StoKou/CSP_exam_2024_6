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