#line 1 "ad_arm_expand.cpp"
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
#include "adfiles/ad_arm.hpp"

// Register masks, one for each register class.
const RegMask _INT_REG_mask( 0xf4ff, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R0_REGI_mask( 0x1000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R1_REGI_mask( 0x2000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R2_REGI_mask( 0x4000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R3_REGI_mask( 0x8000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R12_REGI_mask( 0x80, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _PTR_REG_mask( 0xf4ff, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _SP_PTR_REG_mask( 0xf7ff, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R0_REGP_mask( 0x1000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R1_REGP_mask( 0x2000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R2_REGP_mask( 0x4000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R4_REGP_mask( 0x1, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _REXCEPTION_REGP_mask( 0x1, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _RICKLASS_REGP_mask( 0x10, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _RMETHOD_REGP_mask( 0x20, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _RTHREAD_REGP_mask( 0x100, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _IP_REGP_mask( 0x80, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _LR_REGP_mask( 0x400, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _FP_REGP_mask( 0x40, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _LONG_REG_mask( 0xf0ff, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _LONG_REG_ALIGN_mask( 0xf03f, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R0R1_REGL_mask( 0x3000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _R2R3_REGL_mask( 0xc000, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _INT_FLAGS_mask( 0x0, 0x0, 0x10000, 0x0, 0x0, 0x0 );
const RegMask _FLOAT_FLAGS_mask( 0x0, 0x0, 0x20000, 0x0, 0x0, 0x0 );
const RegMask _SFLT_REG_mask( 0xffff0000, 0x3fff, 0x0, 0x0, 0x0, 0x0 );
const RegMask _DFLT_REG_mask( 0xffff0000, 0xffff3fff, 0xffff, 0x0, 0x0, 0x0 );
const RegMask _DFLT_LOW_REG_mask( 0xffff0000, 0x3fff, 0x0, 0x0, 0x0, 0x0 );
const RegMask _S0_REGF_mask( 0x0, 0x1, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D0_REGD_mask( 0x0, 0x3, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D1_REGD_mask( 0x0, 0xc, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D2_REGD_mask( 0x0, 0x30, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D3_REGD_mask( 0x0, 0xc0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D4_REGD_mask( 0x0, 0x300, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D5_REGD_mask( 0x0, 0xc00, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D6_REGD_mask( 0x0, 0x3000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D7_REGD_mask( 0x0, 0xc000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D16_REGD_mask( 0x0, 0x30000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D17_REGD_mask( 0x0, 0xc0000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D18_REGD_mask( 0x0, 0x300000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D19_REGD_mask( 0x0, 0xc00000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D20_REGD_mask( 0x0, 0x3000000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D21_REGD_mask( 0x0, 0xc000000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D22_REGD_mask( 0x0, 0x30000000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D23_REGD_mask( 0x0, 0xc0000000, 0x0, 0x0, 0x0, 0x0 );
const RegMask _D24_REGD_mask( 0x0, 0x0, 0x3, 0x0, 0x0, 0x0 );
const RegMask _D25_REGD_mask( 0x0, 0x0, 0xc, 0x0, 0x0, 0x0 );
const RegMask _D26_REGD_mask( 0x0, 0x0, 0x30, 0x0, 0x0, 0x0 );
const RegMask _D27_REGD_mask( 0x0, 0x0, 0xc0, 0x0, 0x0, 0x0 );
const RegMask _D28_REGD_mask( 0x0, 0x0, 0x300, 0x0, 0x0, 0x0 );
const RegMask _D29_REGD_mask( 0x0, 0x0, 0xc00, 0x0, 0x0, 0x0 );
const RegMask _D30_REGD_mask( 0x0, 0x0, 0x3000, 0x0, 0x0, 0x0 );
const RegMask _D31_REGD_mask( 0x0, 0x0, 0xc000, 0x0, 0x0, 0x0 );
const RegMask _VECTORX_REG_mask( 0xffff0000, 0xffff0fff, 0xffff, 0x0, 0x0, 0x0 );
const RegMask _STACK_SLOTS_mask( 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 );
const RegMask _STACK_OR_STACK_SLOTS_mask( 0x0, 0x0, 0xff000000, 0xffffffff, 0xffffffff, 0xffffffff );
MachNode* loadS2BNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 4) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// mem
    unsigned num2 = opnd_array(2)->num_edges(); 	// twentyfour
    unsigned num3 = opnd_array(3)->num_edges(); 	// twentyfour
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    for (int i = idx4 - 1; i >= (int)idx3; i--) {
      del_req(i);
    }
    _num_opnds = 3;
  } else {
    assert(_num_opnds == 3, "There should be either 3 or 4 operands.");
  }

  return this;
}

MachNode* loadUS2BNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 4) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// mem
    unsigned num2 = opnd_array(2)->num_edges(); 	// twentyfour
    unsigned num3 = opnd_array(3)->num_edges(); 	// twentyfour
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    for (int i = idx4 - 1; i >= (int)idx3; i--) {
      del_req(i);
    }
    _num_opnds = 3;
  } else {
    assert(_num_opnds == 3, "There should be either 3 or 4 operands.");
  }

  return this;
}

MachNode* loadI2BNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 4) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// mem
    unsigned num2 = opnd_array(2)->num_edges(); 	// twentyfour
    unsigned num3 = opnd_array(3)->num_edges(); 	// twentyfour
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    for (int i = idx4 - 1; i >= (int)idx3; i--) {
      del_req(i);
    }
    _num_opnds = 3;
  } else {
    assert(_num_opnds == 3, "There should be either 3 or 4 operands.");
  }

  return this;
}

MachNode* loadI2SNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 4) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// mem
    unsigned num2 = opnd_array(2)->num_edges(); 	// sixteen
    unsigned num3 = opnd_array(3)->num_edges(); 	// sixteen
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    for (int i = idx4 - 1; i >= (int)idx3; i--) {
      del_req(i);
    }
    _num_opnds = 3;
  } else {
    assert(_num_opnds == 3, "There should be either 3 or 4 operands.");
  }

  return this;
}

MachNode* loadI2L_immU31Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGL));
  add_req(def);
  // TEMP tmp
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* loadLNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);

  return this;
}

MachNode* loadConFNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* loadConDNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);
  add_req(C->mach_constant_base_node());

  return this;
}

MachNode* addL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* addL_reg_immRotNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* storePConditionalNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* storeXConditionalNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* compareAndSwapL_boolNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* compareAndSwapI_boolNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* compareAndSwapP_boolNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddI_aimmI_no_resNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp1
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddI_reg_no_resNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp1
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddI_aimmINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp1
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddI_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp1
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddL_reg_no_resNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp1
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddL_immRot_no_resNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp1
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddL_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp1
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xaddL_immRotNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp1
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp2
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xchgINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xchgLNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGLD));
  add_req(def);
  // TEMP tmp
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* xchgPNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP res
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);
  // TEMP tmp
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* subL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL icc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* subL_reg_immRotNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL icc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* negL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL icc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* mulL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  mulL_lo1_hi2Node *n0 = new mulL_lo1_hi2Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(IREGL));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );

  mulL_hi1_lo2Node *n1 = new mulL_hi1_lo2Node();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n1->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n1->add_req(_in[i + idx0]);
    }
  }
  else n1->add_req(tmp0);
  tmp0 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  n1->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n1->add_req(_in[i + idx2]);
    }
  }
  else n1->add_req(tmp2);
  result = n1->Expand( state, proj_list, mem );

  mulL_lo1_lo2Node *n2 = new mulL_lo1_lo2Node();
  n2->add_req(_in[0]);
  n2->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n2->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n2->add_req(_in[i + idx0]);
    }
  }
  else n2->add_req(tmp0);
  tmp0 = n2;
  n2->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n2->add_req(_in[i + idx1]);
    }
  }
  else n2->add_req(tmp1);
  n2->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n2->add_req(_in[i + idx2]);
    }
  }
  else n2->add_req(tmp2);
  result = n2->Expand( state, proj_list, mem );


  return result;
}

MachNode* divI_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL src1
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (R0_REGI_mask()), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL src2
  kill = new MachProjNode( this, 2, (R2_REGI_mask()), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL lr
  kill = new MachProjNode( this, 3, (LR_REGP_mask()), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL ccr
  kill = new MachProjNode( this, 4, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* modI_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL src2
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (R2_REGI_mask()), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL temp
  kill = new MachProjNode( this, 2, (R1_REGI_mask()), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL lr
  kill = new MachProjNode( this, 3, (LR_REGP_mask()), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL ccr
  kill = new MachProjNode( this, 4, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* shlL_reg_reg_overlapNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* shlL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new flagsRegOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  shlL_reg_reg_overlapNode *n0 = new shlL_reg_reg_overlapNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(IREGL));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );

  shlL_reg_reg_merge_hiNode *n1 = new shlL_reg_reg_merge_hiNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n1->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n1->add_req(_in[i + idx0]);
    }
  }
  else n1->add_req(tmp0);
  tmp0 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  n1->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n1->add_req(_in[i + idx2]);
    }
  }
  else n1->add_req(tmp2);
  result = n1->Expand( state, proj_list, mem );

  shlL_reg_reg_merge_loNode *n2 = new shlL_reg_reg_merge_loNode();
  n2->add_req(_in[0]);
  n2->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n2->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n2->add_req(_in[i + idx0]);
    }
  }
  else n2->add_req(tmp0);
  tmp0 = n2;
  n2->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n2->add_req(_in[i + idx1]);
    }
  }
  else n2->add_req(tmp1);
  n2->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n2->add_req(_in[i + idx2]);
    }
  }
  else n2->add_req(tmp2);
  result = n2->Expand( state, proj_list, mem );


  return result;
}

