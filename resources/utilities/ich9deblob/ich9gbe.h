/*
 *  ich9gbe.h
 *  This file is part of the ich9deblob utility from the libreboot project
 *
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
 
// Purpose: provide struct representing gbe region.
// Map actual buffers of this regions, directly to instances of these
// structs. This makes working with gbe really easy.
 
// bit fields used, corresponding to datasheet. See links to datasheets
// and documentation in ich9deblob.c

#ifndef ICH9GBE_H
#define ICH9GBE_H

#define GBEREGIONSIZE 0x2000 // 8 KiB
// These will have a modified descriptor+gbe based on what's in the factory.rom
// These will be joined into a single 12KiB buffer (descriptor, then gbe) and saved to a file
// NOTE: The GBE region of 8K is actually 2x 4K regions in a single region; both 4K blocks can be identical (and by default, are)
// The 2nd one is a "backup", but we don't know when it's used. perhaps it's used when the checksum on the first one does not match?

struct GBEREGIONRECORD_4K {
	unsigned char macAddress[6]; // 0x03 words, or 0x06 bytes
	unsigned char otherStuff[120];  // 0x3c words, or 0x7E bytes
	unsigned short checkSum; // when added to the sum of all words above, this should be 0xBABA
	unsigned char padding1[3968];
};

// main and backup region in gbe
struct GBEREGIONRECORD_8K {
	struct GBEREGIONRECORD_4K main;
	struct GBEREGIONRECORD_4K backup;
	// Backup region:
	// This is actually "main" on X200, since the real main has a bad checksum
	// and other errors. You should do what you need on this one (if modifying
	// lenovobios's gbe region) and then copy to main
};

#endif