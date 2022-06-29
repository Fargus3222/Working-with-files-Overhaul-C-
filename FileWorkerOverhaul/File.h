#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>

class File
{
public:
    File(std::string path)
    {

        this->path = path;

    }
    ~File()
    {
    }


#pragma region GetSize()
    /// <summary> Get size of file </summary>
    /// <param> none </param>
    /// <returns> size_t size of file </returns>
    size_t GetSize();
#pragma endregion

#pragma region GetFileName()
    /// <summary> Get name of file with extension </summary>
    /// <param> none </param>
    /// <returns> string file name </returns>
    std::string GetFileName();
#pragma endregion

#pragma region GetFileExtension()
    /// <summary> Get file extension with out name </summary>
    /// <param> none </param>
    /// <returns> string extension of file </returns>
    std::string GetFileExeption();
#pragma endregion

#pragma region ReadAllBytes()
    /// <summary> Get all bytes in file </summary>
    /// <param> none </param>
    /// <returns> char* array of the byts </returns>
    char* ReadAllBytes();
#pragma endregion

#pragma region WriteAllBytes()
    /// <summary> Write all bytes to the file </summary>
    /// <param name="path"> Path to the file </param>
    /// <param name="data"> Byte array </param>
    /// <returns>  </returns>
    void WriteAllBytes(std::string path, char* data);
#pragma endregion

private:

    static std::vector<std::string> split(std::string s, std::string delimiter);
    template < typename T >
    static int getSizeArr(T* p);

    std::string path;

};


