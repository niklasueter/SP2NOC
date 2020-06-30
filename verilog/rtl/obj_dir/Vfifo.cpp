// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfifo.h for the primary calling header

#include "Vfifo.h"             // For This
#include "Vfifo__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_SC_CTOR_IMP(Vfifo)
#if (SYSTEMC_VERSION>20011000)
    : i_clk("i_clk"), i_wr("i_wr"), i_data("i_data"), 
      o_full("o_full"), o_fill("o_fill"), i_rd("i_rd"), 
      o_data("o_data"), o_empty("o_empty")
#endif
 {
    Vfifo__Syms* __restrict vlSymsp = __VlSymsp = new Vfifo__Syms(this, name());
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << i_clk;
    sensitive << i_wr;
    sensitive << i_data;
    sensitive << i_rd;
    
    // Reset internal values
    
    // Reset structure values
    __Vcellout__v__o_data = VL_RAND_RESET_I(8);
    __Vcellinp__v__i_rd = VL_RAND_RESET_I(1);
    __Vcellout__v__o_fill = VL_RAND_RESET_I(5);
    __Vcellinp__v__i_data = VL_RAND_RESET_I(8);
    __Vcellinp__v__i_wr = VL_RAND_RESET_I(1);
    __Vcellinp__v__i_clk = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    v__DOT__fifo_mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__wr_addr = VL_RAND_RESET_I(5);
    v__DOT__rd_addr = VL_RAND_RESET_I(5);
    v__DOT__w_wr = VL_RAND_RESET_I(1);
    __Vclklast__TOP____Vcellinp__v__i_clk = VL_RAND_RESET_I(1);
}

void Vfifo::__Vconfigure(Vfifo__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vfifo::~Vfifo() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vfifo::eval() {
    Vfifo__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vfifo::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vfifo::_eval_initial_loop(Vfifo__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vfifo::_combo__TOP__1(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_combo__TOP__1\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__i_wr, vlTOPp->i_wr);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__i_clk, vlTOPp->i_clk);
}

VL_INLINE_OPT void Vfifo::_sequent__TOP__3(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_sequent__TOP__3\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__wr_addr,4,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__fifo_mem__v0,3,0);
    VL_SIG8(__Vdlyvval__v__DOT__fifo_mem__v0,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__fifo_mem__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__rd_addr,4,0);
    //char	__VpadToAlign29[3];
    // Body
    __Vdlyvset__v__DOT__fifo_mem__v0 = 0U;
    __Vdly__v__DOT__wr_addr = vlTOPp->v__DOT__wr_addr;
    __Vdly__v__DOT__rd_addr = vlTOPp->v__DOT__rd_addr;
    // ALWAYS at fifo.v:38
    if (vlTOPp->v__DOT__w_wr) {
	__Vdlyvval__v__DOT__fifo_mem__v0 = vlTOPp->__Vcellinp__v__i_data;
	__Vdlyvset__v__DOT__fifo_mem__v0 = 1U;
	__Vdlyvdim0__v__DOT__fifo_mem__v0 = (0xfU & (IData)(vlTOPp->v__DOT__wr_addr));
    }
    // ALWAYS at fifo.v:34
    if (vlTOPp->v__DOT__w_wr) {
	__Vdly__v__DOT__wr_addr = (0x1fU & ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__wr_addr)));
    }
    // ALWAYS at fifo.v:46
    if (((IData)(vlTOPp->__Vcellinp__v__i_rd) & (0U 
						 != (IData)(vlTOPp->__Vcellout__v__o_fill)))) {
	__Vdly__v__DOT__rd_addr = (0x1fU & ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__rd_addr)));
    }
    // ALWAYSPOST at fifo.v:40
    if (__Vdlyvset__v__DOT__fifo_mem__v0) {
	vlTOPp->v__DOT__fifo_mem[__Vdlyvdim0__v__DOT__fifo_mem__v0] 
	    = __Vdlyvval__v__DOT__fifo_mem__v0;
    }
    vlTOPp->v__DOT__wr_addr = __Vdly__v__DOT__wr_addr;
    vlTOPp->v__DOT__rd_addr = __Vdly__v__DOT__rd_addr;
}

