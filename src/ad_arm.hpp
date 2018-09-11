#line 1 "ad_arm.hpp"
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


#ifndef GENERATED_ADFILES_AD_HPP
#define GENERATED_ADFILES_AD_HPP

#include "memory/allocation.hpp"
#include "code/nativeInst.hpp"
#include "opto/machnode.hpp"
#include "opto/node.hpp"
#include "opto/regalloc.hpp"
#include "opto/subnode.hpp"
#include "opto/vectornode.hpp"

#define  DEFAULT_COST  (100)  
// value == 100 
#define  HUGE_COST  (1000000)  
// value == 1000000 
#define  MEMORY_REF_COST  (DEFAULT_COST * 2)  
// value == 200 
#define  BRANCH_COST  (DEFAULT_COST * 3)  
// value == 300 
#define  CALL_COST  (DEFAULT_COST * 3)  
// value == 300 

enum MachOperands {
  /*    0 */  UNIVERSE,
  /*    1 */  LABEL,
  /*    2 */  SREGI,
  /*    3 */  SREGP,
  /*    4 */  SREGF,
  /*    5 */  SREGD,
  /*    6 */  SREGL,
  /*    7 */  METHOD,
  /*    8 */  IMMIROT,
  /*    9 */  IMMIROTN,
  /*   10 */  IMMIROTNEG,
  /*   11 */  IMMU31ROT,
  /*   12 */  IMMPROT,
  /*   13 */  IMMLLOWROT,
  /*   14 */  IMMLROT2,
  /*   15 */  IMMI12,
  /*   16 */  IMMI10X2,
  /*   17 */  IMMI12X2,
  /*   18 */  IMMI,
  /*   19 */  IMMU8,
  /*   20 */  IMMI16,
  /*   21 */  IMMIHD,
  /*   22 */  IMMIFP,
  /*   23 */  IMMU5,
  /*   24 */  IMMU6BIG,
  /*   25 */  IMMI0,
  /*   26 */  IMMI_1,
  /*   27 */  IMMI_2,
  /*   28 */  IMMI_3,
  /*   29 */  IMMI_4,
  /*   30 */  IMMI_8,
  /*   31 */  IMMU31,
  /*   32 */  IMMI_32_63,
  /*   33 */  IMMI_16,
  /*   34 */  IMMI_24,
  /*   35 */  IMMI_255,
  /*   36 */  IMMI_65535,
  /*   37 */  AIMMI,
  /*   38 */  AIMMINEG,
  /*   39 */  AIMMU31,
  /*   40 */  LIMMI,
  /*   41 */  LIMMILOW8,
  /*   42 */  LIMMU31,
  /*   43 */  LIMMIN,
  /*   44 */  IMML_FF,
  /*   45 */  IMML_FFFF,
  /*   46 */  IMMP,
  /*   47 */  IMMP0,
  /*   48 */  IMMP_POLL,
  /*   49 */  IMMN,
  /*   50 */  IMMNKLASS,
  /*   51 */  IMMN0,
  /*   52 */  IMML,
  /*   53 */  IMML0,
  /*   54 */  IMML16,
  /*   55 */  IMML_32BITS,
  /*   56 */  IMMD,
  /*   57 */  IMMD0,
  /*   58 */  IMM8D,
  /*   59 */  IMMF,
  /*   60 */  IMMF0,
  /*   61 */  IMM8F,
  /*   62 */  IREGI,
  /*   63 */  IREGP,
  /*   64 */  SP_PTR_REGP,
  /*   65 */  R0REGP,
  /*   66 */  R1REGP,
  /*   67 */  R2REGP,
  /*   68 */  REXCEPTIONREGP,
  /*   69 */  RTHREADREGP,
  /*   70 */  IPREGP,
  /*   71 */  LRREGP,
  /*   72 */  R0REGI,
  /*   73 */  R1REGI,
  /*   74 */  R2REGI,
  /*   75 */  R3REGI,
  /*   76 */  R12REGI,
  /*   77 */  IREGL,
  /*   78 */  IREGLD,
  /*   79 */  R0R1REGL,
  /*   80 */  R2R3REGL,
  /*   81 */  FLAGSREG,
  /*   82 */  FLAGSREG_EQNELTGE,
  /*   83 */  FLAGSREGU,
  /*   84 */  FLAGSREGP,
  /*   85 */  FLAGSREGL_LTGE,
  /*   86 */  FLAGSREGL_EQNE,
  /*   87 */  FLAGSREGL_LEGT,
  /*   88 */  FLAGSREGF,
  /*   89 */  VECD,
  /*   90 */  VECX,
  /*   91 */  REGD,
  /*   92 */  REGF,
  /*   93 */  REGD_LOW,
  /*   94 */  INLINE_CACHE_REGP,
  /*   95 */  INTERPRETER_METHOD_OOP_REGP,
  /*   96 */  INDIRECT,
  /*   97 */  INDOFFSET12,
  /*   98 */  INDOFFSETFP,
  /*   99 */  INDOFFSETHD,
  /*  100 */  INDOFFSETFPX2,
  /*  101 */  INDOFFSET12X2,
  /*  102 */  INDINDEX,
  /*  103 */  INDINDEXSCALE,
  /*  104 */  CMPOP,
  /*  105 */  CMPOP0,
  /*  106 */  CMPOPU,
  /*  107 */  CMPOPP,
  /*  108 */  CMPOPL,
  /*  109 */  CMPOPL_COMMUTE,
  /*  110 */  SHIFTEDX,
  // last operand
  /*  111 */  MEMORYI,
  /*  112 */  MEMORYP,
  /*  113 */  MEMORYF,
  /*  114 */  MEMORYF2,
  /*  115 */  MEMORYD,
  /*  116 */  MEMORYFP,
  /*  117 */  MEMORYB,
  /*  118 */  MEMORYS,
  /*  119 */  MEMORYL,
  /*  120 */  MEMORYSCALEDI,
  /*  121 */  MEMORYSCALEDP,
  /*  122 */  MEMORYEX,
  /*  123 */  INDINDEXMEMORY,
  /*  124 */  MEMORYLONG,
  /*  125 */  MEMORYVLD,
  // last operand class
  /*  126 */  _LSHIFTI_IREGI_IMMU5,
  /*  127 */  _LOADB_MEMORYB_,
  /*  128 */  _LOADUB_MEMORYB_,
  /*  129 */  _ANDI__LOADUB_MEMORYB__LIMMILOW8,
  /*  130 */  _LOADS_MEMORYS_,
  /*  131 */  _LSHIFTI__LOADS_MEMORYS__IMMI_24,
  /*  132 */  _LOADUS_MEMORYB_,
  /*  133 */  _LSHIFTI__LOADUS_MEMORYB__IMMI_24,
  /*  134 */  _LOADUS_MEMORYS_,
  /*  135 */  _ANDI__LOADUS_MEMORYB__IMMI_255,
  /*  136 */  _ANDI__LOADUS_MEMORYS__LIMMI,
  /*  137 */  _LOADI_MEMORYS_,
  /*  138 */  _LSHIFTI__LOADI_MEMORYS__IMMI_24,
  /*  139 */  _LOADI_MEMORYB_,
  /*  140 */  _LSHIFTI__LOADI_MEMORYS__IMMI_16,
  /*  141 */  _LOADI_MEMORYI_,
  /*  142 */  _ANDI__LOADI_MEMORYB__IMMI_255,
  /*  143 */  _ANDI__LOADI_MEMORYS__IMMI_65535,
  /*  144 */  _ANDI__LOADI_MEMORYI__LIMMU31,
  /*  145 */  _ANDI__LOADI_MEMORYI__IMMU31,
  /*  146 */  _CONVI2L__LOADI_MEMORYI__,
  /*  147 */  _BINARY_CMPOPP_FLAGSREGP,
  /*  148 */  _BINARY_IREGI_IREGI,
  /*  149 */  _BINARY_IREGI_IMMIROT,
  /*  150 */  _BINARY_IREGI_IMMI16,
  /*  151 */  _BINARY_CMPOP_FLAGSREG,
  /*  152 */  _BINARY_CMPOP0_FLAGSREG_EQNELTGE,
  /*  153 */  _BINARY_CMPOPU_FLAGSREGU,
  /*  154 */  _BINARY_IREGP_IREGP,
  /*  155 */  _BINARY_IREGP_IMMP0,
  /*  156 */  _BINARY_REGF_REGF,
  /*  157 */  _BINARY_REGD_REGD,
  /*  158 */  _BINARY_IREGL_IREGL,
  /*  159 */  _BINARY_IREGL_IMMLLOWROT,
  /*  160 */  _BINARY_IREGL_IMML16,
  /*  161 */  _LSHIFTI_IREGI_IREGI,
  /*  162 */  _RSHIFTI_IREGI_IREGI,
  /*  163 */  _RSHIFTI_IREGI_IMMU5,
  /*  164 */  _URSHIFTI_IREGI_IREGI,
  /*  165 */  _URSHIFTI_IREGI_IMMU5,
  /*  166 */  _BINARY_IREGL_IREGLD,
  /*  167 */  _CASTP2X_IREGP_,
  /*  168 */  _CONVF2D_REGF_,
  /*  169 */  _SQRTD__CONVF2D_REGF__,
  /*  170 */  _CMPLTMASK_IREGI_IREGI,
  /*  171 */  _ANDI__CMPLTMASK_IREGI_IREGI_IREGI,
  /*  172 */  _ANDI_IREGI__CMPLTMASK_IREGI_IREGI,
  /*  173 */  _CMPLTMASK_IREGI_AIMMI,
  /*  174 */  _ANDI__CMPLTMASK_IREGI_AIMMI_IREGI,
  /*  175 */  _ANDI_IREGI__CMPLTMASK_IREGI_AIMMI,
  /*  176 */  _SUBI_IREGI_IREGI,
  /*  177 */  _CONVI2L_IREGI_,
  /*  178 */  _RSHIFTL_IREGL_IMMI_32_63,
  /*  179 */  _ANDI_IREGI_IREGI,
  /*  180 */  _ANDI_IREGI__LSHIFTI_IREGI_IREGI,
  /*  181 */  _ANDI__LSHIFTI_IREGI_IREGI_IREGI,
  /*  182 */  _ANDI_IREGI__LSHIFTI_IREGI_IMMU5,
  /*  183 */  _ANDI__LSHIFTI_IREGI_IMMU5_IREGI,
  /*  184 */  _ANDI_IREGI__RSHIFTI_IREGI_IREGI,
  /*  185 */  _ANDI__RSHIFTI_IREGI_IREGI_IREGI,
  /*  186 */  _ANDI_IREGI__RSHIFTI_IREGI_IMMU5,
  /*  187 */  _ANDI__RSHIFTI_IREGI_IMMU5_IREGI,
  /*  188 */  _ANDI_IREGI__URSHIFTI_IREGI_IREGI,
  /*  189 */  _ANDI__URSHIFTI_IREGI_IREGI_IREGI,
  /*  190 */  _ANDI_IREGI__URSHIFTI_IREGI_IMMU5,
  /*  191 */  _ANDI__URSHIFTI_IREGI_IMMU5_IREGI,
  /*  192 */  _ANDI_IREGI_LIMMI,
  /*  193 */  _BINARY_CMPOPL_FLAGSREGL_LTGE,
  /*  194 */  _BINARY_CMPOPL_FLAGSREGL_EQNE,
  /*  195 */  _BINARY_CMPOPL_COMMUTE_FLAGSREGL_LEGT,
  /*  196 */  _BINARY_IREGL_IMML0,
  // last internally defined operand
  _LAST_MACH_OPER
};

