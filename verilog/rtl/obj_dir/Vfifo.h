// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vfifo_H_
#define _Vfifo_H_

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"
class Vfifo__Syms;

//----------

SC_MODULE(Vfifo) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_in<bool>	i_clk;
    sc_in<bool>	i_wr;
    sc_in<uint32_t>	i_data;
    sc_out<bool>	o_full;
    sc_out<uint32_t>	o_fill;
    sc_in<bool>	i_rd;
    sc_out<uint32_t>	o_data;
    sc_out<bool>	o_empty;
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__wr_addr,4,0);
    VL_SIG8(v__DOT__rd_addr,4,0);
    VL_SIG8(v__DOT__w_wr,0,0);
    //char	__VpadToAlign39[1];
    VL_SIG8(v__DOT__fifo_mem[16],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vcellinp__v__i_clk,0,0);
    VL_SIG8(__Vcellout__v__o_data,7,0);
    VL_SIG8(__Vcellinp__v__i_rd,0,0);
    VL_SIG8(__Vcellout__v__o_fill,4,0);
    VL_SIG8(__Vcellinp__v__i_data,7,0);
    VL_SIG8(__Vcellinp__v__i_wr,0,0);
    VL_SIG8(__Vclklast__TOP____Vcellinp__v__i_clk,0,0);
    //char	__VpadToAlign67[1];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfifo__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vfifo& operator= (const Vfifo&);	///< Copying not allowed
    Vfifo(const Vfifo&);	///< Copying not allowed
  public:
    SC_CTOR(Vfifo);
    virtual ~Vfifo();
    
    // USER METHODS
    
    // API METHODS
  private:
    void eval();
  public:
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vfifo__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfifo__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vfifo__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(Vfifo__Syms* __restrict vlSymsp);
    static void	_combo__TOP__10(Vfifo__Syms* __restrict vlSymsp);
    static void	_combo__TOP__4(Vfifo__Syms* __restrict vlSymsp);
    static void	_eval(Vfifo__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vfifo__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vfifo__Syms* __restrict vlSymsp);
    static void	_initial__TOP__6(Vfifo__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vfifo__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__7(Vfifo__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__9(Vfifo__Syms* __restrict vlSymsp);
    static void	_settle__TOP__8(Vfifo__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
