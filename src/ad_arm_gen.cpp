#line 1 "ad_arm_gen.cpp"
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
#include "opto/cfgnode.hpp"
#include "opto/locknode.hpp"


//------------------------- MachOper Generator ---------------
// A switch statement on the dense-packed user-defined type system
// that invokes 'new' on the corresponding class constructor.

MachOper *State::MachOperGenerator(int opcode){

  switch(opcode) {
  case UNIVERSE:
    return new UniverseOper( );
  case LABEL:
    return new labelOper( );
  case SREGI:
    return new sRegIOper( );
  case SREGP:
    return new sRegPOper( );
  case SREGF:
    return new sRegFOper( );
  case SREGD:
    return new sRegDOper( );
  case SREGL:
    return new sRegLOper( );
  case METHOD:
    return new methodOper( );
  case IMMIROT:
    return new immIRotOper(_leaf->get_int() );
  case IMMIROTN:
    return new immIRotnOper(_leaf->get_int() );
  case IMMIROTNEG:
    return new immIRotnegOper(_leaf->get_int() );
  case IMMU31ROT:
    return new immU31RotOper(_leaf->get_int() );
  case IMMPROT:
    return new immPRotOper(_leaf->bottom_type()->is_ptr() );
  case IMMLLOWROT:
    return new immLlowRotOper(_leaf->get_long() );
  case IMMLROT2:
    return new immLRot2Oper(_leaf->get_long() );
  case IMMI12:
    return new immI12Oper(_leaf->get_int() );
  case IMMI10X2:
    return new immI10x2Oper(_leaf->get_int() );
  case IMMI12X2:
    return new immI12x2Oper(_leaf->get_int() );
  case IMMI:
    return new immIOper(_leaf->get_int() );
  case IMMU8:
    return new immU8Oper(_leaf->get_int() );
  case IMMI16:
    return new immI16Oper(_leaf->get_int() );
  case IMMIHD:
    return new immIHDOper(_leaf->get_int() );
  case IMMIFP:
    return new immIFPOper(_leaf->get_int() );
  case IMMU5:
    return new immU5Oper(_leaf->get_int() );
  case IMMU6BIG:
    return new immU6BigOper(_leaf->get_int() );
  case IMMI0:
    return new immI0Oper(_leaf->get_int() );
  case IMMI_1:
    return new immI_1Oper(_leaf->get_int() );
  case IMMI_2:
    return new immI_2Oper(_leaf->get_int() );
  case IMMI_3:
    return new immI_3Oper(_leaf->get_int() );
  case IMMI_4:
    return new immI_4Oper(_leaf->get_int() );
  case IMMI_8:
    return new immI_8Oper(_leaf->get_int() );
  case IMMU31:
    return new immU31Oper(_leaf->get_int() );
  case IMMI_32_63:
    return new immI_32_63Oper(_leaf->get_int() );
  case IMMI_16:
    return new immI_16Oper(_leaf->get_int() );
  case IMMI_24:
    return new immI_24Oper(_leaf->get_int() );
  case IMMI_255:
    return new immI_255Oper(_leaf->get_int() );
  case IMMI_65535:
    return new immI_65535Oper(_leaf->get_int() );
  case AIMMI:
    return new aimmIOper(_leaf->get_int() );
  case AIMMINEG:
    return new aimmInegOper(_leaf->get_int() );
  case AIMMU31:
    return new aimmU31Oper(_leaf->get_int() );
  case LIMMI:
    return new limmIOper(_leaf->get_int() );
  case LIMMILOW8:
    return new limmIlow8Oper(_leaf->get_int() );
  case LIMMU31:
    return new limmU31Oper(_leaf->get_int() );
  case LIMMIN:
    return new limmInOper(_leaf->get_int() );
  case IMML_FF:
    return new immL_FFOper(_leaf->get_long() );
  case IMML_FFFF:
    return new immL_FFFFOper(_leaf->get_long() );
  case IMMP:
    return new immPOper(_leaf->bottom_type()->is_ptr() );
  case IMMP0:
    return new immP0Oper(_leaf->bottom_type()->is_ptr() );
  case IMMP_POLL:
    return new immP_pollOper(_leaf->bottom_type()->is_ptr() );
  case IMMN:
    return new immNOper(_leaf->bottom_type()->is_narrowoop() );
  case IMMNKLASS:
    return new immNKlassOper(_leaf->bottom_type()->is_narrowklass() );
  case IMMN0:
    return new immN0Oper(_leaf->bottom_type()->is_narrowoop() );
  case IMML:
    return new immLOper(_leaf->get_long() );
  case IMML0:
    return new immL0Oper(_leaf->get_long() );
  case IMML16:
    return new immL16Oper(_leaf->get_long() );
  case IMML_32BITS:
    return new immL_32bitsOper(_leaf->get_long() );
  case IMMD:
    return new immDOper(_leaf->getd() );
  case IMMD0:
    return new immD0Oper(_leaf->getd() );
  case IMM8D:
    return new imm8DOper(_leaf->getd() );
  case IMMF:
    return new immFOper(_leaf->getf() );
  case IMMF0:
    return new immF0Oper(_leaf->getf() );
  case IMM8F:
    return new imm8FOper(_leaf->getf() );
  case IREGI:
    return new iRegIOper( );
  case IREGP:
    return new iRegPOper( );
  case SP_PTR_REGP:
    return new sp_ptr_RegPOper( );
  case R0REGP:
    return new R0RegPOper( );
  case R1REGP:
    return new R1RegPOper( );
  case R2REGP:
    return new R2RegPOper( );
  case REXCEPTIONREGP:
    return new RExceptionRegPOper( );
  case RTHREADREGP:
    return new RthreadRegPOper( );
  case IPREGP:
    return new IPRegPOper( );
  case LRREGP:
    return new LRRegPOper( );
  case R0REGI:
    return new R0RegIOper( );
  case R1REGI:
    return new R1RegIOper( );
  case R2REGI:
    return new R2RegIOper( );
  case R3REGI:
    return new R3RegIOper( );
  case R12REGI:
    return new R12RegIOper( );
  case IREGL:
    return new iRegLOper( );
  case IREGLD:
    return new iRegLdOper( );
  case R0R1REGL:
    return new R0R1RegLOper( );
  case R2R3REGL:
    return new R2R3RegLOper( );
  case FLAGSREG:
    return new flagsRegOper( );
  case FLAGSREG_EQNELTGE:
    return new flagsReg_EQNELTGEOper( );
  case FLAGSREGU:
    return new flagsRegUOper( );
  case FLAGSREGP:
    return new flagsRegPOper( );
  case FLAGSREGL_LTGE:
    return new flagsRegL_LTGEOper( );
  case FLAGSREGL_EQNE:
    return new flagsRegL_EQNEOper( );
  case FLAGSREGL_LEGT:
    return new flagsRegL_LEGTOper( );
  case FLAGSREGF:
    return new flagsRegFOper( );
  case VECD:
    return new vecDOper( );
  case VECX:
    return new vecXOper( );
  case REGD:
    return new regDOper( );
  case REGF:
    return new regFOper( );
  case REGD_LOW:
    return new regD_lowOper( );
  case INLINE_CACHE_REGP:
    return new inline_cache_regPOper( );
  case INTERPRETER_METHOD_OOP_REGP:
    return new interpreter_method_oop_regPOper( );
  case INDIRECT:
    return new indirectOper( );
  case INDOFFSET12:
    return new indOffset12Oper(_kids[1]->_leaf->get_int() );
  case INDOFFSETFP:
    return new indOffsetFPOper(_kids[1]->_leaf->get_int() );
  case INDOFFSETHD:
    return new indOffsetHDOper(_kids[1]->_leaf->get_int() );
  case INDOFFSETFPX2:
    return new indOffsetFPx2Oper(_kids[1]->_leaf->get_int() );
  case INDOFFSET12X2:
    return new indOffset12x2Oper(_kids[1]->_leaf->get_int() );
  case INDINDEX:
    return new indIndexOper( );
  case INDINDEXSCALE:
    return new indIndexScaleOper(_kids[1]->_kids[1]->_leaf->get_int() );
  case CMPOP:
    return new cmpOpOper(_leaf->as_Bool()->_test._test );
  case CMPOP0:
    return new cmpOp0Oper(_leaf->as_Bool()->_test._test );
  case CMPOPU:
    return new cmpOpUOper(_leaf->as_Bool()->_test._test );
  case CMPOPP:
    return new cmpOpPOper(_leaf->as_Bool()->_test._test );
  case CMPOPL:
    return new cmpOpLOper(_leaf->as_Bool()->_test._test );
  case CMPOPL_COMMUTE:
    return new cmpOpL_commuteOper(_leaf->as_Bool()->_test._test );
  case SHIFTEDX:
    return new shiftedXOper(_kids[1]->_leaf->get_int() );
  case _LSHIFTI_IREGI_IMMU5:    return NULL;
  case _LOADB_MEMORYB_:    return NULL;
  case _LOADUB_MEMORYB_:    return NULL;
  case _ANDI__LOADUB_MEMORYB__LIMMILOW8:    return NULL;
  case _LOADS_MEMORYS_:    return NULL;
  case _LSHIFTI__LOADS_MEMORYS__IMMI_24:    return NULL;
  case _LOADUS_MEMORYB_:    return NULL;
  case _LSHIFTI__LOADUS_MEMORYB__IMMI_24:    return NULL;
  case _LOADUS_MEMORYS_:    return NULL;
  case _ANDI__LOADUS_MEMORYB__IMMI_255:    return NULL;
  case _ANDI__LOADUS_MEMORYS__LIMMI:    return NULL;
  case _LOADI_MEMORYS_:    return NULL;
  case _LSHIFTI__LOADI_MEMORYS__IMMI_24:    return NULL;
  case _LOADI_MEMORYB_:    return NULL;
  case _LSHIFTI__LOADI_MEMORYS__IMMI_16:    return NULL;
  case _LOADI_MEMORYI_:    return NULL;
  case _ANDI__LOADI_MEMORYB__IMMI_255:    return NULL;
  case _ANDI__LOADI_MEMORYS__IMMI_65535:    return NULL;
  case _ANDI__LOADI_MEMORYI__LIMMU31:    return NULL;
  case _ANDI__LOADI_MEMORYI__IMMU31:    return NULL;
  case _CONVI2L__LOADI_MEMORYI__:    return NULL;
  case _BINARY_CMPOPP_FLAGSREGP:    return NULL;
  case _BINARY_IREGI_IREGI:    return NULL;
  case _BINARY_IREGI_IMMIROT:    return NULL;
  case _BINARY_IREGI_IMMI16:    return NULL;
  case _BINARY_CMPOP_FLAGSREG:    return NULL;
  case _BINARY_CMPOP0_FLAGSREG_EQNELTGE:    return NULL;
  case _BINARY_CMPOPU_FLAGSREGU:    return NULL;
  case _BINARY_IREGP_IREGP:    return NULL;
  case _BINARY_IREGP_IMMP0:    return NULL;
  case _BINARY_REGF_REGF:    return NULL;
  case _BINARY_REGD_REGD:    return NULL;
  case _BINARY_IREGL_IREGL:    return NULL;
  case _BINARY_IREGL_IMMLLOWROT:    return NULL;
  case _BINARY_IREGL_IMML16:    return NULL;
  case _LSHIFTI_IREGI_IREGI:    return NULL;
  case _RSHIFTI_IREGI_IREGI:    return NULL;
  case _RSHIFTI_IREGI_IMMU5:    return NULL;
  case _URSHIFTI_IREGI_IREGI:    return NULL;
  case _URSHIFTI_IREGI_IMMU5:    return NULL;
  case _BINARY_IREGL_IREGLD:    return NULL;
  case _CASTP2X_IREGP_:    return NULL;
  case _CONVF2D_REGF_:    return NULL;
  case _SQRTD__CONVF2D_REGF__:    return NULL;
  case _CMPLTMASK_IREGI_IREGI:    return NULL;
  case _ANDI__CMPLTMASK_IREGI_IREGI_IREGI:    return NULL;
  case _ANDI_IREGI__CMPLTMASK_IREGI_IREGI:    return NULL;
  case _CMPLTMASK_IREGI_AIMMI:    return NULL;
  case _ANDI__CMPLTMASK_IREGI_AIMMI_IREGI:    return NULL;
  case _ANDI_IREGI__CMPLTMASK_IREGI_AIMMI:    return NULL;
  case _SUBI_IREGI_IREGI:    return NULL;
  case _CONVI2L_IREGI_:    return NULL;
  case _RSHIFTL_IREGL_IMMI_32_63:    return NULL;
  case _ANDI_IREGI_IREGI:    return NULL;
  case _ANDI_IREGI__LSHIFTI_IREGI_IREGI:    return NULL;
  case _ANDI__LSHIFTI_IREGI_IREGI_IREGI:    return NULL;
  case _ANDI_IREGI__LSHIFTI_IREGI_IMMU5:    return NULL;
  case _ANDI__LSHIFTI_IREGI_IMMU5_IREGI:    return NULL;
  case _ANDI_IREGI__RSHIFTI_IREGI_IREGI:    return NULL;
  case _ANDI__RSHIFTI_IREGI_IREGI_IREGI:    return NULL;
  case _ANDI_IREGI__RSHIFTI_IREGI_IMMU5:    return NULL;
  case _ANDI__RSHIFTI_IREGI_IMMU5_IREGI:    return NULL;
  case _ANDI_IREGI__URSHIFTI_IREGI_IREGI:    return NULL;
  case _ANDI__URSHIFTI_IREGI_IREGI_IREGI:    return NULL;
  case _ANDI_IREGI__URSHIFTI_IREGI_IMMU5:    return NULL;
  case _ANDI__URSHIFTI_IREGI_IMMU5_IREGI:    return NULL;
  case _ANDI_IREGI_LIMMI:    return NULL;
  case _BINARY_CMPOPL_FLAGSREGL_LTGE:    return NULL;
  case _BINARY_CMPOPL_FLAGSREGL_EQNE:    return NULL;
  case _BINARY_CMPOPL_COMMUTE_FLAGSREGL_LEGT:    return NULL;
  case _BINARY_IREGL_IMML0:    return NULL;
  
  default:
    fprintf(stderr, "Default MachOper Generator invoked for: \n");
    fprintf(stderr, "   opcode = %d\n", opcode);
    break;
  }
  return NULL;
};