enum MachOpcodes {
  /*    0 */  Universe_rule,
  /*    1 */  label_rule,
  /*    2 */  sRegI_rule,
  /*    3 */  sRegP_rule,
  /*    4 */  sRegF_rule,
  /*    5 */  sRegD_rule,
  /*    6 */  sRegL_rule,
  /*    7 */  method_rule,
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
  /*  197 */  loadConI_rule,
  /*  198 */  loadConIMov_rule,
  /*  199 */  loadConIMovn_rule,
  /*  200 */  loadConI16_rule,
  /*  201 */  loadConP_rule,
  /*  202 */  loadConP_poll_rule,
  /*  203 */  loadConL_rule,
  /*  204 */  loadConL16_rule,
  /*  205 */  loadConF_imm8_rule,
  /*  206 */  loadConF_rule,
  /*  207 */  loadConD_imm8_rule,
  /*  208 */  loadConD_rule,
  /*  209 */  castX2P_rule,
  /*  210 */  castP2X_rule,
  /*  211 */  tlsLoadP_rule,
  /*  212 */  checkCastPP_rule,
  /*  213 */  castPP_rule,
  /*  214 */  castII_rule,
  /*  215 */  storePConditional_rule,
  /*  216 */  storeXConditional_rule,
  /*  217 */  absD_reg_rule,
  /*  218 */  absF_reg_rule,
  /*  219 */  negF_reg_rule,
  /*  220 */  negD_reg_rule,
  /*  221 */  MoveF2I_reg_reg_rule,
  /*  222 */  MoveI2F_reg_reg_rule,
  /*  223 */  MoveD2L_reg_reg_rule,
  /*  224 */  MoveL2D_reg_reg_rule,
  /*  225 */  convI2D_regDHi_regD_rule,
  /*  226 */  regL_to_regD_rule,
  /*  227 */  compI_iReg_rule,
  /*  228 */  compU_iReg_rule,
  /*  229 */  compI_iReg_immneg_rule,
  /*  230 */  compI_iReg_imm_rule,
  /*  231 */  testI_reg_reg_rule,
  /*  232 */  testshlI_reg_reg_reg_rule,
  /*  233 */  testshlI_reg_reg_reg_0_rule,
  /*  234 */  testshlI_reg_reg_imm_rule,
  /*  235 */  testshlI_reg_reg_imm_0_rule,
  /*  236 */  testsarI_reg_reg_reg_rule,
  /*  237 */  testsarI_reg_reg_reg_0_rule,
  /*  238 */  testsarI_reg_reg_imm_rule,
  /*  239 */  testsarI_reg_reg_imm_0_rule,
  /*  240 */  testshrI_reg_reg_reg_rule,
  /*  241 */  testshrI_reg_reg_reg_0_rule,
  /*  242 */  testshrI_reg_reg_imm_rule,
  /*  243 */  testshrI_reg_reg_imm_0_rule,
  /*  244 */  testI_reg_imm_rule,
  /*  245 */  compL_reg_reg_LTGE_rule,
  /*  246 */  compL_reg_reg_EQNE_rule,
  /*  247 */  compL_reg_reg_LEGT_rule,
  /*  248 */  compL_reg_con_LTGE_rule,
  /*  249 */  compL_reg_con_EQNE_rule,
  /*  250 */  compL_reg_con_LEGT_rule,
  /*  251 */  compU_iReg_imm_rule,
  /*  252 */  compP_iRegP_rule,
  /*  253 */  compP_iRegP_imm_rule,
  /*  254 */  cmpF_cc_rule,
  /*  255 */  cmpF0_cc_rule,
  /*  256 */  cmpD_cc_rule,
  /*  257 */  cmpD0_cc_rule,
  /*  258 */  cmpFastLock_rule,
  /*  259 */  cmpFastUnlock_rule,
  /*  260 */  countLeadingZerosI_rule,
  /*  261 */  vneg8B_reg_rule,
  /*  262 */  vneg16B_reg_rule,
  /*  263 */  vslcntD_rule,
  /*  264 */  vslcntX_rule,
  /*  265 */  vsrcntD_rule,
  /*  266 */  vsrcntX_rule,
  /*  267 */  Nop_A0_rule,
  /*  268 */  Nop_A1_rule,
  /*  269 */  Nop_MS_rule,
  /*  270 */  Nop_FA_rule,
  /*  271 */  Nop_BR_rule,
  /*  272 */  loadB_rule,
  /*  273 */  loadB2L_rule,
  /*  274 */  loadUB_rule,
  /*  275 */  loadUB2L_rule,
  /*  276 */  loadUB2L_limmI_rule,
  /*  277 */  loadS_rule,
  /*  278 */  loadS2B_rule,
  /*  279 */  loadS2L_rule,
  /*  280 */  loadUS_rule,
  /*  281 */  loadUS2B_rule,
  /*  282 */  loadUS2L_rule,
  /*  283 */  loadUS2L_immI_255_rule,
  /*  284 */  loadUS2L_limmI_rule,
  /*  285 */  loadI_rule,
  /*  286 */  loadI2B_rule,
  /*  287 */  loadI2UB_rule,
  /*  288 */  loadI2S_rule,
  /*  289 */  loadI2US_rule,
  /*  290 */  loadI2L_rule,
  /*  291 */  loadI2L_immI_255_rule,
  /*  292 */  loadI2L_immI_65535_rule,
  /*  293 */  loadI2L_limmU31_rule,
  /*  294 */  loadI2L_immU31_rule,
  /*  295 */  loadUI2L_rule,
  /*  296 */  loadL_rule,
  /*  297 */  loadL_2instr_rule,
  /*  298 */  loadL_volatile_rule,
  /*  299 */  loadL_volatile_fp_rule,
  /*  300 */  loadL_unaligned_rule,
  /*  301 */  loadRange_rule,
  /*  302 */  loadP_rule,
  /*  303 */  loadKlass_rule,
  /*  304 */  loadD_rule,
  /*  305 */  loadD_unaligned_rule,
  /*  306 */  loadF_rule,
  /*  307 */  prefetchAlloc_mp_rule,
  /*  308 */  prefetchAlloc_sp_rule,
  /*  309 */  storeB_rule,
  /*  310 */  storeCM_rule,
  /*  311 */  storeC_rule,
  /*  312 */  storeI_rule,
  /*  313 */  storeL_rule,
  /*  314 */  storeL_2instr_rule,
  /*  315 */  storeL_volatile_rule,
  /*  316 */  storeL_volatile_fp_rule,
  /*  317 */  storeP_rule,
  /*  318 */  storeD_rule,
  /*  319 */  storeF_rule,
  /*  320 */  membar_storestore_rule,
  /*  321 */  membar_acquire_rule,
  /*  322 */  membar_acquire_0_rule,
  /*  323 */  membar_acquire_lock_rule,
  /*  324 */  membar_release_rule,
  /*  325 */  membar_release_0_rule,
  /*  326 */  membar_release_lock_rule,
  /*  327 */  membar_volatile_rule,
  /*  328 */  unnecessary_membar_volatile_rule,
  /*  329 */  cmovIP_reg_rule,
  /*  330 */  cmovIP_immMov_rule,
  /*  331 */  cmovIP_imm16_rule,
  /*  332 */  cmovI_reg_rule,
  /*  333 */  cmovI_immMov_rule,
  /*  334 */  cmovII_imm16_rule,
  /*  335 */  cmovII_reg_EQNELTGE_rule,
  /*  336 */  cmovII_immMov_EQNELTGE_rule,
  /*  337 */  cmovII_imm16_EQNELTGE_rule,
  /*  338 */  cmovIIu_reg_rule,
  /*  339 */  cmovIIu_immMov_rule,
  /*  340 */  cmovIIu_imm16_rule,
  /*  341 */  cmovPP_reg_rule,
  /*  342 */  cmovPP_imm_rule,
  /*  343 */  cmovPI_reg_rule,
  /*  344 */  cmovPI_reg_EQNELTGE_rule,
  /*  345 */  cmovPIu_reg_rule,
  /*  346 */  cmovPI_imm_rule,
  /*  347 */  cmovPI_imm_EQNELTGE_rule,
  /*  348 */  cmovPIu_imm_rule,
  /*  349 */  cmovFP_reg_rule,
  /*  350 */  cmovFI_reg_rule,
  /*  351 */  cmovFI_reg_EQNELTGE_rule,
  /*  352 */  cmovFIu_reg_rule,
  /*  353 */  cmovDP_reg_rule,
  /*  354 */  cmovDI_reg_rule,
  /*  355 */  cmovDI_reg_EQNELTGE_rule,
  /*  356 */  cmovDIu_reg_rule,
  /*  357 */  cmovLP_reg_rule,
  /*  358 */  cmovLP_immRot_rule,
  /*  359 */  cmovLP_imm16_rule,
  /*  360 */  cmovLI_reg_rule,
  /*  361 */  cmovLI_reg_EQNELTGE_rule,
  /*  362 */  cmovLI_immRot_rule,
  /*  363 */  cmovLI_immRot_EQNELTGE_rule,
  /*  364 */  cmovLI_imm16_rule,
  /*  365 */  cmovLI_imm16_EQNELTGE_rule,
  /*  366 */  cmovLIu_reg_rule,
  /*  367 */  addI_reg_reg_rule,
  /*  368 */  addshlI_reg_reg_reg_rule,
  /*  369 */  addshlI_reg_reg_reg_0_rule,
  /*  370 */  addshlI_reg_imm_reg_rule,
  /*  371 */  addshlI_reg_imm_reg_0_rule,
  /*  372 */  addsarI_reg_reg_reg_rule,
  /*  373 */  addsarI_reg_reg_reg_0_rule,
  /*  374 */  addsarI_reg_imm_reg_rule,
  /*  375 */  addsarI_reg_imm_reg_0_rule,
  /*  376 */  addshrI_reg_reg_reg_rule,
  /*  377 */  addshrI_reg_reg_reg_0_rule,
  /*  378 */  addshrI_reg_imm_reg_rule,
  /*  379 */  addshrI_reg_imm_reg_0_rule,
  /*  380 */  addI_reg_aimmI_rule,
  /*  381 */  addP_reg_reg_rule,
  /*  382 */  addshlP_reg_reg_imm_rule,
  /*  383 */  addP_reg_aimmX_rule,
  /*  384 */  addL_reg_reg_rule,
  /*  385 */  addL_reg_immRot_rule,
  /*  386 */  loadPLocked_rule,
  /*  387 */  compareAndSwapL_bool_rule,
  /*  388 */  compareAndSwapI_bool_rule,
  /*  389 */  compareAndSwapP_bool_rule,
  /*  390 */  xaddI_aimmI_no_res_rule,
  /*  391 */  xaddI_reg_no_res_rule,
  /*  392 */  xaddI_aimmI_rule,
  /*  393 */  xaddI_reg_rule,
  /*  394 */  xaddL_reg_no_res_rule,
  /*  395 */  xaddL_immRot_no_res_rule,
  /*  396 */  xaddL_reg_rule,
  /*  397 */  xaddL_immRot_rule,
  /*  398 */  xchgI_rule,
  /*  399 */  xchgL_rule,
  /*  400 */  xchgP_rule,
  /*  401 */  subI_reg_reg_rule,
  /*  402 */  subshlI_reg_reg_reg_rule,
  /*  403 */  subshlI_reg_reg_imm_rule,
  /*  404 */  subsarI_reg_reg_reg_rule,
  /*  405 */  subsarI_reg_reg_imm_rule,
  /*  406 */  subshrI_reg_reg_reg_rule,
  /*  407 */  subshrI_reg_reg_imm_rule,
  /*  408 */  rsbshlI_reg_reg_reg_rule,
  /*  409 */  rsbshlI_reg_imm_reg_rule,
  /*  410 */  rsbsarI_reg_reg_reg_rule,
  /*  411 */  rsbsarI_reg_imm_reg_rule,
  /*  412 */  rsbshrI_reg_reg_reg_rule,
  /*  413 */  rsbshrI_reg_imm_reg_rule,
  /*  414 */  subI_reg_aimmI_rule,
  /*  415 */  subI_reg_immRotneg_rule,
  /*  416 */  subI_immRot_reg_rule,
  /*  417 */  subL_reg_reg_rule,
  /*  418 */  subL_reg_immRot_rule,
  /*  419 */  negL_reg_reg_rule,
  /*  420 */  mulI_reg_reg_rule,
  /*  421 */  mulL_lo1_hi2_rule,
  /*  422 */  mulL_hi1_lo2_rule,
  /*  423 */  mulL_lo1_lo2_rule,
  /*  424 */  mulL_reg_reg_rule,
  /*  425 */  divI_reg_reg_rule,
  /*  426 */  divL_reg_reg_rule,
  /*  427 */  modI_reg_reg_rule,
  /*  428 */  modL_reg_reg_rule,
  /*  429 */  shlI_reg_reg_rule,
  /*  430 */  shlI_reg_imm5_rule,
  /*  431 */  shlL_reg_reg_merge_hi_rule,
  /*  432 */  shlL_reg_reg_merge_lo_rule,
  /*  433 */  shlL_reg_reg_overlap_rule,
  /*  434 */  shlL_reg_reg_rule,
  /*  435 */  shlL_reg_imm6_rule,
  /*  436 */  shlL_reg_imm5_rule,
  /*  437 */  sarI_reg_reg_rule,
  /*  438 */  sarI_reg_imm5_rule,
  /*  439 */  sarL_reg_reg_merge_lo_rule,
  /*  440 */  sarL_reg_reg_merge_hi_rule,
  /*  441 */  sarL_reg_reg_overlap_rule,
  /*  442 */  sarL_reg_reg_rule,
  /*  443 */  sarL_reg_imm6_rule,
  /*  444 */  sarL_reg_imm5_rule,
  /*  445 */  shrI_reg_reg_rule,
  /*  446 */  shrI_reg_imm5_rule,
  /*  447 */  shrL_reg_reg_merge_lo_rule,
  /*  448 */  shrL_reg_reg_merge_hi_rule,
  /*  449 */  shrL_reg_reg_overlap_rule,
  /*  450 */  shrL_reg_reg_rule,
  /*  451 */  shrL_reg_imm6_rule,
  /*  452 */  shrL_reg_imm5_rule,
  /*  453 */  shrP_reg_imm5_rule,
  /*  454 */  addF_reg_reg_rule,
  /*  455 */  addD_reg_reg_rule,
  /*  456 */  subF_reg_reg_rule,
  /*  457 */  subD_reg_reg_rule,
  /*  458 */  mulF_reg_reg_rule,
  /*  459 */  mulD_reg_reg_rule,
  /*  460 */  divF_reg_reg_rule,
  /*  461 */  divD_reg_reg_rule,
  /*  462 */  sqrtF_reg_reg_rule,
  /*  463 */  sqrtD_reg_reg_rule,
  /*  464 */  andI_reg_reg_rule,
  /*  465 */  andshlI_reg_reg_reg_rule,
  /*  466 */  andshlI_reg_reg_reg_0_rule,
  /*  467 */  andshlI_reg_reg_imm_rule,
  /*  468 */  andshlI_reg_reg_imm_0_rule,
  /*  469 */  andsarI_reg_reg_reg_rule,
  /*  470 */  andsarI_reg_reg_reg_0_rule,
  /*  471 */  andsarI_reg_reg_imm_rule,
  /*  472 */  andsarI_reg_reg_imm_0_rule,
  /*  473 */  andshrI_reg_reg_reg_rule,
  /*  474 */  andshrI_reg_reg_reg_0_rule,
  /*  475 */  andshrI_reg_reg_imm_rule,
  /*  476 */  andshrI_reg_reg_imm_0_rule,
  /*  477 */  andI_reg_limm_rule,
  /*  478 */  andI_reg_limmn_rule,
  /*  479 */  andL_reg_reg_rule,
  /*  480 */  andL_reg_immRot_rule,
  /*  481 */  orI_reg_reg_rule,
  /*  482 */  orshlI_reg_reg_reg_rule,
  /*  483 */  orshlI_reg_reg_reg_0_rule,
  /*  484 */  orshlI_reg_reg_imm_rule,
  /*  485 */  orshlI_reg_reg_imm_0_rule,
  /*  486 */  orsarI_reg_reg_reg_rule,
  /*  487 */  orsarI_reg_reg_reg_0_rule,
  /*  488 */  orsarI_reg_reg_imm_rule,
  /*  489 */  orsarI_reg_reg_imm_0_rule,
  /*  490 */  orshrI_reg_reg_reg_rule,
  /*  491 */  orshrI_reg_reg_reg_0_rule,
  /*  492 */  orshrI_reg_reg_imm_rule,
  /*  493 */  orshrI_reg_reg_imm_0_rule,
  /*  494 */  orI_reg_limm_rule,
  /*  495 */  orL_reg_reg_rule,
  /*  496 */  orL_reg_immRot_rule,
  /*  497 */  xorI_reg_reg_rule,
  /*  498 */  xorshlI_reg_reg_reg_rule,
  /*  499 */  xorshlI_reg_reg_reg_0_rule,
  /*  500 */  xorshlI_reg_reg_imm_rule,
  /*  501 */  xorshlI_reg_reg_imm_0_rule,
  /*  502 */  xorsarI_reg_reg_reg_rule,
  /*  503 */  xorsarI_reg_reg_reg_0_rule,
  /*  504 */  xorsarI_reg_reg_imm_rule,
  /*  505 */  xorsarI_reg_reg_imm_0_rule,
  /*  506 */  xorshrI_reg_reg_reg_rule,
  /*  507 */  xorshrI_reg_reg_reg_0_rule,
  /*  508 */  xorshrI_reg_reg_imm_rule,
  /*  509 */  xorshrI_reg_reg_imm_0_rule,
  /*  510 */  xorI_reg_imm_rule,
  /*  511 */  xorL_reg_reg_rule,
  /*  512 */  xorL_reg_immRot_rule,
  /*  513 */  convI2B_rule,
  /*  514 */  convP2B_rule,
  /*  515 */  cmpLTMask_reg_reg_rule,
  /*  516 */  cmpLTMask_reg_imm_rule,
  /*  517 */  cadd_cmpLTMask3_rule,
  /*  518 */  cadd_cmpLTMask3_1_rule,
  /*  519 */  cadd_cmpLTMask3_0_rule,
  /*  520 */  cadd_cmpLTMask3_2_rule,
  /*  521 */  cadd_cmpLTMask4_rule,
  /*  522 */  cadd_cmpLTMask4_1_rule,
  /*  523 */  cadd_cmpLTMask4_0_rule,
  /*  524 */  cadd_cmpLTMask4_2_rule,
  /*  525 */  cadd_cmpLTMask_rule,
  /*  526 */  cadd_cmpLTMask_1_rule,
  /*  527 */  cadd_cmpLTMask_0_rule,
  /*  528 */  cadd_cmpLTMask_2_rule,
  /*  529 */  convD2F_reg_rule,
  /*  530 */  convD2I_reg_reg_rule,
  /*  531 */  convD2L_reg_rule,
  /*  532 */  convF2D_reg_rule,
  /*  533 */  convF2I_reg_reg_rule,
  /*  534 */  convF2L_reg_rule,
  /*  535 */  convI2D_reg_reg_rule,
  /*  536 */  convI2F_reg_reg_rule,
  /*  537 */  convI2L_reg_rule,
  /*  538 */  convI2L_reg_zex_rule,
  /*  539 */  zerox_long_rule,
  /*  540 */  loadConI_x43300000_rule,
  /*  541 */  loadConI_x41f00000_rule,
  /*  542 */  loadConI_x0_rule,
  /*  543 */  regDHi_regDLo_to_regD_rule,
  /*  544 */  addD_regD_regD_rule,
  /*  545 */  subD_regD_regD_rule,
  /*  546 */  mulD_regD_regD_rule,
  /*  547 */  regI_regI_to_regD_rule,
  /*  548 */  convL2D_reg_slow_fxtof_rule,
  /*  549 */  convL2I_reg_rule,
  /*  550 */  shrL_reg_imm6_L2I_rule,
  /*  551 */  cmovI_reg_lt_rule,
  /*  552 */  minI_eReg_rule,
  /*  553 */  cmovI_reg_gt_rule,
  /*  554 */  maxI_eReg_rule,
  /*  555 */  cmpF_reg_rule,
  /*  556 */  cmpF0_reg_rule,
  /*  557 */  cmpD_reg_rule,
  /*  558 */  cmpD0_reg_rule,
  /*  559 */  jumpXtnd_rule,
  /*  560 */  branch_rule,
  /*  561 */  branchCon_rule,
  /*  562 */  branchCon_EQNELTGE_rule,
  /*  563 */  branchConU_rule,
  /*  564 */  branchConP_rule,
  /*  565 */  branchConL_LTGE_rule,
  /*  566 */  branchConL_EQNE_rule,
  /*  567 */  branchConL_LEGT_rule,
  /*  568 */  branchLoopEnd_rule,
  /*  569 */  cmpL3_reg_reg_rule,
  /*  570 */  cmovLL_reg_LTGE_rule,
  /*  571 */  cmovLL_reg_EQNE_rule,
  /*  572 */  cmovLL_reg_LEGT_rule,
  /*  573 */  cmovLL_imm_LTGE_rule,
  /*  574 */  cmovLL_imm_EQNE_rule,
  /*  575 */  cmovLL_imm_LEGT_rule,
  /*  576 */  cmovIL_reg_LTGE_rule,
  /*  577 */  cmovIL_reg_EQNE_rule,
  /*  578 */  cmovIL_reg_LEGT_rule,
  /*  579 */  cmovIL_imm_LTGE_rule,
  /*  580 */  cmovIL_imm_EQNE_rule,
  /*  581 */  cmovIL_imm_LEGT_rule,
  /*  582 */  cmovPL_reg_LTGE_rule,
  /*  583 */  cmovPL_reg_EQNE_rule,
  /*  584 */  cmovPL_reg_LEGT_rule,
  /*  585 */  cmovPL_imm_LTGE_rule,
  /*  586 */  cmovPL_imm_EQNE_rule,
  /*  587 */  cmovPL_imm_LEGT_rule,
  /*  588 */  cmovFL_reg_LTGE_rule,
  /*  589 */  cmovFL_reg_EQNE_rule,
  /*  590 */  cmovFL_reg_LEGT_rule,
  /*  591 */  cmovDL_reg_LTGE_rule,
  /*  592 */  cmovDL_reg_EQNE_rule,
  /*  593 */  cmovDL_reg_LEGT_rule,
  /*  594 */  safePoint_poll_rule,
  /*  595 */  CallStaticJavaDirect_rule,
  /*  596 */  CallStaticJavaHandle_rule,
  /*  597 */  CallDynamicJavaDirect_rule,
  /*  598 */  CallRuntimeDirect_rule,
  /*  599 */  CallLeafDirect_rule,
  /*  600 */  CallLeafNoFPDirect_rule,
  /*  601 */  TailCalljmpInd_rule,
  /*  602 */  Ret_rule,
  /*  603 */  tailjmpInd_rule,
  /*  604 */  CreateException_rule,
  /*  605 */  RethrowException_rule,
  /*  606 */  ShouldNotReachHere_rule,
  /*  607 */  partialSubtypeCheck_rule,
  /*  608 */  clear_array_rule,
  /*  609 */  countLeadingZerosL_rule,
  /*  610 */  countTrailingZerosI_rule,
  /*  611 */  countTrailingZerosL_rule,
  /*  612 */  popCountI_rule,
  /*  613 */  popCountL_rule,
  /*  614 */  bytes_reverse_int_rule,
  /*  615 */  bytes_reverse_long_rule,
  /*  616 */  bytes_reverse_unsigned_short_rule,
  /*  617 */  bytes_reverse_short_rule,
  /*  618 */  loadV8_rule,
  /*  619 */  loadV16_rule,
  /*  620 */  storeV8_rule,
  /*  621 */  storeV16_rule,
  /*  622 */  Repl8B_reg_rule,
  /*  623 */  Repl8B_reg_simd_rule,
  /*  624 */  Repl16B_reg_rule,
  /*  625 */  Repl8B_immI_rule,
  /*  626 */  Repl8B_immU8_rule,
  /*  627 */  Repl16B_immU8_rule,
  /*  628 */  Repl4S_reg_rule,
  /*  629 */  Repl4S_reg_simd_rule,
  /*  630 */  Repl8S_reg_rule,
  /*  631 */  Repl4S_immI_rule,
  /*  632 */  Repl4S_immU8_rule,
  /*  633 */  Repl8S_immU8_rule,
  /*  634 */  Repl2I_reg_rule,
  /*  635 */  Repl4I_reg_rule,
  /*  636 */  Repl2I_reg_simd_rule,
  /*  637 */  Repl4I_reg_simd_rule,
  /*  638 */  Repl2I_immI_rule,
  /*  639 */  Repl2I_immU8_rule,
  /*  640 */  Repl4I_immU8_rule,
  /*  641 */  Repl2L_reg_rule,
  /*  642 */  Repl2F_regI_rule,
  /*  643 */  Repl2F_reg_vfp_rule,
  /*  644 */  Repl2F_reg_simd_rule,
  /*  645 */  Repl4F_reg_rule,
  /*  646 */  Repl4F_reg_simd_rule,
  /*  647 */  Repl2F_immI_rule,
  /*  648 */  Repl2D_reg_rule,
  /*  649 */  vadd8B_reg_rule,
  /*  650 */  vadd16B_reg_rule,
  /*  651 */  vadd4S_reg_rule,
  /*  652 */  vadd8S_reg_rule,
  /*  653 */  vadd2I_reg_rule,
  /*  654 */  vadd4I_reg_rule,
  /*  655 */  vadd2L_reg_rule,
  /*  656 */  vadd2F_reg_rule,
  /*  657 */  vadd2F_reg_vfp_rule,
  /*  658 */  vadd4F_reg_simd_rule,
  /*  659 */  vadd4F_reg_vfp_rule,
  /*  660 */  vadd2D_reg_vfp_rule,
  /*  661 */  vsub8B_reg_rule,
  /*  662 */  vsub16B_reg_rule,
  /*  663 */  vsub4S_reg_rule,
  /*  664 */  vsub16S_reg_rule,
  /*  665 */  vsub2I_reg_rule,
  /*  666 */  vsub4I_reg_rule,
  /*  667 */  vsub2L_reg_rule,
  /*  668 */  vsub2F_reg_rule,
  /*  669 */  vsub2F_reg_vfp_rule,
  /*  670 */  vsub4F_reg_rule,
  /*  671 */  vsub4F_reg_vfp_rule,
  /*  672 */  vsub2D_reg_vfp_rule,
  /*  673 */  vmul4S_reg_rule,
  /*  674 */  vmul8S_reg_rule,
  /*  675 */  vmul2I_reg_rule,
  /*  676 */  vmul4I_reg_rule,
  /*  677 */  vmul2F_reg_rule,
  /*  678 */  vmul2F_reg_vfp_rule,
  /*  679 */  vmul4F_reg_rule,
  /*  680 */  vmul4F_reg_vfp_rule,
  /*  681 */  vmul2D_reg_vfp_rule,
  /*  682 */  vdiv2F_reg_vfp_rule,
  /*  683 */  vdiv4F_reg_vfp_rule,
  /*  684 */  vdiv2D_reg_vfp_rule,
  /*  685 */  vsh8B_reg_rule,
  /*  686 */  vsh16B_reg_rule,
  /*  687 */  vsh4S_reg_rule,
  /*  688 */  vsh8S_reg_rule,
  /*  689 */  vsh2I_reg_rule,
  /*  690 */  vsh4I_reg_rule,
  /*  691 */  vsh2L_reg_rule,
  /*  692 */  vsl8B_reg_rule,
  /*  693 */  vsl16B_reg_rule,
  /*  694 */  vsl8B_immI_rule,
  /*  695 */  vsl16B_immI_rule,
  /*  696 */  vsl4S_reg_rule,
  /*  697 */  vsl4S_reg_0_rule,
  /*  698 */  vsl8S_reg_rule,
  /*  699 */  vsl8S_reg_0_rule,
  /*  700 */  vsl4S_immI_rule,
  /*  701 */  vsl8S_immI_rule,
  /*  702 */  vsl2I_reg_rule,
  /*  703 */  vsl2I_reg_0_rule,
  /*  704 */  vsl4I_reg_rule,
  /*  705 */  vsl4I_reg_0_rule,
  /*  706 */  vsl2I_immI_rule,
  /*  707 */  vsl4I_immI_rule,
  /*  708 */  vsl2L_reg_rule,
  /*  709 */  vsl2L_reg_0_rule,
  /*  710 */  vsl2L_immI_rule,
  /*  711 */  vsrl4S_immI_rule,
  /*  712 */  vsrl8S_immI_rule,
  /*  713 */  vsrl2I_immI_rule,
  /*  714 */  vsrl4I_immI_rule,
  /*  715 */  vsrl2L_immI_rule,
  /*  716 */  vsha8B_reg_rule,
  /*  717 */  vsha16B_reg_rule,
  /*  718 */  vsha4S_reg_rule,
  /*  719 */  vsha8S_reg_rule,
  /*  720 */  vsha2I_reg_rule,
  /*  721 */  vsha4I_reg_rule,
  /*  722 */  vsha2L_reg_rule,
  /*  723 */  vsra8B_reg_rule,
  /*  724 */  vsrl16B_reg_rule,
  /*  725 */  vsrl8B_immI_rule,
  /*  726 */  vsrl16B_immI_rule,
  /*  727 */  vsra4S_reg_rule,
  /*  728 */  vsra8S_reg_rule,
  /*  729 */  vsra4S_immI_rule,
  /*  730 */  vsra8S_immI_rule,
  /*  731 */  vsra2I_reg_rule,
  /*  732 */  vsra4I_reg_rule,
  /*  733 */  vsra2I_immI_rule,
  /*  734 */  vsra4I_immI_rule,
  /*  735 */  vsra2L_reg_rule,
  /*  736 */  vsra2L_immI_rule,
  /*  737 */  vandD_rule,
  /*  738 */  vandX_rule,
  /*  739 */  vorD_rule,
  /*  740 */  vorX_rule,
  /*  741 */  vxorD_rule,
  /*  742 */  vxorX_rule,
  // last instruction
  _BEGIN_INST_CHAIN_RULE = 197,
  _END_INST_CHAIN_RULE  = 209,
  _BEGIN_REMATERIALIZE   = 197,
  _END_REMATERIALIZE    = 267,
  _last_Mach_Node  = 743 
};

