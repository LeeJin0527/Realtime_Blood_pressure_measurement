/* mbed USBMSD_BD Library, for providing file access to Block Devices
 * Copyright (c) 2008-2010, sford
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef USBMSD_BD_H
#define USBMSD_BD_H

#include "mbed.h"
#include "BlockDevice.h"
#include "USBMSD.h"

/** Use the SDcard as mass storage device using the USBMSD class
 *
 * @code
 * #include "mbed.h"
 * #include "USBMSD_BD.h"
 *
 * USBMSD_BD sd(p5, p6, p7, p8);
 *
 * int main() {
 *   while(1);
 * }
 *
 * @endcode
 */
class USBMSD_BD : public USBMSD {
public:

    /** Create the File System for accessing an SD Card using SPI
     *
     * @param mosi SPI mosi pin connected to SD Card
     * @param miso SPI miso pin conencted to SD Card
     * @param sclk SPI sclk pin connected to SD Card
     * @param cs   DigitalOut pin used as SD Card chip select
     * @param name The name used to access the virtual filesystem
     */
    USBMSD_BD(BlockDevice *bd);
    virtual int disk_initialize();
    virtual int disk_status();
    virtual int disk_read(uint8_t * buffer, uint64_t block_number, uint8_t count);
    virtual int disk_write(const uint8_t * buffer, uint64_t block_number, uint8_t count);
    virtual int disk_sync();
    virtual uint64_t disk_sectors();    
    virtual uint64_t disk_size();

protected:
    
    uint64_t _sectors;
    bd_size_t _ssize;
    
    uint8_t _status;
    
    BlockDevice* _bd;
};

#endif