//------------------------- MachNode Generator ---------------
// A switch statement on the dense-packed user-defined type system
// that invokes 'new' on the corresponding class constructor.

MachNode *State::MachNodeGenerator(int opcode){
  switch(opcode) {
  case loadB_rule: {
      loadBNode *node = new loadBNode();
      return node;
    }
  case loadB2L_rule: {
      loadB2LNode *node = new loadB2LNode();
      return node;
    }
  case loadUB_rule: {
      loadUBNode *node = new loadUBNode();
      return node;
    }
  case loadUB2L_rule: {
      loadUB2LNode *node = new loadUB2LNode();
      return node;
    }
  case loadUB2L_limmI_rule: {
      loadUB2L_limmINode *node = new loadUB2L_limmINode();
      return node;
    }
  case loadS_rule: {
      loadSNode *node = new loadSNode();
      return node;
    }
  case loadS2B_rule: {
      loadS2BNode *node = new loadS2BNode();
      return node;
    }
  case loadS2L_rule: {
      loadS2LNode *node = new loadS2LNode();
      return node;
    }
  case loadUS_rule: {
      loadUSNode *node = new loadUSNode();
      return node;
    }
  case loadUS2B_rule: {
      loadUS2BNode *node = new loadUS2BNode();
      return node;
    }
  case loadUS2L_rule: {
      loadUS2LNode *node = new loadUS2LNode();
      return node;
    }
  case loadUS2L_immI_255_rule: {
      loadUS2L_immI_255Node *node = new loadUS2L_immI_255Node();
      return node;
    }
  case loadUS2L_limmI_rule: {
      loadUS2L_limmINode *node = new loadUS2L_limmINode();
      return node;
    }
  case loadI_rule: {
      loadINode *node = new loadINode();
      return node;
    }
  case loadI2B_rule: {
      loadI2BNode *node = new loadI2BNode();
      return node;
    }
  case loadI2UB_rule: {
      loadI2UBNode *node = new loadI2UBNode();
      return node;
    }
  case loadI2S_rule: {
      loadI2SNode *node = new loadI2SNode();
      return node;
    }
  case loadI2US_rule: {
      loadI2USNode *node = new loadI2USNode();
      return node;
    }
  case loadI2L_rule: {
      loadI2LNode *node = new loadI2LNode();
      return node;
    }
  case loadI2L_immI_255_rule: {
      loadI2L_immI_255Node *node = new loadI2L_immI_255Node();
      return node;
    }
  case loadI2L_immI_65535_rule: {
      loadI2L_immI_65535Node *node = new loadI2L_immI_65535Node();
      return node;
    }
  case loadI2L_limmU31_rule: {
      loadI2L_limmU31Node *node = new loadI2L_limmU31Node();
      return node;
    }
  case loadI2L_immU31_rule: {
      loadI2L_immU31Node *node = new loadI2L_immU31Node();
      node->set_opnd_array(3, MachOperGenerator(IREGL));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case loadUI2L_rule: {
      loadUI2LNode *node = new loadUI2LNode();
      return node;
    }
  case loadL_rule: {
      loadLNode *node = new loadLNode();
      node->set_opnd_array(2, MachOperGenerator(IREGLD));
      return node;
    }
  case loadL_2instr_rule: {
      loadL_2instrNode *node = new loadL_2instrNode();
      return node;
    }
  case loadL_volatile_rule: {
      loadL_volatileNode *node = new loadL_volatileNode();
      return node;
    }
  case loadL_volatile_fp_rule: {
      loadL_volatile_fpNode *node = new loadL_volatile_fpNode();
      return node;
    }
  case loadL_unaligned_rule: {
      loadL_unalignedNode *node = new loadL_unalignedNode();
      return node;
    }
  case loadRange_rule: {
      loadRangeNode *node = new loadRangeNode();
      return node;
    }
  case loadP_rule: {
      loadPNode *node = new loadPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadKlass_rule: {
      loadKlassNode *node = new loadKlassNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadD_rule: {
      loadDNode *node = new loadDNode();
      return node;
    }
  case loadD_unaligned_rule: {
      loadD_unalignedNode *node = new loadD_unalignedNode();
      return node;
    }
  case loadF_rule: {
      loadFNode *node = new loadFNode();
      return node;
    }
  case loadConI_rule: {
      loadConINode *node = new loadConINode();
      node->_opnd_array[1] = new immIOper(_leaf->get_int() );
      return node;
    }
  case loadConIMov_rule: {
      loadConIMovNode *node = new loadConIMovNode();
      node->_opnd_array[1] = new immIRotOper(_leaf->get_int() );
      return node;
    }
  case loadConIMovn_rule: {
      loadConIMovnNode *node = new loadConIMovnNode();
      node->_opnd_array[1] = new immIRotnOper(_leaf->get_int() );
      return node;
    }
  case loadConI16_rule: {
      loadConI16Node *node = new loadConI16Node();
      node->_opnd_array[1] = new immI16Oper(_leaf->get_int() );
      return node;
    }
  case loadConP_rule: {
      loadConPNode *node = new loadConPNode();
      node->_opnd_array[1] = new immPOper(_leaf->bottom_type()->is_ptr() );
      return node;
    }
  case loadConP_poll_rule: {
      loadConP_pollNode *node = new loadConP_pollNode();
      node->_opnd_array[1] = new immP_pollOper(_leaf->bottom_type()->is_ptr() );
      return node;
    }
  case loadConL_rule: {
      loadConLNode *node = new loadConLNode();
      node->_opnd_array[1] = new immLOper(_leaf->get_long() );
      return node;
    }
  case loadConL16_rule: {
      loadConL16Node *node = new loadConL16Node();
      node->_opnd_array[1] = new immL16Oper(_leaf->get_long() );
      return node;
    }
  case loadConF_imm8_rule: {
      loadConF_imm8Node *node = new loadConF_imm8Node();
      node->_opnd_array[1] = new imm8FOper(_leaf->getf() );
      return node;
    }
  case loadConF_rule: {
      loadConFNode *node = new loadConFNode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      return node;
    }
  case loadConD_imm8_rule: {
      loadConD_imm8Node *node = new loadConD_imm8Node();
      node->_opnd_array[1] = new imm8DOper(_leaf->getd() );
      return node;
    }
  case loadConD_rule: {
      loadConDNode *node = new loadConDNode();
      node->set_opnd_array(2, MachOperGenerator(IREGP));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case prefetchAlloc_mp_rule: {
      prefetchAlloc_mpNode *node = new prefetchAlloc_mpNode();
      return node;
    }
  case prefetchAlloc_sp_rule: {
      prefetchAlloc_spNode *node = new prefetchAlloc_spNode();
      return node;
    }
  case storeB_rule: {
      storeBNode *node = new storeBNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeCM_rule: {
      storeCMNode *node = new storeCMNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeC_rule: {
      storeCNode *node = new storeCNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeI_rule: {
      storeINode *node = new storeINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL_rule: {
      storeLNode *node = new storeLNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL_2instr_rule: {
      storeL_2instrNode *node = new storeL_2instrNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL_volatile_rule: {
      storeL_volatileNode *node = new storeL_volatileNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL_volatile_fp_rule: {
      storeL_volatile_fpNode *node = new storeL_volatile_fpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeP_rule: {
      storePNode *node = new storePNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeD_rule: {
      storeDNode *node = new storeDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeF_rule: {
      storeFNode *node = new storeFNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case membar_storestore_rule: {
      membar_storestoreNode *node = new membar_storestoreNode();
      return node;
    }
  case membar_acquire_rule: {
      membar_acquireNode *node = new membar_acquireNode();
      return node;
    }
  case membar_acquire_0_rule: {
      membar_acquire_0Node *node = new membar_acquire_0Node();
      return node;
    }
  case membar_acquire_lock_rule: {
      membar_acquire_lockNode *node = new membar_acquire_lockNode();
      return node;
    }
  case membar_release_rule: {
      membar_releaseNode *node = new membar_releaseNode();
      return node;
    }
  case membar_release_0_rule: {
      membar_release_0Node *node = new membar_release_0Node();
      return node;
    }
  case membar_release_lock_rule: {
      membar_release_lockNode *node = new membar_release_lockNode();
      return node;
    }
  case membar_volatile_rule: {
      membar_volatileNode *node = new membar_volatileNode();
      return node;
    }
  case unnecessary_membar_volatile_rule: {
      unnecessary_membar_volatileNode *node = new unnecessary_membar_volatileNode();
      return node;
    }
  case castX2P_rule: {
      castX2PNode *node = new castX2PNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case castP2X_rule: {
      castP2XNode *node = new castP2XNode();
      return node;
    }
  case cmovIP_reg_rule: {
      cmovIP_regNode *node = new cmovIP_regNode();
      return node;
    }
  case cmovIP_immMov_rule: {
      cmovIP_immMovNode *node = new cmovIP_immMovNode();
      return node;
    }
  case cmovIP_imm16_rule: {
      cmovIP_imm16Node *node = new cmovIP_imm16Node();
      return node;
    }
  case cmovI_reg_rule: {
      cmovI_regNode *node = new cmovI_regNode();
      return node;
    }
  case cmovI_immMov_rule: {
      cmovI_immMovNode *node = new cmovI_immMovNode();
      return node;
    }
  case cmovII_imm16_rule: {
      cmovII_imm16Node *node = new cmovII_imm16Node();
      return node;
    }
  case cmovII_reg_EQNELTGE_rule: {
      cmovII_reg_EQNELTGENode *node = new cmovII_reg_EQNELTGENode();
      return node;
    }
  case cmovII_immMov_EQNELTGE_rule: {
      cmovII_immMov_EQNELTGENode *node = new cmovII_immMov_EQNELTGENode();
      return node;
    }
  case cmovII_imm16_EQNELTGE_rule: {
      cmovII_imm16_EQNELTGENode *node = new cmovII_imm16_EQNELTGENode();
      return node;
    }
  case cmovIIu_reg_rule: {
      cmovIIu_regNode *node = new cmovIIu_regNode();
      return node;
    }
  case cmovIIu_immMov_rule: {
      cmovIIu_immMovNode *node = new cmovIIu_immMovNode();
      return node;
    }
  case cmovIIu_imm16_rule: {
      cmovIIu_imm16Node *node = new cmovIIu_imm16Node();
      return node;
    }
  case cmovPP_reg_rule: {
      cmovPP_regNode *node = new cmovPP_regNode();
      return node;
    }
  case cmovPP_imm_rule: {
      cmovPP_immNode *node = new cmovPP_immNode();
      return node;
    }
  case cmovPI_reg_rule: {
      cmovPI_regNode *node = new cmovPI_regNode();
      return node;
    }
  case cmovPI_reg_EQNELTGE_rule: {
      cmovPI_reg_EQNELTGENode *node = new cmovPI_reg_EQNELTGENode();
      return node;
    }
  case cmovPIu_reg_rule: {
      cmovPIu_regNode *node = new cmovPIu_regNode();
      return node;
    }
  case cmovPI_imm_rule: {
      cmovPI_immNode *node = new cmovPI_immNode();
      return node;
    }
  case cmovPI_imm_EQNELTGE_rule: {
      cmovPI_imm_EQNELTGENode *node = new cmovPI_imm_EQNELTGENode();
      return node;
    }
  case cmovPIu_imm_rule: {
      cmovPIu_immNode *node = new cmovPIu_immNode();
      return node;
    }
  case cmovFP_reg_rule: {
      cmovFP_regNode *node = new cmovFP_regNode();
      return node;
    }
  case cmovFI_reg_rule: {
      cmovFI_regNode *node = new cmovFI_regNode();
      return node;
    }
  case cmovFI_reg_EQNELTGE_rule: {
      cmovFI_reg_EQNELTGENode *node = new cmovFI_reg_EQNELTGENode();
      return node;
    }
  case cmovFIu_reg_rule: {
      cmovFIu_regNode *node = new cmovFIu_regNode();
      return node;
    }
  case cmovDP_reg_rule: {
      cmovDP_regNode *node = new cmovDP_regNode();
      return node;
    }
  case cmovDI_reg_rule: {
      cmovDI_regNode *node = new cmovDI_regNode();
      return node;
    }
  case cmovDI_reg_EQNELTGE_rule: {
      cmovDI_reg_EQNELTGENode *node = new cmovDI_reg_EQNELTGENode();
      return node;
    }
  case cmovDIu_reg_rule: {
      cmovDIu_regNode *node = new cmovDIu_regNode();
      return node;
    }
  case cmovLP_reg_rule: {
      cmovLP_regNode *node = new cmovLP_regNode();
      return node;
    }
  case cmovLP_immRot_rule: {
      cmovLP_immRotNode *node = new cmovLP_immRotNode();
      return node;
    }
  case cmovLP_imm16_rule: {
      cmovLP_imm16Node *node = new cmovLP_imm16Node();
      return node;
    }
  case cmovLI_reg_rule: {
      cmovLI_regNode *node = new cmovLI_regNode();
      return node;
    }
  case cmovLI_reg_EQNELTGE_rule: {
      cmovLI_reg_EQNELTGENode *node = new cmovLI_reg_EQNELTGENode();
      return node;
    }
  case cmovLI_immRot_rule: {
      cmovLI_immRotNode *node = new cmovLI_immRotNode();
      return node;
    }
  case cmovLI_immRot_EQNELTGE_rule: {
      cmovLI_immRot_EQNELTGENode *node = new cmovLI_immRot_EQNELTGENode();
      return node;
    }
  case cmovLI_imm16_rule: {
      cmovLI_imm16Node *node = new cmovLI_imm16Node();
      return node;
    }
  case cmovLI_imm16_EQNELTGE_rule: {
      cmovLI_imm16_EQNELTGENode *node = new cmovLI_imm16_EQNELTGENode();
      return node;
    }
  case cmovLIu_reg_rule: {
      cmovLIu_regNode *node = new cmovLIu_regNode();
      return node;
    }
  case tlsLoadP_rule: {
      tlsLoadPNode *node = new tlsLoadPNode();
      return node;
    }
  case checkCastPP_rule: {
      checkCastPPNode *node = new checkCastPPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case castPP_rule: {
      castPPNode *node = new castPPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case castII_rule: {
      castIINode *node = new castIINode();
      return node;
    }
  case addI_reg_reg_rule: {
      addI_reg_regNode *node = new addI_reg_regNode();
      return node;
    }
  case addshlI_reg_reg_reg_rule: {
      addshlI_reg_reg_regNode *node = new addshlI_reg_reg_regNode();
      return node;
    }
  case addshlI_reg_reg_reg_0_rule: {
      addshlI_reg_reg_reg_0Node *node = new addshlI_reg_reg_reg_0Node();
      return node;
    }
  case addshlI_reg_imm_reg_rule: {
      addshlI_reg_imm_regNode *node = new addshlI_reg_imm_regNode();
      return node;
    }
  case addshlI_reg_imm_reg_0_rule: {
      addshlI_reg_imm_reg_0Node *node = new addshlI_reg_imm_reg_0Node();
      return node;
    }
  case addsarI_reg_reg_reg_rule: {
      addsarI_reg_reg_regNode *node = new addsarI_reg_reg_regNode();
      return node;
    }
  case addsarI_reg_reg_reg_0_rule: {
      addsarI_reg_reg_reg_0Node *node = new addsarI_reg_reg_reg_0Node();
      return node;
    }
  case addsarI_reg_imm_reg_rule: {
      addsarI_reg_imm_regNode *node = new addsarI_reg_imm_regNode();
      return node;
    }
  case addsarI_reg_imm_reg_0_rule: {
      addsarI_reg_imm_reg_0Node *node = new addsarI_reg_imm_reg_0Node();
      return node;
    }
  case addshrI_reg_reg_reg_rule: {
      addshrI_reg_reg_regNode *node = new addshrI_reg_reg_regNode();
      return node;
    }
  case addshrI_reg_reg_reg_0_rule: {
      addshrI_reg_reg_reg_0Node *node = new addshrI_reg_reg_reg_0Node();
      return node;
    }
  case addshrI_reg_imm_reg_rule: {
      addshrI_reg_imm_regNode *node = new addshrI_reg_imm_regNode();
      return node;
    }
  case addshrI_reg_imm_reg_0_rule: {
      addshrI_reg_imm_reg_0Node *node = new addshrI_reg_imm_reg_0Node();
      return node;
    }
  case addI_reg_aimmI_rule: {
      addI_reg_aimmINode *node = new addI_reg_aimmINode();
      return node;
    }
  case addP_reg_reg_rule: {
      addP_reg_regNode *node = new addP_reg_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addshlP_reg_reg_imm_rule: {
      addshlP_reg_reg_immNode *node = new addshlP_reg_reg_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addP_reg_aimmX_rule: {
      addP_reg_aimmXNode *node = new addP_reg_aimmXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addL_reg_reg_rule: {
      addL_reg_regNode *node = new addL_reg_regNode();
      return node;
    }
  case addL_reg_immRot_rule: {
      addL_reg_immRotNode *node = new addL_reg_immRotNode();
      return node;
    }
  case loadPLocked_rule: {
      loadPLockedNode *node = new loadPLockedNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storePConditional_rule: {
      storePConditionalNode *node = new storePConditionalNode();
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case storeXConditional_rule: {
      storeXConditionalNode *node = new storeXConditionalNode();
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case compareAndSwapL_bool_rule: {
      compareAndSwapL_boolNode *node = new compareAndSwapL_boolNode();
      node->set_opnd_array(4, MachOperGenerator(IREGLD));
      return node;
    }
  case compareAndSwapI_bool_rule: {
      compareAndSwapI_boolNode *node = new compareAndSwapI_boolNode();
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case compareAndSwapP_bool_rule: {
      compareAndSwapP_boolNode *node = new compareAndSwapP_boolNode();
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xaddI_aimmI_no_res_rule: {
      xaddI_aimmI_no_resNode *node = new xaddI_aimmI_no_resNode();
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xaddI_reg_no_res_rule: {
      xaddI_reg_no_resNode *node = new xaddI_reg_no_resNode();
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xaddI_aimmI_rule: {
      xaddI_aimmINode *node = new xaddI_aimmINode();
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      node->set_opnd_array(5, MachOperGenerator(IREGI));
      return node;
    }
  case xaddI_reg_rule: {
      xaddI_regNode *node = new xaddI_regNode();
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      node->set_opnd_array(5, MachOperGenerator(IREGI));
      return node;
    }
  case xaddL_reg_no_res_rule: {
      xaddL_reg_no_resNode *node = new xaddL_reg_no_resNode();
      node->set_opnd_array(3, MachOperGenerator(IREGLD));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xaddL_immRot_no_res_rule: {
      xaddL_immRot_no_resNode *node = new xaddL_immRot_no_resNode();
      node->set_opnd_array(3, MachOperGenerator(IREGLD));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xaddL_reg_rule: {
      xaddL_regNode *node = new xaddL_regNode();
      node->set_opnd_array(3, MachOperGenerator(IREGLD));
      node->set_opnd_array(4, MachOperGenerator(IREGLD));
      node->set_opnd_array(5, MachOperGenerator(IREGI));
      return node;
    }
  case xaddL_immRot_rule: {
      xaddL_immRotNode *node = new xaddL_immRotNode();
      node->set_opnd_array(3, MachOperGenerator(IREGLD));
      node->set_opnd_array(4, MachOperGenerator(IREGLD));
      node->set_opnd_array(5, MachOperGenerator(IREGI));
      return node;
    }
  case xchgI_rule: {
      xchgINode *node = new xchgINode();
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xchgL_rule: {
      xchgLNode *node = new xchgLNode();
      node->set_opnd_array(3, MachOperGenerator(IREGLD));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case xchgP_rule: {
      xchgPNode *node = new xchgPNode();
      node->set_opnd_array(3, MachOperGenerator(IREGP));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case subI_reg_reg_rule: {
      subI_reg_regNode *node = new subI_reg_regNode();
      return node;
    }
  case subshlI_reg_reg_reg_rule: {
      subshlI_reg_reg_regNode *node = new subshlI_reg_reg_regNode();
      return node;
    }
  case subshlI_reg_reg_imm_rule: {
      subshlI_reg_reg_immNode *node = new subshlI_reg_reg_immNode();
      return node;
    }
  case subsarI_reg_reg_reg_rule: {
      subsarI_reg_reg_regNode *node = new subsarI_reg_reg_regNode();
      return node;
    }
  case subsarI_reg_reg_imm_rule: {
      subsarI_reg_reg_immNode *node = new subsarI_reg_reg_immNode();
      return node;
    }
  case subshrI_reg_reg_reg_rule: {
      subshrI_reg_reg_regNode *node = new subshrI_reg_reg_regNode();
      return node;
    }
  case subshrI_reg_reg_imm_rule: {
      subshrI_reg_reg_immNode *node = new subshrI_reg_reg_immNode();
      return node;
    }
  case rsbshlI_reg_reg_reg_rule: {
      rsbshlI_reg_reg_regNode *node = new rsbshlI_reg_reg_regNode();
      return node;
    }
  case rsbshlI_reg_imm_reg_rule: {
      rsbshlI_reg_imm_regNode *node = new rsbshlI_reg_imm_regNode();
      return node;
    }
  case rsbsarI_reg_reg_reg_rule: {
      rsbsarI_reg_reg_regNode *node = new rsbsarI_reg_reg_regNode();
      return node;
    }
  case rsbsarI_reg_imm_reg_rule: {
      rsbsarI_reg_imm_regNode *node = new rsbsarI_reg_imm_regNode();
      return node;
    }
  case rsbshrI_reg_reg_reg_rule: {
      rsbshrI_reg_reg_regNode *node = new rsbshrI_reg_reg_regNode();
      return node;
    }
  case rsbshrI_reg_imm_reg_rule: {
      rsbshrI_reg_imm_regNode *node = new rsbshrI_reg_imm_regNode();
      return node;
    }
  case subI_reg_aimmI_rule: {
      subI_reg_aimmINode *node = new subI_reg_aimmINode();
      return node;
    }
  case subI_reg_immRotneg_rule: {
      subI_reg_immRotnegNode *node = new subI_reg_immRotnegNode();
      return node;
    }
  case subI_immRot_reg_rule: {
      subI_immRot_regNode *node = new subI_immRot_regNode();
      return node;
    }
  case subL_reg_reg_rule: {
      subL_reg_regNode *node = new subL_reg_regNode();
      return node;
    }
  case subL_reg_immRot_rule: {
      subL_reg_immRotNode *node = new subL_reg_immRotNode();
      return node;
    }
  case negL_reg_reg_rule: {
      negL_reg_regNode *node = new negL_reg_regNode();
      return node;
    }
  case mulI_reg_reg_rule: {
      mulI_reg_regNode *node = new mulI_reg_regNode();
      return node;
    }
  case mulL_reg_reg_rule: {
      mulL_reg_regNode *node = new mulL_reg_regNode();
      return node;
    }
  case divI_reg_reg_rule: {
      divI_reg_regNode *node = new divI_reg_regNode();
      return node;
    }
  case divL_reg_reg_rule: {
      divL_reg_regNode *node = new divL_reg_regNode();
      return node;
    }
  case modI_reg_reg_rule: {
      modI_reg_regNode *node = new modI_reg_regNode();
      return node;
    }
  case modL_reg_reg_rule: {
      modL_reg_regNode *node = new modL_reg_regNode();
      return node;
    }
  case shlI_reg_reg_rule: {
      shlI_reg_regNode *node = new shlI_reg_regNode();
      return node;
    }
  case shlI_reg_imm5_rule: {
      shlI_reg_imm5Node *node = new shlI_reg_imm5Node();
      return node;
    }
  case shlL_reg_reg_rule: {
      shlL_reg_regNode *node = new shlL_reg_regNode();
      return node;
    }
  case shlL_reg_imm6_rule: {
      shlL_reg_imm6Node *node = new shlL_reg_imm6Node();
      return node;
    }
  case shlL_reg_imm5_rule: {
      shlL_reg_imm5Node *node = new shlL_reg_imm5Node();
      return node;
    }
  case sarI_reg_reg_rule: {
      sarI_reg_regNode *node = new sarI_reg_regNode();
      return node;
    }
  case sarI_reg_imm5_rule: {
      sarI_reg_imm5Node *node = new sarI_reg_imm5Node();
      return node;
    }
  case sarL_reg_reg_rule: {
      sarL_reg_regNode *node = new sarL_reg_regNode();
      return node;
    }
  case sarL_reg_imm6_rule: {
      sarL_reg_imm6Node *node = new sarL_reg_imm6Node();
      return node;
    }
  case sarL_reg_imm5_rule: {
      sarL_reg_imm5Node *node = new sarL_reg_imm5Node();
      return node;
    }
  case shrI_reg_reg_rule: {
      shrI_reg_regNode *node = new shrI_reg_regNode();
      return node;
    }
  case shrI_reg_imm5_rule: {
      shrI_reg_imm5Node *node = new shrI_reg_imm5Node();
      return node;
    }
  case shrL_reg_reg_rule: {
      shrL_reg_regNode *node = new shrL_reg_regNode();
      return node;
    }
  case shrL_reg_imm6_rule: {
      shrL_reg_imm6Node *node = new shrL_reg_imm6Node();
      return node;
    }
  case shrL_reg_imm5_rule: {
      shrL_reg_imm5Node *node = new shrL_reg_imm5Node();
      return node;
    }
  case shrP_reg_imm5_rule: {
      shrP_reg_imm5Node *node = new shrP_reg_imm5Node();
      return node;
    }
  case addF_reg_reg_rule: {
      addF_reg_regNode *node = new addF_reg_regNode();
      return node;
    }
  case addD_reg_reg_rule: {
      addD_reg_regNode *node = new addD_reg_regNode();
      return node;
    }
  case subF_reg_reg_rule: {
      subF_reg_regNode *node = new subF_reg_regNode();
      return node;
    }
  case subD_reg_reg_rule: {
      subD_reg_regNode *node = new subD_reg_regNode();
      return node;
    }
  case mulF_reg_reg_rule: {
      mulF_reg_regNode *node = new mulF_reg_regNode();
      return node;
    }
  case mulD_reg_reg_rule: {
      mulD_reg_regNode *node = new mulD_reg_regNode();
      return node;
    }
  case divF_reg_reg_rule: {
      divF_reg_regNode *node = new divF_reg_regNode();
      return node;
    }
  case divD_reg_reg_rule: {
      divD_reg_regNode *node = new divD_reg_regNode();
      return node;
    }
  case absD_reg_rule: {
      absD_regNode *node = new absD_regNode();
      return node;
    }
  case absF_reg_rule: {
      absF_regNode *node = new absF_regNode();
      return node;
    }
  case negF_reg_rule: {
      negF_regNode *node = new negF_regNode();
      return node;
    }
  case negD_reg_rule: {
      negD_regNode *node = new negD_regNode();
      return node;
    }
  case sqrtF_reg_reg_rule: {
      sqrtF_reg_regNode *node = new sqrtF_reg_regNode();
      return node;
    }
  case sqrtD_reg_reg_rule: {
      sqrtD_reg_regNode *node = new sqrtD_reg_regNode();
      return node;
    }
  case andI_reg_reg_rule: {
      andI_reg_regNode *node = new andI_reg_regNode();
      return node;
    }
  case andshlI_reg_reg_reg_rule: {
      andshlI_reg_reg_regNode *node = new andshlI_reg_reg_regNode();
      return node;
    }
  case andshlI_reg_reg_reg_0_rule: {
      andshlI_reg_reg_reg_0Node *node = new andshlI_reg_reg_reg_0Node();
      return node;
    }
  case andshlI_reg_reg_imm_rule: {
      andshlI_reg_reg_immNode *node = new andshlI_reg_reg_immNode();
      return node;
    }
  case andshlI_reg_reg_imm_0_rule: {
      andshlI_reg_reg_imm_0Node *node = new andshlI_reg_reg_imm_0Node();
      return node;
    }
  case andsarI_reg_reg_reg_rule: {
      andsarI_reg_reg_regNode *node = new andsarI_reg_reg_regNode();
      return node;
    }
  case andsarI_reg_reg_reg_0_rule: {
      andsarI_reg_reg_reg_0Node *node = new andsarI_reg_reg_reg_0Node();
      return node;
    }
  case andsarI_reg_reg_imm_rule: {
      andsarI_reg_reg_immNode *node = new andsarI_reg_reg_immNode();
      return node;
    }
  case andsarI_reg_reg_imm_0_rule: {
      andsarI_reg_reg_imm_0Node *node = new andsarI_reg_reg_imm_0Node();
      return node;
    }
  case andshrI_reg_reg_reg_rule: {
      andshrI_reg_reg_regNode *node = new andshrI_reg_reg_regNode();
      return node;
    }
  case andshrI_reg_reg_reg_0_rule: {
      andshrI_reg_reg_reg_0Node *node = new andshrI_reg_reg_reg_0Node();
      return node;
    }
  case andshrI_reg_reg_imm_rule: {
      andshrI_reg_reg_immNode *node = new andshrI_reg_reg_immNode();
      return node;
    }
  case andshrI_reg_reg_imm_0_rule: {
      andshrI_reg_reg_imm_0Node *node = new andshrI_reg_reg_imm_0Node();
      return node;
    }
  case andI_reg_limm_rule: {
      andI_reg_limmNode *node = new andI_reg_limmNode();
      return node;
    }
  case andI_reg_limmn_rule: {
      andI_reg_limmnNode *node = new andI_reg_limmnNode();
      return node;
    }
  case andL_reg_reg_rule: {
      andL_reg_regNode *node = new andL_reg_regNode();
      return node;
    }
  case andL_reg_immRot_rule: {
      andL_reg_immRotNode *node = new andL_reg_immRotNode();
      return node;
    }
  case orI_reg_reg_rule: {
      orI_reg_regNode *node = new orI_reg_regNode();
      return node;
    }
  case orshlI_reg_reg_reg_rule: {
      orshlI_reg_reg_regNode *node = new orshlI_reg_reg_regNode();
      return node;
    }
  case orshlI_reg_reg_reg_0_rule: {
      orshlI_reg_reg_reg_0Node *node = new orshlI_reg_reg_reg_0Node();
      return node;
    }
  case orshlI_reg_reg_imm_rule: {
      orshlI_reg_reg_immNode *node = new orshlI_reg_reg_immNode();
      return node;
    }
  case orshlI_reg_reg_imm_0_rule: {
      orshlI_reg_reg_imm_0Node *node = new orshlI_reg_reg_imm_0Node();
      return node;
    }
  case orsarI_reg_reg_reg_rule: {
      orsarI_reg_reg_regNode *node = new orsarI_reg_reg_regNode();
      return node;
    }
  case orsarI_reg_reg_reg_0_rule: {
      orsarI_reg_reg_reg_0Node *node = new orsarI_reg_reg_reg_0Node();
      return node;
    }
  case orsarI_reg_reg_imm_rule: {
      orsarI_reg_reg_immNode *node = new orsarI_reg_reg_immNode();
      return node;
    }
  case orsarI_reg_reg_imm_0_rule: {
      orsarI_reg_reg_imm_0Node *node = new orsarI_reg_reg_imm_0Node();
      return node;
    }
  case orshrI_reg_reg_reg_rule: {
      orshrI_reg_reg_regNode *node = new orshrI_reg_reg_regNode();
      return node;
    }
  case orshrI_reg_reg_reg_0_rule: {
      orshrI_reg_reg_reg_0Node *node = new orshrI_reg_reg_reg_0Node();
      return node;
    }
  case orshrI_reg_reg_imm_rule: {
      orshrI_reg_reg_immNode *node = new orshrI_reg_reg_immNode();
      return node;
    }
  case orshrI_reg_reg_imm_0_rule: {
      orshrI_reg_reg_imm_0Node *node = new orshrI_reg_reg_imm_0Node();
      return node;
    }
  case orI_reg_limm_rule: {
      orI_reg_limmNode *node = new orI_reg_limmNode();
      return node;
    }
  case orL_reg_reg_rule: {
      orL_reg_regNode *node = new orL_reg_regNode();
      return node;
    }
  case orL_reg_immRot_rule: {
      orL_reg_immRotNode *node = new orL_reg_immRotNode();
      return node;
    }
  case xorI_reg_reg_rule: {
      xorI_reg_regNode *node = new xorI_reg_regNode();
      return node;
    }
  case xorshlI_reg_reg_reg_rule: {
      xorshlI_reg_reg_regNode *node = new xorshlI_reg_reg_regNode();
      return node;
    }
  case xorshlI_reg_reg_reg_0_rule: {
      xorshlI_reg_reg_reg_0Node *node = new xorshlI_reg_reg_reg_0Node();
      return node;
    }
  case xorshlI_reg_reg_imm_rule: {
      xorshlI_reg_reg_immNode *node = new xorshlI_reg_reg_immNode();
      return node;
    }
  case xorshlI_reg_reg_imm_0_rule: {
      xorshlI_reg_reg_imm_0Node *node = new xorshlI_reg_reg_imm_0Node();
      return node;
    }
  case xorsarI_reg_reg_reg_rule: {
      xorsarI_reg_reg_regNode *node = new xorsarI_reg_reg_regNode();
      return node;
    }
  case xorsarI_reg_reg_reg_0_rule: {
      xorsarI_reg_reg_reg_0Node *node = new xorsarI_reg_reg_reg_0Node();
      return node;
    }
  case xorsarI_reg_reg_imm_rule: {
      xorsarI_reg_reg_immNode *node = new xorsarI_reg_reg_immNode();
      return node;
    }
  case xorsarI_reg_reg_imm_0_rule: {
      xorsarI_reg_reg_imm_0Node *node = new xorsarI_reg_reg_imm_0Node();
      return node;
    }
  case xorshrI_reg_reg_reg_rule: {
      xorshrI_reg_reg_regNode *node = new xorshrI_reg_reg_regNode();
      return node;
    }
  case xorshrI_reg_reg_reg_0_rule: {
      xorshrI_reg_reg_reg_0Node *node = new xorshrI_reg_reg_reg_0Node();
      return node;
    }
  case xorshrI_reg_reg_imm_rule: {
      xorshrI_reg_reg_immNode *node = new xorshrI_reg_reg_immNode();
      return node;
    }
  case xorshrI_reg_reg_imm_0_rule: {
      xorshrI_reg_reg_imm_0Node *node = new xorshrI_reg_reg_imm_0Node();
      return node;
    }
  case xorI_reg_imm_rule: {
      xorI_reg_immNode *node = new xorI_reg_immNode();
      return node;
    }
  case xorL_reg_reg_rule: {
      xorL_reg_regNode *node = new xorL_reg_regNode();
      return node;
    }
  case xorL_reg_immRot_rule: {
      xorL_reg_immRotNode *node = new xorL_reg_immRotNode();
      return node;
    }
  case convI2B_rule: {
      convI2BNode *node = new convI2BNode();
      return node;
    }
  case convP2B_rule: {
      convP2BNode *node = new convP2BNode();
      return node;
    }
  case cmpLTMask_reg_reg_rule: {
      cmpLTMask_reg_regNode *node = new cmpLTMask_reg_regNode();
      return node;
    }
  case cmpLTMask_reg_imm_rule: {
      cmpLTMask_reg_immNode *node = new cmpLTMask_reg_immNode();
      return node;
    }
  case cadd_cmpLTMask3_rule: {
      cadd_cmpLTMask3Node *node = new cadd_cmpLTMask3Node();
      return node;
    }
  case cadd_cmpLTMask3_1_rule: {
      cadd_cmpLTMask3_1Node *node = new cadd_cmpLTMask3_1Node();
      return node;
    }
  case cadd_cmpLTMask3_0_rule: {
      cadd_cmpLTMask3_0Node *node = new cadd_cmpLTMask3_0Node();
      return node;
    }
  case cadd_cmpLTMask3_2_rule: {
      cadd_cmpLTMask3_2Node *node = new cadd_cmpLTMask3_2Node();
      return node;
    }
  case cadd_cmpLTMask4_rule: {
      cadd_cmpLTMask4Node *node = new cadd_cmpLTMask4Node();
      return node;
    }
  case cadd_cmpLTMask4_1_rule: {
      cadd_cmpLTMask4_1Node *node = new cadd_cmpLTMask4_1Node();
      return node;
    }
  case cadd_cmpLTMask4_0_rule: {
      cadd_cmpLTMask4_0Node *node = new cadd_cmpLTMask4_0Node();
      return node;
    }
  case cadd_cmpLTMask4_2_rule: {
      cadd_cmpLTMask4_2Node *node = new cadd_cmpLTMask4_2Node();
      return node;
    }
  case cadd_cmpLTMask_rule: {
      cadd_cmpLTMaskNode *node = new cadd_cmpLTMaskNode();
      return node;
    }
  case cadd_cmpLTMask_1_rule: {
      cadd_cmpLTMask_1Node *node = new cadd_cmpLTMask_1Node();
      return node;
    }
  case cadd_cmpLTMask_0_rule: {
      cadd_cmpLTMask_0Node *node = new cadd_cmpLTMask_0Node();
      return node;
    }
  case cadd_cmpLTMask_2_rule: {
      cadd_cmpLTMask_2Node *node = new cadd_cmpLTMask_2Node();
      return node;
    }
  case convD2F_reg_rule: {
      convD2F_regNode *node = new convD2F_regNode();
      return node;
    }
  case convD2I_reg_reg_rule: {
      convD2I_reg_regNode *node = new convD2I_reg_regNode();
      node->set_opnd_array(2, MachOperGenerator(REGF));
      return node;
    }
  case convD2L_reg_rule: {
      convD2L_regNode *node = new convD2L_regNode();
      return node;
    }
  case convF2D_reg_rule: {
      convF2D_regNode *node = new convF2D_regNode();
      return node;
    }
  case convF2I_reg_reg_rule: {
      convF2I_reg_regNode *node = new convF2I_reg_regNode();
      node->set_opnd_array(2, MachOperGenerator(REGF));
      return node;
    }
  case convF2L_reg_rule: {
      convF2L_regNode *node = new convF2L_regNode();
      return node;
    }
  case convI2D_reg_reg_rule: {
      convI2D_reg_regNode *node = new convI2D_reg_regNode();
      return node;
    }
  case convI2F_reg_reg_rule: {
      convI2F_reg_regNode *node = new convI2F_reg_regNode();
      return node;
    }
  case convI2L_reg_rule: {
      convI2L_regNode *node = new convI2L_regNode();
      return node;
    }
  case convI2L_reg_zex_rule: {
      convI2L_reg_zexNode *node = new convI2L_reg_zexNode();
      return node;
    }
  case zerox_long_rule: {
      zerox_longNode *node = new zerox_longNode();
      return node;
    }
  case MoveF2I_reg_reg_rule: {
      MoveF2I_reg_regNode *node = new MoveF2I_reg_regNode();
      return node;
    }
  case MoveI2F_reg_reg_rule: {
      MoveI2F_reg_regNode *node = new MoveI2F_reg_regNode();
      return node;
    }
  case MoveD2L_reg_reg_rule: {
      MoveD2L_reg_regNode *node = new MoveD2L_reg_regNode();
      return node;
    }
  case MoveL2D_reg_reg_rule: {
      MoveL2D_reg_regNode *node = new MoveL2D_reg_regNode();
      return node;
    }
  case convL2D_reg_slow_fxtof_rule: {
      convL2D_reg_slow_fxtofNode *node = new convL2D_reg_slow_fxtofNode();
      return node;
    }
  case convL2I_reg_rule: {
      convL2I_regNode *node = new convL2I_regNode();
      return node;
    }
  case shrL_reg_imm6_L2I_rule: {
      shrL_reg_imm6_L2INode *node = new shrL_reg_imm6_L2INode();
      return node;
    }
  case compI_iReg_rule: {
      compI_iRegNode *node = new compI_iRegNode();
      return node;
    }
  case compU_iReg_rule: {
      compU_iRegNode *node = new compU_iRegNode();
      return node;
    }
  case compI_iReg_immneg_rule: {
      compI_iReg_immnegNode *node = new compI_iReg_immnegNode();
      return node;
    }
  case compI_iReg_imm_rule: {
      compI_iReg_immNode *node = new compI_iReg_immNode();
      return node;
    }
  case testI_reg_reg_rule: {
      testI_reg_regNode *node = new testI_reg_regNode();
      return node;
    }
  case testshlI_reg_reg_reg_rule: {
      testshlI_reg_reg_regNode *node = new testshlI_reg_reg_regNode();
      return node;
    }
  case testshlI_reg_reg_reg_0_rule: {
      testshlI_reg_reg_reg_0Node *node = new testshlI_reg_reg_reg_0Node();
      return node;
    }
  case testshlI_reg_reg_imm_rule: {
      testshlI_reg_reg_immNode *node = new testshlI_reg_reg_immNode();
      return node;
    }
  case testshlI_reg_reg_imm_0_rule: {
      testshlI_reg_reg_imm_0Node *node = new testshlI_reg_reg_imm_0Node();
      return node;
    }
  case testsarI_reg_reg_reg_rule: {
      testsarI_reg_reg_regNode *node = new testsarI_reg_reg_regNode();
      return node;
    }
  case testsarI_reg_reg_reg_0_rule: {
      testsarI_reg_reg_reg_0Node *node = new testsarI_reg_reg_reg_0Node();
      return node;
    }
  case testsarI_reg_reg_imm_rule: {
      testsarI_reg_reg_immNode *node = new testsarI_reg_reg_immNode();
      return node;
    }
  case testsarI_reg_reg_imm_0_rule: {
      testsarI_reg_reg_imm_0Node *node = new testsarI_reg_reg_imm_0Node();
      return node;
    }
  case testshrI_reg_reg_reg_rule: {
      testshrI_reg_reg_regNode *node = new testshrI_reg_reg_regNode();
      return node;
    }
  case testshrI_reg_reg_reg_0_rule: {
      testshrI_reg_reg_reg_0Node *node = new testshrI_reg_reg_reg_0Node();
      return node;
    }
  case testshrI_reg_reg_imm_rule: {
      testshrI_reg_reg_immNode *node = new testshrI_reg_reg_immNode();
      return node;
    }
  case testshrI_reg_reg_imm_0_rule: {
      testshrI_reg_reg_imm_0Node *node = new testshrI_reg_reg_imm_0Node();
      return node;
    }
  case testI_reg_imm_rule: {
      testI_reg_immNode *node = new testI_reg_immNode();
      return node;
    }
  case compL_reg_reg_LTGE_rule: {
      compL_reg_reg_LTGENode *node = new compL_reg_reg_LTGENode();
      node->set_opnd_array(3, MachOperGenerator(IREGL));
      return node;
    }
  case compL_reg_reg_EQNE_rule: {
      compL_reg_reg_EQNENode *node = new compL_reg_reg_EQNENode();
      return node;
    }
  case compL_reg_reg_LEGT_rule: {
      compL_reg_reg_LEGTNode *node = new compL_reg_reg_LEGTNode();
      node->set_opnd_array(3, MachOperGenerator(IREGL));
      return node;
    }
  case compL_reg_con_LTGE_rule: {
      compL_reg_con_LTGENode *node = new compL_reg_con_LTGENode();
      node->set_opnd_array(3, MachOperGenerator(IREGL));
      return node;
    }
  case compL_reg_con_EQNE_rule: {
      compL_reg_con_EQNENode *node = new compL_reg_con_EQNENode();
      return node;
    }
  case compL_reg_con_LEGT_rule: {
      compL_reg_con_LEGTNode *node = new compL_reg_con_LEGTNode();
      node->set_opnd_array(3, MachOperGenerator(IREGL));
      return node;
    }
  case compU_iReg_imm_rule: {
      compU_iReg_immNode *node = new compU_iReg_immNode();
      return node;
    }
  case compP_iRegP_rule: {
      compP_iRegPNode *node = new compP_iRegPNode();
      return node;
    }
  case compP_iRegP_imm_rule: {
      compP_iRegP_immNode *node = new compP_iRegP_immNode();
      return node;
    }
  case minI_eReg_rule: {
      minI_eRegNode *node = new minI_eRegNode();
      return node;
    }
  case maxI_eReg_rule: {
      maxI_eRegNode *node = new maxI_eRegNode();
      return node;
    }
  case cmpF_cc_rule: {
      cmpF_ccNode *node = new cmpF_ccNode();
      return node;
    }
  case cmpF0_cc_rule: {
      cmpF0_ccNode *node = new cmpF0_ccNode();
      return node;
    }
  case cmpD_cc_rule: {
      cmpD_ccNode *node = new cmpD_ccNode();
      return node;
    }
  case cmpD0_cc_rule: {
      cmpD0_ccNode *node = new cmpD0_ccNode();
      return node;
    }
  case cmpF_reg_rule: {
      cmpF_regNode *node = new cmpF_regNode();
      return node;
    }
  case cmpF0_reg_rule: {
      cmpF0_regNode *node = new cmpF0_regNode();
      return node;
    }
  case cmpD_reg_rule: {
      cmpD_regNode *node = new cmpD_regNode();
      return node;
    }
  case cmpD0_reg_rule: {
      cmpD0_regNode *node = new cmpD0_regNode();
      return node;
    }
  case jumpXtnd_rule: {
      jumpXtndNode *node = new jumpXtndNode();
      node->set_opnd_array(2, MachOperGenerator(IREGP));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case branch_rule: {
      branchNode *node = new branchNode();
      node->set_opnd_array(1, MachOperGenerator(LABEL));
      return node;
    }
  case branchCon_rule: {
      branchConNode *node = new branchConNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchCon_EQNELTGE_rule: {
      branchCon_EQNELTGENode *node = new branchCon_EQNELTGENode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchConU_rule: {
      branchConUNode *node = new branchConUNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchConP_rule: {
      branchConPNode *node = new branchConPNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchConL_LTGE_rule: {
      branchConL_LTGENode *node = new branchConL_LTGENode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchConL_EQNE_rule: {
      branchConL_EQNENode *node = new branchConL_EQNENode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchConL_LEGT_rule: {
      branchConL_LEGTNode *node = new branchConL_LEGTNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case branchLoopEnd_rule: {
      branchLoopEndNode *node = new branchLoopEndNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case cmpL3_reg_reg_rule: {
      cmpL3_reg_regNode *node = new cmpL3_reg_regNode();
      return node;
    }
  case cmovLL_reg_LTGE_rule: {
      cmovLL_reg_LTGENode *node = new cmovLL_reg_LTGENode();
      return node;
    }
  case cmovLL_reg_EQNE_rule: {
      cmovLL_reg_EQNENode *node = new cmovLL_reg_EQNENode();
      return node;
    }
  case cmovLL_reg_LEGT_rule: {
      cmovLL_reg_LEGTNode *node = new cmovLL_reg_LEGTNode();
      return node;
    }
  case cmovLL_imm_LTGE_rule: {
      cmovLL_imm_LTGENode *node = new cmovLL_imm_LTGENode();
      return node;
    }
  case cmovLL_imm_EQNE_rule: {
      cmovLL_imm_EQNENode *node = new cmovLL_imm_EQNENode();
      return node;
    }
  case cmovLL_imm_LEGT_rule: {
      cmovLL_imm_LEGTNode *node = new cmovLL_imm_LEGTNode();
      return node;
    }
  case cmovIL_reg_LTGE_rule: {
      cmovIL_reg_LTGENode *node = new cmovIL_reg_LTGENode();
      return node;
    }
  case cmovIL_reg_EQNE_rule: {
      cmovIL_reg_EQNENode *node = new cmovIL_reg_EQNENode();
      return node;
    }
  case cmovIL_reg_LEGT_rule: {
      cmovIL_reg_LEGTNode *node = new cmovIL_reg_LEGTNode();
      return node;
    }
  case cmovIL_imm_LTGE_rule: {
      cmovIL_imm_LTGENode *node = new cmovIL_imm_LTGENode();
      return node;
    }
  case cmovIL_imm_EQNE_rule: {
      cmovIL_imm_EQNENode *node = new cmovIL_imm_EQNENode();
      return node;
    }
  case cmovIL_imm_LEGT_rule: {
      cmovIL_imm_LEGTNode *node = new cmovIL_imm_LEGTNode();
      return node;
    }
  case cmovPL_reg_LTGE_rule: {
      cmovPL_reg_LTGENode *node = new cmovPL_reg_LTGENode();
      return node;
    }
  case cmovPL_reg_EQNE_rule: {
      cmovPL_reg_EQNENode *node = new cmovPL_reg_EQNENode();
      return node;
    }
  case cmovPL_reg_LEGT_rule: {
      cmovPL_reg_LEGTNode *node = new cmovPL_reg_LEGTNode();
      return node;
    }
  case cmovPL_imm_LTGE_rule: {
      cmovPL_imm_LTGENode *node = new cmovPL_imm_LTGENode();
      return node;
    }
  case cmovPL_imm_EQNE_rule: {
      cmovPL_imm_EQNENode *node = new cmovPL_imm_EQNENode();
      return node;
    }
  case cmovPL_imm_LEGT_rule: {
      cmovPL_imm_LEGTNode *node = new cmovPL_imm_LEGTNode();
      return node;
    }
  case cmovFL_reg_LTGE_rule: {
      cmovFL_reg_LTGENode *node = new cmovFL_reg_LTGENode();
      return node;
    }
  case cmovFL_reg_EQNE_rule: {
      cmovFL_reg_EQNENode *node = new cmovFL_reg_EQNENode();
      return node;
    }
  case cmovFL_reg_LEGT_rule: {
      cmovFL_reg_LEGTNode *node = new cmovFL_reg_LEGTNode();
      return node;
    }
  case cmovDL_reg_LTGE_rule: {
      cmovDL_reg_LTGENode *node = new cmovDL_reg_LTGENode();
      return node;
    }
  case cmovDL_reg_EQNE_rule: {
      cmovDL_reg_EQNENode *node = new cmovDL_reg_EQNENode();
      return node;
    }
  case cmovDL_reg_LEGT_rule: {
      cmovDL_reg_LEGTNode *node = new cmovDL_reg_LEGTNode();
      return node;
    }
  case safePoint_poll_rule: {
      safePoint_pollNode *node = new safePoint_pollNode();
      return node;
    }
  case CallStaticJavaDirect_rule: {
      CallStaticJavaDirectNode *node = new CallStaticJavaDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD));
      return node;
    }
  case CallStaticJavaHandle_rule: {
      CallStaticJavaHandleNode *node = new CallStaticJavaHandleNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD));
      return node;
    }
  case CallDynamicJavaDirect_rule: {
      CallDynamicJavaDirectNode *node = new CallDynamicJavaDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD));
      return node;
    }
  case CallRuntimeDirect_rule: {
      CallRuntimeDirectNode *node = new CallRuntimeDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD));
      return node;
    }
  case CallLeafDirect_rule: {
      CallLeafDirectNode *node = new CallLeafDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD));
      return node;
    }
  case CallLeafNoFPDirect_rule: {
      CallLeafNoFPDirectNode *node = new CallLeafNoFPDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD));
      return node;
    }
  case TailCalljmpInd_rule: {
      TailCalljmpIndNode *node = new TailCalljmpIndNode();
      return node;
    }
  case Ret_rule: {
      RetNode *node = new RetNode();
      return node;
    }
  case tailjmpInd_rule: {
      tailjmpIndNode *node = new tailjmpIndNode();
      return node;
    }
  case CreateException_rule: {
      CreateExceptionNode *node = new CreateExceptionNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case RethrowException_rule: {
      RethrowExceptionNode *node = new RethrowExceptionNode();
      return node;
    }
  case ShouldNotReachHere_rule: {
      ShouldNotReachHereNode *node = new ShouldNotReachHereNode();
      return node;
    }
  case partialSubtypeCheck_rule: {
      partialSubtypeCheckNode *node = new partialSubtypeCheckNode();
      return node;
    }
  case cmpFastLock_rule: {
      cmpFastLockNode *node = new cmpFastLockNode();
      node->set_opnd_array(3, MachOperGenerator(IREGP));
      node->set_opnd_array(4, MachOperGenerator(IREGP));
      node->_counters = _leaf->as_FastLock()->counters();
      node->_rtm_counters = _leaf->as_FastLock()->rtm_counters();
      node->_stack_rtm_counters = _leaf->as_FastLock()->stack_rtm_counters();
      return node;
    }
  case cmpFastUnlock_rule: {
      cmpFastUnlockNode *node = new cmpFastUnlockNode();
      node->set_opnd_array(3, MachOperGenerator(IREGP));
      node->set_opnd_array(4, MachOperGenerator(IREGP));
      return node;
    }
  case clear_array_rule: {
      clear_arrayNode *node = new clear_arrayNode();
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      node->set_opnd_array(4, MachOperGenerator(IREGI));
      return node;
    }
  case countLeadingZerosI_rule: {
      countLeadingZerosINode *node = new countLeadingZerosINode();
      return node;
    }
  case countLeadingZerosL_rule: {
      countLeadingZerosLNode *node = new countLeadingZerosLNode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      return node;
    }
  case countTrailingZerosI_rule: {
      countTrailingZerosINode *node = new countTrailingZerosINode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      return node;
    }
  case countTrailingZerosL_rule: {
      countTrailingZerosLNode *node = new countTrailingZerosLNode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->set_opnd_array(3, MachOperGenerator(IREGI));
      return node;
    }
  case popCountI_rule: {
      popCountINode *node = new popCountINode();
      node->set_opnd_array(2, MachOperGenerator(REGD_LOW));
      return node;
    }
  case popCountL_rule: {
      popCountLNode *node = new popCountLNode();
      node->set_opnd_array(2, MachOperGenerator(REGD_LOW));
      return node;
    }
  case bytes_reverse_int_rule: {
      bytes_reverse_intNode *node = new bytes_reverse_intNode();
      return node;
    }
  case bytes_reverse_long_rule: {
      bytes_reverse_longNode *node = new bytes_reverse_longNode();
      node->set_opnd_array(2, MachOperGenerator(IREGL));
      return node;
    }
  case bytes_reverse_unsigned_short_rule: {
      bytes_reverse_unsigned_shortNode *node = new bytes_reverse_unsigned_shortNode();
      return node;
    }
  case bytes_reverse_short_rule: {
      bytes_reverse_shortNode *node = new bytes_reverse_shortNode();
      return node;
    }
  case loadV8_rule: {
      loadV8Node *node = new loadV8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadV16_rule: {
      loadV16Node *node = new loadV16Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeV8_rule: {
      storeV8Node *node = new storeV8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeV16_rule: {
      storeV16Node *node = new storeV16Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl8B_reg_rule: {
      Repl8B_regNode *node = new Repl8B_regNode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl8B_reg_simd_rule: {
      Repl8B_reg_simdNode *node = new Repl8B_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl16B_reg_rule: {
      Repl16B_regNode *node = new Repl16B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl8B_immI_rule: {
      Repl8B_immINode *node = new Repl8B_immINode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl8B_immU8_rule: {
      Repl8B_immU8Node *node = new Repl8B_immU8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl16B_immU8_rule: {
      Repl16B_immU8Node *node = new Repl16B_immU8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4S_reg_rule: {
      Repl4S_regNode *node = new Repl4S_regNode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4S_reg_simd_rule: {
      Repl4S_reg_simdNode *node = new Repl4S_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl8S_reg_rule: {
      Repl8S_regNode *node = new Repl8S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4S_immI_rule: {
      Repl4S_immINode *node = new Repl4S_immINode();
      node->set_opnd_array(2, MachOperGenerator(IREGP));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4S_immU8_rule: {
      Repl4S_immU8Node *node = new Repl4S_immU8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl8S_immU8_rule: {
      Repl8S_immU8Node *node = new Repl8S_immU8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2I_reg_rule: {
      Repl2I_regNode *node = new Repl2I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4I_reg_rule: {
      Repl4I_regNode *node = new Repl4I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2I_reg_simd_rule: {
      Repl2I_reg_simdNode *node = new Repl2I_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4I_reg_simd_rule: {
      Repl4I_reg_simdNode *node = new Repl4I_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2I_immI_rule: {
      Repl2I_immINode *node = new Repl2I_immINode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2I_immU8_rule: {
      Repl2I_immU8Node *node = new Repl2I_immU8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4I_immU8_rule: {
      Repl4I_immU8Node *node = new Repl4I_immU8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2L_reg_rule: {
      Repl2L_regNode *node = new Repl2L_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2F_regI_rule: {
      Repl2F_regINode *node = new Repl2F_regINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2F_reg_vfp_rule: {
      Repl2F_reg_vfpNode *node = new Repl2F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2F_reg_simd_rule: {
      Repl2F_reg_simdNode *node = new Repl2F_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4F_reg_rule: {
      Repl4F_regNode *node = new Repl4F_regNode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl4F_reg_simd_rule: {
      Repl4F_reg_simdNode *node = new Repl4F_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2F_immI_rule: {
      Repl2F_immINode *node = new Repl2F_immINode();
      node->set_opnd_array(2, MachOperGenerator(IREGI));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case Repl2D_reg_rule: {
      Repl2D_regNode *node = new Repl2D_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd8B_reg_rule: {
      vadd8B_regNode *node = new vadd8B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd16B_reg_rule: {
      vadd16B_regNode *node = new vadd16B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd4S_reg_rule: {
      vadd4S_regNode *node = new vadd4S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd8S_reg_rule: {
      vadd8S_regNode *node = new vadd8S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd2I_reg_rule: {
      vadd2I_regNode *node = new vadd2I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd4I_reg_rule: {
      vadd4I_regNode *node = new vadd4I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd2L_reg_rule: {
      vadd2L_regNode *node = new vadd2L_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd2F_reg_rule: {
      vadd2F_regNode *node = new vadd2F_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd2F_reg_vfp_rule: {
      vadd2F_reg_vfpNode *node = new vadd2F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd4F_reg_simd_rule: {
      vadd4F_reg_simdNode *node = new vadd4F_reg_simdNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd4F_reg_vfp_rule: {
      vadd4F_reg_vfpNode *node = new vadd4F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vadd2D_reg_vfp_rule: {
      vadd2D_reg_vfpNode *node = new vadd2D_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub8B_reg_rule: {
      vsub8B_regNode *node = new vsub8B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub16B_reg_rule: {
      vsub16B_regNode *node = new vsub16B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub4S_reg_rule: {
      vsub4S_regNode *node = new vsub4S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub16S_reg_rule: {
      vsub16S_regNode *node = new vsub16S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub2I_reg_rule: {
      vsub2I_regNode *node = new vsub2I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub4I_reg_rule: {
      vsub4I_regNode *node = new vsub4I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub2L_reg_rule: {
      vsub2L_regNode *node = new vsub2L_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub2F_reg_rule: {
      vsub2F_regNode *node = new vsub2F_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub2F_reg_vfp_rule: {
      vsub2F_reg_vfpNode *node = new vsub2F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub4F_reg_rule: {
      vsub4F_regNode *node = new vsub4F_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub4F_reg_vfp_rule: {
      vsub4F_reg_vfpNode *node = new vsub4F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsub2D_reg_vfp_rule: {
      vsub2D_reg_vfpNode *node = new vsub2D_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul4S_reg_rule: {
      vmul4S_regNode *node = new vmul4S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul8S_reg_rule: {
      vmul8S_regNode *node = new vmul8S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul2I_reg_rule: {
      vmul2I_regNode *node = new vmul2I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul4I_reg_rule: {
      vmul4I_regNode *node = new vmul4I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul2F_reg_rule: {
      vmul2F_regNode *node = new vmul2F_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul2F_reg_vfp_rule: {
      vmul2F_reg_vfpNode *node = new vmul2F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul4F_reg_rule: {
      vmul4F_regNode *node = new vmul4F_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul4F_reg_vfp_rule: {
      vmul4F_reg_vfpNode *node = new vmul4F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vmul2D_reg_vfp_rule: {
      vmul2D_reg_vfpNode *node = new vmul2D_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vdiv2F_reg_vfp_rule: {
      vdiv2F_reg_vfpNode *node = new vdiv2F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vdiv4F_reg_vfp_rule: {
      vdiv4F_reg_vfpNode *node = new vdiv4F_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vdiv2D_reg_vfp_rule: {
      vdiv2D_reg_vfpNode *node = new vdiv2D_reg_vfpNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vslcntD_rule: {
      vslcntDNode *node = new vslcntDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vslcntX_rule: {
      vslcntXNode *node = new vslcntXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrcntD_rule: {
      vsrcntDNode *node = new vsrcntDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrcntX_rule: {
      vsrcntXNode *node = new vsrcntXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl8B_reg_rule: {
      vsl8B_regNode *node = new vsl8B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl16B_reg_rule: {
      vsl16B_regNode *node = new vsl16B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl8B_immI_rule: {
      vsl8B_immINode *node = new vsl8B_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl16B_immI_rule: {
      vsl16B_immINode *node = new vsl16B_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl4S_reg_rule: {
      vsl4S_regNode *node = new vsl4S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl4S_reg_0_rule: {
      vsl4S_reg_0Node *node = new vsl4S_reg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl8S_reg_rule: {
      vsl8S_regNode *node = new vsl8S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl8S_reg_0_rule: {
      vsl8S_reg_0Node *node = new vsl8S_reg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl4S_immI_rule: {
      vsl4S_immINode *node = new vsl4S_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl8S_immI_rule: {
      vsl8S_immINode *node = new vsl8S_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl2I_reg_rule: {
      vsl2I_regNode *node = new vsl2I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl2I_reg_0_rule: {
      vsl2I_reg_0Node *node = new vsl2I_reg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl4I_reg_rule: {
      vsl4I_regNode *node = new vsl4I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl4I_reg_0_rule: {
      vsl4I_reg_0Node *node = new vsl4I_reg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl2I_immI_rule: {
      vsl2I_immINode *node = new vsl2I_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl4I_immI_rule: {
      vsl4I_immINode *node = new vsl4I_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl2L_reg_rule: {
      vsl2L_regNode *node = new vsl2L_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl2L_reg_0_rule: {
      vsl2L_reg_0Node *node = new vsl2L_reg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsl2L_immI_rule: {
      vsl2L_immINode *node = new vsl2L_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl4S_immI_rule: {
      vsrl4S_immINode *node = new vsrl4S_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl8S_immI_rule: {
      vsrl8S_immINode *node = new vsrl8S_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl2I_immI_rule: {
      vsrl2I_immINode *node = new vsrl2I_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl4I_immI_rule: {
      vsrl4I_immINode *node = new vsrl4I_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl2L_immI_rule: {
      vsrl2L_immINode *node = new vsrl2L_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra8B_reg_rule: {
      vsra8B_regNode *node = new vsra8B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl16B_reg_rule: {
      vsrl16B_regNode *node = new vsrl16B_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl8B_immI_rule: {
      vsrl8B_immINode *node = new vsrl8B_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsrl16B_immI_rule: {
      vsrl16B_immINode *node = new vsrl16B_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra4S_reg_rule: {
      vsra4S_regNode *node = new vsra4S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra8S_reg_rule: {
      vsra8S_regNode *node = new vsra8S_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra4S_immI_rule: {
      vsra4S_immINode *node = new vsra4S_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra8S_immI_rule: {
      vsra8S_immINode *node = new vsra8S_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra2I_reg_rule: {
      vsra2I_regNode *node = new vsra2I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra4I_reg_rule: {
      vsra4I_regNode *node = new vsra4I_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra2I_immI_rule: {
      vsra2I_immINode *node = new vsra2I_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra4I_immI_rule: {
      vsra4I_immINode *node = new vsra4I_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra2L_reg_rule: {
      vsra2L_regNode *node = new vsra2L_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vsra2L_immI_rule: {
      vsra2L_immINode *node = new vsra2L_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vandD_rule: {
      vandDNode *node = new vandDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vandX_rule: {
      vandXNode *node = new vandXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vorD_rule: {
      vorDNode *node = new vorDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vorX_rule: {
      vorXNode *node = new vorXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vxorD_rule: {
      vxorDNode *node = new vxorDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case vxorX_rule: {
      vxorXNode *node = new vxorXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  
  default:
    fprintf(stderr, "Default MachNode Generator invoked for: \n");
    fprintf(stderr, "   opcode = %d\n", opcode);
    break;
  };
  return NULL;
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