// Enumerate machine registers starting after reserved regs.
// in the order of occurrence in the alloc_class(es).
enum MachRegisterEncodes {
  R_R4_enc   =   4,
  R_R5_enc   =   5,
  R_R6_enc   =   6,
  R_R7_enc   =   7,
  R_R8_enc   =   8,
  R_R9_enc   =   9,
  R_R11_enc  =  11,
  R_R12_enc  =  12,
  R_R10_enc  =  10,
  R_R13_enc  =  13,
  R_R14_enc  =  14,
  R_R15_enc  =  15,
  R_R0_enc   =   0,
  R_R1_enc   =   1,
  R_R2_enc   =   2,
  R_R3_enc   =   3,
  R_S16_enc  =  16,
  R_S17_enc  =  17,
  R_S18_enc  =  18,
  R_S19_enc  =  19,
  R_S20_enc  =  20,
  R_S21_enc  =  21,
  R_S22_enc  =  22,
  R_S23_enc  =  23,
  R_S24_enc  =  24,
  R_S25_enc  =  25,
  R_S26_enc  =  26,
  R_S27_enc  =  27,
  R_S28_enc  =  28,
  R_S29_enc  =  29,
  R_S30_enc  =  30,
  R_S31_enc  =  31,
  R_S0_enc   =   0,
  R_S1_enc   =   1,
  R_S2_enc   =   2,
  R_S3_enc   =   3,
  R_S4_enc   =   4,
  R_S5_enc   =   5,
  R_S6_enc   =   6,
  R_S7_enc   =   7,
  R_S8_enc   =   8,
  R_S9_enc   =   9,
  R_S10_enc  =  10,
  R_S11_enc  =  11,
  R_S12_enc  =  12,
  R_S13_enc  =  13,
  R_S14_enc  =  14,
  R_S15_enc  =  15,
  R_D16_enc  =  32,
  R_D16x_enc = 255,
  R_D17_enc  =  34,
  R_D17x_enc = 255,
  R_D18_enc  =  36,
  R_D18x_enc = 255,
  R_D19_enc  =  38,
  R_D19x_enc = 255,
  R_D20_enc  =  40,
  R_D20x_enc = 255,
  R_D21_enc  =  42,
  R_D21x_enc = 255,
  R_D22_enc  =  44,
  R_D22x_enc = 255,
  R_D23_enc  =  46,
  R_D23x_enc = 255,
  R_D24_enc  =  48,
  R_D24x_enc = 255,
  R_D25_enc  =  50,
  R_D25x_enc = 255,
  R_D26_enc  =  52,
  R_D26x_enc = 255,
  R_D27_enc  =  54,
  R_D27x_enc = 255,
  R_D28_enc  =  56,
  R_D28x_enc = 255,
  R_D29_enc  =  58,
  R_D29x_enc = 255,
  R_D30_enc  =  60,
  R_D30x_enc = 255,
  R_D31_enc  =  62,
  R_D31x_enc = 255,
  APSR_enc   =   0,
  FPSCR_enc  =   0
};

// Pipeline Stages
enum machPipelineStages {
   stage_undefined = 0,
   stage_A         = 1,
   stage_P         = 2,
   stage_F         = 3,
   stage_B         = 4,
   stage_I         = 5,
   stage_J         = 6,
   stage_S         = 7,
   stage_R         = 8,
   stage_E         = 9,
   stage_C         = 10,
   stage_M         = 11,
   stage_W         = 12,
   stage_X         = 13,
   stage_T         = 14,
   stage_D         = 15,
   stage_count     = 15
};

// Pipeline Resources
enum machPipelineResources {
   resource_A0   = 0,
   resource_A1   = 1,
   resource_MS   = 2,
   resource_BR   = 3,
   resource_FA   = 4,
   resource_FM   = 5,
   resource_IDIV = 6,
   resource_FDIV = 7,

   res_mask_A0   = 0x00000001,
   res_mask_A1   = 0x00000002,
   res_mask_MS   = 0x00000004,
   res_mask_BR   = 0x00000008,
   res_mask_FA   = 0x00000010,
   res_mask_FM   = 0x00000020,
   res_mask_IDIV = 0x00000040,
   res_mask_FDIV = 0x00000080,
   res_mask_IALU = 0x00000003,

   resource_count = 8
};

// MACROS to inline and constant fold State::valid(index)...
// when given a constant 'index' in dfa_<arch>.cpp
//   uint word   = index >> 5;       // Shift out bit position
//   uint bitpos = index & 0x0001F;  // Mask off word bits
#define STATE__VALID(index)     (_valid[((uint)index) >> 5] &  (0x1 << (((uint)index) & 0x0001F)))

#define STATE__NOT_YET_VALID(index)   ( (_valid[((uint)index) >> 5] &  (0x1 << (((uint)index) & 0x0001F))) == 0 )

#define STATE__VALID_CHILD(state,index)   ( state && (state->_valid[((uint)index) >> 5] &  (0x1 << (((uint)index) & 0x0001F))) )

#define STATE__SET_VALID(index)   (_valid[((uint)index) >> 5] |= (0x1 << (((uint)index) & 0x0001F)))

//---------------------------State-------------------------------------------
// State contains an integral cost vector, indexed by machine operand opcodes,
// a rule vector consisting of machine operand/instruction opcodes, and also
// indexed by machine operand opcodes, pointers to the children in the label
// tree generated by the Label routines in ideal nodes (currently limited to
// two for convenience, but this could change).
class State : public ResourceObj {
public:
  int    _id;         // State identifier
  Node  *_leaf;       // Ideal (non-machine-node) leaf of match tree
  State *_kids[2];       // Children of state node in label tree
  unsigned int _cost[_LAST_MACH_OPER];  // Cost vector, indexed by operand opcodes
  unsigned int _rule[_LAST_MACH_OPER];  // Rule vector, indexed by operand opcodes
  unsigned int _valid[(_LAST_MACH_OPER/32)+1]; // Bit Map of valid Cost/Rule entries

  State(void);                      // Constructor
  DEBUG_ONLY( ~State(void); )       // Destructor

  // Methods created by ADLC and invoked by Reduce
  MachOper *MachOperGenerator(int opcode);
  MachNode *MachNodeGenerator(int opcode);

  // Assign a state to a node, definition of method produced by ADLC
  bool DFA( int opcode, const Node *ideal );

  // Access function for _valid bit vector
  bool valid(uint index) {
    return( STATE__VALID(index) != 0 );
  }

  // Set function for _valid bit vector
  void set_valid(uint index) {
    STATE__SET_VALID(index);
  }

#ifndef PRODUCT
  void dump();                // Debugging prints
  void dump(int depth);
#endif
  void  _sub_Op_RegI(const Node *n);
  void  _sub_Op_RegP(const Node *n);
  void  _sub_Op_RegF(const Node *n);
  void  _sub_Op_RegD(const Node *n);
  void  _sub_Op_RegL(const Node *n);
  void  _sub_Op_RegFlags(const Node *n);
  void  _sub_Op_VecD(const Node *n);
  void  _sub_Op_VecX(const Node *n);
  void  _sub_Op_AbsD(const Node *n);
  void  _sub_Op_AbsF(const Node *n);
  void  _sub_Op_AddD(const Node *n);
  void  _sub_Op_AddF(const Node *n);
  void  _sub_Op_AddI(const Node *n);
  void  _sub_Op_AddL(const Node *n);
  void  _sub_Op_AddP(const Node *n);
  void  _sub_Op_AndI(const Node *n);
  void  _sub_Op_AndL(const Node *n);
  void  _sub_Op_Binary(const Node *n);
  void  _sub_Op_Bool(const Node *n);
  void  _sub_Op_ReverseBytesI(const Node *n);
  void  _sub_Op_ReverseBytesL(const Node *n);
  void  _sub_Op_ReverseBytesUS(const Node *n);
  void  _sub_Op_ReverseBytesS(const Node *n);
  void  _sub_Op_CallDynamicJava(const Node *n);
  void  _sub_Op_CallLeaf(const Node *n);
  void  _sub_Op_CallLeafNoFP(const Node *n);
  void  _sub_Op_CallRuntime(const Node *n);
  void  _sub_Op_CallStaticJava(const Node *n);
  void  _sub_Op_CastII(const Node *n);
  void  _sub_Op_CastX2P(const Node *n);
  void  _sub_Op_CastP2X(const Node *n);
  void  _sub_Op_CastPP(const Node *n);
  void  _sub_Op_CheckCastPP(const Node *n);
  void  _sub_Op_ClearArray(const Node *n);
  void  _sub_Op_CMoveD(const Node *n);
  void  _sub_Op_CMoveF(const Node *n);
  void  _sub_Op_CMoveI(const Node *n);
  void  _sub_Op_CMoveL(const Node *n);
  void  _sub_Op_CMoveP(const Node *n);
  void  _sub_Op_CmpD(const Node *n);
  void  _sub_Op_CmpD3(const Node *n);
  void  _sub_Op_CmpF(const Node *n);
  void  _sub_Op_CmpF3(const Node *n);
  void  _sub_Op_CmpI(const Node *n);
  void  _sub_Op_CmpL(const Node *n);
  void  _sub_Op_CmpL3(const Node *n);
  void  _sub_Op_CmpLTMask(const Node *n);
  void  _sub_Op_CmpP(const Node *n);
  void  _sub_Op_CmpU(const Node *n);
  void  _sub_Op_CompareAndSwapI(const Node *n);
  void  _sub_Op_CompareAndSwapL(const Node *n);
  void  _sub_Op_CompareAndSwapP(const Node *n);
  void  _sub_Op_GetAndAddI(const Node *n);
  void  _sub_Op_GetAndAddL(const Node *n);
  void  _sub_Op_GetAndSetI(const Node *n);
  void  _sub_Op_GetAndSetL(const Node *n);
  void  _sub_Op_GetAndSetP(const Node *n);
  void  _sub_Op_ConN(const Node *n);
  void  _sub_Op_ConNKlass(const Node *n);
  void  _sub_Op_ConD(const Node *n);
  void  _sub_Op_ConF(const Node *n);
  void  _sub_Op_ConI(const Node *n);
  void  _sub_Op_ConL(const Node *n);
  void  _sub_Op_ConP(const Node *n);
  void  _sub_Op_Conv2B(const Node *n);
  void  _sub_Op_ConvD2F(const Node *n);
  void  _sub_Op_ConvD2I(const Node *n);
  void  _sub_Op_ConvD2L(const Node *n);
  void  _sub_Op_ConvF2D(const Node *n);
  void  _sub_Op_ConvF2I(const Node *n);
  void  _sub_Op_ConvF2L(const Node *n);
  void  _sub_Op_ConvI2D(const Node *n);
  void  _sub_Op_ConvI2F(const Node *n);
  void  _sub_Op_ConvI2L(const Node *n);
  void  _sub_Op_ConvL2D(const Node *n);
  void  _sub_Op_ConvL2I(const Node *n);
  void  _sub_Op_CountedLoopEnd(const Node *n);
  void  _sub_Op_CountLeadingZerosI(const Node *n);
  void  _sub_Op_CountLeadingZerosL(const Node *n);
  void  _sub_Op_CountTrailingZerosI(const Node *n);
  void  _sub_Op_CountTrailingZerosL(const Node *n);
  void  _sub_Op_CreateEx(const Node *n);
  void  _sub_Op_DivD(const Node *n);
  void  _sub_Op_DivF(const Node *n);
  void  _sub_Op_DivI(const Node *n);
  void  _sub_Op_DivL(const Node *n);
  void  _sub_Op_FastLock(const Node *n);
  void  _sub_Op_FastUnlock(const Node *n);
  void  _sub_Op_Goto(const Node *n);
  void  _sub_Op_Halt(const Node *n);
  void  _sub_Op_If(const Node *n);
  void  _sub_Op_Jump(const Node *n);
  void  _sub_Op_LShiftI(const Node *n);
  void  _sub_Op_LShiftL(const Node *n);
  void  _sub_Op_LoadB(const Node *n);
  void  _sub_Op_LoadUB(const Node *n);
  void  _sub_Op_LoadUS(const Node *n);
  void  _sub_Op_LoadD(const Node *n);
  void  _sub_Op_LoadD_unaligned(const Node *n);
  void  _sub_Op_LoadF(const Node *n);
  void  _sub_Op_LoadI(const Node *n);
  void  _sub_Op_LoadKlass(const Node *n);
  void  _sub_Op_LoadL(const Node *n);
  void  _sub_Op_LoadL_unaligned(const Node *n);
  void  _sub_Op_LoadPLocked(const Node *n);
  void  _sub_Op_LoadP(const Node *n);
  void  _sub_Op_LoadRange(const Node *n);
  void  _sub_Op_LoadS(const Node *n);
  void  _sub_Op_MaxI(const Node *n);
  void  _sub_Op_MemBarAcquire(const Node *n);
  void  _sub_Op_LoadFence(const Node *n);
  void  _sub_Op_MemBarAcquireLock(const Node *n);
  void  _sub_Op_MemBarRelease(const Node *n);
  void  _sub_Op_StoreFence(const Node *n);
  void  _sub_Op_MemBarReleaseLock(const Node *n);
  void  _sub_Op_MemBarVolatile(const Node *n);
  void  _sub_Op_MemBarStoreStore(const Node *n);
  void  _sub_Op_MinI(const Node *n);
  void  _sub_Op_ModI(const Node *n);
  void  _sub_Op_ModL(const Node *n);
  void  _sub_Op_MoveI2F(const Node *n);
  void  _sub_Op_MoveF2I(const Node *n);
  void  _sub_Op_MoveL2D(const Node *n);
  void  _sub_Op_MoveD2L(const Node *n);
  void  _sub_Op_MulD(const Node *n);
  void  _sub_Op_MulF(const Node *n);
  void  _sub_Op_MulI(const Node *n);
  void  _sub_Op_MulL(const Node *n);
  void  _sub_Op_NegD(const Node *n);
  void  _sub_Op_NegF(const Node *n);
  void  _sub_Op_OrI(const Node *n);
  void  _sub_Op_OrL(const Node *n);
  void  _sub_Op_PartialSubtypeCheck(const Node *n);
  void  _sub_Op_PopCountI(const Node *n);
  void  _sub_Op_PopCountL(const Node *n);
  void  _sub_Op_PrefetchAllocation(const Node *n);
  void  _sub_Op_RShiftI(const Node *n);
  void  _sub_Op_RShiftL(const Node *n);
  void  _sub_Op_Rethrow(const Node *n);
  void  _sub_Op_Return(const Node *n);
  void  _sub_Op_SafePoint(const Node *n);
  void  _sub_Op_SqrtD(const Node *n);
  void  _sub_Op_StoreB(const Node *n);
  void  _sub_Op_StoreC(const Node *n);
  void  _sub_Op_StoreCM(const Node *n);
  void  _sub_Op_StorePConditional(const Node *n);
  void  _sub_Op_StoreIConditional(const Node *n);
  void  _sub_Op_StoreD(const Node *n);
  void  _sub_Op_StoreF(const Node *n);
  void  _sub_Op_StoreI(const Node *n);
  void  _sub_Op_StoreL(const Node *n);
  void  _sub_Op_StoreP(const Node *n);
  void  _sub_Op_SubD(const Node *n);
  void  _sub_Op_SubF(const Node *n);
  void  _sub_Op_SubI(const Node *n);
  void  _sub_Op_SubL(const Node *n);
  void  _sub_Op_TailCall(const Node *n);
  void  _sub_Op_TailJump(const Node *n);
  void  _sub_Op_ThreadLocal(const Node *n);
  void  _sub_Op_URShiftI(const Node *n);
  void  _sub_Op_URShiftL(const Node *n);
  void  _sub_Op_XorI(const Node *n);
  void  _sub_Op_XorL(const Node *n);
  void  _sub_Op_AddVB(const Node *n);
  void  _sub_Op_AddVS(const Node *n);
  void  _sub_Op_AddVI(const Node *n);
  void  _sub_Op_AddVL(const Node *n);
  void  _sub_Op_AddVF(const Node *n);
  void  _sub_Op_AddVD(const Node *n);
  void  _sub_Op_SubVB(const Node *n);
  void  _sub_Op_SubVS(const Node *n);
  void  _sub_Op_SubVI(const Node *n);
  void  _sub_Op_SubVL(const Node *n);
  void  _sub_Op_SubVF(const Node *n);
  void  _sub_Op_SubVD(const Node *n);
  void  _sub_Op_MulVS(const Node *n);
  void  _sub_Op_MulVI(const Node *n);
  void  _sub_Op_MulVF(const Node *n);
  void  _sub_Op_MulVD(const Node *n);
  void  _sub_Op_DivVF(const Node *n);
  void  _sub_Op_DivVD(const Node *n);
  void  _sub_Op_LShiftCntV(const Node *n);
  void  _sub_Op_RShiftCntV(const Node *n);
  void  _sub_Op_LShiftVB(const Node *n);
  void  _sub_Op_LShiftVS(const Node *n);
  void  _sub_Op_LShiftVI(const Node *n);
  void  _sub_Op_LShiftVL(const Node *n);
  void  _sub_Op_RShiftVB(const Node *n);
  void  _sub_Op_RShiftVS(const Node *n);
  void  _sub_Op_RShiftVI(const Node *n);
  void  _sub_Op_RShiftVL(const Node *n);
  void  _sub_Op_URShiftVS(const Node *n);
  void  _sub_Op_URShiftVI(const Node *n);
  void  _sub_Op_URShiftVL(const Node *n);
  void  _sub_Op_AndV(const Node *n);
  void  _sub_Op_OrV(const Node *n);
  void  _sub_Op_XorV(const Node *n);
  void  _sub_Op_LoadVector(const Node *n);
  void  _sub_Op_StoreVector(const Node *n);
  void  _sub_Op_ReplicateB(const Node *n);
  void  _sub_Op_ReplicateS(const Node *n);
  void  _sub_Op_ReplicateI(const Node *n);
  void  _sub_Op_ReplicateL(const Node *n);
  void  _sub_Op_ReplicateF(const Node *n);
  void  _sub_Op_ReplicateD(const Node *n);
};



// Total number of operands defined in architecture definition
#define FIRST_OPERAND_CLASS   111
#define NUM_OPERANDS          126

// Total number of instructions defined in architecture definition
#define NUM_INSTRUCTIONS   501

//----------------------------Declare classes derived from MachOper----------

class UniverseOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
public:
  UniverseOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return UNIVERSE; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "Universe";}
#endif
};

class sRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return SREGI; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegI";}
#endif
};

class sRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return SREGP; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegP";}
#endif
};

class sRegFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegFOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return SREGF; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegF";}
#endif
};

class sRegDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegDOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return SREGD; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegD";}
#endif
};

class sRegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegLOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return SREGL; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegL";}
#endif
};

class immIRotOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immIRotOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMIROT; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immIRot";}
#endif
};

class immIRotnOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immIRotnOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMIROTN; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immIRotn";}
#endif
};

class immIRotnegOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immIRotnegOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMIROTNEG; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immIRotneg";}
#endif
};

class immU31RotOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immU31RotOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMU31ROT; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immU31Rot";}
#endif
};

class immPRotOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  immPRotOper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMPROT; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immPRot";}
#endif
};

class immLlowRotOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immLlowRotOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMLLOWROT; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immLlowRot";}
#endif
};

class immLRot2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immLRot2Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMLROT2; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immLRot2";}
#endif
};

class immI12Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI12Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI12; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI12";}
#endif
};

class immI10x2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI10x2Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI10X2; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI10x2";}
#endif
};

class immI12x2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI12x2Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI12X2; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI12x2";}
#endif
};

class immIOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immIOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI";}
#endif
};

class immU8Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immU8Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMU8; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immU8";}
#endif
};

class immI16Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI16Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI16; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI16";}
#endif
};

class immIHDOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immIHDOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMIHD; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immIHD";}
#endif
};

class immIFPOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immIFPOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMIFP; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immIFP";}
#endif
};

class immU5Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immU5Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMU5; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immU5";}
#endif
};

class immU6BigOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immU6BigOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMU6BIG; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immU6Big";}
#endif
};

class immI0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI0Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI0; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI0";}
#endif
};

class immI_1Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_1Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_1; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_1";}
#endif
};

class immI_2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_2Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_2; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_2";}
#endif
};

class immI_3Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_3Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_3; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_3";}
#endif
};

class immI_4Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_4Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_4; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_4";}
#endif
};

class immI_8Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_8Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_8; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_8";}
#endif
};

class immU31Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immU31Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMU31; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immU31";}
#endif
};

class immI_32_63Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_32_63Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_32_63; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_32_63";}
#endif
};

class immI_16Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_16Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_16; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_16";}
#endif
};

class immI_24Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_24Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_24; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_24";}
#endif
};

class immI_255Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_255Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_255; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_255";}
#endif
};

class immI_65535Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  immI_65535Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_65535; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "immI_65535";}
#endif
};

class aimmIOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  aimmIOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return AIMMI; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "aimmI";}
#endif
};

class aimmInegOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  aimmInegOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return AIMMINEG; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "aimmIneg";}
#endif
};

class aimmU31Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  aimmU31Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return AIMMU31; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "aimmU31";}
#endif
};

class limmIOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  limmIOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return LIMMI; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "limmI";}
#endif
};

class limmIlow8Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  limmIlow8Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return LIMMILOW8; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "limmIlow8";}
#endif
};

class limmU31Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  limmU31Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return LIMMU31; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "limmU31";}
#endif
};

class limmInOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32_t        _c0;
public:
  limmInOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return LIMMIN; }
  virtual const Type    *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "limmIn";}
#endif
};

class immL_FFOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL_FFOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML_FF; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immL_FF";}
#endif
};

class immL_FFFFOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL_FFFFOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML_FFFF; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immL_FFFF";}
#endif
};

class immPOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  immPOper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMP; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immP";}
#endif
};

class immP0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  immP0Oper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMP0; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immP0";}
#endif
};

