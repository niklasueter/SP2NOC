// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter.h for the primary calling header

#include "Vcounter.h"          // For This
#include "Vcounter__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_SC_CTOR_IMP(Vcounter)
#if (SYSTEMC_VERSION>20011000)
    : out("out"), enable("enable"), clk("clk"), reset("reset")
#endif
 {
    Vcounter__Syms* __restrict vlSymsp = __VlSymsp = new Vcounter__Syms(this, name());
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << enable;
    sensitive << clk;
    sensitive << reset;
    
    // Reset internal values
    
    // Reset structure values
    __Vcellinp__v__reset = VL_RAND_RESET_I(1);
    __Vcellinp__v__clk = VL_RAND_RESET_I(1);
    __Vcellinp__v__enable = VL_RAND_RESET_I(1);
	 __Vcellout__v__out = VL_RAND_RESET_I(4);
    __Vclklast__TOP____Vcellinp__v__clk = VL_RAND_RESET_I(1);
}

void Vcounter::__Vconfigure(Vcounter__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcounter::~Vcounter() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vcounter::eval() {
    Vcounter__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vcounter::eval\n"); );
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

void Vcounter::_eval_initial_loop(Vcounter__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vcounter::_combo__TOP__1(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_combo__TOP__1\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__clk, vlTOPp->clk);
}

VL_INLINE_OPT void Vcounter::_sequent__TOP__3(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_sequent__TOP__3\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
	// Variables
	VL_SIG8(__Vdly____Vcellout__v__out, 3, 0);
	//char	__VpadToAlign25[3];
    // Body
	__Vdly____Vcellout__v__out = vlTOPp->__Vcellout__v__out;
    // ALWAYS at counter.v:9
    if (vlTOPp->__Vcellinp__v__reset) {
		__Vdly____Vcellout__v__out = 0U;
    } else {
	if (vlTOPp->__Vcellinp__v__enable) {
		__Vdly____Vcellout__v__out = (0xfU & ((IData) (1U)
											  + (IData) (vlTOPp->__Vcellout__v__out)));
	}
    }
	vlTOPp->__Vcellout__v__out = __Vdly____Vcellout__v__out;
	VL_ASSIGN_SII(4, vlTOPp->out, vlTOPp->__Vcellout__v__out);
}

VL_INLINE_OPT void Vcounter::_combo__TOP__4(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_combo__TOP__4\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__reset, vlTOPp->reset);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__enable, vlTOPp->enable);
}

void Vcounter::_settle__TOP__5(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_settle__TOP__5\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__reset, vlTOPp->reset);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__v__enable, vlTOPp->enable);
	VL_ASSIGN_SII(4, vlTOPp->out, vlTOPp->__Vcellout__v__out);
}

void Vcounter::_eval(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_eval\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->__Vcellinp__v__clk) & (~ (IData)(vlTOPp->__Vclklast__TOP____Vcellinp__v__clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP____Vcellinp__v__clk = vlTOPp->__Vcellinp__v__clk;
}

void Vcounter::_eval_initial(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_eval_initial\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcounter::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::final\n"); );
    // Variables
    Vcounter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcounter::_eval_settle(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_eval_settle\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData Vcounter::_change_request(Vcounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcounter::_change_request\n"); );
    Vcounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