MachNode* sarL_reg_reg_overlapNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* sarL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new flagsRegOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  sarL_reg_reg_overlapNode *n0 = new sarL_reg_reg_overlapNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(IREGL));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );

  sarL_reg_reg_merge_loNode *n1 = new sarL_reg_reg_merge_loNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n1->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n1->add_req(_in[i + idx0]);
    }
  }
  else n1->add_req(tmp0);
  tmp0 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  n1->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n1->add_req(_in[i + idx2]);
    }
  }
  else n1->add_req(tmp2);
  result = n1->Expand( state, proj_list, mem );

  sarL_reg_reg_merge_hiNode *n2 = new sarL_reg_reg_merge_hiNode();
  n2->add_req(_in[0]);
  n2->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n2->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n2->add_req(_in[i + idx0]);
    }
  }
  else n2->add_req(tmp0);
  tmp0 = n2;
  n2->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n2->add_req(_in[i + idx1]);
    }
  }
  else n2->add_req(tmp1);
  n2->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n2->add_req(_in[i + idx2]);
    }
  }
  else n2->add_req(tmp2);
  result = n2->Expand( state, proj_list, mem );


  return result;
}

MachNode* shrL_reg_reg_overlapNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* shrL_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new flagsRegOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  shrL_reg_reg_overlapNode *n0 = new shrL_reg_reg_overlapNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(IREGL));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );

  shrL_reg_reg_merge_loNode *n1 = new shrL_reg_reg_merge_loNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n1->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n1->add_req(_in[i + idx0]);
    }
  }
  else n1->add_req(tmp0);
  tmp0 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  n1->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n1->add_req(_in[i + idx2]);
    }
  }
  else n1->add_req(tmp2);
  result = n1->Expand( state, proj_list, mem );

  shrL_reg_reg_merge_hiNode *n2 = new shrL_reg_reg_merge_hiNode();
  n2->add_req(_in[0]);
  n2->set_opnd_array(0, state->MachOperGenerator(IREGL));
  n2->set_opnd_array(1, opnd_array(0)->clone()); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n2->add_req(_in[i + idx0]);
    }
  }
  else n2->add_req(tmp0);
  tmp0 = n2;
  n2->set_opnd_array(2, opnd_array(1)->clone()); // src1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n2->add_req(_in[i + idx1]);
    }
  }
  else n2->add_req(tmp1);
  n2->set_opnd_array(3, opnd_array(2)->clone()); // src2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n2->add_req(_in[i + idx2]);
    }
  }
  else n2->add_req(tmp2);
  result = n2->Expand( state, proj_list, mem );


  return result;
}

