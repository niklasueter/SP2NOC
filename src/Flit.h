/*
 * MIT License
 *
 * Copyright (c) 2020 TU Dortmund -- Design Automation for Embedded Systems
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights 
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions: 
 * 
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 * SOFTWARE.
 */

#ifndef SP2NOC_FLIT_H
#define SP2NOC_FLIT_H

#include <stdint.h>
#include <iosfwd>
#include <iostream>


struct Coordinate {
	unsigned int x, y;
	bool operator==(const Coordinate& other)
	{
		return ((x == other.x) && (y == other.y));
	}
};

enum FlitType {
	FLIT_TYPE_HEAD = 0,
	FLIT_TYPE_BODY,
	FLIT_TYPE_TAIL
};


template<unsigned size>
struct Payload {
	unsigned int data[size];
};


struct Flit {
	unsigned int src_id;
	unsigned int dst_id;
	unsigned int vc_id; // Virtual Channel
	FlitType flit_type;	// The flit type (FLIT_TYPE_HEAD, FLIT_TYPE_BODY, FLIT_TYPE_TAIL)
	int sequence_no;		// The sequence number of the flit inside the packet
	int sequence_length;
	Payload<12> payload;	// Optional payload
	double timestamp;		// Unix timestamp at packet generation
	int hop_no;			// Current number of hops from source to destination

	int hub_relay_node;



	};

std::ostream& operator<<(std::ostream& os, const Flit& flit) {
	os << flit.vc_id;
	return os;
}

#endif //SP2NOC_FLIT_H
