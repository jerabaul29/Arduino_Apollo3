//*****************************************************************************
//
//! @file am_hal_ble_patch_b0.c
//!
//! @brief This is a binary patch for the BLE core.
//!
//! @addtogroup
//! @ingroup
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2019, Ambiq Micro
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
// 
// Third party software included in this distribution is subject to the
// additional license terms as defined in the /docs/licenses directory.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision 2.1.0 of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include "am_mcu_apollo.h"

//*****************************************************************************
//
// Patches included in this file.
//
//*****************************************************************************
am_hal_ble_patch_t am_ble_buffer_patch_b0;
am_hal_ble_patch_t am_ble_performance_patch_b0;
am_hal_ble_patch_t am_ble_nvds_patch_b0;

//*****************************************************************************
//
// Patch application order.
//
//*****************************************************************************
am_hal_ble_patch_t *am_hal_ble_default_patch_array_b0[] =
{
    // FTCODE patches (type 0xAA)

    // RAMCODE patches (type 0xBB)
    &am_ble_performance_patch_b0,

    // Standard patches (type 0xCC)
    &am_ble_buffer_patch_b0,

    // nvds param (type 0xDD)
    &am_ble_nvds_patch_b0,
};

#define AM_HAL_BLE_NUM_DEFAULT_PATCHES_B0                                        \
    (sizeof(am_hal_ble_default_patch_array_b0) /                                 \
     sizeof(am_hal_ble_default_patch_array_b0[0]))

am_hal_ble_patch_t **am_hal_ble_default_patches_b0 = am_hal_ble_default_patch_array_b0;
const uint32_t am_hal_ble_num_default_patches_b0 = AM_HAL_BLE_NUM_DEFAULT_PATCHES_B0;

//*****************************************************************************
//
// Patch Name:   RAMCODE PATCH v0.3    for Apollo3 B0

// Reduce duration from TX to TX
// Optimized 32K XO frequency calculation
// Optimized AGC Table
// Fixed Channelmap indication rejected issue
// Date:        2019-03-05
//*****************************************************************************

