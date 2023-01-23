#include <iostream>
#include "communication.hpp"
#include "kernelinterface.hpp"
#include "offsets.hpp"

int main()
{
    KernelInterface Driver = KernelInterface("\\\\.\\testingdriver");

    DWORD address = Driver.GetClientAddress();
    ULONG processid = Driver.GetProcessID();

    std::cout << " yolo " << std::hex << address << std::endl;

    std::cout << "Hello World!\n";

    while (true) {
        uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processid, address + 0x18AC00, sizeof(uint32_t));

        std::cout << address << std::endl;
        Driver.WriteVirtualMemory(processid, LocalPlayerAddress + 0xEC, 1000, sizeof(int32_t));
    }
}