MachNode* convI2BNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* convP2BNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpLTMask_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpLTMask_reg_immNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask3Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask3_1Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask3_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask3_2Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask4Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask4_1Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask4_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMask4_2Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cadd_cmpLTMaskNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 6) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// p
    unsigned num2 = opnd_array(2)->num_edges(); 	// q
    unsigned num3 = opnd_array(3)->num_edges(); 	// y
    unsigned num4 = opnd_array(4)->num_edges(); 	// p
    unsigned num5 = opnd_array(5)->num_edges(); 	// q
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    unsigned idx5 = idx4 + num4;
    unsigned idx6 = idx5 + num5;
    for (int i = idx6 - 1; i >= (int)idx4; i--) {
      del_req(i);
    }
    _num_opnds = 4;
  } else {
    assert(_num_opnds == 4, "There should be either 4 or 6 operands.");
  }

  return this;
}

MachNode* cadd_cmpLTMask_1Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 6) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// p
    unsigned num2 = opnd_array(2)->num_edges(); 	// q
    unsigned num3 = opnd_array(3)->num_edges(); 	// p
    unsigned num4 = opnd_array(4)->num_edges(); 	// q
    unsigned num5 = opnd_array(5)->num_edges(); 	// y
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    unsigned idx5 = idx4 + num4;
    unsigned idx6 = idx5 + num5;
    set_opnd_array(3, opnd_array(5)->clone()); // y
    for (unsigned i = 0; i < num5; i++) {
      set_req(i + idx3, _in[i + idx5]);
    }
    num3 = num5;
    idx4 = idx3 + num3;
    for (int i = idx6 - 1; i >= (int)idx4; i--) {
      del_req(i);
    }
    _num_opnds = 4;
  } else {
    assert(_num_opnds == 4, "There should be either 4 or 6 operands.");
  }

  return this;
}