am_hal_ble_buffer(0x0428) am_ble_performance_patch_data_b0 =
{
    .bytes =
    {
        0x00,0x11,0x24,0x04,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0xc5,0x01,
        0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x1f,0xb5,0x00,0x24,0x00,0x98,0x22,0x28,0x25,0xd2,0x01,0x00,
        0x79,0x44,0x09,0x79,0x49,0x18,0x8f,0x44,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,
        0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x10,0x22,0x22,0x22,0x22,0x22,0x22,0x22,
        0x22,0x13,0x16,0x22,0x22,0x20,0x20,0x20,0x20,0x1c,0x00,0xf0,0x13,0xf8,0x0e,0xe0,
        0x00,0xf0,0x24,0xf9,0x0b,0xe0,0x01,0x98,0xc0,0xb2,0x00,0xf0,0xb3,0xf8,0x04,0x46,
        0x05,0xe0,0x00,0xf0,0x95,0xf9,0x04,0x46,0x01,0xe0,0x00,0x24,0xe4,0x43,0x20,0x46,
        0x04,0xb0,0x10,0xbd,0xf0,0xb4,0x00,0x20,0x43,0x21,0x09,0x06,0x4a,0x68,0xff,0x23,
        0x01,0x33,0x1a,0x43,0x4a,0x60,0x4a,0x68,0x1b,0x03,0x1a,0x43,0x4a,0x60,0x41,0x49,
        0x41,0x4e,0x0a,0x8c,0xb2,0x42,0x20,0xd0,0xe6,0x23,0x0b,0x70,0x28,0x22,0x0a,0x72,
        0x3e,0x4a,0x0a,0x83,0x3e,0x4a,0xe0,0x24,0x14,0x76,0xd4,0x25,0x4d,0x70,0x3c,0x25,
        0x4d,0x72,0x3c,0x4d,0x4d,0x83,0x53,0x76,0xc8,0x27,0x8f,0x70,0x46,0x25,0x8d,0x72,
        0x39,0x4d,0x8d,0x83,0x93,0x76,0xcf,0x70,0x50,0x23,0xcb,0x72,0x37,0x4b,0xcb,0x83,
        0xd4,0x76,0x5a,0x23,0x0b,0x73,0x0e,0x84,0x14,0x77,0xa3,0x24,0xe4,0x05,0x22,0x68,
        0x52,0x08,0x52,0x00,0x22,0x60,0x32,0x4a,0x12,0x69,0xd3,0xb2,0x31,0x4d,0x2a,0x88,
        0xb2,0x42,0x01,0xd3,0x04,0x20,0x0d,0xe0,0x2c,0x4e,0xb2,0x42,0x01,0xd3,0x03,0x20,
        0x08,0xe0,0x29,0x4e,0xb2,0x42,0x01,0xd3,0x02,0x20,0x03,0xe0,0x25,0x4e,0xb2,0x42,
        0x00,0xd3,0x01,0x20,0x0a,0x18,0x20,0x32,0x12,0x7e,0x9a,0x42,0x09,0xda,0x00,0x28,
        0x01,0xdd,0x40,0x1e,0x40,0xb2,0x0a,0x18,0x12,0x7a,0x40,0x00,0x40,0x18,0x00,0x8b,
        0x0b,0xe0,0x04,0x28,0x04,0xda,0x0a,0x5c,0x9a,0x42,0x01,0xdb,0x40,0x1c,0x40,0xb2,
        0x0a,0x18,0x12,0x7a,0x40,0x00,0x40,0x18,0x00,0x8b,0x1b,0x49,0x0a,0x62,0x21,0x68,
        0x49,0x08,0x49,0x00,0x21,0x60,0x19,0x4b,0x19,0x6b,0xff,0x22,0x01,0x32,0x0e,0x46,
        0x16,0x43,0x1e,0x63,0xa0,0x62,0x91,0x43,0x19,0x63,0x28,0x80,0x43,0x21,0x09,0x06,
        0x4b,0x68,0x10,0x03,0x83,0x43,0x12,0x48,0x00,0x78,0xc0,0x07,0xc0,0x0f,0x04,0x05,
        0x23,0x43,0x4b,0x60,0x4b,0x68,0x00,0x02,0x93,0x43,0x03,0x43,0x4b,0x60,0xf0,0xbc,
        0x70,0x47,0x00,0x00,0x50,0x6e,0x00,0x20,0xf6,0x3f,0x00,0x00,0xf6,0x07,0x00,0x00,
        0x70,0x6e,0x00,0x20,0xf6,0x09,0x00,0x00,0xf6,0x2d,0x00,0x00,0xf6,0x38,0x00,0x00,
        0x80,0x00,0x80,0x45,0x50,0x68,0x00,0x20,0x80,0x04,0xc0,0x50,0x40,0x00,0x80,0x45,
        0x3a,0x68,0x00,0x20,0xf8,0xb5,0x2d,0x48,0x00,0x68,0x00,0x28,0x54,0xd1,0x43,0x22,
        0x12,0x06,0x50,0x68,0x01,0x21,0xc9,0x03,0x08,0x43,0x50,0x60,0x28,0x4f,0x3c,0x68,
        0x01,0x25,0x03,0x20,0x00,0x06,0x20,0x43,0x38,0x60,0x00,0x26,0x25,0x49,0x1e,0x20,
        0x88,0x47,0x24,0x49,0x01,0x20,0x88,0x47,0x78,0x68,0xc0,0x07,0xc0,0x0f,0x31,0x46,
        0x21,0x4a,0x76,0x1c,0x91,0x42,0x01,0xd8,0x00,0x28,0xf2,0xd0,0x1c,0x48,0x81,0x68,
        0x1e,0x48,0x01,0x60,0x00,0x20,0x00,0x26,0x00,0x2d,0x11,0xd0,0x1c,0x4b,0x32,0x46,
        0x00,0x25,0xcb,0x1a,0xaa,0x41,0x14,0xda,0x40,0x1c,0x05,0x46,0x18,0x4f,0x4d,0x43,
        0x33,0x46,0x00,0x22,0x7d,0x1b,0x9a,0x41,0x4d,0x1b,0x93,0x41,0xf4,0xdb,0x08,0xe0,
        0x14,0x4b,0x99,0x42,0x05,0xd2,0x40,0x1c,0x02,0x46,0x4a,0x43,0x9a,0x1a,0x8a,0x42,
        0xf9,0xd8,0x01,0x21,0x09,0x06,0x8c,0x43,0x49,0x00,0x0c,0x43,0x08,0x49,0x0c,0x60,
        0x43,0x22,0x12,0x06,0x51,0x68,0x01,0x23,0xdb,0x03,0x99,0x43,0x0a,0x4b,0x1b,0x78,
        0xdb,0x07,0x1b,0x0c,0x19,0x43,0x51,0x60,0xf8,0xbd,0x00,0x00,0x60,0x68,0x00,0x20,
        0x00,0x00,0x40,0x44,0xe5,0x3e,0x00,0x00,0x10,0x27,0x00,0x00,0x64,0x68,0x00,0x20,
        0x00,0x20,0xbc,0xbe,0x00,0xd0,0x12,0x13,0x3a,0x68,0x00,0x20,0x70,0xb5,0x2f,0x4d,
        0x0f,0x20,0x68,0x60,0x8b,0x24,0xe4,0x05,0x20,0x68,0x01,0x21,0x49,0x02,0x88,0x43,
        0x20,0x60,0x2b,0x48,0x80,0x47,0x01,0x20,0x80,0xf3,0x10,0x88,0x29,0x48,0x40,0x68,
        0x29,0x49,0x80,0x00,0x06,0xd4,0x20,0x68,0x08,0x22,0x10,0x43,0x20,0x60,0x01,0x20,
        0x88,0x47,0x01,0xe0,0x01,0x20,0x88,0x47,0x24,0x48,0x80,0x47,0x24,0x48,0x25,0x49,
        0x00,0x78,0x88,0x47,0x0d,0x20,0x68,0x60,0x23,0x48,0x80,0x47,0x43,0x20,0x00,0x06,
        0x41,0x68,0x01,0x23,0x5b,0x03,0x19,0x43,0x41,0x60,0x29,0x21,0x1f,0x4a,0x49,0x06,
        0xca,0x60,0x0a,0x6a,0x12,0x09,0x12,0x01,0x08,0x32,0x0a,0x62,0x0a,0x68,0xdc,0x10,
        0x22,0x43,0x0a,0x60,0x1a,0x4a,0x12,0x78,0x52,0x00,0x52,0x1c,0x4a,0x61,0x42,0x68,
        0x18,0x49,0x9a,0x43,0x09,0x78,0xc9,0x07,0xc9,0x0f,0x4b,0x03,0x1a,0x43,0x42,0x60,
        0x43,0x68,0xa2,0x02,0x13,0x43,0x43,0x60,0x28,0x24,0xa3,0x23,0xdb,0x05,0x1c,0x60,
        0x11,0x4c,0x24,0x88,0x9c,0x62,0x43,0x68,0x09,0x05,0x93,0x43,0x0b,0x43,0x43,0x60,
        0x00,0x20,0x80,0xf3,0x10,0x88,0x0d,0x48,0x80,0x47,0x70,0xbd,0x40,0x00,0x80,0x45,
        0x65,0x50,0x01,0x00,0x80,0x00,0x80,0x45,0xa1,0x59,0x01,0x00,0x29,0x48,0x01,0x00,
        0x41,0x68,0x00,0x20,0xe5,0x3e,0x00,0x00,0xc5,0x64,0x01,0x00,0xcc,0x34,0x63,0x04,
        0x74,0x68,0x00,0x20,0x3a,0x68,0x00,0x20,0x50,0x68,0x00,0x20,0x69,0x48,0x01,0x00,
        0x10,0xb5,0x15,0x48,0x80,0x7a,0xc0,0x07,0x01,0xd0,0x00,0x20,0x10,0xbd,0x13,0x48,
        0x80,0x47,0x05,0x20,0x00,0x07,0xc0,0x69,0x11,0x49,0x00,0x05,0x04,0xd0,0x08,0x78,
        0x01,0x28,0x14,0xd0,0x02,0x28,0x12,0xd0,0x08,0x78,0x00,0x28,0x08,0xd0,0x01,0x28,
        0x06,0xd0,0x02,0x28,0x04,0xd0,0x0b,0x48,0x80,0x47,0x0b,0x49,0x32,0x20,0x88,0x47,
        0x0a,0x49,0x04,0x20,0x88,0x47,0x0a,0x48,0x80,0x47,0x00,0x20,0x10,0xbd,0x09,0x49,
        0x04,0x20,0x88,0x47,0x01,0x20,0x10,0xbd,0x0c,0x6e,0x00,0x20,0x51,0x9a,0x00,0x00,
        0x18,0x10,0x00,0x20,0x69,0x61,0x01,0x00,0xe5,0x3e,0x00,0x00,0x59,0x59,0x01,0x00,
        0xd3,0x60,0x01,0x00,0xa1,0x59,0x01,0x00
    }
};

