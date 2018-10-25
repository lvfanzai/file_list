#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cmath>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>

#include "file_list.h"

using namespace std;

//读文件中的数据
vector<unsigned char> read_file(char const* path) {
    vector<unsigned char> data;
    FILE* fin = fopen(path, "rb");
    if (!fin) {
        fprintf(stderr, "failed to read %s\n", path);
        abort();
    }

    fseek(fin, 0, SEEK_END);
    size_t len = ftell(fin);
    rewind(fin);

    data.resize(len);
    fread(data.data(), 1, len, fin);

    fclose(fin);

    return data;
}

int main()
{
    string folder = "file_imgs";
    
    vector<string> subfolders = SearchSubfolder(folder);
    for (int ff = 0; ff < subfolders.size(); ff++) {
        string foldername = subfolders[ff];
        vector<string> rawfiles = SearchDirectory(foldername, ".raw");
        int num_frames = rawfiles.size();

        // read image
        vector<vector<unsigned char> > images;
        for (int i = 0; i < num_frames; i++) {
            printf("rawfiles[%d] name = %s\n",i,rawfiles[i].c_str());
            auto sample = read_file(rawfiles[i].c_str());
            images.push_back(sample);
        }
    }

    return 0;
}