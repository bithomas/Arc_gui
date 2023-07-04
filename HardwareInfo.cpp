#include "pch.h"
#include "framework.h"
#include <vector>
#include <iomanip>
#include "HardwareInfo.h"
#include "hwinfo/hwinfo.h"

using namespace std;

string GetHardwareInfo()
{
    ostringstream oss;
    oss << std::endl << "Hardware Report:" << "\r\n" << "\r\n";
    hwinfo::CPU cpu;
    oss << "----------------------------------- CPU -----------------------------------" << "\r\n";
    oss << std::left << std::setw(20) << "vendor:";
    oss << cpu.vendor() << "\r\n";
    oss << std::left << std::setw(20) << "model:";
    oss << cpu.modelName() << "\r\n";
    oss << std::left << std::setw(20) << "physical cores:";
    oss << cpu.numPhysicalCores() << "\r\n";
    oss << std::left << std::setw(20) << "logical cores:";
    oss << cpu.numLogicalCores() << "\r\n";
    oss << std::left << std::setw(20) << "max frequency:";
    oss << cpu.maxClockSpeed_kHz() << "\r\n";
    oss << std::left << std::setw(20) << "regular frequency:";
    oss << cpu.regularClockSpeed_kHz() << "\r\n";
    oss << std::left << std::setw(20) << "current frequency:";
    oss << hwinfo::CPU::currentClockSpeed_kHz() << "\r\n";
    oss << std::left << std::setw(20) << "cache size:";
    oss << cpu.cacheSize_Bytes() << "\r\n";

    hwinfo::OS os;
    oss << "----------------------------------- OS ------------------------------------" << "\r\n";
    oss << std::left << std::setw(20) << "Operating System:";
    oss << os.fullName() << "\r\n";
    oss << std::left << std::setw(20) << "short name:";
    oss << os.name() << "\r\n";
    oss << std::left << std::setw(20) << "version:";
    oss << os.version() << "\r\n";
    oss << std::left << std::setw(20) << "kernel:";
    oss << os.kernel() << "\r\n";
    oss << std::left << std::setw(20) << "architecture:";
    oss << (os.is32bit() ? "32 bit" : "64 bit") << "\r\n";
    oss << std::left << std::setw(20) << "endianess:";
    oss << (os.isLittleEndian() ? "little endian" : "big endian") << "\r\n";

    hwinfo::GPU gpu;
    oss << "----------------------------------- GPU -----------------------------------" << "\r\n";
    oss << std::left << std::setw(20) << "vendor:";
    oss << gpu.vendor() << "\r\n";
    oss << std::left << std::setw(20) << "model:";
    oss << gpu.name() << "\r\n";
    oss << std::left << std::setw(20) << "driverVersion:";
    oss << gpu.driverVersion() << "\r\n";
    oss << std::left << std::setw(20) << "memory [MiB]:";
    oss << static_cast<double>(gpu.memory_Bytes()) / 1024.0 / 1024.0 << "\r\n";

    hwinfo::RAM ram;
    oss << "----------------------------------- RAM -----------------------------------" << "\r\n";
    oss << std::left << std::setw(20) << "vendor:";
    oss << ram.vendor() << "\r\n";
    oss << std::left << std::setw(20) << "model:";
    oss << ram.model() << "\r\n";
    oss << std::left << std::setw(20) << "name:";
    oss << ram.name() << "\r\n";
    oss << std::left << std::setw(20) << "serial-number:";
    oss << ram.serialNumber() << "\r\n";
    oss << std::left << std::setw(20) << "size [MiB]:";
    oss << static_cast<double>(ram.totalSize_Bytes()) / 1024.0 / 1024.0 << "\r\n";
    oss << std::left << std::setw(20) << "free [MiB]:";
    oss << static_cast<double>(ram.availableMemory()) / 1024.0 / 1024.0 << "\r\n";

    hwinfo::MainBoard main_board;
    oss << "------------------------------- Main Board --------------------------------" << "\r\n";
    oss << std::left << std::setw(20) << "vendor:";
    oss << main_board.vendor() << "\r\n";
    oss << std::left << std::setw(20) << "name:";
    oss << main_board.name() << "\r\n";
    oss << std::left << std::setw(20) << "version:";
    oss << main_board.version() << "\r\n";
    oss << std::left << std::setw(20) << "serial-number:";
    oss << ram.serialNumber() << "\r\n";

    std::vector<hwinfo::Battery> batteries = hwinfo::getAllBatteries();
    oss << "------------------------------- Batteries ---------------------------------" << "\r\n";
    if (!batteries.empty()) {
        int battery_counter = 0;
        for (auto& battery : batteries) {
            oss << "Battery " << battery_counter++ << ":" << "\r\n";
            oss << std::left << std::setw(20) << "  vendor:";
            oss << battery.vendor() << "\r\n";
            oss << std::left << std::setw(20) << "  model:";
            oss << battery.model() << "\r\n";
            oss << std::left << std::setw(20) << "  serial-number:";
            oss << battery.serialNumber() << "\r\n";
            oss << std::left << std::setw(20) << "  charging:";
            oss << (battery.charging() ? "yes" : "no") << "\r\n";
            oss << std::left << std::setw(20) << "  capacity:";
            oss << battery.capacity() << "\r\n";
        }
        oss << "---------------------------------------------------------------------------" << "\r\n";
    }
    else {
        oss << "No Batteries installed or detected" << "\r\n";
    }

    std::vector<hwinfo::Disk> disks = hwinfo::getAllDisks();
    oss << "--------------------------------- Disks -----------------------------------" << "\r\n";
    if (!disks.empty()) {
        int disk_counter = 0;
        for (const auto& disk : disks) {
            oss << "Disk " << disk_counter++ << ":" << "\r\n";
            oss << std::left << std::setw(20) << "  vendor:";
            oss << disk.vendor() << "\r\n";
            oss << std::left << std::setw(20) << "  model:";
            oss << disk.model() << "\r\n";
            oss << std::left << std::setw(20) << "  serial-number:";
            oss << disk.serialNumber() << "\r\n";
            oss << std::left << std::setw(20) << "  size:";
            oss << disk.size_Bytes() << "\r\n";
        }
        oss << "---------------------------------------------------------------------------" << "\r\n";
    }
    else {
        oss << "No Disks installed or detected" << "\r\n";
    }

    // call to get all CPU-Sockets:
    hwinfo::getAllSockets();

    return oss.str();
}