class immP_pollOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  immP_pollOper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMP_POLL; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immP_poll";}
#endif
};

class immNOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypeNarrowOop *_c0;
public:
  immNOper(const TypeNarrowOop *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMN; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_ptrtype()->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->get_ptrtype()->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immN";}
#endif
};

class immNKlassOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypeNarrowKlass *_c0;
public:
  immNKlassOper(const TypeNarrowKlass *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMNKLASS; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_ptrtype()->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->get_ptrtype()->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immNKlass";}
#endif
};

class immN0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypeNarrowOop *_c0;
public:
  immN0Oper(const TypeNarrowOop *c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMN0; }
  virtual const Type    *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_ptrtype()->get_con(); }
  virtual relocInfo::relocType           constant_reloc() const { return _c0->get_ptrtype()->reloc(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immN0";}
#endif
};

class immLOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immLOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immL";}
#endif
};

class immL0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL0Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML0; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immL0";}
#endif
};

class immL16Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL16Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML16; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immL16";}
#endif
};

class immL_32bitsOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL_32bitsOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML_32BITS; }
  virtual const Type    *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, (int64_t)_c0);
    st->print("/" PTR64_FORMAT, (uint64_t)_c0);
  }
  virtual const char    *Name() const { return "immL_32bits";}
#endif
};

class immDOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immDOper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMD; }
  virtual const Type    *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
    jlong _c0l = JavaValue(_c0).get_jlong();
    st->print("/" PTR64_FORMAT, (uint64_t)_c0l);
  }
  virtual const char    *Name() const { return "immD";}
#endif
};

class immD0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immD0Oper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMD0; }
  virtual const Type    *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
    jlong _c0l = JavaValue(_c0).get_jlong();
    st->print("/" PTR64_FORMAT, (uint64_t)_c0l);
  }
  virtual const char    *Name() const { return "immD0";}
#endif
};

class imm8DOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  imm8DOper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMM8D; }
  virtual const Type    *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
    jlong _c0l = JavaValue(_c0).get_jlong();
    st->print("/" PTR64_FORMAT, (uint64_t)_c0l);
  }
  virtual const char    *Name() const { return "imm8D";}
#endif
};

class immFOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  immFOper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMF; }
  virtual const Type    *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
    jint _c0i = JavaValue(_c0).get_jint();
    st->print("/0x%x/", _c0i);
  }
  virtual const char    *Name() const { return "immF";}
#endif
};

class immF0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  immF0Oper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMMF0; }
  virtual const Type    *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
    jint _c0i = JavaValue(_c0).get_jint();
    st->print("/0x%x/", _c0i);
  }
  virtual const char    *Name() const { return "immF0";}
#endif
};

class imm8FOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  imm8FOper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IMM8F; }
  virtual const Type    *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
    jint _c0i = JavaValue(_c0).get_jint();
    st->print("/0x%x/", _c0i);
  }
  virtual const char    *Name() const { return "imm8F";}
#endif
};

class iRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  iRegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IREGI; }
  virtual const Type    *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "iRegI";}
#endif
};

class iRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  iRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IREGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "iRegP";}
#endif
};

class sp_ptr_RegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sp_ptr_RegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return SP_PTR_REGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sp_ptr_RegP";}
#endif
};

class R0RegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R0RegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R0REGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R0RegP";}
#endif
};

class R1RegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R1RegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R1REGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R1RegP";}
#endif
};

class R2RegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R2RegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R2REGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R2RegP";}
#endif
};

class RExceptionRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  RExceptionRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return REXCEPTIONREGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "RExceptionRegP";}
#endif
};

class RthreadRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  RthreadRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return RTHREADREGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "RthreadRegP";}
#endif
};

class IPRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  IPRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IPREGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "IPRegP";}
#endif
};

class LRRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  LRRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return LRREGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "LRRegP";}
#endif
};

class R0RegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R0RegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R0REGI; }
  virtual const Type    *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R0RegI";}
#endif
};

class R1RegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R1RegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R1REGI; }
  virtual const Type    *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R1RegI";}
#endif
};

class R2RegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R2RegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R2REGI; }
  virtual const Type    *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R2RegI";}
#endif
};

class R3RegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R3RegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R3REGI; }
  virtual const Type    *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R3RegI";}
#endif
};

class R12RegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R12RegIOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R12REGI; }
  virtual const Type    *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R12RegI";}
#endif
};

class iRegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  iRegLOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IREGL; }
  virtual const Type    *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "iRegL";}
#endif
};

class iRegLdOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  iRegLdOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return IREGLD; }
  virtual const Type    *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "iRegLd";}
#endif
};

class R0R1RegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R0R1RegLOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R0R1REGL; }
  virtual const Type    *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R0R1RegL";}
#endif
};

class R2R3RegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  R2R3RegLOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return R2R3REGL; }
  virtual const Type    *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "R2R3RegL";}
#endif
};

class flagsRegOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREG; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsReg";}
#endif
};

class flagsReg_EQNELTGEOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsReg_EQNELTGEOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREG_EQNELTGE; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsReg_EQNELTGE";}
#endif
};

class flagsRegUOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegUOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREGU; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsRegU";}
#endif
};

class flagsRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREGP; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsRegP";}
#endif
};

class flagsRegL_LTGEOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegL_LTGEOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREGL_LTGE; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsRegL_LTGE";}
#endif
};

class flagsRegL_EQNEOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegL_EQNEOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREGL_EQNE; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsRegL_EQNE";}
#endif
};

class flagsRegL_LEGTOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegL_LEGTOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREGL_LEGT; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsRegL_LEGT";}
#endif
};

class flagsRegFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsRegFOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return FLAGSREGF; }
  virtual const Type    *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsRegF";}
#endif
};

class vecDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  vecDOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return VECD; }
  virtual const Type    *type() const { return TypeVect::VECTD; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "vecD";}
#endif
};

class vecXOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  vecXOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return VECX; }
  virtual const Type    *type() const { return TypeVect::VECTX; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "vecX";}
#endif
};

class regDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regDOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return REGD; }
  virtual const Type    *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regD";}
#endif
};

class regFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regFOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return REGF; }
  virtual const Type    *type() const { return Type::FLOAT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regF";}
#endif
};

class regD_lowOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regD_lowOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return REGD_LOW; }
  virtual const Type    *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regD_low";}
#endif
};

class inline_cache_regPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  inline_cache_regPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return INLINE_CACHE_REGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "inline_cache_regP";}
#endif
};

class interpreter_method_oop_regPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  interpreter_method_oop_regPOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return INTERPRETER_METHOD_OOP_REGP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "interpreter_method_oop_regP";}
#endif
};

class indirectOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  indirectOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return INDIRECT; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xf;
  }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0x0;
  }
  virtual int            constant_disp() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "indirect";}
#endif
};

class indOffset12Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffset12Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSET12; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xf;
  }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: offset
    return (int)_c0;
  }
  virtual int            constant_disp() const {
    // Replacement variable: offset
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "indOffset12";}
#endif
};

class indOffsetFPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffsetFPOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSETFP; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xf;
  }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: offset
    return (int)_c0;
  }
  virtual int            constant_disp() const {
    // Replacement variable: offset
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "indOffsetFP";}
#endif
};

class indOffsetHDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffsetHDOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSETHD; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xf;
  }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: offset
    return (int)_c0;
  }
  virtual int            constant_disp() const {
    // Replacement variable: offset
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "indOffsetHD";}
#endif
};

class indOffsetFPx2Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffsetFPx2Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSETFPX2; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xf;
  }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: offset
    return (int)_c0;
  }
  virtual int            constant_disp() const {
    // Replacement variable: offset
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "indOffsetFPx2";}
#endif
};

class indOffset12x2Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffset12x2Oper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSET12X2; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xf;
  }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: offset
    return (int)_c0;
  }
  virtual int            constant_disp() const {
    // Replacement variable: offset
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "indOffset12x2";}
#endif
};

class indIndexOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
public:
  indIndexOper() {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return INDINDEX; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: addr
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: index
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const {
    return 0x0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0x0;
  }
  virtual int            constant_disp() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "indIndex";}
#endif
};

class indIndexScaleOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indIndexScaleOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDINDEXSCALE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: addr
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: index
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const {
    // Replacement variable: scale
    return (int)_c0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0x0;
  }
  virtual int            constant_disp() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "indIndexScale";}
#endif
};

class cmpOpOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    case  BoolTest::overflow : return overflow();
    case  BoolTest::no_overflow: return no_overflow();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return CMPOP; }
  virtual const Type    *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const {
    return 0x0;
  }
  virtual int            not_equal() const {
    return 0x1;
  }
  virtual int            less() const {
    return 0xb;
  }
  virtual int            greater_equal() const {
    return 0xa;
  }
  virtual int            less_equal() const {
    return 0xd;
  }
  virtual int            greater() const {
    return 0xc;
  }
  virtual int            overflow() const {
    return 0x0;
  }
  virtual int            no_overflow() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
  }
  virtual const char    *Name() const { return "cmpOp";}
#endif
};

class cmpOp0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    case  BoolTest::overflow : return overflow();
    case  BoolTest::no_overflow: return no_overflow();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOp0Oper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return CMPOP0; }
  virtual const Type    *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const {
    return 0x0;
  }
  virtual int            not_equal() const {
    return 0x1;
  }
  virtual int            less() const {
    return 0x4;
  }
  virtual int            greater_equal() const {
    return 0x5;
  }
  virtual int            less_equal() const {
    return 0xd;
  }
  virtual int            greater() const {
    return 0xc;
  }
  virtual int            overflow() const {
    return 0x0;
  }
  virtual int            no_overflow() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
  }
  virtual const char    *Name() const { return "cmpOp0";}
#endif
};

class cmpOpUOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    case  BoolTest::overflow : return overflow();
    case  BoolTest::no_overflow: return no_overflow();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpUOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return CMPOPU; }
  virtual const Type    *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const {
    return 0x0;
  }
  virtual int            not_equal() const {
    return 0x1;
  }
  virtual int            less() const {
    return 0x3;
  }
  virtual int            greater_equal() const {
    return 0x2;
  }
  virtual int            less_equal() const {
    return 0x9;
  }
  virtual int            greater() const {
    return 0x8;
  }
  virtual int            overflow() const {
    return 0x0;
  }
  virtual int            no_overflow() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
  }
  virtual const char    *Name() const { return "cmpOpU";}
#endif
};

class cmpOpPOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    case  BoolTest::overflow : return overflow();
    case  BoolTest::no_overflow: return no_overflow();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpPOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return CMPOPP; }
  virtual const Type    *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const {
    return 0x0;
  }
  virtual int            not_equal() const {
    return 0x1;
  }
  virtual int            less() const {
    return 0x3;
  }
  virtual int            greater_equal() const {
    return 0x2;
  }
  virtual int            less_equal() const {
    return 0x9;
  }
  virtual int            greater() const {
    return 0x8;
  }
  virtual int            overflow() const {
    return 0x0;
  }
  virtual int            no_overflow() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
  }
  virtual const char    *Name() const { return "cmpOpP";}
#endif
};

class cmpOpLOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    case  BoolTest::overflow : return overflow();
    case  BoolTest::no_overflow: return no_overflow();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpLOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return CMPOPL; }
  virtual const Type    *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const {
    return 0x0;
  }
  virtual int            not_equal() const {
    return 0x1;
  }
  virtual int            less() const {
    return 0xb;
  }
  virtual int            greater_equal() const {
    return 0xa;
  }
  virtual int            less_equal() const {
    return 0xd;
  }
  virtual int            greater() const {
    return 0xc;
  }
  virtual int            overflow() const {
    return 0x0;
  }
  virtual int            no_overflow() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
  }
  virtual const char    *Name() const { return "cmpOpL";}
#endif
};

class cmpOpL_commuteOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    case  BoolTest::overflow : return overflow();
    case  BoolTest::no_overflow: return no_overflow();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpL_commuteOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual uint           opcode() const { return CMPOPL_COMMUTE; }
  virtual const Type    *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const {
    return 0x0;
  }
  virtual int            not_equal() const {
    return 0x1;
  }
  virtual int            less() const {
    return 0xc;
  }
  virtual int            greater_equal() const {
    return 0xd;
  }
  virtual int            less_equal() const {
    return 0xa;
  }
  virtual int            greater() const {
    return 0xb;
  }
  virtual int            overflow() const {
    return 0x0;
  }
  virtual int            no_overflow() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
  }
  virtual const char    *Name() const { return "cmpOpL_commute";}
#endif
};

class shiftedXOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  shiftedXOper(int32_t c0)  : _c0(c0) {}
  virtual MachOper      *clone() const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return SHIFTEDX; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    // Replacement variable: src2
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0xff;
  }
  virtual int            scale() const {
    // Replacement variable: src3
    return (int)_c0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
    return 0x0;
  }
  virtual int            constant_disp() const {
    return 0x0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("/0x%08x", _c0);
  }
  virtual const char    *Name() const { return "shiftedX";}
#endif
};

//----------------------------Declare classes for Pipelines-----------------

// Pipeline_Use_Cycle_Mask Class
class Pipeline_Use_Cycle_Mask {
protected:
  uint _mask1, _mask2, _mask3;

public:
  Pipeline_Use_Cycle_Mask() : _mask1(0), _mask2(0), _mask3(0) {}

  Pipeline_Use_Cycle_Mask(uint mask1, uint mask2, uint mask3) : _mask1(mask1), _mask2(mask2), _mask3(mask3) {}

  Pipeline_Use_Cycle_Mask& operator=(const Pipeline_Use_Cycle_Mask &in) {
    _mask1 = in._mask1;
    _mask2 = in._mask2;
    _mask3 = in._mask3;
    return *this;
  }

  Pipeline_Use_Cycle_Mask intersect(const Pipeline_Use_Cycle_Mask &in2) {
    Pipeline_Use_Cycle_Mask out;
    out._mask1 = _mask1 & in2._mask1;
    out._mask2 = _mask2 & in2._mask2;
    out._mask3 = _mask3 & in2._mask3;
    return out;
  }

  bool overlaps(const Pipeline_Use_Cycle_Mask &in2) const {
    return (((_mask1 & in2._mask1) != 0) || ((_mask2 & in2._mask2) != 0) || ((_mask3 & in2._mask3) != 0)) ? true : false;
  }

  Pipeline_Use_Cycle_Mask& operator<<=(int n) {
    if (n >= 32)
      do {
        _mask3 = _mask2; _mask2 = _mask1; _mask1 = 0;
      } while ((n -= 32) >= 32);

    if (n > 0) {
      uint m = 32 - n;
      uint mask = (1 << n) - 1;
      uint temp2 = mask & (_mask1 >> m); _mask1 <<= n;
      uint temp3 = mask & (_mask2 >> m); _mask2 <<= n; _mask2 |= temp2;
      _mask3 <<= n; _mask3 |= temp3;
    }
    return *this;
  }

  void Or(const Pipeline_Use_Cycle_Mask &);

  friend Pipeline_Use_Cycle_Mask operator&(const Pipeline_Use_Cycle_Mask &, const Pipeline_Use_Cycle_Mask &);
  friend Pipeline_Use_Cycle_Mask operator|(const Pipeline_Use_Cycle_Mask &, const Pipeline_Use_Cycle_Mask &);

  friend class Pipeline_Use;

  friend class Pipeline_Use_Element;

};

// Pipeline_Use_Element Class
class Pipeline_Use_Element {
protected:
  // Mask of used functional units
  uint _used;

  // Lower and upper bound of functional unit number range
  uint _lb, _ub;

  // Indicates multiple functionals units available
  bool _multiple;

  // Mask of specific used cycles
  Pipeline_Use_Cycle_Mask _mask;

public:
  Pipeline_Use_Element() {}

  Pipeline_Use_Element(uint used, uint lb, uint ub, bool multiple, Pipeline_Use_Cycle_Mask mask)
  : _used(used), _lb(lb), _ub(ub), _multiple(multiple), _mask(mask) {}

  uint used() const { return _used; }

  uint lowerBound() const { return _lb; }

  uint upperBound() const { return _ub; }

  bool multiple() const { return _multiple; }

  Pipeline_Use_Cycle_Mask mask() const { return _mask; }

  bool overlaps(const Pipeline_Use_Element &in2) const {
    return ((_used & in2._used) != 0 && _mask.overlaps(in2._mask));
  }

  void step(uint cycles) {
    _used = 0;
    _mask <<= cycles;
  }

  friend class Pipeline_Use;
};

// Pipeline_Use Class
class Pipeline_Use {
protected:
  // These resources can be used
  uint _resources_used;

  // These resources are used; excludes multiple choice functional units
  uint _resources_used_exclusively;

  // Number of elements
  uint _count;

  // This is the array of Pipeline_Use_Elements
  Pipeline_Use_Element * _elements;

public:
  Pipeline_Use(uint resources_used, uint resources_used_exclusively, uint count, Pipeline_Use_Element *elements)
  : _resources_used(resources_used)
  , _resources_used_exclusively(resources_used_exclusively)
  , _count(count)
  , _elements(elements)
  {}

  uint resourcesUsed() const { return _resources_used; }

  uint resourcesUsedExclusively() const { return _resources_used_exclusively; }

  uint count() const { return _count; }

  Pipeline_Use_Element * element(uint i) const { return &_elements[i]; }

  uint full_latency(uint delay, const Pipeline_Use &pred) const;

  void add_usage(const Pipeline_Use &pred);

  void reset() {
    _resources_used = _resources_used_exclusively = 0;
  };

  void step(uint cycles) {
    reset();
    for (uint i = 0; i < 8; i++)
      (&_elements[i])->step(cycles);
  };

  static const Pipeline_Use         elaborated_use;
  static const Pipeline_Use_Element elaborated_elements[8];

  friend class Pipeline;
};

// Pipeline Class
class Pipeline {
public:
  static bool enabled() { return true; }

  enum {
    _variable_size_instructions = 0,
    _fixed_size_instructions = 1,
    _branch_has_delay_slot = 0,
    _max_instrs_per_bundle = 4,
    _max_bundles_per_cycle = 1,
    _max_instrs_per_cycle = 4
  };

  static bool instr_has_unit_size() { return true; }

// Bundling is not supported

  // Size of an instruction
  static uint instr_unit_size() { return 4; };

  // Bundles do not exist - unsupported
  static uint bundle_unit_size() { assert( false, "Bundles are not supported" ); return 0; };

  static bool requires_bundling() { return false; }

private:
  Pipeline();  // Not a legal constructor

  const unsigned char                   _read_stage_count;
  const unsigned char                   _write_stage;
  const unsigned char                   _fixed_latency;
  const unsigned char                   _instruction_count;
  const bool                            _has_fixed_latency;
  const bool                            _has_branch_delay;
  const bool                            _has_multiple_bundles;
  const bool                            _force_serialization;
  const bool                            _may_have_no_code;
  const enum machPipelineStages * const _read_stages;
  const enum machPipelineStages * const _resource_stage;
  const uint                    * const _resource_cycles;
  const Pipeline_Use                    _resource_use;

public:
  Pipeline(uint                            write_stage,
           uint                            count,
           bool                            has_fixed_latency,
           uint                            fixed_latency,
           uint                            instruction_count,
           bool                            has_branch_delay,
           bool                            has_multiple_bundles,
           bool                            force_serialization,
           bool                            may_have_no_code,
           enum machPipelineStages * const dst,
           enum machPipelineStages * const stage,
           uint                    * const cycles,
           Pipeline_Use                    resource_use)
  : _write_stage(write_stage)
  , _read_stage_count(count)
  , _has_fixed_latency(has_fixed_latency)
  , _fixed_latency(fixed_latency)
  , _read_stages(dst)
  , _resource_stage(stage)
  , _resource_cycles(cycles)
  , _resource_use(resource_use)
  , _instruction_count(instruction_count)
  , _has_branch_delay(has_branch_delay)
  , _has_multiple_bundles(has_multiple_bundles)
  , _force_serialization(force_serialization)
  , _may_have_no_code(may_have_no_code)
  {};

  uint writeStage() const {
    return (_write_stage);
  }

  enum machPipelineStages readStage(int ndx) const {
    return (ndx < _read_stage_count ? _read_stages[ndx] : stage_undefined);  }

  uint resourcesUsed() const {
    return _resource_use.resourcesUsed();
  }

  uint resourcesUsedExclusively() const {
    return _resource_use.resourcesUsedExclusively();
  }

  bool hasFixedLatency() const {
    return (_has_fixed_latency);
  }

  uint fixedLatency() const {
    return (_fixed_latency);
  }

  uint functional_unit_latency(uint start, const Pipeline *pred) const;

  uint operand_latency(uint opnd, const Pipeline *pred) const;

  const Pipeline_Use& resourceUse() const {
    return (_resource_use); }

  const Pipeline_Use_Element * resourceUseElement(uint i) const {
    return (&_resource_use._elements[i]); }

  uint resourceUseCount() const {
    return (_resource_use._count); }

  uint instructionCount() const {
    return (_instruction_count); }

  bool hasBranchDelay() const {
    return (_has_branch_delay); }

  bool hasMultipleBundles() const {
    return (_has_multiple_bundles); }

  bool forceSerialization() const {
    return (_force_serialization); }

