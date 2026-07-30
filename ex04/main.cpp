#include <iostream>
#include <fstream>

typedef std::string     string;
typedef std::ifstream   ifstream;
typedef std::ofstream   ofstream;


int err(string msg)
{
    std::cout << "Error: " << msg << std::endl;
    return (1);
}

int main(int ac, char **av)
{
    string filename(av[1]);
    string toFind(av[2]);
    string toReplace(av[3]);

    ifstream toRead;
    ofstream toWrite;

    string fileContent;
    string line;

    if (ac != 4)
        return (err("Usage: ./replace <filename> <s1> <s2>"));

    if (toFind.empty())
        return (err("s1 cannot be empty"));
    
    //Opening the file to read from
    toRead.open(filename.c_str());
    if(toRead.fail())
        return (err(string("failed to open file '") + filename + "'"));

    //Openng the file to write into
    toWrite.open((filename + ".replace").c_str());
    if (toWrite.fail())
        return (toRead.close(),
                err(string("failed to create new file '") + filename + ".replace'"));

    //Reading file content into a string 
    while (std::getline(toRead, line))
    {
        if (!fileContent.empty())
            fileContent.append("\n"); //add a newline before evry read run, except for the first line
        fileContent.append(line);
    }

    //Replace the found strings
    string::size_type pos = 0;
    while ((pos = fileContent.find(toFind, pos)) != string::npos)
    {
        fileContent.replace(pos, toFind.length(), toReplace);
        pos += toReplace.length();
    }

    //Writing the content into <filname>.replace file
    toWrite << fileContent;
    
    toRead.close();
    toWrite.close();
}