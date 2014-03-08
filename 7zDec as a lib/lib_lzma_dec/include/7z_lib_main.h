/**
A Test about 7z unCompress.
cswuyg@gmail.com
*/

#ifndef __7Z_LIB_MAIN
#define __7Z_LIB_MAIN


typedef void (*FunType)(char* fmt, ...);    //回调函数，必须是有可变参数的

int lzma_lib_main(int numargs, char *args[], FunType callback);

#endif