/*
* Copyright (c) 2022, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     cp_copy_interface.h
//! \brief    CP copy interface for content protection
//! \details  Impelements the copy functionalities across all platforms for content protection
//!

#ifndef __CP_COPY_INTERFACE_H__
#define __CP_COPY_INTERFACE_H__

#include "mos_os.h"
#include "media_copy.h"

typedef struct _CPCPY_STATE_PARAMS
{
    bool        bForceMediaCopy  = false;                // If true will use MediaCopy directly.
    MCPY_METHOD mediaCopyMethiod = MCPY_METHOD_BALANCE;  // Read it when bForceMediaCopy is true, otherwise ignore it.
} CPCPY_STATE_PARAMS;

class CpCopyInterface
{
public:
    virtual ~CpCopyInterface(){};

    virtual MOS_STATUS InitCpCopy(PMOS_CONTEXT pOsDriverContext) = 0;

    virtual MOS_STATUS CopyResource(PMOS_SURFACE src, PMOS_SURFACE dst, CPCPY_STATE_PARAMS params) = 0;

    MEDIA_CLASS_DEFINE_END(CpCopyInterface)
};

CpCopyInterface *Create_CpCopyInterface(PMOS_CONTEXT pOsDriverContext, MOS_STATUS &status);

void Delete_CpCopyInterface(CpCopyInterface *pCpCopyInterface);

#endif  // __CP_COPY_INTERFACE_H__