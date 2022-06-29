#include "pch.h"
#include "File.h"



inline size_t File::GetSize()
{

    std::ifstream fin(this->path, std::ios::binary);
    fin.seekg(0, std::ios::end);
    size_t n = fin.tellg();
    fin.seekg(0, std::ios::beg);
    fin.close();
    return n;

}
inline std::string File::GetFileName()
{
    std::vector<std::string> SplitString = split(path, "\\");

    return SplitString[SplitString.size() - 1];
}
inline std::string File::GetFileExeption()
{
    std::vector<std::string> SplitString = split(path, "\\");
    std::vector<std::string> FileNameSplit = split(SplitString[SplitString.size() - 1], ".");

    return FileNameSplit[FileNameSplit.size() - 1];
}
inline char* File::ReadAllBytes()
{
    std::ifstream fin(this->path, std::ios::binary);
    size_t n = this->GetSize();
    char* arr = new char[n];
    fin.read(arr, n);
    fin.close();

    return arr;
}
void File::WriteAllBytes(std::string path, char* data)
{
    std::ofstream file(path, std::ios::binary);
    file.write(data, this->GetSize());
}
inline std::vector<std::string> File::split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}
template<typename T>
inline int File::getSizeArr(T* p)
{
    int size = (sizeof(p) / sizeof(*p));
    return size;
}