  bool mayHaveNoCode() const {
    return (_may_have_no_code); }

//const Pipeline_Use_Cycle_Mask& resourceUseMask(int resource) const {
//  return (_resource_use_masks[resource]); }


#ifndef PRODUCT
  static const char * stageName(uint i);
#endif
};

// Bundle class
class Bundle {
protected:
  enum {
    _unused_delay                   = 0x0,
    _use_nop_delay                  = 0x1,
    _use_unconditional_delay        = 0x2,
    _use_conditional_delay          = 0x3,
    _used_in_conditional_delay      = 0x4,
    _used_in_unconditional_delay    = 0x5,
    _used_in_all_conditional_delays = 0x6,

    _use_delay                      = 0x3,
    _used_in_delay                  = 0x4
  };

  uint _flags          : 3,
       _starts_bundle  : 1,
       _instr_count    : 3,
       _resources_used : 8;
public:
  Bundle() : _flags(_unused_delay), _starts_bundle(0), _instr_count(0), _resources_used(0) {}

  void set_instr_count(uint i) { _instr_count  = i; }
  void set_resources_used(uint i) { _resources_used   = i; }
  void clear_usage() { _flags = _unused_delay; }
  void set_starts_bundle() { _starts_bundle = true; }
  uint flags() const { return (_flags); }
  uint instr_count() const { return (_instr_count); }
  uint resources_used() const { return (_resources_used); }
  bool starts_bundle() const { return (_starts_bundle != 0); }
  void set_use_nop_delay() { _flags = _use_nop_delay; }
  void set_use_unconditional_delay() { _flags = _use_unconditional_delay; }
  void set_use_conditional_delay() { _flags = _use_conditional_delay; }
  void set_used_in_unconditional_delay() { _flags = _used_in_unconditional_delay; }
  void set_used_in_conditional_delay() { _flags = _used_in_conditional_delay; }
  void set_used_in_all_conditional_delays() { _flags = _used_in_all_conditional_delays; }
  bool use_nop_delay() { return (_flags == _use_nop_delay); }
  bool use_unconditional_delay() { return (_flags == _use_unconditional_delay); }
  bool use_conditional_delay() { return (_flags == _use_conditional_delay); }
  bool used_in_unconditional_delay() { return (_flags == _used_in_unconditional_delay); }
  bool used_in_conditional_delay() { return (_flags == _used_in_conditional_delay); }
  bool used_in_all_conditional_delays() { return (_flags == _used_in_all_conditional_delays); }
  bool use_delay() { return ((_flags & _use_delay) != 0); }
  bool used_in_delay() { return ((_flags & _used_in_delay) != 0); }

  enum {
    _nop_count = 5
  };

  static void initialize_nops(MachNode *nop_list[5]);

#ifndef PRODUCT
  void dump(outputStream *st = tty) const;
#endif
};


//----------------------------Declare classes derived from MachNode----------

class Nop_A0Node : public MachNopNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Nop_A0_rule; }
  virtual int            ideal_Opcode() const { return Op_Node; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Nop_A0Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Nop_A0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Nop_A0";}
#endif
};

class Nop_A1Node : public MachNopNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Nop_A1_rule; }
  virtual int            ideal_Opcode() const { return Op_Node; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Nop_A1Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Nop_A1Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Nop_A1";}
#endif
};

class Nop_MSNode : public MachNopNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Nop_MS_rule; }
  virtual int            ideal_Opcode() const { return Op_Node; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Nop_MSNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Nop_MSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Nop_MS";}
#endif
};

class Nop_FANode : public MachNopNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Nop_FA_rule; }
  virtual int            ideal_Opcode() const { return Op_Node; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Nop_FANode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Nop_FANode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Nop_FA";}
#endif
};

class Nop_BRNode : public MachNopNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Nop_BR_rule; }
  virtual int            ideal_Opcode() const { return Op_Node; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Nop_BRNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Nop_BRNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Nop_BR";}
#endif
};

class loadBNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadB; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadBNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadB";}
#endif
};

class loadB2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadB2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadB2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadB2LNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadB2L";}
#endif
};

class loadUBNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadUB; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUBNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUB";}
#endif
};

class loadUB2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUB2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUB2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUB2LNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUB2L";}
#endif
};

class loadUB2L_limmINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUB2L_limmI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUB2L_limmINode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUB2L_limmINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUB2L_limmI";}
#endif
};

class loadSNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadS; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadSNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadS";}
#endif
};

class loadS2BNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadS2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadS2BNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadS2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadS2B";}
#endif
};

class loadS2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadS2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadS2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadS2LNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadS2L";}
#endif
};

class loadUSNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadUS; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUSNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS";}
#endif
};

class loadUS2BNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2BNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2B";}
#endif
};

class loadUS2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2LNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2L";}
#endif
};

class loadUS2L_immI_255Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2L_immI_255_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2L_immI_255Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2L_immI_255Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2L_immI_255";}
#endif
};

class loadUS2L_limmINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2L_limmI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2L_limmINode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2L_limmINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2L_limmI";}
#endif
};

class loadINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadINode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI";}
#endif
};

class loadI2BNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2BNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2B";}
#endif
};

class loadI2UBNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2UB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2UBNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2UBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2UB";}
#endif
};

class loadI2SNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2S_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2SNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2SNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2S";}
#endif
};

class loadI2USNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2US_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2USNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2USNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2US";}
#endif
};

class loadI2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2LNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L";}
#endif
};

class loadI2L_immI_255Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_immI_255_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_immI_255Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_immI_255Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_immI_255";}
#endif
};

class loadI2L_immI_65535Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_immI_65535_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_immI_65535Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_immI_65535Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_immI_65535";}
#endif
};

class loadI2L_limmU31Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_limmU31_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_limmU31Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_limmU31Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_limmU31";}
#endif
};

class loadI2L_immU31Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_immU31_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_immU31Node() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_immU31Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_immU31";}
#endif
};

class loadUI2LNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUI2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUI2LNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUI2LNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUI2L";}
#endif
};

class loadLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL";}
#endif
};

class loadL_2instrNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_2instr_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadL_2instrNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadL_2instrNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL_2instr";}
#endif
};

class loadL_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual uint           oper_input_base() const { return 2; }
public:
  loadL_volatileNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadL_volatileNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL_volatile";}
#endif
};

class loadL_volatile_fpNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_volatile_fp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadL_volatile_fpNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadL_volatile_fpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL_volatile_fp";}
#endif
};

class loadL_unalignedNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_unaligned_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL_unaligned; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadL_unalignedNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadL_unalignedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL_unaligned";}
#endif
};

class loadRangeNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadRange_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadRange; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadRangeNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadRangeNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadRange";}
#endif
};

class loadPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadP; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadPNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadPNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadP";}
#endif
};

class loadKlassNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadKlass_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadKlass; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadKlassNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadKlassNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadKlass";}
#endif
};

class loadDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadD; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadDNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadD";}
#endif
};

class loadD_unalignedNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadD_unaligned_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadD_unaligned; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadD_unalignedNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadD_unalignedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadD_unaligned";}
#endif
};

class loadFNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadF; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadFNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadFNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadF";}
#endif
};

class loadConINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConI; }
public:
  loadConINode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConINode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConI
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeInt::make(opnd_array(1)->constant());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI";}
#endif
};

class loadConIMovNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConIMov_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConI; }
public:
  loadConIMovNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConIMovNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConIMov
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeInt::make(opnd_array(1)->constant());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConIMov";}
#endif
};

class loadConIMovnNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConIMovn_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConI; }
public:
  loadConIMovnNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConIMovnNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConIMovn
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeInt::make(opnd_array(1)->constant());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConIMovn";}
#endif
};

class loadConI16Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConI; }
public:
  loadConI16Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConI16Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConI16
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeInt::make(opnd_array(1)->constant());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI16";}
#endif
};

class loadConPNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConP; }
  virtual int            reloc() const;
public:
  loadConPNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConPNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  opnd_array(1)->type();
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConP";}
#endif
};

class loadConP_pollNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConP_poll_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConP; }
  virtual int            reloc() const;
public:
  loadConP_pollNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConP_pollNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConP_poll
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  opnd_array(1)->type();
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConP_poll";}
#endif
};

class loadConLNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConL; }
public:
  loadConLNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConLNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConL
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeLong::make(opnd_array(1)->constantL());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConL";}
#endif
};

class loadConL16Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConL16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConL; }
public:
  loadConL16Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConL16Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConL16
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeLong::make(opnd_array(1)->constantL());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConL16";}
#endif
};

class loadConF_imm8Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConF_imm8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConF; }
  virtual int            reloc() const;
public:
  loadConF_imm8Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConF_imm8Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConF_imm8
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeF::make(opnd_array(1)->constantF());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConF_imm8";}
#endif
};

class loadConFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConF; }
  virtual int            reloc() const;
public:
  loadConFNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeF::make(opnd_array(1)->constantF());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConF";}
#endif
};

class loadConD_imm8Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConD_imm8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConD; }
  virtual int            reloc() const;
public:
  loadConD_imm8Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConD_imm8Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConD_imm8
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeD::make(opnd_array(1)->constantD());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConD_imm8";}
#endif
};

class loadConDNode : public MachConstantNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConD_rule; }
  virtual void           eval_constant(Compile* C);
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConD; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  loadConDNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConDNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize loadConD
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const {
    return  TypeD::make(opnd_array(1)->constantD());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConD";}
#endif
};

class prefetchAlloc_mpNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchAlloc_mp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchAllocation; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchAlloc_mpNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchAlloc_mpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchAlloc_mp";}
#endif
};

class prefetchAlloc_spNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchAlloc_sp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchAllocation; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchAlloc_spNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchAlloc_spNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchAlloc_sp";}
#endif
};

class storeBNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreB; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeBNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeB";}
#endif
};

class storeCMNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeCM_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreCM; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeCMNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeCMNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeCM";}
#endif
};

class storeCNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeC_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreC; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeCNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeCNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeC";}
#endif
};

class storeINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeI";}
#endif
};

class storeLNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeLNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL";}
#endif
};

class storeL_2instrNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL_2instr_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeL_2instrNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeL_2instrNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL_2instr";}
#endif
};

class storeL_volatileNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual uint           oper_input_base() const { return 2; }
public:
  storeL_volatileNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeL_volatileNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL_volatile";}
#endif
};

class storeL_volatile_fpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL_volatile_fp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeL_volatile_fpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeL_volatile_fpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL_volatile_fp";}
#endif
};

class storePNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreP; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storePNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storePNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeP";}
#endif
};

class storeDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreD; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeD";}
#endif
};

class storeFNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeFNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeFNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeF";}
#endif
};

class membar_storestoreNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_storestore_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarStoreStore; }
public:
  membar_storestoreNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_storestoreNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_storestore";}
#endif
};

class membar_acquireNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_acquire_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarAcquire; }
public:
  membar_acquireNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_acquireNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_acquire";}
#endif
};

class membar_acquire_0Node : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_acquire_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadFence; }
public:
  membar_acquire_0Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_acquire_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_acquire_0";}
#endif
};

class membar_acquire_lockNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_acquire_lock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarAcquireLock; }
public:
  membar_acquire_lockNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_acquire_lockNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_acquire_lock";}
#endif
};

class membar_releaseNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_release_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarRelease; }
public:
  membar_releaseNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_releaseNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_release";}
#endif
};

class membar_release_0Node : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_release_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreFence; }
public:
  membar_release_0Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_release_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_release_0";}
#endif
};

class membar_release_lockNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_release_lock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarReleaseLock; }
public:
  membar_release_lockNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_release_lockNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_release_lock";}
#endif
};

class membar_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarVolatile; }
public:
  membar_volatileNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_volatileNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_volatile";}
#endif
};

class unnecessary_membar_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return unnecessary_membar_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarVolatile; }
public:
  unnecessary_membar_volatileNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(unnecessary_membar_volatileNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "unnecessary_membar_volatile";}
#endif
};

class castX2PNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castX2P_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastX2P; }
  virtual uint           oper_input_base() const { return 1; }
public:
  castX2PNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castX2PNode); }
  // Rematerialize castX2P
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castX2P";}
#endif
};

class castP2XNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castP2X_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastP2X; }
public:
  castP2XNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castP2XNode); }
  // Rematerialize castP2X
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castP2X";}
#endif
};

class cmovIP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIP_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIP_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIP_reg";}
#endif
};

class cmovIP_immMovNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIP_immMov_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIP_immMovNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIP_immMovNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIP_immMov";}
#endif
};

class cmovIP_imm16Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIP_imm16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIP_imm16Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIP_imm16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIP_imm16";}
#endif
};

class cmovI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovI_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_reg";}
#endif
};

class cmovI_immMovNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_immMov_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovI_immMovNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_immMovNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_immMov";}
#endif
};

class cmovII_imm16Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_imm16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovII_imm16Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_imm16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_imm16";}
#endif
};

class cmovII_reg_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_reg_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovII_reg_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_reg_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_reg_EQNELTGE";}
#endif
};

class cmovII_immMov_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_immMov_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovII_immMov_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_immMov_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_immMov_EQNELTGE";}
#endif
};

class cmovII_imm16_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_imm16_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovII_imm16_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_imm16_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_imm16_EQNELTGE";}
#endif
};

class cmovIIu_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIIu_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIIu_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIIu_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIIu_reg";}
#endif
};

class cmovIIu_immMovNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIIu_immMov_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIIu_immMovNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIIu_immMovNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIIu_immMov";}
#endif
};

class cmovIIu_imm16Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIIu_imm16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIIu_imm16Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIIu_imm16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIIu_imm16";}
#endif
};

class cmovPP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPP_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPP_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPP_reg";}
#endif
};

class cmovPP_immNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPP_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPP_immNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPP_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPP_imm";}
#endif
};

class cmovPI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPI_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPI_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPI_reg";}
#endif
};

class cmovPI_reg_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPI_reg_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPI_reg_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPI_reg_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPI_reg_EQNELTGE";}
#endif
};

class cmovPIu_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPIu_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPIu_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPIu_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPIu_reg";}
#endif
};

class cmovPI_immNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPI_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPI_immNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPI_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPI_imm";}
#endif
};

class cmovPI_imm_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPI_imm_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPI_imm_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPI_imm_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPI_imm_EQNELTGE";}
#endif
};

class cmovPIu_immNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPIu_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPIu_immNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPIu_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPIu_imm";}
#endif
};

class cmovFP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFP_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFP_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFP_reg";}
#endif
};

class cmovFI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFI_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFI_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFI_reg";}
#endif
};

class cmovFI_reg_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFI_reg_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFI_reg_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFI_reg_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFI_reg_EQNELTGE";}
#endif
};

class cmovFIu_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFIu_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFIu_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFIu_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFIu_reg";}
#endif
};

class cmovDP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDP_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDP_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDP_reg";}
#endif
};

class cmovDI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDI_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDI_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDI_reg";}
#endif
};

class cmovDI_reg_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDI_reg_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDI_reg_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDI_reg_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDI_reg_EQNELTGE";}
#endif
};

class cmovDIu_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDIu_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDIu_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDIu_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDIu_reg";}
#endif
};

class cmovLP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLP_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLP_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLP_reg";}
#endif
};

class cmovLP_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLP_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLP_immRotNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLP_immRotNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLP_immRot";}
#endif
};

class cmovLP_imm16Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLP_imm16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLP_imm16Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLP_imm16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLP_imm16";}
#endif
};

class cmovLI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLI_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLI_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLI_reg";}
#endif
};

class cmovLI_reg_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLI_reg_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLI_reg_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLI_reg_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLI_reg_EQNELTGE";}
#endif
};

class cmovLI_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLI_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLI_immRotNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLI_immRotNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLI_immRot";}
#endif
};

class cmovLI_immRot_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLI_immRot_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLI_immRot_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLI_immRot_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLI_immRot_EQNELTGE";}
#endif
};

class cmovLI_imm16Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLI_imm16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLI_imm16Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLI_imm16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLI_imm16";}
#endif
};

class cmovLI_imm16_EQNELTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLI_imm16_EQNELTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLI_imm16_EQNELTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLI_imm16_EQNELTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLI_imm16_EQNELTGE";}
#endif
};

class cmovLIu_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLIu_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLIu_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLIu_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLIu_reg";}
#endif
};

class tlsLoadPNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return tlsLoadP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ThreadLocal; }
public:
  tlsLoadPNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(tlsLoadPNode); }
  // Rematerialize tlsLoadP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeRawPtr::BOTTOM; } // tlsLoadP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "tlsLoadP";}
#endif
};

class checkCastPPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return checkCastPP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CheckCastPP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 1; }
public:
  checkCastPPNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(checkCastPPNode); }
  // Rematerialize checkCastPP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "checkCastPP";}
#endif
};

class castPPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castPP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastPP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 1; }
public:
  castPPNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castPPNode); }
  // Rematerialize castPP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castPP";}
#endif
};

class castIINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castII_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastII; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  castIINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castIINode); }
  // Rematerialize castII
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castII";}
#endif
};

class addI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_reg_reg";}
#endif
};

class addshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshlI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshlI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshlI_reg_reg_reg";}
#endif
};

class addshlI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshlI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshlI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshlI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshlI_reg_reg_reg_0";}
#endif
};

class addshlI_reg_imm_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshlI_reg_imm_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshlI_reg_imm_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshlI_reg_imm_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshlI_reg_imm_reg";}
#endif
};

class addshlI_reg_imm_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshlI_reg_imm_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshlI_reg_imm_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshlI_reg_imm_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshlI_reg_imm_reg_0";}
#endif
};

class addsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addsarI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addsarI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addsarI_reg_reg_reg";}
#endif
};

class addsarI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addsarI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addsarI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addsarI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addsarI_reg_reg_reg_0";}
#endif
};

class addsarI_reg_imm_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addsarI_reg_imm_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addsarI_reg_imm_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addsarI_reg_imm_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addsarI_reg_imm_reg";}
#endif
};

class addsarI_reg_imm_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addsarI_reg_imm_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addsarI_reg_imm_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addsarI_reg_imm_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addsarI_reg_imm_reg_0";}
#endif
};

class addshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshrI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshrI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshrI_reg_reg_reg";}
#endif
};

class addshrI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshrI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshrI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshrI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshrI_reg_reg_reg_0";}
#endif
};

class addshrI_reg_imm_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshrI_reg_imm_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshrI_reg_imm_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshrI_reg_imm_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshrI_reg_imm_reg";}
#endif
};

class addshrI_reg_imm_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshrI_reg_imm_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addshrI_reg_imm_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addshrI_reg_imm_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshrI_reg_imm_reg_0";}
#endif
};

class addI_reg_aimmINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_reg_aimmI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  addI_reg_aimmINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_reg_aimmINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_reg_aimmI";}
#endif
};

class addP_reg_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addP_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  addP_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addP_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addP_reg_reg";}
#endif
};

class addshlP_reg_reg_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addshlP_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  addshlP_reg_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addshlP_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addshlP_reg_reg_imm";}
#endif
};

class addP_reg_aimmXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addP_reg_aimmX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  addP_reg_aimmXNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addP_reg_aimmXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addP_reg_aimmX";}
#endif
};

class addL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddL; }
public:
  addL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addL_reg_reg";}
#endif
};

class addL_reg_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addL_reg_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddL; }
public:
  addL_reg_immRotNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addL_reg_immRotNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addL_reg_immRot";}
#endif
};

class loadPLockedNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadPLocked_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadPLocked; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadPLockedNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadPLockedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadPLocked";}
#endif
};

class storePConditionalNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storePConditional_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StorePConditional; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storePConditionalNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(storePConditionalNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize storePConditional
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storePConditional";}
#endif
};

class storeXConditionalNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeXConditional_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreIConditional; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeXConditionalNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(storeXConditionalNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize storeXConditional
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeXConditional";}
#endif
};

class compareAndSwapL_boolNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compareAndSwapL_bool_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CompareAndSwapL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compareAndSwapL_boolNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compareAndSwapL_boolNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compareAndSwapL_bool";}
#endif
};

class compareAndSwapI_boolNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compareAndSwapI_bool_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CompareAndSwapI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compareAndSwapI_boolNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compareAndSwapI_boolNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compareAndSwapI_bool";}
#endif
};

class compareAndSwapP_boolNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compareAndSwapP_bool_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CompareAndSwapP; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compareAndSwapP_boolNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compareAndSwapP_boolNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compareAndSwapP_bool";}
#endif
};

class xaddI_aimmI_no_resNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddI_aimmI_no_res_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddI_aimmI_no_resNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddI_aimmI_no_resNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddI_aimmI_no_res";}
#endif
};

class xaddI_reg_no_resNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddI_reg_no_res_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddI; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddI_reg_no_resNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddI_reg_no_resNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddI_reg_no_res";}
#endif
};

class xaddI_aimmINode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddI_aimmI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddI_aimmINode() {  _num_opnds = 6; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddI_aimmINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddI_aimmI";}
#endif
};

class xaddI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddI_regNode() {  _num_opnds = 6; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddI_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddI_reg";}
#endif
};

class xaddL_reg_no_resNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddL_reg_no_res_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddL_reg_no_resNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddL_reg_no_resNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddL_reg_no_res";}
#endif
};