am_hal_ble_patch_t am_ble_performance_patch_b0 =
{
    .ui32Type = 0xBB,
    .ui32Length = 0x0428,
    .ui32CRC = 0x454a,
    .pui32Data = am_ble_performance_patch_data_b0.words,
};

//*****************************************************************************

//*****************************************************************************
//
// Patch Name:  Function PATCH v0.3    for Apollo3 B0
//
// Reduce duration from TX to TX
// Optimized 32K XO frequency calculation
// Optimized AGC Table
// Fixed Channelmap indication rejected issue
// Date:        2019-03-05
//*****************************************************************************

am_hal_ble_buffer(0x01dc) am_ble_buffer_patch_data_b0 =
{
    .bytes =
    {
        0x00,0x22,0xdc,0x01,0x0f,0x00,0x00,0x00,0x84,0x1d,0x06,0x00,0x73,0x25,0x06,0x00,
        0x75,0x2d,0x06,0x00,0x17,0x33,0x06,0x00,0x21,0x20,0xec,0xf7,0xf9,0xfc,0x00,0x28,
        0x0a,0xd0,0x00,0x20,0x00,0x90,0x03,0x46,0x02,0x46,0x01,0x46,0x24,0x68,0x21,0x20,
        0x35,0x34,0xa0,0x47,0x00,0xbf,0x38,0xbd,0xef,0xf7,0xfb,0xfe,0x0f,0x49,0x00,0x28,
        0x02,0xd0,0x08,0x78,0x01,0x28,0x12,0xd0,0x08,0x78,0x02,0x28,0x0f,0xd0,0x00,0x28,
        0x06,0xd0,0x01,0x28,0x04,0xd0,0x00,0xf0,0x0c,0x6e,0x00,0x20,0x00,0x00,0x00,0x04,
        0x1c,0x6e,0x00,0x20,0x00,0x49,0x08,0x47,0xc1,0x31,0x00,0x20,0x23,0x4e,0xca,0x7c,
        0x75,0x68,0xc9,0x6a,0x00,0x2a,0x1d,0xd0,0x7d,0x22,0x12,0x02,0x91,0x42,0x02,0xd3,
        0x8a,0x1a,0x01,0x20,0x00,0xe0,0x52,0x1a,0x00,0x28,0x05,0xd0,0x20,0x46,0x50,0x43,
        0xea,0xf7,0x02,0xfa,0x20,0x1a,0x04,0xe0,0xea,0xf7,0xde,0xf9,0x00,0x19,0x01,0x02,
        0xc2,0x00,0x69,0x18,0x12,0x18,0x89,0x18,0x4a,0x0a,0x53,0x02,0xc9,0x1a,0x71,0x60,
        0x1e,0x21,0x48,0x43,0x80,0x18,0x70,0xbd,0x2c,0x68,0x00,0x20,0x0c,0x6e,0x00,0x20,
        0x00,0x49,0x08,0x47,0x31,0x32,0x00,0x20,0xc1,0x7c,0xc0,0x6a,0x00,0x29,0x15,0xd0,
        0x7d,0x21,0x09,0x02,0x88,0x42,0x02,0xd3,0x02,0xd5,0x04,0x20,0x60,0x70,0x34,0xe0,
        0x28,0x69,0x06,0xf0,0xb5,0xf8,0x00,0x28,0x02,0xd0,0x02,0x20,0x60,0x70,0x2c,0xe0,
        0x03,0x98,0x04,0xf0,0x1f,0xfa,0x04,0x28,0x07,0xd1,0x68,0x46,0x01,0x79,0x02,0x20,
        0x88,0x43,0x05,0xd0,0x00,0x20,0x00,0x28,0x04,0xd0,0x00,0xbf,0x00,0x20,0x1c,0xe0,
        0x01,0x20,0xf8,0xe7,0xf0,0x88,0x00,0x90,0xf0,0xb4,0x00,0x23,0x18,0x4c,0x25,0x69,
        0x18,0x49,0x7d,0x22,0x09,0x68,0x12,0x02,0x91,0x42,0x02,0xd3,0x8a,0x1a,0x01,0x23,
        0x00,0xe0,0x52,0x1a,0x06,0x46,0x56,0x43,0xf2,0x13,0x51,0x43,0x71,0x1a,0x1e,0x26,
        0x4e,0x43,0x4f,0x10,0xf6,0x19,0x8f,0x11,0xf6,0x19,0x49,0x12,0x71,0x18,0xce,0x13,
        0x00,0x2b,0x01,0xd0,0x80,0x1a,0x00,0xe0,0x10,0x18,0x42,0x19,0x91,0x08,0x8d,0x00,
        0x52,0x1b,0x00,0x2b,0x04,0xd0,0x43,0x01,0x18,0x1a,0x40,0x18,0x80,0x1b,0x03,0xe0,
        0x43,0x01,0x18,0x1a,0x40,0x18,0x80,0x19,0x22,0x61,0xf0,0xbc,0x70,0x47,0x00,0x00,
        0x00,0x6e,0x00,0x20,0x58,0x68,0x00,0x20,0x10,0xb4,0x00,0x23,0x14,0x21,0x02,0x46,
        0x4a,0x43,0x11,0x49,0x7d,0x24,0x09,0x68,0x24,0x02,0xa1,0x42,0x02,0xd9,0x09,0x1b,
        0x01,0x23,0x00,0xe0,0x61,0x1a,0x48,0x43,0x81,0x00,0x41,0x18,0x88,0x0a,0x0c,0x0c,
        0x00,0x19,0x4c,0x0c,0x00,0x19,0x4c,0x0d,0x00,0x19,0x4c,0x0e,0x00,0x19,0xc9,0x0f,
        0x40,0x18,0xc0,0x08,0x00,0x2b,0x01,0xd0,0x10,0x18,0x01,0xe0,0x10,0x1a,0x40,0x1e,
        0x40,0x1e,0x10,0xbc,0x70,0x47,0x00,0x00,0x58,0x68,0x00,0x20
    }
};

