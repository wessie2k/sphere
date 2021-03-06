#include "DefaultFile.hpp"
////////////////////////////////////////////////////////////////////////////////
DefaultFile::~DefaultFile()
{
    fclose(m_file);
}

////////////////////////////////////////////////////////////////////////////////
int
DefaultFile::Read(void* bytes, int size)
{
    return fread(bytes, 1, size, m_file);
}

////////////////////////////////////////////////////////////////////////////////
int
DefaultFile::Write(const void* bytes, int size)
{
    return fwrite(bytes, 1, size, m_file);
}

////////////////////////////////////////////////////////////////////////////////
int
DefaultFile::Size()
{
    long pos = ftell(m_file);
    fseek(m_file, 0, SEEK_END);
    int end = ftell(m_file);
    fseek(m_file, pos, SEEK_SET);
    return end;
}

////////////////////////////////////////////////////////////////////////////////
int
DefaultFile::Tell()
{
    return ftell(m_file);
}

////////////////////////////////////////////////////////////////////////////////
void
DefaultFile::Seek(int position)
{
    fseek(m_file, position, SEEK_SET);
}

////////////////////////////////////////////////////////////////////////////////
DefaultFile::DefaultFile(FILE* file)
{
    m_file = file;
}

////////////////////////////////////////////////////////////////////////////////