class xaddL_immRot_no_resNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddL_immRot_no_res_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddL; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddL_immRot_no_resNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddL_immRot_no_resNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddL_immRot_no_res";}
#endif
};

class xaddL_regNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddL_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddL_regNode() {  _num_opnds = 6; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddL_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddL_reg";}
#endif
};

class xaddL_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xaddL_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndAddL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xaddL_immRotNode() {  _num_opnds = 6; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xaddL_immRotNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xaddL_immRot";}
#endif
};

class xchgINode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xchgI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndSetI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xchgINode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xchgINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xchgI";}
#endif
};

class xchgLNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xchgL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndSetL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xchgLNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xchgLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xchgL";}
#endif
};

class xchgPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xchgP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_GetAndSetP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xchgPNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xchgPNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xchgP";}
#endif
};

class subI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_reg_reg";}
#endif
};

class subshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subshlI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subshlI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subshlI_reg_reg_reg";}
#endif
};

class subshlI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subshlI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subshlI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subshlI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subshlI_reg_reg_imm";}
#endif
};

class subsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subsarI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subsarI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subsarI_reg_reg_reg";}
#endif
};

class subsarI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subsarI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subsarI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subsarI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subsarI_reg_reg_imm";}
#endif
};

class subshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subshrI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subshrI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subshrI_reg_reg_reg";}
#endif
};

class subshrI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subshrI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subshrI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subshrI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subshrI_reg_reg_imm";}
#endif
};

class rsbshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rsbshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  rsbshlI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rsbshlI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rsbshlI_reg_reg_reg";}
#endif
};

class rsbshlI_reg_imm_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rsbshlI_reg_imm_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  rsbshlI_reg_imm_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rsbshlI_reg_imm_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rsbshlI_reg_imm_reg";}
#endif
};

class rsbsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rsbsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  rsbsarI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rsbsarI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rsbsarI_reg_reg_reg";}
#endif
};

class rsbsarI_reg_imm_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rsbsarI_reg_imm_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  rsbsarI_reg_imm_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rsbsarI_reg_imm_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rsbsarI_reg_imm_reg";}
#endif
};

class rsbshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rsbshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  rsbshrI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rsbshrI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rsbshrI_reg_reg_reg";}
#endif
};

class rsbshrI_reg_imm_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rsbshrI_reg_imm_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  rsbshrI_reg_imm_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rsbshrI_reg_imm_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rsbshrI_reg_imm_reg";}
#endif
};

class subI_reg_aimmINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_reg_aimmI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subI_reg_aimmINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_reg_aimmINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_reg_aimmI";}
#endif
};

class subI_reg_immRotnegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_reg_immRotneg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  subI_reg_immRotnegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_reg_immRotnegNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_reg_immRotneg";}
#endif
};

class subI_immRot_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_immRot_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
public:
  subI_immRot_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_immRot_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_immRot_reg";}
#endif
};

class subL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
public:
  subL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subL_reg_reg";}
#endif
};

class subL_reg_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subL_reg_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
public:
  subL_reg_immRotNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subL_reg_immRotNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subL_reg_immRot";}
#endif
};

class negL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
public:
  negL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negL_reg_reg";}
#endif
};

class mulI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulI; }
public:
  mulI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_reg_reg";}
#endif
};

class mulL_lo1_hi2Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_lo1_hi2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  mulL_lo1_hi2Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_lo1_hi2Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_lo1_hi2";}
#endif
};

class mulL_hi1_lo2Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_hi1_lo2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_hi1_lo2Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_hi1_lo2Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_hi1_lo2";}
#endif
};

class mulL_lo1_lo2Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_lo1_lo2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_lo1_lo2Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_lo1_lo2Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_lo1_lo2";}
#endif
};

class mulL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_reg_reg_rule; }
  virtual int            ideal_Opcode() const { return Op_MulL; }
public:
  mulL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_reg_reg";}
#endif
};

class divI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivI; }
public:
  divI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divI_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divI_reg_reg";}
#endif
};

class divL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivL; }
public:
  divL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_has_call); }
  virtual uint           size_of() const { return sizeof(divL_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divL_reg_reg";}
#endif
};

class modI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModI; }
public:
  modI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modI_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modI_reg_reg";}
#endif
};

class modL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModL; }
public:
  modL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_has_call); }
  virtual uint           size_of() const { return sizeof(modL_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modL_reg_reg";}
#endif
};

class shlI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftI; }
public:
  shlI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlI_reg_reg";}
#endif
};

class shlI_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlI_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftI; }
public:
  shlI_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlI_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlI_reg_imm5";}
#endif
};

class shlL_reg_reg_merge_hiNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_reg_reg_merge_hi_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_reg_reg_merge_hiNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_reg_reg_merge_hiNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_reg_reg_merge_hi";}
#endif
};

class shlL_reg_reg_merge_loNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_reg_reg_merge_lo_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_reg_reg_merge_loNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_reg_reg_merge_loNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_reg_reg_merge_lo";}
#endif
};

class shlL_reg_reg_overlapNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_reg_reg_overlap_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  shlL_reg_reg_overlapNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_reg_reg_overlapNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_reg_reg_overlap";}
#endif
};

class shlL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_reg_reg_rule; }
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
public:
  shlL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_reg_reg";}
#endif
};

class shlL_reg_imm6Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_reg_imm6_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
public:
  shlL_reg_imm6Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_reg_imm6Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_reg_imm6";}
#endif
};

class shlL_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
public:
  shlL_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_reg_imm5";}
#endif
};

class sarI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
public:
  sarI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_reg_reg";}
#endif
};

class sarI_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
public:
  sarI_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_reg_imm5";}
#endif
};

class sarL_reg_reg_merge_loNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_reg_reg_merge_lo_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarL_reg_reg_merge_loNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_reg_reg_merge_loNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_reg_reg_merge_lo";}
#endif
};

class sarL_reg_reg_merge_hiNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_reg_reg_merge_hi_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarL_reg_reg_merge_hiNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_reg_reg_merge_hiNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_reg_reg_merge_hi";}
#endif
};

class sarL_reg_reg_overlapNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_reg_reg_overlap_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  sarL_reg_reg_overlapNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_reg_reg_overlapNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_reg_reg_overlap";}
#endif
};

class sarL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_reg_reg_rule; }
  virtual int            ideal_Opcode() const { return Op_RShiftL; }
public:
  sarL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_reg_reg";}
#endif
};

class sarL_reg_imm6Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_reg_imm6_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftL; }
public:
  sarL_reg_imm6Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_reg_imm6Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_reg_imm6";}
#endif
};

class sarL_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftL; }
public:
  sarL_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_reg_imm5";}
#endif
};

class shrI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftI; }
public:
  shrI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrI_reg_reg";}
#endif
};

class shrI_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrI_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftI; }
public:
  shrI_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrI_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrI_reg_imm5";}
#endif
};

class shrL_reg_reg_merge_loNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_reg_merge_lo_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrL_reg_reg_merge_loNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_reg_merge_loNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_reg_merge_lo";}
#endif
};

class shrL_reg_reg_merge_hiNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_reg_merge_hi_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrL_reg_reg_merge_hiNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_reg_merge_hiNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_reg_merge_hi";}
#endif
};

class shrL_reg_reg_overlapNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_reg_overlap_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  shrL_reg_reg_overlapNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_reg_overlapNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_reg_overlap";}
#endif
};

class shrL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_reg_rule; }
  virtual int            ideal_Opcode() const { return Op_URShiftL; }
public:
  shrL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_reg";}
#endif
};

class shrL_reg_imm6Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_imm6_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftL; }
public:
  shrL_reg_imm6Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_imm6Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_imm6";}
#endif
};

class shrL_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftL; }
public:
  shrL_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_imm5";}
#endif
};

class shrP_reg_imm5Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrP_reg_imm5_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftI; }
public:
  shrP_reg_imm5Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrP_reg_imm5Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrP_reg_imm5";}
#endif
};

class addF_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
public:
  addF_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_reg_reg";}
#endif
};

class addD_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
public:
  addD_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_reg";}
#endif
};

class subF_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subF_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubF; }
public:
  subF_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subF_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subF_reg_reg";}
#endif
};

class subD_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subD_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
public:
  subD_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subD_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subD_reg_reg";}
#endif
};

class mulF_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
public:
  mulF_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulF_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg_reg";}
#endif
};

class mulD_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
public:
  mulD_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulD_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg_reg";}
#endif
};

class divF_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divF_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
public:
  divF_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divF_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divF_reg_reg";}
#endif
};

class divD_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divD_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivD; }
public:
  divD_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divD_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divD_reg_reg";}
#endif
};

class absD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return absD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AbsD; }
public:
  absD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(absD_regNode); }
  // Rematerialize absD_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "absD_reg";}
#endif
};

class absF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return absF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AbsF; }
public:
  absF_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(absF_regNode); }
  // Rematerialize absF_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "absF_reg";}
#endif
};

class negF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_NegF; }
public:
  negF_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negF_regNode); }
  // Rematerialize negF_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negF_reg";}
#endif
};

class negD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_NegD; }
public:
  negD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negD_regNode); }
  // Rematerialize negD_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negD_reg";}
#endif
};

class sqrtF_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtF_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
public:
  sqrtF_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sqrtF_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtF_reg_reg";}
#endif
};

class sqrtD_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtD_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SqrtD; }
public:
  sqrtD_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sqrtD_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtD_reg_reg";}
#endif
};

class andI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_reg_reg";}
#endif
};

class andshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshlI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshlI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshlI_reg_reg_reg";}
#endif
};

class andshlI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshlI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshlI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshlI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshlI_reg_reg_reg_0";}
#endif
};

class andshlI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshlI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshlI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshlI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshlI_reg_reg_imm";}
#endif
};

class andshlI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshlI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshlI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshlI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshlI_reg_reg_imm_0";}
#endif
};

class andsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andsarI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andsarI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andsarI_reg_reg_reg";}
#endif
};

class andsarI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andsarI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andsarI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andsarI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andsarI_reg_reg_reg_0";}
#endif
};

class andsarI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andsarI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andsarI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andsarI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andsarI_reg_reg_imm";}
#endif
};

class andsarI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andsarI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andsarI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andsarI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andsarI_reg_reg_imm_0";}
#endif
};

class andshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshrI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshrI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshrI_reg_reg_reg";}
#endif
};

class andshrI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshrI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshrI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshrI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshrI_reg_reg_reg_0";}
#endif
};

class andshrI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshrI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshrI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshrI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshrI_reg_reg_imm";}
#endif
};

class andshrI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andshrI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andshrI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andshrI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andshrI_reg_reg_imm_0";}
#endif
};

class andI_reg_limmNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_reg_limm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andI_reg_limmNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_reg_limmNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_reg_limm";}
#endif
};

class andI_reg_limmnNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_reg_limmn_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
public:
  andI_reg_limmnNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_reg_limmnNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_reg_limmn";}
#endif
};

class andL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
public:
  andL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andL_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andL_reg_reg";}
#endif
};

class andL_reg_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andL_reg_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
public:
  andL_reg_immRotNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andL_reg_immRotNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andL_reg_immRot";}
#endif
};

class orI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_reg_reg";}
#endif
};

class orshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshlI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshlI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshlI_reg_reg_reg";}
#endif
};

class orshlI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshlI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshlI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshlI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshlI_reg_reg_reg_0";}
#endif
};

class orshlI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshlI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshlI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshlI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshlI_reg_reg_imm";}
#endif
};

class orshlI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshlI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshlI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshlI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshlI_reg_reg_imm_0";}
#endif
};

class orsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orsarI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orsarI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orsarI_reg_reg_reg";}
#endif
};

class orsarI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orsarI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orsarI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orsarI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orsarI_reg_reg_reg_0";}
#endif
};

class orsarI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orsarI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orsarI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orsarI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orsarI_reg_reg_imm";}
#endif
};

class orsarI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orsarI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orsarI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orsarI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orsarI_reg_reg_imm_0";}
#endif
};

class orshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshrI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshrI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshrI_reg_reg_reg";}
#endif
};

class orshrI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshrI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshrI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshrI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshrI_reg_reg_reg_0";}
#endif
};

class orshrI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshrI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshrI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshrI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshrI_reg_reg_imm";}
#endif
};

class orshrI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orshrI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orshrI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orshrI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orshrI_reg_reg_imm_0";}
#endif
};

class orI_reg_limmNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_reg_limm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
public:
  orI_reg_limmNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_reg_limmNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_reg_limm";}
#endif
};

class orL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrL; }
public:
  orL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orL_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orL_reg_reg";}
#endif
};

class orL_reg_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orL_reg_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrL; }
public:
  orL_reg_immRotNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orL_reg_immRotNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orL_reg_immRot";}
#endif
};

class xorI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorI_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_reg_reg";}
#endif
};

class xorshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshlI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshlI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshlI_reg_reg_reg";}
#endif
};

class xorshlI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshlI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshlI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshlI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshlI_reg_reg_reg_0";}
#endif
};

class xorshlI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshlI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshlI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshlI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshlI_reg_reg_imm";}
#endif
};

class xorshlI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshlI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshlI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshlI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshlI_reg_reg_imm_0";}
#endif
};

class xorsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorsarI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorsarI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorsarI_reg_reg_reg";}
#endif
};

class xorsarI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorsarI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorsarI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorsarI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorsarI_reg_reg_reg_0";}
#endif
};

class xorsarI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorsarI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorsarI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorsarI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorsarI_reg_reg_imm";}
#endif
};

class xorsarI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorsarI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorsarI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorsarI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorsarI_reg_reg_imm_0";}
#endif
};

class xorshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshrI_reg_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshrI_reg_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshrI_reg_reg_reg";}
#endif
};

class xorshrI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshrI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshrI_reg_reg_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshrI_reg_reg_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshrI_reg_reg_reg_0";}
#endif
};

class xorshrI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshrI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshrI_reg_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshrI_reg_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshrI_reg_reg_imm";}
#endif
};

class xorshrI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorshrI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorshrI_reg_reg_imm_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorshrI_reg_reg_imm_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorshrI_reg_reg_imm_0";}
#endif
};

class xorI_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
public:
  xorI_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_reg_immNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_reg_imm";}
#endif
};

class xorL_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorL_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
public:
  xorL_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorL_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorL_reg_reg";}
#endif
};

class xorL_reg_immRotNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorL_reg_immRot_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
public:
  xorL_reg_immRotNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorL_reg_immRotNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorL_reg_immRot";}
#endif
};

class convI2BNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Conv2B; }
public:
  convI2BNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2B";}
#endif
};

class convP2BNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convP2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Conv2B; }
public:
  convP2BNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convP2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convP2B";}
#endif
};

class cmpLTMask_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpLTMask_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpLTMask; }
public:
  cmpLTMask_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpLTMask_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpLTMask_reg_reg";}
#endif
};

class cmpLTMask_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpLTMask_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpLTMask; }
public:
  cmpLTMask_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpLTMask_reg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpLTMask_reg_imm";}
#endif
};

class cadd_cmpLTMask3Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask3_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges() + opnd_array(3)->num_edges(); }
public:
  cadd_cmpLTMask3Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask3Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask3";}
#endif
};

class cadd_cmpLTMask3_1Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask3_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask3_1Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask3_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask3_1";}
#endif
};

class cadd_cmpLTMask3_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask3_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges() + opnd_array(3)->num_edges(); }
public:
  cadd_cmpLTMask3_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask3_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask3_0";}
#endif
};

class cadd_cmpLTMask3_2Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask3_2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask3_2Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask3_2Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask3_2";}
#endif
};

class cadd_cmpLTMask4Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask4_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges() + opnd_array(3)->num_edges(); }
public:
  cadd_cmpLTMask4Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask4Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask4";}
#endif
};

class cadd_cmpLTMask4_1Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask4_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask4_1Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask4_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask4_1";}
#endif
};

class cadd_cmpLTMask4_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask4_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges() + opnd_array(3)->num_edges(); }
public:
  cadd_cmpLTMask4_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask4_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask4_0";}
#endif
};

class cadd_cmpLTMask4_2Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask4_2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask4_2Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask4_2Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask4_2";}
#endif
};

class cadd_cmpLTMaskNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMaskNode() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMaskNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask";}
#endif
};

class cadd_cmpLTMask_1Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask_1Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask_1";}
#endif
};

class cadd_cmpLTMask_0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  cadd_cmpLTMask_0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask_0";}
#endif
};

class cadd_cmpLTMask_2Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask_2Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask_2Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask_2";}
#endif
};

class convD2F_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
public:
  convD2F_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convD2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2F_reg";}
#endif
};

class convD2I_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2I_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2I; }
public:
  convD2I_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convD2I_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2I_reg_reg";}
#endif
};

class convD2L_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2L; }
public:
  convD2L_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_has_call); }
  virtual uint           size_of() const { return sizeof(convD2L_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2L_reg";}
#endif
};

class convF2D_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2D_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2D; }
public:
  convF2D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convF2D_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2D_reg";}
#endif
};

class convF2I_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2I_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2I; }
public:
  convF2I_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convF2I_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2I_reg_reg";}
#endif
};

class convF2L_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2L; }
public:
  convF2L_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_has_call); }
  virtual uint           size_of() const { return sizeof(convF2L_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2L_reg";}
#endif
};

class convI2D_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2D_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2D; }
public:
  convI2D_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2D_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2D_reg_reg";}
#endif
};

class convI2F_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2F_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
public:
  convI2F_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2F_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2F_reg_reg";}
#endif
};

class convI2L_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
public:
  convI2L_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2L_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2L_reg";}
#endif
};

class convI2L_reg_zexNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2L_reg_zex_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
public:
  convI2L_reg_zexNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2L_reg_zexNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2L_reg_zex";}
#endif
};

class zerox_longNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return zerox_long_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
public:
  zerox_longNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(zerox_longNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "zerox_long";}
#endif
};

class MoveF2I_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveF2I_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveF2I; }
public:
  MoveF2I_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveF2I_reg_regNode); }
  // Rematerialize MoveF2I_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveF2I_reg_reg";}
#endif
};

class MoveI2F_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveI2F_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveI2F; }
public:
  MoveI2F_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveI2F_reg_regNode); }
  // Rematerialize MoveI2F_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveI2F_reg_reg";}
#endif
};

class MoveD2L_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveD2L_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveD2L; }
public:
  MoveD2L_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveD2L_reg_regNode); }
  // Rematerialize MoveD2L_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveD2L_reg_reg";}
#endif
};

class MoveL2D_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveL2D_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveL2D; }
public:
  MoveL2D_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveL2D_reg_regNode); }
  // Rematerialize MoveL2D_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveL2D_reg_reg";}
#endif
};

class loadConI_x43300000Node : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI_x43300000_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  loadConI_x43300000Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadConI_x43300000Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI_x43300000";}
#endif
};

class loadConI_x41f00000Node : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI_x41f00000_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  loadConI_x41f00000Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadConI_x41f00000Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI_x41f00000";}
#endif
};

class loadConI_x0Node : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI_x0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  loadConI_x0Node() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadConI_x0Node); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI_x0";}
#endif
};

class regDHi_regDLo_to_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return regDHi_regDLo_to_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  regDHi_regDLo_to_regDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(regDHi_regDLo_to_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "regDHi_regDLo_to_regD";}
#endif
};

class convI2D_regDHi_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2D_regDHi_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  convI2D_regDHi_regDNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2D_regDHi_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize convI2D_regDHi_regD
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2D_regDHi_regD";}
#endif
};

class addD_regD_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_regD_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  addD_regD_regDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_regD_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_regD_regD";}
#endif
};

class subD_regD_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subD_regD_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  subD_regD_regDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subD_regD_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subD_regD_regD";}
#endif
};

class mulD_regD_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_regD_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  mulD_regD_regDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulD_regD_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_regD_regD";}
#endif
};

class regL_to_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return regL_to_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  regL_to_regDNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(regL_to_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize regL_to_regD
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "regL_to_regD";}
#endif
};

class regI_regI_to_regDNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return regI_regI_to_regD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  regI_regI_to_regDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(regI_regI_to_regDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "regI_regI_to_regD";}
#endif
};

class convL2D_reg_slow_fxtofNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2D_reg_slow_fxtof_rule; }
  virtual int            ideal_Opcode() const { return Op_ConvL2D; }
public:
  convL2D_reg_slow_fxtofNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2D_reg_slow_fxtofNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2D_reg_slow_fxtof";}
#endif
};

class convL2I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  convL2I_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2I_reg";}
#endif
};

class shrL_reg_imm6_L2INode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_reg_imm6_L2I_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  shrL_reg_imm6_L2INode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_reg_imm6_L2INode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_reg_imm6_L2I";}
#endif
};

class compI_iRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compI_iReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  compI_iRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compI_iRegNode); }
  // Rematerialize compI_iReg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compI_iReg";}
#endif
};

class compU_iRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compU_iReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpU; }
public:
  compU_iRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compU_iRegNode); }
  // Rematerialize compU_iReg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compU_iReg";}
#endif
};

class compI_iReg_immnegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compI_iReg_immneg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  compI_iReg_immnegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compI_iReg_immnegNode); }
  // Rematerialize compI_iReg_immneg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compI_iReg_immneg";}
#endif
};

class compI_iReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compI_iReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  compI_iReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compI_iReg_immNode); }
  // Rematerialize compI_iReg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compI_iReg_imm";}
