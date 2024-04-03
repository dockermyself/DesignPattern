//
// Created by feng on 2020/11/16.
//

#include "Composite.h"
#include <string>
#include <iostream>
using namespace std;
using namespace composite;
static const string TAB("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
File::File(const std::string &path):_path(path){}

inline const string &File::getPath() const {
    return _path;
}


Image::Image(const std::string &path) : File(path) {}

inline void Image::display(int depth) {
    cout << TAB.substr(0,depth) << "Image:" << getPath() << endl;
}
Text::Text(const std::string &path) : File(path) {}

inline void Text::display(int depth) {
    cout << TAB.substr(0,depth) << "Text:" << getPath() << endl;
}

inline void Folder::display(int depth) {
    cout << TAB.substr(0,depth) << "Folder:" << getPath() << endl;
    for(auto file : _files){
        file->display(depth + 1);
    }
}

void Folder::add(File *file) {
    _files.push_back(file);
}


void testComposite(){
    Image im_1(string("/home/feng/m_1.jpg"));
    Image im_2(string("/home/feng/m_2.jpg"));
    Image im_3(string("/home/feng/m_3.jpg"));
    Image im_4("/home/feng/m_4.jpg");

    Text text_1("/home/feng/t_1.txt");
    Text text_2("/home/feng/t_2.txt");
    Text text_3("/home/feng/t_3.txt");
    Text text_4("/home/feng/t_4.txt");

    Folder root("/home/feng/root");
    Folder folder_1("/home/feng/f_1");
    Folder folder_2("/home/feng/f_2");
    Folder folder_3("/home/feng/f_3");

    folder_1.add(&im_1);
    folder_1.add(&im_2);
    folder_1.add(&text_1);
    folder_1.add(&text_2);

    folder_2.add(&im_3);
    folder_2.add(&text_3);

    folder_3.add(&folder_2);
    folder_3.add(&im_4);
    folder_3.add(&text_4);

    root.add(&folder_1);
    root.add(&folder_2);
    root.add(&folder_3);

    root.display(0);
}


