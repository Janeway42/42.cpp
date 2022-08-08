#include <fstream>
#include <iostream>

void    create_file(std::fstream *fs, std::string str1, std::string str2)
{
    std::fstream fs_new;

    std::ofstream new_file;
    fs_new.open(new_file, std::fstream::in | std::fstream::out | std::fstream::app);

}


int main (int argc, char **argv)
{
    std::fstream fs;

    if (argc != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }

    fs.open(argv[1], std::fstream::in);
    if (fs.is_open())
    {
        if (argv[2] && argv[3])
            create_file(&fs, argv[2], argv[3]);
        fs.close();
    }
    else
        std::cout << "Opne file failed" <<std::endl;
    return (0);
}