am_hal_ble_patch_t am_ble_buffer_patch_b0 =
{
    .ui32Type = 0xCC,
    .ui32Length = 0x01dc,
    .ui32CRC = 0x1440,
    .pui32Data = am_ble_buffer_patch_data_b0.words,
};

//*****************************************************************************
//
// Patch Name:  Function PATCH v0.3    for Apollo3 B0
// Reduce duration from TX to TX
// Optimized 32K XO frequency calculation
// Optimized AGC Table
// Fixed Channelmap indication rejected issue
// Date:        2019-03-05
//*****************************************************************************

am_hal_ble_buffer(0x00cd) am_ble_buffer_nvds_data_b0 =
{
    .bytes =
    {
        0x4e,0x56,0x44,0x53, //NVDS_MAGIC_NUMBER
        0x01,0x06,0x06,0xef,0xbb,0x23,0x88,0x77,0x66, //bluetooth address
        0x02,0x06,0x0a,0x4e,0x5a,0x38,0x38,0x30,0x31,0x56,0x31,0x41,0x00, //device name
        0x03,0x06,0x01,0x00, //system clock frequency, 00=32MHz  01=24MHz  others=16MHz
        0x07,0x06,0x02,0x00,0x00, //32K clock drift, 0x01f4 = 500 ppm
        0x0c,0x06,0x02,50,0x00, //sleep clock accuracy in ppm, 0x01f4 = 500 ppm
        0x08,0x06,0x01,0x00, //01 for BQB qualification, 00 for normal usage
        0x09,0x06,0x01,0x02, //clock source selection, 00 = internal RC32KHz, 02= use Apollo3 MCU 32.768KHz
        0x0a,0x06,0x04,0x00,0x00,0x00,0x00, //0x00000000 = auto detect and low frequency clock calibration
        0x0b,0x06,0x01,0x96, //rx_ifs  0x96 = 150us
        0x23,0x06,0x01,0x95, //tx_ifs  0x95 = 149us
        0x0d,0x06,0x02,0xe8,0x03, //duration allowed for XO32M stabilization from external wakeup
        0x0e,0x06,0x02,0xe8,0x03, //duration allowed for XO32M stabilization from internal wakeup signal
        0x0f,0x06,0x02,0x2c,0x01, //duration allowed for radio to leave low power mode
        0x10,0x06,0x04,0x00,0xc2,0x01,0x00, //set UART_BAUDRATE
        0x11,0x06,0x01,0x01, //sleep algorithm enabled
        // 0x11,0x06,0x01,0x00, //sleep algorithm disabled
        0x12,0x06,0x01,0x01, //external wake-up support
        0x13,0x06,0x02,0xf4,0x01, //duration of sleep and wake-up algorithm
        0x14,0x06,0x02,0x60,0x00, //BLE Company ID
        0x15,0x06,0x01,0x08, //BLE major version
        0x16,0x06,0x01,0x03, //BLE minor version
        0x17,0x06,0x01,0x29, //BLE SW version build
        0x18,0x06,0x02,0x4c,0x04, //advertising interval (undirect)
        0x19,0x06,0x02,0xe2,0x04, //advertising interval (direct)
        0x20,0x06,0x01,0x01, //agc switch on
        0x21,0x06,0x01,0x02, //EA programming latency,set '2' with master mode
        0x22,0x06,0x01,0x00, //EA asap latency
        0x24,0x06,0x04,0x42,0x02,0x6A,0x09, //radio TRX timing
        0x25,0x06,0x01,0x11, //modem polarity setting
        0x26,0x06,0x01,0x00, //modem sync setting
        0x27,0x06,0x01,0x02, //BLE reset delay
        0x2d,0x06,0x01,0x00, //2 byte mode switch, 01 to enable
        0x28,0x06,0x02,0xf6,0x3f, //initial agc gain setting
        0x29,0x06,0x01,0x0f, //initial Tx output power, 0x0f is +4dBm
        0x35,0x06,0x01,0x08, //maximum Tx ouput power setting
        0x37,0x06,0x01,0x00, //RC32K calibration control, 0xAA to enable
        0x05,0x06,0x02,0x34,0x00, //no use
        0x04,0x06,0x01,0x20, //internal dvdd voltage level control if using 0.9V from MCU side
        0x06,0x06,0x08,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //ble feature mask  default 0x21
        0x2e,0x06,0x01,0x00, //instant indication,set "0" to disbale instant reject
        0x00,0x00,0x00,0x00     //dummy
    }
};

am_hal_ble_patch_t am_ble_nvds_patch_b0 =
{
    .ui32Type = 0xDD,
    .ui32Length = 0x00cd,
    .ui32CRC = 0x112b,
    .pui32Data = am_ble_buffer_nvds_data_b0.words,
};

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************
