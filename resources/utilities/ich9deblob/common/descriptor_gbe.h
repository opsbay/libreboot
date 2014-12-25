/*
 *  gbe_descriptor.h
 *  This file is part of the ich9deblob utility from the libreboot project
 * 
 * Purpose: header file for descriptor_gbe.c
 *
 *  Copyright (C) 2014 Steve Shenton <sgsit@libreboot.org>
 *                     Francis Rowe <info@gluglug.org.uk>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef COMMON_DESCRIPTOR_GBE_H
#define COMMON_DESCRIPTOR_GBE_H

#include <stdio.h>
#include <string.h>

#include "../descriptor/descriptor.h" /* structs describing what's in the descriptor region */
#include "../gbe/gbe.h"               /* structs describing what's in the gbe region */

int notCreatedDescriptorGbeFile(struct DESCRIPTORREGIONRECORD descriptorStruct, struct GBEREGIONRECORD_8K gbeStruct8k, char* fileName);

#endif