MachNode* cadd_cmpLTMask_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 6) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// y
    unsigned num2 = opnd_array(2)->num_edges(); 	// p
    unsigned num3 = opnd_array(3)->num_edges(); 	// q
    unsigned num4 = opnd_array(4)->num_edges(); 	// p
    unsigned num5 = opnd_array(5)->num_edges(); 	// q
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    unsigned idx5 = idx4 + num4;
    unsigned idx6 = idx5 + num5;
    for (int i = idx6 - 1; i >= (int)idx4; i--) {
      del_req(i);
    }
    _num_opnds = 4;
  } else {
    assert(_num_opnds == 4, "There should be either 4 or 6 operands.");
  }

  return this;
}

MachNode* cadd_cmpLTMask_2Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);
  // Remove duplicated operands and inputs which use the same name.
  if (num_opnds() == 6) {
    unsigned num0 = 0;
    unsigned num1 = opnd_array(1)->num_edges(); 	// p
    unsigned num2 = opnd_array(2)->num_edges(); 	// q
    unsigned num3 = opnd_array(3)->num_edges(); 	// y
    unsigned num4 = opnd_array(4)->num_edges(); 	// p
    unsigned num5 = opnd_array(5)->num_edges(); 	// q
    unsigned idx0 = oper_input_base();
    unsigned idx1 = idx0 + num0;
    unsigned idx2 = idx1 + num1;
    unsigned idx3 = idx2 + num2;
    unsigned idx4 = idx3 + num3;
    unsigned idx5 = idx4 + num4;
    unsigned idx6 = idx5 + num5;
    for (int i = idx6 - 1; i >= (int)idx4; i--) {
      del_req(i);
    }
    _num_opnds = 4;
  } else {
    assert(_num_opnds == 4, "There should be either 4 or 6 operands.");
  }

  return this;
}