#endif
};

class testI_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testI_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testI_reg_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testI_reg_regNode); }
  // Rematerialize testI_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testI_reg_reg";}
#endif
};

class testshlI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshlI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshlI_reg_reg_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshlI_reg_reg_regNode); }
  // Rematerialize testshlI_reg_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshlI_reg_reg_reg";}
#endif
};

class testshlI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshlI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshlI_reg_reg_reg_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshlI_reg_reg_reg_0Node); }
  // Rematerialize testshlI_reg_reg_reg_0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshlI_reg_reg_reg_0";}
#endif
};

class testshlI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshlI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshlI_reg_reg_immNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshlI_reg_reg_immNode); }
  // Rematerialize testshlI_reg_reg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshlI_reg_reg_imm";}
#endif
};

class testshlI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshlI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshlI_reg_reg_imm_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshlI_reg_reg_imm_0Node); }
  // Rematerialize testshlI_reg_reg_imm_0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshlI_reg_reg_imm_0";}
#endif
};

class testsarI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testsarI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testsarI_reg_reg_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testsarI_reg_reg_regNode); }
  // Rematerialize testsarI_reg_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testsarI_reg_reg_reg";}
#endif
};

class testsarI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testsarI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testsarI_reg_reg_reg_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testsarI_reg_reg_reg_0Node); }
  // Rematerialize testsarI_reg_reg_reg_0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testsarI_reg_reg_reg_0";}
#endif
};

class testsarI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testsarI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testsarI_reg_reg_immNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testsarI_reg_reg_immNode); }
  // Rematerialize testsarI_reg_reg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testsarI_reg_reg_imm";}
#endif
};

class testsarI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testsarI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testsarI_reg_reg_imm_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testsarI_reg_reg_imm_0Node); }
  // Rematerialize testsarI_reg_reg_imm_0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testsarI_reg_reg_imm_0";}
#endif
};

class testshrI_reg_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshrI_reg_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshrI_reg_reg_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshrI_reg_reg_regNode); }
  // Rematerialize testshrI_reg_reg_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshrI_reg_reg_reg";}
#endif
};

class testshrI_reg_reg_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshrI_reg_reg_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshrI_reg_reg_reg_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshrI_reg_reg_reg_0Node); }
  // Rematerialize testshrI_reg_reg_reg_0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshrI_reg_reg_reg_0";}
#endif
};

class testshrI_reg_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshrI_reg_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshrI_reg_reg_immNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshrI_reg_reg_immNode); }
  // Rematerialize testshrI_reg_reg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshrI_reg_reg_imm";}
#endif
};

class testshrI_reg_reg_imm_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testshrI_reg_reg_imm_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testshrI_reg_reg_imm_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testshrI_reg_reg_imm_0Node); }
  // Rematerialize testshrI_reg_reg_imm_0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testshrI_reg_reg_imm_0";}
#endif
};

class testI_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testI_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testI_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testI_reg_immNode); }
  // Rematerialize testI_reg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testI_reg_imm";}
#endif
};

class compL_reg_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compL_reg_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  compL_reg_reg_LTGENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compL_reg_reg_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize compL_reg_reg_LTGE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compL_reg_reg_LTGE";}
#endif
};

class compL_reg_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compL_reg_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  compL_reg_reg_EQNENode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compL_reg_reg_EQNENode); }
  // Rematerialize compL_reg_reg_EQNE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compL_reg_reg_EQNE";}
#endif
};

class compL_reg_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compL_reg_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  compL_reg_reg_LEGTNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compL_reg_reg_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize compL_reg_reg_LEGT
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compL_reg_reg_LEGT";}
#endif
};

class compL_reg_con_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compL_reg_con_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  compL_reg_con_LTGENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compL_reg_con_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize compL_reg_con_LTGE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compL_reg_con_LTGE";}
#endif
};

class compL_reg_con_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compL_reg_con_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  compL_reg_con_EQNENode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compL_reg_con_EQNENode); }
  // Rematerialize compL_reg_con_EQNE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compL_reg_con_EQNE";}
#endif
};

class compL_reg_con_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compL_reg_con_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  compL_reg_con_LEGTNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compL_reg_con_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize compL_reg_con_LEGT
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compL_reg_con_LEGT";}
#endif
};

class compU_iReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compU_iReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpU; }
public:
  compU_iReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compU_iReg_immNode); }
  // Rematerialize compU_iReg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compU_iReg_imm";}
#endif
};

class compP_iRegPNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compP_iRegP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
public:
  compP_iRegPNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compP_iRegPNode); }
  // Rematerialize compP_iRegP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compP_iRegP";}
#endif
};

class compP_iRegP_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compP_iRegP_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc() const;
public:
  compP_iRegP_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compP_iRegP_immNode); }
  // Rematerialize compP_iRegP_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compP_iRegP_imm";}
#endif
};

class cmovI_reg_ltNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_reg_lt_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cmovI_reg_ltNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_reg_ltNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_reg_lt";}
#endif
};

class minI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return minI_eReg_rule; }
  virtual int            ideal_Opcode() const { return Op_MinI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  minI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(minI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "minI_eReg";}
#endif
};

class cmovI_reg_gtNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_reg_gt_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cmovI_reg_gtNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_reg_gtNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_reg_gt";}
#endif
};

class maxI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return maxI_eReg_rule; }
  virtual int            ideal_Opcode() const { return Op_MaxI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  maxI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(maxI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "maxI_eReg";}
#endif
};

class cmpF_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
public:
  cmpF_ccNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize cmpF_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_cc";}
#endif
};

class cmpF0_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF0_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
  virtual int            reloc() const;
public:
  cmpF0_ccNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF0_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize cmpF0_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF0_cc";}
#endif
};

class cmpD_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
public:
  cmpD_ccNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize cmpD_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_cc";}
#endif
};

class cmpD0_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD0_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
  virtual int            reloc() const;
public:
  cmpD0_ccNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD0_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize cmpD0_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD0_cc";}
#endif
};

class cmpF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF3; }
public:
  cmpF_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_reg";}
#endif
};

class cmpF0_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF0_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF3; }
  virtual int            reloc() const;
public:
  cmpF0_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF0_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF0_reg";}
#endif
};

class cmpD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD3; }
public:
  cmpD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_reg";}
#endif
};

class cmpD0_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD0_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD3; }
  virtual int            reloc() const;
public:
  cmpD0_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD0_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD0_reg";}
#endif
};

class jumpXtndNode : public MachConstantNode { 
private:
  MachOper *_opnd_array[3];
  GrowableArray<Label*> _index2label;
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual void           add_case_label(int index_num, Label* blockLabel) {
    _index2label.at_put_grow(index_num, blockLabel);
  }
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jumpXtnd_rule; }
  virtual void           eval_constant(Compile* C);
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Jump; }
  virtual uint           oper_input_base() const { return 1; }
public:
  jumpXtndNode() : _index2label(MinJumpTableSize*2) {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(jumpXtndNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jumpXtnd";}
#endif
};

class branchNode : public MachGotoNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branch_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Goto; }
  virtual uint           oper_input_base() const { return 1; }
public:
  branchNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branch";}
#endif
};

class branchConNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchCon_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchConNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchConNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchCon";}
#endif
};

class branchCon_EQNELTGENode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchCon_EQNELTGE_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchCon_EQNELTGENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchCon_EQNELTGENode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchCon_EQNELTGE";}
#endif
};

class branchConUNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchConU_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchConUNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchConUNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchConU";}
#endif
};

class branchConPNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchConP_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchConPNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchConPNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchConP";}
#endif
};

class branchConL_LTGENode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchConL_LTGE_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchConL_LTGENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchConL_LTGENode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchConL_LTGE";}
#endif
};

class branchConL_EQNENode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchConL_EQNE_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchConL_EQNENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchConL_EQNENode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchConL_EQNE";}
#endif
};

class branchConL_LEGTNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchConL_LEGT_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchConL_LEGTNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchConL_LEGTNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchConL_LEGT";}
#endif
};

class branchLoopEndNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return branchLoopEnd_rule; }
  virtual void           label_set( Label* label, uint block_num );
  virtual void           save_label( Label** label, uint* block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  branchLoopEndNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(branchLoopEndNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "branchLoopEnd";}
#endif
};

class cmpL3_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL3_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL3; }
public:
  cmpL3_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL3_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL3_reg_reg";}
#endif
};

class cmovLL_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLL_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_reg_LTGE";}
#endif
};

class cmovLL_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLL_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_reg_EQNE";}
#endif
};

class cmovLL_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLL_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_reg_LEGT";}
#endif
};

class cmovLL_imm_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_imm_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLL_imm_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_imm_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_imm_LTGE";}
#endif
};

class cmovLL_imm_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_imm_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLL_imm_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_imm_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_imm_EQNE";}
#endif
};

class cmovLL_imm_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_imm_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovLL_imm_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_imm_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_imm_LEGT";}
#endif
};

class cmovIL_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIL_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIL_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIL_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIL_reg_LTGE";}
#endif
};

class cmovIL_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIL_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIL_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIL_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIL_reg_EQNE";}
#endif
};

class cmovIL_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIL_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIL_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIL_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIL_reg_LEGT";}
#endif
};

class cmovIL_imm_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIL_imm_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIL_imm_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIL_imm_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIL_imm_LTGE";}
#endif
};

class cmovIL_imm_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIL_imm_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIL_imm_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIL_imm_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIL_imm_EQNE";}
#endif
};

class cmovIL_imm_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovIL_imm_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovIL_imm_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovIL_imm_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovIL_imm_LEGT";}
#endif
};

class cmovPL_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPL_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPL_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPL_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPL_reg_LTGE";}
#endif
};

class cmovPL_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPL_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPL_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPL_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPL_reg_EQNE";}
#endif
};

class cmovPL_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPL_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPL_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPL_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPL_reg_LEGT";}
#endif
};

class cmovPL_imm_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPL_imm_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPL_imm_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPL_imm_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPL_imm_LTGE";}
#endif
};

class cmovPL_imm_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPL_imm_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPL_imm_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPL_imm_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPL_imm_EQNE";}
#endif
};

class cmovPL_imm_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPL_imm_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc() const;
public:
  cmovPL_imm_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPL_imm_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPL_imm_LEGT";}
#endif
};

class cmovFL_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFL_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFL_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFL_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFL_reg_LTGE";}
#endif
};

class cmovFL_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFL_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFL_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFL_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFL_reg_EQNE";}
#endif
};

class cmovFL_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFL_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFL_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFL_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFL_reg_LEGT";}
#endif
};

class cmovDL_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDL_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDL_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDL_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDL_reg_LTGE";}
#endif
};

class cmovDL_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDL_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDL_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDL_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDL_reg_EQNE";}
#endif
};

class cmovDL_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDL_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDL_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDL_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDL_reg_LEGT";}
#endif
};

class safePoint_pollNode : public MachSafePointNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return safePoint_poll_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SafePoint; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 5; }
public:
  safePoint_pollNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(safePoint_pollNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "safePoint_poll";}
#endif
};

class CallStaticJavaDirectNode : public MachCallStaticJavaNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallStaticJavaDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallStaticJava; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallStaticJavaDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CallStaticJavaDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallStaticJavaDirect";}
#endif
};

class CallStaticJavaHandleNode : public MachCallStaticJavaNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallStaticJavaHandle_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallStaticJava; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallStaticJavaHandleNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CallStaticJavaHandleNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallStaticJavaHandle";}
#endif
};

class CallDynamicJavaDirectNode : public MachCallDynamicJavaNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallDynamicJavaDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallDynamicJava; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallDynamicJavaDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CallDynamicJavaDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallDynamicJavaDirect";}
#endif
};

class CallRuntimeDirectNode : public MachCallRuntimeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallRuntimeDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallRuntime; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallRuntimeDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CallRuntimeDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallRuntimeDirect";}
#endif
};

class CallLeafDirectNode : public MachCallLeafNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallLeafDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallLeaf; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallLeafDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CallLeafDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallLeafDirect";}
#endif
};

class CallLeafNoFPDirectNode : public MachCallLeafNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallLeafNoFPDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallLeafNoFP; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallLeafNoFPDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CallLeafNoFPDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallLeafNoFPDirect";}
#endif
};

class TailCalljmpIndNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return TailCalljmpInd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_TailCall; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 5; }
public:
  TailCalljmpIndNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(TailCalljmpIndNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "TailCalljmpInd";}
#endif
};

class RetNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Ret_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Return; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 5; }
public:
  RetNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(RetNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Ret";}
#endif
};

class tailjmpIndNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return tailjmpInd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_TailJump; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 5; }
public:
  tailjmpIndNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(tailjmpIndNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "tailjmpInd";}
#endif
};

class CreateExceptionNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CreateException_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CreateEx; }
  virtual uint           oper_input_base() const { return 1; }
public:
  CreateExceptionNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CreateExceptionNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CreateException";}
#endif
};

class RethrowExceptionNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return RethrowException_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Rethrow; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 5; }
public:
  RethrowExceptionNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(RethrowExceptionNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "RethrowException";}
#endif
};

class ShouldNotReachHereNode : public MachHaltNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return ShouldNotReachHere_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Halt; }
  virtual uint           oper_input_base() const { return 5; }
public:
  ShouldNotReachHereNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(ShouldNotReachHereNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "ShouldNotReachHere";}
#endif
};

class partialSubtypeCheckNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return partialSubtypeCheck_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PartialSubtypeCheck; }
public:
  partialSubtypeCheckNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(partialSubtypeCheckNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "partialSubtypeCheck";}
#endif
};

class cmpFastLockNode : public MachFastLockNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpFastLock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_FastLock; }
  virtual uint           oper_input_base() const { return 1; }
public:
  cmpFastLockNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpFastLockNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize cmpFastLock
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpFastLock";}
#endif
};

class cmpFastUnlockNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpFastUnlock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_FastUnlock; }
public:
  cmpFastUnlockNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpFastUnlockNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize cmpFastUnlock
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpFastUnlock";}
#endif
};

class clear_arrayNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return clear_array_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ClearArray; }
  virtual uint           oper_input_base() const { return 2; }
public:
  clear_arrayNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(clear_arrayNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "clear_array";}
#endif
};

class countLeadingZerosINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countLeadingZerosI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountLeadingZerosI; }
public:
  countLeadingZerosINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countLeadingZerosINode); }
  // Rematerialize countLeadingZerosI
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countLeadingZerosI";}
#endif
};

class countLeadingZerosLNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countLeadingZerosL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountLeadingZerosL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  countLeadingZerosLNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countLeadingZerosLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countLeadingZerosL";}
#endif
};

class countTrailingZerosINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countTrailingZerosI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountTrailingZerosI; }
public:
  countTrailingZerosINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countTrailingZerosINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countTrailingZerosI";}
#endif
};

class countTrailingZerosLNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countTrailingZerosL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountTrailingZerosL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  countTrailingZerosLNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countTrailingZerosLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countTrailingZerosL";}
#endif
};

class popCountINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return popCountI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PopCountI; }
public:
  popCountINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(popCountINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "popCountI";}
#endif
};

class popCountLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return popCountL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PopCountL; }
public:
  popCountLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(popCountLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "popCountL";}
#endif
};

class bytes_reverse_intNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_int_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesI; }
public:
  bytes_reverse_intNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_intNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_int";}
#endif
};

class bytes_reverse_longNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_long_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  bytes_reverse_longNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_longNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_long";}
#endif
};

class bytes_reverse_unsigned_shortNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_unsigned_short_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesUS; }
public:
  bytes_reverse_unsigned_shortNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_unsigned_shortNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_unsigned_short";}
#endif
};

class bytes_reverse_shortNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_short_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesS; }
public:
  bytes_reverse_shortNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_shortNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_short";}
#endif
};

class loadV8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadV8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadVector; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadV8Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadV8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadV8";}
#endif
};

class loadV16Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadV16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadVector; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadV16Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadV16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadV16";}
#endif
};

class storeV8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeV8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreVector; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeV8Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeV8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeV8";}
#endif
};

class storeV16Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeV16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreVector; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeV16Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeV16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeV16";}
#endif
};

class Repl8B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_reg";}
#endif
};

class Repl8B_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl8B_reg_simdNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_reg_simd";}
#endif
};

class Repl16B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl16B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl16B_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl16B_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl16B_reg";}
#endif
};

class Repl8B_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl8B_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_immINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_immI";}
#endif
};

class Repl8B_immU8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_immU8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl8B_immU8Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_immU8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_immU8";}
#endif
};

class Repl16B_immU8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl16B_immU8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl16B_immU8Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl16B_immU8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl16B_immU8";}
#endif
};

class Repl4S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_reg";}
#endif
};

class Repl4S_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4S_reg_simdNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_reg_simd";}
#endif
};

class Repl8S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl8S_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8S_reg";}
#endif
};

class Repl4S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_immINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_immI";}
#endif
};

class Repl4S_immU8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_immU8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4S_immU8Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_immU8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_immU8";}
#endif
};

class Repl8S_immU8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8S_immU8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl8S_immU8Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8S_immU8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8S_immU8";}
#endif
};

class Repl2I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2I_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_reg";}
#endif
};

class Repl4I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4I_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4I_reg";}
#endif
};

class Repl2I_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2I_reg_simdNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_reg_simd";}
#endif
};

class Repl4I_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4I_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4I_reg_simdNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4I_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4I_reg_simd";}
#endif
};

class Repl2I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_immINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_immI";}
#endif
};

class Repl2I_immU8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_immU8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2I_immU8Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_immU8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_immU8";}
#endif
};

class Repl4I_immU8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4I_immU8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4I_immU8Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4I_immU8Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4I_immU8";}
#endif
};

class Repl2L_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2L_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2L_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2L_reg";}
#endif
};

class Repl2F_regINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_regI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2F_regINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_regINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_regI";}
#endif
};

class Repl2F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_reg_vfp_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2F_reg_vfpNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_reg_vfpNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_reg_vfp";}
#endif
};

class Repl2F_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2F_reg_simdNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_reg_simd";}
#endif
};

class Repl4F_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4F_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4F_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4F_reg";}
#endif
};

class Repl4F_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4F_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl4F_reg_simdNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4F_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4F_reg_simd";}
#endif
};

class Repl2F_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateF; }
  virtual int            reloc() const;
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2F_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_immINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_immI";}
#endif
};

class Repl2D_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2D_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReplicateD; }
  virtual uint           oper_input_base() const { return 1; }
public:
  Repl2D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2D_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2D_reg";}
#endif
};

class vadd8B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd8B_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd8B_reg";}
#endif
};

class vadd16B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd16B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd16B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd16B_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd16B_reg";}
#endif
};

class vadd4S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd4S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd4S_reg";}
#endif
};

class vadd8S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd8S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd8S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd8S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd8S_reg";}
#endif
};

class vadd2I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd2I_reg";}
#endif
};

class vadd4I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd4I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd4I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd4I_reg";}
#endif
};

class vadd2L_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd2L_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd2L_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd2L_reg";}
#endif
};

class vadd2F_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd2F_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd2F_reg";}
#endif
};

class vadd2F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd2F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd2F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd2F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd2F_reg_vfp";}
#endif
};

class vadd4F_reg_simdNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd4F_reg_simd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd4F_reg_simdNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd4F_reg_simdNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd4F_reg_simd";}
#endif
};

class vadd4F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd4F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd4F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd4F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd4F_reg_vfp";}
#endif
};

class vadd2D_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vadd2D_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddVD; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vadd2D_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vadd2D_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vadd2D_reg_vfp";}
#endif
};

class vsub8B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub8B_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub8B_reg";}
#endif
};

class vsub16B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub16B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub16B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub16B_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub16B_reg";}
#endif
};

class vsub4S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub4S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub4S_reg";}
#endif
};

class vsub16S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub16S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub16S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub16S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub16S_reg";}
#endif
};

class vsub2I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub2I_reg";}
#endif
};

class vsub4I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub4I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub4I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub4I_reg";}
#endif
};

class vsub2L_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub2L_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub2L_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub2L_reg";}
#endif
};

class vsub2F_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub2F_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub2F_reg";}
#endif
};

class vsub2F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub2F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub2F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub2F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub2F_reg_vfp";}
#endif
};

class vsub4F_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub4F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub4F_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub4F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub4F_reg";}
#endif
};

class vsub4F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub4F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub4F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub4F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub4F_reg_vfp";}
#endif
};

class vsub2D_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsub2D_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubVD; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsub2D_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsub2D_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsub2D_reg_vfp";}
#endif
};

class vmul4S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul4S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul4S_reg";}
#endif
};

class vmul8S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul8S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul8S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul8S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul8S_reg";}
#endif
};

class vmul2I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul2I_reg";}
#endif
};

class vmul4I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul4I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul4I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul4I_reg";}
#endif
};

class vmul2F_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul2F_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul2F_reg";}
#endif
};

class vmul2F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul2F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul2F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul2F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul2F_reg_vfp";}
#endif
};

class vmul4F_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul4F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul4F_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul4F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul4F_reg";}
#endif
};

