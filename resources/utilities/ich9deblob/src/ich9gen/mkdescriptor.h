/*
 *  Copyright (C) 2014 Francis Rowe <info@gluglug.org.uk>
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

#ifndef ICH9GEN_MKDESCRIPTOR_H
#define ICH9GEN_MKDESCRIPTOR_H

#include <stdio.h>
#include <string.h>
#include "../descriptor/descriptor.h"

/* ROM image sizes in bytes */
#define ROMSIZE_4MB 0x400000
#define ROMSIZE_8MB 0x800000

struct DESCRIPTORREGIONRECORD generatedDescriptorStruct(unsigned int romSize);
struct DESCRIPTORREGIONRECORD generatedDescriptorStructRom4M();
struct DESCRIPTORREGIONRECORD generatedDescriptorStructRom8M();
#endif