VL_INLINE_OPT void Vfifo::_combo__TOP__4(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_combo__TOP__4\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(8,vlTOPp->__Vcellinp__v__i_data, vlTOPp->i_data);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__i_rd, vlTOPp->i_rd);
}

void Vfifo::_initial__TOP__6(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_initial__TOP__6\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at fifo.v:33
    vlTOPp->v__DOT__wr_addr = 0U;
    // INITIAL at fifo.v:45
    vlTOPp->v__DOT__rd_addr = 0U;
}

VL_INLINE_OPT void Vfifo::_sequent__TOP__7(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_sequent__TOP__7\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at fifo.v:50
    vlTOPp->__Vcellout__v__o_data = vlTOPp->v__DOT__fifo_mem
	[(0xfU & (IData)(vlTOPp->v__DOT__rd_addr))];
    // ALWAYS at fifo.v:58
    vlTOPp->__Vcellout__v__o_fill = (0x1fU & ((IData)(vlTOPp->v__DOT__wr_addr) 
					      - (IData)(vlTOPp->v__DOT__rd_addr)));
}

void Vfifo::_settle__TOP__8(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_settle__TOP__8\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at fifo.v:50
    vlTOPp->__Vcellout__v__o_data = vlTOPp->v__DOT__fifo_mem
	[(0xfU & (IData)(vlTOPp->v__DOT__rd_addr))];
    // ALWAYS at fifo.v:58
    vlTOPp->__Vcellout__v__o_fill = (0x1fU & ((IData)(vlTOPp->v__DOT__wr_addr) 
					      - (IData)(vlTOPp->v__DOT__rd_addr)));
    VL_ASSIGN_SII(8,vlTOPp->o_data, vlTOPp->__Vcellout__v__o_data);
    VL_ASSIGN_SII(1,vlTOPp->o_empty, (0U == (IData)(vlTOPp->__Vcellout__v__o_fill)));
    VL_ASSIGN_SII(5,vlTOPp->o_fill, vlTOPp->__Vcellout__v__o_fill);
    VL_ASSIGN_SII(1,vlTOPp->o_full, (0x10U == (IData)(vlTOPp->__Vcellout__v__o_fill)));
    vlTOPp->v__DOT__w_wr = ((IData)(vlTOPp->__Vcellinp__v__i_wr) 
			    & (0x10U != (IData)(vlTOPp->__Vcellout__v__o_fill)));
}

VL_INLINE_OPT void Vfifo::_sequent__TOP__9(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_sequent__TOP__9\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_SII(8,vlTOPp->o_data, vlTOPp->__Vcellout__v__o_data);
    VL_ASSIGN_SII(1,vlTOPp->o_empty, (0U == (IData)(vlTOPp->__Vcellout__v__o_fill)));
    VL_ASSIGN_SII(5,vlTOPp->o_fill, vlTOPp->__Vcellout__v__o_fill);
    VL_ASSIGN_SII(1,vlTOPp->o_full, (0x10U == (IData)(vlTOPp->__Vcellout__v__o_fill)));
}

VL_INLINE_OPT void Vfifo::_combo__TOP__10(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_combo__TOP__10\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__w_wr = ((IData)(vlTOPp->__Vcellinp__v__i_wr) 
			    & (0x10U != (IData)(vlTOPp->__Vcellout__v__o_fill)));
}

void Vfifo::_eval(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_eval\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->__Vcellinp__v__i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP____Vcellinp__v__i_clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    if (((IData)(vlTOPp->__Vcellinp__v__i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP____Vcellinp__v__i_clk)))) {
	vlTOPp->_sequent__TOP__7(vlSymsp);
	vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    vlTOPp->_combo__TOP__10(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP____Vcellinp__v__i_clk = vlTOPp->__Vcellinp__v__i_clk;
}

void Vfifo::_eval_initial(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_eval_initial\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__6(vlSymsp);
}

void Vfifo::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::final\n"); );
    // Variables
    Vfifo__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfifo::_eval_settle(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_eval_settle\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->_settle__TOP__8(vlSymsp);
}

VL_INLINE_OPT QData Vfifo::_change_request(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vfifo::_change_request\n"); );
    Vfifo* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
