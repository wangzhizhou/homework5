# compile and run with test data file

- `tar zxvf homework5.tar.gz`解压文件
- `corpus`是输入文件的路径
-  生成的执行文件名为`homeword5`
- `make clean && make debug`会生成带有调试输出的执行文件

## Release

```
$ make clean && make && ./homework5 corpus

```

## Debug

```
$ make clean && make debug && ./homework5 corpus
```

