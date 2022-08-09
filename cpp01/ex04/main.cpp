#include <fstream>
#include <iostream>

void    create_file(std::fstream *fs, std::string str1, std::string str2)
{
	std::ofstream new_file;
	std::ifstream fs_new;
	std::string buffer;
	std::string temp;
	
	new_file.open("new_file",  std::ios::out | std::ios::trunc);	
	fs_new.open("new_file", std::ios::in | std::ios::out | std::ios::app);

	if (fs_new)
	{
		if (str1.length() == str2.length() && str1.compare(str2) == 0)
		{
			while (!(*fs).eof())
			{
				getline((*fs), buffer);
				new_file << buffer;
				new_file << std::endl;
			}
		}
		else
		{
			while (!(*fs).eof())
			{
				
				getline((*fs), buffer);
				
				int out = buffer.find(str1, 0);
				
				while (out != std::string::npos)
				{
					temp = buffer.substr(0, out);
					temp += str2;
					temp += buffer.substr(out + str1.length(), buffer.length());
					out = buffer.find(str1, out + str1.length());
				}
				new_file << temp;
				new_file << std::endl;
			}
		}
		new_file.close();
	}
	else
		std::cout<<"Error creating new file" <<std::endl;
}

int main (int argc, char **argv)
{
	std::fstream fs;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	if (argv[2] && argv[3])
	{
		fs.open(argv[1], std::fstream::in);
		if (fs.is_open())
		{
			create_file(&fs, argv[2], argv[3]);
			fs.close();
		}
		else
			std::cout << "Open file failed" <<std::endl;
	}
	else
		std::cout << "No strings to replace" << std::endl;    
	return (0);
}