MachNode* convD2I_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(REGF));
  add_req(def);

  return this;
}

MachNode* convF2I_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(REGF));
  add_req(def);

  return this;
}

MachNode* convL2D_reg_slow_fxtofNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new regD_lowOper();
  MachOper *op1 = new iRegIOper();
  MachOper *op2 = new iRegIOper();
  MachOper *op3 = new iRegIOper();
  MachOper *op4 = new regD_lowOper();
  MachOper *op5 = new regDOper();
  MachOper *op6 = new regDOper();
  MachOper *op7 = new regD_lowOper();
  MachOper *op8 = new regDOper();
  MachOper *op9 = new regDOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = NULL;
  MachNode *tmp3 = NULL;
  MachNode *tmp4 = NULL;
  MachNode *tmp5 = NULL;
  MachNode *tmp6 = NULL;
  MachNode *tmp7 = NULL;
  MachNode *tmp8 = NULL;
  MachNode *tmp9 = NULL;
  MachNode *tmp10 = NULL;
  MachNode *tmp11 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  regL_to_regDNode *n0 = new regL_to_regDNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp2 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );

  loadConI_x43300000Node *n1 = new loadConI_x43300000Node();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGI));
  tmp3 = n1;
  result = n1->Expand( state, proj_list, mem );

  loadConI_x41f00000Node *n2 = new loadConI_x41f00000Node();
  n2->add_req(_in[0]);
  n2->set_opnd_array(0, state->MachOperGenerator(IREGI));
  tmp4 = n2;
  result = n2->Expand( state, proj_list, mem );

  loadConI_x0Node *n3 = new loadConI_x0Node();
  n3->add_req(_in[0]);
  n3->set_opnd_array(0, state->MachOperGenerator(IREGI));
  tmp5 = n3;
  result = n3->Expand( state, proj_list, mem );

  regI_regI_to_regDNode *n4 = new regI_regI_to_regDNode();
  n4->add_req(_in[0]);
  n4->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp6 = n4;
  n4->set_opnd_array(1, op3->clone()); // ix0
  if(tmp5 != NULL)
    n4->add_req(tmp5);
  n4->set_opnd_array(2, op1->clone()); // ix43300000
  if(tmp3 != NULL)
    n4->add_req(tmp3);
  result = n4->Expand( state, proj_list, mem );

  regI_regI_to_regDNode *n5 = new regI_regI_to_regDNode();
  n5->add_req(_in[0]);
  n5->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp7 = n5;
  n5->set_opnd_array(1, op3->clone()); // ix0
  if(tmp5 != NULL)
    n5->add_req(tmp5);
  n5->set_opnd_array(2, op2->clone()); // ix41f00000
  if(tmp4 != NULL)
    n5->add_req(tmp4);
  result = n5->Expand( state, proj_list, mem );

  convI2D_regDHi_regDNode *n6 = new convI2D_regDHi_regDNode();
  n6->add_req(_in[0]);
  n6->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp8 = n6;
  n6->set_opnd_array(1, op0->clone()); // tmpsrc
  if(tmp2 != NULL)
    n6->add_req(tmp2);
  result = n6->Expand( state, proj_list, mem );

  regDHi_regDLo_to_regDNode *n7 = new regDHi_regDLo_to_regDNode();
  n7->add_req(_in[0]);
  n7->set_opnd_array(0, state->MachOperGenerator(REGD_LOW));
  tmp9 = n7;
  n7->set_opnd_array(1, op4->clone()); // dx43300000
  if(tmp6 != NULL)
    n7->add_req(tmp6);
  n7->set_opnd_array(2, op0->clone()); // tmpsrc
  if(tmp2 != NULL)
    n7->add_req(tmp2);
  result = n7->Expand( state, proj_list, mem );

  subD_regD_regDNode *n8 = new subD_regD_regDNode();
  n8->add_req(_in[0]);
  n8->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp10 = n8;
  n8->set_opnd_array(1, op7->clone()); // tmp2
  if(tmp9 != NULL)
    n8->add_req(tmp9);
  n8->set_opnd_array(2, op4->clone()); // dx43300000
  if(tmp6 != NULL)
    n8->add_req(tmp6);
  result = n8->Expand( state, proj_list, mem );

  mulD_regD_regDNode *n9 = new mulD_regD_regDNode();
  n9->add_req(_in[0]);
  n9->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp11 = n9;
  n9->set_opnd_array(1, op6->clone()); // tmp1
  if(tmp8 != NULL)
    n9->add_req(tmp8);
  n9->set_opnd_array(2, op5->clone()); // dx41f00000
  if(tmp7 != NULL)
    n9->add_req(tmp7);
  result = n9->Expand( state, proj_list, mem );

  addD_regD_regDNode *n10 = new addD_regD_regDNode();
  n10->add_req(_in[0]);
  n10->set_opnd_array(0, state->MachOperGenerator(REGD));
  tmp0 = n10;
  n10->set_opnd_array(1, op8->clone()); // tmp3
  if(tmp10 != NULL)
    n10->add_req(tmp10);
  n10->set_opnd_array(2, op9->clone()); // tmp4
  if(tmp11 != NULL)
    n10->add_req(tmp11);
  result = n10->Expand( state, proj_list, mem );


  return result;
}

