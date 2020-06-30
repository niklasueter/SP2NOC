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


#include "verilog/rtl/obj_dir/Vcounter.h"
#include "verilog/rtl/obj_dir/Vfifo.h"
#include "verilated.h"
#include <iostream>
#include <systemc>
#include <memory>


int sc_main(int argc, char** argv) {
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<Vfifo> fifo = std::make_unique<Vfifo>("fifo");

	sc_clock clk{"clk", 12, SC_NS};
	sc_signal<bool> wr;
	sc_signal<bool> full;
	sc_signal<uint32_t> fill;
	sc_signal<bool> rd;
	sc_signal<bool> empty;
	sc_signal<uint32_t> in_data;
	sc_signal<uint32_t> out_data;

	fifo->i_clk(clk);
	fifo->i_data(in_data);
	fifo->i_wr(wr);
	fifo->o_full(full);
	fifo->o_fill(fill);
	fifo->i_rd(rd);
	fifo->o_data(out_data);
	fifo->o_empty(empty);


	in_data = 1;
	wr = 1;

	in_data = 2;
	wr = 1;

	in_data = 3;
	wr = 1;

	while (!Verilated::gotFinish()) {
		cout << out_data << endl;
		sc_start(12, SC_NS);

	}

	fifo->final();
	exit(EXIT_SUCCESS);
}