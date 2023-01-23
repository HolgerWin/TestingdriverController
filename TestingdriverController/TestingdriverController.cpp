#include <iostream>
#include "communication.hpp"
#include "kernelinterface.hpp"

int main()
{
    KernelInterface Driver = KernelInterface("\\\\.\\testingdriver");

    DWORD Address = Driver.GetClientAddress();

    std::cout << " yolo " << std::hex << Address << std::endl;

    std::cout << "Hello World!\n";
}
