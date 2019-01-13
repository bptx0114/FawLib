﻿#////////////////////////////////////////////////////////////////////////////////
//
// Class Name:  Directory
// Description: 文件夹类
// Class URI:   https://github.com/fawdlstty/FawLib
// Author:      Fawdlstty
// Author URI:  https://www.fawdlstty.com/
// License:     MIT
// Last Update: Jan 13, 2019
//
////////////////////////////////////////////////////////////////////////////////

#ifndef FAWLIB__DIRECTORY_HPP__
#define FAWLIB__DIRECTORY_HPP__



#include <Windows.h>



namespace faw {
	class Directory {
		Directory () {}
	public:
		static bool exist (LPCTSTR _path) {
			DWORD _attr = ::GetFileAttributes (_path);
			return (_attr != INVALID_FILE_ATTRIBUTES && _attr & FILE_ATTRIBUTE_DIRECTORY);
		}
		static bool create (LPCTSTR _path, DWORD _attr = 0) {
			bool bRet = (exist (_path) ? true : !!::CreateDirectory (_path, NULL));
			if (bRet) {
				_attr &= (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_DEVICE | FILE_ATTRIBUTE_NORMAL);
				if (_attr)
					::SetFileAttributes (_path, _attr);
			}
			return bRet;
		}
	};
}



#endif //FAWLIB__DIRECTORY_HPP__