MachNode* compL_reg_reg_LTGENode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGL));
  add_req(def);

  return this;
}

MachNode* compL_reg_reg_LEGTNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGL));
  add_req(def);

  return this;
}

MachNode* compL_reg_con_LTGENode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGL));
  add_req(def);

  return this;
}

MachNode* compL_reg_con_LEGTNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGL));
  add_req(def);

  return this;
}

MachNode* minI_eRegNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new flagsRegOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  compI_iRegNode *n0 = new compI_iRegNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(FLAGSREG));
  tmp3 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // op1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // op2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );

  cmovI_reg_ltNode *n1 = new cmovI_reg_ltNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGI));
  n1->set_opnd_array(1, opnd_array(2)->clone()); // op2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n1->add_req(_in[i + idx2]);
    }
  }
  else n1->add_req(tmp2);
  tmp2 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone()); // op1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  n1->set_opnd_array(3, op0->clone()); // icc
  if(tmp3 != NULL)
    n1->add_req(tmp3);
  result = n1->Expand( state, proj_list, mem );


  return result;
}

MachNode* maxI_eRegNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new flagsRegOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  compI_iRegNode *n0 = new compI_iRegNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(FLAGSREG));
  tmp3 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // op1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // op2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );

  cmovI_reg_gtNode *n1 = new cmovI_reg_gtNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator(IREGI));
  n1->set_opnd_array(1, opnd_array(2)->clone()); // op2
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n1->add_req(_in[i + idx2]);
    }
  }
  else n1->add_req(tmp2);
  tmp2 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone()); // op1
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  n1->set_opnd_array(3, op0->clone()); // icc
  if(tmp3 != NULL)
    n1->add_req(tmp3);
  result = n1->Expand( state, proj_list, mem );


  return result;
}

MachNode* cmpF_ccNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpF0_ccNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpD_ccNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpD0_ccNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpF_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpF0_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpD_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* cmpD0_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL fcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (FLOAT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* jumpXtndNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);
  add_req(C->mach_constant_base_node());

  return this;
}

