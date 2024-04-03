//
// Created by feng on 2020/11/16.
//

#ifndef DESIGNPATTERN_COMPOSITE_H
#define DESIGNPATTERN_COMPOSITE_H
#include <string>
#include <vector>
#include <iostream>

namespace composite{

    class File {
        std::string _path;
    public:
        explicit File(const std::string &path);
        const std::string &getPath() const;

        virtual void display(int depth) = 0;

    };


    class Image:public File{
    public:
        explicit Image(const std::string &path);
        void display(int depth) override;
    };

    class Text:public File{
    public:
        explicit Text(const std::string &path);
        void display(int depth) override;
    };

    class Folder: public File{
        std::vector<File*> _files;
    public:
        explicit Folder(const std::string& path):File(path){}
        void add(File* file);
        void display(int depth) override ;

    };

    void testComposite();
}


#endif //DESIGNPATTERN_COMPOSITE_H
