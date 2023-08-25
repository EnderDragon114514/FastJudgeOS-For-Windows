# FastJudgeOS-For-Windows —— 一个为轻量化快速编译而生的评测机，适用于Windows系统

#### [点击前往作者的主页](https://enderdragon114514.github.io/Homepage/index.html)

## Part 1 介绍

这就是一个评测机，可以通过传入参数实现的快速评测

## Part 2 开发原因

没什么原因，就是看了[lemon评测机](https://oi-wiki.org/tools/judger/lemon/)后自己写的一个评测机，依赖于WindowsAPI

## Part 3 更新日志

#### v0.1.0 Beta Release 1

初版开发，功能不完全

并且这个版本的代码和程序均已被覆写为Release 2的代码和程序

#### v0.1.0 Beta Release 2

v0.1.0 Beta的最后一个版本

这次除了补全功能和修复bug以外，还增加了Linux版

后续更新中Linux版将会同步Windows版更新(仅支持64位模式)

下次修复Bug时就是0.1.1了

#### v0.1.0 Beta Release 2 Emergency Update 1

这是v0.1.0的一个适用于Linux客户端的一个紧急更新

因为这个版本有一个严重的bug:无法正常读取样例输入输出以及配置文件

所以再额外加一个这个更新

但是客户端版本号不会有变更

同时Windows版会出一个快速安装脚本

这个脚本安装的静态编译版可以直接运行

### 这里最后再声明一次，不要下载裸露在外的文件，那些代码都有BUG！！！！！！一定要前往带版本号文件夹中的！！！！！！！！！！！！！

### 因为GitHub不支持删除指定的文件，而我也没办法通过`git clone`来删除文件，所以大家不要乱下载（测试人员除外）

### 最后声明！！！！！！！！不要下载裸露在外的文件！！！里面的代码都有BUG！！！！！！！一定要前往带版本号文件夹中的！！！！！！！！！！！！！

### 如果发生了任何因为下错文件了而导致的对服务器或电脑产生的任何问题作者不提供任何回复！！！！！！！！！！

### 再说一下，若下错了文件，请立即终止程序运行并重新安装最新版（如果你安装了Linux版，可以先终止运行，然后直接运行新的安装脚本替换文件）

### 当前最新版：0.1.0 Beta Release 2 Emergency Update 1

## Part 4 使用说明

1. 编译器：目前仅支持G++编译器
 
2. 文件存放地址：将要评测的代码命名为`test.cpp`并放在评测机主程序所在目录
 
3. 样例存放地址：将要评测的样例也放在主程序所在目录

4. 配置文件存放地址以及格式：将配置文件存放在主程序所在目录，并确认其中有如下信息：样例总数、输入样例的名称、输出样例的名称，每行一个数据。下面是一个示例格式
```
5
sample1.in
sample2.in
sample3.in
sample4.in
sample5.in
sample1.out
sample2.out
sample3.out
sample4.out
sample5.out
```
5. 返回值解释
   
若返回值为`-1`或`4292967295`，评测结果为SE

若返回值为`0~100`，则表示评测结果为AC(`100`)或WA(`0~99`)

若返回值为`128`，则表示评测结果为CE

若返回值为`256~355`，则表示评测结果为TLE或MLE，也有可能是RE

若为上一种结果，则分数为`返回值-256`

6. 评测文件

6.1. 启动主程序并检查所有文件是否正常

6.2. 输入比赛名称（注:必须与配置文件名称一致，需要添加后缀`.fjcf`）

6.3. 开始评测

6.4. 输出成绩并退出程序

### 注:一定要把MinGW-W64文件夹放在主程序所在目录中，否则将无法正常生成程序！(Windows)

7. Linux版使用说明

7.1. 先解压下载的`.tar.xz`文件至一个文件夹

7.2. 然后以`root`身份运行下面指令:`bash install.sh`

7.3. 安装完成

7.4. 解压下来的文件中有一个叫做`Sources`的文件夹

7.5. 里面有`make.sh`和`FastJudge-For-Linux.cpp`，`.sh`的是快速生成脚本，适用于安装后无法使用的人用这个生成的文件替换`/bin/FastJudge-For-Linux`；`FastJudge-For-Linux.cpp`是程序源代码

## Part 5 开源说明

本软件使用GPLv3开源协议，此处为附加条款，与原始协议互不冲突

1. 禁止恶意盗用此软件或其中的任何一部分
   
2. 禁止删除软件版权信息

# 最后希望大家点一下Star(右上角那个)支持一下我吧！

# 有能力再[投喂](https://enderdragon114514.github.io/Homepage/pay.html)一下呗！
