//
// Created by yangfan.
//

#ifndef FILE_LIST_H
#define FILE_LIST_H

#include <iostream>
#include <stdio.h>
#include <vector>


std::vector<std::string> SearchSubfolder(std::string folder);
std::vector<std::string> SearchDirectory(std::string folder, std::string subname);


#endif //FILE_LIST_H