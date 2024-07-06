#include "File.h"
#include "Directory.h"
#include <iostream>
using namespace std;

int main () {
    seneca::File* f1 = new seneca::File("flag.jpg", "A Canadian flag.");
    cout << f1->path() <<endl;
    seneca::Directory* videos = new seneca::Directory("videos/");
    seneca::Directory* images = new seneca::Directory("images/");
    f1->update_parent_path("videos/");
    cout << f1->path() <<endl;
    return 0;
}