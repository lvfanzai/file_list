#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cmath>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>

using namespace std;

vector<string> SearchSubfolder(string folder) {
    DIR *dp;
    vector<string> files;
    struct dirent *dirp;
    printf("%s\n",folder.c_str());
    if ((dp  = opendir(folder.c_str())) == NULL) {
        printf("could not open folder %s, %d, %s\n", folder.c_str(), errno, strerror(errno));
        return files;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".")!=0 && strcmp(dirp->d_name, "..")!=0 && dirp->d_type == DT_DIR)
            files.push_back(folder+"/"+string(dirp->d_name));
    }
    closedir(dp);
    sort(files.begin(), files.end());
    return files;
}

vector<string> SearchDirectory(string folder, string subname) {
    DIR *dp;
    vector<string> files;
    struct dirent *dirp;
    printf("%s\n",folder.c_str());
    if ((dp  = opendir(folder.c_str())) == NULL) {
        printf("could not open folder %s, %d, %s\n", folder.c_str(), errno, strerror(errno));
        return files;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (/*strcmp(dirp->d_name, "img_res.raw") != 0 && */strstr(dirp->d_name, subname.c_str()) && dirp->d_type != DT_DIR)
            files.push_back(folder+"/"+string(dirp->d_name));
    }
    closedir(dp);
    sort(files.begin(), files.end());
    return files;
}
