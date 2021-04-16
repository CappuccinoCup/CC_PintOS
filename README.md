## PintOS指南

### 安装PintOS
> 笔者搭建的是基于 qemu 环境的 pintos ，若使用 bochs 请移步
>
> 运行环境：wsl2
1. 运行 `sudo apt-get install qemu-system-x86` 安装 qemu

2. 在git公共库中获取最新PintOS：打开[链接](https://pintos-os.org/cgi-bin/gitweb.cgi?p=pintos-anon;a=summary)，先找到master，点击其后的链接tree，然后点击snapshot下载最新的安装包
3. 把压缩包解压到工作目录。笔者的目录是`/home/cappuccinocup/codes/pintos` ，解压命令：  `tar -xvzf {文件名}`

4. 打开 `src/utils/pintos-gdb` 修改 `GDBMACROS` 变量，填写本机的完整路径。笔者填写的是 `/home/cappuccinocup/codes/pintos/src/misc/gdb-macros`

5. 打开 `src/utils/squish-pty.c` 将报错的 `#include` 语句注释掉并把第286行报错的代码块注释掉

6. 打开 `src/utils/squish-unix.c`  将报错的 `#include` 语句注释掉

7. 在 `/src/utils` 目录下输入 `make` ，编译 utils

8. 打开 `/src/threads/Make.vars` 修改第7行 `bochs` 为 `qemu`

9. 在 `/src/threads` 目录下输入 `make` ，编译 threads

10. 打开 `/utils/pintos` 修改第103行 `bochs` 为 `qemu`

11. 打开 `/utils/pintos` 修改第257行 `kernel.bin`为完整路径的 `kernel.bin` ，笔者填写的是 `/home/cappuccinocup/codes/pintos/src/threads/build/kernel.bin`

12. 打开 `/utils/pintos` 修改621行 `qemu` 为 `qemu-system-x86_64`

13. 打开 `/utils/Pintos.pm` 修改第362行 `loader.bin`为完整路径的 `loader.bin` ，笔者填写的是 `/home/cappuccinocup/codes/pintos/src/threads/build/loader.bin`

14. 打开 `~/.bashrc` 并添加 `export PATH=/home/.../pintos/src/utils:$PATH` 到最后一行

15. 输入 `source ~/.bashrc` 并重新打开终端

16. 输入 `pintos run alarm-multiple` 尝试运行

### Project Threads
> 可供参考的资料：
>
> [Pintos Projects: Table of Contents (stanford.edu)](http://www.scs.stanford.edu/10wi-cs140/pintos/pintos.html)
>
> [如何优雅地完成PintOS（Project1、2） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/343328700)
>
> [GitHub - CCXXXI/pintos](https://github.com/CCXXXI/pintos)
>
> [pintos thread_xwyzsn的博客-CSDN博客](https://blog.csdn.net/xwyzsn/article/details/107396398)

- 压缩包使用方法：临时解压到一个文件夹中，然后将其中的同名文件替换项目中的文件。如此一来运行 `make check` 时就不需要再次编译运行了