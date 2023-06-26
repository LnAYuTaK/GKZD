/**
 * @file FileHelper.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  文件操作 内部全是静态需要静态调用
 * @version 0.1
 * @date 2023-06-25
 * @copyright Copyright (c) 2023
 */
#pragma once
#include <dirent.h>
#include <fcntl.h>
#include <glob.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>
#include <cerrno>
#include <cstddef>
#include <string>
#include <iostream>
/**
 * @brief 文件操作类提供基础文件/文件夹操作管理 
*/
class FileHelper
{
    enum FileType 
    { 
        TYPE_FILE, 
        TYPE_DIR 
    };
public:
    static bool getContent(const std::string &file_name, std::string *content);

    static std::string getAbsolutePath(const std::string &prefix,
                                                            const std::string &relative_path);

    static bool pathExists(const std::string &path);

    static bool directoryExists(const std::string &directory_path);

    static std::vector<std::string> globs(const std::string &pattern);

    static bool copyFile(const std::string &from, const std::string &to);

    static bool copyDir(const std::string &from, const std::string &to);

    static bool copy(const std::string &from, const std::string &to);

    static bool ensureDirectory(const std::string &directory_path);

    static bool removeAllFiles(const std::string &directory_path);

    static std::vector<std::string> listSubPaths(const std::string &directory_path,
                                                 const unsigned char d_type = DT_DIR);

    static std::string getFileName(const std::string &path,
                                    const bool remove_extension = false);

    static std::string getCurrentPath();

    static bool deleteFile(const std::string &filename);

    static bool getType(const std::string &filename, FileType *type);

    static bool createDir(const std::string &dir);

private:
    FileHelper(){;}
    ~FileHelper(){;}

};
