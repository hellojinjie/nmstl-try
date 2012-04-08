#include <NMSTL/netioevent>
#include <cstdio>
#include <iostream>

using namespace NMSTL;

int main()
{
    
    int readmeFile = open("README", O_RDWR);
    
    IOHandle readmeHandle(readmeFile);
    char charBuffer[1024];
    databuf buffer(charBuffer, 1024);

    lseek(readmeFile, 0, SEEK_SET);
    int readLength = readmeHandle.read(buffer, 6);

    std::cout << readLength << endl;

    std::cout << buffer.length() << endl;
    std::cout << buffer.data() << endl;

    close(readmeFile);
}
