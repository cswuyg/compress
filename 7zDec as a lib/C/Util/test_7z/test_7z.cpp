// test_7z.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>
#include <iostream>
extern "C"
{
#include "7z_lib_main.h"
}

const int kBufSize = 4096;

void lzmaCallback(char* fmt, ...)
{
	char info_buf[kBufSize] = { 0 };
	char* p = info_buf;
	va_list args;
	va_start(args, fmt);
	int req_buf_size = _vscprintf(fmt, args) + 1;
	bool has_new = false;
	//大于10K的日志不写
	if (req_buf_size < 10 * 1024)
	{
		if (req_buf_size > kBufSize)
		{
			p = new char[req_buf_size];
			::memset(p, 0, req_buf_size);
			has_new = true;
		}
#if _MSC_VER >= 1400 // 编译器版本为vc8.0及以上
		_vsnprintf_s(p, req_buf_size, _TRUNCATE, fmt, args);
#else
		_vsnprintf(p, req_buf_size, fmt, args);
#endif
	}
	else
	{
		//	buf too long
	}
	va_end(args);

	std::string strLogInfo = p;
	if (has_new)
	{
		delete [] p;
	}
	std::cout << strLogInfo << std::endl;
}


int _tmain(int /*argc*/, _TCHAR* /*argv[]*/)
{
	char* args[4];
	args[0] = "";
	args[1] = "x";
	args[2] = "d:\\test_data_report.7z";
	args[3] = "d:\\zz\\";
	lzma_lib_main(4, args,  lzmaCallback);
	system("pause");
	return 0;
}

