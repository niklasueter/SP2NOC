// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vcounter_H_
#define _Vcounter_H_

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"
class Vcounter__Syms;

//----------

SC_MODULE(Vcounter) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_out<uint32_t>	out;
    sc_in<bool>	enable;
    sc_in<bool>	clk;
    sc_in<bool>	reset;
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vcellinp__v__clk,0,0);
    VL_SIG8(__Vcellinp__v__reset,0,0);
    VL_SIG8(__Vcellinp__v__enable,0,0);
	VL_SIG8(__Vcellout__v__out, 3, 0);
    VL_SIG8(__Vclklast__TOP____Vcellinp__v__clk,0,0);
	//char	__VpadToAlign29[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
	//char	__VpadToAlign36[4];
    Vcounter__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vcounter& operator= (const Vcounter&);	///< Copying not allowed
    Vcounter(const Vcounter&);	///< Copying not allowed
  public:
    SC_CTOR(Vcounter);
    virtual ~Vcounter();
    
    // USER METHODS
    
    // API METHODS
  private:
    void eval();
  public:
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcounter__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcounter__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vcounter__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(Vcounter__Syms* __restrict vlSymsp);
    static void	_combo__TOP__4(Vcounter__Syms* __restrict vlSymsp);
    static void	_eval(Vcounter__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vcounter__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vcounter__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vcounter__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(Vcounter__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