class vmul4F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul4F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul4F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul4F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul4F_reg_vfp";}
#endif
};

class vmul2D_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vmul2D_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulVD; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vmul2D_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vmul2D_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vmul2D_reg_vfp";}
#endif
};

class vdiv2F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vdiv2F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vdiv2F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vdiv2F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vdiv2F_reg_vfp";}
#endif
};

class vdiv4F_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vdiv4F_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivVF; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vdiv4F_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vdiv4F_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vdiv4F_reg_vfp";}
#endif
};

class vdiv2D_reg_vfpNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vdiv2D_reg_vfp_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivVD; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vdiv2D_reg_vfpNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vdiv2D_reg_vfpNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vdiv2D_reg_vfp";}
#endif
};

class vneg8B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vneg8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vneg8B_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vneg8B_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize vneg8B_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vneg8B_reg";}
#endif
};

class vneg16B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vneg16B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vneg16B_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vneg16B_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  // Rematerialize vneg16B_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vneg16B_reg";}
#endif
};

class vslcntDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vslcntD_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftCntV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vslcntDNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vslcntDNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  // Rematerialize vslcntD
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vslcntD";}
#endif
};

class vslcntXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vslcntX_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftCntV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vslcntXNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vslcntXNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  // Rematerialize vslcntX
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vslcntX";}
#endif
};

class vsrcntDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrcntD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftCntV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrcntDNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrcntDNode); }
  // Rematerialize vsrcntD
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrcntD";}
#endif
};

class vsrcntXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrcntX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftCntV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrcntXNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrcntXNode); }
  // Rematerialize vsrcntX
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrcntX";}
#endif
};

class vsh8B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh8B_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh8B_reg";}
#endif
};

class vsh16B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh16B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh16B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh16B_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh16B_reg";}
#endif
};

class vsh4S_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh4S_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh4S_reg";}
#endif
};

class vsh8S_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh8S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh8S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh8S_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh8S_reg";}
#endif
};

class vsh2I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh2I_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh2I_reg";}
#endif
};

class vsh4I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh4I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh4I_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh4I_reg";}
#endif
};

class vsh2L_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsh2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsh2L_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsh2L_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsh2L_reg";}
#endif
};

class vsl8B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl8B_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl8B_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl8B_reg";}
#endif
};

class vsl16B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl16B_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl16B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl16B_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl16B_reg";}
#endif
};

class vsl8B_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl8B_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl8B_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl8B_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl8B_immI";}
#endif
};

class vsl16B_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl16B_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl16B_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl16B_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl16B_immI";}
#endif
};

class vsl4S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl4S_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl4S_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl4S_reg";}
#endif
};

class vsl4S_reg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl4S_reg_0_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl4S_reg_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl4S_reg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl4S_reg_0";}
#endif
};

class vsl8S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl8S_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl8S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl8S_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl8S_reg";}
#endif
};

class vsl8S_reg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl8S_reg_0_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl8S_reg_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl8S_reg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl8S_reg_0";}
#endif
};

class vsl4S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl4S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl4S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl4S_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl4S_immI";}
#endif
};

class vsl8S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl8S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl8S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl8S_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl8S_immI";}
#endif
};

class vsl2I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl2I_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl2I_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl2I_reg";}
#endif
};

class vsl2I_reg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl2I_reg_0_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl2I_reg_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl2I_reg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl2I_reg_0";}
#endif
};

class vsl4I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl4I_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl4I_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl4I_reg";}
#endif
};

class vsl4I_reg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl4I_reg_0_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl4I_reg_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl4I_reg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl4I_reg_0";}
#endif
};

class vsl2I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl2I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl2I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl2I_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl2I_immI";}
#endif
};

class vsl4I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl4I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl4I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl4I_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl4I_immI";}
#endif
};

class vsl2L_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl2L_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl2L_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl2L_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl2L_reg";}
#endif
};

class vsl2L_reg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl2L_reg_0_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl2L_reg_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl2L_reg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl2L_reg_0";}
#endif
};

class vsl2L_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsl2L_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsl2L_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsl2L_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsl2L_immI";}
#endif
};

class vsrl4S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl4S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl4S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl4S_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl4S_immI";}
#endif
};

class vsrl8S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl8S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl8S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl8S_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl8S_immI";}
#endif
};

class vsrl2I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl2I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl2I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl2I_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl2I_immI";}
#endif
};

class vsrl4I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl4I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl4I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl4I_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl4I_immI";}
#endif
};

class vsrl2L_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl2L_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl2L_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl2L_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl2L_immI";}
#endif
};

class vsha8B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha8B_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha8B_reg";}
#endif
};

class vsha16B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha16B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha16B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha16B_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha16B_reg";}
#endif
};

class vsha4S_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha4S_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha4S_reg";}
#endif
};

class vsha8S_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha8S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha8S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha8S_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha8S_reg";}
#endif
};

class vsha2I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha2I_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha2I_reg";}
#endif
};

class vsha4I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha4I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha4I_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha4I_reg";}
#endif
};

class vsha2L_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsha2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
public:
  vsha2L_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsha2L_regNode); }
  friend MachNode *State::MachNodeGenerator(int opcode);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsha2L_reg";}
#endif
};

class vsra8B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra8B_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra8B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra8B_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra8B_reg";}
#endif
};

class vsrl16B_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl16B_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl16B_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl16B_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl16B_reg";}
#endif
};

class vsrl8B_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl8B_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl8B_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl8B_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl8B_immI";}
#endif
};

class vsrl16B_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsrl16B_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVB; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsrl16B_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsrl16B_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsrl16B_immI";}
#endif
};

class vsra4S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra4S_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra4S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra4S_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra4S_reg";}
#endif
};

class vsra8S_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra8S_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra8S_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra8S_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra8S_reg";}
#endif
};

class vsra4S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra4S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra4S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra4S_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra4S_immI";}
#endif
};

class vsra8S_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra8S_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVS; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra8S_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra8S_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra8S_immI";}
#endif
};

class vsra2I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra2I_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra2I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra2I_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra2I_reg";}
#endif
};

class vsra4I_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra4I_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra4I_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra4I_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra4I_reg";}
#endif
};

class vsra2I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra2I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra2I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra2I_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra2I_immI";}
#endif
};

class vsra4I_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra4I_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVI; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra4I_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra4I_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra4I_immI";}
#endif
};

class vsra2L_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra2L_reg_rule; }
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra2L_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra2L_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra2L_reg";}
#endif
};

class vsra2L_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vsra2L_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftVL; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vsra2L_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vsra2L_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vsra2L_immI";}
#endif
};

class vandDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vandD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vandDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vandDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vandD";}
#endif
};

class vandXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vandX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vandXNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vandXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vandX";}
#endif
};

class vorDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vorD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vorDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vorDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vorD";}
#endif
};

class vorXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vorX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vorXNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vorXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vorX";}
#endif
};

class vxorDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vxorD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vxorDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vxorDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vxorD";}
#endif
};

class vxorXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    return _opnd_array[operand_index];
  }
  void      set_opnd_array(uint operand_index, MachOper *operand) {
    assert(operand_index < _num_opnds, "invalid _opnd_array index");
    _opnd_array[operand_index] = operand;
  }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return vxorX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorV; }
  virtual uint           oper_input_base() const { return 1; }
public:
  vxorXNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(vxorXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "vxorX";}
#endif
};

//HeaderForm

#line 325 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm_32.ad"

// FIXME
const MachRegisterNumbers R_mem_copy_lo_num = R_S14_num;
const MachRegisterNumbers R_mem_copy_hi_num = R_S15_num;
const FloatRegister Rmemcopy = S14;
const MachRegisterNumbers R_hf_ret_lo_num = R_S0_num;
const MachRegisterNumbers R_hf_ret_hi_num = R_S1_num;

const MachRegisterNumbers R_Ricklass_num = R_R8_num;
const MachRegisterNumbers R_Rmethod_num  = R_R9_num;

#define LDR_DOUBLE "FLDD"
#define LDR_FLOAT  "FLDS"
#define STR_DOUBLE "FSTD"
#define STR_FLOAT  "FSTS"
#define LDR_64     "LDRD"
#define STR_64     "STRD"
#define LDR_32     "LDR"
#define STR_32     "STR"
#define MOV_DOUBLE "FCPYD"
#define MOV_FLOAT  "FCPYS"
#define FMSR       "FMSR"
#define FMRS       "FMRS"
#define LDREX      "ldrex "
#define STREX      "strex "

#define str_64     strd
#define ldr_64     ldrd
#define ldr_32     ldr
#define ldrex      ldrex
#define strex      strex

static inline bool is_memoryD(int offset) {
  return offset < 1024 && offset > -1024;
}

static inline bool is_memoryfp(int offset) {
  return offset < 1024 && offset > -1024;
}

static inline bool is_memoryI(int offset) {
  return offset < 4096 && offset > -4096;
}

static inline bool is_memoryP(int offset) {
  return offset < 4096 && offset > -4096;
}

static inline bool is_memoryHD(int offset) {
  return offset < 256 && offset > -256;
}

static inline bool is_aimm(int imm) {
  return AsmOperand::is_rotated_imm(imm);
}

static inline bool is_limmI(jint imm) {
  return AsmOperand::is_rotated_imm(imm);
}

static inline bool is_limmI_low(jint imm, int n) {
  int imml = imm & right_n_bits(n);
  return is_limmI(imml) || is_limmI(imm);
}

static inline int limmI_low(jint imm, int n) {
  int imml = imm & right_n_bits(n);
  return is_limmI(imml) ? imml : imm;
}


#line 21218 "ad_arm.hpp"


//HeaderForm

#line 54 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm.ad"

// Header information of the source block.
// Method declarations/definitions which are used outside
// the ad-scope can conveniently be defined here.
//
// To keep related declarations/definitions/uses close together,
// we switch between source %{ }% and source_hpp %{ }% freely as needed.

// Does destination need to be loaded in a register then passed to a
// branch instruction?
extern bool maybe_far_call(const CallNode *n);
extern bool maybe_far_call(const MachCallNode *n);
static inline bool cache_reachable() {
  return MacroAssembler::_cache_fully_reachable();
}

#ifdef AARCH64
#define ldr_32 ldr_w
#define str_32 str_w
#else
#define ldr_32 ldr
#define str_32 str
#define tst_32 tst
#define teq_32 teq
#endif
#if 1
extern bool PrintOptoAssembly;
#endif

class c2 {
public:
  static OptoRegPair return_value(int ideal_reg);
};

class CallStubImpl {

  //--------------------------------------------------------------
  //---<  Used for optimization in Compile::Shorten_branches  >---
  //--------------------------------------------------------------

 public:
  // Size of call trampoline stub.
  static uint size_call_trampoline() {
    return 0; // no call trampolines on this platform
  }

  // number of relocations needed by a call trampoline stub
  static uint reloc_call_trampoline() {
    return 0; // no call trampolines on this platform
  }
};

class HandlerImpl {

 public:

  static int emit_exception_handler(CodeBuffer &cbuf);
  static int emit_deopt_handler(CodeBuffer& cbuf);

  static uint size_exception_handler() {
#ifdef AARCH64
    // ldr_literal; br; (pad); <literal>
    return 3 * Assembler::InstructionSize + wordSize;
#else
    return ( 3 * 4 );
#endif
  }


  static uint size_deopt_handler() {
    return ( 9 * 4 );
  }

};


#line 21300 "ad_arm.hpp"


extern const char  register_save_policy[];
extern const char  c_reg_save_policy[];
extern const int   register_save_type[];

extern const int   reduceOp[];
extern const int   leftOp[];
extern const int   rightOp[];
extern const char *ruleName[];
extern const bool  swallowed[];
// Mapping from machine-independent opcode to boolean
// Flag cases where machine needs cloned values or instructions
extern const char must_clone[];


// Enumeration of register class names
enum machRegisterClass {
  INT_REG,
  R0_REGI,
  R1_REGI,
  R2_REGI,
  R3_REGI,
  R12_REGI,
  PTR_REG,
  SP_PTR_REG,
  R0_REGP,
  R1_REGP,
  R2_REGP,
  R4_REGP,
  REXCEPTION_REGP,
  RICKLASS_REGP,
  RMETHOD_REGP,
  RTHREAD_REGP,
  IP_REGP,
  LR_REGP,
  FP_REGP,
  LONG_REG,
  LONG_REG_ALIGN,
  R0R1_REGL,
  R2R3_REGL,
  INT_FLAGS,
  FLOAT_FLAGS,
  SFLT_REG,
  DFLT_REG,
  DFLT_LOW_REG,
  ACTUAL_DFLT_REG,
  S0_REGF,
  D0_REGD,
  D1_REGD,
  D2_REGD,
  D3_REGD,
  D4_REGD,
  D5_REGD,
  D6_REGD,
  D7_REGD,
  D16_REGD,
  D17_REGD,
  D18_REGD,
  D19_REGD,
  D20_REGD,
  D21_REGD,
  D22_REGD,
  D23_REGD,
  D24_REGD,
  D25_REGD,
  D26_REGD,
  D27_REGD,
  D28_REGD,
  D29_REGD,
  D30_REGD,
  D31_REGD,
  VECTORX_REG,
  STACK_SLOTS,
  _last_Mach_Reg_Class
};

// Register masks, one for each register class.
extern const RegMask _INT_REG_mask;
inline const RegMask &INT_REG_mask() { return _INT_REG_mask; }
extern const RegMask _R0_REGI_mask;
inline const RegMask &R0_REGI_mask() { return _R0_REGI_mask; }
extern const RegMask _R1_REGI_mask;
inline const RegMask &R1_REGI_mask() { return _R1_REGI_mask; }
extern const RegMask _R2_REGI_mask;
inline const RegMask &R2_REGI_mask() { return _R2_REGI_mask; }
extern const RegMask _R3_REGI_mask;
inline const RegMask &R3_REGI_mask() { return _R3_REGI_mask; }
extern const RegMask _R12_REGI_mask;
inline const RegMask &R12_REGI_mask() { return _R12_REGI_mask; }
extern const RegMask _PTR_REG_mask;
inline const RegMask &PTR_REG_mask() { return _PTR_REG_mask; }
extern const RegMask _SP_PTR_REG_mask;
inline const RegMask &SP_PTR_REG_mask() { return _SP_PTR_REG_mask; }
extern const RegMask _R0_REGP_mask;
inline const RegMask &R0_REGP_mask() { return _R0_REGP_mask; }
extern const RegMask _R1_REGP_mask;
inline const RegMask &R1_REGP_mask() { return _R1_REGP_mask; }
extern const RegMask _R2_REGP_mask;
inline const RegMask &R2_REGP_mask() { return _R2_REGP_mask; }
extern const RegMask _R4_REGP_mask;
inline const RegMask &R4_REGP_mask() { return _R4_REGP_mask; }
extern const RegMask _REXCEPTION_REGP_mask;
inline const RegMask &REXCEPTION_REGP_mask() { return _REXCEPTION_REGP_mask; }
extern const RegMask _RICKLASS_REGP_mask;
inline const RegMask &RICKLASS_REGP_mask() { return _RICKLASS_REGP_mask; }
extern const RegMask _RMETHOD_REGP_mask;
inline const RegMask &RMETHOD_REGP_mask() { return _RMETHOD_REGP_mask; }
extern const RegMask _RTHREAD_REGP_mask;
inline const RegMask &RTHREAD_REGP_mask() { return _RTHREAD_REGP_mask; }
extern const RegMask _IP_REGP_mask;
inline const RegMask &IP_REGP_mask() { return _IP_REGP_mask; }
extern const RegMask _LR_REGP_mask;
inline const RegMask &LR_REGP_mask() { return _LR_REGP_mask; }
extern const RegMask _FP_REGP_mask;
inline const RegMask &FP_REGP_mask() { return _FP_REGP_mask; }
extern const RegMask _LONG_REG_mask;
inline const RegMask &LONG_REG_mask() { return _LONG_REG_mask; }
extern const RegMask _LONG_REG_ALIGN_mask;
inline const RegMask &LONG_REG_ALIGN_mask() { return _LONG_REG_ALIGN_mask; }
extern const RegMask _R0R1_REGL_mask;
inline const RegMask &R0R1_REGL_mask() { return _R0R1_REGL_mask; }
extern const RegMask _R2R3_REGL_mask;
inline const RegMask &R2R3_REGL_mask() { return _R2R3_REGL_mask; }
extern const RegMask _INT_FLAGS_mask;
inline const RegMask &INT_FLAGS_mask() { return _INT_FLAGS_mask; }
extern const RegMask _FLOAT_FLAGS_mask;
inline const RegMask &FLOAT_FLAGS_mask() { return _FLOAT_FLAGS_mask; }
extern const RegMask _SFLT_REG_mask;
inline const RegMask &SFLT_REG_mask() { return _SFLT_REG_mask; }
extern const RegMask _DFLT_REG_mask;
inline const RegMask &DFLT_REG_mask() { return _DFLT_REG_mask; }
extern const RegMask _DFLT_LOW_REG_mask;
inline const RegMask &DFLT_LOW_REG_mask() { return _DFLT_LOW_REG_mask; }
inline const RegMask &ACTUAL_DFLT_REG_mask() { 
#line 279 "/build/jdk/openjdk-jdk9-jdk9/hotspot/src/cpu/arm/vm/arm_32.ad"

  if (VM_Version::has_vfp3_32()) {
    return DFLT_REG_mask();
  } else {
    return DFLT_LOW_REG_mask();
  }

#line 21444 "ad_arm.hpp"
 }
extern const RegMask _S0_REGF_mask;
inline const RegMask &S0_REGF_mask() { return _S0_REGF_mask; }
extern const RegMask _D0_REGD_mask;
inline const RegMask &D0_REGD_mask() { return _D0_REGD_mask; }
extern const RegMask _D1_REGD_mask;
inline const RegMask &D1_REGD_mask() { return _D1_REGD_mask; }
extern const RegMask _D2_REGD_mask;
inline const RegMask &D2_REGD_mask() { return _D2_REGD_mask; }
extern const RegMask _D3_REGD_mask;
inline const RegMask &D3_REGD_mask() { return _D3_REGD_mask; }
extern const RegMask _D4_REGD_mask;
inline const RegMask &D4_REGD_mask() { return _D4_REGD_mask; }
extern const RegMask _D5_REGD_mask;
inline const RegMask &D5_REGD_mask() { return _D5_REGD_mask; }
extern const RegMask _D6_REGD_mask;
inline const RegMask &D6_REGD_mask() { return _D6_REGD_mask; }
extern const RegMask _D7_REGD_mask;
inline const RegMask &D7_REGD_mask() { return _D7_REGD_mask; }
extern const RegMask _D16_REGD_mask;
inline const RegMask &D16_REGD_mask() { return _D16_REGD_mask; }
extern const RegMask _D17_REGD_mask;
inline const RegMask &D17_REGD_mask() { return _D17_REGD_mask; }
extern const RegMask _D18_REGD_mask;
inline const RegMask &D18_REGD_mask() { return _D18_REGD_mask; }
extern const RegMask _D19_REGD_mask;
inline const RegMask &D19_REGD_mask() { return _D19_REGD_mask; }
extern const RegMask _D20_REGD_mask;
inline const RegMask &D20_REGD_mask() { return _D20_REGD_mask; }
extern const RegMask _D21_REGD_mask;
inline const RegMask &D21_REGD_mask() { return _D21_REGD_mask; }
extern const RegMask _D22_REGD_mask;
inline const RegMask &D22_REGD_mask() { return _D22_REGD_mask; }
extern const RegMask _D23_REGD_mask;
inline const RegMask &D23_REGD_mask() { return _D23_REGD_mask; }
extern const RegMask _D24_REGD_mask;
inline const RegMask &D24_REGD_mask() { return _D24_REGD_mask; }
extern const RegMask _D25_REGD_mask;
inline const RegMask &D25_REGD_mask() { return _D25_REGD_mask; }
extern const RegMask _D26_REGD_mask;
inline const RegMask &D26_REGD_mask() { return _D26_REGD_mask; }
extern const RegMask _D27_REGD_mask;
inline const RegMask &D27_REGD_mask() { return _D27_REGD_mask; }
extern const RegMask _D28_REGD_mask;
inline const RegMask &D28_REGD_mask() { return _D28_REGD_mask; }
extern const RegMask _D29_REGD_mask;
inline const RegMask &D29_REGD_mask() { return _D29_REGD_mask; }
extern const RegMask _D30_REGD_mask;
inline const RegMask &D30_REGD_mask() { return _D30_REGD_mask; }
extern const RegMask _D31_REGD_mask;
inline const RegMask &D31_REGD_mask() { return _D31_REGD_mask; }
extern const RegMask _VECTORX_REG_mask;
inline const RegMask &VECTORX_REG_mask() { return _VECTORX_REG_mask; }
extern const RegMask _STACK_SLOTS_mask;
inline const RegMask &STACK_SLOTS_mask() { return _STACK_SLOTS_mask; }
extern const RegMask _STACK_OR_STACK_SLOTS_mask;
inline const RegMask &STACK_OR_STACK_SLOTS_mask() { return _STACK_OR_STACK_SLOTS_mask; }

#endif // GENERATED_ADFILES_AD_HPP
