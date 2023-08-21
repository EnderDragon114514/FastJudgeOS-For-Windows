# FastJudgeOS-For-Windows —— 一个为轻量化快速编译而生的评测机，适用于Windows系统

由于某些SDK原因，暂未开发Linux版

[点击前往作者的主页](https://enderdragon114514.github.io/Homepage/index.html)

## Part 1 介绍

这就是一个评测机，可以通过传入参数实现的快速评测

## Part 2 开发原因

没什么原因，就是看了[lemon评测机](https://oi-wiki.org/tools/judger/lemon/)后自己写的一个评测机，依赖于WindowsAPI

## Part 3 更新日志

#### v0.1.0 Beta Release 1

初版开发，功能不完全

#### v0.1.0 Beta Release 2

开发ing，再等一下嘛，~~很快~~一会儿就好了

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
若返回值为-1或4292967295，评测结果为SE
若返回值为0~100，则表示评测结果为AC(100)或WA(0~99)
若返回值为128，则表示评测结果为CE
若返回值为256，则表示评测结果为TLE或MLE，也有可能是RE
6. 评测文件
6.1. 启动主程序并检查所有文件是否正常
6.2. 输入比赛名称（注:必须与配置文件名称一致，需要添加后缀`.fjcf`）
6.3. 开始评测
6.4. 输出成绩并退出程序

## Part 5 开源说明

本软件使用GPLv3开源协议，此处为附加条款，与原始协议互不冲突

1. 禁止恶意盗用此软件或其中的任何一部分
2. 禁止删除软件版权信息

# 最后希望大家点一下Star(右上角那个)支持一下我吧！
