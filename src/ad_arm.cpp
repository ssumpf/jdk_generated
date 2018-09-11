#line 1 "ad_arm.cpp"
//
// Copyright (c) 2008, 2013, Oracle and/or its affiliates. All rights reserved.
// DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
//
// This code is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License version 2 only, as
// published by the Free Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// version 2 for more details (a copy is included in the LICENSE file that
// accompanied this code).
//
// You should have received a copy of the GNU General Public License version
// 2 along with this work; if not, write to the Free Software Foundation,
// Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
// or visit www.oracle.com if you need additional information or have any
// questions.
//

// Machine Generated File.  Do Not Edit!

#include "precompiled.hpp"
#include "adfiles/adGlobals_arm.hpp"
#include "adfiles/ad_arm.hpp"
#include "memory/allocation.inline.hpp"
#include "asm/macroAssembler.inline.hpp"
#include "code/compiledIC.hpp"
#include "code/nativeInst.hpp"
#include "code/vmreg.inline.hpp"
#include "gc/shared/collectedHeap.inline.hpp"
#include "oops/compiledICHolder.hpp"
#include "oops/markOop.hpp"
#include "oops/method.hpp"
#include "oops/oop.inline.hpp"
#include "opto/cfgnode.hpp"
#include "opto/intrinsicnode.hpp"
#include "opto/locknode.hpp"
#include "opto/opcodes.hpp"
#include "opto/regalloc.hpp"
#include "opto/regmask.hpp"
#include "opto/runtime.hpp"
#include "runtime/biasedLocking.hpp"
#include "runtime/sharedRuntime.hpp"
#include "runtime/stubRoutines.hpp"
#include "utilities/growableArray.hpp"

//SourceForm

#line 397 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm_32.ad"


// Given a register encoding, produce a Integer Register object
static Register reg_to_register_object(int register_encoding) {
  assert(R0->encoding() == R_R0_enc && R15->encoding() == R_R15_enc, "right coding");
  return as_Register(register_encoding);
}

// Given a register encoding, produce a single-precision Float Register object
static FloatRegister reg_to_FloatRegister_object(int register_encoding) {
  assert(S0->encoding() == R_S0_enc && S31->encoding() == R_S31_enc, "right coding");
  return as_FloatRegister(register_encoding);
}

void Compile::pd_compiler2_init() {
  // Umimplemented
}

// Location of compiled Java return values.  Same as C
OptoRegPair c2::return_value(int ideal_reg) {
  assert( ideal_reg >= Op_RegI && ideal_reg <= Op_RegL, "only return normal values" );
#ifndef __ABI_HARD__
  static int lo[Op_RegL+1] = { 0, 0, OptoReg::Bad, R_R0_num,     R_R0_num,     R_R0_num,     R_R0_num, R_R0_num };
  static int hi[Op_RegL+1] = { 0, 0, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, R_R1_num, R_R1_num };
#else
  static int lo[Op_RegL+1] = { 0, 0, OptoReg::Bad, R_R0_num,     R_R0_num,     R_hf_ret_lo_num,  R_hf_ret_lo_num, R_R0_num };
  static int hi[Op_RegL+1] = { 0, 0, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad,     R_hf_ret_hi_num, R_R1_num };
#endif
  return OptoRegPair( hi[ideal_reg], lo[ideal_reg]);
}

// !!!!! Special hack to get all type of calls to specify the byte offset
//       from the start of the call to the point where the return address
//       will point.

int MachCallStaticJavaNode::ret_addr_offset() {
  bool far = (_method == NULL) ? maybe_far_call(this) : !cache_reachable();
  return ((far ? 3 : 1) + (_method_handle_invoke ? 1 : 0)) *
    NativeInstruction::instruction_size;
}

int MachCallDynamicJavaNode::ret_addr_offset() {
  bool far = !cache_reachable();
  // mov_oop is always 2 words
  return (2 + (far ? 3 : 1)) * NativeInstruction::instruction_size; 
}

int MachCallRuntimeNode::ret_addr_offset() {
  // bl or movw; movt; blx
  bool far = maybe_far_call(this);
  return (far ? 3 : 1) * NativeInstruction::instruction_size;
}

#line 108 "ad_arm.cpp"


//SourceForm

#line 131 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#define __ _masm.

static FloatRegister reg_to_FloatRegister_object(int register_encoding);
static Register reg_to_register_object(int register_encoding);


// ****************************************************************************

// REQUIRED FUNCTIONALITY

// Indicate if the safepoint node needs the polling page as an input.
// Since ARM does not have absolute addressing, it does.
bool SafePointNode::needs_polling_address_input() {
  return true;
}

// emit an interrupt that is caught by the debugger (for debugging compiler)
void emit_break(CodeBuffer &cbuf) {
  MacroAssembler _masm(&cbuf);
  __ breakpoint();
}

#ifndef PRODUCT
void MachBreakpointNode::format( PhaseRegAlloc *, outputStream *st ) const {
  st->print("TA");
}
#endif

void MachBreakpointNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  emit_break(cbuf);
}

uint MachBreakpointNode::size(PhaseRegAlloc *ra_) const {
  return MachNode::size(ra_);
}


void emit_nop(CodeBuffer &cbuf) {
  MacroAssembler _masm(&cbuf);
  __ nop();
}


void emit_call_reloc(CodeBuffer &cbuf, const MachCallNode *n, MachOper *m, RelocationHolder const& rspec) {
  int ret_addr_offset0 = n->as_MachCall()->ret_addr_offset();
  int call_site_offset = cbuf.insts()->mark_off();
  MacroAssembler _masm(&cbuf);
  __ set_inst_mark(); // needed in emit_to_interp_stub() to locate the call
  address target = (address)m->method();
  assert(n->as_MachCall()->entry_point() == target, "sanity");
  assert(maybe_far_call(n) == !__ reachable_from_cache(target), "sanity");
  assert(cache_reachable() == __ cache_fully_reachable(), "sanity");

  assert(target != NULL, "need real address");

  int ret_addr_offset = -1;
  if (rspec.type() == relocInfo::runtime_call_type) {
    __ call(target, rspec);
    ret_addr_offset = __ offset();
  } else {
    // scratches Rtemp
    ret_addr_offset = __ patchable_call(target, rspec, true);
  }
  assert(ret_addr_offset - call_site_offset == ret_addr_offset0, "fix ret_addr_offset()");
}

//=============================================================================
// REQUIRED FUNCTIONALITY for encoding
void emit_lo(CodeBuffer &cbuf, int val) {  }
void emit_hi(CodeBuffer &cbuf, int val) {  }


//=============================================================================
const RegMask& MachConstantBaseNode::_out_RegMask = PTR_REG_mask();

int Compile::ConstantTable::calculate_table_base_offset() const {
#ifdef AARCH64
  return 0;
#else
  int offset = -(size() / 2);
  // flds, fldd: 8-bit  offset multiplied by 4: +/- 1024
  // ldr, ldrb : 12-bit offset:                 +/- 4096
  if (!Assembler::is_simm10(offset)) {
    offset = Assembler::min_simm10();
  }
  return offset;
#endif
}

bool MachConstantBaseNode::requires_postalloc_expand() const { return false; }
void MachConstantBaseNode::postalloc_expand(GrowableArray <Node *> *nodes, PhaseRegAlloc *ra_) {
  ShouldNotReachHere();
}

void MachConstantBaseNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  Compile* C = ra_->C;
  Compile::ConstantTable& constant_table = C->constant_table();
  MacroAssembler _masm(&cbuf);

  Register r = as_Register(ra_->get_encode(this));
  CodeSection* consts_section = __ code()->consts();
  int consts_size = consts_section->align_at_start(consts_section->size());
  assert(constant_table.size() == consts_size, "must be: %d == %d", constant_table.size(), consts_size);

  // Materialize the constant table base.
  address baseaddr = consts_section->start() + -(constant_table.table_base_offset());
  RelocationHolder rspec = internal_word_Relocation::spec(baseaddr);
  __ mov_address(r, baseaddr, rspec);
}

uint MachConstantBaseNode::size(PhaseRegAlloc*) const {
#ifdef AARCH64
  return 5 * Assembler::InstructionSize;
#else
  return 8;
#endif
}

#ifndef PRODUCT
void MachConstantBaseNode::format(PhaseRegAlloc* ra_, outputStream* st) const {
  char reg[128];
  ra_->dump_register(this, reg);
  st->print("MOV_SLOW    &constanttable,%s\t! constant table base", reg);
}
#endif

#ifndef PRODUCT
void MachPrologNode::format( PhaseRegAlloc *ra_, outputStream *st ) const {
  Compile* C = ra_->C;

  for (int i = 0; i < OptoPrologueNops; i++) {
    st->print_cr("NOP"); st->print("\t");
  }
#ifdef AARCH64
  if (OptoPrologueNops <= 0) {
    st->print_cr("NOP\t! required for safe patching");
    st->print("\t");
  }
#endif

  size_t framesize = C->frame_size_in_bytes();
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  int bangsize = C->bang_size_in_bytes();
  // Remove two words for return addr and rbp,
  framesize -= 2*wordSize;
  bangsize -= 2*wordSize;

  // Calls to C2R adapters often do not accept exceptional returns.
  // We require that their callers must bang for them.  But be careful, because
  // some VM calls (such as call site linkage) can use several kilobytes of
  // stack.  But the stack safety zone should account for that.
  // See bugs 4446381, 4468289, 4497237.
  if (C->need_stack_bang(bangsize)) {
    st->print_cr("! stack bang (%d bytes)", bangsize); st->print("\t");
  }
  st->print_cr("PUSH   R_FP|R_LR_LR"); st->print("\t");
  if (framesize != 0) {
    st->print   ("SUB    R_SP, R_SP, " SIZE_FORMAT,framesize);
  }
}
#endif

void MachPrologNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  Compile* C = ra_->C;
  MacroAssembler _masm(&cbuf);

  for (int i = 0; i < OptoPrologueNops; i++) {
    __ nop();
  }
#ifdef AARCH64
  if (OptoPrologueNops <= 0) {
    __ nop(); // required for safe patching by patch_verified_entry()
  }
#endif

  size_t framesize = C->frame_size_in_bytes();
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  int bangsize = C->bang_size_in_bytes();
  // Remove two words for return addr and fp,
  framesize -= 2*wordSize;
  bangsize -= 2*wordSize;

  // Calls to C2R adapters often do not accept exceptional returns.
  // We require that their callers must bang for them.  But be careful, because
  // some VM calls (such as call site linkage) can use several kilobytes of
  // stack.  But the stack safety zone should account for that.
  // See bugs 4446381, 4468289, 4497237.
  if (C->need_stack_bang(bangsize)) {
    __ arm_stack_overflow_check(bangsize, Rtemp);
  }

  __ raw_push(FP, LR);
  if (framesize != 0) {
    __ sub_slow(SP, SP, framesize);
  }

  // offset from scratch buffer is not valid
  if (strcmp(cbuf.name(), "Compile::Fill_buffer") == 0) {
    C->set_frame_complete( __ offset() );
  }

  if (C->has_mach_constant_base_node()) {
    // NOTE: We set the table base offset here because users might be
    // emitted before MachConstantBaseNode.
    Compile::ConstantTable& constant_table = C->constant_table();
    constant_table.set_table_base_offset(constant_table.calculate_table_base_offset());
  }
}

uint MachPrologNode::size(PhaseRegAlloc *ra_) const {
  return MachNode::size(ra_);
}

int MachPrologNode::reloc() const {
  return 10; // a large enough number
}

//=============================================================================
#ifndef PRODUCT
void MachEpilogNode::format( PhaseRegAlloc *ra_, outputStream *st ) const {
  Compile* C = ra_->C;

  size_t framesize = C->frame_size_in_bytes();
  framesize -= 2*wordSize;

  if (framesize != 0) {
    st->print("ADD    R_SP, R_SP, " SIZE_FORMAT "\n\t",framesize);
  }
  st->print("POP    R_FP|R_LR_LR");

  if (do_polling() && ra_->C->is_method_compilation()) {
    st->print("\n\t");
#ifdef AARCH64
    if (MacroAssembler::page_reachable_from_cache(os::get_polling_page())) {
      st->print("ADRP     Rtemp, #PollAddr\t! Load Polling address\n\t");
      st->print("LDR      ZR,[Rtemp + #PollAddr & 0xfff]\t!Poll for Safepointing");
    } else {
      st->print("mov_slow Rtemp, #PollAddr\t! Load Polling address\n\t");
      st->print("LDR      ZR,[Rtemp]\t!Poll for Safepointing");
    }
#else
    st->print("MOV    Rtemp, #PollAddr\t! Load Polling address\n\t");
    st->print("LDR    Rtemp,[Rtemp]\t!Poll for Safepointing");
#endif
  }
}
#endif

void MachEpilogNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  MacroAssembler _masm(&cbuf);
  Compile* C = ra_->C;

  size_t framesize = C->frame_size_in_bytes();
  framesize -= 2*wordSize;
  if (framesize != 0) {
    __ add_slow(SP, SP, framesize);
  }
  __ raw_pop(FP, LR);

  // If this does safepoint polling, then do it here
  if (do_polling() && ra_->C->is_method_compilation()) {
#ifdef AARCH64
    if (false && MacroAssembler::page_reachable_from_cache(os::get_polling_page())) {
/* FIXME: TODO
      __ relocate(relocInfo::xxx);
      __ adrp(Rtemp, (intptr_t)os::get_polling_page());
      __ relocate(relocInfo::poll_return_type);
      int offset = os::get_polling_page() & 0xfff;
      __ ldr(ZR, Address(Rtemp + offset));
*/
    } else {
      __ mov_address(Rtemp, (address)os::get_polling_page(), symbolic_Relocation::polling_page_reference);
      __ relocate(relocInfo::poll_return_type);
      __ ldr(ZR, Address(Rtemp));
    }
#else
    // mov_slow here is usually one or two instruction
    __ mov_address(Rtemp, (address)os::get_polling_page(), symbolic_Relocation::polling_page_reference);
    __ relocate(relocInfo::poll_return_type);
    __ ldr(Rtemp, Address(Rtemp));
#endif
  }
}

uint MachEpilogNode::size(PhaseRegAlloc *ra_) const {
#ifdef AARCH64
  // allow for added alignment nop from mov_address bind_literal
  return MachNode::size(ra_) + 1 * Assembler::InstructionSize;
#else
  return MachNode::size(ra_);
#endif
}

int MachEpilogNode::reloc() const {
  return 16; // a large enough number
}

const Pipeline * MachEpilogNode::pipeline() const {
  return MachNode::pipeline_class();
}

int MachEpilogNode::safepoint_offset() const {
  assert( do_polling(), "no return for this epilog node");
  //  return MacroAssembler::size_of_sethi(os::get_polling_page());
  Unimplemented();
  return 0;
}

//=============================================================================

// Figure out which register class each belongs in: rc_int, rc_float, rc_stack
enum RC { rc_bad, rc_int, rc_float, rc_stack };
static enum RC rc_class( OptoReg::Name reg ) {
  if (!OptoReg::is_valid(reg)) return rc_bad;
  if (OptoReg::is_stack(reg)) return rc_stack;
  VMReg r = OptoReg::as_VMReg(reg);
  if (r->is_Register()) return rc_int;
  assert(r->is_FloatRegister(), "must be");
  return rc_float;
}

static inline bool is_iRegLd_memhd(OptoReg::Name src_first, OptoReg::Name src_second, int offset) {
#ifdef AARCH64
  return is_memoryHD(offset);
#else
  int rlo = Matcher::_regEncode[src_first];
  int rhi = Matcher::_regEncode[src_second];
  if (!((rlo&1)==0 && (rlo+1 == rhi))) {
    tty->print_cr("CAUGHT BAD LDRD/STRD");
  }
  return (rlo&1)==0 && (rlo+1 == rhi) && is_memoryHD(offset);
#endif
}

uint MachSpillCopyNode::implementation( CodeBuffer *cbuf,
                                        PhaseRegAlloc *ra_,
                                        bool do_size,
                                        outputStream* st ) const {
  // Get registers to move
  OptoReg::Name src_second = ra_->get_reg_second(in(1));
  OptoReg::Name src_first = ra_->get_reg_first(in(1));
  OptoReg::Name dst_second = ra_->get_reg_second(this );
  OptoReg::Name dst_first = ra_->get_reg_first(this );

  enum RC src_second_rc = rc_class(src_second);
  enum RC src_first_rc = rc_class(src_first);
  enum RC dst_second_rc = rc_class(dst_second);
  enum RC dst_first_rc = rc_class(dst_first);

  assert( OptoReg::is_valid(src_first) && OptoReg::is_valid(dst_first), "must move at least 1 register" );

  // Generate spill code!
  int size = 0;

  if (src_first == dst_first && src_second == dst_second)
    return size;            // Self copy, no move

#ifdef TODO
  if (bottom_type()->isa_vect() != NULL) {
  }
#endif

  // Shared code does not expect instruction set capability based bailouts here.
  // Handle offset unreachable bailout with minimal change in shared code.
  // Bailout only for real instruction emit.
  // This requires a single comment change in shared code. ( see output.cpp "Normal" instruction case )

  MacroAssembler _masm(cbuf);

  // --------------------------------------
  // Check for mem-mem move.  Load into unused float registers and fall into
  // the float-store case.
  if (src_first_rc == rc_stack && dst_first_rc == rc_stack) {
    int offset = ra_->reg2offset(src_first);
    if (cbuf && !is_memoryfp(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      if (src_second_rc != rc_bad) {
        assert((src_first&1)==0 && src_first+1 == src_second, "pair of registers must be aligned/contiguous");
        src_first     = OptoReg::Name(R_mem_copy_lo_num);
        src_second    = OptoReg::Name(R_mem_copy_hi_num);
        src_first_rc  = rc_float;
        src_second_rc = rc_float;
        if (cbuf) {
          __ ldr_double(Rmemcopy, Address(SP, offset));
        } else if (!do_size) {
          st->print(LDR_DOUBLE "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_first),offset);
        }
      } else {
        src_first     = OptoReg::Name(R_mem_copy_lo_num);
        src_first_rc  = rc_float;
        if (cbuf) {
          __ ldr_float(Rmemcopy, Address(SP, offset));
        } else if (!do_size) {
          st->print(LDR_FLOAT "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_first),offset);
        }
      }
      size += 4;
    }
  }

  if (src_second_rc == rc_stack && dst_second_rc == rc_stack) {
    Unimplemented();
  }

  // --------------------------------------
  // Check for integer reg-reg copy
  if (src_first_rc == rc_int && dst_first_rc == rc_int) {
    // Else normal reg-reg copy
    assert( src_second != dst_first, "smashed second before evacuating it" );
    if (cbuf) {
      __ mov(reg_to_register_object(Matcher::_regEncode[dst_first]), reg_to_register_object(Matcher::_regEncode[src_first]));
#ifndef PRODUCT
    } else if (!do_size) {
      st->print("MOV    R_%s, R_%s\t# spill",
                Matcher::regName[dst_first],
                Matcher::regName[src_first]);
#endif
    }
#ifdef AARCH64
    if (src_first+1 == src_second && dst_first+1 == dst_second) {
      return size + 4;
    }
#endif
    size += 4;
  }

  // Check for integer store
  if (src_first_rc == rc_int && dst_first_rc == rc_stack) {
    int offset = ra_->reg2offset(dst_first);
    if (cbuf && !is_memoryI(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      if (src_second_rc != rc_bad && is_iRegLd_memhd(src_first, src_second, offset)) {
        assert((src_first&1)==0 && src_first+1 == src_second, "pair of registers must be aligned/contiguous");
        if (cbuf) {
          __ str_64(reg_to_register_object(Matcher::_regEncode[src_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(STR_64 "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_first), offset);
#endif
        }
        return size + 4;
      } else {
        if (cbuf) {
          __ str_32(reg_to_register_object(Matcher::_regEncode[src_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(STR_32 "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_first), offset);
#endif
        }
      }
    }
    size += 4;
  }

  // Check for integer load
  if (dst_first_rc == rc_int && src_first_rc == rc_stack) {
    int offset = ra_->reg2offset(src_first);
    if (cbuf && !is_memoryI(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      if (src_second_rc != rc_bad && is_iRegLd_memhd(dst_first, dst_second, offset)) {
        assert((src_first&1)==0 && src_first+1 == src_second, "pair of registers must be aligned/contiguous");
        if (cbuf) {
          __ ldr_64(reg_to_register_object(Matcher::_regEncode[dst_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(LDR_64 "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(dst_first), offset);
#endif
        }
        return size + 4;
      } else {
        if (cbuf) {
          __ ldr_32(reg_to_register_object(Matcher::_regEncode[dst_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(LDR_32 "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(dst_first), offset);
#endif
        }
      }
    }
    size += 4;
  }

  // Check for float reg-reg copy
  if (src_first_rc == rc_float && dst_first_rc == rc_float) {
    if (src_second_rc != rc_bad) {
      assert((src_first&1)==0 && src_first+1 == src_second && (dst_first&1)==0 && dst_first+1 == dst_second, "pairs of registers must be aligned/contiguous");
      if (cbuf) {
      __ mov_double(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), reg_to_FloatRegister_object(Matcher::_regEncode[src_first]));
#ifndef PRODUCT
      } else if (!do_size) {
        st->print(MOV_DOUBLE "    R_%s, R_%s\t# spill",
                  Matcher::regName[dst_first],
                  Matcher::regName[src_first]);
#endif
      }
      return 4;
    }
    if (cbuf) {
      __ mov_float(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), reg_to_FloatRegister_object(Matcher::_regEncode[src_first]));
#ifndef PRODUCT
    } else if (!do_size) {
      st->print(MOV_FLOAT "    R_%s, R_%s\t# spill",
                Matcher::regName[dst_first],
                Matcher::regName[src_first]);
#endif
    }
    size = 4;
  }

  // Check for float store
  if (src_first_rc == rc_float && dst_first_rc == rc_stack) {
    int offset = ra_->reg2offset(dst_first);
    if (cbuf && !is_memoryfp(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      // Further check for aligned-adjacent pair, so we can use a double store
      if (src_second_rc != rc_bad) {
        assert((src_first&1)==0 && src_first+1 == src_second && (dst_first&1)==0 && dst_first+1 == dst_second, "pairs of registers and stack slots must be aligned/contiguous");
        if (cbuf) {
          __ str_double(reg_to_FloatRegister_object(Matcher::_regEncode[src_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(STR_DOUBLE "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_first),offset);
#endif
        }
        return size + 4;
      } else {
        if (cbuf) {
          __ str_float(reg_to_FloatRegister_object(Matcher::_regEncode[src_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(STR_FLOAT "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_first),offset);
#endif
        }
      }
    }
    size += 4;
  }

  // Check for float load
  if (dst_first_rc == rc_float && src_first_rc == rc_stack) {
    int offset = ra_->reg2offset(src_first);
    if (cbuf && !is_memoryfp(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      // Further check for aligned-adjacent pair, so we can use a double store
      if (src_second_rc != rc_bad) {
        assert((src_first&1)==0 && src_first+1 == src_second && (dst_first&1)==0 && dst_first+1 == dst_second, "pairs of registers and stack slots must be aligned/contiguous");
        if (cbuf) {
          __ ldr_double(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(LDR_DOUBLE "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(dst_first),offset);
#endif
        }
        return size + 4;
      } else {
        if (cbuf) {
          __ ldr_float(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), Address(SP, offset));
#ifndef PRODUCT
        } else if (!do_size) {
          if (size != 0) st->print("\n\t");
          st->print(LDR_FLOAT "   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(dst_first),offset);
#endif
        }
      }
    }
    size += 4;
  }

  // check for int reg -> float reg move
  if (src_first_rc == rc_int && dst_first_rc == rc_float) {
    // Further check for aligned-adjacent pair, so we can use a single instruction
    if (src_second_rc != rc_bad) {
      assert((dst_first&1)==0 && dst_first+1 == dst_second, "pairs of registers must be aligned/contiguous");
      assert((src_first&1)==0 && src_first+1 == src_second, "pairs of registers must be aligned/contiguous");
      assert(src_second_rc == rc_int && dst_second_rc == rc_float, "unsupported");
      if (cbuf) {
#ifdef AARCH64
        __ fmov_dx(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), reg_to_register_object(Matcher::_regEncode[src_first]));
#else
        __ fmdrr(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), reg_to_register_object(Matcher::_regEncode[src_first]), reg_to_register_object(Matcher::_regEncode[src_second]));
#endif
#ifndef PRODUCT
      } else if (!do_size) {
        if (size != 0) st->print("\n\t");
#ifdef AARCH64
        st->print("FMOV_DX   R_%s, R_%s\t! spill",OptoReg::regname(dst_first), OptoReg::regname(src_first));
#else
        st->print("FMDRR   R_%s, R_%s, R_%s\t! spill",OptoReg::regname(dst_first), OptoReg::regname(src_first), OptoReg::regname(src_second));
#endif
#endif
      }
      return size + 4;
    } else {
      if (cbuf) {
        __ fmsr(reg_to_FloatRegister_object(Matcher::_regEncode[dst_first]), reg_to_register_object(Matcher::_regEncode[src_first]));
#ifndef PRODUCT
      } else if (!do_size) {
        if (size != 0) st->print("\n\t");
        st->print(FMSR "   R_%s, R_%s\t! spill",OptoReg::regname(dst_first), OptoReg::regname(src_first));
#endif
      }
      size += 4;
    }
  }

  // check for float reg -> int reg move
  if (src_first_rc == rc_float && dst_first_rc == rc_int) {
    // Further check for aligned-adjacent pair, so we can use a single instruction
    if (src_second_rc != rc_bad) {
      assert((src_first&1)==0 && src_first+1 == src_second, "pairs of registers must be aligned/contiguous");
      assert((dst_first&1)==0 && dst_first+1 == dst_second, "pairs of registers must be aligned/contiguous");
      assert(src_second_rc == rc_float && dst_second_rc == rc_int, "unsupported");
      if (cbuf) {
#ifdef AARCH64
        __ fmov_xd(reg_to_register_object(Matcher::_regEncode[dst_first]), reg_to_FloatRegister_object(Matcher::_regEncode[src_first]));
#else
        __ fmrrd(reg_to_register_object(Matcher::_regEncode[dst_first]), reg_to_register_object(Matcher::_regEncode[dst_second]), reg_to_FloatRegister_object(Matcher::_regEncode[src_first]));
#endif
#ifndef PRODUCT
      } else if (!do_size) {
        if (size != 0) st->print("\n\t");
#ifdef AARCH64
        st->print("FMOV_XD R_%s, R_%s\t! spill",OptoReg::regname(dst_first), OptoReg::regname(src_first));
#else
        st->print("FMRRD   R_%s, R_%s, R_%s\t! spill",OptoReg::regname(dst_first), OptoReg::regname(dst_second), OptoReg::regname(src_first));
#endif
#endif
      }
      return size + 4;
    } else {
      if (cbuf) {
        __ fmrs(reg_to_register_object(Matcher::_regEncode[dst_first]), reg_to_FloatRegister_object(Matcher::_regEncode[src_first]));
#ifndef PRODUCT
      } else if (!do_size) {
        if (size != 0) st->print("\n\t");
        st->print(FMRS "   R_%s, R_%s\t! spill",OptoReg::regname(dst_first), OptoReg::regname(src_first));
#endif
      }
      size += 4;
    }
  }

  // --------------------------------------------------------------------
  // Check for hi bits still needing moving.  Only happens for misaligned
  // arguments to native calls.
  if (src_second == dst_second)
    return size;               // Self copy; no move
  assert( src_second_rc != rc_bad && dst_second_rc != rc_bad, "src_second & dst_second cannot be Bad" );

#ifndef AARCH64
  // Check for integer reg-reg copy.  Hi bits are stuck up in the top
  // 32-bits of a 64-bit register, but are needed in low bits of another
  // register (else it's a hi-bits-to-hi-bits copy which should have
  // happened already as part of a 64-bit move)
  if (src_second_rc == rc_int && dst_second_rc == rc_int) {
    if (cbuf) {
      __ mov(reg_to_register_object(Matcher::_regEncode[dst_second]), reg_to_register_object(Matcher::_regEncode[src_second]));
#ifndef PRODUCT
    } else if (!do_size) {
      if (size != 0) st->print("\n\t");
      st->print("MOV    R_%s, R_%s\t# spill high",
                Matcher::regName[dst_second],
                Matcher::regName[src_second]);
#endif
    }
    return size+4;
  }

  // Check for high word integer store
  if (src_second_rc == rc_int && dst_second_rc == rc_stack) {
    int offset = ra_->reg2offset(dst_second);

    if (cbuf && !is_memoryP(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      if (cbuf) {
        __ str(reg_to_register_object(Matcher::_regEncode[src_second]), Address(SP, offset));
#ifndef PRODUCT
      } else if (!do_size) {
        if (size != 0) st->print("\n\t");
        st->print("STR   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(src_second), offset);
#endif
      }
    }
    return size + 4;
  }

  // Check for high word integer load
  if (dst_second_rc == rc_int && src_second_rc == rc_stack) {
    int offset = ra_->reg2offset(src_second);
    if (cbuf && !is_memoryP(offset)) {
      ra_->C->record_method_not_compilable("unable to handle large constant offsets");
      return 0;
    } else {
      if (cbuf) {
        __ ldr(reg_to_register_object(Matcher::_regEncode[dst_second]), Address(SP, offset));
#ifndef PRODUCT
      } else if (!do_size) {
        if (size != 0) st->print("\n\t");
        st->print("LDR   R_%s,[R_SP + #%d]\t! spill",OptoReg::regname(dst_second), offset);
#endif
      }
    }
    return size + 4;
  }
#endif

  Unimplemented();
  return 0; // Mute compiler
}

#ifndef PRODUCT
void MachSpillCopyNode::format( PhaseRegAlloc *ra_, outputStream *st ) const {
  implementation( NULL, ra_, false, st );
}
#endif

void MachSpillCopyNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  implementation( &cbuf, ra_, false, NULL );
}

uint MachSpillCopyNode::size(PhaseRegAlloc *ra_) const {
  return implementation( NULL, ra_, true, NULL );
}

//=============================================================================
#ifndef PRODUCT
void MachNopNode::format( PhaseRegAlloc *, outputStream *st ) const {
  st->print("NOP \t# %d bytes pad for loops and calls", 4 * _count);
}
#endif

void MachNopNode::emit(CodeBuffer &cbuf, PhaseRegAlloc * ) const {
  MacroAssembler _masm(&cbuf);
  for(int i = 0; i < _count; i += 1) {
    __ nop();
  }
}

uint MachNopNode::size(PhaseRegAlloc *ra_) const {
  return 4 * _count;
}


//=============================================================================
#ifndef PRODUCT
void BoxLockNode::format( PhaseRegAlloc *ra_, outputStream *st ) const {
  int offset = ra_->reg2offset(in_RegMask(0).find_first_elem());
  int reg = ra_->get_reg_first(this);
  st->print("ADD    %s,R_SP+#%d",Matcher::regName[reg], offset);
}
#endif

void BoxLockNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  MacroAssembler _masm(&cbuf);
  int offset = ra_->reg2offset(in_RegMask(0).find_first_elem());
  int reg = ra_->get_encode(this);
  Register dst = reg_to_register_object(reg);

  if (is_aimm(offset)) {
    __ add(dst, SP, offset);
  } else {
    __ mov_slow(dst, offset);
#ifdef AARCH64
    __ add(dst, SP, dst, ex_lsl);
#else
    __ add(dst, SP, dst);
#endif
  }
}

uint BoxLockNode::size(PhaseRegAlloc *ra_) const {
  // BoxLockNode is not a MachNode, so we can't just call MachNode::size(ra_)
  assert(ra_ == ra_->C->regalloc(), "sanity");
  return ra_->C->scratch_emit_size(this);
}

//=============================================================================
#ifndef PRODUCT
#ifdef AARCH64
#define R_RTEMP "R_R16"
#else
#define R_RTEMP "R_R12"
#endif
void MachUEPNode::format( PhaseRegAlloc *ra_, outputStream *st ) const {
  st->print_cr("\nUEP:");
  if (UseCompressedClassPointers) {
    st->print_cr("\tLDR_w " R_RTEMP ",[R_R0 + oopDesc::klass_offset_in_bytes]\t! Inline cache check");
    st->print_cr("\tdecode_klass " R_RTEMP);
  } else {
    st->print_cr("\tLDR   " R_RTEMP ",[R_R0 + oopDesc::klass_offset_in_bytes]\t! Inline cache check");
  }
  st->print_cr("\tCMP   " R_RTEMP ",R_R8" );
  st->print   ("\tB.NE  SharedRuntime::handle_ic_miss_stub");
}
#endif

void MachUEPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  MacroAssembler _masm(&cbuf);
  Register iCache  = reg_to_register_object(Matcher::inline_cache_reg_encode());
  assert(iCache == Ricklass, "should be");
  Register receiver = R0;

  __ load_klass(Rtemp, receiver);
  __ cmp(Rtemp, iCache);
#ifdef AARCH64
  Label match;
  __ b(match, eq);
  __ jump(SharedRuntime::get_ic_miss_stub(), relocInfo::runtime_call_type, Rtemp);
  __ bind(match);
#else
  __ jump(SharedRuntime::get_ic_miss_stub(), relocInfo::runtime_call_type, noreg, ne);
#endif
}

uint MachUEPNode::size(PhaseRegAlloc *ra_) const {
  return MachNode::size(ra_);
}


//=============================================================================

// Emit exception handler code.
int HandlerImpl::emit_exception_handler(CodeBuffer& cbuf) {
  MacroAssembler _masm(&cbuf);

  address base = __ start_a_stub(size_exception_handler());
  if (base == NULL) {
    ciEnv::current()->record_failure("CodeCache is full");
    return 0;  // CodeBuffer::expand failed
  }

  int offset = __ offset();

  // OK to trash LR, because exception blob will kill it
  __ jump(OptoRuntime::exception_blob()->entry_point(), relocInfo::runtime_call_type, LR_tmp);

  assert(__ offset() - offset <= (int) size_exception_handler(), "overflow");

  __ end_a_stub();

  return offset;
}

int HandlerImpl::emit_deopt_handler(CodeBuffer& cbuf) {
  // Can't use any of the current frame's registers as we may have deopted
  // at a poll and everything can be live.
  MacroAssembler _masm(&cbuf);

  address base = __ start_a_stub(size_deopt_handler());
  if (base == NULL) {
    ciEnv::current()->record_failure("CodeCache is full");
    return 0;  // CodeBuffer::expand failed
  }

  int offset = __ offset();
  address deopt_pc = __ pc();

#ifdef AARCH64
  // See LR saved by caller in sharedRuntime_arm.cpp
  // see also hse1 ws
  // see also LIR_Assembler::emit_deopt_handler

  __ raw_push(LR, LR); // preserve LR in both slots
  __ mov_relative_address(LR, deopt_pc);
  __ str(LR, Address(SP, 1 * wordSize)); // save deopt PC
  // OK to kill LR, because deopt blob will restore it from SP[0]
  __ jump(SharedRuntime::deopt_blob()->unpack(), relocInfo::runtime_call_type, LR_tmp);
#else
  __ sub(SP, SP, wordSize); // make room for saved PC
  __ push(LR); // save LR that may be live when we get here
  __ mov_relative_address(LR, deopt_pc);
  __ str(LR, Address(SP, wordSize)); // save deopt PC
  __ pop(LR); // restore LR
  __ jump(SharedRuntime::deopt_blob()->unpack(), relocInfo::runtime_call_type, noreg);
#endif

  assert(__ offset() - offset <= (int) size_deopt_handler(), "overflow");

  __ end_a_stub();
  return offset;
}

const bool Matcher::match_rule_supported(int opcode) {
  if (!has_match_rule(opcode))
    return false;

  switch (opcode) {
  case Op_PopCountI:
  case Op_PopCountL:
    if (!UsePopCountInstruction)
      return false;
    break;
  case Op_LShiftCntV:
  case Op_RShiftCntV:
  case Op_AddVB:
  case Op_AddVS:
  case Op_AddVI:
  case Op_AddVL:
  case Op_SubVB:
  case Op_SubVS:
  case Op_SubVI:
  case Op_SubVL:
  case Op_MulVS:
  case Op_MulVI:
  case Op_LShiftVB:
  case Op_LShiftVS:
  case Op_LShiftVI:
  case Op_LShiftVL:
  case Op_RShiftVB:
  case Op_RShiftVS:
  case Op_RShiftVI:
  case Op_RShiftVL:
  case Op_URShiftVB:
  case Op_URShiftVS:
  case Op_URShiftVI:
  case Op_URShiftVL:
  case Op_AndV:
  case Op_OrV:
  case Op_XorV:
    return VM_Version::has_simd();
  case Op_LoadVector:
  case Op_StoreVector:
  case Op_AddVF:
  case Op_SubVF:
  case Op_MulVF:
#ifdef AARCH64
    return VM_Version::has_simd();
#else
    return VM_Version::has_vfp() || VM_Version::has_simd();
#endif
  case Op_AddVD:
  case Op_SubVD:
  case Op_MulVD:
  case Op_DivVF:
  case Op_DivVD:
#ifdef AARCH64
    return VM_Version::has_simd();
#else
    return VM_Version::has_vfp();
#endif
  }

  return true;  // Per default match rules are supported.
}

const bool Matcher::match_rule_supported_vector(int opcode, int vlen) {

  // TODO
  // identify extra cases that we might want to provide match rules for
  // e.g. Op_ vector nodes and other intrinsics while guarding with vlen
  bool ret_value = match_rule_supported(opcode);
  // Add rules here.

  return ret_value;  // Per default match rules are supported.
}

const bool Matcher::has_predicated_vectors(void) {
  return false;
}

const int Matcher::float_pressure(int default_pressure_threshold) {
  return default_pressure_threshold;
}

int Matcher::regnum_to_fpu_offset(int regnum) {
  return regnum - 32; // The FP registers are in the second chunk
}

// Vector width in bytes
const int Matcher::vector_width_in_bytes(BasicType bt) {
  return MaxVectorSize;
}

// Vector ideal reg corresponding to specified size in bytes
const int Matcher::vector_ideal_reg(int size) {
  assert(MaxVectorSize >= size, "");
  switch(size) {
    case  8: return Op_VecD;
    case 16: return Op_VecX;
  }
  ShouldNotReachHere();
  return 0;
}

const int Matcher::vector_shift_count_ideal_reg(int size) {
  return vector_ideal_reg(size);
}

// Limits on vector size (number of elements) loaded into vector.
const int Matcher::max_vector_size(const BasicType bt) {
  assert(is_java_primitive(bt), "only primitive type vectors");
  return vector_width_in_bytes(bt)/type2aelembytes(bt);
}

const int Matcher::min_vector_size(const BasicType bt) {
  assert(is_java_primitive(bt), "only primitive type vectors");
  return 8/type2aelembytes(bt);
}

// ARM doesn't support misaligned vectors store/load.
const bool Matcher::misaligned_vectors_ok() {
  return false;
}

// ARM doesn't support AES intrinsics
const bool Matcher::pass_original_key_for_aes() {
  return false;
}

const bool Matcher::convL2FSupported(void) {
#ifdef AARCH64
  return true;
#else
  return false;
#endif
}

// Is this branch offset short enough that a short branch can be used?
//
// NOTE: If the platform does not provide any short branch variants, then
//       this method should return false for offset 0.
bool Matcher::is_short_branch_offset(int rule, int br_size, int offset) {
  // The passed offset is relative to address of the branch.
  // On ARM a branch displacement is calculated relative to address
  // of the branch + 8.
  //
  // offset -= 8;
  // return (Assembler::is_simm24(offset));
  return false;
}

const bool Matcher::isSimpleConstant64(jlong value) {
  // Will one (StoreL ConL) be cheaper than two (StoreI ConI)?.
#ifdef AARCH64
  return (value == 0);
#else
  return false;
#endif
}

// No scaling for the parameter the ClearArray node.
const bool Matcher::init_array_count_is_in_bytes = true;

#ifdef AARCH64
const int Matcher::long_cmove_cost() { return 1; }
#else
// Needs 2 CMOV's for longs.
const int Matcher::long_cmove_cost() { return 2; }
#endif

#ifdef AARCH64
const int Matcher::float_cmove_cost() { return 1; }
#else
// CMOVF/CMOVD are expensive on ARM.
const int Matcher::float_cmove_cost() { return ConditionalMoveLimit; }
#endif

// Does the CPU require late expand (see block.cpp for description of late expand)?
const bool Matcher::require_postalloc_expand = false;

// Do we need to mask the count passed to shift instructions or does
// the cpu only look at the lower 5/6 bits anyway?
// FIXME: does this handle vector shifts as well?
#ifdef AARCH64
const bool Matcher::need_masked_shift_count = false;
#else
const bool Matcher::need_masked_shift_count = true;
#endif

const bool Matcher::convi2l_type_required = true;

// Should the Matcher clone shifts on addressing modes, expecting them
// to be subsumed into complex addressing expressions or compute them
// into registers?
bool Matcher::clone_address_expressions(AddPNode* m, Matcher::MStack& mstack, VectorSet& address_visited) {
  return clone_base_plus_offset_address(m, mstack, address_visited);
}

void Compile::reshape_address(AddPNode* addp) {
}

bool Matcher::narrow_oop_use_complex_address() {
  NOT_LP64(ShouldNotCallThis());
  assert(UseCompressedOops, "only for compressed oops code");
  return false;
}

bool Matcher::narrow_klass_use_complex_address() {
  NOT_LP64(ShouldNotCallThis());
  assert(UseCompressedClassPointers, "only for compressed klass code");
  return false;
}

bool Matcher::const_oop_prefer_decode() {
  NOT_LP64(ShouldNotCallThis());
  return true;
}

bool Matcher::const_klass_prefer_decode() {
  NOT_LP64(ShouldNotCallThis());
  return true;
}

// Is it better to copy float constants, or load them directly from memory?
// Intel can load a float constant from a direct address, requiring no
// extra registers.  Most RISCs will have to materialize an address into a
// register first, so they would do better to copy the constant from stack.
const bool Matcher::rematerialize_float_constants = false;

// If CPU can load and store mis-aligned doubles directly then no fixup is
// needed.  Else we split the double into 2 integer pieces and move it
// piece-by-piece.  Only happens when passing doubles into C code as the
// Java calling convention forces doubles to be aligned.
#ifdef AARCH64
// On stack replacement support:
// We don't need Load[DL]_unaligned support, because interpreter stack
// has correct alignment
const bool Matcher::misaligned_doubles_ok = true;
#else
const bool Matcher::misaligned_doubles_ok = false;
#endif

// No-op on ARM.
void Matcher::pd_implicit_null_fixup(MachNode *node, uint idx) {
}

// Advertise here if the CPU requires explicit rounding operations
// to implement the UseStrictFP mode.
const bool Matcher::strict_fp_requires_explicit_rounding = false;

// Are floats converted to double when stored to stack during deoptimization?
// ARM does not handle callee-save floats.
bool Matcher::float_in_double() {
  return false;
}

// Do ints take an entire long register or just half?
// Note that we if-def off of _LP64.
// The relevant question is how the int is callee-saved.  In _LP64
// the whole long is written but de-opt'ing will have to extract
// the relevant 32 bits, in not-_LP64 only the low 32 bits is written.
#ifdef _LP64
const bool Matcher::int_in_long = true;
#else
const bool Matcher::int_in_long = false;
#endif

// Return whether or not this register is ever used as an argument.  This
// function is used on startup to build the trampoline stubs in generateOptoStub.
// Registers not mentioned will be killed by the VM call in the trampoline, and
// arguments in those registers not be available to the callee.
bool Matcher::can_be_java_arg( int reg ) {
#ifdef AARCH64
  if (reg >= R_R0_num && reg < R_R8_num) return true;
  if (reg >= R_V0_num && reg <= R_V7b_num && ((reg & 3) < 2)) return true;
#else
  if (reg == R_R0_num ||
      reg == R_R1_num ||
      reg == R_R2_num ||
      reg == R_R3_num) return true;

  if (reg >= R_S0_num &&
      reg <= R_S13_num) return true;
#endif
  return false;
}

bool Matcher::is_spillable_arg( int reg ) {
  return can_be_java_arg(reg);
}

bool Matcher::use_asm_for_ldiv_by_con( jlong divisor ) {
  return false;
}

// Register for DIVI projection of divmodI
RegMask Matcher::divI_proj_mask() {
  ShouldNotReachHere();
  return RegMask();
}

// Register for MODI projection of divmodI
RegMask Matcher::modI_proj_mask() {
  ShouldNotReachHere();
  return RegMask();
}

// Register for DIVL projection of divmodL
RegMask Matcher::divL_proj_mask() {
  ShouldNotReachHere();
  return RegMask();
}

// Register for MODL projection of divmodL
RegMask Matcher::modL_proj_mask() {
  ShouldNotReachHere();
  return RegMask();
}

const RegMask Matcher::method_handle_invoke_SP_save_mask() {
  return FP_REGP_mask();
}

bool maybe_far_call(const CallNode *n) {
  return !MacroAssembler::_reachable_from_cache(n->as_Call()->entry_point());
}

bool maybe_far_call(const MachCallNode *n) {
  return !MacroAssembler::_reachable_from_cache(n->as_MachCall()->entry_point());
}


#line 1346 "ad_arm.cpp"


#ifndef PRODUCT
void Compile::adlc_verification() {

  // Following assertions generated from definition section
  assert( DEFAULT_COST == 100, "Expect (100) to equal 100");
  assert( HUGE_COST == 1000000, "Expect (1000000) to equal 1000000");
  assert( MEMORY_REF_COST == 200, "Expect (DEFAULT_COST * 2) to equal 200");
  assert( BRANCH_COST == 300, "Expect (DEFAULT_COST * 3) to equal 300");
  assert( CALL_COST == 300, "Expect (DEFAULT_COST * 3) to equal 300");
}
#endif

// Map from machine-independent register number to register_save_policy
const        char register_save_policy[] = {
  'C', // R_R4
  'C', // R_R5
  'C', // R_R6
  'C', // R_R7
  'C', // R_R8
  'C', // R_R9
  'N', // R_R11
  'C', // R_R12
  'N', // R_R10
  'N', // R_R13
  'C', // R_R14
  'N', // R_R15
  'C', // R_R0
  'C', // R_R1
  'C', // R_R2
  'C', // R_R3
  'C', // R_S16
  'C', // R_S17
  'C', // R_S18
  'C', // R_S19
  'C', // R_S20
  'C', // R_S21
  'C', // R_S22
  'C', // R_S23
  'C', // R_S24
  'C', // R_S25
  'C', // R_S26
  'C', // R_S27
  'C', // R_S28
  'C', // R_S29
  'C', // R_S30
  'C', // R_S31
  'C', // R_S0
  'C', // R_S1
  'C', // R_S2
  'C', // R_S3
  'C', // R_S4
  'C', // R_S5
  'C', // R_S6
  'C', // R_S7
  'C', // R_S8
  'C', // R_S9
  'C', // R_S10
  'C', // R_S11
  'C', // R_S12
  'C', // R_S13
  'C', // R_S14
  'C', // R_S15
  'C', // R_D16
  'C', // R_D16x
  'C', // R_D17
  'C', // R_D17x
  'C', // R_D18
  'C', // R_D18x
  'C', // R_D19
  'C', // R_D19x
  'C', // R_D20
  'C', // R_D20x
  'C', // R_D21
  'C', // R_D21x
  'C', // R_D22
  'C', // R_D22x
  'C', // R_D23
  'C', // R_D23x
  'C', // R_D24
  'C', // R_D24x
  'C', // R_D25
  'C', // R_D25x
  'C', // R_D26
  'C', // R_D26x
  'C', // R_D27
  'C', // R_D27x
  'C', // R_D28
  'C', // R_D28x
  'C', // R_D29
  'C', // R_D29x
  'C', // R_D30
  'C', // R_D30x
  'C', // R_D31
  'C', // R_D31x
  'C', // APSR
  'C' // no trailing comma // FPSCR
};

// Map from machine-independent register number to c_reg_save_policy
const        char c_reg_save_policy[] = {
  'E', // R_R4
  'E', // R_R5
  'E', // R_R6
  'E', // R_R7
  'E', // R_R8
  'E', // R_R9
  'E', // R_R11
  'C', // R_R12
  'E', // R_R10
  'N', // R_R13
  'C', // R_R14
  'N', // R_R15
  'C', // R_R0
  'C', // R_R1
  'C', // R_R2
  'C', // R_R3
  'E', // R_S16
  'E', // R_S17
  'E', // R_S18
  'E', // R_S19
  'E', // R_S20
  'E', // R_S21
  'E', // R_S22
  'E', // R_S23
  'E', // R_S24
  'E', // R_S25
  'E', // R_S26
  'E', // R_S27
  'E', // R_S28
  'E', // R_S29
  'E', // R_S30
  'E', // R_S31
  'C', // R_S0
  'C', // R_S1
  'C', // R_S2
  'C', // R_S3
  'C', // R_S4
  'C', // R_S5
  'C', // R_S6
  'C', // R_S7
  'C', // R_S8
  'C', // R_S9
  'C', // R_S10
  'C', // R_S11
  'C', // R_S12
  'C', // R_S13
  'C', // R_S14
  'C', // R_S15
  'C', // R_D16
  'C', // R_D16x
  'C', // R_D17
  'C', // R_D17x
  'C', // R_D18
  'C', // R_D18x
  'C', // R_D19
  'C', // R_D19x
  'C', // R_D20
  'C', // R_D20x
  'C', // R_D21
  'C', // R_D21x
  'C', // R_D22
  'C', // R_D22x
  'C', // R_D23
  'C', // R_D23x
  'C', // R_D24
  'C', // R_D24x
  'C', // R_D25
  'C', // R_D25x
  'C', // R_D26
  'C', // R_D26x
  'C', // R_D27
  'C', // R_D27x
  'C', // R_D28
  'C', // R_D28x
  'C', // R_D29
  'C', // R_D29x
  'C', // R_D30
  'C', // R_D30x
  'C', // R_D31
  'C', // R_D31x
  'C', // APSR
  'C' // no trailing comma // FPSCR
};

// Map from machine-independent register number to register_save_type
const        int register_save_type[] = {
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegD,
  Op_RegFlags,
  Op_RegFlags // no trailing comma
};


const        int   reduceOp[] = {
  /*    0 */  0,
  /*    1 */  0,
  /*    2 */  0,
  /*    3 */  0,
  /*    4 */  0,
  /*    5 */  0,
  /*    6 */  0,
  /*    7 */  0,
  /*    8 */  immIRot_rule,
  /*    9 */  immIRotn_rule,
  /*   10 */  immIRotneg_rule,
  /*   11 */  immU31Rot_rule,
  /*   12 */  immPRot_rule,
  /*   13 */  immLlowRot_rule,
  /*   14 */  immLRot2_rule,
  /*   15 */  immI12_rule,
  /*   16 */  immI10x2_rule,
  /*   17 */  immI12x2_rule,
  /*   18 */  immI_rule,
  /*   19 */  immU8_rule,
  /*   20 */  immI16_rule,
  /*   21 */  immIHD_rule,
  /*   22 */  immIFP_rule,
  /*   23 */  immU5_rule,
  /*   24 */  immU6Big_rule,
  /*   25 */  immI0_rule,
  /*   26 */  immI_1_rule,
  /*   27 */  immI_2_rule,
  /*   28 */  immI_3_rule,
  /*   29 */  immI_4_rule,
  /*   30 */  immI_8_rule,
  /*   31 */  immU31_rule,
  /*   32 */  immI_32_63_rule,
  /*   33 */  immI_16_rule,
  /*   34 */  immI_24_rule,
  /*   35 */  immI_255_rule,
  /*   36 */  immI_65535_rule,
  /*   37 */  aimmI_rule,
  /*   38 */  aimmIneg_rule,
  /*   39 */  aimmU31_rule,
  /*   40 */  limmI_rule,
  /*   41 */  limmIlow8_rule,
  /*   42 */  limmU31_rule,
  /*   43 */  limmIn_rule,
  /*   44 */  immL_FF_rule,
  /*   45 */  immL_FFFF_rule,
  /*   46 */  immP_rule,
  /*   47 */  immP0_rule,
  /*   48 */  immP_poll_rule,
  /*   49 */  immN_rule,
  /*   50 */  immNKlass_rule,
  /*   51 */  immN0_rule,
  /*   52 */  immL_rule,
  /*   53 */  immL0_rule,
  /*   54 */  immL16_rule,
  /*   55 */  immL_32bits_rule,
  /*   56 */  immD_rule,
  /*   57 */  immD0_rule,
  /*   58 */  imm8D_rule,
  /*   59 */  immF_rule,
  /*   60 */  immF0_rule,
  /*   61 */  imm8F_rule,
  /*   62 */  iRegI_rule,
  /*   63 */  iRegP_rule,
  /*   64 */  sp_ptr_RegP_rule,
  /*   65 */  R0RegP_rule,
  /*   66 */  R1RegP_rule,
  /*   67 */  R2RegP_rule,
  /*   68 */  RExceptionRegP_rule,
  /*   69 */  RthreadRegP_rule,
  /*   70 */  IPRegP_rule,
  /*   71 */  LRRegP_rule,
  /*   72 */  R0RegI_rule,
  /*   73 */  R1RegI_rule,
  /*   74 */  R2RegI_rule,
  /*   75 */  R3RegI_rule,
  /*   76 */  R12RegI_rule,
  /*   77 */  iRegL_rule,
  /*   78 */  iRegLd_rule,
  /*   79 */  R0R1RegL_rule,
  /*   80 */  R2R3RegL_rule,
  /*   81 */  flagsReg_rule,
  /*   82 */  flagsReg_EQNELTGE_rule,
  /*   83 */  flagsRegU_rule,
  /*   84 */  flagsRegP_rule,
  /*   85 */  flagsRegL_LTGE_rule,
  /*   86 */  flagsRegL_EQNE_rule,
  /*   87 */  flagsRegL_LEGT_rule,
  /*   88 */  flagsRegF_rule,
  /*   89 */  vecD_rule,
  /*   90 */  vecX_rule,
  /*   91 */  regD_rule,
  /*   92 */  regF_rule,
  /*   93 */  regD_low_rule,
  /*   94 */  inline_cache_regP_rule,
  /*   95 */  interpreter_method_oop_regP_rule,
  /*   96 */  indirect_rule,
  /*   97 */  indOffset12_rule,
  /*   98 */  indOffsetFP_rule,
  /*   99 */  indOffsetHD_rule,
  /*  100 */  indOffsetFPx2_rule,
  /*  101 */  indOffset12x2_rule,
  /*  102 */  indIndex_rule,
  /*  103 */  indIndexScale_rule,
  /*  104 */  cmpOp_rule,
  /*  105 */  cmpOp0_rule,
  /*  106 */  cmpOpU_rule,
  /*  107 */  cmpOpP_rule,
  /*  108 */  cmpOpL_rule,
  /*  109 */  cmpOpL_commute_rule,
  /*  110 */  shiftedX_rule,
  // last operand
  /*  111 */  memoryI_rule,
  /*  112 */  memoryP_rule,
  /*  113 */  memoryF_rule,
  /*  114 */  memoryF2_rule,
  /*  115 */  memoryD_rule,
  /*  116 */  memoryfp_rule,
  /*  117 */  memoryB_rule,
  /*  118 */  memoryS_rule,
  /*  119 */  memoryL_rule,
  /*  120 */  memoryScaledI_rule,
  /*  121 */  memoryScaledP_rule,
  /*  122 */  memoryex_rule,
  /*  123 */  indIndexMemory_rule,
  /*  124 */  memorylong_rule,
  /*  125 */  memoryvld_rule,
  // last operand class
  /*  126 */  _LShiftI_iRegI_immU5_rule,
  /*  127 */  _LoadB_memoryB__rule,
  /*  128 */  _LoadUB_memoryB__rule,
  /*  129 */  _AndI__LoadUB_memoryB__limmIlow8_rule,
  /*  130 */  _LoadS_memoryS__rule,
  /*  131 */  _LShiftI__LoadS_memoryS__immI_24_rule,
  /*  132 */  _LoadUS_memoryB__rule,
  /*  133 */  _LShiftI__LoadUS_memoryB__immI_24_rule,
  /*  134 */  _LoadUS_memoryS__rule,
  /*  135 */  _AndI__LoadUS_memoryB__immI_255_rule,
  /*  136 */  _AndI__LoadUS_memoryS__limmI_rule,
  /*  137 */  _LoadI_memoryS__rule,
  /*  138 */  _LShiftI__LoadI_memoryS__immI_24_rule,
  /*  139 */  _LoadI_memoryB__rule,
  /*  140 */  _LShiftI__LoadI_memoryS__immI_16_rule,
  /*  141 */  _LoadI_memoryI__rule,
  /*  142 */  _AndI__LoadI_memoryB__immI_255_rule,
  /*  143 */  _AndI__LoadI_memoryS__immI_65535_rule,
  /*  144 */  _AndI__LoadI_memoryI__limmU31_rule,
  /*  145 */  _AndI__LoadI_memoryI__immU31_rule,
  /*  146 */  _ConvI2L__LoadI_memoryI___rule,
  /*  147 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  148 */  _Binary_iRegI_iRegI_rule,
  /*  149 */  _Binary_iRegI_immIRot_rule,
  /*  150 */  _Binary_iRegI_immI16_rule,
  /*  151 */  _Binary_cmpOp_flagsReg_rule,
  /*  152 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  153 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  154 */  _Binary_iRegP_iRegP_rule,
  /*  155 */  _Binary_iRegP_immP0_rule,
  /*  156 */  _Binary_regF_regF_rule,
  /*  157 */  _Binary_regD_regD_rule,
  /*  158 */  _Binary_iRegL_iRegL_rule,
  /*  159 */  _Binary_iRegL_immLlowRot_rule,
  /*  160 */  _Binary_iRegL_immL16_rule,
  /*  161 */  _LShiftI_iRegI_iRegI_rule,
  /*  162 */  _RShiftI_iRegI_iRegI_rule,
  /*  163 */  _RShiftI_iRegI_immU5_rule,
  /*  164 */  _URShiftI_iRegI_iRegI_rule,
  /*  165 */  _URShiftI_iRegI_immU5_rule,
  /*  166 */  _Binary_iRegL_iRegLd_rule,
  /*  167 */  _CastP2X_iRegP__rule,
  /*  168 */  _ConvF2D_regF__rule,
  /*  169 */  _SqrtD__ConvF2D_regF___rule,
  /*  170 */  _CmpLTMask_iRegI_iRegI_rule,
  /*  171 */  _AndI__CmpLTMask_iRegI_iRegI_iRegI_rule,
  /*  172 */  _AndI_iRegI__CmpLTMask_iRegI_iRegI_rule,
  /*  173 */  _CmpLTMask_iRegI_aimmI_rule,
  /*  174 */  _AndI__CmpLTMask_iRegI_aimmI_iRegI_rule,
  /*  175 */  _AndI_iRegI__CmpLTMask_iRegI_aimmI_rule,
  /*  176 */  _SubI_iRegI_iRegI_rule,
  /*  177 */  _ConvI2L_iRegI__rule,
  /*  178 */  _RShiftL_iRegL_immI_32_63_rule,
  /*  179 */  _AndI_iRegI_iRegI_rule,
  /*  180 */  _AndI_iRegI__LShiftI_iRegI_iRegI_rule,
  /*  181 */  _AndI__LShiftI_iRegI_iRegI_iRegI_rule,
  /*  182 */  _AndI_iRegI__LShiftI_iRegI_immU5_rule,
  /*  183 */  _AndI__LShiftI_iRegI_immU5_iRegI_rule,
  /*  184 */  _AndI_iRegI__RShiftI_iRegI_iRegI_rule,
  /*  185 */  _AndI__RShiftI_iRegI_iRegI_iRegI_rule,
  /*  186 */  _AndI_iRegI__RShiftI_iRegI_immU5_rule,
  /*  187 */  _AndI__RShiftI_iRegI_immU5_iRegI_rule,
  /*  188 */  _AndI_iRegI__URShiftI_iRegI_iRegI_rule,
  /*  189 */  _AndI__URShiftI_iRegI_iRegI_iRegI_rule,
  /*  190 */  _AndI_iRegI__URShiftI_iRegI_immU5_rule,
  /*  191 */  _AndI__URShiftI_iRegI_immU5_iRegI_rule,
  /*  192 */  _AndI_iRegI_limmI_rule,
  /*  193 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  194 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  195 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  196 */  _Binary_iRegL_immL0_rule,
  // last internally defined operand
  /*  197 */  iRegI_rule,
  /*  198 */  iRegI_rule,
  /*  199 */  iRegI_rule,
  /*  200 */  iRegI_rule,
  /*  201 */  iRegP_rule,
  /*  202 */  iRegP_rule,
  /*  203 */  iRegL_rule,
  /*  204 */  iRegL_rule,
  /*  205 */  regF_rule,
  /*  206 */  regF_rule,
  /*  207 */  regD_rule,
  /*  208 */  regD_rule,
  /*  209 */  iRegP_rule,
  /*  210 */  iRegI_rule,
  /*  211 */  RthreadRegP_rule,
  /*  212 */  iRegP_rule,
  /*  213 */  iRegP_rule,
  /*  214 */  iRegI_rule,
  /*  215 */  flagsRegP_rule,
  /*  216 */  flagsReg_rule,
  /*  217 */  regD_rule,
  /*  218 */  regF_rule,
  /*  219 */  regF_rule,
  /*  220 */  regD_rule,
  /*  221 */  iRegI_rule,
  /*  222 */  regF_rule,
  /*  223 */  iRegL_rule,
  /*  224 */  regD_rule,
  /*  225 */  0,
  /*  226 */  0,
  /*  227 */  flagsReg_rule,
  /*  228 */  flagsRegU_rule,
  /*  229 */  flagsReg_rule,
  /*  230 */  flagsReg_rule,
  /*  231 */  flagsReg_EQNELTGE_rule,
  /*  232 */  flagsReg_EQNELTGE_rule,
  /*  233 */  flagsReg_EQNELTGE_rule,
  /*  234 */  flagsReg_EQNELTGE_rule,
  /*  235 */  flagsReg_EQNELTGE_rule,
  /*  236 */  flagsReg_EQNELTGE_rule,
  /*  237 */  flagsReg_EQNELTGE_rule,
  /*  238 */  flagsReg_EQNELTGE_rule,
  /*  239 */  flagsReg_EQNELTGE_rule,
  /*  240 */  flagsReg_EQNELTGE_rule,
  /*  241 */  flagsReg_EQNELTGE_rule,
  /*  242 */  flagsReg_EQNELTGE_rule,
  /*  243 */  flagsReg_EQNELTGE_rule,
  /*  244 */  flagsReg_EQNELTGE_rule,
  /*  245 */  flagsRegL_LTGE_rule,
  /*  246 */  flagsRegL_EQNE_rule,
  /*  247 */  flagsRegL_LEGT_rule,
  /*  248 */  flagsRegL_LTGE_rule,
  /*  249 */  flagsRegL_EQNE_rule,
  /*  250 */  flagsRegL_LEGT_rule,
  /*  251 */  flagsRegU_rule,
  /*  252 */  flagsRegP_rule,
  /*  253 */  flagsRegP_rule,
  /*  254 */  flagsReg_rule,
  /*  255 */  flagsReg_rule,
  /*  256 */  flagsReg_rule,
  /*  257 */  flagsReg_rule,
  /*  258 */  flagsRegP_rule,
  /*  259 */  flagsRegP_rule,
  /*  260 */  iRegI_rule,
  /*  261 */  0,
  /*  262 */  0,
  /*  263 */  vecD_rule,
  /*  264 */  vecX_rule,
  /*  265 */  vecD_rule,
  /*  266 */  vecX_rule,
  /*  267 */  0,
  /*  268 */  0,
  /*  269 */  0,
  /*  270 */  0,
  /*  271 */  0,
  /*  272 */  iRegI_rule,
  /*  273 */  iRegL_rule,
  /*  274 */  iRegI_rule,
  /*  275 */  iRegL_rule,
  /*  276 */  iRegL_rule,
  /*  277 */  iRegI_rule,
  /*  278 */  iRegI_rule,
  /*  279 */  iRegL_rule,
  /*  280 */  iRegI_rule,
  /*  281 */  iRegI_rule,
  /*  282 */  iRegL_rule,
  /*  283 */  iRegL_rule,
  /*  284 */  iRegL_rule,
  /*  285 */  iRegI_rule,
  /*  286 */  iRegI_rule,
  /*  287 */  iRegI_rule,
  /*  288 */  iRegI_rule,
  /*  289 */  iRegI_rule,
  /*  290 */  iRegL_rule,
  /*  291 */  iRegL_rule,
  /*  292 */  iRegL_rule,
  /*  293 */  iRegL_rule,
  /*  294 */  iRegL_rule,
  /*  295 */  iRegL_rule,
  /*  296 */  iRegLd_rule,
  /*  297 */  iRegL_rule,
  /*  298 */  iRegL_rule,
  /*  299 */  iRegL_rule,
  /*  300 */  iRegL_rule,
  /*  301 */  iRegI_rule,
  /*  302 */  iRegP_rule,
  /*  303 */  iRegP_rule,
  /*  304 */  regD_rule,
  /*  305 */  regD_low_rule,
  /*  306 */  regF_rule,
  /*  307 */  Universe_rule,
  /*  308 */  Universe_rule,
  /*  309 */  Universe_rule,
  /*  310 */  Universe_rule,
  /*  311 */  Universe_rule,
  /*  312 */  Universe_rule,
  /*  313 */  Universe_rule,
  /*  314 */  Universe_rule,
  /*  315 */  Universe_rule,
  /*  316 */  Universe_rule,
  /*  317 */  Universe_rule,
  /*  318 */  Universe_rule,
  /*  319 */  Universe_rule,
  /*  320 */  Universe_rule,
  /*  321 */  Universe_rule,
  /*  322 */  Universe_rule,
  /*  323 */  Universe_rule,
  /*  324 */  Universe_rule,
  /*  325 */  Universe_rule,
  /*  326 */  Universe_rule,
  /*  327 */  Universe_rule,
  /*  328 */  Universe_rule,
  /*  329 */  iRegI_rule,
  /*  330 */  iRegI_rule,
  /*  331 */  iRegI_rule,
  /*  332 */  iRegI_rule,
  /*  333 */  iRegI_rule,
  /*  334 */  iRegI_rule,
  /*  335 */  iRegI_rule,
  /*  336 */  iRegI_rule,
  /*  337 */  iRegI_rule,
  /*  338 */  iRegI_rule,
  /*  339 */  iRegI_rule,
  /*  340 */  iRegI_rule,
  /*  341 */  iRegP_rule,
  /*  342 */  iRegP_rule,
  /*  343 */  iRegP_rule,
  /*  344 */  iRegP_rule,
  /*  345 */  iRegP_rule,
  /*  346 */  iRegP_rule,
  /*  347 */  iRegP_rule,
  /*  348 */  iRegP_rule,
  /*  349 */  regF_rule,
  /*  350 */  regF_rule,
  /*  351 */  regF_rule,
  /*  352 */  regF_rule,
  /*  353 */  regD_rule,
  /*  354 */  regD_rule,
  /*  355 */  regD_rule,
  /*  356 */  regD_rule,
  /*  357 */  iRegL_rule,
  /*  358 */  iRegL_rule,
  /*  359 */  iRegL_rule,
  /*  360 */  iRegL_rule,
  /*  361 */  iRegL_rule,
  /*  362 */  iRegL_rule,
  /*  363 */  iRegL_rule,
  /*  364 */  iRegL_rule,
  /*  365 */  iRegL_rule,
  /*  366 */  iRegL_rule,
  /*  367 */  iRegI_rule,
  /*  368 */  iRegI_rule,
  /*  369 */  iRegI_rule,
  /*  370 */  iRegI_rule,
  /*  371 */  iRegI_rule,
  /*  372 */  iRegI_rule,
  /*  373 */  iRegI_rule,
  /*  374 */  iRegI_rule,
  /*  375 */  iRegI_rule,
  /*  376 */  iRegI_rule,
  /*  377 */  iRegI_rule,
  /*  378 */  iRegI_rule,
  /*  379 */  iRegI_rule,
  /*  380 */  iRegI_rule,
  /*  381 */  iRegP_rule,
  /*  382 */  iRegP_rule,
  /*  383 */  iRegP_rule,
  /*  384 */  iRegL_rule,
  /*  385 */  iRegL_rule,
  /*  386 */  iRegP_rule,
  /*  387 */  iRegI_rule,
  /*  388 */  iRegI_rule,
  /*  389 */  iRegI_rule,
  /*  390 */  Universe_rule,
  /*  391 */  Universe_rule,
  /*  392 */  iRegI_rule,
  /*  393 */  iRegI_rule,
  /*  394 */  Universe_rule,
  /*  395 */  Universe_rule,
  /*  396 */  iRegLd_rule,
  /*  397 */  iRegLd_rule,
  /*  398 */  iRegI_rule,
  /*  399 */  iRegLd_rule,
  /*  400 */  iRegP_rule,
  /*  401 */  iRegI_rule,
  /*  402 */  iRegI_rule,
  /*  403 */  iRegI_rule,
  /*  404 */  iRegI_rule,
  /*  405 */  iRegI_rule,
  /*  406 */  iRegI_rule,
  /*  407 */  iRegI_rule,
  /*  408 */  iRegI_rule,
  /*  409 */  iRegI_rule,
  /*  410 */  iRegI_rule,
  /*  411 */  iRegI_rule,
  /*  412 */  iRegI_rule,
  /*  413 */  iRegI_rule,
  /*  414 */  iRegI_rule,
  /*  415 */  iRegI_rule,
  /*  416 */  iRegI_rule,
  /*  417 */  iRegL_rule,
  /*  418 */  iRegL_rule,
  /*  419 */  iRegL_rule,
  /*  420 */  iRegI_rule,
  /*  421 */  0,
  /*  422 */  0,
  /*  423 */  0,
  /*  424 */  iRegL_rule,
  /*  425 */  R1RegI_rule,
  /*  426 */  R0R1RegL_rule,
  /*  427 */  R0RegI_rule,
  /*  428 */  R0R1RegL_rule,
  /*  429 */  iRegI_rule,
  /*  430 */  iRegI_rule,
  /*  431 */  0,
  /*  432 */  0,
  /*  433 */  0,
  /*  434 */  iRegL_rule,
  /*  435 */  iRegL_rule,
  /*  436 */  iRegL_rule,
  /*  437 */  iRegI_rule,
  /*  438 */  iRegI_rule,
  /*  439 */  0,
  /*  440 */  0,
  /*  441 */  0,
  /*  442 */  iRegL_rule,
  /*  443 */  iRegL_rule,
  /*  444 */  iRegL_rule,
  /*  445 */  iRegI_rule,
  /*  446 */  iRegI_rule,
  /*  447 */  0,
  /*  448 */  0,
  /*  449 */  0,
  /*  450 */  iRegL_rule,
  /*  451 */  iRegL_rule,
  /*  452 */  iRegL_rule,
  /*  453 */  iRegI_rule,
  /*  454 */  regF_rule,
  /*  455 */  regD_rule,
  /*  456 */  regF_rule,
  /*  457 */  regD_rule,
  /*  458 */  regF_rule,
  /*  459 */  regD_rule,
  /*  460 */  regF_rule,
  /*  461 */  regD_rule,
  /*  462 */  regF_rule,
  /*  463 */  regD_rule,
  /*  464 */  iRegI_rule,
  /*  465 */  iRegI_rule,
  /*  466 */  iRegI_rule,
  /*  467 */  iRegI_rule,
  /*  468 */  iRegI_rule,
  /*  469 */  iRegI_rule,
  /*  470 */  iRegI_rule,
  /*  471 */  iRegI_rule,
  /*  472 */  iRegI_rule,
  /*  473 */  iRegI_rule,
  /*  474 */  iRegI_rule,
  /*  475 */  iRegI_rule,
  /*  476 */  iRegI_rule,
  /*  477 */  iRegI_rule,
  /*  478 */  iRegI_rule,
  /*  479 */  iRegL_rule,
  /*  480 */  iRegL_rule,
  /*  481 */  iRegI_rule,
  /*  482 */  iRegI_rule,
  /*  483 */  iRegI_rule,
  /*  484 */  iRegI_rule,
  /*  485 */  iRegI_rule,
  /*  486 */  iRegI_rule,
  /*  487 */  iRegI_rule,
  /*  488 */  iRegI_rule,
  /*  489 */  iRegI_rule,
  /*  490 */  iRegI_rule,
  /*  491 */  iRegI_rule,
  /*  492 */  iRegI_rule,
  /*  493 */  iRegI_rule,
  /*  494 */  iRegI_rule,
  /*  495 */  iRegL_rule,
  /*  496 */  iRegL_rule,
  /*  497 */  iRegI_rule,
  /*  498 */  iRegI_rule,
  /*  499 */  iRegI_rule,
  /*  500 */  iRegI_rule,
  /*  501 */  iRegI_rule,
  /*  502 */  iRegI_rule,
  /*  503 */  iRegI_rule,
  /*  504 */  iRegI_rule,
  /*  505 */  iRegI_rule,
  /*  506 */  iRegI_rule,
  /*  507 */  iRegI_rule,
  /*  508 */  iRegI_rule,
  /*  509 */  iRegI_rule,
  /*  510 */  iRegI_rule,
  /*  511 */  iRegL_rule,
  /*  512 */  iRegL_rule,
  /*  513 */  iRegI_rule,
  /*  514 */  iRegI_rule,
  /*  515 */  iRegI_rule,
  /*  516 */  iRegI_rule,
  /*  517 */  iRegI_rule,
  /*  518 */  iRegI_rule,
  /*  519 */  iRegI_rule,
  /*  520 */  iRegI_rule,
  /*  521 */  iRegI_rule,
  /*  522 */  iRegI_rule,
  /*  523 */  iRegI_rule,
  /*  524 */  iRegI_rule,
  /*  525 */  iRegI_rule,
  /*  526 */  iRegI_rule,
  /*  527 */  iRegI_rule,
  /*  528 */  iRegI_rule,
  /*  529 */  regF_rule,
  /*  530 */  iRegI_rule,
  /*  531 */  R0R1RegL_rule,
  /*  532 */  regD_rule,
  /*  533 */  iRegI_rule,
  /*  534 */  R0R1RegL_rule,
  /*  535 */  regD_low_rule,
  /*  536 */  regF_rule,
  /*  537 */  iRegL_rule,
  /*  538 */  iRegL_rule,
  /*  539 */  iRegL_rule,
  /*  540 */  0,
  /*  541 */  0,
  /*  542 */  0,
  /*  543 */  0,
  /*  544 */  0,
  /*  545 */  0,
  /*  546 */  0,
  /*  547 */  0,
  /*  548 */  regD_rule,
  /*  549 */  iRegI_rule,
  /*  550 */  iRegI_rule,
  /*  551 */  0,
  /*  552 */  iRegI_rule,
  /*  553 */  0,
  /*  554 */  iRegI_rule,
  /*  555 */  iRegI_rule,
  /*  556 */  iRegI_rule,
  /*  557 */  iRegI_rule,
  /*  558 */  iRegI_rule,
  /*  559 */  Universe_rule,
  /*  560 */  Universe_rule,
  /*  561 */  Universe_rule,
  /*  562 */  Universe_rule,
  /*  563 */  Universe_rule,
  /*  564 */  Universe_rule,
  /*  565 */  Universe_rule,
  /*  566 */  Universe_rule,
  /*  567 */  Universe_rule,
  /*  568 */  Universe_rule,
  /*  569 */  iRegI_rule,
  /*  570 */  iRegL_rule,
  /*  571 */  iRegL_rule,
  /*  572 */  iRegL_rule,
  /*  573 */  iRegL_rule,
  /*  574 */  iRegL_rule,
  /*  575 */  iRegL_rule,
  /*  576 */  iRegI_rule,
  /*  577 */  iRegI_rule,
  /*  578 */  iRegI_rule,
  /*  579 */  iRegI_rule,
  /*  580 */  iRegI_rule,
  /*  581 */  iRegI_rule,
  /*  582 */  iRegP_rule,
  /*  583 */  iRegP_rule,
  /*  584 */  iRegP_rule,
  /*  585 */  iRegP_rule,
  /*  586 */  iRegP_rule,
  /*  587 */  iRegP_rule,
  /*  588 */  regF_rule,
  /*  589 */  regF_rule,
  /*  590 */  regF_rule,
  /*  591 */  regD_rule,
  /*  592 */  regD_rule,
  /*  593 */  regD_rule,
  /*  594 */  Universe_rule,
  /*  595 */  Universe_rule,
  /*  596 */  Universe_rule,
  /*  597 */  Universe_rule,
  /*  598 */  Universe_rule,
  /*  599 */  Universe_rule,
  /*  600 */  Universe_rule,
  /*  601 */  Universe_rule,
  /*  602 */  Universe_rule,
  /*  603 */  Universe_rule,
  /*  604 */  RExceptionRegP_rule,
  /*  605 */  Universe_rule,
  /*  606 */  Universe_rule,
  /*  607 */  R0RegP_rule,
  /*  608 */  Universe_rule,
  /*  609 */  iRegI_rule,
  /*  610 */  iRegI_rule,
  /*  611 */  iRegI_rule,
  /*  612 */  iRegI_rule,
  /*  613 */  iRegI_rule,
  /*  614 */  iRegI_rule,
  /*  615 */  iRegL_rule,
  /*  616 */  iRegI_rule,
  /*  617 */  iRegI_rule,
  /*  618 */  vecD_rule,
  /*  619 */  vecX_rule,
  /*  620 */  Universe_rule,
  /*  621 */  Universe_rule,
  /*  622 */  vecD_rule,
  /*  623 */  vecD_rule,
  /*  624 */  vecX_rule,
  /*  625 */  vecD_rule,
  /*  626 */  vecD_rule,
  /*  627 */  vecX_rule,
  /*  628 */  vecD_rule,
  /*  629 */  vecD_rule,
  /*  630 */  vecX_rule,
  /*  631 */  vecD_rule,
  /*  632 */  vecD_rule,
  /*  633 */  vecX_rule,
  /*  634 */  vecD_rule,
  /*  635 */  vecX_rule,
  /*  636 */  vecD_rule,
  /*  637 */  vecX_rule,
  /*  638 */  vecD_rule,
  /*  639 */  vecD_rule,
  /*  640 */  vecX_rule,
  /*  641 */  vecX_rule,
  /*  642 */  vecD_rule,
  /*  643 */  vecD_rule,
  /*  644 */  vecD_rule,
  /*  645 */  vecX_rule,
  /*  646 */  vecX_rule,
  /*  647 */  vecD_rule,
  /*  648 */  vecX_rule,
  /*  649 */  vecD_rule,
  /*  650 */  vecX_rule,
  /*  651 */  vecD_rule,
  /*  652 */  vecX_rule,
  /*  653 */  vecD_rule,
  /*  654 */  vecX_rule,
  /*  655 */  vecX_rule,
  /*  656 */  vecD_rule,
  /*  657 */  vecD_rule,
  /*  658 */  vecX_rule,
  /*  659 */  vecX_rule,
  /*  660 */  vecX_rule,
  /*  661 */  vecD_rule,
  /*  662 */  vecX_rule,
  /*  663 */  vecD_rule,
  /*  664 */  vecX_rule,
  /*  665 */  vecD_rule,
  /*  666 */  vecX_rule,
  /*  667 */  vecX_rule,
  /*  668 */  vecD_rule,
  /*  669 */  vecD_rule,
  /*  670 */  vecX_rule,
  /*  671 */  vecX_rule,
  /*  672 */  vecX_rule,
  /*  673 */  vecD_rule,
  /*  674 */  vecX_rule,
  /*  675 */  vecD_rule,
  /*  676 */  vecX_rule,
  /*  677 */  vecD_rule,
  /*  678 */  vecD_rule,
  /*  679 */  vecX_rule,
  /*  680 */  vecX_rule,
  /*  681 */  vecX_rule,
  /*  682 */  vecD_rule,
  /*  683 */  vecX_rule,
  /*  684 */  vecX_rule,
  /*  685 */  0,
  /*  686 */  0,
  /*  687 */  0,
  /*  688 */  0,
  /*  689 */  0,
  /*  690 */  0,
  /*  691 */  0,
  /*  692 */  vecD_rule,
  /*  693 */  vecX_rule,
  /*  694 */  vecD_rule,
  /*  695 */  vecX_rule,
  /*  696 */  vecD_rule,
  /*  697 */  vecD_rule,
  /*  698 */  vecX_rule,
  /*  699 */  vecX_rule,
  /*  700 */  vecD_rule,
  /*  701 */  vecX_rule,
  /*  702 */  vecD_rule,
  /*  703 */  vecD_rule,
  /*  704 */  vecX_rule,
  /*  705 */  vecX_rule,
  /*  706 */  vecD_rule,
  /*  707 */  vecX_rule,
  /*  708 */  vecX_rule,
  /*  709 */  vecX_rule,
  /*  710 */  vecX_rule,
  /*  711 */  vecD_rule,
  /*  712 */  vecX_rule,
  /*  713 */  vecD_rule,
  /*  714 */  vecX_rule,
  /*  715 */  vecX_rule,
  /*  716 */  0,
  /*  717 */  0,
  /*  718 */  0,
  /*  719 */  0,
  /*  720 */  0,
  /*  721 */  0,
  /*  722 */  0,
  /*  723 */  vecD_rule,
  /*  724 */  vecX_rule,
  /*  725 */  vecD_rule,
  /*  726 */  vecX_rule,
  /*  727 */  vecD_rule,
  /*  728 */  vecX_rule,
  /*  729 */  vecD_rule,
  /*  730 */  vecX_rule,
  /*  731 */  vecD_rule,
  /*  732 */  vecX_rule,
  /*  733 */  vecD_rule,
  /*  734 */  vecX_rule,
  /*  735 */  vecX_rule,
  /*  736 */  vecX_rule,
  /*  737 */  vecD_rule,
  /*  738 */  vecX_rule,
  /*  739 */  vecD_rule,
  /*  740 */  vecX_rule,
  /*  741 */  vecD_rule,
  /*  742 */  vecX_rule,
  // last instruction
  0 // no trailing comma
};

const        int   leftOp[] = {
  /*    0 */  0,
  /*    1 */  0,
  /*    2 */  0,
  /*    3 */  0,
  /*    4 */  0,
  /*    5 */  0,
  /*    6 */  0,
  /*    7 */  0,
  /*    8 */  0,
  /*    9 */  0,
  /*   10 */  0,
  /*   11 */  0,
  /*   12 */  0,
  /*   13 */  0,
  /*   14 */  0,
  /*   15 */  0,
  /*   16 */  0,
  /*   17 */  0,
  /*   18 */  0,
  /*   19 */  0,
  /*   20 */  0,
  /*   21 */  0,
  /*   22 */  0,
  /*   23 */  0,
  /*   24 */  0,
  /*   25 */  0,
  /*   26 */  0,
  /*   27 */  0,
  /*   28 */  0,
  /*   29 */  0,
  /*   30 */  0,
  /*   31 */  0,
  /*   32 */  0,
  /*   33 */  0,
  /*   34 */  0,
  /*   35 */  0,
  /*   36 */  0,
  /*   37 */  0,
  /*   38 */  0,
  /*   39 */  0,
  /*   40 */  0,
  /*   41 */  0,
  /*   42 */  0,
  /*   43 */  0,
  /*   44 */  0,
  /*   45 */  0,
  /*   46 */  0,
  /*   47 */  0,
  /*   48 */  0,
  /*   49 */  0,
  /*   50 */  0,
  /*   51 */  0,
  /*   52 */  0,
  /*   53 */  0,
  /*   54 */  0,
  /*   55 */  0,
  /*   56 */  0,
  /*   57 */  0,
  /*   58 */  0,
  /*   59 */  0,
  /*   60 */  0,
  /*   61 */  0,
  /*   62 */  0,
  /*   63 */  0,
  /*   64 */  0,
  /*   65 */  0,
  /*   66 */  0,
  /*   67 */  0,
  /*   68 */  0,
  /*   69 */  0,
  /*   70 */  0,
  /*   71 */  0,
  /*   72 */  0,
  /*   73 */  0,
  /*   74 */  0,
  /*   75 */  0,
  /*   76 */  0,
  /*   77 */  0,
  /*   78 */  0,
  /*   79 */  0,
  /*   80 */  0,
  /*   81 */  0,
  /*   82 */  0,
  /*   83 */  0,
  /*   84 */  0,
  /*   85 */  0,
  /*   86 */  0,
  /*   87 */  0,
  /*   88 */  0,
  /*   89 */  0,
  /*   90 */  0,
  /*   91 */  0,
  /*   92 */  0,
  /*   93 */  0,
  /*   94 */  0,
  /*   95 */  0,
  /*   96 */  0,
  /*   97 */  sp_ptr_RegP_rule,
  /*   98 */  sp_ptr_RegP_rule,
  /*   99 */  sp_ptr_RegP_rule,
  /*  100 */  sp_ptr_RegP_rule,
  /*  101 */  sp_ptr_RegP_rule,
  /*  102 */  iRegP_rule,
  /*  103 */  iRegP_rule,
  /*  104 */  0,
  /*  105 */  0,
  /*  106 */  0,
  /*  107 */  0,
  /*  108 */  0,
  /*  109 */  0,
  /*  110 */  iRegI_rule,
  // last operand
  /*  111 */  0,
  /*  112 */  0,
  /*  113 */  0,
  /*  114 */  0,
  /*  115 */  0,
  /*  116 */  0,
  /*  117 */  0,
  /*  118 */  0,
  /*  119 */  0,
  /*  120 */  0,
  /*  121 */  0,
  /*  122 */  0,
  /*  123 */  0,
  /*  124 */  0,
  /*  125 */  0,
  // last operand class
  /*  126 */  iRegI_rule,
  /*  127 */  memoryB_rule,
  /*  128 */  memoryB_rule,
  /*  129 */  _LoadUB_memoryB__rule,
  /*  130 */  memoryS_rule,
  /*  131 */  _LoadS_memoryS__rule,
  /*  132 */  memoryB_rule,
  /*  133 */  _LoadUS_memoryB__rule,
  /*  134 */  memoryS_rule,
  /*  135 */  _LoadUS_memoryB__rule,
  /*  136 */  _LoadUS_memoryS__rule,
  /*  137 */  memoryS_rule,
  /*  138 */  _LoadI_memoryS__rule,
  /*  139 */  memoryB_rule,
  /*  140 */  _LoadI_memoryS__rule,
  /*  141 */  memoryI_rule,
  /*  142 */  _LoadI_memoryB__rule,
  /*  143 */  _LoadI_memoryS__rule,
  /*  144 */  _LoadI_memoryI__rule,
  /*  145 */  _LoadI_memoryI__rule,
  /*  146 */  _LoadI_memoryI__rule,
  /*  147 */  cmpOpP_rule,
  /*  148 */  iRegI_rule,
  /*  149 */  iRegI_rule,
  /*  150 */  iRegI_rule,
  /*  151 */  cmpOp_rule,
  /*  152 */  cmpOp0_rule,
  /*  153 */  cmpOpU_rule,
  /*  154 */  iRegP_rule,
  /*  155 */  iRegP_rule,
  /*  156 */  regF_rule,
  /*  157 */  regD_rule,
  /*  158 */  iRegL_rule,
  /*  159 */  iRegL_rule,
  /*  160 */  iRegL_rule,
  /*  161 */  iRegI_rule,
  /*  162 */  iRegI_rule,
  /*  163 */  iRegI_rule,
  /*  164 */  iRegI_rule,
  /*  165 */  iRegI_rule,
  /*  166 */  iRegL_rule,
  /*  167 */  iRegP_rule,
  /*  168 */  regF_rule,
  /*  169 */  _ConvF2D_regF__rule,
  /*  170 */  iRegI_rule,
  /*  171 */  _CmpLTMask_iRegI_iRegI_rule,
  /*  172 */  iRegI_rule,
  /*  173 */  iRegI_rule,
  /*  174 */  _CmpLTMask_iRegI_aimmI_rule,
  /*  175 */  iRegI_rule,
  /*  176 */  iRegI_rule,
  /*  177 */  iRegI_rule,
  /*  178 */  iRegL_rule,
  /*  179 */  iRegI_rule,
  /*  180 */  iRegI_rule,
  /*  181 */  _LShiftI_iRegI_iRegI_rule,
  /*  182 */  iRegI_rule,
  /*  183 */  _LShiftI_iRegI_immU5_rule,
  /*  184 */  iRegI_rule,
  /*  185 */  _RShiftI_iRegI_iRegI_rule,
  /*  186 */  iRegI_rule,
  /*  187 */  _RShiftI_iRegI_immU5_rule,
  /*  188 */  iRegI_rule,
  /*  189 */  _URShiftI_iRegI_iRegI_rule,
  /*  190 */  iRegI_rule,
  /*  191 */  _URShiftI_iRegI_immU5_rule,
  /*  192 */  iRegI_rule,
  /*  193 */  cmpOpL_rule,
  /*  194 */  cmpOpL_rule,
  /*  195 */  cmpOpL_commute_rule,
  /*  196 */  iRegL_rule,
  // last internally defined operand
  /*  197 */  immI_rule,
  /*  198 */  immIRot_rule,
  /*  199 */  immIRotn_rule,
  /*  200 */  immI16_rule,
  /*  201 */  immP_rule,
  /*  202 */  immP_poll_rule,
  /*  203 */  immL_rule,
  /*  204 */  immL16_rule,
  /*  205 */  imm8F_rule,
  /*  206 */  immF_rule,
  /*  207 */  imm8D_rule,
  /*  208 */  immD_rule,
  /*  209 */  iRegI_rule,
  /*  210 */  iRegP_rule,
  /*  211 */  0,
  /*  212 */  iRegP_rule,
  /*  213 */  iRegP_rule,
  /*  214 */  iRegI_rule,
  /*  215 */  memoryex_rule,
  /*  216 */  memoryex_rule,
  /*  217 */  regD_rule,
  /*  218 */  regF_rule,
  /*  219 */  regF_rule,
  /*  220 */  regD_rule,
  /*  221 */  regF_rule,
  /*  222 */  iRegI_rule,
  /*  223 */  regD_rule,
  /*  224 */  iRegL_rule,
  /*  225 */  0,
  /*  226 */  0,
  /*  227 */  iRegI_rule,
  /*  228 */  iRegI_rule,
  /*  229 */  iRegI_rule,
  /*  230 */  iRegI_rule,
  /*  231 */  _AndI_iRegI_iRegI_rule,
  /*  232 */  _AndI_iRegI__LShiftI_iRegI_iRegI_rule,
  /*  233 */  _AndI__LShiftI_iRegI_iRegI_iRegI_rule,
  /*  234 */  _AndI_iRegI__LShiftI_iRegI_immU5_rule,
  /*  235 */  _AndI__LShiftI_iRegI_immU5_iRegI_rule,
  /*  236 */  _AndI_iRegI__RShiftI_iRegI_iRegI_rule,
  /*  237 */  _AndI__RShiftI_iRegI_iRegI_iRegI_rule,
  /*  238 */  _AndI_iRegI__RShiftI_iRegI_immU5_rule,
  /*  239 */  _AndI__RShiftI_iRegI_immU5_iRegI_rule,
  /*  240 */  _AndI_iRegI__URShiftI_iRegI_iRegI_rule,
  /*  241 */  _AndI__URShiftI_iRegI_iRegI_iRegI_rule,
  /*  242 */  _AndI_iRegI__URShiftI_iRegI_immU5_rule,
  /*  243 */  _AndI__URShiftI_iRegI_immU5_iRegI_rule,
  /*  244 */  _AndI_iRegI_limmI_rule,
  /*  245 */  iRegL_rule,
  /*  246 */  iRegL_rule,
  /*  247 */  iRegL_rule,
  /*  248 */  iRegL_rule,
  /*  249 */  iRegL_rule,
  /*  250 */  iRegL_rule,
  /*  251 */  iRegI_rule,
  /*  252 */  iRegP_rule,
  /*  253 */  iRegP_rule,
  /*  254 */  regF_rule,
  /*  255 */  regF_rule,
  /*  256 */  regD_rule,
  /*  257 */  regD_rule,
  /*  258 */  iRegP_rule,
  /*  259 */  iRegP_rule,
  /*  260 */  iRegI_rule,
  /*  261 */  0,
  /*  262 */  0,
  /*  263 */  iRegI_rule,
  /*  264 */  iRegI_rule,
  /*  265 */  iRegI_rule,
  /*  266 */  iRegI_rule,
  /*  267 */  0,
  /*  268 */  0,
  /*  269 */  0,
  /*  270 */  0,
  /*  271 */  0,
  /*  272 */  memoryB_rule,
  /*  273 */  _LoadB_memoryB__rule,
  /*  274 */  memoryB_rule,
  /*  275 */  _LoadUB_memoryB__rule,
  /*  276 */  _AndI__LoadUB_memoryB__limmIlow8_rule,
  /*  277 */  memoryS_rule,
  /*  278 */  _LShiftI__LoadS_memoryS__immI_24_rule,
  /*  279 */  _LoadS_memoryS__rule,
  /*  280 */  memoryS_rule,
  /*  281 */  _LShiftI__LoadUS_memoryB__immI_24_rule,
  /*  282 */  _LoadUS_memoryS__rule,
  /*  283 */  _AndI__LoadUS_memoryB__immI_255_rule,
  /*  284 */  _AndI__LoadUS_memoryS__limmI_rule,
  /*  285 */  memoryI_rule,
  /*  286 */  _LShiftI__LoadI_memoryS__immI_24_rule,
  /*  287 */  _LoadI_memoryB__rule,
  /*  288 */  _LShiftI__LoadI_memoryS__immI_16_rule,
  /*  289 */  _LoadI_memoryS__rule,
  /*  290 */  _LoadI_memoryI__rule,
  /*  291 */  _AndI__LoadI_memoryB__immI_255_rule,
  /*  292 */  _AndI__LoadI_memoryS__immI_65535_rule,
  /*  293 */  _AndI__LoadI_memoryI__limmU31_rule,
  /*  294 */  _AndI__LoadI_memoryI__immU31_rule,
  /*  295 */  _ConvI2L__LoadI_memoryI___rule,
  /*  296 */  memoryL_rule,
  /*  297 */  memorylong_rule,
  /*  298 */  indirect_rule,
  /*  299 */  memoryD_rule,
  /*  300 */  memorylong_rule,
  /*  301 */  memoryI_rule,
  /*  302 */  memoryP_rule,
  /*  303 */  memoryI_rule,
  /*  304 */  memoryD_rule,
  /*  305 */  memoryF2_rule,
  /*  306 */  memoryF_rule,
  /*  307 */  memoryP_rule,
  /*  308 */  memoryP_rule,
  /*  309 */  memoryB_rule,
  /*  310 */  memoryB_rule,
  /*  311 */  memoryS_rule,
  /*  312 */  memoryI_rule,
  /*  313 */  memoryL_rule,
  /*  314 */  memorylong_rule,
  /*  315 */  indirect_rule,
  /*  316 */  memoryD_rule,
  /*  317 */  memoryP_rule,
  /*  318 */  memoryD_rule,
  /*  319 */  memoryF_rule,
  /*  320 */  0,
  /*  321 */  0,
  /*  322 */  0,
  /*  323 */  0,
  /*  324 */  0,
  /*  325 */  0,
  /*  326 */  0,
  /*  327 */  0,
  /*  328 */  0,
  /*  329 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  330 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  331 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  332 */  _Binary_cmpOp_flagsReg_rule,
  /*  333 */  _Binary_cmpOp_flagsReg_rule,
  /*  334 */  _Binary_cmpOp_flagsReg_rule,
  /*  335 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  336 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  337 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  338 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  339 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  340 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  341 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  342 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  343 */  _Binary_cmpOp_flagsReg_rule,
  /*  344 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  345 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  346 */  _Binary_cmpOp_flagsReg_rule,
  /*  347 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  348 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  349 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  350 */  _Binary_cmpOp_flagsReg_rule,
  /*  351 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  352 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  353 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  354 */  _Binary_cmpOp_flagsReg_rule,
  /*  355 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  356 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  357 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  358 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  359 */  _Binary_cmpOpP_flagsRegP_rule,
  /*  360 */  _Binary_cmpOp_flagsReg_rule,
  /*  361 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  362 */  _Binary_cmpOp_flagsReg_rule,
  /*  363 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  364 */  _Binary_cmpOp_flagsReg_rule,
  /*  365 */  _Binary_cmpOp0_flagsReg_EQNELTGE_rule,
  /*  366 */  _Binary_cmpOpU_flagsRegU_rule,
  /*  367 */  iRegI_rule,
  /*  368 */  _LShiftI_iRegI_iRegI_rule,
  /*  369 */  iRegI_rule,
  /*  370 */  _LShiftI_iRegI_immU5_rule,
  /*  371 */  iRegI_rule,
  /*  372 */  _RShiftI_iRegI_iRegI_rule,
  /*  373 */  iRegI_rule,
  /*  374 */  _RShiftI_iRegI_immU5_rule,
  /*  375 */  iRegI_rule,
  /*  376 */  _URShiftI_iRegI_iRegI_rule,
  /*  377 */  iRegI_rule,
  /*  378 */  _URShiftI_iRegI_immU5_rule,
  /*  379 */  iRegI_rule,
  /*  380 */  iRegI_rule,
  /*  381 */  iRegP_rule,
  /*  382 */  iRegP_rule,
  /*  383 */  iRegP_rule,
  /*  384 */  iRegL_rule,
  /*  385 */  iRegL_rule,
  /*  386 */  memoryex_rule,
  /*  387 */  memoryex_rule,
  /*  388 */  memoryex_rule,
  /*  389 */  memoryex_rule,
  /*  390 */  memoryex_rule,
  /*  391 */  memoryex_rule,
  /*  392 */  memoryex_rule,
  /*  393 */  memoryex_rule,
  /*  394 */  memoryex_rule,
  /*  395 */  memoryex_rule,
  /*  396 */  memoryex_rule,
  /*  397 */  memoryex_rule,
  /*  398 */  memoryex_rule,
  /*  399 */  memoryex_rule,
  /*  400 */  memoryex_rule,
  /*  401 */  iRegI_rule,
  /*  402 */  iRegI_rule,
  /*  403 */  iRegI_rule,
  /*  404 */  iRegI_rule,
  /*  405 */  iRegI_rule,
  /*  406 */  iRegI_rule,
  /*  407 */  iRegI_rule,
  /*  408 */  _LShiftI_iRegI_iRegI_rule,
  /*  409 */  _LShiftI_iRegI_immU5_rule,
  /*  410 */  _RShiftI_iRegI_iRegI_rule,
  /*  411 */  _RShiftI_iRegI_immU5_rule,
  /*  412 */  _URShiftI_iRegI_iRegI_rule,
  /*  413 */  _URShiftI_iRegI_immU5_rule,
  /*  414 */  iRegI_rule,
  /*  415 */  iRegI_rule,
  /*  416 */  immIRot_rule,
  /*  417 */  iRegL_rule,
  /*  418 */  iRegL_rule,
  /*  419 */  immL0_rule,
  /*  420 */  iRegI_rule,
  /*  421 */  0,
  /*  422 */  0,
  /*  423 */  0,
  /*  424 */  iRegL_rule,
  /*  425 */  R0RegI_rule,
  /*  426 */  R2R3RegL_rule,
  /*  427 */  R0RegI_rule,
  /*  428 */  R2R3RegL_rule,
  /*  429 */  iRegI_rule,
  /*  430 */  iRegI_rule,
  /*  431 */  0,
  /*  432 */  0,
  /*  433 */  0,
  /*  434 */  iRegL_rule,
  /*  435 */  iRegL_rule,
  /*  436 */  iRegL_rule,
  /*  437 */  iRegI_rule,
  /*  438 */  iRegI_rule,
  /*  439 */  0,
  /*  440 */  0,
  /*  441 */  0,
  /*  442 */  iRegL_rule,
  /*  443 */  iRegL_rule,
  /*  444 */  iRegL_rule,
  /*  445 */  iRegI_rule,
  /*  446 */  iRegI_rule,
  /*  447 */  0,
  /*  448 */  0,
  /*  449 */  0,
  /*  450 */  iRegL_rule,
  /*  451 */  iRegL_rule,
  /*  452 */  iRegL_rule,
  /*  453 */  _CastP2X_iRegP__rule,
  /*  454 */  regF_rule,
  /*  455 */  regD_rule,
  /*  456 */  regF_rule,
  /*  457 */  regD_rule,
  /*  458 */  regF_rule,
  /*  459 */  regD_rule,
  /*  460 */  regF_rule,
  /*  461 */  regD_rule,
  /*  462 */  _SqrtD__ConvF2D_regF___rule,
  /*  463 */  regD_rule,
  /*  464 */  iRegI_rule,
  /*  465 */  iRegI_rule,
  /*  466 */  _LShiftI_iRegI_iRegI_rule,
  /*  467 */  iRegI_rule,
  /*  468 */  _LShiftI_iRegI_immU5_rule,
  /*  469 */  iRegI_rule,
  /*  470 */  _RShiftI_iRegI_iRegI_rule,
  /*  471 */  iRegI_rule,
  /*  472 */  _RShiftI_iRegI_immU5_rule,
  /*  473 */  iRegI_rule,
  /*  474 */  _URShiftI_iRegI_iRegI_rule,
  /*  475 */  iRegI_rule,
  /*  476 */  _URShiftI_iRegI_immU5_rule,
  /*  477 */  iRegI_rule,
  /*  478 */  iRegI_rule,
  /*  479 */  iRegL_rule,
  /*  480 */  iRegL_rule,
  /*  481 */  iRegI_rule,
  /*  482 */  iRegI_rule,
  /*  483 */  _LShiftI_iRegI_iRegI_rule,
  /*  484 */  iRegI_rule,
  /*  485 */  _LShiftI_iRegI_immU5_rule,
  /*  486 */  iRegI_rule,
  /*  487 */  _RShiftI_iRegI_iRegI_rule,
  /*  488 */  iRegI_rule,
  /*  489 */  _RShiftI_iRegI_immU5_rule,
  /*  490 */  iRegI_rule,
  /*  491 */  _URShiftI_iRegI_iRegI_rule,
  /*  492 */  iRegI_rule,
  /*  493 */  _URShiftI_iRegI_immU5_rule,
  /*  494 */  iRegI_rule,
  /*  495 */  iRegL_rule,
  /*  496 */  iRegL_rule,
  /*  497 */  iRegI_rule,
  /*  498 */  iRegI_rule,
  /*  499 */  _LShiftI_iRegI_iRegI_rule,
  /*  500 */  iRegI_rule,
  /*  501 */  _LShiftI_iRegI_immU5_rule,
  /*  502 */  iRegI_rule,
  /*  503 */  _RShiftI_iRegI_iRegI_rule,
  /*  504 */  iRegI_rule,
  /*  505 */  _RShiftI_iRegI_immU5_rule,
  /*  506 */  iRegI_rule,
  /*  507 */  _URShiftI_iRegI_iRegI_rule,
  /*  508 */  iRegI_rule,
  /*  509 */  _URShiftI_iRegI_immU5_rule,
  /*  510 */  iRegI_rule,
  /*  511 */  iRegL_rule,
  /*  512 */  iRegL_rule,
  /*  513 */  iRegI_rule,
  /*  514 */  iRegP_rule,
  /*  515 */  iRegI_rule,
  /*  516 */  iRegI_rule,
  /*  517 */  _AndI__CmpLTMask_iRegI_iRegI_iRegI_rule,
  /*  518 */  iRegI_rule,
  /*  519 */  _AndI_iRegI__CmpLTMask_iRegI_iRegI_rule,
  /*  520 */  iRegI_rule,
  /*  521 */  _AndI__CmpLTMask_iRegI_aimmI_iRegI_rule,
  /*  522 */  iRegI_rule,
  /*  523 */  _AndI_iRegI__CmpLTMask_iRegI_aimmI_rule,
  /*  524 */  iRegI_rule,
  /*  525 */  _AndI__CmpLTMask_iRegI_iRegI_iRegI_rule,
  /*  526 */  _SubI_iRegI_iRegI_rule,
  /*  527 */  _AndI_iRegI__CmpLTMask_iRegI_iRegI_rule,
  /*  528 */  _SubI_iRegI_iRegI_rule,
  /*  529 */  regD_rule,
  /*  530 */  regD_rule,
  /*  531 */  regD_rule,
  /*  532 */  regF_rule,
  /*  533 */  regF_rule,
  /*  534 */  regF_rule,
  /*  535 */  iRegI_rule,
  /*  536 */  iRegI_rule,
  /*  537 */  iRegI_rule,
  /*  538 */  _ConvI2L_iRegI__rule,
  /*  539 */  iRegL_rule,
  /*  540 */  0,
  /*  541 */  0,
  /*  542 */  0,
  /*  543 */  0,
  /*  544 */  0,
  /*  545 */  0,
  /*  546 */  0,
  /*  547 */  0,
  /*  548 */  iRegL_rule,
  /*  549 */  iRegL_rule,
  /*  550 */  _RShiftL_iRegL_immI_32_63_rule,
  /*  551 */  0,
  /*  552 */  iRegI_rule,
  /*  553 */  0,
  /*  554 */  iRegI_rule,
  /*  555 */  regF_rule,
  /*  556 */  regF_rule,
  /*  557 */  regD_rule,
  /*  558 */  regD_rule,
  /*  559 */  iRegI_rule,
  /*  560 */  0,
  /*  561 */  cmpOp_rule,
  /*  562 */  cmpOp0_rule,
  /*  563 */  cmpOpU_rule,
  /*  564 */  cmpOpP_rule,
  /*  565 */  cmpOpL_rule,
  /*  566 */  cmpOpL_rule,
  /*  567 */  cmpOpL_commute_rule,
  /*  568 */  cmpOp_rule,
  /*  569 */  iRegL_rule,
  /*  570 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  571 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  572 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  573 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  574 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  575 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  576 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  577 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  578 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  579 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  580 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  581 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  582 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  583 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  584 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  585 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  586 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  587 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  588 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  589 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  590 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  591 */  _Binary_cmpOpL_flagsRegL_LTGE_rule,
  /*  592 */  _Binary_cmpOpL_flagsRegL_EQNE_rule,
  /*  593 */  _Binary_cmpOpL_commute_flagsRegL_LEGT_rule,
  /*  594 */  iRegP_rule,
  /*  595 */  0,
  /*  596 */  0,
  /*  597 */  0,
  /*  598 */  0,
  /*  599 */  0,
  /*  600 */  0,
  /*  601 */  IPRegP_rule,
  /*  602 */  0,
  /*  603 */  IPRegP_rule,
  /*  604 */  0,
  /*  605 */  0,
  /*  606 */  0,
  /*  607 */  R1RegP_rule,
  /*  608 */  iRegI_rule,
  /*  609 */  iRegL_rule,
  /*  610 */  iRegI_rule,
  /*  611 */  iRegL_rule,
  /*  612 */  iRegI_rule,
  /*  613 */  iRegL_rule,
  /*  614 */  iRegI_rule,
  /*  615 */  iRegL_rule,
  /*  616 */  iRegI_rule,
  /*  617 */  iRegI_rule,
  /*  618 */  memoryD_rule,
  /*  619 */  memoryvld_rule,
  /*  620 */  memoryD_rule,
  /*  621 */  memoryvld_rule,
  /*  622 */  iRegI_rule,
  /*  623 */  iRegI_rule,
  /*  624 */  iRegI_rule,
  /*  625 */  immI_rule,
  /*  626 */  immU8_rule,
  /*  627 */  immU8_rule,
  /*  628 */  iRegI_rule,
  /*  629 */  iRegI_rule,
  /*  630 */  iRegI_rule,
  /*  631 */  immI_rule,
  /*  632 */  immU8_rule,
  /*  633 */  immU8_rule,
  /*  634 */  iRegI_rule,
  /*  635 */  iRegI_rule,
  /*  636 */  iRegI_rule,
  /*  637 */  iRegI_rule,
  /*  638 */  immI_rule,
  /*  639 */  immU8_rule,
  /*  640 */  immU8_rule,
  /*  641 */  iRegL_rule,
  /*  642 */  iRegI_rule,
  /*  643 */  regF_rule,
  /*  644 */  regF_rule,
  /*  645 */  regF_rule,
  /*  646 */  regF_rule,
  /*  647 */  immF_rule,
  /*  648 */  regD_rule,
  /*  649 */  vecD_rule,
  /*  650 */  vecX_rule,
  /*  651 */  vecD_rule,
  /*  652 */  vecX_rule,
  /*  653 */  vecD_rule,
  /*  654 */  vecX_rule,
  /*  655 */  vecX_rule,
  /*  656 */  vecD_rule,
  /*  657 */  vecD_rule,
  /*  658 */  vecX_rule,
  /*  659 */  vecX_rule,
  /*  660 */  vecX_rule,
  /*  661 */  vecD_rule,
  /*  662 */  vecX_rule,
  /*  663 */  vecD_rule,
  /*  664 */  vecX_rule,
  /*  665 */  vecD_rule,
  /*  666 */  vecX_rule,
  /*  667 */  vecX_rule,
  /*  668 */  vecD_rule,
  /*  669 */  vecD_rule,
  /*  670 */  vecX_rule,
  /*  671 */  vecX_rule,
  /*  672 */  vecX_rule,
  /*  673 */  vecD_rule,
  /*  674 */  vecX_rule,
  /*  675 */  vecD_rule,
  /*  676 */  vecX_rule,
  /*  677 */  vecD_rule,
  /*  678 */  vecD_rule,
  /*  679 */  vecX_rule,
  /*  680 */  vecX_rule,
  /*  681 */  vecX_rule,
  /*  682 */  vecD_rule,
  /*  683 */  vecX_rule,
  /*  684 */  vecX_rule,
  /*  685 */  0,
  /*  686 */  0,
  /*  687 */  0,
  /*  688 */  0,
  /*  689 */  0,
  /*  690 */  0,
  /*  691 */  0,
  /*  692 */  vecD_rule,
  /*  693 */  vecX_rule,
  /*  694 */  vecD_rule,
  /*  695 */  vecX_rule,
  /*  696 */  vecD_rule,
  /*  697 */  vecD_rule,
  /*  698 */  vecX_rule,
  /*  699 */  vecX_rule,
  /*  700 */  vecD_rule,
  /*  701 */  vecX_rule,
  /*  702 */  vecD_rule,
  /*  703 */  vecD_rule,
  /*  704 */  vecX_rule,
  /*  705 */  vecX_rule,
  /*  706 */  vecD_rule,
  /*  707 */  vecX_rule,
  /*  708 */  vecX_rule,
  /*  709 */  vecX_rule,
  /*  710 */  vecX_rule,
  /*  711 */  vecD_rule,
  /*  712 */  vecX_rule,
  /*  713 */  vecD_rule,
  /*  714 */  vecX_rule,
  /*  715 */  vecX_rule,
  /*  716 */  0,
  /*  717 */  0,
  /*  718 */  0,
  /*  719 */  0,
  /*  720 */  0,
  /*  721 */  0,
  /*  722 */  0,
  /*  723 */  vecD_rule,
  /*  724 */  vecX_rule,
  /*  725 */  vecD_rule,
  /*  726 */  vecX_rule,
  /*  727 */  vecD_rule,
  /*  728 */  vecX_rule,
  /*  729 */  vecD_rule,
  /*  730 */  vecX_rule,
  /*  731 */  vecD_rule,
  /*  732 */  vecX_rule,
  /*  733 */  vecD_rule,
  /*  734 */  vecX_rule,
  /*  735 */  vecX_rule,
  /*  736 */  vecX_rule,
  /*  737 */  vecD_rule,
  /*  738 */  vecX_rule,
  /*  739 */  vecD_rule,
  /*  740 */  vecX_rule,
  /*  741 */  vecD_rule,
  /*  742 */  vecX_rule,
  // last instruction
  0 // no trailing comma
};

const        int   rightOp[] = {
  /*    0 */  0,
  /*    1 */  0,
  /*    2 */  0,
  /*    3 */  0,
  /*    4 */  0,
  /*    5 */  0,
  /*    6 */  0,
  /*    7 */  0,
  /*    8 */  0,
  /*    9 */  0,
  /*   10 */  0,
  /*   11 */  0,
  /*   12 */  0,
  /*   13 */  0,
  /*   14 */  0,
  /*   15 */  0,
  /*   16 */  0,
  /*   17 */  0,
  /*   18 */  0,
  /*   19 */  0,
  /*   20 */  0,
  /*   21 */  0,
  /*   22 */  0,
  /*   23 */  0,
  /*   24 */  0,
  /*   25 */  0,
  /*   26 */  0,
  /*   27 */  0,
  /*   28 */  0,
  /*   29 */  0,
  /*   30 */  0,
  /*   31 */  0,
  /*   32 */  0,
  /*   33 */  0,
  /*   34 */  0,
  /*   35 */  0,
  /*   36 */  0,
  /*   37 */  0,
  /*   38 */  0,
  /*   39 */  0,
  /*   40 */  0,
  /*   41 */  0,
  /*   42 */  0,
  /*   43 */  0,
  /*   44 */  0,
  /*   45 */  0,
  /*   46 */  0,
  /*   47 */  0,
  /*   48 */  0,
  /*   49 */  0,
  /*   50 */  0,
  /*   51 */  0,
  /*   52 */  0,
  /*   53 */  0,
  /*   54 */  0,
  /*   55 */  0,
  /*   56 */  0,
  /*   57 */  0,
  /*   58 */  0,
  /*   59 */  0,
  /*   60 */  0,
  /*   61 */  0,
  /*   62 */  0,
  /*   63 */  0,
  /*   64 */  0,
  /*   65 */  0,
  /*   66 */  0,
  /*   67 */  0,
  /*   68 */  0,
  /*   69 */  0,
  /*   70 */  0,
  /*   71 */  0,
  /*   72 */  0,
  /*   73 */  0,
  /*   74 */  0,
  /*   75 */  0,
  /*   76 */  0,
  /*   77 */  0,
  /*   78 */  0,
  /*   79 */  0,
  /*   80 */  0,
  /*   81 */  0,
  /*   82 */  0,
  /*   83 */  0,
  /*   84 */  0,
  /*   85 */  0,
  /*   86 */  0,
  /*   87 */  0,
  /*   88 */  0,
  /*   89 */  0,
  /*   90 */  0,
  /*   91 */  0,
  /*   92 */  0,
  /*   93 */  0,
  /*   94 */  0,
  /*   95 */  0,
  /*   96 */  0,
  /*   97 */  immI12_rule,
  /*   98 */  immIFP_rule,
  /*   99 */  immIHD_rule,
  /*  100 */  immI10x2_rule,
  /*  101 */  immI12x2_rule,
  /*  102 */  iRegI_rule,
  /*  103 */  _LShiftI_iRegI_immU5_rule,
  /*  104 */  0,
  /*  105 */  0,
  /*  106 */  0,
  /*  107 */  0,
  /*  108 */  0,
  /*  109 */  0,
  /*  110 */  immU5_rule,
  // last operand
  /*  111 */  0,
  /*  112 */  0,
  /*  113 */  0,
  /*  114 */  0,
  /*  115 */  0,
  /*  116 */  0,
  /*  117 */  0,
  /*  118 */  0,
  /*  119 */  0,
  /*  120 */  0,
  /*  121 */  0,
  /*  122 */  0,
  /*  123 */  0,
  /*  124 */  0,
  /*  125 */  0,
  // last operand class
  /*  126 */  immU5_rule,
  /*  127 */  0,
  /*  128 */  0,
  /*  129 */  limmIlow8_rule,
  /*  130 */  0,
  /*  131 */  immI_24_rule,
  /*  132 */  0,
  /*  133 */  immI_24_rule,
  /*  134 */  0,
  /*  135 */  immI_255_rule,
  /*  136 */  limmI_rule,
  /*  137 */  0,
  /*  138 */  immI_24_rule,
  /*  139 */  0,
  /*  140 */  immI_16_rule,
  /*  141 */  0,
  /*  142 */  immI_255_rule,
  /*  143 */  immI_65535_rule,
  /*  144 */  limmU31_rule,
  /*  145 */  immU31_rule,
  /*  146 */  0,
  /*  147 */  flagsRegP_rule,
  /*  148 */  iRegI_rule,
  /*  149 */  immIRot_rule,
  /*  150 */  immI16_rule,
  /*  151 */  flagsReg_rule,
  /*  152 */  flagsReg_EQNELTGE_rule,
  /*  153 */  flagsRegU_rule,
  /*  154 */  iRegP_rule,
  /*  155 */  immP0_rule,
  /*  156 */  regF_rule,
  /*  157 */  regD_rule,
  /*  158 */  iRegL_rule,
  /*  159 */  immLlowRot_rule,
  /*  160 */  immL16_rule,
  /*  161 */  iRegI_rule,
  /*  162 */  iRegI_rule,
  /*  163 */  immU5_rule,
  /*  164 */  iRegI_rule,
  /*  165 */  immU5_rule,
  /*  166 */  iRegLd_rule,
  /*  167 */  0,
  /*  168 */  0,
  /*  169 */  0,
  /*  170 */  iRegI_rule,
  /*  171 */  iRegI_rule,
  /*  172 */  _CmpLTMask_iRegI_iRegI_rule,
  /*  173 */  aimmI_rule,
  /*  174 */  iRegI_rule,
  /*  175 */  _CmpLTMask_iRegI_aimmI_rule,
  /*  176 */  iRegI_rule,
  /*  177 */  0,
  /*  178 */  immI_32_63_rule,
  /*  179 */  iRegI_rule,
  /*  180 */  _LShiftI_iRegI_iRegI_rule,
  /*  181 */  iRegI_rule,
  /*  182 */  _LShiftI_iRegI_immU5_rule,
  /*  183 */  iRegI_rule,
  /*  184 */  _RShiftI_iRegI_iRegI_rule,
  /*  185 */  iRegI_rule,
  /*  186 */  _RShiftI_iRegI_immU5_rule,
  /*  187 */  iRegI_rule,
  /*  188 */  _URShiftI_iRegI_iRegI_rule,
  /*  189 */  iRegI_rule,
  /*  190 */  _URShiftI_iRegI_immU5_rule,
  /*  191 */  iRegI_rule,
  /*  192 */  limmI_rule,
  /*  193 */  flagsRegL_LTGE_rule,
  /*  194 */  flagsRegL_EQNE_rule,
  /*  195 */  flagsRegL_LEGT_rule,
  /*  196 */  immL0_rule,
  // last internally defined operand
  /*  197 */  0,
  /*  198 */  0,
  /*  199 */  0,
  /*  200 */  0,
  /*  201 */  0,
  /*  202 */  0,
  /*  203 */  0,
  /*  204 */  0,
  /*  205 */  0,
  /*  206 */  0,
  /*  207 */  0,
  /*  208 */  0,
  /*  209 */  0,
  /*  210 */  0,
  /*  211 */  0,
  /*  212 */  0,
  /*  213 */  0,
  /*  214 */  0,
  /*  215 */  _Binary_iRegP_iRegP_rule,
  /*  216 */  _Binary_iRegI_iRegI_rule,
  /*  217 */  0,
  /*  218 */  0,
  /*  219 */  0,
  /*  220 */  0,
  /*  221 */  0,
  /*  222 */  0,
  /*  223 */  0,
  /*  224 */  0,
  /*  225 */  0,
  /*  226 */  0,
  /*  227 */  iRegI_rule,
  /*  228 */  iRegI_rule,
  /*  229 */  aimmIneg_rule,
  /*  230 */  aimmI_rule,
  /*  231 */  immI0_rule,
  /*  232 */  immI0_rule,
  /*  233 */  immI0_rule,
  /*  234 */  immI0_rule,
  /*  235 */  immI0_rule,
  /*  236 */  immI0_rule,
  /*  237 */  immI0_rule,
  /*  238 */  immI0_rule,
  /*  239 */  immI0_rule,
  /*  240 */  immI0_rule,
  /*  241 */  immI0_rule,
  /*  242 */  immI0_rule,
  /*  243 */  immI0_rule,
  /*  244 */  immI0_rule,
  /*  245 */  iRegL_rule,
  /*  246 */  iRegL_rule,
  /*  247 */  iRegL_rule,
  /*  248 */  immLlowRot_rule,
  /*  249 */  immLlowRot_rule,
  /*  250 */  immLlowRot_rule,
  /*  251 */  aimmU31_rule,
  /*  252 */  iRegP_rule,
  /*  253 */  immPRot_rule,
  /*  254 */  regF_rule,
  /*  255 */  immF0_rule,
  /*  256 */  regD_rule,
  /*  257 */  immD0_rule,
  /*  258 */  iRegP_rule,
  /*  259 */  iRegP_rule,
  /*  260 */  0,
  /*  261 */  0,
  /*  262 */  0,
  /*  263 */  0,
  /*  264 */  0,
  /*  265 */  0,
  /*  266 */  0,
  /*  267 */  0,
  /*  268 */  0,
  /*  269 */  0,
  /*  270 */  0,
  /*  271 */  0,
  /*  272 */  0,
  /*  273 */  0,
  /*  274 */  0,
  /*  275 */  0,
  /*  276 */  0,
  /*  277 */  0,
  /*  278 */  immI_24_rule,
  /*  279 */  0,
  /*  280 */  0,
  /*  281 */  immI_24_rule,
  /*  282 */  0,
  /*  283 */  0,
  /*  284 */  0,
  /*  285 */  0,
  /*  286 */  immI_24_rule,
  /*  287 */  immI_255_rule,
  /*  288 */  immI_16_rule,
  /*  289 */  immI_65535_rule,
  /*  290 */  0,
  /*  291 */  0,
  /*  292 */  0,
  /*  293 */  0,
  /*  294 */  0,
  /*  295 */  immL_32bits_rule,
  /*  296 */  0,
  /*  297 */  0,
  /*  298 */  0,
  /*  299 */  0,
  /*  300 */  0,
  /*  301 */  0,
  /*  302 */  0,
  /*  303 */  0,
  /*  304 */  0,
  /*  305 */  0,
  /*  306 */  0,
  /*  307 */  0,
  /*  308 */  0,
  /*  309 */  iRegI_rule,
  /*  310 */  iRegI_rule,
  /*  311 */  iRegI_rule,
  /*  312 */  iRegI_rule,
  /*  313 */  iRegLd_rule,
  /*  314 */  iRegL_rule,
  /*  315 */  iRegL_rule,
  /*  316 */  iRegL_rule,
  /*  317 */  iRegP_rule,
  /*  318 */  regD_rule,
  /*  319 */  regF_rule,
  /*  320 */  0,
  /*  321 */  0,
  /*  322 */  0,
  /*  323 */  0,
  /*  324 */  0,
  /*  325 */  0,
  /*  326 */  0,
  /*  327 */  0,
  /*  328 */  0,
  /*  329 */  _Binary_iRegI_iRegI_rule,
  /*  330 */  _Binary_iRegI_immIRot_rule,
  /*  331 */  _Binary_iRegI_immI16_rule,
  /*  332 */  _Binary_iRegI_iRegI_rule,
  /*  333 */  _Binary_iRegI_immIRot_rule,
  /*  334 */  _Binary_iRegI_immI16_rule,
  /*  335 */  _Binary_iRegI_iRegI_rule,
  /*  336 */  _Binary_iRegI_immIRot_rule,
  /*  337 */  _Binary_iRegI_immI16_rule,
  /*  338 */  _Binary_iRegI_iRegI_rule,
  /*  339 */  _Binary_iRegI_immIRot_rule,
  /*  340 */  _Binary_iRegI_immI16_rule,
  /*  341 */  _Binary_iRegP_iRegP_rule,
  /*  342 */  _Binary_iRegP_immP0_rule,
  /*  343 */  _Binary_iRegP_iRegP_rule,
  /*  344 */  _Binary_iRegP_iRegP_rule,
  /*  345 */  _Binary_iRegP_iRegP_rule,
  /*  346 */  _Binary_iRegP_immP0_rule,
  /*  347 */  _Binary_iRegP_immP0_rule,
  /*  348 */  _Binary_iRegP_immP0_rule,
  /*  349 */  _Binary_regF_regF_rule,
  /*  350 */  _Binary_regF_regF_rule,
  /*  351 */  _Binary_regF_regF_rule,
  /*  352 */  _Binary_regF_regF_rule,
  /*  353 */  _Binary_regD_regD_rule,
  /*  354 */  _Binary_regD_regD_rule,
  /*  355 */  _Binary_regD_regD_rule,
  /*  356 */  _Binary_regD_regD_rule,
  /*  357 */  _Binary_iRegL_iRegL_rule,
  /*  358 */  _Binary_iRegL_immLlowRot_rule,
  /*  359 */  _Binary_iRegL_immL16_rule,
  /*  360 */  _Binary_iRegL_iRegL_rule,
  /*  361 */  _Binary_iRegL_iRegL_rule,
  /*  362 */  _Binary_iRegL_immLlowRot_rule,
  /*  363 */  _Binary_iRegL_immLlowRot_rule,
  /*  364 */  _Binary_iRegL_immL16_rule,
  /*  365 */  _Binary_iRegL_immL16_rule,
  /*  366 */  _Binary_iRegL_iRegL_rule,
  /*  367 */  iRegI_rule,
  /*  368 */  iRegI_rule,
  /*  369 */  _LShiftI_iRegI_iRegI_rule,
  /*  370 */  iRegI_rule,
  /*  371 */  _LShiftI_iRegI_immU5_rule,
  /*  372 */  iRegI_rule,
  /*  373 */  _RShiftI_iRegI_iRegI_rule,
  /*  374 */  iRegI_rule,
  /*  375 */  _RShiftI_iRegI_immU5_rule,
  /*  376 */  iRegI_rule,
  /*  377 */  _URShiftI_iRegI_iRegI_rule,
  /*  378 */  iRegI_rule,
  /*  379 */  _URShiftI_iRegI_immU5_rule,
  /*  380 */  aimmI_rule,
  /*  381 */  iRegI_rule,
  /*  382 */  shiftedX_rule,
  /*  383 */  aimmI_rule,
  /*  384 */  iRegL_rule,
  /*  385 */  immLlowRot_rule,
  /*  386 */  0,
  /*  387 */  _Binary_iRegL_iRegLd_rule,
  /*  388 */  _Binary_iRegI_iRegI_rule,
  /*  389 */  _Binary_iRegP_iRegP_rule,
  /*  390 */  aimmI_rule,
  /*  391 */  iRegI_rule,
  /*  392 */  aimmI_rule,
  /*  393 */  iRegI_rule,
  /*  394 */  iRegL_rule,
  /*  395 */  immLlowRot_rule,
  /*  396 */  iRegL_rule,
  /*  397 */  immLlowRot_rule,
  /*  398 */  iRegI_rule,
  /*  399 */  iRegLd_rule,
  /*  400 */  iRegP_rule,
  /*  401 */  iRegI_rule,
  /*  402 */  _LShiftI_iRegI_iRegI_rule,
  /*  403 */  _LShiftI_iRegI_immU5_rule,
  /*  404 */  _RShiftI_iRegI_iRegI_rule,
  /*  405 */  _RShiftI_iRegI_immU5_rule,
  /*  406 */  _URShiftI_iRegI_iRegI_rule,
  /*  407 */  _URShiftI_iRegI_immU5_rule,
  /*  408 */  iRegI_rule,
  /*  409 */  iRegI_rule,
  /*  410 */  iRegI_rule,
  /*  411 */  iRegI_rule,
  /*  412 */  iRegI_rule,
  /*  413 */  iRegI_rule,
  /*  414 */  aimmI_rule,
  /*  415 */  aimmIneg_rule,
  /*  416 */  iRegI_rule,
  /*  417 */  iRegL_rule,
  /*  418 */  immLlowRot_rule,
  /*  419 */  iRegL_rule,
  /*  420 */  iRegI_rule,
  /*  421 */  0,
  /*  422 */  0,
  /*  423 */  0,
  /*  424 */  iRegL_rule,
  /*  425 */  R2RegI_rule,
  /*  426 */  R0R1RegL_rule,
  /*  427 */  R2RegI_rule,
  /*  428 */  R0R1RegL_rule,
  /*  429 */  iRegI_rule,
  /*  430 */  immU5_rule,
  /*  431 */  0,
  /*  432 */  0,
  /*  433 */  0,
  /*  434 */  iRegI_rule,
  /*  435 */  immU6Big_rule,
  /*  436 */  immU5_rule,
  /*  437 */  iRegI_rule,
  /*  438 */  immU5_rule,
  /*  439 */  0,
  /*  440 */  0,
  /*  441 */  0,
  /*  442 */  iRegI_rule,
  /*  443 */  immU6Big_rule,
  /*  444 */  immU5_rule,
  /*  445 */  iRegI_rule,
  /*  446 */  immU5_rule,
  /*  447 */  0,
  /*  448 */  0,
  /*  449 */  0,
  /*  450 */  iRegI_rule,
  /*  451 */  immU6Big_rule,
  /*  452 */  immU5_rule,
  /*  453 */  immU5_rule,
  /*  454 */  regF_rule,
  /*  455 */  regD_rule,
  /*  456 */  regF_rule,
  /*  457 */  regD_rule,
  /*  458 */  regF_rule,
  /*  459 */  regD_rule,
  /*  460 */  regF_rule,
  /*  461 */  regD_rule,
  /*  462 */  0,
  /*  463 */  0,
  /*  464 */  iRegI_rule,
  /*  465 */  _LShiftI_iRegI_iRegI_rule,
  /*  466 */  iRegI_rule,
  /*  467 */  _LShiftI_iRegI_immU5_rule,
  /*  468 */  iRegI_rule,
  /*  469 */  _RShiftI_iRegI_iRegI_rule,
  /*  470 */  iRegI_rule,
  /*  471 */  _RShiftI_iRegI_immU5_rule,
  /*  472 */  iRegI_rule,
  /*  473 */  _URShiftI_iRegI_iRegI_rule,
  /*  474 */  iRegI_rule,
  /*  475 */  _URShiftI_iRegI_immU5_rule,
  /*  476 */  iRegI_rule,
  /*  477 */  limmI_rule,
  /*  478 */  limmIn_rule,
  /*  479 */  iRegL_rule,
  /*  480 */  immLlowRot_rule,
  /*  481 */  iRegI_rule,
  /*  482 */  _LShiftI_iRegI_iRegI_rule,
  /*  483 */  iRegI_rule,
  /*  484 */  _LShiftI_iRegI_immU5_rule,
  /*  485 */  iRegI_rule,
  /*  486 */  _RShiftI_iRegI_iRegI_rule,
  /*  487 */  iRegI_rule,
  /*  488 */  _RShiftI_iRegI_immU5_rule,
  /*  489 */  iRegI_rule,
  /*  490 */  _URShiftI_iRegI_iRegI_rule,
  /*  491 */  iRegI_rule,
  /*  492 */  _URShiftI_iRegI_immU5_rule,
  /*  493 */  iRegI_rule,
  /*  494 */  limmI_rule,
  /*  495 */  iRegL_rule,
  /*  496 */  immLlowRot_rule,
  /*  497 */  iRegI_rule,
  /*  498 */  _LShiftI_iRegI_iRegI_rule,
  /*  499 */  iRegI_rule,
  /*  500 */  _LShiftI_iRegI_immU5_rule,
  /*  501 */  iRegI_rule,
  /*  502 */  _RShiftI_iRegI_iRegI_rule,
  /*  503 */  iRegI_rule,
  /*  504 */  _RShiftI_iRegI_immU5_rule,
  /*  505 */  iRegI_rule,
  /*  506 */  _URShiftI_iRegI_iRegI_rule,
  /*  507 */  iRegI_rule,
  /*  508 */  _URShiftI_iRegI_immU5_rule,
  /*  509 */  iRegI_rule,
  /*  510 */  limmI_rule,
  /*  511 */  iRegL_rule,
  /*  512 */  immLlowRot_rule,
  /*  513 */  0,
  /*  514 */  0,
  /*  515 */  iRegI_rule,
  /*  516 */  aimmI_rule,
  /*  517 */  iRegI_rule,
  /*  518 */  _AndI__CmpLTMask_iRegI_iRegI_iRegI_rule,
  /*  519 */  iRegI_rule,
  /*  520 */  _AndI_iRegI__CmpLTMask_iRegI_iRegI_rule,
  /*  521 */  iRegI_rule,
  /*  522 */  _AndI__CmpLTMask_iRegI_aimmI_iRegI_rule,
  /*  523 */  iRegI_rule,
  /*  524 */  _AndI_iRegI__CmpLTMask_iRegI_aimmI_rule,
  /*  525 */  _SubI_iRegI_iRegI_rule,
  /*  526 */  _AndI__CmpLTMask_iRegI_iRegI_iRegI_rule,
  /*  527 */  _SubI_iRegI_iRegI_rule,
  /*  528 */  _AndI_iRegI__CmpLTMask_iRegI_iRegI_rule,
  /*  529 */  0,
  /*  530 */  0,
  /*  531 */  0,
  /*  532 */  0,
  /*  533 */  0,
  /*  534 */  0,
  /*  535 */  0,
  /*  536 */  0,
  /*  537 */  0,
  /*  538 */  immL_32bits_rule,
  /*  539 */  immL_32bits_rule,
  /*  540 */  0,
  /*  541 */  0,
  /*  542 */  0,
  /*  543 */  0,
  /*  544 */  0,
  /*  545 */  0,
  /*  546 */  0,
  /*  547 */  0,
  /*  548 */  0,
  /*  549 */  0,
  /*  550 */  0,
  /*  551 */  0,
  /*  552 */  iRegI_rule,
  /*  553 */  0,
  /*  554 */  iRegI_rule,
  /*  555 */  regF_rule,
  /*  556 */  immF0_rule,
  /*  557 */  regD_rule,
  /*  558 */  immD0_rule,
  /*  559 */  0,
  /*  560 */  0,
  /*  561 */  flagsReg_rule,
  /*  562 */  flagsReg_EQNELTGE_rule,
  /*  563 */  flagsRegU_rule,
  /*  564 */  flagsRegP_rule,
  /*  565 */  flagsRegL_LTGE_rule,
  /*  566 */  flagsRegL_EQNE_rule,
  /*  567 */  flagsRegL_LEGT_rule,
  /*  568 */  flagsReg_rule,
  /*  569 */  iRegL_rule,
  /*  570 */  _Binary_iRegL_iRegL_rule,
  /*  571 */  _Binary_iRegL_iRegL_rule,
  /*  572 */  _Binary_iRegL_iRegL_rule,
  /*  573 */  _Binary_iRegL_immL0_rule,
  /*  574 */  _Binary_iRegL_immL0_rule,
  /*  575 */  _Binary_iRegL_immL0_rule,
  /*  576 */  _Binary_iRegI_iRegI_rule,
  /*  577 */  _Binary_iRegI_iRegI_rule,
  /*  578 */  _Binary_iRegI_iRegI_rule,
  /*  579 */  _Binary_iRegI_immI16_rule,
  /*  580 */  _Binary_iRegI_immI16_rule,
  /*  581 */  _Binary_iRegI_immI16_rule,
  /*  582 */  _Binary_iRegP_iRegP_rule,
  /*  583 */  _Binary_iRegP_iRegP_rule,
  /*  584 */  _Binary_iRegP_iRegP_rule,
  /*  585 */  _Binary_iRegP_immP0_rule,
  /*  586 */  _Binary_iRegP_immP0_rule,
  /*  587 */  _Binary_iRegP_immP0_rule,
  /*  588 */  _Binary_regF_regF_rule,
  /*  589 */  _Binary_regF_regF_rule,
  /*  590 */  _Binary_regF_regF_rule,
  /*  591 */  _Binary_regD_regD_rule,
  /*  592 */  _Binary_regD_regD_rule,
  /*  593 */  _Binary_regD_regD_rule,
  /*  594 */  0,
  /*  595 */  0,
  /*  596 */  0,
  /*  597 */  0,
  /*  598 */  0,
  /*  599 */  0,
  /*  600 */  0,
  /*  601 */  inline_cache_regP_rule,
  /*  602 */  0,
  /*  603 */  RExceptionRegP_rule,
  /*  604 */  0,
  /*  605 */  0,
  /*  606 */  0,
  /*  607 */  R2RegP_rule,
  /*  608 */  iRegP_rule,
  /*  609 */  0,
  /*  610 */  0,
  /*  611 */  0,
  /*  612 */  0,
  /*  613 */  0,
  /*  614 */  0,
  /*  615 */  0,
  /*  616 */  0,
  /*  617 */  0,
  /*  618 */  0,
  /*  619 */  0,
  /*  620 */  vecD_rule,
  /*  621 */  vecX_rule,
  /*  622 */  0,
  /*  623 */  0,
  /*  624 */  0,
  /*  625 */  0,
  /*  626 */  0,
  /*  627 */  0,
  /*  628 */  0,
  /*  629 */  0,
  /*  630 */  0,
  /*  631 */  0,
  /*  632 */  0,
  /*  633 */  0,
  /*  634 */  0,
  /*  635 */  0,
  /*  636 */  0,
  /*  637 */  0,
  /*  638 */  0,
  /*  639 */  0,
  /*  640 */  0,
  /*  641 */  0,
  /*  642 */  0,
  /*  643 */  0,
  /*  644 */  0,
  /*  645 */  0,
  /*  646 */  0,
  /*  647 */  0,
  /*  648 */  0,
  /*  649 */  vecD_rule,
  /*  650 */  vecX_rule,
  /*  651 */  vecD_rule,
  /*  652 */  vecX_rule,
  /*  653 */  vecD_rule,
  /*  654 */  vecX_rule,
  /*  655 */  vecX_rule,
  /*  656 */  vecD_rule,
  /*  657 */  vecD_rule,
  /*  658 */  vecX_rule,
  /*  659 */  vecX_rule,
  /*  660 */  vecX_rule,
  /*  661 */  vecD_rule,
  /*  662 */  vecX_rule,
  /*  663 */  vecD_rule,
  /*  664 */  vecX_rule,
  /*  665 */  vecD_rule,
  /*  666 */  vecX_rule,
  /*  667 */  vecX_rule,
  /*  668 */  vecD_rule,
  /*  669 */  vecD_rule,
  /*  670 */  vecX_rule,
  /*  671 */  vecX_rule,
  /*  672 */  vecX_rule,
  /*  673 */  vecD_rule,
  /*  674 */  vecX_rule,
  /*  675 */  vecD_rule,
  /*  676 */  vecX_rule,
  /*  677 */  vecD_rule,
  /*  678 */  vecD_rule,
  /*  679 */  vecX_rule,
  /*  680 */  vecX_rule,
  /*  681 */  vecX_rule,
  /*  682 */  vecD_rule,
  /*  683 */  vecX_rule,
  /*  684 */  vecX_rule,
  /*  685 */  0,
  /*  686 */  0,
  /*  687 */  0,
  /*  688 */  0,
  /*  689 */  0,
  /*  690 */  0,
  /*  691 */  0,
  /*  692 */  vecD_rule,
  /*  693 */  vecX_rule,
  /*  694 */  immI_rule,
  /*  695 */  immI_rule,
  /*  696 */  vecD_rule,
  /*  697 */  vecD_rule,
  /*  698 */  vecX_rule,
  /*  699 */  vecX_rule,
  /*  700 */  immI_rule,
  /*  701 */  immI_rule,
  /*  702 */  vecD_rule,
  /*  703 */  vecD_rule,
  /*  704 */  vecX_rule,
  /*  705 */  vecX_rule,
  /*  706 */  immI_rule,
  /*  707 */  immI_rule,
  /*  708 */  vecX_rule,
  /*  709 */  vecX_rule,
  /*  710 */  immI_rule,
  /*  711 */  immI_rule,
  /*  712 */  immI_rule,
  /*  713 */  immI_rule,
  /*  714 */  immI_rule,
  /*  715 */  immI_rule,
  /*  716 */  0,
  /*  717 */  0,
  /*  718 */  0,
  /*  719 */  0,
  /*  720 */  0,
  /*  721 */  0,
  /*  722 */  0,
  /*  723 */  vecD_rule,
  /*  724 */  vecX_rule,
  /*  725 */  immI_rule,
  /*  726 */  immI_rule,
  /*  727 */  vecD_rule,
  /*  728 */  vecX_rule,
  /*  729 */  immI_rule,
  /*  730 */  immI_rule,
  /*  731 */  vecD_rule,
  /*  732 */  vecX_rule,
  /*  733 */  immI_rule,
  /*  734 */  immI_rule,
  /*  735 */  vecX_rule,
  /*  736 */  immI_rule,
  /*  737 */  vecD_rule,
  /*  738 */  vecX_rule,
  /*  739 */  vecD_rule,
  /*  740 */  vecX_rule,
  /*  741 */  vecD_rule,
  /*  742 */  vecX_rule,
  // last instruction
  0 // no trailing comma
};

const char        *ruleName[] = {
  /*    0 */  "UNIVERSE",
  /*    1 */  "LABEL",
  /*    2 */  "SREGI",
  /*    3 */  "SREGP",
  /*    4 */  "SREGF",
  /*    5 */  "SREGD",
  /*    6 */  "SREGL",
  /*    7 */  "METHOD",
  /*    8 */  "IMMIROT",
  /*    9 */  "IMMIROTN",
  /*   10 */  "IMMIROTNEG",
  /*   11 */  "IMMU31ROT",
  /*   12 */  "IMMPROT",
  /*   13 */  "IMMLLOWROT",
  /*   14 */  "IMMLROT2",
  /*   15 */  "IMMI12",
  /*   16 */  "IMMI10X2",
  /*   17 */  "IMMI12X2",
  /*   18 */  "IMMI",
  /*   19 */  "IMMU8",
  /*   20 */  "IMMI16",
  /*   21 */  "IMMIHD",
  /*   22 */  "IMMIFP",
  /*   23 */  "IMMU5",
  /*   24 */  "IMMU6BIG",
  /*   25 */  "IMMI0",
  /*   26 */  "IMMI_1",
  /*   27 */  "IMMI_2",
  /*   28 */  "IMMI_3",
  /*   29 */  "IMMI_4",
  /*   30 */  "IMMI_8",
  /*   31 */  "IMMU31",
  /*   32 */  "IMMI_32_63",
  /*   33 */  "IMMI_16",
  /*   34 */  "IMMI_24",
  /*   35 */  "IMMI_255",
  /*   36 */  "IMMI_65535",
  /*   37 */  "AIMMI",
  /*   38 */  "AIMMINEG",
  /*   39 */  "AIMMU31",
  /*   40 */  "LIMMI",
  /*   41 */  "LIMMILOW8",
  /*   42 */  "LIMMU31",
  /*   43 */  "LIMMIN",
  /*   44 */  "IMML_FF",
  /*   45 */  "IMML_FFFF",
  /*   46 */  "IMMP",
  /*   47 */  "IMMP0",
  /*   48 */  "IMMP_POLL",
  /*   49 */  "IMMN",
  /*   50 */  "IMMNKLASS",
  /*   51 */  "IMMN0",
  /*   52 */  "IMML",
  /*   53 */  "IMML0",
  /*   54 */  "IMML16",
  /*   55 */  "IMML_32BITS",
  /*   56 */  "IMMD",
  /*   57 */  "IMMD0",
  /*   58 */  "IMM8D",
  /*   59 */  "IMMF",
  /*   60 */  "IMMF0",
  /*   61 */  "IMM8F",
  /*   62 */  "IREGI",
  /*   63 */  "IREGP",
  /*   64 */  "SP_PTR_REGP",
  /*   65 */  "R0REGP",
  /*   66 */  "R1REGP",
  /*   67 */  "R2REGP",
  /*   68 */  "REXCEPTIONREGP",
  /*   69 */  "RTHREADREGP",
  /*   70 */  "IPREGP",
  /*   71 */  "LRREGP",
  /*   72 */  "R0REGI",
  /*   73 */  "R1REGI",
  /*   74 */  "R2REGI",
  /*   75 */  "R3REGI",
  /*   76 */  "R12REGI",
  /*   77 */  "IREGL",
  /*   78 */  "IREGLD",
  /*   79 */  "R0R1REGL",
  /*   80 */  "R2R3REGL",
  /*   81 */  "FLAGSREG",
  /*   82 */  "FLAGSREG_EQNELTGE",
  /*   83 */  "FLAGSREGU",
  /*   84 */  "FLAGSREGP",
  /*   85 */  "FLAGSREGL_LTGE",
  /*   86 */  "FLAGSREGL_EQNE",
  /*   87 */  "FLAGSREGL_LEGT",
  /*   88 */  "FLAGSREGF",
  /*   89 */  "VECD",
  /*   90 */  "VECX",
  /*   91 */  "REGD",
  /*   92 */  "REGF",
  /*   93 */  "REGD_LOW",
  /*   94 */  "INLINE_CACHE_REGP",
  /*   95 */  "INTERPRETER_METHOD_OOP_REGP",
  /*   96 */  "INDIRECT",
  /*   97 */  "INDOFFSET12",
  /*   98 */  "INDOFFSETFP",
  /*   99 */  "INDOFFSETHD",
  /*  100 */  "INDOFFSETFPX2",
  /*  101 */  "INDOFFSET12X2",
  /*  102 */  "INDINDEX",
  /*  103 */  "INDINDEXSCALE",
  /*  104 */  "CMPOP",
  /*  105 */  "CMPOP0",
  /*  106 */  "CMPOPU",
  /*  107 */  "CMPOPP",
  /*  108 */  "CMPOPL",
  /*  109 */  "CMPOPL_COMMUTE",
  /*  110 */  "SHIFTEDX",
  // last operand
  /*  111 */  "MEMORYI",
  /*  112 */  "MEMORYP",
  /*  113 */  "MEMORYF",
  /*  114 */  "MEMORYF2",
  /*  115 */  "MEMORYD",
  /*  116 */  "MEMORYFP",
  /*  117 */  "MEMORYB",
  /*  118 */  "MEMORYS",
  /*  119 */  "MEMORYL",
  /*  120 */  "MEMORYSCALEDI",
  /*  121 */  "MEMORYSCALEDP",
  /*  122 */  "MEMORYEX",
  /*  123 */  "INDINDEXMEMORY",
  /*  124 */  "MEMORYLONG",
  /*  125 */  "MEMORYVLD",
  // last operand class
  /*  126 */  "_LShiftI_iRegI_immU5",
  /*  127 */  "_LoadB_memoryB_",
  /*  128 */  "_LoadUB_memoryB_",
  /*  129 */  "_AndI__LoadUB_memoryB__limmIlow8",
  /*  130 */  "_LoadS_memoryS_",
  /*  131 */  "_LShiftI__LoadS_memoryS__immI_24",
  /*  132 */  "_LoadUS_memoryB_",
  /*  133 */  "_LShiftI__LoadUS_memoryB__immI_24",
  /*  134 */  "_LoadUS_memoryS_",
  /*  135 */  "_AndI__LoadUS_memoryB__immI_255",
  /*  136 */  "_AndI__LoadUS_memoryS__limmI",
  /*  137 */  "_LoadI_memoryS_",
  /*  138 */  "_LShiftI__LoadI_memoryS__immI_24",
  /*  139 */  "_LoadI_memoryB_",
  /*  140 */  "_LShiftI__LoadI_memoryS__immI_16",
  /*  141 */  "_LoadI_memoryI_",
  /*  142 */  "_AndI__LoadI_memoryB__immI_255",
  /*  143 */  "_AndI__LoadI_memoryS__immI_65535",
  /*  144 */  "_AndI__LoadI_memoryI__limmU31",
  /*  145 */  "_AndI__LoadI_memoryI__immU31",
  /*  146 */  "_ConvI2L__LoadI_memoryI__",
  /*  147 */  "_Binary_cmpOpP_flagsRegP",
  /*  148 */  "_Binary_iRegI_iRegI",
  /*  149 */  "_Binary_iRegI_immIRot",
  /*  150 */  "_Binary_iRegI_immI16",
  /*  151 */  "_Binary_cmpOp_flagsReg",
  /*  152 */  "_Binary_cmpOp0_flagsReg_EQNELTGE",
  /*  153 */  "_Binary_cmpOpU_flagsRegU",
  /*  154 */  "_Binary_iRegP_iRegP",
  /*  155 */  "_Binary_iRegP_immP0",
  /*  156 */  "_Binary_regF_regF",
  /*  157 */  "_Binary_regD_regD",
  /*  158 */  "_Binary_iRegL_iRegL",
  /*  159 */  "_Binary_iRegL_immLlowRot",
  /*  160 */  "_Binary_iRegL_immL16",
  /*  161 */  "_LShiftI_iRegI_iRegI",
  /*  162 */  "_RShiftI_iRegI_iRegI",
  /*  163 */  "_RShiftI_iRegI_immU5",
  /*  164 */  "_URShiftI_iRegI_iRegI",
  /*  165 */  "_URShiftI_iRegI_immU5",
  /*  166 */  "_Binary_iRegL_iRegLd",
  /*  167 */  "_CastP2X_iRegP_",
  /*  168 */  "_ConvF2D_regF_",
  /*  169 */  "_SqrtD__ConvF2D_regF__",
  /*  170 */  "_CmpLTMask_iRegI_iRegI",
  /*  171 */  "_AndI__CmpLTMask_iRegI_iRegI_iRegI",
  /*  172 */  "_AndI_iRegI__CmpLTMask_iRegI_iRegI",
  /*  173 */  "_CmpLTMask_iRegI_aimmI",
  /*  174 */  "_AndI__CmpLTMask_iRegI_aimmI_iRegI",
  /*  175 */  "_AndI_iRegI__CmpLTMask_iRegI_aimmI",
  /*  176 */  "_SubI_iRegI_iRegI",
  /*  177 */  "_ConvI2L_iRegI_",
  /*  178 */  "_RShiftL_iRegL_immI_32_63",
  /*  179 */  "_AndI_iRegI_iRegI",
  /*  180 */  "_AndI_iRegI__LShiftI_iRegI_iRegI",
  /*  181 */  "_AndI__LShiftI_iRegI_iRegI_iRegI",
  /*  182 */  "_AndI_iRegI__LShiftI_iRegI_immU5",
  /*  183 */  "_AndI__LShiftI_iRegI_immU5_iRegI",
  /*  184 */  "_AndI_iRegI__RShiftI_iRegI_iRegI",
  /*  185 */  "_AndI__RShiftI_iRegI_iRegI_iRegI",
  /*  186 */  "_AndI_iRegI__RShiftI_iRegI_immU5",
  /*  187 */  "_AndI__RShiftI_iRegI_immU5_iRegI",
  /*  188 */  "_AndI_iRegI__URShiftI_iRegI_iRegI",
  /*  189 */  "_AndI__URShiftI_iRegI_iRegI_iRegI",
  /*  190 */  "_AndI_iRegI__URShiftI_iRegI_immU5",
  /*  191 */  "_AndI__URShiftI_iRegI_immU5_iRegI",
  /*  192 */  "_AndI_iRegI_limmI",
  /*  193 */  "_Binary_cmpOpL_flagsRegL_LTGE",
  /*  194 */  "_Binary_cmpOpL_flagsRegL_EQNE",
  /*  195 */  "_Binary_cmpOpL_commute_flagsRegL_LEGT",
  /*  196 */  "_Binary_iRegL_immL0",
  // last internally defined operand
  /*  197 */  "loadConI",
  /*  198 */  "loadConIMov",
  /*  199 */  "loadConIMovn",
  /*  200 */  "loadConI16",
  /*  201 */  "loadConP",
  /*  202 */  "loadConP_poll",
  /*  203 */  "loadConL",
  /*  204 */  "loadConL16",
  /*  205 */  "loadConF_imm8",
  /*  206 */  "loadConF",
  /*  207 */  "loadConD_imm8",
  /*  208 */  "loadConD",
  /*  209 */  "castX2P",
  /*  210 */  "castP2X",
  /*  211 */  "tlsLoadP",
  /*  212 */  "checkCastPP",
  /*  213 */  "castPP",
  /*  214 */  "castII",
  /*  215 */  "storePConditional",
  /*  216 */  "storeXConditional",
  /*  217 */  "absD_reg",
  /*  218 */  "absF_reg",
  /*  219 */  "negF_reg",
  /*  220 */  "negD_reg",
  /*  221 */  "MoveF2I_reg_reg",
  /*  222 */  "MoveI2F_reg_reg",
  /*  223 */  "MoveD2L_reg_reg",
  /*  224 */  "MoveL2D_reg_reg",
  /*  225 */  "convI2D_regDHi_regD",
  /*  226 */  "regL_to_regD",
  /*  227 */  "compI_iReg",
  /*  228 */  "compU_iReg",
  /*  229 */  "compI_iReg_immneg",
  /*  230 */  "compI_iReg_imm",
  /*  231 */  "testI_reg_reg",
  /*  232 */  "testshlI_reg_reg_reg",
  /*  233 */  "testshlI_reg_reg_reg_0",
  /*  234 */  "testshlI_reg_reg_imm",
  /*  235 */  "testshlI_reg_reg_imm_0",
  /*  236 */  "testsarI_reg_reg_reg",
  /*  237 */  "testsarI_reg_reg_reg_0",
  /*  238 */  "testsarI_reg_reg_imm",
  /*  239 */  "testsarI_reg_reg_imm_0",
  /*  240 */  "testshrI_reg_reg_reg",
  /*  241 */  "testshrI_reg_reg_reg_0",
  /*  242 */  "testshrI_reg_reg_imm",
  /*  243 */  "testshrI_reg_reg_imm_0",
  /*  244 */  "testI_reg_imm",
  /*  245 */  "compL_reg_reg_LTGE",
  /*  246 */  "compL_reg_reg_EQNE",
  /*  247 */  "compL_reg_reg_LEGT",
  /*  248 */  "compL_reg_con_LTGE",
  /*  249 */  "compL_reg_con_EQNE",
  /*  250 */  "compL_reg_con_LEGT",
  /*  251 */  "compU_iReg_imm",
  /*  252 */  "compP_iRegP",
  /*  253 */  "compP_iRegP_imm",
  /*  254 */  "cmpF_cc",
  /*  255 */  "cmpF0_cc",
  /*  256 */  "cmpD_cc",
  /*  257 */  "cmpD0_cc",
  /*  258 */  "cmpFastLock",
  /*  259 */  "cmpFastUnlock",
  /*  260 */  "countLeadingZerosI",
  /*  261 */  "vneg8B_reg",
  /*  262 */  "vneg16B_reg",
  /*  263 */  "vslcntD",
  /*  264 */  "vslcntX",
  /*  265 */  "vsrcntD",
  /*  266 */  "vsrcntX",
  /*  267 */  "Nop_A0",
  /*  268 */  "Nop_A1",
  /*  269 */  "Nop_MS",
  /*  270 */  "Nop_FA",
  /*  271 */  "Nop_BR",
  /*  272 */  "loadB",
  /*  273 */  "loadB2L",
  /*  274 */  "loadUB",
  /*  275 */  "loadUB2L",
  /*  276 */  "loadUB2L_limmI",
  /*  277 */  "loadS",
  /*  278 */  "loadS2B",
  /*  279 */  "loadS2L",
  /*  280 */  "loadUS",
  /*  281 */  "loadUS2B",
  /*  282 */  "loadUS2L",
  /*  283 */  "loadUS2L_immI_255",
  /*  284 */  "loadUS2L_limmI",
  /*  285 */  "loadI",
  /*  286 */  "loadI2B",
  /*  287 */  "loadI2UB",
  /*  288 */  "loadI2S",
  /*  289 */  "loadI2US",
  /*  290 */  "loadI2L",
  /*  291 */  "loadI2L_immI_255",
  /*  292 */  "loadI2L_immI_65535",
  /*  293 */  "loadI2L_limmU31",
  /*  294 */  "loadI2L_immU31",
  /*  295 */  "loadUI2L",
  /*  296 */  "loadL",
  /*  297 */  "loadL_2instr",
  /*  298 */  "loadL_volatile",
  /*  299 */  "loadL_volatile_fp",
  /*  300 */  "loadL_unaligned",
  /*  301 */  "loadRange",
  /*  302 */  "loadP",
  /*  303 */  "loadKlass",
  /*  304 */  "loadD",
  /*  305 */  "loadD_unaligned",
  /*  306 */  "loadF",
  /*  307 */  "prefetchAlloc_mp",
  /*  308 */  "prefetchAlloc_sp",
  /*  309 */  "storeB",
  /*  310 */  "storeCM",
  /*  311 */  "storeC",
  /*  312 */  "storeI",
  /*  313 */  "storeL",
  /*  314 */  "storeL_2instr",
  /*  315 */  "storeL_volatile",
  /*  316 */  "storeL_volatile_fp",
  /*  317 */  "storeP",
  /*  318 */  "storeD",
  /*  319 */  "storeF",
  /*  320 */  "membar_storestore",
  /*  321 */  "membar_acquire",
  /*  322 */  "membar_acquire_0",
  /*  323 */  "membar_acquire_lock",
  /*  324 */  "membar_release",
  /*  325 */  "membar_release_0",
  /*  326 */  "membar_release_lock",
  /*  327 */  "membar_volatile",
  /*  328 */  "unnecessary_membar_volatile",
  /*  329 */  "cmovIP_reg",
  /*  330 */  "cmovIP_immMov",
  /*  331 */  "cmovIP_imm16",
  /*  332 */  "cmovI_reg",
  /*  333 */  "cmovI_immMov",
  /*  334 */  "cmovII_imm16",
  /*  335 */  "cmovII_reg_EQNELTGE",
  /*  336 */  "cmovII_immMov_EQNELTGE",
  /*  337 */  "cmovII_imm16_EQNELTGE",
  /*  338 */  "cmovIIu_reg",
  /*  339 */  "cmovIIu_immMov",
  /*  340 */  "cmovIIu_imm16",
  /*  341 */  "cmovPP_reg",
  /*  342 */  "cmovPP_imm",
  /*  343 */  "cmovPI_reg",
  /*  344 */  "cmovPI_reg_EQNELTGE",
  /*  345 */  "cmovPIu_reg",
  /*  346 */  "cmovPI_imm",
  /*  347 */  "cmovPI_imm_EQNELTGE",
  /*  348 */  "cmovPIu_imm",
  /*  349 */  "cmovFP_reg",
  /*  350 */  "cmovFI_reg",
  /*  351 */  "cmovFI_reg_EQNELTGE",
  /*  352 */  "cmovFIu_reg",
  /*  353 */  "cmovDP_reg",
  /*  354 */  "cmovDI_reg",
  /*  355 */  "cmovDI_reg_EQNELTGE",
  /*  356 */  "cmovDIu_reg",
  /*  357 */  "cmovLP_reg",
  /*  358 */  "cmovLP_immRot",
  /*  359 */  "cmovLP_imm16",
  /*  360 */  "cmovLI_reg",
  /*  361 */  "cmovLI_reg_EQNELTGE",
  /*  362 */  "cmovLI_immRot",
  /*  363 */  "cmovLI_immRot_EQNELTGE",
  /*  364 */  "cmovLI_imm16",
  /*  365 */  "cmovLI_imm16_EQNELTGE",
  /*  366 */  "cmovLIu_reg",
  /*  367 */  "addI_reg_reg",
  /*  368 */  "addshlI_reg_reg_reg",
  /*  369 */  "addshlI_reg_reg_reg_0",
  /*  370 */  "addshlI_reg_imm_reg",
  /*  371 */  "addshlI_reg_imm_reg_0",
  /*  372 */  "addsarI_reg_reg_reg",
  /*  373 */  "addsarI_reg_reg_reg_0",
  /*  374 */  "addsarI_reg_imm_reg",
  /*  375 */  "addsarI_reg_imm_reg_0",
  /*  376 */  "addshrI_reg_reg_reg",
  /*  377 */  "addshrI_reg_reg_reg_0",
  /*  378 */  "addshrI_reg_imm_reg",
  /*  379 */  "addshrI_reg_imm_reg_0",
  /*  380 */  "addI_reg_aimmI",
  /*  381 */  "addP_reg_reg",
  /*  382 */  "addshlP_reg_reg_imm",
  /*  383 */  "addP_reg_aimmX",
  /*  384 */  "addL_reg_reg",
  /*  385 */  "addL_reg_immRot",
  /*  386 */  "loadPLocked",
  /*  387 */  "compareAndSwapL_bool",
  /*  388 */  "compareAndSwapI_bool",
  /*  389 */  "compareAndSwapP_bool",
  /*  390 */  "xaddI_aimmI_no_res",
  /*  391 */  "xaddI_reg_no_res",
  /*  392 */  "xaddI_aimmI",
  /*  393 */  "xaddI_reg",
  /*  394 */  "xaddL_reg_no_res",
  /*  395 */  "xaddL_immRot_no_res",
  /*  396 */  "xaddL_reg",
  /*  397 */  "xaddL_immRot",
  /*  398 */  "xchgI",
  /*  399 */  "xchgL",
  /*  400 */  "xchgP",
  /*  401 */  "subI_reg_reg",
  /*  402 */  "subshlI_reg_reg_reg",
  /*  403 */  "subshlI_reg_reg_imm",
  /*  404 */  "subsarI_reg_reg_reg",
  /*  405 */  "subsarI_reg_reg_imm",
  /*  406 */  "subshrI_reg_reg_reg",
  /*  407 */  "subshrI_reg_reg_imm",
  /*  408 */  "rsbshlI_reg_reg_reg",
  /*  409 */  "rsbshlI_reg_imm_reg",
  /*  410 */  "rsbsarI_reg_reg_reg",
  /*  411 */  "rsbsarI_reg_imm_reg",
  /*  412 */  "rsbshrI_reg_reg_reg",
  /*  413 */  "rsbshrI_reg_imm_reg",
  /*  414 */  "subI_reg_aimmI",
  /*  415 */  "subI_reg_immRotneg",
  /*  416 */  "subI_immRot_reg",
  /*  417 */  "subL_reg_reg",
  /*  418 */  "subL_reg_immRot",
  /*  419 */  "negL_reg_reg",
  /*  420 */  "mulI_reg_reg",
  /*  421 */  "mulL_lo1_hi2",
  /*  422 */  "mulL_hi1_lo2",
  /*  423 */  "mulL_lo1_lo2",
  /*  424 */  "mulL_reg_reg",
  /*  425 */  "divI_reg_reg",
  /*  426 */  "divL_reg_reg",
  /*  427 */  "modI_reg_reg",
  /*  428 */  "modL_reg_reg",
  /*  429 */  "shlI_reg_reg",
  /*  430 */  "shlI_reg_imm5",
  /*  431 */  "shlL_reg_reg_merge_hi",
  /*  432 */  "shlL_reg_reg_merge_lo",
  /*  433 */  "shlL_reg_reg_overlap",
  /*  434 */  "shlL_reg_reg",
  /*  435 */  "shlL_reg_imm6",
  /*  436 */  "shlL_reg_imm5",
  /*  437 */  "sarI_reg_reg",
  /*  438 */  "sarI_reg_imm5",
  /*  439 */  "sarL_reg_reg_merge_lo",
  /*  440 */  "sarL_reg_reg_merge_hi",
  /*  441 */  "sarL_reg_reg_overlap",
  /*  442 */  "sarL_reg_reg",
  /*  443 */  "sarL_reg_imm6",
  /*  444 */  "sarL_reg_imm5",
  /*  445 */  "shrI_reg_reg",
  /*  446 */  "shrI_reg_imm5",
  /*  447 */  "shrL_reg_reg_merge_lo",
  /*  448 */  "shrL_reg_reg_merge_hi",
  /*  449 */  "shrL_reg_reg_overlap",
  /*  450 */  "shrL_reg_reg",
  /*  451 */  "shrL_reg_imm6",
  /*  452 */  "shrL_reg_imm5",
  /*  453 */  "shrP_reg_imm5",
  /*  454 */  "addF_reg_reg",
  /*  455 */  "addD_reg_reg",
  /*  456 */  "subF_reg_reg",
  /*  457 */  "subD_reg_reg",
  /*  458 */  "mulF_reg_reg",
  /*  459 */  "mulD_reg_reg",
  /*  460 */  "divF_reg_reg",
  /*  461 */  "divD_reg_reg",
  /*  462 */  "sqrtF_reg_reg",
  /*  463 */  "sqrtD_reg_reg",
  /*  464 */  "andI_reg_reg",
  /*  465 */  "andshlI_reg_reg_reg",
  /*  466 */  "andshlI_reg_reg_reg_0",
  /*  467 */  "andshlI_reg_reg_imm",
  /*  468 */  "andshlI_reg_reg_imm_0",
  /*  469 */  "andsarI_reg_reg_reg",
  /*  470 */  "andsarI_reg_reg_reg_0",
  /*  471 */  "andsarI_reg_reg_imm",
  /*  472 */  "andsarI_reg_reg_imm_0",
  /*  473 */  "andshrI_reg_reg_reg",
  /*  474 */  "andshrI_reg_reg_reg_0",
  /*  475 */  "andshrI_reg_reg_imm",
  /*  476 */  "andshrI_reg_reg_imm_0",
  /*  477 */  "andI_reg_limm",
  /*  478 */  "andI_reg_limmn",
  /*  479 */  "andL_reg_reg",
  /*  480 */  "andL_reg_immRot",
  /*  481 */  "orI_reg_reg",
  /*  482 */  "orshlI_reg_reg_reg",
  /*  483 */  "orshlI_reg_reg_reg_0",
  /*  484 */  "orshlI_reg_reg_imm",
  /*  485 */  "orshlI_reg_reg_imm_0",
  /*  486 */  "orsarI_reg_reg_reg",
  /*  487 */  "orsarI_reg_reg_reg_0",
  /*  488 */  "orsarI_reg_reg_imm",
  /*  489 */  "orsarI_reg_reg_imm_0",
  /*  490 */  "orshrI_reg_reg_reg",
  /*  491 */  "orshrI_reg_reg_reg_0",
  /*  492 */  "orshrI_reg_reg_imm",
  /*  493 */  "orshrI_reg_reg_imm_0",
  /*  494 */  "orI_reg_limm",
  /*  495 */  "orL_reg_reg",
  /*  496 */  "orL_reg_immRot",
  /*  497 */  "xorI_reg_reg",
  /*  498 */  "xorshlI_reg_reg_reg",
  /*  499 */  "xorshlI_reg_reg_reg_0",
  /*  500 */  "xorshlI_reg_reg_imm",
  /*  501 */  "xorshlI_reg_reg_imm_0",
  /*  502 */  "xorsarI_reg_reg_reg",
  /*  503 */  "xorsarI_reg_reg_reg_0",
  /*  504 */  "xorsarI_reg_reg_imm",
  /*  505 */  "xorsarI_reg_reg_imm_0",
  /*  506 */  "xorshrI_reg_reg_reg",
  /*  507 */  "xorshrI_reg_reg_reg_0",
  /*  508 */  "xorshrI_reg_reg_imm",
  /*  509 */  "xorshrI_reg_reg_imm_0",
  /*  510 */  "xorI_reg_imm",
  /*  511 */  "xorL_reg_reg",
  /*  512 */  "xorL_reg_immRot",
  /*  513 */  "convI2B",
  /*  514 */  "convP2B",
  /*  515 */  "cmpLTMask_reg_reg",
  /*  516 */  "cmpLTMask_reg_imm",
  /*  517 */  "cadd_cmpLTMask3",
  /*  518 */  "cadd_cmpLTMask3_1",
  /*  519 */  "cadd_cmpLTMask3_0",
  /*  520 */  "cadd_cmpLTMask3_2",
  /*  521 */  "cadd_cmpLTMask4",
  /*  522 */  "cadd_cmpLTMask4_1",
  /*  523 */  "cadd_cmpLTMask4_0",
  /*  524 */  "cadd_cmpLTMask4_2",
  /*  525 */  "cadd_cmpLTMask",
  /*  526 */  "cadd_cmpLTMask_1",
  /*  527 */  "cadd_cmpLTMask_0",
  /*  528 */  "cadd_cmpLTMask_2",
  /*  529 */  "convD2F_reg",
  /*  530 */  "convD2I_reg_reg",
  /*  531 */  "convD2L_reg",
  /*  532 */  "convF2D_reg",
  /*  533 */  "convF2I_reg_reg",
  /*  534 */  "convF2L_reg",
  /*  535 */  "convI2D_reg_reg",
  /*  536 */  "convI2F_reg_reg",
  /*  537 */  "convI2L_reg",
  /*  538 */  "convI2L_reg_zex",
  /*  539 */  "zerox_long",
  /*  540 */  "loadConI_x43300000",
  /*  541 */  "loadConI_x41f00000",
  /*  542 */  "loadConI_x0",
  /*  543 */  "regDHi_regDLo_to_regD",
  /*  544 */  "addD_regD_regD",
  /*  545 */  "subD_regD_regD",
  /*  546 */  "mulD_regD_regD",
  /*  547 */  "regI_regI_to_regD",
  /*  548 */  "convL2D_reg_slow_fxtof",
  /*  549 */  "convL2I_reg",
  /*  550 */  "shrL_reg_imm6_L2I",
  /*  551 */  "cmovI_reg_lt",
  /*  552 */  "minI_eReg",
  /*  553 */  "cmovI_reg_gt",
  /*  554 */  "maxI_eReg",
  /*  555 */  "cmpF_reg",
  /*  556 */  "cmpF0_reg",
  /*  557 */  "cmpD_reg",
  /*  558 */  "cmpD0_reg",
  /*  559 */  "jumpXtnd",
  /*  560 */  "branch",
  /*  561 */  "branchCon",
  /*  562 */  "branchCon_EQNELTGE",
  /*  563 */  "branchConU",
  /*  564 */  "branchConP",
  /*  565 */  "branchConL_LTGE",
  /*  566 */  "branchConL_EQNE",
  /*  567 */  "branchConL_LEGT",
  /*  568 */  "branchLoopEnd",
  /*  569 */  "cmpL3_reg_reg",
  /*  570 */  "cmovLL_reg_LTGE",
  /*  571 */  "cmovLL_reg_EQNE",
  /*  572 */  "cmovLL_reg_LEGT",
  /*  573 */  "cmovLL_imm_LTGE",
  /*  574 */  "cmovLL_imm_EQNE",
  /*  575 */  "cmovLL_imm_LEGT",
  /*  576 */  "cmovIL_reg_LTGE",
  /*  577 */  "cmovIL_reg_EQNE",
  /*  578 */  "cmovIL_reg_LEGT",
  /*  579 */  "cmovIL_imm_LTGE",
  /*  580 */  "cmovIL_imm_EQNE",
  /*  581 */  "cmovIL_imm_LEGT",
  /*  582 */  "cmovPL_reg_LTGE",
  /*  583 */  "cmovPL_reg_EQNE",
  /*  584 */  "cmovPL_reg_LEGT",
  /*  585 */  "cmovPL_imm_LTGE",
  /*  586 */  "cmovPL_imm_EQNE",
  /*  587 */  "cmovPL_imm_LEGT",
  /*  588 */  "cmovFL_reg_LTGE",
  /*  589 */  "cmovFL_reg_EQNE",
  /*  590 */  "cmovFL_reg_LEGT",
  /*  591 */  "cmovDL_reg_LTGE",
  /*  592 */  "cmovDL_reg_EQNE",
  /*  593 */  "cmovDL_reg_LEGT",
  /*  594 */  "safePoint_poll",
  /*  595 */  "CallStaticJavaDirect",
  /*  596 */  "CallStaticJavaHandle",
  /*  597 */  "CallDynamicJavaDirect",
  /*  598 */  "CallRuntimeDirect",
  /*  599 */  "CallLeafDirect",
  /*  600 */  "CallLeafNoFPDirect",
  /*  601 */  "TailCalljmpInd",
  /*  602 */  "Ret",
  /*  603 */  "tailjmpInd",
  /*  604 */  "CreateException",
  /*  605 */  "RethrowException",
  /*  606 */  "ShouldNotReachHere",
  /*  607 */  "partialSubtypeCheck",
  /*  608 */  "clear_array",
  /*  609 */  "countLeadingZerosL",
  /*  610 */  "countTrailingZerosI",
  /*  611 */  "countTrailingZerosL",
  /*  612 */  "popCountI",
  /*  613 */  "popCountL",
  /*  614 */  "bytes_reverse_int",
  /*  615 */  "bytes_reverse_long",
  /*  616 */  "bytes_reverse_unsigned_short",
  /*  617 */  "bytes_reverse_short",
  /*  618 */  "loadV8",
  /*  619 */  "loadV16",
  /*  620 */  "storeV8",
  /*  621 */  "storeV16",
  /*  622 */  "Repl8B_reg",
  /*  623 */  "Repl8B_reg_simd",
  /*  624 */  "Repl16B_reg",
  /*  625 */  "Repl8B_immI",
  /*  626 */  "Repl8B_immU8",
  /*  627 */  "Repl16B_immU8",
  /*  628 */  "Repl4S_reg",
  /*  629 */  "Repl4S_reg_simd",
  /*  630 */  "Repl8S_reg",
  /*  631 */  "Repl4S_immI",
  /*  632 */  "Repl4S_immU8",
  /*  633 */  "Repl8S_immU8",
  /*  634 */  "Repl2I_reg",
  /*  635 */  "Repl4I_reg",
  /*  636 */  "Repl2I_reg_simd",
  /*  637 */  "Repl4I_reg_simd",
  /*  638 */  "Repl2I_immI",
  /*  639 */  "Repl2I_immU8",
  /*  640 */  "Repl4I_immU8",
  /*  641 */  "Repl2L_reg",
  /*  642 */  "Repl2F_regI",
  /*  643 */  "Repl2F_reg_vfp",
  /*  644 */  "Repl2F_reg_simd",
  /*  645 */  "Repl4F_reg",
  /*  646 */  "Repl4F_reg_simd",
  /*  647 */  "Repl2F_immI",
  /*  648 */  "Repl2D_reg",
  /*  649 */  "vadd8B_reg",
  /*  650 */  "vadd16B_reg",
  /*  651 */  "vadd4S_reg",
  /*  652 */  "vadd8S_reg",
  /*  653 */  "vadd2I_reg",
  /*  654 */  "vadd4I_reg",
  /*  655 */  "vadd2L_reg",
  /*  656 */  "vadd2F_reg",
  /*  657 */  "vadd2F_reg_vfp",
  /*  658 */  "vadd4F_reg_simd",
  /*  659 */  "vadd4F_reg_vfp",
  /*  660 */  "vadd2D_reg_vfp",
  /*  661 */  "vsub8B_reg",
  /*  662 */  "vsub16B_reg",
  /*  663 */  "vsub4S_reg",
  /*  664 */  "vsub16S_reg",
  /*  665 */  "vsub2I_reg",
  /*  666 */  "vsub4I_reg",
  /*  667 */  "vsub2L_reg",
  /*  668 */  "vsub2F_reg",
  /*  669 */  "vsub2F_reg_vfp",
  /*  670 */  "vsub4F_reg",
  /*  671 */  "vsub4F_reg_vfp",
  /*  672 */  "vsub2D_reg_vfp",
  /*  673 */  "vmul4S_reg",
  /*  674 */  "vmul8S_reg",
  /*  675 */  "vmul2I_reg",
  /*  676 */  "vmul4I_reg",
  /*  677 */  "vmul2F_reg",
  /*  678 */  "vmul2F_reg_vfp",
  /*  679 */  "vmul4F_reg",
  /*  680 */  "vmul4F_reg_vfp",
  /*  681 */  "vmul2D_reg_vfp",
  /*  682 */  "vdiv2F_reg_vfp",
  /*  683 */  "vdiv4F_reg_vfp",
  /*  684 */  "vdiv2D_reg_vfp",
  /*  685 */  "vsh8B_reg",
  /*  686 */  "vsh16B_reg",
  /*  687 */  "vsh4S_reg",
  /*  688 */  "vsh8S_reg",
  /*  689 */  "vsh2I_reg",
  /*  690 */  "vsh4I_reg",
  /*  691 */  "vsh2L_reg",
  /*  692 */  "vsl8B_reg",
  /*  693 */  "vsl16B_reg",
  /*  694 */  "vsl8B_immI",
  /*  695 */  "vsl16B_immI",
  /*  696 */  "vsl4S_reg",
  /*  697 */  "vsl4S_reg_0",
  /*  698 */  "vsl8S_reg",
  /*  699 */  "vsl8S_reg_0",
  /*  700 */  "vsl4S_immI",
  /*  701 */  "vsl8S_immI",
  /*  702 */  "vsl2I_reg",
  /*  703 */  "vsl2I_reg_0",
  /*  704 */  "vsl4I_reg",
  /*  705 */  "vsl4I_reg_0",
  /*  706 */  "vsl2I_immI",
  /*  707 */  "vsl4I_immI",
  /*  708 */  "vsl2L_reg",
  /*  709 */  "vsl2L_reg_0",
  /*  710 */  "vsl2L_immI",
  /*  711 */  "vsrl4S_immI",
  /*  712 */  "vsrl8S_immI",
  /*  713 */  "vsrl2I_immI",
  /*  714 */  "vsrl4I_immI",
  /*  715 */  "vsrl2L_immI",
  /*  716 */  "vsha8B_reg",
  /*  717 */  "vsha16B_reg",
  /*  718 */  "vsha4S_reg",
  /*  719 */  "vsha8S_reg",
  /*  720 */  "vsha2I_reg",
  /*  721 */  "vsha4I_reg",
  /*  722 */  "vsha2L_reg",
  /*  723 */  "vsra8B_reg",
  /*  724 */  "vsrl16B_reg",
  /*  725 */  "vsrl8B_immI",
  /*  726 */  "vsrl16B_immI",
  /*  727 */  "vsra4S_reg",
  /*  728 */  "vsra8S_reg",
  /*  729 */  "vsra4S_immI",
  /*  730 */  "vsra8S_immI",
  /*  731 */  "vsra2I_reg",
  /*  732 */  "vsra4I_reg",
  /*  733 */  "vsra2I_immI",
  /*  734 */  "vsra4I_immI",
  /*  735 */  "vsra2L_reg",
  /*  736 */  "vsra2L_immI",
  /*  737 */  "vandD",
  /*  738 */  "vandX",
  /*  739 */  "vorD",
  /*  740 */  "vorX",
  /*  741 */  "vxorD",
  /*  742 */  "vxorX",
  // last instruction
  "invalid rule name" // no trailing comma
};

const        bool  swallowed[] = {
  /*    0 */  false,
  /*    1 */  false,
  /*    2 */  false,
  /*    3 */  false,
  /*    4 */  false,
  /*    5 */  false,
  /*    6 */  false,
  /*    7 */  false,
  /*    8 */  true,
  /*    9 */  true,
  /*   10 */  true,
  /*   11 */  true,
  /*   12 */  true,
  /*   13 */  true,
  /*   14 */  true,
  /*   15 */  true,
  /*   16 */  true,
  /*   17 */  true,
  /*   18 */  true,
  /*   19 */  true,
  /*   20 */  true,
  /*   21 */  true,
  /*   22 */  true,
  /*   23 */  true,
  /*   24 */  true,
  /*   25 */  true,
  /*   26 */  true,
  /*   27 */  true,
  /*   28 */  true,
  /*   29 */  true,
  /*   30 */  true,
  /*   31 */  true,
  /*   32 */  true,
  /*   33 */  true,
  /*   34 */  true,
  /*   35 */  true,
  /*   36 */  true,
  /*   37 */  true,
  /*   38 */  true,
  /*   39 */  true,
  /*   40 */  true,
  /*   41 */  true,
  /*   42 */  true,
  /*   43 */  true,
  /*   44 */  true,
  /*   45 */  true,
  /*   46 */  true,
  /*   47 */  true,
  /*   48 */  true,
  /*   49 */  true,
  /*   50 */  true,
  /*   51 */  true,
  /*   52 */  true,
  /*   53 */  true,
  /*   54 */  true,
  /*   55 */  true,
  /*   56 */  true,
  /*   57 */  true,
  /*   58 */  true,
  /*   59 */  true,
  /*   60 */  true,
  /*   61 */  true,
  /*   62 */  false,
  /*   63 */  false,
  /*   64 */  false,
  /*   65 */  false,
  /*   66 */  false,
  /*   67 */  false,
  /*   68 */  false,
  /*   69 */  false,
  /*   70 */  false,
  /*   71 */  false,
  /*   72 */  false,
  /*   73 */  false,
  /*   74 */  false,
  /*   75 */  false,
  /*   76 */  false,
  /*   77 */  false,
  /*   78 */  false,
  /*   79 */  false,
  /*   80 */  false,
  /*   81 */  false,
  /*   82 */  false,
  /*   83 */  false,
  /*   84 */  false,
  /*   85 */  false,
  /*   86 */  false,
  /*   87 */  false,
  /*   88 */  false,
  /*   89 */  false,
  /*   90 */  false,
  /*   91 */  false,
  /*   92 */  false,
  /*   93 */  false,
  /*   94 */  false,
  /*   95 */  false,
  /*   96 */  false,
  /*   97 */  false,
  /*   98 */  false,
  /*   99 */  false,
  /*  100 */  false,
  /*  101 */  false,
  /*  102 */  false,
  /*  103 */  false,
  /*  104 */  true,
  /*  105 */  true,
  /*  106 */  true,
  /*  107 */  true,
  /*  108 */  true,
  /*  109 */  true,
  /*  110 */  false,
  // last operand
  /*  111 */  false,
  /*  112 */  false,
  /*  113 */  false,
  /*  114 */  false,
  /*  115 */  false,
  /*  116 */  false,
  /*  117 */  false,
  /*  118 */  false,
  /*  119 */  false,
  /*  120 */  false,
  /*  121 */  false,
  /*  122 */  false,
  /*  123 */  false,
  /*  124 */  false,
  /*  125 */  false,
  // last operand class
  /*  126 */  false,
  /*  127 */  false,
  /*  128 */  false,
  /*  129 */  false,
  /*  130 */  false,
  /*  131 */  false,
  /*  132 */  false,
  /*  133 */  false,
  /*  134 */  false,
  /*  135 */  false,
  /*  136 */  false,
  /*  137 */  false,
  /*  138 */  false,
  /*  139 */  false,
  /*  140 */  false,
  /*  141 */  false,
  /*  142 */  false,
  /*  143 */  false,
  /*  144 */  false,
  /*  145 */  false,
  /*  146 */  false,
  /*  147 */  false,
  /*  148 */  false,
  /*  149 */  false,
  /*  150 */  false,
  /*  151 */  false,
  /*  152 */  false,
  /*  153 */  false,
  /*  154 */  false,
  /*  155 */  false,
  /*  156 */  false,
  /*  157 */  false,
  /*  158 */  false,
  /*  159 */  false,
  /*  160 */  false,
  /*  161 */  false,
  /*  162 */  false,
  /*  163 */  false,
  /*  164 */  false,
  /*  165 */  false,
  /*  166 */  false,
  /*  167 */  false,
  /*  168 */  false,
  /*  169 */  false,
  /*  170 */  false,
  /*  171 */  false,
  /*  172 */  false,
  /*  173 */  false,
  /*  174 */  false,
  /*  175 */  false,
  /*  176 */  false,
  /*  177 */  false,
  /*  178 */  false,
  /*  179 */  false,
  /*  180 */  false,
  /*  181 */  false,
  /*  182 */  false,
  /*  183 */  false,
  /*  184 */  false,
  /*  185 */  false,
  /*  186 */  false,
  /*  187 */  false,
  /*  188 */  false,
  /*  189 */  false,
  /*  190 */  false,
  /*  191 */  false,
  /*  192 */  false,
  /*  193 */  false,
  /*  194 */  false,
  /*  195 */  false,
  /*  196 */  false,
  // last internally defined operand
  /*  197 */  false,
  /*  198 */  false,
  /*  199 */  false,
  /*  200 */  false,
  /*  201 */  false,
  /*  202 */  false,
  /*  203 */  false,
  /*  204 */  false,
  /*  205 */  false,
  /*  206 */  false,
  /*  207 */  false,
  /*  208 */  false,
  /*  209 */  false,
  /*  210 */  false,
  /*  211 */  false,
  /*  212 */  false,
  /*  213 */  false,
  /*  214 */  false,
  /*  215 */  false,
  /*  216 */  false,
  /*  217 */  false,
  /*  218 */  false,
  /*  219 */  false,
  /*  220 */  false,
  /*  221 */  false,
  /*  222 */  false,
  /*  223 */  false,
  /*  224 */  false,
  /*  225 */  false,
  /*  226 */  false,
  /*  227 */  false,
  /*  228 */  false,
  /*  229 */  false,
  /*  230 */  false,
  /*  231 */  false,
  /*  232 */  false,
  /*  233 */  false,
  /*  234 */  false,
  /*  235 */  false,
  /*  236 */  false,
  /*  237 */  false,
  /*  238 */  false,
  /*  239 */  false,
  /*  240 */  false,
  /*  241 */  false,
  /*  242 */  false,
  /*  243 */  false,
  /*  244 */  false,
  /*  245 */  false,
  /*  246 */  false,
  /*  247 */  false,
  /*  248 */  false,
  /*  249 */  false,
  /*  250 */  false,
  /*  251 */  false,
  /*  252 */  false,
  /*  253 */  false,
  /*  254 */  false,
  /*  255 */  false,
  /*  256 */  false,
  /*  257 */  false,
  /*  258 */  false,
  /*  259 */  false,
  /*  260 */  false,
  /*  261 */  false,
  /*  262 */  false,
  /*  263 */  false,
  /*  264 */  false,
  /*  265 */  false,
  /*  266 */  false,
  /*  267 */  false,
  /*  268 */  false,
  /*  269 */  false,
  /*  270 */  false,
  /*  271 */  false,
  /*  272 */  false,
  /*  273 */  false,
  /*  274 */  false,
  /*  275 */  false,
  /*  276 */  false,
  /*  277 */  false,
  /*  278 */  false,
  /*  279 */  false,
  /*  280 */  false,
  /*  281 */  false,
  /*  282 */  false,
  /*  283 */  false,
  /*  284 */  false,
  /*  285 */  false,
  /*  286 */  false,
  /*  287 */  false,
  /*  288 */  false,
  /*  289 */  false,
  /*  290 */  false,
  /*  291 */  false,
  /*  292 */  false,
  /*  293 */  false,
  /*  294 */  false,
  /*  295 */  false,
  /*  296 */  false,
  /*  297 */  false,
  /*  298 */  false,
  /*  299 */  false,
  /*  300 */  false,
  /*  301 */  false,
  /*  302 */  false,
  /*  303 */  false,
  /*  304 */  false,
  /*  305 */  false,
  /*  306 */  false,
  /*  307 */  false,
  /*  308 */  false,
  /*  309 */  false,
  /*  310 */  false,
  /*  311 */  false,
  /*  312 */  false,
  /*  313 */  false,
  /*  314 */  false,
  /*  315 */  false,
  /*  316 */  false,
  /*  317 */  false,
  /*  318 */  false,
  /*  319 */  false,
  /*  320 */  false,
  /*  321 */  false,
  /*  322 */  false,
  /*  323 */  false,
  /*  324 */  false,
  /*  325 */  false,
  /*  326 */  false,
  /*  327 */  false,
  /*  328 */  false,
  /*  329 */  false,
  /*  330 */  false,
  /*  331 */  false,
  /*  332 */  false,
  /*  333 */  false,
  /*  334 */  false,
  /*  335 */  false,
  /*  336 */  false,
  /*  337 */  false,
  /*  338 */  false,
  /*  339 */  false,
  /*  340 */  false,
  /*  341 */  false,
  /*  342 */  false,
  /*  343 */  false,
  /*  344 */  false,
  /*  345 */  false,
  /*  346 */  false,
  /*  347 */  false,
  /*  348 */  false,
  /*  349 */  false,
  /*  350 */  false,
  /*  351 */  false,
  /*  352 */  false,
  /*  353 */  false,
  /*  354 */  false,
  /*  355 */  false,
  /*  356 */  false,
  /*  357 */  false,
  /*  358 */  false,
  /*  359 */  false,
  /*  360 */  false,
  /*  361 */  false,
  /*  362 */  false,
  /*  363 */  false,
  /*  364 */  false,
  /*  365 */  false,
  /*  366 */  false,
  /*  367 */  false,
  /*  368 */  false,
  /*  369 */  false,
  /*  370 */  false,
  /*  371 */  false,
  /*  372 */  false,
  /*  373 */  false,
  /*  374 */  false,
  /*  375 */  false,
  /*  376 */  false,
  /*  377 */  false,
  /*  378 */  false,
  /*  379 */  false,
  /*  380 */  false,
  /*  381 */  false,
  /*  382 */  false,
  /*  383 */  false,
  /*  384 */  false,
  /*  385 */  false,
  /*  386 */  false,
  /*  387 */  false,
  /*  388 */  false,
  /*  389 */  false,
  /*  390 */  false,
  /*  391 */  false,
  /*  392 */  false,
  /*  393 */  false,
  /*  394 */  false,
  /*  395 */  false,
  /*  396 */  false,
  /*  397 */  false,
  /*  398 */  false,
  /*  399 */  false,
  /*  400 */  false,
  /*  401 */  false,
  /*  402 */  false,
  /*  403 */  false,
  /*  404 */  false,
  /*  405 */  false,
  /*  406 */  false,
  /*  407 */  false,
  /*  408 */  false,
  /*  409 */  false,
  /*  410 */  false,
  /*  411 */  false,
  /*  412 */  false,
  /*  413 */  false,
  /*  414 */  false,
  /*  415 */  false,
  /*  416 */  false,
  /*  417 */  false,
  /*  418 */  false,
  /*  419 */  false,
  /*  420 */  false,
  /*  421 */  false,
  /*  422 */  false,
  /*  423 */  false,
  /*  424 */  false,
  /*  425 */  false,
  /*  426 */  false,
  /*  427 */  false,
  /*  428 */  false,
  /*  429 */  false,
  /*  430 */  false,
  /*  431 */  false,
  /*  432 */  false,
  /*  433 */  false,
  /*  434 */  false,
  /*  435 */  false,
  /*  436 */  false,
  /*  437 */  false,
  /*  438 */  false,
  /*  439 */  false,
  /*  440 */  false,
  /*  441 */  false,
  /*  442 */  false,
  /*  443 */  false,
  /*  444 */  false,
  /*  445 */  false,
  /*  446 */  false,
  /*  447 */  false,
  /*  448 */  false,
  /*  449 */  false,
  /*  450 */  false,
  /*  451 */  false,
  /*  452 */  false,
  /*  453 */  false,
  /*  454 */  false,
  /*  455 */  false,
  /*  456 */  false,
  /*  457 */  false,
  /*  458 */  false,
  /*  459 */  false,
  /*  460 */  false,
  /*  461 */  false,
  /*  462 */  false,
  /*  463 */  false,
  /*  464 */  false,
  /*  465 */  false,
  /*  466 */  false,
  /*  467 */  false,
  /*  468 */  false,
  /*  469 */  false,
  /*  470 */  false,
  /*  471 */  false,
  /*  472 */  false,
  /*  473 */  false,
  /*  474 */  false,
  /*  475 */  false,
  /*  476 */  false,
  /*  477 */  false,
  /*  478 */  false,
  /*  479 */  false,
  /*  480 */  false,
  /*  481 */  false,
  /*  482 */  false,
  /*  483 */  false,
  /*  484 */  false,
  /*  485 */  false,
  /*  486 */  false,
  /*  487 */  false,
  /*  488 */  false,
  /*  489 */  false,
  /*  490 */  false,
  /*  491 */  false,
  /*  492 */  false,
  /*  493 */  false,
  /*  494 */  false,
  /*  495 */  false,
  /*  496 */  false,
  /*  497 */  false,
  /*  498 */  false,
  /*  499 */  false,
  /*  500 */  false,
  /*  501 */  false,
  /*  502 */  false,
  /*  503 */  false,
  /*  504 */  false,
  /*  505 */  false,
  /*  506 */  false,
  /*  507 */  false,
  /*  508 */  false,
  /*  509 */  false,
  /*  510 */  false,
  /*  511 */  false,
  /*  512 */  false,
  /*  513 */  false,
  /*  514 */  false,
  /*  515 */  false,
  /*  516 */  false,
  /*  517 */  false,
  /*  518 */  false,
  /*  519 */  false,
  /*  520 */  false,
  /*  521 */  false,
  /*  522 */  false,
  /*  523 */  false,
  /*  524 */  false,
  /*  525 */  false,
  /*  526 */  false,
  /*  527 */  false,
  /*  528 */  false,
  /*  529 */  false,
  /*  530 */  false,
  /*  531 */  false,
  /*  532 */  false,
  /*  533 */  false,
  /*  534 */  false,
  /*  535 */  false,
  /*  536 */  false,
  /*  537 */  false,
  /*  538 */  false,
  /*  539 */  false,
  /*  540 */  false,
  /*  541 */  false,
  /*  542 */  false,
  /*  543 */  false,
  /*  544 */  false,
  /*  545 */  false,
  /*  546 */  false,
  /*  547 */  false,
  /*  548 */  false,
  /*  549 */  false,
  /*  550 */  false,
  /*  551 */  false,
  /*  552 */  false,
  /*  553 */  false,
  /*  554 */  false,
  /*  555 */  false,
  /*  556 */  false,
  /*  557 */  false,
  /*  558 */  false,
  /*  559 */  false,
  /*  560 */  false,
  /*  561 */  false,
  /*  562 */  false,
  /*  563 */  false,
  /*  564 */  false,
  /*  565 */  false,
  /*  566 */  false,
  /*  567 */  false,
  /*  568 */  false,
  /*  569 */  false,
  /*  570 */  false,
  /*  571 */  false,
  /*  572 */  false,
  /*  573 */  false,
  /*  574 */  false,
  /*  575 */  false,
  /*  576 */  false,
  /*  577 */  false,
  /*  578 */  false,
  /*  579 */  false,
  /*  580 */  false,
  /*  581 */  false,
  /*  582 */  false,
  /*  583 */  false,
  /*  584 */  false,
  /*  585 */  false,
  /*  586 */  false,
  /*  587 */  false,
  /*  588 */  false,
  /*  589 */  false,
  /*  590 */  false,
  /*  591 */  false,
  /*  592 */  false,
  /*  593 */  false,
  /*  594 */  false,
  /*  595 */  false,
  /*  596 */  false,
  /*  597 */  false,
  /*  598 */  false,
  /*  599 */  false,
  /*  600 */  false,
  /*  601 */  false,
  /*  602 */  false,
  /*  603 */  false,
  /*  604 */  false,
  /*  605 */  false,
  /*  606 */  false,
  /*  607 */  false,
  /*  608 */  false,
  /*  609 */  false,
  /*  610 */  false,
  /*  611 */  false,
  /*  612 */  false,
  /*  613 */  false,
  /*  614 */  false,
  /*  615 */  false,
  /*  616 */  false,
  /*  617 */  false,
  /*  618 */  false,
  /*  619 */  false,
  /*  620 */  false,
  /*  621 */  false,
  /*  622 */  false,
  /*  623 */  false,
  /*  624 */  false,
  /*  625 */  false,
  /*  626 */  false,
  /*  627 */  false,
  /*  628 */  false,
  /*  629 */  false,
  /*  630 */  false,
  /*  631 */  false,
  /*  632 */  false,
  /*  633 */  false,
  /*  634 */  false,
  /*  635 */  false,
  /*  636 */  false,
  /*  637 */  false,
  /*  638 */  false,
  /*  639 */  false,
  /*  640 */  false,
  /*  641 */  false,
  /*  642 */  false,
  /*  643 */  false,
  /*  644 */  false,
  /*  645 */  false,
  /*  646 */  false,
  /*  647 */  false,
  /*  648 */  false,
  /*  649 */  false,
  /*  650 */  false,
  /*  651 */  false,
  /*  652 */  false,
  /*  653 */  false,
  /*  654 */  false,
  /*  655 */  false,
  /*  656 */  false,
  /*  657 */  false,
  /*  658 */  false,
  /*  659 */  false,
  /*  660 */  false,
  /*  661 */  false,
  /*  662 */  false,
  /*  663 */  false,
  /*  664 */  false,
  /*  665 */  false,
  /*  666 */  false,
  /*  667 */  false,
  /*  668 */  false,
  /*  669 */  false,
  /*  670 */  false,
  /*  671 */  false,
  /*  672 */  false,
  /*  673 */  false,
  /*  674 */  false,
  /*  675 */  false,
  /*  676 */  false,
  /*  677 */  false,
  /*  678 */  false,
  /*  679 */  false,
  /*  680 */  false,
  /*  681 */  false,
  /*  682 */  false,
  /*  683 */  false,
  /*  684 */  false,
  /*  685 */  false,
  /*  686 */  false,
  /*  687 */  false,
  /*  688 */  false,
  /*  689 */  false,
  /*  690 */  false,
  /*  691 */  false,
  /*  692 */  false,
  /*  693 */  false,
  /*  694 */  false,
  /*  695 */  false,
  /*  696 */  false,
  /*  697 */  false,
  /*  698 */  false,
  /*  699 */  false,
  /*  700 */  false,
  /*  701 */  false,
  /*  702 */  false,
  /*  703 */  false,
  /*  704 */  false,
  /*  705 */  false,
  /*  706 */  false,
  /*  707 */  false,
  /*  708 */  false,
  /*  709 */  false,
  /*  710 */  false,
  /*  711 */  false,
  /*  712 */  false,
  /*  713 */  false,
  /*  714 */  false,
  /*  715 */  false,
  /*  716 */  false,
  /*  717 */  false,
  /*  718 */  false,
  /*  719 */  false,
  /*  720 */  false,
  /*  721 */  false,
  /*  722 */  false,
  /*  723 */  false,
  /*  724 */  false,
  /*  725 */  false,
  /*  726 */  false,
  /*  727 */  false,
  /*  728 */  false,
  /*  729 */  false,
  /*  730 */  false,
  /*  731 */  false,
  /*  732 */  false,
  /*  733 */  false,
  /*  734 */  false,
  /*  735 */  false,
  /*  736 */  false,
  /*  737 */  false,
  /*  738 */  false,
  /*  739 */  false,
  /*  740 */  false,
  /*  741 */  false,
  /*  742 */  false,
  // last instruction
  false // no trailing comma
};

// Mapping from machine-independent opcode to boolean
const        char must_clone[] = {
  0, // Node: 0
  0, // Set: 1
  0, // RegN: 2
  0, // RegI: 3
  0, // RegP: 4
  0, // RegF: 5
  0, // RegD: 6
  0, // RegL: 7
  0, // RegFlags: 8
  0, // VecS: 9
  0, // VecD: 10
  0, // VecX: 11
  0, // VecY: 12
  0, // VecZ: 13
  0, // _last_machine_leaf: 14
  0, // AbsD: 15
  0, // AbsF: 16
  0, // AbsI: 17
  0, // AddD: 18
  0, // AddF: 19
  0, // AddI: 20
  0, // AddL: 21
  0, // AddP: 22
  0, // Allocate: 23
  0, // AllocateArray: 24
  0, // AndI: 25
  0, // AndL: 26
  0, // ArrayCopy: 27
  0, // AryEq: 28
  0, // AtanD: 29
  1, // Binary: 30
  1, // Bool: 31
  0, // BoxLock: 32
  0, // ReverseBytesI: 33
  0, // ReverseBytesL: 34
  0, // ReverseBytesUS: 35
  0, // ReverseBytesS: 36
  0, // CProj: 37
  0, // CallDynamicJava: 38
  0, // CallJava: 39
  0, // CallLeaf: 40
  0, // CallLeafNoFP: 41
  0, // CallRuntime: 42
  0, // CallStaticJava: 43
  0, // CastII: 44
  0, // CastX2P: 45
  0, // CastP2X: 46
  0, // CastPP: 47
  0, // Catch: 48
  0, // CatchProj: 49
  0, // CheckCastPP: 50
  0, // ClearArray: 51
  0, // ConstraintCast: 52
  0, // CMoveD: 53
  0, // CMoveVD: 54
  0, // CMoveF: 55
  0, // CMoveI: 56
  0, // CMoveL: 57
  0, // CMoveP: 58
  0, // CMoveN: 59
  1, // CmpN: 60
  1, // CmpD: 61
  0, // CmpD3: 62
  1, // CmpF: 63
  0, // CmpF3: 64
  1, // CmpI: 65
  1, // CmpL: 66
  0, // CmpL3: 67
  0, // CmpLTMask: 68
  1, // CmpP: 69
  1, // CmpU: 70
  0, // CompareAndSwapB: 71
  0, // CompareAndSwapS: 72
  0, // CompareAndSwapI: 73
  0, // CompareAndSwapL: 74
  0, // CompareAndSwapP: 75
  0, // CompareAndSwapN: 76
  0, // WeakCompareAndSwapB: 77
  0, // WeakCompareAndSwapS: 78
  0, // WeakCompareAndSwapI: 79
  0, // WeakCompareAndSwapL: 80
  0, // WeakCompareAndSwapP: 81
  0, // WeakCompareAndSwapN: 82
  0, // CompareAndExchangeB: 83
  0, // CompareAndExchangeS: 84
  0, // CompareAndExchangeI: 85
  0, // CompareAndExchangeL: 86
  0, // CompareAndExchangeP: 87
  0, // CompareAndExchangeN: 88
  0, // GetAndAddB: 89
  0, // GetAndAddS: 90
  0, // GetAndAddI: 91
  0, // GetAndAddL: 92
  0, // GetAndSetB: 93
  0, // GetAndSetS: 94
  0, // GetAndSetI: 95
  0, // GetAndSetL: 96
  0, // GetAndSetP: 97
  0, // GetAndSetN: 98
  0, // Con: 99
  0, // ConN: 100
  0, // ConNKlass: 101
  0, // ConD: 102
  0, // ConF: 103
  0, // ConI: 104
  0, // ConL: 105
  0, // ConP: 106
  0, // Conv2B: 107
  0, // ConvD2F: 108
  0, // ConvD2I: 109
  0, // ConvD2L: 110
  0, // ConvF2D: 111
  0, // ConvF2I: 112
  0, // ConvF2L: 113
  0, // ConvI2D: 114
  0, // ConvI2F: 115
  0, // ConvI2L: 116
  0, // ConvL2D: 117
  0, // ConvL2F: 118
  0, // ConvL2I: 119
  0, // CountedLoop: 120
  0, // CountedLoopEnd: 121
  0, // CountLeadingZerosI: 122
  0, // CountLeadingZerosL: 123
  0, // CountTrailingZerosI: 124
  0, // CountTrailingZerosL: 125
  0, // CreateEx: 126
  0, // DecodeN: 127
  0, // DecodeNKlass: 128
  0, // DivD: 129
  0, // DivF: 130
  0, // DivI: 131
  0, // DivL: 132
  0, // DivMod: 133
  0, // DivModI: 134
  0, // DivModL: 135
  0, // EncodeISOArray: 136
  0, // EncodeP: 137
  0, // EncodePKlass: 138
  1, // FastLock: 139
  1, // FastUnlock: 140
  0, // FmaD: 141
  0, // FmaF: 142
  0, // Goto: 143
  0, // Halt: 144
  0, // HasNegatives: 145
  0, // If: 146
  0, // RangeCheck: 147
  0, // IfFalse: 148
  0, // IfTrue: 149
  0, // Initialize: 150
  0, // JProj: 151
  0, // Jump: 152
  0, // JumpProj: 153
  0, // LShiftI: 154
  0, // LShiftL: 155
  0, // LoadB: 156
  0, // LoadUB: 157
  0, // LoadUS: 158
  0, // LoadD: 159
  0, // LoadD_unaligned: 160
  0, // LoadF: 161
  0, // LoadI: 162
  0, // LoadKlass: 163
  0, // LoadNKlass: 164
  0, // LoadL: 165
  0, // LoadL_unaligned: 166
  0, // LoadPLocked: 167
  0, // LoadP: 168
  0, // LoadN: 169
  0, // LoadRange: 170
  0, // LoadS: 171
  0, // Lock: 172
  0, // Loop: 173
  0, // LoopLimit: 174
  0, // Mach: 175
  0, // MachProj: 176
  0, // MaxI: 177
  0, // MemBarAcquire: 178
  0, // LoadFence: 179
  0, // SetVectMaskI: 180
  0, // MemBarAcquireLock: 181
  0, // MemBarCPUOrder: 182
  0, // MemBarRelease: 183
  0, // StoreFence: 184
  0, // MemBarReleaseLock: 185
  0, // MemBarVolatile: 186
  0, // MemBarStoreStore: 187
  0, // MergeMem: 188
  0, // MinI: 189
  0, // ModD: 190
  0, // ModF: 191
  0, // ModI: 192
  0, // ModL: 193
  0, // MoveI2F: 194
  0, // MoveF2I: 195
  0, // MoveL2D: 196
  0, // MoveD2L: 197
  0, // MulD: 198
  0, // MulF: 199
  0, // MulHiL: 200
  0, // MulI: 201
  0, // MulL: 202
  0, // Multi: 203
  0, // NegD: 204
  0, // NegF: 205
  0, // NeverBranch: 206
  0, // OnSpinWait: 207
  0, // Opaque1: 208
  0, // Opaque2: 209
  0, // Opaque3: 210
  0, // ProfileBoolean: 211
  0, // OrI: 212
  0, // OrL: 213
  1, // OverflowAddI: 214
  1, // OverflowSubI: 215
  1, // OverflowMulI: 216
  1, // OverflowAddL: 217
  1, // OverflowSubL: 218
  1, // OverflowMulL: 219
  0, // PCTable: 220
  0, // Parm: 221
  0, // PartialSubtypeCheck: 222
  0, // Phi: 223
  0, // PopCountI: 224
  0, // PopCountL: 225
  0, // PrefetchAllocation: 226
  0, // Proj: 227
  0, // RShiftI: 228
  0, // RShiftL: 229
  0, // Region: 230
  0, // Rethrow: 231
  0, // Return: 232
  0, // Root: 233
  0, // RoundDouble: 234
  0, // RoundFloat: 235
  0, // SafePoint: 236
  0, // SafePointScalarObject: 237
  0, // SCMemProj: 238
  0, // SqrtD: 239
  0, // Start: 240
  0, // StartOSR: 241
  0, // StoreB: 242
  0, // StoreC: 243
  0, // StoreCM: 244
  0, // StorePConditional: 245
  0, // StoreIConditional: 246
  0, // StoreLConditional: 247
  0, // StoreD: 248
  0, // StoreF: 249
  0, // StoreI: 250
  0, // StoreL: 251
  0, // StoreP: 252
  0, // StoreN: 253
  0, // StoreNKlass: 254
  0, // StrComp: 255
  0, // StrCompressedCopy: 256
  0, // StrEquals: 257
  0, // StrIndexOf: 258
  0, // StrIndexOfChar: 259
  0, // StrInflatedCopy: 260
  0, // SubD: 261
  0, // SubF: 262
  0, // SubI: 263
  0, // SubL: 264
  0, // TailCall: 265
  0, // TailJump: 266
  0, // ThreadLocal: 267
  0, // Unlock: 268
  0, // URShiftI: 269
  0, // URShiftL: 270
  0, // XorI: 271
  0, // XorL: 272
  0, // Vector: 273
  0, // AddVB: 274
  0, // AddVS: 275
  0, // AddVI: 276
  0, // AddReductionVI: 277
  0, // AddVL: 278
  0, // AddReductionVL: 279
  0, // AddVF: 280
  0, // AddReductionVF: 281
  0, // AddVD: 282
  0, // AddReductionVD: 283
  0, // SubVB: 284
  0, // SubVS: 285
  0, // SubVI: 286
  0, // SubVL: 287
  0, // SubVF: 288
  0, // SubVD: 289
  0, // MulVS: 290
  0, // MulVI: 291
  0, // MulReductionVI: 292
  0, // MulVL: 293
  0, // MulReductionVL: 294
  0, // MulVF: 295
  0, // MulReductionVF: 296
  0, // MulVD: 297
  0, // MulReductionVD: 298
  0, // DivVF: 299
  0, // DivVD: 300
  0, // AbsVF: 301
  0, // AbsVD: 302
  0, // NegVF: 303
  0, // NegVD: 304
  0, // SqrtVD: 305
  0, // LShiftCntV: 306
  0, // RShiftCntV: 307
  0, // LShiftVB: 308
  0, // LShiftVS: 309
  0, // LShiftVI: 310
  0, // LShiftVL: 311
  0, // RShiftVB: 312
  0, // RShiftVS: 313
  0, // RShiftVI: 314
  0, // RShiftVL: 315
  0, // URShiftVB: 316
  0, // URShiftVS: 317
  0, // URShiftVI: 318
  0, // URShiftVL: 319
  0, // AndV: 320
  0, // OrV: 321
  0, // XorV: 322
  0, // LoadVector: 323
  0, // StoreVector: 324
  0, // Pack: 325
  0, // PackB: 326
  0, // PackS: 327
  0, // PackI: 328
  0, // PackL: 329
  0, // PackF: 330
  0, // PackD: 331
  0, // Pack2L: 332
  0, // Pack2D: 333
  0, // ReplicateB: 334
  0, // ReplicateS: 335
  0, // ReplicateI: 336
  0, // ReplicateL: 337
  0, // ReplicateF: 338
  0, // ReplicateD: 339
  0, // Extract: 340
  0, // ExtractB: 341
  0, // ExtractUB: 342
  0, // ExtractC: 343
  0, // ExtractS: 344
  0, // ExtractI: 345
  0, // ExtractL: 346
  0, // ExtractF: 347
  0 // no trailing comma // ExtractD: 348
};
//  The following instructions can cisc-spill



// An array of character pointers to machine register names.
const char *Matcher::regName[REG_COUNT] = {
  "R_R4",
  "R_R5",
  "R_R6",
  "R_R7",
  "R_R8",
  "R_R9",
  "R_R11",
  "R_R12",
  "R_R10",
  "R_R13",
  "R_R14",
  "R_R15",
  "R_R0",
  "R_R1",
  "R_R2",
  "R_R3",
  "R_S16",
  "R_S17",
  "R_S18",
  "R_S19",
  "R_S20",
  "R_S21",
  "R_S22",
  "R_S23",
  "R_S24",
  "R_S25",
  "R_S26",
  "R_S27",
  "R_S28",
  "R_S29",
  "R_S30",
  "R_S31",
  "R_S0",
  "R_S1",
  "R_S2",
  "R_S3",
  "R_S4",
  "R_S5",
  "R_S6",
  "R_S7",
  "R_S8",
  "R_S9",
  "R_S10",
  "R_S11",
  "R_S12",
  "R_S13",
  "R_S14",
  "R_S15",
  "R_D16",
  "R_D16x",
  "R_D17",
  "R_D17x",
  "R_D18",
  "R_D18x",
  "R_D19",
  "R_D19x",
  "R_D20",
  "R_D20x",
  "R_D21",
  "R_D21x",
  "R_D22",
  "R_D22x",
  "R_D23",
  "R_D23x",
  "R_D24",
  "R_D24x",
  "R_D25",
  "R_D25x",
  "R_D26",
  "R_D26x",
  "R_D27",
  "R_D27x",
  "R_D28",
  "R_D28x",
  "R_D29",
  "R_D29x",
  "R_D30",
  "R_D30x",
  "R_D31",
  "R_D31x",
  "APSR",
  "FPSCR" // no trailing comma
};

// An array of character pointers to machine register names.
const VMReg OptoReg::opto2vm[REG_COUNT] = {
	R(4)->as_VMReg(),
	R(5)->as_VMReg(),
	R(6)->as_VMReg(),
	R(7)->as_VMReg(),
	R(8)->as_VMReg(),
	R(9)->as_VMReg(),
	R(11)->as_VMReg(),
	R(12)->as_VMReg(),
	R(10)->as_VMReg(),
	R(13)->as_VMReg(),
	R(14)->as_VMReg(),
	R(15)->as_VMReg(),
	R(0)->as_VMReg(),
	R(1)->as_VMReg(),
	R(2)->as_VMReg(),
	R(3)->as_VMReg(),
	S16->as_VMReg(),
	S17->as_VMReg(),
	S18->as_VMReg(),
	S19->as_VMReg(),
	S20->as_VMReg(),
	S21->as_VMReg(),
	S22->as_VMReg(),
	S23->as_VMReg(),
	S24->as_VMReg(),
	S25->as_VMReg(),
	S26->as_VMReg(),
	S27->as_VMReg(),
	S28->as_VMReg(),
	S29->as_VMReg(),
	S30->as_VMReg(),
	S31->as_VMReg(),
	S0->as_VMReg(),
	S1_reg->as_VMReg(),
	S2_reg->as_VMReg(),
	S3_reg->as_VMReg(),
	S4_reg->as_VMReg(),
	S5_reg->as_VMReg(),
	S6_reg->as_VMReg(),
	S7->as_VMReg(),
	S8->as_VMReg(),
	S9->as_VMReg(),
	S10->as_VMReg(),
	S11->as_VMReg(),
	S12->as_VMReg(),
	S13->as_VMReg(),
	S14->as_VMReg(),
	S15->as_VMReg(),
	D16->as_VMReg(),
	D16->as_VMReg()->next(),
	D17->as_VMReg(),
	D17->as_VMReg()->next(),
	D18->as_VMReg(),
	D18->as_VMReg()->next(),
	D19->as_VMReg(),
	D19->as_VMReg()->next(),
	D20->as_VMReg(),
	D20->as_VMReg()->next(),
	D21->as_VMReg(),
	D21->as_VMReg()->next(),
	D22->as_VMReg(),
	D22->as_VMReg()->next(),
	D23->as_VMReg(),
	D23->as_VMReg()->next(),
	D24->as_VMReg(),
	D24->as_VMReg()->next(),
	D25->as_VMReg(),
	D25->as_VMReg()->next(),
	D26->as_VMReg(),
	D26->as_VMReg()->next(),
	D27->as_VMReg(),
	D27->as_VMReg()->next(),
	D28->as_VMReg(),
	D28->as_VMReg()->next(),
	D29->as_VMReg(),
	D29->as_VMReg()->next(),
	D30->as_VMReg(),
	D30->as_VMReg()->next(),
	D31->as_VMReg(),
	D31->as_VMReg()->next(),
	VMRegImpl::Bad(),
	VMRegImpl::Bad() // no trailing comma
	};

 OptoReg::Name OptoReg::vm2opto[ConcreteRegisterImpl::number_of_registers];

// An array of the machine register encode values
const unsigned char Matcher::_regEncode[REG_COUNT] = {
  (unsigned char)'\x4',  // R_R4
  (unsigned char)'\x5',  // R_R5
  (unsigned char)'\x6',  // R_R6
  (unsigned char)'\x7',  // R_R7
  (unsigned char)'\x8',  // R_R8
  (unsigned char)'\x9',  // R_R9
  (unsigned char)'\xB',  // R_R11
  (unsigned char)'\xC',  // R_R12
  (unsigned char)'\xA',  // R_R10
  (unsigned char)'\xD',  // R_R13
  (unsigned char)'\xE',  // R_R14
  (unsigned char)'\xF',  // R_R15
  (unsigned char)'\x0',  // R_R0
  (unsigned char)'\x1',  // R_R1
  (unsigned char)'\x2',  // R_R2
  (unsigned char)'\x3',  // R_R3
  (unsigned char)'\x10',  // R_S16
  (unsigned char)'\x11',  // R_S17
  (unsigned char)'\x12',  // R_S18
  (unsigned char)'\x13',  // R_S19
  (unsigned char)'\x14',  // R_S20
  (unsigned char)'\x15',  // R_S21
  (unsigned char)'\x16',  // R_S22
  (unsigned char)'\x17',  // R_S23
  (unsigned char)'\x18',  // R_S24
  (unsigned char)'\x19',  // R_S25
  (unsigned char)'\x1A',  // R_S26
  (unsigned char)'\x1B',  // R_S27
  (unsigned char)'\x1C',  // R_S28
  (unsigned char)'\x1D',  // R_S29
  (unsigned char)'\x1E',  // R_S30
  (unsigned char)'\x1F',  // R_S31
  (unsigned char)'\x0',  // R_S0
  (unsigned char)'\x1',  // R_S1
  (unsigned char)'\x2',  // R_S2
  (unsigned char)'\x3',  // R_S3
  (unsigned char)'\x4',  // R_S4
  (unsigned char)'\x5',  // R_S5
  (unsigned char)'\x6',  // R_S6
  (unsigned char)'\x7',  // R_S7
  (unsigned char)'\x8',  // R_S8
  (unsigned char)'\x9',  // R_S9
  (unsigned char)'\xA',  // R_S10
  (unsigned char)'\xB',  // R_S11
  (unsigned char)'\xC',  // R_S12
  (unsigned char)'\xD',  // R_S13
  (unsigned char)'\xE',  // R_S14
  (unsigned char)'\xF',  // R_S15
  (unsigned char)'\x20',  // R_D16
  (unsigned char)'\xFF',  // R_D16x
  (unsigned char)'\x22',  // R_D17
  (unsigned char)'\xFF',  // R_D17x
  (unsigned char)'\x24',  // R_D18
  (unsigned char)'\xFF',  // R_D18x
  (unsigned char)'\x26',  // R_D19
  (unsigned char)'\xFF',  // R_D19x
  (unsigned char)'\x28',  // R_D20
  (unsigned char)'\xFF',  // R_D20x
  (unsigned char)'\x2A',  // R_D21
  (unsigned char)'\xFF',  // R_D21x
  (unsigned char)'\x2C',  // R_D22
  (unsigned char)'\xFF',  // R_D22x
  (unsigned char)'\x2E',  // R_D23
  (unsigned char)'\xFF',  // R_D23x
  (unsigned char)'\x30',  // R_D24
  (unsigned char)'\xFF',  // R_D24x
  (unsigned char)'\x32',  // R_D25
  (unsigned char)'\xFF',  // R_D25x
  (unsigned char)'\x34',  // R_D26
  (unsigned char)'\xFF',  // R_D26x
  (unsigned char)'\x36',  // R_D27
  (unsigned char)'\xFF',  // R_D27x
  (unsigned char)'\x38',  // R_D28
  (unsigned char)'\xFF',  // R_D28x
  (unsigned char)'\x3A',  // R_D29
  (unsigned char)'\xFF',  // R_D29x
  (unsigned char)'\x3C',  // R_D30
  (unsigned char)'\xFF',  // R_D30x
  (unsigned char)'\x3E',  // R_D31
  (unsigned char)'\xFF',  // R_D31x
  (unsigned char)'\x0',  // APSR
  (unsigned char)'\x0' // no trailing comma  // FPSCR
};


//------------------Define classes derived from MachOper---------------------
MachOper  *labelOper::clone() const {
  return  new labelOper(_label, _block_num);
}
uint labelOper::opcode() const { return LABEL; }

const RegMask *sRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

MachOper  *methodOper::clone() const {
  return  new methodOper(_method);
}
uint methodOper::opcode() const { return METHOD; }

const RegMask *iRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_REG_mask();
}

const RegMask *iRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &PTR_REG_mask();
}

const RegMask *sp_ptr_RegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *R0RegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R0_REGP_mask();
}

const RegMask *R1RegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R1_REGP_mask();
}

const RegMask *R2RegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R2_REGP_mask();
}

const RegMask *RExceptionRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &REXCEPTION_REGP_mask();
}

const RegMask *RthreadRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &RTHREAD_REGP_mask();
}

const RegMask *IPRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &IP_REGP_mask();
}

const RegMask *LRRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &LR_REGP_mask();
}

const RegMask *R0RegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R0_REGI_mask();
}

const RegMask *R1RegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R1_REGI_mask();
}

const RegMask *R2RegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R2_REGI_mask();
}

const RegMask *R3RegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R3_REGI_mask();
}

const RegMask *R12RegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R12_REGI_mask();
}

const RegMask *iRegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &LONG_REG_mask();
}

const RegMask *iRegLdOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &LONG_REG_ALIGN_mask();
}

const RegMask *R0R1RegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R0R1_REGL_mask();
}

const RegMask *R2R3RegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &R2R3_REGL_mask();
}

const RegMask *flagsRegOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsReg_EQNELTGEOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsRegUOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsRegL_LTGEOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsRegL_EQNEOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsRegL_LEGTOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask();
}

const RegMask *flagsRegFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &FLOAT_FLAGS_mask();
}

const RegMask *vecDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ACTUAL_DFLT_REG_mask();
}

const RegMask *vecXOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &VECTORX_REG_mask();
}

const RegMask *regDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ACTUAL_DFLT_REG_mask();
}

const RegMask *regFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SFLT_REG_mask();
}

const RegMask *regD_lowOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &DFLT_LOW_REG_mask();
}

const RegMask *inline_cache_regPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &RICKLASS_REGP_mask();
}

const RegMask *interpreter_method_oop_regPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &RMETHOD_REGP_mask();
}

const RegMask *indirectOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *indOffset12Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *indOffsetFPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *indOffsetHDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *indOffsetFPx2Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *indOffset12x2Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &SP_PTR_REG_mask();
}

const RegMask *indIndexOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  switch (index) {
  case 0: return &PTR_REG_mask();
  case 1: return &INT_REG_mask();
  }
  ShouldNotReachHere();
  return NULL;
}

const RegMask *indIndexScaleOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  switch (index) {
  case 0: return &PTR_REG_mask();
  case 1: return &INT_REG_mask();
  }
  ShouldNotReachHere();
  return NULL;
}

const RegMask *shiftedXOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_REG_mask();
}

//------------------Define members for classes derived from MachNode----------

// Copy _idx, inputs and operands to new node
void MachNode::fill_new_machnode(MachNode* node) const {
  // This architecture does not have cisc or short branch instructions
  ShouldNotCallThis();
}

void branchNode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(1));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchNode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(1));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchConNode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchConNode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchCon_EQNELTGENode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchCon_EQNELTGENode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchConUNode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchConUNode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchConPNode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchConPNode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchConL_LTGENode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchConL_LTGENode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchConL_EQNENode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchConL_EQNENode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchConL_LEGTNode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchConL_LEGTNode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void branchLoopEndNode::label_set( Label* label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = label;
  oper->_block_num = block_num;
}
void branchLoopEndNode::save_label( Label** label, uint* block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  *label = oper->_label;
  *block_num = oper->_block_num;
}
void CallStaticJavaDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallStaticJavaHandleNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallDynamicJavaDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallRuntimeDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallLeafDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallLeafNoFPDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

int loadBNode::reloc() const {
  return 1;
}

int loadB2LNode::reloc() const {
  return 1;
}

int loadUBNode::reloc() const {
  return 1;
}

int loadUB2LNode::reloc() const {
  return 1;
}

int loadUB2L_limmINode::reloc() const {
  return 1;
}

int loadSNode::reloc() const {
  return 1;
}

int loadS2BNode::reloc() const {
  return 1;
}

int loadS2LNode::reloc() const {
  return 1;
}

int loadUSNode::reloc() const {
  return 1;
}

int loadUS2BNode::reloc() const {
  return 1;
}

int loadUS2LNode::reloc() const {
  return 1;
}

int loadUS2L_immI_255Node::reloc() const {
  return 1;
}

int loadUS2L_limmINode::reloc() const {
  return 1;
}

int loadINode::reloc() const {
  return 1;
}

int loadI2BNode::reloc() const {
  return 1;
}

int loadI2UBNode::reloc() const {
  return 1;
}

int loadI2SNode::reloc() const {
  return 1;
}

int loadI2USNode::reloc() const {
  return 1;
}

int loadI2LNode::reloc() const {
  return 1;
}

int loadI2L_immI_255Node::reloc() const {
  return 1;
}

int loadI2L_immI_65535Node::reloc() const {
  return 1;
}

int loadI2L_limmU31Node::reloc() const {
  return 1;
}

int loadI2L_immU31Node::reloc() const {
  return 1;
}

int loadUI2LNode::reloc() const {
  return 1;
}

int loadLNode::reloc() const {
  return 1;
}

int loadL_2instrNode::reloc() const {
  return 1;
}

int loadL_volatile_fpNode::reloc() const {
  return 1;
}

int loadL_unalignedNode::reloc() const {
  return 1;
}

int loadRangeNode::reloc() const {
  return 1;
}

int loadPNode::reloc() const {
  return 1;
}

int loadKlassNode::reloc() const {
  return 1;
}

int loadDNode::reloc() const {
  return 1;
}

int loadD_unalignedNode::reloc() const {
  return 1;
}

int loadFNode::reloc() const {
  return 1;
}

int loadConPNode::reloc() const {
  return 1;
}

int loadConP_pollNode::reloc() const {
  return 1;
}

int loadConF_imm8Node::reloc() const {
  return 2;
}

int loadConFNode::reloc() const {
  return 2;
}

int loadConD_imm8Node::reloc() const {
  return 2;
}

int loadConDNode::reloc() const {
  return 2;
}

int prefetchAlloc_mpNode::reloc() const {
  return 1;
}

int prefetchAlloc_spNode::reloc() const {
  return 1;
}

int storeBNode::reloc() const {
  return 2;
}

int storeCMNode::reloc() const {
  return 2;
}

int storeCNode::reloc() const {
  return 2;
}

int storeINode::reloc() const {
  return 2;
}

int storeLNode::reloc() const {
  return 2;
}

int storeL_2instrNode::reloc() const {
  return 2;
}

int storeL_volatile_fpNode::reloc() const {
  return 2;
}

int storePNode::reloc() const {
  return 2;
}

int storeDNode::reloc() const {
  return 2;
}

int storeFNode::reloc() const {
  return 2;
}

int cmovPP_immNode::reloc() const {
  return 1;
}

int cmovPI_immNode::reloc() const {
  return 1;
}

int cmovPI_imm_EQNELTGENode::reloc() const {
  return 1;
}

int cmovPIu_immNode::reloc() const {
  return 1;
}

int loadPLockedNode::reloc() const {
  return 1;
}

int storePConditionalNode::reloc() const {
  return 1;
}

int storeXConditionalNode::reloc() const {
  return 1;
}

int compareAndSwapL_boolNode::reloc() const {
  return 1;
}

int compareAndSwapI_boolNode::reloc() const {
  return 1;
}

int compareAndSwapP_boolNode::reloc() const {
  return 1;
}

int xaddI_aimmI_no_resNode::reloc() const {
  return 1;
}

int xaddI_reg_no_resNode::reloc() const {
  return 1;
}

int xaddI_aimmINode::reloc() const {
  return 1;
}

int xaddI_regNode::reloc() const {
  return 1;
}

int xaddL_reg_no_resNode::reloc() const {
  return 1;
}

int xaddL_immRot_no_resNode::reloc() const {
  return 1;
}

int xaddL_regNode::reloc() const {
  return 1;
}

int xaddL_immRotNode::reloc() const {
  return 1;
}

int xchgINode::reloc() const {
  return 1;
}

int xchgLNode::reloc() const {
  return 1;
}

int xchgPNode::reloc() const {
  return 1;
}

int compP_iRegP_immNode::reloc() const {
  return 1;
}

int cmpF0_ccNode::reloc() const {
  return 1;
}

int cmpD0_ccNode::reloc() const {
  return 1;
}

int cmpF0_regNode::reloc() const {
  return 1;
}

int cmpD0_regNode::reloc() const {
  return 1;
}

int cmovPL_imm_LTGENode::reloc() const {
  return 1;
}

int cmovPL_imm_EQNENode::reloc() const {
  return 1;
}

int cmovPL_imm_LEGTNode::reloc() const {
  return 1;
}

int safePoint_pollNode::reloc() const {
  return 1;
}

int CallStaticJavaDirectNode::reloc() const {
  return 1;
}

int CallStaticJavaHandleNode::reloc() const {
  return 1;
}

int CallDynamicJavaDirectNode::reloc() const {
  return 1;
}

int CallRuntimeDirectNode::reloc() const {
  return 1;
}

int CallLeafDirectNode::reloc() const {
  return 1;
}

int CallLeafNoFPDirectNode::reloc() const {
  return 1;
}

int TailCalljmpIndNode::reloc() const {
  return 1;
}

int RetNode::reloc() const {
  return 1;
}

int tailjmpIndNode::reloc() const {
  return 1;
}

int RethrowExceptionNode::reloc() const {
  return 1;
}

int loadV8Node::reloc() const {
  return 1;
}

int loadV16Node::reloc() const {
  return 1;
}

int storeV8Node::reloc() const {
  return 2;
}

int storeV16Node::reloc() const {
  return 2;
}

int Repl2F_immINode::reloc() const {
  return 1;
}


void loadBNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4108 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // High 32 bits are harmlessly set on Aarch64
    __ ldrsb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 6777 "ad_arm.cpp"
  }
}

uint loadBNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadB2LNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4130 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrsb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(0)->as_Register(ra_,this)/* dst */, asr, 31));
  
#line 6799 "ad_arm.cpp"
  }
}

uint loadB2LNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadUBNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4145 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 6820 "ad_arm.cpp"
  }
}

uint loadUBNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadUB2LNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4166 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 6842 "ad_arm.cpp"
  }
}

uint loadUB2LNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadUB2L_limmINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4193 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, limmI_low(opnd_array(2)->constant(), 8));
  
#line 6866 "ad_arm.cpp"
  }
}

uint loadUB2L_limmINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void loadSNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4228 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrsh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 6887 "ad_arm.cpp"
  }
}

uint loadSNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadS2BNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// twentyfour
  {
    MacroAssembler _masm(&cbuf);

#line 4242 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // High 32 bits are harmlessly set on Aarch64
    __ ldrsb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 6910 "ad_arm.cpp"
  }
}

uint loadS2BNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadS2LNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4264 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrsh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(0)->as_Register(ra_,this)/* dst */, asr, 31));
  
#line 6932 "ad_arm.cpp"
  }
}

uint loadS2LNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadUSNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4299 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 6953 "ad_arm.cpp"
  }
}

uint loadUSNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadUS2BNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// twentyfour
  {
    MacroAssembler _masm(&cbuf);

#line 4312 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrsb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 6975 "ad_arm.cpp"
  }
}

uint loadUS2BNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadUS2LNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4333 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 6997 "ad_arm.cpp"
  }
}

uint loadUS2LNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadUS2L_immI_255Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4356 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 7020 "ad_arm.cpp"
  }
}

uint loadUS2L_immI_255Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadUS2L_limmINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4384 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->constant());
  
#line 7044 "ad_arm.cpp"
  }
}

uint loadUS2L_limmINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void loadINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4420 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr_s32(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7065 "ad_arm.cpp"
  }
}

uint loadINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadI2BNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// twentyfour
  {
    MacroAssembler _masm(&cbuf);

#line 4434 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrsb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7087 "ad_arm.cpp"
  }
}

uint loadI2BNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadI2UBNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4448 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7109 "ad_arm.cpp"
  }
}

uint loadI2UBNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadI2SNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// sixteen
  {
    MacroAssembler _masm(&cbuf);

#line 4461 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrsh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7131 "ad_arm.cpp"
  }
}

uint loadI2SNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadI2USNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4474 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7153 "ad_arm.cpp"
  }
}

uint loadI2USNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadI2LNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4497 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(0)->as_Register(ra_,this)/* dst */, asr, 31));
  
#line 7175 "ad_arm.cpp"
  }
}

uint loadI2LNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadI2L_immI_255Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4522 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrb(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 7198 "ad_arm.cpp"
  }
}

uint loadI2L_immI_255Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadI2L_immI_65535Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4545 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldrh(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 7221 "ad_arm.cpp"
  }
}

uint loadI2L_immI_65535Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadI2L_limmU31Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4580 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->constant());
  
#line 7245 "ad_arm.cpp"
  }
}

uint loadI2L_limmU31Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void loadI2L_immU31Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 4620 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0);
    __ mov_slow(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->constant());
    __ andr(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */);
  
#line 7272 "ad_arm.cpp"
  }
}

uint loadI2L_immU31Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void loadUI2LNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 4645 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 7295 "ad_arm.cpp"
  }
}

uint loadUI2LNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  {
    MacroAssembler _masm(&cbuf);

#line 4686 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr_64(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7317 "ad_arm.cpp"
  }
}

uint loadLNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadL_2instrNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4701 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Address Amemlo = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), relocInfo::none);
    Address Amemhi = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1)+ 4, relocInfo::none);

    if (opnd_array(0)->as_Register(ra_,this)/* dst */== reg_to_register_object(opnd_array(1)->base(ra_,this,idx1))) {
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), Amemhi);
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Amemlo);
    } else {
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Amemlo);
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), Amemhi);
    }
  
#line 7347 "ad_arm.cpp"
  }
}

uint loadL_2instrNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadL_volatileNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4723 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // FIXME: why is ldmia considered atomic?  Should be ldrexd
    RegisterSet set(opnd_array(0)->as_Register(ra_,this)/* dst */);
    set = set | reg_to_register_object(opnd_array(0)->reg(ra_,this)/* dst */+ 1);
    __ ldmia(reg_to_register_object(opnd_array(1)->base(ra_,this,idx1)), set);
  
#line 7371 "ad_arm.cpp"
  }
}

uint loadL_volatileNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadL_volatile_fpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4740 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fldd(S14, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ fmrrd(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), S14);
  
#line 7393 "ad_arm.cpp"
  }
}

uint loadL_volatile_fpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadL_unalignedNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4754 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Address Amemlo = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), relocInfo::none);
    Address Amemhi = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1)+ 4, relocInfo::none);

    if (opnd_array(0)->as_Register(ra_,this)/* dst */== reg_to_register_object(opnd_array(1)->base(ra_,this,idx1))) {
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), Amemhi);
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Amemlo);
    } else {
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Amemlo);
      __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), Amemhi);
    }
  
#line 7423 "ad_arm.cpp"
  }
}

uint loadL_unalignedNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadRangeNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4777 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr_u32(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7444 "ad_arm.cpp"
  }
}

uint loadRangeNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4810 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7465 "ad_arm.cpp"
  }
}

uint loadPNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadKlassNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4875 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr(opnd_array(0)->as_Register(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7486 "ad_arm.cpp"
  }
}

uint loadKlassNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4923 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7507 "ad_arm.cpp"
  }
}

uint loadDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadD_unalignedNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4937 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Address Amemlo = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), relocInfo::none);
    Address Amemhi = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1)+ 4, relocInfo::none);
      __ flds(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Amemlo);
      __ flds(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor(), Amemhi);
  
#line 7531 "ad_arm.cpp"
  }
}

uint loadD_unalignedNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadFNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 4972 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7552 "ad_arm.cpp"
  }
}

uint loadFNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 4995 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov_slow(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->constant());
  
#line 7573 "ad_arm.cpp"
  }
}

void loadConIMovNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5005 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->constant());
  
#line 7589 "ad_arm.cpp"
  }
}

uint loadConIMovNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConIMovnNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5016 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mvn(opnd_array(0)->as_Register(ra_,this)/* dst */, ~opnd_array(1)->constant());
  
#line 7610 "ad_arm.cpp"
  }
}

uint loadConIMovnNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConI16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5031 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ mov_w(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->constant());
#else
    __ movw(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->constant());
#endif
  
#line 7635 "ad_arm.cpp"
  }
}

uint loadConI16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5045 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    relocInfo::relocType constant_reloc = _opnds[1]->constant_reloc();
    intptr_t val = opnd_array(1)->constant();
    if (constant_reloc == relocInfo::oop_type) {
      __ mov_oop(opnd_array(0)->as_Register(ra_,this)/* dst */, (jobject)val);
    } else if (constant_reloc == relocInfo::metadata_type) {
      __ mov_metadata(opnd_array(0)->as_Register(ra_,this)/* dst */, (Metadata*)val);
    } else {
      __ mov_slow(opnd_array(0)->as_Register(ra_,this)/* dst */, val);
    }
  
#line 7664 "ad_arm.cpp"
  }
}

void loadConP_pollNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5064 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

      __ mov_slow(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->constant());
  
#line 7680 "ad_arm.cpp"
  }
}

void loadConLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5149 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov_slow(reg_to_register_object(opnd_array(0)->reg(ra_,this)/* dst */), opnd_array(1)->constantL()& 0x0FFFFFFFFL);
    __ mov_slow(reg_to_register_object(opnd_array(0)->reg(ra_,this)/* dst */+ 1), ((julong)(opnd_array(1)->constantL())) >> 32);
  
#line 7697 "ad_arm.cpp"
  }
}

void loadConL16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5163 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->constantL());
    __ movw(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 7714 "ad_arm.cpp"
  }
}

uint loadConL16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadConF_imm8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5178 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fconsts(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Assembler::float_num(opnd_array(1)->constantF()).imm8());
  
#line 7735 "ad_arm.cpp"
  }
}

uint loadConF_imm8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConFNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 5213 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // FIXME revisit once 6961697 is in
    union {
      jfloat f;
      int i;
    } v;
    v.f = opnd_array(1)->constantF();
    __ mov_slow(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, v.i);
    __ fmsr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 7764 "ad_arm.cpp"
  }
}

uint loadConFNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 3*4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 3*4);
}

void loadConD_imm8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5233 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fconstd(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Assembler::double_num(opnd_array(1)->constantD()).imm8());
  
#line 7785 "ad_arm.cpp"
  }
}

uint loadConD_imm8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 5245 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Register r = as_Register(ra_->get_encode(in(mach_constant_base_node_input())));
    int offset  = constant_offset();
    if (!is_memoryD(offset)) {                // can't use a predicate
                                              // in load constant instructs
      __ add_slow(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, r, offset);
      r = opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */;
      offset = 0;
    }
    __ ldr_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Address(r, offset));
  
#line 7815 "ad_arm.cpp"
  }
}

void loadConDNode::eval_constant(Compile* C) {
  {

#line 5247 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"
    _constant = C->constant_table().add(this, opnd_array(1));
#line 7824 "ad_arm.cpp"
  }
}
void prefetchAlloc_mpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5269 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ prfm(pstl1keep, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
#else
    __ pldw(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
#endif
  
#line 7843 "ad_arm.cpp"
  }
}

uint prefetchAlloc_mpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void prefetchAlloc_spNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5286 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ prfm(pstl1keep, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
#else
    __ pld(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
#endif
  
#line 7868 "ad_arm.cpp"
  }
}

uint prefetchAlloc_spNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeBNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5304 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ strb(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7890 "ad_arm.cpp"
  }
}

uint storeBNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeCMNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5316 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ strb(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7912 "ad_arm.cpp"
  }
}

uint storeCMNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeCNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5349 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ strh(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7934 "ad_arm.cpp"
  }
}

uint storeCNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5382 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ str_32(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7956 "ad_arm.cpp"
  }
}

uint storeINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5421 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ str_64(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 7978 "ad_arm.cpp"
  }
}

uint storeLNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeL_2instrNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5437 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Address Amemlo = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), relocInfo::none);
    Address Amemhi = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1)+ 4, relocInfo::none);
    __ str(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Amemlo);
    __ str(opnd_array(2)->as_Register(ra_,this,idx2)/* src */->successor(), Amemhi);
  
#line 8003 "ad_arm.cpp"
  }
}

uint storeL_2instrNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void storeL_volatileNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5452 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // FIXME: why is stmia considered atomic?  Should be strexd
    RegisterSet set(opnd_array(2)->as_Register(ra_,this,idx2)/* src */);
    set = set | reg_to_register_object(opnd_array(2)->reg(ra_,this,idx2)/* src */+ 1);
    __ stmia(reg_to_register_object(opnd_array(1)->base(ra_,this,idx1)), set);
  
#line 8028 "ad_arm.cpp"
  }
}

uint storeL_volatileNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeL_volatile_fpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5470 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(S14, opnd_array(2)->as_Register(ra_,this,idx2)/* src */, opnd_array(2)->as_Register(ra_,this,idx2)/* src */->successor());
    __ fstd(S14, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 8051 "ad_arm.cpp"
  }
}

uint storeL_volatile_fpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void storePNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5556 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ str(opnd_array(2)->as_Register(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 8073 "ad_arm.cpp"
  }
}

uint storePNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5669 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ str_double(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 8095 "ad_arm.cpp"
  }
}

uint storeDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeFNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5726 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ str_float(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 8117 "ad_arm.cpp"
  }
}

uint storeFNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void membar_storestoreNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5808 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ membar(MacroAssembler::Membar_mask_bits(MacroAssembler::StoreStore), noreg);
  
#line 8138 "ad_arm.cpp"
  }
}

uint membar_storestoreNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void membar_acquireNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5821 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ membar(MacroAssembler::Membar_mask_bits(MacroAssembler::LoadLoad | MacroAssembler::LoadStore), noreg);
  
#line 8159 "ad_arm.cpp"
  }
}

uint membar_acquireNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void membar_acquire_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5821 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ membar(MacroAssembler::Membar_mask_bits(MacroAssembler::LoadLoad | MacroAssembler::LoadStore), noreg);
  
#line 8180 "ad_arm.cpp"
  }
}

uint membar_acquire_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void membar_acquire_lockNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  // User did not define which encode class to use.
}

uint membar_acquire_lockNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 0);
}

void membar_releaseNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5844 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ membar(MacroAssembler::Membar_mask_bits(MacroAssembler::StoreStore | MacroAssembler::LoadStore), noreg);
  
#line 8214 "ad_arm.cpp"
  }
}

uint membar_releaseNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void membar_release_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5844 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ membar(MacroAssembler::Membar_mask_bits(MacroAssembler::StoreStore | MacroAssembler::LoadStore), noreg);
  
#line 8235 "ad_arm.cpp"
  }
}

uint membar_release_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void membar_release_lockNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  // User did not define which encode class to use.
}

uint membar_release_lockNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 0);
}

void membar_volatileNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 5866 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ membar(MacroAssembler::StoreLoad, noreg);
  
#line 8269 "ad_arm.cpp"
  }
}

uint membar_volatileNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void unnecessary_membar_volatileNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  // User did not define which encode class to use.
}

uint unnecessary_membar_volatileNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 0);
}

void castX2PNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5949 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    if (opnd_array(0)->as_Register(ra_,this)/* dst */!=  opnd_array(1)->as_Register(ra_,this,idx1)/* src */) {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    }
  
#line 8305 "ad_arm.cpp"
  }
}

void castP2XNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5962 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    if (opnd_array(0)->as_Register(ra_,this)/* dst */!=  opnd_array(1)->as_Register(ra_,this,idx1)/* src */) {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    }
  
#line 8323 "ad_arm.cpp"
  }
}

void cmovIP_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 5978 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8342 "ad_arm.cpp"
  }
}

uint cmovIP_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIP_immMovNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6169 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8366 "ad_arm.cpp"
  }
}

uint cmovIP_immMovNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIP_imm16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6180 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8390 "ad_arm.cpp"
  }
}

uint cmovIP_imm16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovI_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6192 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8414 "ad_arm.cpp"
  }
}

uint cmovI_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovI_immMovNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6217 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8438 "ad_arm.cpp"
  }
}

uint cmovI_immMovNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovII_imm16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6228 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8462 "ad_arm.cpp"
  }
}

uint cmovII_imm16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovII_reg_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6244 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8486 "ad_arm.cpp"
  }
}

uint cmovII_reg_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovII_immMov_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6260 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8510 "ad_arm.cpp"
  }
}

uint cmovII_immMov_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovII_imm16_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6275 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8534 "ad_arm.cpp"
  }
}

uint cmovII_imm16_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIIu_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6287 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8558 "ad_arm.cpp"
  }
}

uint cmovIIu_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIIu_immMovNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6299 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8582 "ad_arm.cpp"
  }
}

uint cmovIIu_immMovNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIIu_imm16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6310 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8606 "ad_arm.cpp"
  }
}

uint cmovIIu_imm16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPP_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6323 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8630 "ad_arm.cpp"
  }
}

uint cmovPP_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPP_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6338 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */,             ZR, (AsmCondition)(opnd_array(1)->ccode()));
#else
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
#endif
  
#line 8658 "ad_arm.cpp"
  }
}

uint cmovPP_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPI_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6355 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8682 "ad_arm.cpp"
  }
}

uint cmovPI_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPI_reg_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6371 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8706 "ad_arm.cpp"
  }
}

uint cmovPI_reg_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPIu_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6383 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8730 "ad_arm.cpp"
  }
}

uint cmovPIu_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPI_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6399 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */,             ZR, (AsmCondition)(opnd_array(1)->ccode()));
#else
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
#endif
  
#line 8758 "ad_arm.cpp"
  }
}

uint cmovPI_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPI_imm_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6423 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */,             ZR, (AsmCondition)(opnd_array(1)->ccode()));
#else
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
#endif
  
#line 8786 "ad_arm.cpp"
  }
}

uint cmovPI_imm_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPIu_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6443 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */,             ZR, (AsmCondition)(opnd_array(1)->ccode()));
#else
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
#endif
  
#line 8814 "ad_arm.cpp"
  }
}

uint cmovPIu_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovFP_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6551 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8838 "ad_arm.cpp"
  }
}

uint cmovFP_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovFI_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6563 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8862 "ad_arm.cpp"
  }
}

uint cmovFI_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovFI_reg_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6579 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8886 "ad_arm.cpp"
  }
}

uint cmovFI_reg_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovFIu_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6591 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8910 "ad_arm.cpp"
  }
}

uint cmovFIu_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDP_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6603 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8934 "ad_arm.cpp"
  }
}

uint cmovDP_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDI_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6615 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8958 "ad_arm.cpp"
  }
}

uint cmovDI_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDI_reg_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6628 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 8982 "ad_arm.cpp"
  }
}

uint cmovDI_reg_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDIu_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6640 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9006 "ad_arm.cpp"
  }
}

uint cmovDIu_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovLP_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6654 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9031 "ad_arm.cpp"
  }
}

uint cmovLP_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLP_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6670 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constantL(), (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9056 "ad_arm.cpp"
  }
}

uint cmovLP_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLP_imm16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6684 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constantL(), (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9081 "ad_arm.cpp"
  }
}

uint cmovLP_imm16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLI_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6698 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9106 "ad_arm.cpp"
  }
}

uint cmovLI_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLI_reg_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6716 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9131 "ad_arm.cpp"
  }
}

uint cmovLI_reg_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLI_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6732 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constantL(), (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9156 "ad_arm.cpp"
  }
}

uint cmovLI_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLI_immRot_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6752 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constantL(), (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9181 "ad_arm.cpp"
  }
}

uint cmovLI_immRot_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLI_imm16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6766 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constantL(), (AsmCondition)(opnd_array(1)->ccode()));
    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9206 "ad_arm.cpp"
  }
}

uint cmovLI_imm16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLI_imm16_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6784 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constantL(), (AsmCondition)(opnd_array(1)->ccode()));
    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9231 "ad_arm.cpp"
  }
}

uint cmovLI_imm16_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLIu_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 6798 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 9256 "ad_arm.cpp"
  }
}

uint cmovLIu_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void tlsLoadPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  // User did not define which encode class to use.
}

uint tlsLoadPNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 0);
}

void checkCastPPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// dst
  // User did not define which encode class to use.
}

uint checkCastPPNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 0);
}

void castPPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// dst
  // User did not define which encode class to use.
}

void castIINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// dst
  // User did not define which encode class to use.
}

void addI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6855 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 9320 "ad_arm.cpp"
  }
}

uint addI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 6867 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 9343 "ad_arm.cpp"
  }
}

uint addshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshlI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6867 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src3 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 9366 "ad_arm.cpp"
  }
}

uint addshlI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshlI_reg_imm_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 6894 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->constant()));
  
#line 9389 "ad_arm.cpp"
  }
}

uint addshlI_reg_imm_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshlI_reg_imm_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6894 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src3 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsl, opnd_array(3)->constant()));
  
#line 9412 "ad_arm.cpp"
  }
}

uint addshlI_reg_imm_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 6906 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 9435 "ad_arm.cpp"
  }
}

uint addsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addsarI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6906 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src3 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, asr, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 9458 "ad_arm.cpp"
  }
}

uint addsarI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addsarI_reg_imm_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 6918 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, asr, opnd_array(2)->constant()));
  
#line 9481 "ad_arm.cpp"
  }
}

uint addsarI_reg_imm_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addsarI_reg_imm_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6918 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src3 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, asr, opnd_array(3)->constant()));
  
#line 9504 "ad_arm.cpp"
  }
}

uint addsarI_reg_imm_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 6930 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 9527 "ad_arm.cpp"
  }
}

uint addshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshrI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6930 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src3 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 9550 "ad_arm.cpp"
  }
}

uint addshrI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshrI_reg_imm_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 6942 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->constant()));
  
#line 9573 "ad_arm.cpp"
  }
}

uint addshrI_reg_imm_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshrI_reg_imm_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6942 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src3 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsr, opnd_array(3)->constant()));
  
#line 9596 "ad_arm.cpp"
  }
}

uint addshrI_reg_imm_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addI_reg_aimmINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6954 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 9618 "ad_arm.cpp"
  }
}

uint addI_reg_aimmINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addP_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 6966 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 9640 "ad_arm.cpp"
  }
}

uint addP_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addshlP_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 7057 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Register base = reg_to_register_object(opnd_array(2)->base(ra_,this,idx2));
    __ add(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(base, lsl, opnd_array(2)->scale()));
  
#line 9663 "ad_arm.cpp"
  }
}

uint addshlP_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addP_reg_aimmXNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 7070 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 9685 "ad_arm.cpp"
  }
}

uint addP_reg_aimmXNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 7107 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ adds(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
    __ adc(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
  
#line 9708 "ad_arm.cpp"
  }
}

uint addL_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void addL_reg_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  {
    MacroAssembler _masm(&cbuf);

#line 7151 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ adds(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constantL());
    __ adc(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), 0);
  
#line 9731 "ad_arm.cpp"
  }
}

uint addL_reg_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadPLockedNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 7170 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    Register base = reg_to_register_object(opnd_array(1)->base(ra_,this,idx1));
    __ ldxr(opnd_array(0)->as_Register(ra_,this)/* dst */, base);
#else
    __ ldrex(opnd_array(0)->as_Register(ra_,this)/* dst */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
#endif
  
#line 9757 "ad_arm.cpp"
  }
}

uint loadPLockedNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storePConditionalNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// heap_top_ptr
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7188 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    Register base = reg_to_register_object(opnd_array(1)->base(ra_,this,idx1));
    __ stxr(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, base);
#else
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
#endif
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0);
  
#line 9787 "ad_arm.cpp"
  }
}

uint storePConditionalNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void storeXConditionalNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7228 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
#ifdef AARCH64
// FIXME: use load-acquire/store-release, remove membar?
    Label done;
    Register base = reg_to_register_object(opnd_array(1)->base(ra_,this,idx1));
    __ ldxr(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, base);
    __ subs(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* oldval */);
    __ b(done, ne);
    __ stxr(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, base);
    __ cbnz_w(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, loop);
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0);
    __ bind(done);
#else
    __ ldrex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ eors(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* oldval */);
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()), eq);
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 1, eq);
    __ b(loop, eq);
    __ teq(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0);
#endif
    // used by biased locking only. Requires a membar.
    __ membar(MacroAssembler::Membar_mask_bits(MacroAssembler::LoadStore | MacroAssembler::LoadLoad), noreg);
  
#line 9833 "ad_arm.cpp"
  }
}

uint storeXConditionalNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 28, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 28);
}

void compareAndSwapL_boolNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7383 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrexd(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* oldval */);
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* oldval */->successor(), eq);
    __ strexd(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()), eq);
    __ mov(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0, ne);
    __ eors(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 1, eq);
    __ b(loop, eq);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* res */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */);
  
#line 9866 "ad_arm.cpp"
  }
}

uint compareAndSwapL_boolNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 32, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 32);
}

void compareAndSwapI_boolNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7412 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* oldval */);
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()), eq);
    __ mov(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0, ne);
    __ eors(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 1, eq);
    __ b(loop, eq);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* res */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */);
  
#line 9898 "ad_arm.cpp"
  }
}

uint compareAndSwapI_boolNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 28, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 28);
}

void compareAndSwapP_boolNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7439 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* oldval */);
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()), eq);
    __ mov(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0, ne);
    __ eors(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 1, eq);
    __ b(loop, eq);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* res */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */);
  
#line 9930 "ad_arm.cpp"
  }
}

uint compareAndSwapP_boolNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 28, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 28);
}

void xaddI_aimmI_no_resNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7490 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ add(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(2)->constant());
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 9960 "ad_arm.cpp"
  }
}

uint xaddI_aimmI_no_resNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void xaddI_reg_no_resNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7539 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ add(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* add */);
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 9990 "ad_arm.cpp"
  }
}

uint xaddI_reg_no_resNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void xaddI_aimmINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7586 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(3)->as_Register(ra_,this,idx3)/* res */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ add(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* res */, opnd_array(2)->constant());
    __ strex(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 10021 "ad_arm.cpp"
  }
}

uint xaddI_aimmINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void xaddI_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7633 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(3)->as_Register(ra_,this,idx3)/* res */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ add(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* res */, opnd_array(2)->as_Register(ra_,this,idx2)/* add */);
    __ strex(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 10052 "ad_arm.cpp"
  }
}

uint xaddI_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void xaddL_reg_no_resNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7683 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrexd(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ adds(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* add */);
    __ adc(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */->successor(), opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* add */->successor());
    __ strexd(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 10083 "ad_arm.cpp"
  }
}

uint xaddL_reg_no_resNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 24, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 24);
}

void xaddL_immRot_no_resNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7736 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrexd(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ adds(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, opnd_array(2)->constantL());
    __ adc(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */->successor(), opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */->successor(), 0);
    __ strexd(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 10114 "ad_arm.cpp"
  }
}

uint xaddL_immRot_no_resNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 24, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 24);
}

void xaddL_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7785 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrexd(opnd_array(3)->as_Register(ra_,this,idx3)/* res */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ adds(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* res */, opnd_array(2)->as_Register(ra_,this,idx2)/* add */);
    __ adc(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */->successor(), opnd_array(3)->as_Register(ra_,this,idx3)/* res */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* add */->successor());
    __ strexd(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 10146 "ad_arm.cpp"
  }
}

uint xaddL_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 24, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 24);
}

void xaddL_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  {
    MacroAssembler _masm(&cbuf);

#line 7836 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrexd(opnd_array(3)->as_Register(ra_,this,idx3)/* res */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ adds(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* res */, opnd_array(2)->constantL());
    __ adc(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */->successor(), opnd_array(3)->as_Register(ra_,this,idx3)/* res */->successor(), 0);
    __ strexd(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, opnd_array(4)->as_Register(ra_,this,idx4)/* tmp1 */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(5)->as_Register(ra_,this,idx5)/* tmp2 */, 0);
    __ b(loop, ne);
  
#line 10178 "ad_arm.cpp"
  }
}

uint xaddL_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 24, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 24);
}

void xchgINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// newval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7904 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(3)->as_Register(ra_,this,idx3)/* res */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0);
    __ b(loop, ne);
  
#line 10207 "ad_arm.cpp"
  }
}

uint xchgINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void xchgLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// newval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7947 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrexd(opnd_array(3)->as_Register(ra_,this,idx3)/* res */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ strexd(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0);
    __ b(loop, ne);
  
#line 10236 "ad_arm.cpp"
  }
}

uint xchgLNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void xchgPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// newval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 7990 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label loop;
    __ bind(loop);
    __ ldrex(opnd_array(3)->as_Register(ra_,this,idx3)/* res */,Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ strex(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* newval */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
    __ cmp(opnd_array(4)->as_Register(ra_,this,idx4)/* tmp */, 0);
    __ b(loop, ne);
  
#line 10265 "ad_arm.cpp"
  }
}

uint xchgPNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void subI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8010 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 10287 "ad_arm.cpp"
  }
}

uint subI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8022 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 10310 "ad_arm.cpp"
  }
}

uint subshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subshlI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8034 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->constant()));
  
#line 10333 "ad_arm.cpp"
  }
}

uint subshlI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8046 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 10356 "ad_arm.cpp"
  }
}

uint subsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subsarI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8058 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->constant()));
  
#line 10379 "ad_arm.cpp"
  }
}

uint subsarI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8070 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 10402 "ad_arm.cpp"
  }
}

uint subshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subshrI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8082 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->constant()));
  
#line 10425 "ad_arm.cpp"
  }
}

uint subshrI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void rsbshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8094 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 10448 "ad_arm.cpp"
  }
}

uint rsbshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void rsbshlI_reg_imm_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8105 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->constant()));
  
#line 10471 "ad_arm.cpp"
  }
}

uint rsbshlI_reg_imm_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void rsbsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8116 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 10494 "ad_arm.cpp"
  }
}

uint rsbsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void rsbsarI_reg_imm_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8127 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, asr, opnd_array(2)->constant()));
  
#line 10517 "ad_arm.cpp"
  }
}

uint rsbsarI_reg_imm_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void rsbshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8138 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 10540 "ad_arm.cpp"
  }
}

uint rsbshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void rsbshrI_reg_imm_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 8149 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->constant()));
  
#line 10563 "ad_arm.cpp"
  }
}

uint rsbshrI_reg_imm_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subI_reg_aimmINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8162 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 10585 "ad_arm.cpp"
  }
}

uint subI_reg_aimmINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subI_reg_immRotnegNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8173 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, -opnd_array(2)->constant());
  
#line 10607 "ad_arm.cpp"
  }
}

uint subI_reg_immRotnegNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subI_immRot_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8185 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, opnd_array(1)->constant());
  
#line 10629 "ad_arm.cpp"
  }
}

uint subI_immRot_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8212 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
    __ sbc(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
  
#line 10652 "ad_arm.cpp"
  }
}

uint subL_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void subL_reg_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  {
    MacroAssembler _masm(&cbuf);

#line 8258 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constantL());
    __ sbc(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), 0);
  
#line 10675 "ad_arm.cpp"
  }
}

uint subL_reg_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void negL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// zero
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8273 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsbs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, 0);
    __ rsc(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor(), 0);
  
#line 10698 "ad_arm.cpp"
  }
}

uint negL_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void mulI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8289 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mul_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 10720 "ad_arm.cpp"
  }
}

uint mulI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void mulL_lo1_hi2Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8310 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mul(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
  
#line 10742 "ad_arm.cpp"
  }
}

uint mulL_lo1_hi2Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void mulL_hi1_lo2Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8321 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mla(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */->successor(), opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */, opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor());
    __ mov(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, 0);
  
#line 10766 "ad_arm.cpp"
  }
}

uint mulL_hi1_lo2Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void mulL_lo1_lo2Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8332 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ umlal(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */);
  
#line 10789 "ad_arm.cpp"
  }
}

uint mulL_lo1_lo2Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void divI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8369 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ call(StubRoutines::Arm::idiv_irem_entry(), relocInfo::runtime_call_type);
  
#line 10811 "ad_arm.cpp"
  }
}

void divL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8394 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    address target = CAST_FROM_FN_PTR(address, SharedRuntime::ldiv);
    __ call(target, relocInfo::runtime_call_type);
  
#line 10829 "ad_arm.cpp"
  }
}

void modI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8437 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ call(StubRoutines::Arm::idiv_irem_entry(), relocInfo::runtime_call_type);
  
#line 10846 "ad_arm.cpp"
  }
}

void modL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8465 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    address target = CAST_FROM_FN_PTR(address, SharedRuntime::lrem);
    __ call(target, relocInfo::runtime_call_type);
  
#line 10864 "ad_arm.cpp"
  }
}

void shlI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8487 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 10881 "ad_arm.cpp"
  }
}

uint shlI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shlI_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8506 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ logical_shift_left(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 10903 "ad_arm.cpp"
  }
}

uint shlI_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shlL_reg_reg_merge_hiNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8518 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor(), AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */->successor(), lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 10926 "ad_arm.cpp"
  }
}

uint shlL_reg_reg_merge_hiNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shlL_reg_reg_merge_loNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8528 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 10949 "ad_arm.cpp"
  }
}

uint shlL_reg_reg_merge_loNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shlL_reg_reg_overlapNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8542 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // $src1$$Register and $dst$$Register->successor() can't be the same
    __ subs(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, 32);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(0)->as_Register(ra_,this)/* dst */->successor()), pl);
    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0, mi);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(0)->as_Register(ra_,this)/* dst */->successor()), mi);
  
#line 10975 "ad_arm.cpp"
  }
}

uint shlL_reg_reg_overlapNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void shlL_reg_imm6Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8592 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    if (opnd_array(2)->constant()== 32) {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */);
    } else {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->constant()-32));
    }
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 0);
  
#line 11002 "ad_arm.cpp"
  }
}

uint shlL_reg_imm6Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void shlL_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8610 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // The order of the following 3 instructions matters: src1.lo and
    // dst.hi can't overlap but src.hi and dst.hi can.
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsl, opnd_array(2)->constant()));
    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, 32-opnd_array(2)->constant()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsl, opnd_array(2)->constant()));
  
#line 11028 "ad_arm.cpp"
  }
}

uint shlL_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void sarI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8632 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 11050 "ad_arm.cpp"
  }
}

uint sarI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void sarI_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8651 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, asr, opnd_array(2)->constant()));
  
#line 11072 "ad_arm.cpp"
  }
}

uint sarI_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void sarL_reg_reg_merge_loNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8664 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 11095 "ad_arm.cpp"
  }
}

uint sarL_reg_reg_merge_loNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void sarL_reg_reg_merge_hiNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8674 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor(), AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */->successor(), asr, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 11118 "ad_arm.cpp"
  }
}

uint sarL_reg_reg_merge_hiNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void sarL_reg_reg_overlapNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8688 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // $src1$$Register->successor() and $dst$$Register can't be the same
    __ subs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, 32);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), asr, opnd_array(0)->as_Register(ra_,this)/* dst */), pl);
    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, 0, mi);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsl, opnd_array(0)->as_Register(ra_,this)/* dst */), mi);
  
#line 11144 "ad_arm.cpp"
  }
}

uint sarL_reg_reg_overlapNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void sarL_reg_imm6Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8738 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    if (opnd_array(2)->constant()== 32) {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor());
    } else{
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), asr, opnd_array(2)->constant()-32));
    }
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), asr, 0));
  
#line 11171 "ad_arm.cpp"
  }
}

uint sarL_reg_imm6Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void sarL_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8756 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // The order of the following 3 instructions matters: src1.lo and
    // dst.hi can't overlap but src.hi and dst.hi can.
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->constant()));
    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsl, 32-opnd_array(2)->constant()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), asr, opnd_array(2)->constant()));
  
#line 11197 "ad_arm.cpp"
  }
}

uint sarL_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void shrI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8778 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */));
  
#line 11219 "ad_arm.cpp"
  }
}

uint shrI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shrI_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8797 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->constant()));
  
#line 11241 "ad_arm.cpp"
  }
}

uint shrI_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shrL_reg_reg_merge_loNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8810 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* dst */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 11264 "ad_arm.cpp"
  }
}

uint shrL_reg_reg_merge_loNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shrL_reg_reg_merge_hiNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 8820 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(1)->as_Register(ra_,this,idx1)/* dst */->successor(), AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src1 */->successor(), lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src2 */));
  
#line 11287 "ad_arm.cpp"
  }
}

uint shrL_reg_reg_merge_hiNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shrL_reg_reg_overlapNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8834 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // $src1$$Register->successor() and $dst$$Register can't be the same
    __ subs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, 32);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsr, opnd_array(0)->as_Register(ra_,this)/* dst */), pl);
    __ rsb(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, 0, mi);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsl, opnd_array(0)->as_Register(ra_,this)/* dst */), mi);
  
#line 11313 "ad_arm.cpp"
  }
}

uint shrL_reg_reg_overlapNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void shrL_reg_imm6Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8884 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    if (opnd_array(2)->constant()== 32) {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor());
    } else {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsr, opnd_array(2)->constant()-32));
    }
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 11340 "ad_arm.cpp"
  }
}

uint shrL_reg_imm6Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void shrL_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8903 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // The order of the following 3 instructions matters: src1.lo and
    // dst.hi can't overlap but src.hi and dst.hi can.
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, lsr, opnd_array(2)->constant()));
    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsl, 32-opnd_array(2)->constant()));
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), lsr, opnd_array(2)->constant()));
  
#line 11366 "ad_arm.cpp"
  }
}

uint shrL_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void shrP_reg_imm5Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8919 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ logical_shift_right(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 11388 "ad_arm.cpp"
  }
}

uint shrP_reg_imm5Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addF_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8933 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11410 "ad_arm.cpp"
  }
}

uint addF_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addD_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8946 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11432 "ad_arm.cpp"
  }
}

uint addD_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subF_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8959 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11454 "ad_arm.cpp"
  }
}

uint subF_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subD_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8971 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11476 "ad_arm.cpp"
  }
}

uint subD_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void mulF_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8983 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mul_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11498 "ad_arm.cpp"
  }
}

uint mulF_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void mulD_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 8996 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mul_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11520 "ad_arm.cpp"
  }
}

uint mulD_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void divF_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9009 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ div_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11542 "ad_arm.cpp"
  }
}

uint divF_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void divD_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9022 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ div_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 11564 "ad_arm.cpp"
  }
}

uint divD_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void absD_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9035 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ abs_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 11585 "ad_arm.cpp"
  }
}

uint absD_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void absF_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9045 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ abs_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 11606 "ad_arm.cpp"
  }
}

void negF_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9056 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ neg_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 11622 "ad_arm.cpp"
  }
}

uint negF_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void negD_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9066 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ neg_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 11643 "ad_arm.cpp"
  }
}

void sqrtF_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9078 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sqrt_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 11659 "ad_arm.cpp"
  }
}

uint sqrtF_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void sqrtD_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9090 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sqrt_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 11680 "ad_arm.cpp"
  }
}

uint sqrtD_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9104 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 11702 "ad_arm.cpp"
  }
}

uint andI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9116 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 11725 "ad_arm.cpp"
  }
}

uint andshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshlI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9116 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 11748 "ad_arm.cpp"
  }
}

uint andshlI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshlI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9128 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->constant()));
  
#line 11771 "ad_arm.cpp"
  }
}

uint andshlI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshlI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9128 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsl, opnd_array(2)->constant()));
  
#line 11794 "ad_arm.cpp"
  }
}

uint andshlI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9140 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 11817 "ad_arm.cpp"
  }
}

uint andsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andsarI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9140 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 11840 "ad_arm.cpp"
  }
}

uint andsarI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andsarI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9152 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->constant()));
  
#line 11863 "ad_arm.cpp"
  }
}

uint andsarI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andsarI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9152 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, asr, opnd_array(2)->constant()));
  
#line 11886 "ad_arm.cpp"
  }
}

uint andsarI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9164 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 11909 "ad_arm.cpp"
  }
}

uint andshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshrI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9164 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 11932 "ad_arm.cpp"
  }
}

uint andshrI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshrI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9176 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->constant()));
  
#line 11955 "ad_arm.cpp"
  }
}

uint andshrI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andshrI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9176 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsr, opnd_array(2)->constant()));
  
#line 11978 "ad_arm.cpp"
  }
}

uint andshrI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andI_reg_limmNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9188 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ and_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 12000 "ad_arm.cpp"
  }
}

uint andI_reg_limmNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andI_reg_limmnNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9200 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ bic(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, ~opnd_array(2)->constant());
  
#line 12022 "ad_arm.cpp"
  }
}

uint andI_reg_limmnNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void andL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9221 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
  
#line 12045 "ad_arm.cpp"
  }
}

uint andL_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void andL_reg_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  {
    MacroAssembler _masm(&cbuf);

#line 9249 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constantL());
    __ andr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), 0);
  
#line 12068 "ad_arm.cpp"
  }
}

uint andL_reg_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void orI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9264 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 12090 "ad_arm.cpp"
  }
}

uint orI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9276 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 12113 "ad_arm.cpp"
  }
}

uint orshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshlI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9276 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 12136 "ad_arm.cpp"
  }
}

uint orshlI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshlI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9288 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->constant()));
  
#line 12159 "ad_arm.cpp"
  }
}

uint orshlI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshlI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9288 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsl, opnd_array(2)->constant()));
  
#line 12182 "ad_arm.cpp"
  }
}

uint orshlI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9300 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 12205 "ad_arm.cpp"
  }
}

uint orsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orsarI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9300 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 12228 "ad_arm.cpp"
  }
}

uint orsarI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orsarI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9312 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->constant()));
  
#line 12251 "ad_arm.cpp"
  }
}

uint orsarI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orsarI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9312 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, asr, opnd_array(2)->constant()));
  
#line 12274 "ad_arm.cpp"
  }
}

uint orsarI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9324 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 12297 "ad_arm.cpp"
  }
}

uint orshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshrI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9324 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 12320 "ad_arm.cpp"
  }
}

uint orshrI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshrI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9336 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->constant()));
  
#line 12343 "ad_arm.cpp"
  }
}

uint orshrI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orshrI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9336 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsr, opnd_array(2)->constant()));
  
#line 12366 "ad_arm.cpp"
  }
}

uint orshrI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orI_reg_limmNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9348 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 12388 "ad_arm.cpp"
  }
}

uint orI_reg_limmNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void orL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9370 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
  
#line 12411 "ad_arm.cpp"
  }
}

uint orL_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void orL_reg_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  {
    MacroAssembler _masm(&cbuf);

#line 9398 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constantL());
    __ orr(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), 0);
  
#line 12434 "ad_arm.cpp"
  }
}

uint orL_reg_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void xorI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9428 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 12456 "ad_arm.cpp"
  }
}

uint xorI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9440 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 12479 "ad_arm.cpp"
  }
}

uint xorshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshlI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9440 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 12502 "ad_arm.cpp"
  }
}

uint xorshlI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshlI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9452 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsl, opnd_array(3)->constant()));
  
#line 12525 "ad_arm.cpp"
  }
}

uint xorshlI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshlI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9452 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsl, opnd_array(2)->constant()));
  
#line 12548 "ad_arm.cpp"
  }
}

uint xorshlI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9464 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 12571 "ad_arm.cpp"
  }
}

uint xorsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorsarI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9464 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 12594 "ad_arm.cpp"
  }
}

uint xorsarI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorsarI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9476 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, asr, opnd_array(3)->constant()));
  
#line 12617 "ad_arm.cpp"
  }
}

uint xorsarI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorsarI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9476 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, asr, opnd_array(2)->constant()));
  
#line 12640 "ad_arm.cpp"
  }
}

uint xorsarI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9488 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* src3 */));
  
#line 12663 "ad_arm.cpp"
  }
}

uint xorshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshrI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9488 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* src3 */));
  
#line 12686 "ad_arm.cpp"
  }
}

uint xorshrI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshrI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  {
    MacroAssembler _masm(&cbuf);

#line 9500 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */, lsr, opnd_array(3)->constant()));
  
#line 12709 "ad_arm.cpp"
  }
}

uint xorshrI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorshrI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  {
    MacroAssembler _masm(&cbuf);

#line 9500 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* src1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src2 */, lsr, opnd_array(2)->constant()));
  
#line 12732 "ad_arm.cpp"
  }
}

uint xorshrI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorI_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9512 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constant());
  
#line 12754 "ad_arm.cpp"
  }
}

uint xorI_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void xorL_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 9532 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
  
#line 12777 "ad_arm.cpp"
  }
}

uint xorL_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void xorL_reg_immRotNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  {
    MacroAssembler _masm(&cbuf);

#line 9560 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->constantL());
    __ eor(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), 0);
  
#line 12800 "ad_arm.cpp"
  }
}

uint xorL_reg_immRotNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void convI2BNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9587 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 0);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 1, ne);
  
#line 12823 "ad_arm.cpp"
  }
}

uint convI2BNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void convP2BNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9614 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 0);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 1, ne);
  
#line 12846 "ad_arm.cpp"
  }
}

uint convP2BNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void cmpLTMask_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  {
    MacroAssembler _masm(&cbuf);

#line 9640 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->as_Register(ra_,this,idx2)/* q */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 0);
    __ mvn(opnd_array(0)->as_Register(ra_,this)/* dst */, 0, lt);
  
#line 12870 "ad_arm.cpp"
  }
}

void cmpLTMask_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  {
    MacroAssembler _masm(&cbuf);

#line 9666 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->constant());
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 0);
    __ mvn(opnd_array(0)->as_Register(ra_,this)/* dst */, 0, lt);
  
#line 12889 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask3Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  {
    MacroAssembler _masm(&cbuf);

#line 9698 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->as_Register(ra_,this,idx2)/* q */);
    __ add(opnd_array(4)->as_Register(ra_,this,idx4)/* z */, opnd_array(3)->as_Register(ra_,this,idx3)/* y */, opnd_array(4)->as_Register(ra_,this,idx4)/* z */, lt);
  
#line 12909 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask3_1Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// y
  {
    MacroAssembler _masm(&cbuf);

#line 9698 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(3)->as_Register(ra_,this,idx3)/* q */);
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* z */, opnd_array(4)->as_Register(ra_,this,idx4)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* z */, lt);
  
#line 12929 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask3_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// y
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  {
    MacroAssembler _masm(&cbuf);

#line 9698 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(3)->as_Register(ra_,this,idx3)/* q */);
    __ add(opnd_array(4)->as_Register(ra_,this,idx4)/* z */, opnd_array(1)->as_Register(ra_,this,idx1)/* y */, opnd_array(4)->as_Register(ra_,this,idx4)/* z */, lt);
  
#line 12949 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask3_2Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// y
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// p
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// q
  {
    MacroAssembler _masm(&cbuf);

#line 9698 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(3)->as_Register(ra_,this,idx3)/* p */, opnd_array(4)->as_Register(ra_,this,idx4)/* q */);
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* z */, opnd_array(2)->as_Register(ra_,this,idx2)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* z */, lt);
  
#line 12969 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask4Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  {
    MacroAssembler _masm(&cbuf);

#line 9730 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->constant());
    __ add(opnd_array(4)->as_Register(ra_,this,idx4)/* z */, opnd_array(3)->as_Register(ra_,this,idx3)/* y */, opnd_array(4)->as_Register(ra_,this,idx4)/* z */, lt);
  
#line 12989 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask4_1Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// y
  {
    MacroAssembler _masm(&cbuf);

#line 9730 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(3)->constant());
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* z */, opnd_array(4)->as_Register(ra_,this,idx4)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* z */, lt);
  
#line 13009 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask4_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// y
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  {
    MacroAssembler _masm(&cbuf);

#line 9730 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(3)->constant());
    __ add(opnd_array(4)->as_Register(ra_,this,idx4)/* z */, opnd_array(1)->as_Register(ra_,this,idx1)/* y */, opnd_array(4)->as_Register(ra_,this,idx4)/* z */, lt);
  
#line 13029 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask4_2Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// y
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// p
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// q
  {
    MacroAssembler _masm(&cbuf);

#line 9730 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(3)->as_Register(ra_,this,idx3)/* p */, opnd_array(4)->constant());
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* z */, opnd_array(2)->as_Register(ra_,this,idx2)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* z */, lt);
  
#line 13049 "ad_arm.cpp"
  }
}

void cadd_cmpLTMaskNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  {
    MacroAssembler _masm(&cbuf);

#line 9761 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->as_Register(ra_,this,idx2)/* q */);
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(3)->as_Register(ra_,this,idx3)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* p */, lt);
  
#line 13068 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask_1Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  {
    MacroAssembler _masm(&cbuf);

#line 9761 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->as_Register(ra_,this,idx2)/* q */);
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(3)->as_Register(ra_,this,idx3)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* p */, lt);
  
#line 13087 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// y
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  {
    MacroAssembler _masm(&cbuf);

#line 9761 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(3)->as_Register(ra_,this,idx3)/* q */);
    __ add(opnd_array(2)->as_Register(ra_,this,idx2)/* p */, opnd_array(1)->as_Register(ra_,this,idx1)/* y */, opnd_array(2)->as_Register(ra_,this,idx2)/* p */, lt);
  
#line 13106 "ad_arm.cpp"
  }
}

void cadd_cmpLTMask_2Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  {
    MacroAssembler _masm(&cbuf);

#line 9761 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(2)->as_Register(ra_,this,idx2)/* q */);
    __ add(opnd_array(1)->as_Register(ra_,this,idx1)/* p */, opnd_array(3)->as_Register(ra_,this,idx3)/* y */, opnd_array(1)->as_Register(ra_,this,idx1)/* p */, lt);
  
#line 13125 "ad_arm.cpp"
  }
}

void convD2F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9776 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ convert_d2f(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 13141 "ad_arm.cpp"
  }
}

uint convD2F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void convD2I_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 9812 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ftosizd(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
    __ fmrs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */);
  
#line 13164 "ad_arm.cpp"
  }
}

void convD2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9830 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifndef __ABI_HARD__
    __ fmrrd(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
#else
    if (opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */!= D0) {
      __ mov_double(D0, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
    }
#endif
    address target = CAST_FROM_FN_PTR(address, SharedRuntime::d2l);
    __ call(target, relocInfo::runtime_call_type);
  
#line 13188 "ad_arm.cpp"
  }
}

void convF2D_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9849 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ convert_f2d(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 13204 "ad_arm.cpp"
  }
}

uint convF2D_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void convF2I_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 9885 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ftosizs(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
    __ fmrs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */);
  
#line 13227 "ad_arm.cpp"
  }
}

uint convF2I_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void convF2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9898 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifndef __ABI_HARD__
    __ fmrs(as_Register(R_R0_enc), opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
#else
    if(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */!= S0) {
      __ mov_float(S0, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
    }
#endif
    address target = CAST_FROM_FN_PTR(address, SharedRuntime::f2l);
    __ call(target, relocInfo::runtime_call_type);
  
#line 13256 "ad_arm.cpp"
  }
}

void convI2D_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9931 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

      __ fmsr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
      __ fsitod(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(0)->as_FloatRegister(ra_,this)/* dst */);
  
#line 13273 "ad_arm.cpp"
  }
}

uint convI2D_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void convI2F_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9952 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

      __ fmsr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
      __ fsitos(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(0)->as_FloatRegister(ra_,this)/* dst */);
  
#line 13295 "ad_arm.cpp"
  }
}

uint convI2F_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void convI2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 9972 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src */, asr, 31));
  
#line 13317 "ad_arm.cpp"
  }
}

uint convI2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void convI2L_reg_zexNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 9993 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 13340 "ad_arm.cpp"
  }
}

uint convI2L_reg_zexNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void zerox_longNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  {
    MacroAssembler _masm(&cbuf);

#line 10014 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), 0);
  
#line 13363 "ad_arm.cpp"
  }
}

uint zerox_longNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void MoveF2I_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10029 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmrs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 13384 "ad_arm.cpp"
  }
}

uint MoveF2I_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void MoveI2F_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10041 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmsr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 13405 "ad_arm.cpp"
  }
}

uint MoveI2F_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void MoveD2L_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10060 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmrrd(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(0)->as_Register(ra_,this)/* dst */->successor(), opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
  
#line 13426 "ad_arm.cpp"
  }
}

uint MoveD2L_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void MoveL2D_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10080 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
  
#line 13447 "ad_arm.cpp"
  }
}

uint MoveL2D_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadConI_x43300000Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10118 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov_slow(opnd_array(0)->as_Register(ra_,this)/* dst */, 0x43300000);
  
#line 13468 "ad_arm.cpp"
  }
}

uint loadConI_x43300000Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadConI_x41f00000Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10129 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov_slow(opnd_array(0)->as_Register(ra_,this)/* dst */, 0x41f00000);
  
#line 13489 "ad_arm.cpp"
  }
}

uint loadConI_x41f00000Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void loadConI_x0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10139 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 0);
  
#line 13510 "ad_arm.cpp"
  }
}

uint loadConI_x0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void regDHi_regDLo_to_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10151 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor(), opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */->successor());
    __ fcpys(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 13533 "ad_arm.cpp"
  }
}

uint regDHi_regDLo_to_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void convI2D_regDHi_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10165 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fsitod(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */->successor());
  
#line 13554 "ad_arm.cpp"
  }
}

uint convI2D_regDHi_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void addD_regD_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10177 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 13576 "ad_arm.cpp"
  }
}

uint addD_regD_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void subD_regD_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10188 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ sub_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 13598 "ad_arm.cpp"
  }
}

uint subD_regD_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void mulD_regD_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10199 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mul_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
  
#line 13620 "ad_arm.cpp"
  }
}

uint mulD_regD_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void regL_to_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10211 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
  
#line 13641 "ad_arm.cpp"
  }
}

uint regL_to_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void regI_regI_to_regDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10223 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
  
#line 13663 "ad_arm.cpp"
  }
}

uint regI_regI_to_regDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void convL2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 10273 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 13684 "ad_arm.cpp"
  }
}

uint convL2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void shrL_reg_imm6_L2INode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// cnt
  {
    MacroAssembler _masm(&cbuf);

#line 10286 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    if (opnd_array(2)->constant()== 32) {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
    } else {
      __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor(), asr, opnd_array(2)->constant()- 32));
    }
  
#line 13710 "ad_arm.cpp"
  }
}

uint shrL_reg_imm6_L2INode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compI_iRegNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10307 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */);
  
#line 13732 "ad_arm.cpp"
  }
}

uint compI_iRegNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compU_iRegNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10333 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */);
  
#line 13754 "ad_arm.cpp"
  }
}

uint compU_iRegNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compI_iReg_immnegNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10345 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmn_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, -opnd_array(2)->constant());
  
#line 13776 "ad_arm.cpp"
  }
}

uint compI_iReg_immnegNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compI_iReg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10357 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constant());
  
#line 13798 "ad_arm.cpp"
  }
}

uint compI_iReg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testI_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10368 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */);
  
#line 13821 "ad_arm.cpp"
  }
}

uint testI_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshlI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10380 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, lsl, opnd_array(3)->as_Register(ra_,this,idx3)/* op3 */));
  
#line 13845 "ad_arm.cpp"
  }
}

uint testshlI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshlI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10380 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(3)->as_Register(ra_,this,idx3)/* op1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, lsl, opnd_array(2)->as_Register(ra_,this,idx2)/* op3 */));
  
#line 13869 "ad_arm.cpp"
  }
}

uint testshlI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshlI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10392 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, lsl, opnd_array(3)->constant()));
  
#line 13893 "ad_arm.cpp"
  }
}

uint testshlI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshlI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10392 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(3)->as_Register(ra_,this,idx3)/* op1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, lsl, opnd_array(2)->constant()));
  
#line 13917 "ad_arm.cpp"
  }
}

uint testshlI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testsarI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10404 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, asr, opnd_array(3)->as_Register(ra_,this,idx3)/* op3 */));
  
#line 13941 "ad_arm.cpp"
  }
}

uint testsarI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testsarI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10404 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(3)->as_Register(ra_,this,idx3)/* op1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, asr, opnd_array(2)->as_Register(ra_,this,idx2)/* op3 */));
  
#line 13965 "ad_arm.cpp"
  }
}

uint testsarI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testsarI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10416 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, asr, opnd_array(3)->constant()));
  
#line 13989 "ad_arm.cpp"
  }
}

uint testsarI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testsarI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10416 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(3)->as_Register(ra_,this,idx3)/* op1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, asr, opnd_array(2)->constant()));
  
#line 14013 "ad_arm.cpp"
  }
}

uint testsarI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshrI_reg_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10428 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, lsr, opnd_array(3)->as_Register(ra_,this,idx3)/* op3 */));
  
#line 14037 "ad_arm.cpp"
  }
}

uint testshrI_reg_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshrI_reg_reg_reg_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10428 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst(opnd_array(3)->as_Register(ra_,this,idx3)/* op1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, lsr, opnd_array(2)->as_Register(ra_,this,idx2)/* op3 */));
  
#line 14061 "ad_arm.cpp"
  }
}

uint testshrI_reg_reg_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshrI_reg_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10440 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, lsr, opnd_array(3)->constant()));
  
#line 14085 "ad_arm.cpp"
  }
}

uint testshrI_reg_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testshrI_reg_reg_imm_0Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10440 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(3)->as_Register(ra_,this,idx3)/* op1 */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, lsr, opnd_array(2)->constant()));
  
#line 14109 "ad_arm.cpp"
  }
}

uint testshrI_reg_reg_imm_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void testI_reg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 10451 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ tst_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constant());
  
#line 14132 "ad_arm.cpp"
  }
}

uint testI_reg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compL_reg_reg_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 10478 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */);
    __ sbcs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */->successor());
  
#line 14156 "ad_arm.cpp"
  }
}

uint compL_reg_reg_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void compL_reg_reg_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10507 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ teq(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */->successor());
    __ teq(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, eq);
  
#line 14179 "ad_arm.cpp"
  }
}

uint compL_reg_reg_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void compL_reg_reg_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 10521 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */, opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */);
    __ sbcs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */->successor());
  
#line 14203 "ad_arm.cpp"
  }
}

uint compL_reg_reg_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void compL_reg_con_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 10537 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ subs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constantL());
    __ sbcs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */->successor(), 0);
  
#line 14227 "ad_arm.cpp"
  }
}

uint compL_reg_con_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void compL_reg_con_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  {
    MacroAssembler _masm(&cbuf);

#line 10554 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ teq(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */->successor(), 0);
    __ teq(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constantL(), eq);
  
#line 14250 "ad_arm.cpp"
  }
}

uint compL_reg_con_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void compL_reg_con_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 10571 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rsbs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constantL());
    __ rscs(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */->successor(), 0);
  
#line 14274 "ad_arm.cpp"
  }
}

uint compL_reg_con_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void compU_iReg_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10602 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp_32(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constant());
  
#line 14296 "ad_arm.cpp"
  }
}

uint compU_iReg_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compP_iRegPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10614 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op2 */);
  
#line 14318 "ad_arm.cpp"
  }
}

uint compP_iRegPNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void compP_iRegP_immNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  {
    MacroAssembler _masm(&cbuf);

#line 10625 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    assert(opnd_array(2)->constant()== 0 || _opnds[2]->constant_reloc() == relocInfo::none, "reloc in cmp?");
    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* op1 */, opnd_array(2)->constant());
  
#line 14341 "ad_arm.cpp"
  }
}

uint compP_iRegP_immNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovI_reg_ltNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10640 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op1 */, lt);
  
#line 14364 "ad_arm.cpp"
  }
}

uint cmovI_reg_ltNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovI_reg_gtNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10662 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(1)->as_Register(ra_,this,idx1)/* op2 */, opnd_array(2)->as_Register(ra_,this,idx2)/* op1 */, gt);
  
#line 14387 "ad_arm.cpp"
  }
}

void cmpF_ccNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10696 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmps(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ fmstat();
  
#line 14405 "ad_arm.cpp"
  }
}

uint cmpF_ccNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmpF0_ccNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10718 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmpzs(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */);
    __ fmstat();
  
#line 14428 "ad_arm.cpp"
  }
}

uint cmpF0_ccNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmpD_ccNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10740 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmpd(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ fmstat();
  
#line 14451 "ad_arm.cpp"
  }
}

uint cmpD_ccNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmpD0_ccNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10762 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmpzd(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */);
    __ fmstat();
  
#line 14474 "ad_arm.cpp"
  }
}

uint cmpD0_ccNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmpF_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10860 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmps(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ floating_cmp(opnd_array(0)->as_Register(ra_,this)/* dst */);
  
#line 14497 "ad_arm.cpp"
  }
}

uint cmpF_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void cmpF0_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10879 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmpzs(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */);
    __ floating_cmp(opnd_array(0)->as_Register(ra_,this)/* dst */);
  
#line 14520 "ad_arm.cpp"
  }
}

uint cmpF0_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void cmpD_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10898 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmpd(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ floating_cmp(opnd_array(0)->as_Register(ra_,this)/* dst */);
  
#line 14543 "ad_arm.cpp"
  }
}

uint cmpD_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void cmpD0_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 10917 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcmpzd(opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */);
    __ floating_cmp(opnd_array(0)->as_Register(ra_,this)/* dst */);
  
#line 14566 "ad_arm.cpp"
  }
}

uint cmpD0_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void jumpXtndNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  ra_->C->constant_table().fill_jump_table(cbuf, (MachConstantNode*) this, _index2label);
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// tmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10937 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Register table_reg;
    Register label_reg = opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */;
    if (constant_offset() == 0) {
      table_reg = as_Register(ra_->get_encode(in(mach_constant_base_node_input())));
      __ ldr(label_reg, Address(table_reg, opnd_array(1)->as_Register(ra_,this,idx1)/* switch_val */));
    } else {
      table_reg = opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */;
      int offset = constant_offset();
      if (is_memoryP(offset)) {
        __ add(table_reg, as_Register(ra_->get_encode(in(mach_constant_base_node_input()))), opnd_array(1)->as_Register(ra_,this,idx1)/* switch_val */);
        __ ldr(label_reg, Address(table_reg, offset));
      } else {
        __ mov_slow(table_reg, constant_offset());
        __ add(table_reg, as_Register(ra_->get_encode(in(mach_constant_base_node_input()))), table_reg);
        __ ldr(label_reg, Address(table_reg, opnd_array(1)->as_Register(ra_,this,idx1)/* switch_val */));
      }
    }
    __ jump(label_reg); // ldr + b better than ldr to PC for branch predictor?
    //    __ ldr(PC, Address($table$$Register, $switch_val$$Register));
  
#line 14607 "ad_arm.cpp"
  }
}

void jumpXtndNode::eval_constant(Compile* C) {
  _constant = C->constant_table().add_jump_table(this);
  // User did not define an encode section.
}
uint jumpXtndNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void branchNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10969 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(1)->label()));
  
#line 14632 "ad_arm.cpp"
  }
}

uint branchNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchConNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10983 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14655 "ad_arm.cpp"
  }
}

uint branchConNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchCon_EQNELTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 10998 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14678 "ad_arm.cpp"
  }
}

uint branchCon_EQNELTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchConUNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11068 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14701 "ad_arm.cpp"
  }
}

uint branchConUNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchConPNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// pcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11081 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14724 "ad_arm.cpp"
  }
}

uint branchConPNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchConL_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// xcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11096 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14747 "ad_arm.cpp"
  }
}

uint branchConL_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchConL_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// xcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11110 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14770 "ad_arm.cpp"
  }
}

uint branchConL_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchConL_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// xcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11124 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14793 "ad_arm.cpp"
  }
}

uint branchConL_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void branchLoopEndNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11138 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ b(*(opnd_array(3)->label()), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14816 "ad_arm.cpp"
  }
}

uint branchLoopEndNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmpL3_reg_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 11211 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Label done;
    __ cmp(opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */->successor(), opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */->successor());
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 1, gt);
    __ mvn(opnd_array(0)->as_Register(ra_,this)/* dst */, 0, lt);
    __ b(done, ne);
    __ subs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src1 */, opnd_array(2)->as_Register(ra_,this,idx2)/* src2 */);
    __ mov(opnd_array(0)->as_Register(ra_,this)/* dst */, 1, hi);
    __ mvn(opnd_array(0)->as_Register(ra_,this)/* dst */, 0, lo);
    __ bind(done);
  
#line 14846 "ad_arm.cpp"
  }
}

uint cmpL3_reg_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 32, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 32);
}

void cmovLL_reg_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11236 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14871 "ad_arm.cpp"
  }
}

uint cmovLL_reg_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLL_reg_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11251 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14896 "ad_arm.cpp"
  }
}

uint cmovLL_reg_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLL_reg_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11266 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), opnd_array(4)->as_Register(ra_,this,idx4)/* src */->successor(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14921 "ad_arm.cpp"
  }
}

uint cmovLL_reg_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLL_imm_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11280 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, 0, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14946 "ad_arm.cpp"
  }
}

uint cmovLL_imm_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLL_imm_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11294 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, 0, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14971 "ad_arm.cpp"
  }
}

uint cmovLL_imm_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovLL_imm_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11308 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, 0, (AsmCondition)(opnd_array(1)->ccode()));
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */->successor(), 0, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 14996 "ad_arm.cpp"
  }
}

uint cmovLL_imm_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void cmovIL_reg_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11324 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15020 "ad_arm.cpp"
  }
}

uint cmovIL_reg_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIL_reg_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11337 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15044 "ad_arm.cpp"
  }
}

uint cmovIL_reg_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIL_reg_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11350 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15068 "ad_arm.cpp"
  }
}

uint cmovIL_reg_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovIL_imm_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11364 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15092 "ad_arm.cpp"
  }
}

void cmovIL_imm_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11376 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15111 "ad_arm.cpp"
  }
}

void cmovIL_imm_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11388 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15130 "ad_arm.cpp"
  }
}

void cmovPL_reg_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11401 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15149 "ad_arm.cpp"
  }
}

uint cmovPL_reg_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPL_reg_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11414 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15173 "ad_arm.cpp"
  }
}

uint cmovPL_reg_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPL_reg_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11427 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->as_Register(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15197 "ad_arm.cpp"
  }
}

uint cmovPL_reg_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovPL_imm_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11439 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15221 "ad_arm.cpp"
  }
}

void cmovPL_imm_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11451 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15240 "ad_arm.cpp"
  }
}

void cmovPL_imm_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11463 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ movw(opnd_array(3)->as_Register(ra_,this,idx3)/* dst */, opnd_array(4)->constant(), (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15259 "ad_arm.cpp"
  }
}

void cmovFL_reg_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11475 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15278 "ad_arm.cpp"
  }
}

uint cmovFL_reg_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovFL_reg_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11487 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15302 "ad_arm.cpp"
  }
}

uint cmovFL_reg_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovFL_reg_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11499 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpys(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15326 "ad_arm.cpp"
  }
}

uint cmovFL_reg_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDL_reg_LTGENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11512 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15350 "ad_arm.cpp"
  }
}

uint cmovDL_reg_LTGENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDL_reg_EQNENode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11525 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15374 "ad_arm.cpp"
  }
}

uint cmovDL_reg_EQNENode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void cmovDL_reg_LEGTNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11538 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fcpyd(opnd_array(3)->as_FloatRegister(ra_,this,idx3)/* dst */, opnd_array(4)->as_FloatRegister(ra_,this,idx4)/* src */, (AsmCondition)(opnd_array(1)->ccode()));
  
#line 15398 "ad_arm.cpp"
  }
}

uint cmovDL_reg_LEGTNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void safePoint_pollNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 11570 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ relocate(relocInfo::poll_type);
    __ ldr(as_Register(R_R12_enc), Address(opnd_array(1)->as_Register(ra_,this,idx1)/* poll */));
  
#line 15420 "ad_arm.cpp"
  }
}

uint safePoint_pollNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void CallStaticJavaDirectNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {

#line 1398 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // CALL to fixup routine.  Fixup routine uses ScopeDesc info to determine
    // who we intended to call.

    if ( !_method) {
      emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), runtime_call_Relocation::spec());
    } else {
      int method_index = resolved_method_index(cbuf);
      RelocationHolder rspec = _optimized_virtual ? opt_virtual_call_Relocation::spec(method_index)
                                                  : static_call_Relocation::spec(method_index);
      emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), rspec);

      // Emit stubs for static call.
      address stub = CompiledStaticCall::emit_to_interp_stub(cbuf);
      if (stub == NULL) {
        ciEnv::current()->record_failure("CodeCache is full");
        return;
      }
    }
  
#line 15457 "ad_arm.cpp"
  }
  {

#line 1389 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // nothing
  
#line 15465 "ad_arm.cpp"
  }
}

void CallStaticJavaHandleNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {

#line 1433 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // preserve mark
    address mark = cbuf.insts()->mark();
    debug_only(int off0 = cbuf.insts_size());
    MacroAssembler _masm(&cbuf);
    // FP is preserved across all calls, even compiled calls.
    // Use it to preserve SP in places where the callee might change the SP.
    __ mov(Rmh_SP_save, SP);
    debug_only(int off1 = cbuf.insts_size());
    assert(off1 - off0 == 4, "correct size prediction");
    // restore mark
    cbuf.insts()->set_mark(mark);
  
#line 15490 "ad_arm.cpp"
  }
  {

#line 1398 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // CALL to fixup routine.  Fixup routine uses ScopeDesc info to determine
    // who we intended to call.

    if ( !_method) {
      emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), runtime_call_Relocation::spec());
    } else {
      int method_index = resolved_method_index(cbuf);
      RelocationHolder rspec = _optimized_virtual ? opt_virtual_call_Relocation::spec(method_index)
                                                  : static_call_Relocation::spec(method_index);
      emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), rspec);

      // Emit stubs for static call.
      address stub = CompiledStaticCall::emit_to_interp_stub(cbuf);
      if (stub == NULL) {
        ciEnv::current()->record_failure("CodeCache is full");
        return;
      }
    }
  
#line 15515 "ad_arm.cpp"
  }
  {

#line 1447 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    MacroAssembler _masm(&cbuf);
    __ mov(SP, Rmh_SP_save);
  
#line 15524 "ad_arm.cpp"
  }
  {

#line 1389 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // nothing
  
#line 15532 "ad_arm.cpp"
  }
}

void CallDynamicJavaDirectNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {

#line 1452 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    MacroAssembler _masm(&cbuf);
    Register R8_ic_reg = reg_to_register_object(Matcher::inline_cache_reg_encode());
    assert(R8_ic_reg == Ricklass, "should be");
    __ set_inst_mark();
#ifdef AARCH64
// TODO: see C1 LIR_Assembler::ic_call()
    InlinedAddress oop_literal((address)Universe::non_oop_word());
    int offset = __ offset();
    int fixed_size = mov_oop_size * 4;
    if (VM_Version::prefer_moves_over_load_literal()) {
      uintptr_t val = (uintptr_t)Universe::non_oop_word();
      __ movz(R8_ic_reg, (val >>  0) & 0xffff,  0);
      __ movk(R8_ic_reg, (val >> 16) & 0xffff, 16);
      __ movk(R8_ic_reg, (val >> 32) & 0xffff, 32);
      __ movk(R8_ic_reg, (val >> 48) & 0xffff, 48);
    } else {
      __ ldr_literal(R8_ic_reg, oop_literal);
    }
    assert(__ offset() - offset == fixed_size, "bad mov_oop size");
#else
    __ movw(R8_ic_reg, ((unsigned int)Universe::non_oop_word()) & 0xffff);
    __ movt(R8_ic_reg, ((unsigned int)Universe::non_oop_word()) >> 16);
#endif
    address  virtual_call_oop_addr = __ inst_mark();
    // CALL to fixup routine.  Fixup routine uses ScopeDesc info to determine
    // who we intended to call.
    int method_index = resolved_method_index(cbuf);
    __ relocate(virtual_call_Relocation::spec(virtual_call_oop_addr, method_index));
    emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), RelocationHolder::none);
#ifdef AARCH64
    if (!VM_Version::prefer_moves_over_load_literal()) {
      Label skip_literal;
      __ b(skip_literal);
      int off2 = __ offset();
      __ bind_literal(oop_literal);
      if (__ offset() - off2 == wordSize) {
        // no padding, so insert nop for worst-case sizing
        __ nop();
      }
      __ bind(skip_literal);
    }
#endif
  
#line 15588 "ad_arm.cpp"
  }
  {

#line 1389 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // nothing
  
#line 15596 "ad_arm.cpp"
  }
}

void CallRuntimeDirectNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {

#line 1393 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // CALL directly to the runtime
    emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), runtime_call_Relocation::spec());
  
#line 15612 "ad_arm.cpp"
  }
  {

#line 1389 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // nothing
  
#line 15620 "ad_arm.cpp"
  }
}

void CallLeafDirectNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {

#line 1393 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // CALL directly to the runtime
    emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), runtime_call_Relocation::spec());
  
#line 15636 "ad_arm.cpp"
  }
  {

#line 1389 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // nothing
  
#line 15644 "ad_arm.cpp"
  }
}

void CallLeafNoFPDirectNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  {

#line 1393 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // CALL directly to the runtime
    emit_call_reloc(cbuf, as_MachCall(), opnd_array(1), runtime_call_Relocation::spec());
  
#line 15660 "ad_arm.cpp"
  }
  {

#line 1389 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // nothing
  
#line 15668 "ad_arm.cpp"
  }
}

void TailCalljmpIndNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// method_oop
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11669 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(Rexception_pc, LR);   // this is used only to call
                                 // StubRoutines::forward_exception_entry()
                                 // which expects PC of exception in
                                 // R5. FIXME?
    __ jump(opnd_array(1)->as_Register(ra_,this,idx1)/* jump_target */);
  
#line 15689 "ad_arm.cpp"
  }
}

void RetNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11686 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ret(LR);
  
#line 15705 "ad_arm.cpp"
  }
}

void tailjmpIndNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// ex_oop
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11705 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(Rexception_pc, LR);
    __ jump(opnd_array(1)->as_Register(ra_,this,idx1)/* jump_target */);
  
#line 15723 "ad_arm.cpp"
  }
}

void CreateExceptionNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  // User did not define which encode class to use.
}

uint CreateExceptionNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 0);
}

void RethrowExceptionNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11738 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    Register scratch = R1_tmp;
    assert_different_registers(scratch, c_rarg0, LR);
    __ jump(OptoRuntime::rethrow_stub(), relocInfo::runtime_call_type, scratch);
  
#line 15754 "ad_arm.cpp"
  }
}

void ShouldNotReachHereNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// 
  {
    MacroAssembler _masm(&cbuf);

#line 11756 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ breakpoint();
  
#line 15770 "ad_arm.cpp"
  }
}

uint ShouldNotReachHereNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void partialSubtypeCheckNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// sub
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// super
  {
    MacroAssembler _masm(&cbuf);

#line 11772 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ call(StubRoutines::Arm::partial_subtype_check(), relocInfo::runtime_call_type);
  
#line 15792 "ad_arm.cpp"
  }
}

void cmpFastLockNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// object
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// box
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// scratch2
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// scratch
  {
    MacroAssembler _masm(&cbuf);

#line 11809 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fast_lock(opnd_array(1)->as_Register(ra_,this,idx1)/* object */, opnd_array(2)->as_Register(ra_,this,idx2)/* box */, opnd_array(4)->as_Register(ra_,this,idx4)/* scratch */, opnd_array(3)->as_Register(ra_,this,idx3)/* scratch2 */);
  
#line 15811 "ad_arm.cpp"
  }
}

void cmpFastUnlockNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// object
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// box
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// scratch2
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// scratch
  {
    MacroAssembler _masm(&cbuf);

#line 11836 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fast_unlock(opnd_array(1)->as_Register(ra_,this,idx1)/* object */, opnd_array(2)->as_Register(ra_,this,idx2)/* box */, opnd_array(4)->as_Register(ra_,this,idx4)/* scratch */, opnd_array(3)->as_Register(ra_,this,idx3)/* scratch2 */);
  
#line 15830 "ad_arm.cpp"
  }
}

void clear_arrayNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// cnt
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// base
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// temp
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  {
    MacroAssembler _masm(&cbuf);

#line 11894 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(4)->as_Register(ra_,this,idx4)/* zero */, 0);
    __ mov(opnd_array(3)->as_Register(ra_,this,idx3)/* temp */, opnd_array(1)->as_Register(ra_,this,idx1)/* cnt */);
    Label(loop);
    __ bind(loop);
    __ subs(opnd_array(3)->as_Register(ra_,this,idx3)/* temp */, opnd_array(3)->as_Register(ra_,this,idx3)/* temp */, 4);
    __ str(opnd_array(4)->as_Register(ra_,this,idx4)/* zero */, Address(opnd_array(2)->as_Register(ra_,this,idx2)/* base */, opnd_array(3)->as_Register(ra_,this,idx3)/* temp */), ge);
    __ b(loop, gt);
  
#line 15855 "ad_arm.cpp"
  }
}

void countLeadingZerosINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 11954 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ clz_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 15871 "ad_arm.cpp"
  }
}

uint countLeadingZerosINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void countLeadingZerosLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 11979 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ clz(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
    __ teq(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, 32);
    __ clz(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, eq);
    __ add(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, eq);
  
#line 15897 "ad_arm.cpp"
  }
}

uint countLeadingZerosLNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void countTrailingZerosINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 11995 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rbit_32(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ clz_32(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 15920 "ad_arm.cpp"
  }
}

uint countTrailingZerosINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void countTrailingZerosLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 12026 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rbit(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ clz(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */);
    __ teq(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, 32);
    __ rbit(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
    __ clz(opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, eq);
    __ add(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(3)->as_Register(ra_,this,idx3)/* tmp */, eq);
  
#line 15948 "ad_arm.cpp"
  }
}

uint countTrailingZerosLNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 24, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 24);
}

void popCountINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 12079 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmsr(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ vcnt(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */);
    __ vpaddl(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, 8, 0);
    __ vpaddl(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, 16, 0);
    __ fmrs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */);
  
#line 15974 "ad_arm.cpp"
  }
}

uint popCountINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 20, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 20);
}

void popCountLNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 12129 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
    __ vcnt(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */);
    __ vpaddl(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, 8, 0);
    __ vpaddl(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, 16, 0);
    __ vpaddl(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */, 32, 0);
    __ fmrs(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* tmp */);
  
#line 16001 "ad_arm.cpp"
  }
}

uint popCountLNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 32, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 32);
}

void bytes_reverse_intNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12150 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

#ifdef AARCH64
    __ rev_w(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    // high 32 bits zeroed, not sign extended
#else
    __ rev(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
#endif
  
#line 16027 "ad_arm.cpp"
  }
}

uint bytes_reverse_intNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void bytes_reverse_longNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  {
    MacroAssembler _masm(&cbuf);

#line 12175 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rev(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
    __ rev(opnd_array(2)->as_Register(ra_,this,idx2)/* dst */->successor(), opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 16050 "ad_arm.cpp"
  }
}

uint bytes_reverse_longNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void bytes_reverse_unsigned_shortNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12195 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ rev16(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 16071 "ad_arm.cpp"
  }
}

uint bytes_reverse_unsigned_shortNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void bytes_reverse_shortNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12215 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ revsh(opnd_array(0)->as_Register(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 16092 "ad_arm.cpp"
  }
}

uint bytes_reverse_shortNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadV8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 12232 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ ldr_double(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 16113 "ad_arm.cpp"
  }
}

uint loadV8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void loadV16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  {
    MacroAssembler _masm(&cbuf);

#line 12245 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vld1(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()), MacroAssembler::VELEM_SIZE_16, 128);
  
#line 16134 "ad_arm.cpp"
  }
}

uint loadV16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeV8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12258 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ str_double(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()));
  
#line 16156 "ad_arm.cpp"
  }
}

uint storeV8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void storeV16Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12271 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vst1(opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src */, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_reloc()), MacroAssembler::VELEM_SIZE_16, 128);
  
#line 16178 "ad_arm.cpp"
  }
}

uint storeV16Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl8B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 12291 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src */, lsl, 24));
    __ orr(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, lsr, 8));
    __ orr(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, lsr, 16));
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16203 "ad_arm.cpp"
  }
}

uint Repl8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 16, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 16);
}

void Repl8B_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12308 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */,
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 16226 "ad_arm.cpp"
  }
}

uint Repl8B_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl16B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12323 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */,
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 16249 "ad_arm.cpp"
  }
}

uint Repl16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl8B_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {

#line 1497 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // FIXME: load from constant table?
    // Load a constant replicated "count" times with width "width"
    int count = ((4));
    int width = ((1));
    assert(count*width == 4, "sanity");
    int val = opnd_array(1)->constant();
    if (width < 4) {
      int bit_width = width * 8;
      val &= (((int)1) << bit_width) - 1; // mask off sign bits
      for (int i = 0; i < count - 1; i++) {
        val |= (val << bit_width);
      }
    }
    MacroAssembler _masm(&cbuf);

    if (val == -1) {
      __ mvn(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else if (val == 0) {
      __ mov(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else {
      __ movw(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, val & 0xffff);
      __ movt(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, (unsigned int)val >> 16);
    }
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16293 "ad_arm.cpp"
  }
}

uint Repl8B_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void Repl8B_immU8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12355 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vmovI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->constant(),
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 16316 "ad_arm.cpp"
  }
}

uint Repl8B_immU8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl16B_immU8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12370 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vmovI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->constant(),
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 16339 "ad_arm.cpp"
  }
}

uint Repl16B_immU8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl4S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 12391 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mov(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, AsmOperand(opnd_array(1)->as_Register(ra_,this,idx1)/* src */, lsl, 16));
    __ orr(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, AsmOperand(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, lsr, 16));
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16363 "ad_arm.cpp"
  }
}

uint Repl4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void Repl4S_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12407 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */,
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 16386 "ad_arm.cpp"
  }
}

uint Repl4S_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl8S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12422 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */,
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 16409 "ad_arm.cpp"
  }
}

uint Repl8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl4S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {

#line 1497 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // FIXME: load from constant table?
    // Load a constant replicated "count" times with width "width"
    int count = ((2));
    int width = ((2));
    assert(count*width == 4, "sanity");
    int val = opnd_array(1)->constant();
    if (width < 4) {
      int bit_width = width * 8;
      val &= (((int)1) << bit_width) - 1; // mask off sign bits
      for (int i = 0; i < count - 1; i++) {
        val |= (val << bit_width);
      }
    }
    MacroAssembler _masm(&cbuf);

    if (val == -1) {
      __ mvn(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else if (val == 0) {
      __ mov(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else {
      __ movw(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, val & 0xffff);
      __ movt(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, (unsigned int)val >> 16);
    }
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16453 "ad_arm.cpp"
  }
}

uint Repl4S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void Repl4S_immU8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12454 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vmovI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->constant(),
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 16476 "ad_arm.cpp"
  }
}

uint Repl4S_immU8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl8S_immU8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12469 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vmovI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->constant(),
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 16499 "ad_arm.cpp"
  }
}

uint Repl8S_immU8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12485 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 16520 "ad_arm.cpp"
  }
}

uint Repl2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl4I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12501 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor()->successor(),
             opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 16543 "ad_arm.cpp"
  }
}

uint Repl4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void Repl2I_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12517 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */,
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 16566 "ad_arm.cpp"
  }
}

uint Repl2I_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl4I_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12532 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */,
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 16589 "ad_arm.cpp"
  }
}

uint Repl4I_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl2I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {

#line 1497 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // FIXME: load from constant table?
    // Load a constant replicated "count" times with width "width"
    int count = ((1));
    int width = ((4));
    assert(count*width == 4, "sanity");
    int val = opnd_array(1)->constant();
    if (width < 4) {
      int bit_width = width * 8;
      val &= (((int)1) << bit_width) - 1; // mask off sign bits
      for (int i = 0; i < count - 1; i++) {
        val |= (val << bit_width);
      }
    }
    MacroAssembler _masm(&cbuf);

    if (val == -1) {
      __ mvn(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else if (val == 0) {
      __ mov(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else {
      __ movw(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, val & 0xffff);
      __ movt(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, (unsigned int)val >> 16);
    }
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16633 "ad_arm.cpp"
  }
}

uint Repl2I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void Repl2I_immU8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12564 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vmovI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->constant(),
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 16656 "ad_arm.cpp"
  }
}

uint Repl2I_immU8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl4I_immU8Node::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12579 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vmovI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->constant(),
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 16679 "ad_arm.cpp"
  }
}

uint Repl4I_immU8Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12613 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor()->successor(),
             opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */->successor());
  
#line 16702 "ad_arm.cpp"
  }
}

uint Repl2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 8, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 8);
}

void Repl2F_regINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12629 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */, opnd_array(1)->as_Register(ra_,this,idx1)/* src */);
  
#line 16723 "ad_arm.cpp"
  }
}

uint Repl2F_regINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint Repl2F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void Repl2F_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12658 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vdupF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, quad);
  
#line 16750 "ad_arm.cpp"
  }
}

uint Repl2F_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl4F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {
    MacroAssembler _masm(&cbuf);

#line 12677 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ fmrs(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */);
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor()->successor(),
             opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16775 "ad_arm.cpp"
  }
}

uint Repl4F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*3, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*3);
}

void Repl4F_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12695 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vdupF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, quad);
  
#line 16797 "ad_arm.cpp"
  }
}

uint Repl4F_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void Repl2F_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  {

#line 1524 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // Replicate float con 2 times and pack into vector (8 bytes) in regD.
    float fval = opnd_array(1)->constantF();
    int val = *((int*)&fval);
    MacroAssembler _masm(&cbuf);

    if (val == -1) {
      __ mvn(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else if (val == 0) {
      __ mov(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, 0);
    } else {
      __ movw(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, val & 0xffff);
      __ movt(opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, (unsigned int)val >> 16);
    }
    __ fmdrr(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */, opnd_array(2)->as_Register(ra_,this,idx2)/* tmp */);
  
#line 16831 "ad_arm.cpp"
  }
}

uint Repl2F_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 12);
}

void Repl2D_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 12739 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */;
    __ fcpyd(dsta, src);
    FloatRegister dstb = dsta->successor()->successor();
    __ fcpyd(dstb, src);
  
#line 16856 "ad_arm.cpp"
  }
}

uint Repl2D_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vadd8B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12760 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 16880 "ad_arm.cpp"
  }
}

uint vadd8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd16B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12773 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 16904 "ad_arm.cpp"
  }
}

uint vadd16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd4S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12787 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 16928 "ad_arm.cpp"
  }
}

uint vadd4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd8S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12800 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 16952 "ad_arm.cpp"
  }
}

uint vadd8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12814 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 16976 "ad_arm.cpp"
  }
}

uint vadd2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd4I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12827 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 17000 "ad_arm.cpp"
  }
}

uint vadd4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12841 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vaddI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_64, quad);
  
#line 17024 "ad_arm.cpp"
  }
}

uint vadd2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd2F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12855 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vaddF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VFA_SIZE_F32, quad);
  
#line 17048 "ad_arm.cpp"
  }
}

uint vadd2F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd2F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12872 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ add_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ add_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor(),
             opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */->successor(),
             opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */->successor());
  
#line 17073 "ad_arm.cpp"
  }
}

uint vadd2F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vadd4F_reg_simdNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12888 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vaddF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VFA_SIZE_F32, quad);
  
#line 17097 "ad_arm.cpp"
  }
}

uint vadd4F_reg_simdNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vadd4F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12921 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ add_float(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor();
    FloatRegister src1b = src1a->successor();
    FloatRegister src2b = src2a->successor();
    __ add_float(dstb, src1b, src2b);
    FloatRegister dstc = dstb->successor();
    FloatRegister src1c = src1b->successor();
    FloatRegister src2c = src2b->successor();
    __ add_float(dstc, src1c, src2c);
    FloatRegister dstd = dstc->successor();
    FloatRegister src1d = src1c->successor();
    FloatRegister src2d = src2c->successor();
    __ add_float(dstd, src1d, src2d);
  
#line 17134 "ad_arm.cpp"
  }
}

uint vadd4F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*4);
}

void vadd2D_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12952 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ add_double(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor()->successor();
    FloatRegister src1b = src1a->successor()->successor();
    FloatRegister src2b = src2a->successor()->successor();
    __ add_double(dstb, src1b, src2b);
  
#line 17163 "ad_arm.cpp"
  }
}

uint vadd2D_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vsub8B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12974 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17187 "ad_arm.cpp"
  }
}

uint vsub8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub16B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 12987 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17211 "ad_arm.cpp"
  }
}

uint vsub16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub4S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13001 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 17235 "ad_arm.cpp"
  }
}

uint vsub4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub16S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13014 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_16, quad);
  
#line 17259 "ad_arm.cpp"
  }
}

uint vsub16S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13028 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 17283 "ad_arm.cpp"
  }
}

uint vsub2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub4I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13041 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_32, quad);
  
#line 17307 "ad_arm.cpp"
  }
}

uint vsub4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13055 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vsubI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_64, quad);
  
#line 17331 "ad_arm.cpp"
  }
}

uint vsub2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub2F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13069 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vsubF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VFA_SIZE_F32, quad);
  
#line 17355 "ad_arm.cpp"
  }
}

uint vsub2F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub2F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13087 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ sub_float(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor();
    FloatRegister src1b = src1a->successor();
    FloatRegister src2b = src2a->successor();
    __ sub_float(dstb, src1b, src2b);
  
#line 17384 "ad_arm.cpp"
  }
}

uint vsub2F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vsub4F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13108 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vsubF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VFA_SIZE_F32, quad);
  
#line 17408 "ad_arm.cpp"
  }
}

uint vsub4F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsub4F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13141 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ sub_float(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor();
    FloatRegister src1b = src1a->successor();
    FloatRegister src2b = src2a->successor();
    __ sub_float(dstb, src1b, src2b);
    FloatRegister dstc = dstb->successor();
    FloatRegister src1c = src1b->successor();
    FloatRegister src2c = src2b->successor();
    __ sub_float(dstc, src1c, src2c);
    FloatRegister dstd = dstc->successor();
    FloatRegister src1d = src1c->successor();
    FloatRegister src2d = src2c->successor();
    __ sub_float(dstd, src1d, src2d);
  
#line 17445 "ad_arm.cpp"
  }
}

uint vsub4F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*4);
}

void vsub2D_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13172 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ sub_double(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor()->successor();
    FloatRegister src1b = src1a->successor()->successor();
    FloatRegister src2b = src2a->successor()->successor();
    __ sub_double(dstb, src1b, src2b);
  
#line 17474 "ad_arm.cpp"
  }
}

uint vsub2D_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vmul4S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13193 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vmulI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_16, 0);
  
#line 17497 "ad_arm.cpp"
  }
}

uint vmul4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vmul8S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13205 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vmulI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_16, 1);
  
#line 17520 "ad_arm.cpp"
  }
}

uint vmul8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vmul2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13218 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vmulI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_32, 0);
  
#line 17543 "ad_arm.cpp"
  }
}

uint vmul2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vmul4I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13230 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vmulI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VELEM_SIZE_32, 1);
  
#line 17566 "ad_arm.cpp"
  }
}

uint vmul4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vmul2F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13243 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vmulF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VFA_SIZE_F32, 0);
  
#line 17589 "ad_arm.cpp"
  }
}

uint vmul2F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vmul2F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13259 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ mul_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ mul_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor(),
             opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */->successor(),
             opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */->successor());
  
#line 17614 "ad_arm.cpp"
  }
}

uint vmul2F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vmul4F_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13275 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ vmulF(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             MacroAssembler::VFA_SIZE_F32, 1);
  
#line 17637 "ad_arm.cpp"
  }
}

uint vmul4F_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vmul4F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13294 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ mul_float(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor();
    FloatRegister src1b = src1a->successor();
    FloatRegister src2b = src2a->successor();
    __ mul_float(dstb, src1b, src2b);
    FloatRegister dstc = dstb->successor();
    FloatRegister src1c = src1b->successor();
    FloatRegister src2c = src2b->successor();
    __ mul_float(dstc, src1c, src2c);
    FloatRegister dstd = dstc->successor();
    FloatRegister src1d = src1c->successor();
    FloatRegister src2d = src2c->successor();
    __ mul_float(dstd, src1d, src2d);
  
#line 17674 "ad_arm.cpp"
  }
}

uint vmul4F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*4);
}

void vmul2D_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13342 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ mul_double(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor()->successor();
    FloatRegister src1b = src1a->successor()->successor();
    FloatRegister src2b = src2a->successor()->successor();
    __ mul_double(dstb, src1b, src2b);
  
#line 17703 "ad_arm.cpp"
  }
}

uint vmul2D_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vdiv2F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13380 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    __ div_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */);
    __ div_float(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */->successor(),
             opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */->successor(),
             opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */->successor());
  
#line 17728 "ad_arm.cpp"
  }
}

uint vdiv2F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vdiv4F_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13415 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ div_float(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor();
    FloatRegister src1b = src1a->successor();
    FloatRegister src2b = src2a->successor();
    __ div_float(dstb, src1b, src2b);
    FloatRegister dstc = dstb->successor();
    FloatRegister src1c = src1b->successor();
    FloatRegister src2c = src2b->successor();
    __ div_float(dstc, src1c, src2c);
    FloatRegister dstd = dstc->successor();
    FloatRegister src1d = src1c->successor();
    FloatRegister src2d = src2c->successor();
    __ div_float(dstd, src1d, src2d);
  
#line 17765 "ad_arm.cpp"
  }
}

uint vdiv4F_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*4);
}

void vdiv2D_reg_vfpNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 13463 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    FloatRegister dsta = opnd_array(0)->as_FloatRegister(ra_,this)/* dst */;
    FloatRegister src1a = opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */;
    FloatRegister src2a = opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */;
    __ div_double(dsta, src1a, src2a);
    FloatRegister dstb = dsta->successor()->successor();
    FloatRegister src1b = src1a->successor()->successor();
    FloatRegister src2b = src2a->successor()->successor();
    __ div_double(dstb, src1b, src2b);
  
#line 17794 "ad_arm.cpp"
  }
}

uint vdiv2D_reg_vfpNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vneg8B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 13486 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vnegI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17817 "ad_arm.cpp"
  }
}

uint vneg8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vneg16B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  {
    MacroAssembler _masm(&cbuf);

#line 13500 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool _float = false;
    bool quad = true;
    __ vnegI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17841 "ad_arm.cpp"
  }
}

uint vneg16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vslcntDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vslcntXNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrcntDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cnt
  {
    MacroAssembler _masm(&cbuf);

#line 13541 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* cnt */,
             MacroAssembler::VELEM_SIZE_8, quad);
    __ vnegI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(0)->as_FloatRegister(ra_,this)/* dst */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17876 "ad_arm.cpp"
  }
}

uint vsrcntDNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vsrcntXNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cnt
  {
    MacroAssembler _masm(&cbuf);

#line 13558 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vdupI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_Register(ra_,this,idx1)/* cnt */,
             MacroAssembler::VELEM_SIZE_8, quad);
    __ vnegI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(0)->as_FloatRegister(ra_,this)/* dst */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17901 "ad_arm.cpp"
  }
}

uint vsrcntXNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*2, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*2);
}

void vsh8B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13577 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17925 "ad_arm.cpp"
  }
}

uint vsh8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsh16B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13593 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 17949 "ad_arm.cpp"
  }
}

uint vsh16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsh4S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13610 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_16, quad);
  
#line 17973 "ad_arm.cpp"
  }
}

uint vsh4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsh8S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13626 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_16, quad);
  
#line 17997 "ad_arm.cpp"
  }
}

uint vsh8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsh2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13643 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_32, quad);
  
#line 18021 "ad_arm.cpp"
  }
}

uint vsh2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsh4I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13659 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_32, quad);
  
#line 18045 "ad_arm.cpp"
  }
}

uint vsh4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsh2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13676 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_64, quad);
  
#line 18069 "ad_arm.cpp"
  }
}

uint vsh2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsl8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

void vsl8B_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13715 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 8, opnd_array(2)->constant(),
             quad);
  
#line 18103 "ad_arm.cpp"
  }
}

uint vsl8B_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsl16B_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13731 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 8, opnd_array(2)->constant(),
             quad);
  
#line 18127 "ad_arm.cpp"
  }
}

uint vsl16B_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsl4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl4S_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl8S_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

void vsl4S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13770 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 16, opnd_array(2)->constant(),
             quad);
  
#line 18171 "ad_arm.cpp"
  }
}

uint vsl4S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsl8S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13786 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 16, opnd_array(2)->constant(),
             quad);
  
#line 18195 "ad_arm.cpp"
  }
}

uint vsl8S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsl2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl2I_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl4I_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

void vsl2I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13825 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 32, opnd_array(2)->constant(),
             quad);
  
#line 18239 "ad_arm.cpp"
  }
}

uint vsl2I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsl4I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13841 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 32, opnd_array(2)->constant(),
             quad);
  
#line 18263 "ad_arm.cpp"
  }
}

uint vsl4I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsl2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

uint vsl2L_reg_0Node::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4*1, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4*1);
}

void vsl2L_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13869 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshli(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 64, opnd_array(2)->constant(),
             quad);
  
#line 18297 "ad_arm.cpp"
  }
}

uint vsl2L_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl4S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13892 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshrUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 16, opnd_array(2)->constant(),
             quad);
  
#line 18321 "ad_arm.cpp"
  }
}

uint vsrl4S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl8S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13908 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 16, opnd_array(2)->constant(),
             quad);
  
#line 18345 "ad_arm.cpp"
  }
}

uint vsrl8S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl2I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13925 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshrUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 32, opnd_array(2)->constant(),
             quad);
  
#line 18369 "ad_arm.cpp"
  }
}

uint vsrl2I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl4I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13941 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 32, opnd_array(2)->constant(),
             quad);
  
#line 18393 "ad_arm.cpp"
  }
}

uint vsrl4I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl2L_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13958 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrUI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 64, opnd_array(2)->constant(),
             quad);
  
#line 18417 "ad_arm.cpp"
  }
}

uint vsrl2L_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha8B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13977 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 18441 "ad_arm.cpp"
  }
}

uint vsha8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha16B_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 13993 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_8, quad);
  
#line 18465 "ad_arm.cpp"
  }
}

uint vsha16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha4S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14010 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_16, quad);
  
#line 18489 "ad_arm.cpp"
  }
}

uint vsha4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha8S_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14026 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_16, quad);
  
#line 18513 "ad_arm.cpp"
  }
}

uint vsha8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha2I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14043 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_32, quad);
  
#line 18537 "ad_arm.cpp"
  }
}

uint vsha2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha4I_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14059 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_32, quad);
  
#line 18561 "ad_arm.cpp"
  }
}

uint vsha4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsha2L_regNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14076 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshlSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* shift */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */,
              MacroAssembler::VELEM_SIZE_64, quad);
  
#line 18585 "ad_arm.cpp"
  }
}

uint vsha2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsra8B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsrl16B_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl8B_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14114 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 8, opnd_array(2)->constant(),
             quad);
  
#line 18619 "ad_arm.cpp"
  }
}

uint vsrl8B_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsrl16B_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14130 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 8, opnd_array(2)->constant(),
             quad);
  
#line 18643 "ad_arm.cpp"
  }
}

uint vsrl16B_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsra4S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsra8S_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsra4S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14167 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 16, opnd_array(2)->constant(),
             quad);
  
#line 18677 "ad_arm.cpp"
  }
}

uint vsra4S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsra8S_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14183 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 16, opnd_array(2)->constant(),
             quad);
  
#line 18701 "ad_arm.cpp"
  }
}

uint vsra8S_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsra2I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsra4I_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsra2I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14220 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 32, opnd_array(2)->constant(),
             quad);
  
#line 18735 "ad_arm.cpp"
  }
}

uint vsra2I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsra4I_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14236 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 32, opnd_array(2)->constant(),
             quad);
  
#line 18759 "ad_arm.cpp"
  }
}

uint vsra4I_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

uint vsra2L_regNode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vsra2L_immINode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  {
    MacroAssembler _masm(&cbuf);

#line 14263 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vshrSI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src */, 64, opnd_array(2)->constant(),
             quad);
  
#line 18788 "ad_arm.cpp"
  }
}

uint vsra2L_immINode::size(PhaseRegAlloc *ra_) const {
  assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
  return (VerifyOops ? MachNode::size(ra_) : 4);
}

void vandDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 14277 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vandI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             quad);
  
#line 18812 "ad_arm.cpp"
  }
}

void vandXNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 14289 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vandI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             quad);
  
#line 18831 "ad_arm.cpp"
  }
}

void vorDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 14303 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vorI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
            quad);
  
#line 18850 "ad_arm.cpp"
  }
}

void vorXNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 14315 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vorI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
            quad);
  
#line 18869 "ad_arm.cpp"
  }
}

void vxorDNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 14329 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = false;
    __ vxorI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             quad);
  
#line 18888 "ad_arm.cpp"
  }
}

void vxorXNode::emit(CodeBuffer& cbuf, PhaseRegAlloc* ra_) const {
  cbuf.set_insts_mark();
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  {
    MacroAssembler _masm(&cbuf);

#line 14341 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    bool quad = true;
    __ vxorI(opnd_array(0)->as_FloatRegister(ra_,this)/* dst */, opnd_array(1)->as_FloatRegister(ra_,this,idx1)/* src1 */, opnd_array(2)->as_FloatRegister(ra_,this,idx2)/* src2 */,
             quad);
  
#line 18907 "ad_arm.cpp"
  }
}

const MachOper* loadBNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadB2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUBNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUB2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUB2L_limmINode::memory_operand() const { return _opnds[1]; }
const MachOper* loadSNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadS2BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadS2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUSNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2L_immI_255Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2L_limmINode::memory_operand() const { return _opnds[1]; }
const MachOper* loadINode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2UBNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2SNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2USNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_immI_255Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_immI_65535Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_limmU31Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_immU31Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadUI2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadL_2instrNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadL_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadL_volatile_fpNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadL_unalignedNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadRangeNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadPNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadKlassNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadDNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadD_unalignedNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadFNode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchAlloc_mpNode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchAlloc_spNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeBNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeCMNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeCNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeINode::memory_operand() const { return _opnds[1]; }
const MachOper* storeLNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeL_2instrNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeL_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeL_volatile_fpNode::memory_operand() const { return _opnds[1]; }
const MachOper* storePNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeDNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeFNode::memory_operand() const { return _opnds[1]; }
const TypePtr *membar_storestoreNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_storestoreNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_acquireNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_acquireNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_acquire_0Node::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_acquire_0Node::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_acquire_lockNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_acquire_lockNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_releaseNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_releaseNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_release_0Node::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_release_0Node::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_release_lockNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_release_lockNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_volatileNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_volatileNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *unnecessary_membar_volatileNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* unnecessary_membar_volatileNode::memory_operand() const { return (MachOper*)-1; }
const MachOper* addshlP_reg_reg_immNode::memory_operand() const { return _opnds[2]; }
const MachOper* loadPLockedNode::memory_operand() const { return _opnds[1]; }
const MachOper* storePConditionalNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeXConditionalNode::memory_operand() const { return _opnds[1]; }
const MachOper* compareAndSwapL_boolNode::memory_operand() const { return _opnds[1]; }
const MachOper* compareAndSwapI_boolNode::memory_operand() const { return _opnds[1]; }
const MachOper* compareAndSwapP_boolNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddI_aimmI_no_resNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddI_reg_no_resNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddI_aimmINode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddI_regNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddL_reg_no_resNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddL_immRot_no_resNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddL_regNode::memory_operand() const { return _opnds[1]; }
const MachOper* xaddL_immRotNode::memory_operand() const { return _opnds[1]; }
const MachOper* xchgINode::memory_operand() const { return _opnds[1]; }
const MachOper* xchgLNode::memory_operand() const { return _opnds[1]; }
const MachOper* xchgPNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadV8Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadV16Node::memory_operand() const { return _opnds[1]; }
const MachOper* storeV8Node::memory_operand() const { return _opnds[1]; }
const MachOper* storeV16Node::memory_operand() const { return _opnds[1]; }


const bool Matcher::has_match_rule(int opcode) {
  assert(_last_machine_leaf < opcode && opcode < _last_opcode, "opcode in range");
  return _hasMatchRule[opcode];
}

const bool Matcher::_hasMatchRule[_last_opcode] = {
    false,  // Node
    false,  // Set
    false,  // RegN
    false,  // RegI
    false,  // RegP
    false,  // RegF
    false,  // RegD
    false,  // RegL
    false,  // RegFlags
    false,  // VecS
    false,  // VecD
    false,  // VecX
    false,  // VecY
    false,  // VecZ
    false,  // _last_machine_leaf
    true ,  // AbsD
    true ,  // AbsF
    false,  // AbsI
    true ,  // AddD
    true ,  // AddF
    true ,  // AddI
    true ,  // AddL
    true ,  // AddP
    false,  // Allocate
    false,  // AllocateArray
    true ,  // AndI
    true ,  // AndL
    false,  // ArrayCopy
    false,  // AryEq
    false,  // AtanD
    true ,  // Binary
    true ,  // Bool
    false,  // BoxLock
    true ,  // ReverseBytesI
    true ,  // ReverseBytesL
    true ,  // ReverseBytesUS
    true ,  // ReverseBytesS
    false,  // CProj
    true ,  // CallDynamicJava
    false,  // CallJava
    true ,  // CallLeaf
    true ,  // CallLeafNoFP
    true ,  // CallRuntime
    true ,  // CallStaticJava
    true ,  // CastII
    true ,  // CastX2P
    true ,  // CastP2X
    true ,  // CastPP
    false,  // Catch
    false,  // CatchProj
    true ,  // CheckCastPP
    true ,  // ClearArray
    false,  // ConstraintCast
    true ,  // CMoveD
    false,  // CMoveVD
    true ,  // CMoveF
    true ,  // CMoveI
    true ,  // CMoveL
    true ,  // CMoveP
    false,  // CMoveN
    false,  // CmpN
    true ,  // CmpD
    true ,  // CmpD3
    true ,  // CmpF
    true ,  // CmpF3
    true ,  // CmpI
    true ,  // CmpL
    true ,  // CmpL3
    true ,  // CmpLTMask
    true ,  // CmpP
    true ,  // CmpU
    false,  // CompareAndSwapB
    false,  // CompareAndSwapS
    true ,  // CompareAndSwapI
    true ,  // CompareAndSwapL
    true ,  // CompareAndSwapP
    false,  // CompareAndSwapN
    false,  // WeakCompareAndSwapB
    false,  // WeakCompareAndSwapS
    false,  // WeakCompareAndSwapI
    false,  // WeakCompareAndSwapL
    false,  // WeakCompareAndSwapP
    false,  // WeakCompareAndSwapN
    false,  // CompareAndExchangeB
    false,  // CompareAndExchangeS
    false,  // CompareAndExchangeI
    false,  // CompareAndExchangeL
    false,  // CompareAndExchangeP
    false,  // CompareAndExchangeN
    false,  // GetAndAddB
    false,  // GetAndAddS
    true ,  // GetAndAddI
    true ,  // GetAndAddL
    false,  // GetAndSetB
    false,  // GetAndSetS
    true ,  // GetAndSetI
    true ,  // GetAndSetL
    true ,  // GetAndSetP
    false,  // GetAndSetN
    false,  // Con
    true ,  // ConN
    true ,  // ConNKlass
    true ,  // ConD
    true ,  // ConF
    true ,  // ConI
    true ,  // ConL
    true ,  // ConP
    true ,  // Conv2B
    true ,  // ConvD2F
    true ,  // ConvD2I
    true ,  // ConvD2L
    true ,  // ConvF2D
    true ,  // ConvF2I
    true ,  // ConvF2L
    true ,  // ConvI2D
    true ,  // ConvI2F
    true ,  // ConvI2L
    true ,  // ConvL2D
    false,  // ConvL2F
    true ,  // ConvL2I
    false,  // CountedLoop
    true ,  // CountedLoopEnd
    true ,  // CountLeadingZerosI
    true ,  // CountLeadingZerosL
    true ,  // CountTrailingZerosI
    true ,  // CountTrailingZerosL
    true ,  // CreateEx
    false,  // DecodeN
    false,  // DecodeNKlass
    true ,  // DivD
    true ,  // DivF
    true ,  // DivI
    true ,  // DivL
    false,  // DivMod
    false,  // DivModI
    false,  // DivModL
    false,  // EncodeISOArray
    false,  // EncodeP
    false,  // EncodePKlass
    true ,  // FastLock
    true ,  // FastUnlock
    false,  // FmaD
    false,  // FmaF
    true ,  // Goto
    true ,  // Halt
    false,  // HasNegatives
    true ,  // If
    false,  // RangeCheck
    false,  // IfFalse
    false,  // IfTrue
    false,  // Initialize
    false,  // JProj
    true ,  // Jump
    false,  // JumpProj
    true ,  // LShiftI
    true ,  // LShiftL
    true ,  // LoadB
    true ,  // LoadUB
    true ,  // LoadUS
    true ,  // LoadD
    true ,  // LoadD_unaligned
    true ,  // LoadF
    true ,  // LoadI
    true ,  // LoadKlass
    false,  // LoadNKlass
    true ,  // LoadL
    true ,  // LoadL_unaligned
    true ,  // LoadPLocked
    true ,  // LoadP
    false,  // LoadN
    true ,  // LoadRange
    true ,  // LoadS
    false,  // Lock
    false,  // Loop
    false,  // LoopLimit
    false,  // Mach
    false,  // MachProj
    true ,  // MaxI
    true ,  // MemBarAcquire
    true ,  // LoadFence
    false,  // SetVectMaskI
    true ,  // MemBarAcquireLock
    false,  // MemBarCPUOrder
    true ,  // MemBarRelease
    true ,  // StoreFence
    true ,  // MemBarReleaseLock
    true ,  // MemBarVolatile
    true ,  // MemBarStoreStore
    false,  // MergeMem
    true ,  // MinI
    false,  // ModD
    false,  // ModF
    true ,  // ModI
    true ,  // ModL
    true ,  // MoveI2F
    true ,  // MoveF2I
    true ,  // MoveL2D
    true ,  // MoveD2L
    true ,  // MulD
    true ,  // MulF
    false,  // MulHiL
    true ,  // MulI
    true ,  // MulL
    false,  // Multi
    true ,  // NegD
    true ,  // NegF
    false,  // NeverBranch
    false,  // OnSpinWait
    false,  // Opaque1
    false,  // Opaque2
    false,  // Opaque3
    false,  // ProfileBoolean
    true ,  // OrI
    true ,  // OrL
    false,  // OverflowAddI
    false,  // OverflowSubI
    false,  // OverflowMulI
    false,  // OverflowAddL
    false,  // OverflowSubL
    false,  // OverflowMulL
    false,  // PCTable
    false,  // Parm
    true ,  // PartialSubtypeCheck
    false,  // Phi
    true ,  // PopCountI
    true ,  // PopCountL
    true ,  // PrefetchAllocation
    false,  // Proj
    true ,  // RShiftI
    true ,  // RShiftL
    false,  // Region
    true ,  // Rethrow
    true ,  // Return
    false,  // Root
    false,  // RoundDouble
    false,  // RoundFloat
    true ,  // SafePoint
    false,  // SafePointScalarObject
    false,  // SCMemProj
    true ,  // SqrtD
    false,  // Start
    false,  // StartOSR
    true ,  // StoreB
    true ,  // StoreC
    true ,  // StoreCM
    true ,  // StorePConditional
    true ,  // StoreIConditional
    false,  // StoreLConditional
    true ,  // StoreD
    true ,  // StoreF
    true ,  // StoreI
    true ,  // StoreL
    true ,  // StoreP
    false,  // StoreN
    false,  // StoreNKlass
    false,  // StrComp
    false,  // StrCompressedCopy
    false,  // StrEquals
    false,  // StrIndexOf
    false,  // StrIndexOfChar
    false,  // StrInflatedCopy
    true ,  // SubD
    true ,  // SubF
    true ,  // SubI
    true ,  // SubL
    true ,  // TailCall
    true ,  // TailJump
    true ,  // ThreadLocal
    false,  // Unlock
    true ,  // URShiftI
    true ,  // URShiftL
    true ,  // XorI
    true ,  // XorL
    false,  // Vector
    true ,  // AddVB
    true ,  // AddVS
    true ,  // AddVI
    false,  // AddReductionVI
    true ,  // AddVL
    false,  // AddReductionVL
    true ,  // AddVF
    false,  // AddReductionVF
    true ,  // AddVD
    false,  // AddReductionVD
    true ,  // SubVB
    true ,  // SubVS
    true ,  // SubVI
    true ,  // SubVL
    true ,  // SubVF
    true ,  // SubVD
    true ,  // MulVS
    true ,  // MulVI
    false,  // MulReductionVI
    false,  // MulVL
    false,  // MulReductionVL
    true ,  // MulVF
    false,  // MulReductionVF
    true ,  // MulVD
    false,  // MulReductionVD
    true ,  // DivVF
    true ,  // DivVD
    false,  // AbsVF
    false,  // AbsVD
    false,  // NegVF
    false,  // NegVD
    false,  // SqrtVD
    true ,  // LShiftCntV
    true ,  // RShiftCntV
    true ,  // LShiftVB
    true ,  // LShiftVS
    true ,  // LShiftVI
    true ,  // LShiftVL
    true ,  // RShiftVB
    true ,  // RShiftVS
    true ,  // RShiftVI
    true ,  // RShiftVL
    false,  // URShiftVB
    true ,  // URShiftVS
    true ,  // URShiftVI
    true ,  // URShiftVL
    true ,  // AndV
    true ,  // OrV
    true ,  // XorV
    true ,  // LoadVector
    true ,  // StoreVector
    false,  // Pack
    false,  // PackB
    false,  // PackS
    false,  // PackI
    false,  // PackL
    false,  // PackF
    false,  // PackD
    false,  // Pack2L
    false,  // Pack2D
    true ,  // ReplicateB
    true ,  // ReplicateS
    true ,  // ReplicateI
    true ,  // ReplicateL
    true ,  // ReplicateF
    true ,  // ReplicateD
    false,  // Extract
    false,  // ExtractB
    false,  // ExtractUB
    false,  // ExtractC
    false,  // ExtractS
    false,  // ExtractI
    false,  // ExtractL
    false,  // ExtractF
    false   // ExtractD
};


bool Matcher::stack_direction() const { return false; }

int Compile::sync_stack_slots() const { return 1 * VMRegImpl::slots_per_word; }

uint Matcher::stack_alignment_in_bytes() { return StackAlignmentInBytes; }

OptoReg::Name Matcher::return_addr() const { return OptoReg::stack2reg(- 1*VMRegImpl::slots_per_word +
              round_to((Compile::current()->in_preserve_stack_slots() +
                        Compile::current()->fixed_slots()),
                       stack_alignment_in_slots())); }

uint Compile::in_preserve_stack_slots() { return 2 * VMRegImpl::slots_per_word; }

uint Compile::out_preserve_stack_slots() { return SharedRuntime::out_preserve_stack_slots(); }

uint Compile::varargs_C_out_slots_killed() const { return 0; }

void Matcher::calling_convention(BasicType *sig_bt, VMRegPair *regs, uint length, bool is_outgoing) {

#line 1891 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    (void) SharedRuntime::java_calling_convention(sig_bt, regs, length, is_outgoing);

  
#line 19383 "ad_arm.cpp"

}

void Matcher::c_calling_convention(BasicType *sig_bt, VMRegPair *regs, uint length) {

#line 1899 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    // This is obviously always outgoing
    (void) SharedRuntime::c_calling_convention(sig_bt, regs, /*regs2=*/NULL, length);
  
#line 19394 "ad_arm.cpp"

}

OptoRegPair Matcher::return_value(int ideal_reg, bool is_outgoing) {

#line 1905 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    return c2::return_value(ideal_reg);
  
#line 19404 "ad_arm.cpp"

}

OptoRegPair Matcher::c_return_value(int ideal_reg, bool is_outgoing) {

#line 1905 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

    return c2::return_value(ideal_reg);
  
#line 19414 "ad_arm.cpp"

}

OptoReg::Name Matcher::inline_cache_reg() { return OptoReg::Name(R_Ricklass_num); }

int Matcher::inline_cache_reg_encode() { return _regEncode[inline_cache_reg()]; }

OptoReg::Name Matcher::interpreter_method_oop_reg() { return OptoReg::Name(R_Rmethod_num); }

int Matcher::interpreter_method_oop_reg_encode() { return _regEncode[interpreter_method_oop_reg()]; }

OptoReg::Name Matcher::interpreter_frame_pointer_reg() { return OptoReg::Bad; }

OptoReg::Name Matcher::c_frame_pointer() const { return OptoReg::Name(R_R13_num); }

// Number of callee-save + always-save registers
int  Matcher::number_of_saved_registers() {
  return 0;
};

bool Compile::needs_clone_jvms() { return false; }

// Check consistency of C++ compilation with ADLC options:
// Check adlc -DLINUX=1
#ifndef LINUX
#  error "LINUX must be defined"
#endif // LINUX
// Check adlc -D_GNU_SOURCE=1
#ifndef _GNU_SOURCE
#  error "_GNU_SOURCE must be defined"
#endif // _GNU_SOURCE
// Check adlc -DARM32=1
#ifndef ARM32
#  error "ARM32 must be defined"
#endif // ARM32
// Check adlc -U_LP64
#ifdef _LP64
#  error "_LP64 must not be defined"
#endif // _LP64
// Check adlc -DARM=1
#ifndef ARM
#  error "ARM must be defined"
#endif // ARM