MachNode* cmpL3_reg_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* safePoint_pollNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (R12_REGI_mask()), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL icc
  kill = new MachProjNode( this, 2, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* partialSubtypeCheckNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL pcc
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);
  // DEF/KILL lr
  kill = new MachProjNode( this, 2, (LR_REGP_mask()), Op_RegP );
  proj_list.push(kill);

  return this;
}

MachNode* cmpFastLockNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP scratch2
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);
  // TEMP scratch
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);

  return this;
}

MachNode* cmpFastUnlockNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP scratch2
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);
  // TEMP scratch
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);

  return this;
}

MachNode* clear_arrayNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP temp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP zero
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL cpsr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* countLeadingZerosLNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* countTrailingZerosINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* countTrailingZerosLNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // TEMP tmp
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);
  // DEF/KILL ccr
  MachProjNode *kill;
  kill = new MachProjNode( this, 1, (INT_FLAGS_mask()), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode* popCountINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(REGD_LOW));
  add_req(def);

  return this;
}

MachNode* popCountLNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(REGD_LOW));
  add_req(def);

  return this;
}

MachNode* bytes_reverse_longNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGL));
  add_req(def);

  return this;
}

MachNode* Repl8B_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* Repl8B_immINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* Repl4S_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* Repl4S_immINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGP));
  add_req(def);

  return this;
}

MachNode* Repl2I_immINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* Repl2F_reg_vfpNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachOper *op0 = new iRegIOper();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = NULL;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  MoveF2I_reg_regNode *n0 = new MoveF2I_reg_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(IREGI));
  tmp2 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );

  Repl2F_regINode *n1 = new Repl2F_regINode();
  n1->add_req(_in[0]);
  ((MachTypeNode*)n1)->_bottom_type = bottom_type();
  n1->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n1;
  n1->set_opnd_array(1, op0->clone()); // tmp
  if(tmp2 != NULL)
    n1->add_req(tmp2);
  result = n1->Expand( state, proj_list, mem );


  return result;
}

MachNode* Repl4F_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* Repl2F_immINode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new MachTempNode(state->MachOperGenerator(IREGI));
  add_req(def);

  return this;
}

MachNode* vslcntDNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  Repl8B_reg_simdNode *n0 = new Repl8B_reg_simdNode();
  n0->add_req(_in[0]);
  ((MachTypeNode*)n0)->_bottom_type = bottom_type();
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // cnt
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vslcntXNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  Repl16B_regNode *n0 = new Repl16B_regNode();
  n0->add_req(_in[0]);
  ((MachTypeNode*)n0)->_bottom_type = bottom_type();
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // cnt
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl8B_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh8B_regNode *n0 = new vsh8B_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl16B_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh16B_regNode *n0 = new vsh16B_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl4S_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh4S_regNode *n0 = new vsh4S_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl4S_reg_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh4S_regNode *n0 = new vsh4S_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl8S_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh8S_regNode *n0 = new vsh8S_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl8S_reg_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh8S_regNode *n0 = new vsh8S_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl2I_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh2I_regNode *n0 = new vsh2I_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl2I_reg_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh2I_regNode *n0 = new vsh2I_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl4I_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh4I_regNode *n0 = new vsh4I_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl4I_reg_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh4I_regNode *n0 = new vsh4I_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl2L_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh2L_regNode *n0 = new vsh2L_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsl2L_reg_0Node::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsh2L_regNode *n0 = new vsh2L_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsra8B_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha8B_regNode *n0 = new vsha8B_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsrl16B_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha16B_regNode *n0 = new vsha16B_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsra4S_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha4S_regNode *n0 = new vsha4S_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsra8S_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha8S_regNode *n0 = new vsha8S_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsra2I_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha2I_regNode *n0 = new vsha2I_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECD));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsra4I_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha4I_regNode *n0 = new vsha4I_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode* vsra2L_regNode::Expand(State* state, Node_List& proj_list, Node* mem) {
  Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  MachNode *result = NULL;

  vsha2L_regNode *n0 = new vsha2L_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator(VECX));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone()); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone()); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

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
