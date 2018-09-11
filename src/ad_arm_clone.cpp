#line 1 "ad_arm_clone.cpp"
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
MachOper *UniverseOper::clone() const {
  return new UniverseOper();
}
MachOper *sRegIOper::clone() const {
  return new sRegIOper();
}
MachOper *sRegPOper::clone() const {
  return new sRegPOper();
}
MachOper *sRegFOper::clone() const {
  return new sRegFOper();
}
MachOper *sRegDOper::clone() const {
  return new sRegDOper();
}
MachOper *sRegLOper::clone() const {
  return new sRegLOper();
}
MachOper *immIRotOper::clone() const {
  return new immIRotOper(_c0);
}
MachOper *immIRotnOper::clone() const {
  return new immIRotnOper(_c0);
}
MachOper *immIRotnegOper::clone() const {
  return new immIRotnegOper(_c0);
}
MachOper *immU31RotOper::clone() const {
  return new immU31RotOper(_c0);
}
MachOper *immPRotOper::clone() const {
  return new immPRotOper(_c0);
}
MachOper *immLlowRotOper::clone() const {
  return new immLlowRotOper(_c0);
}
MachOper *immLRot2Oper::clone() const {
  return new immLRot2Oper(_c0);
}
MachOper *immI12Oper::clone() const {
  return new immI12Oper(_c0);
}
MachOper *immI10x2Oper::clone() const {
  return new immI10x2Oper(_c0);
}
MachOper *immI12x2Oper::clone() const {
  return new immI12x2Oper(_c0);
}
MachOper *immIOper::clone() const {
  return new immIOper(_c0);
}
MachOper *immU8Oper::clone() const {
  return new immU8Oper(_c0);
}
MachOper *immI16Oper::clone() const {
  return new immI16Oper(_c0);
}
MachOper *immIHDOper::clone() const {
  return new immIHDOper(_c0);
}
MachOper *immIFPOper::clone() const {
  return new immIFPOper(_c0);
}
MachOper *immU5Oper::clone() const {
  return new immU5Oper(_c0);
}
MachOper *immU6BigOper::clone() const {
  return new immU6BigOper(_c0);
}
MachOper *immI0Oper::clone() const {
  return new immI0Oper(_c0);
}
MachOper *immI_1Oper::clone() const {
  return new immI_1Oper(_c0);
}
MachOper *immI_2Oper::clone() const {
  return new immI_2Oper(_c0);
}
MachOper *immI_3Oper::clone() const {
  return new immI_3Oper(_c0);
}
MachOper *immI_4Oper::clone() const {
  return new immI_4Oper(_c0);
}
MachOper *immI_8Oper::clone() const {
  return new immI_8Oper(_c0);
}
MachOper *immU31Oper::clone() const {
  return new immU31Oper(_c0);
}
MachOper *immI_32_63Oper::clone() const {
  return new immI_32_63Oper(_c0);
}
MachOper *immI_16Oper::clone() const {
  return new immI_16Oper(_c0);
}
MachOper *immI_24Oper::clone() const {
  return new immI_24Oper(_c0);
}
MachOper *immI_255Oper::clone() const {
  return new immI_255Oper(_c0);
}
MachOper *immI_65535Oper::clone() const {
  return new immI_65535Oper(_c0);
}
MachOper *aimmIOper::clone() const {
  return new aimmIOper(_c0);
}
MachOper *aimmInegOper::clone() const {
  return new aimmInegOper(_c0);
}
MachOper *aimmU31Oper::clone() const {
  return new aimmU31Oper(_c0);
}
MachOper *limmIOper::clone() const {
  return new limmIOper(_c0);
}
MachOper *limmIlow8Oper::clone() const {
  return new limmIlow8Oper(_c0);
}
MachOper *limmU31Oper::clone() const {
  return new limmU31Oper(_c0);
}
MachOper *limmInOper::clone() const {
  return new limmInOper(_c0);
}
MachOper *immL_FFOper::clone() const {
  return new immL_FFOper(_c0);
}
MachOper *immL_FFFFOper::clone() const {
  return new immL_FFFFOper(_c0);
}
MachOper *immPOper::clone() const {
  return new immPOper(_c0);
}
MachOper *immP0Oper::clone() const {
  return new immP0Oper(_c0);
}
MachOper *immP_pollOper::clone() const {
  return new immP_pollOper(_c0);
}
MachOper *immNOper::clone() const {
  return new immNOper(_c0);
}
MachOper *immNKlassOper::clone() const {
  return new immNKlassOper(_c0);
}
MachOper *immN0Oper::clone() const {
  return new immN0Oper(_c0);
}
MachOper *immLOper::clone() const {
  return new immLOper(_c0);
}
MachOper *immL0Oper::clone() const {
  return new immL0Oper(_c0);
}
MachOper *immL16Oper::clone() const {
  return new immL16Oper(_c0);
}
MachOper *immL_32bitsOper::clone() const {
  return new immL_32bitsOper(_c0);
}
MachOper *immDOper::clone() const {
  return new immDOper(_c0);
}
MachOper *immD0Oper::clone() const {
  return new immD0Oper(_c0);
}
MachOper *imm8DOper::clone() const {
  return new imm8DOper(_c0);
}
MachOper *immFOper::clone() const {
  return new immFOper(_c0);
}
MachOper *immF0Oper::clone() const {
  return new immF0Oper(_c0);
}
MachOper *imm8FOper::clone() const {
  return new imm8FOper(_c0);
}
MachOper *iRegIOper::clone() const {
  return new iRegIOper();
}
MachOper *iRegPOper::clone() const {
  return new iRegPOper();
}
MachOper *sp_ptr_RegPOper::clone() const {
  return new sp_ptr_RegPOper();
}
MachOper *R0RegPOper::clone() const {
  return new R0RegPOper();
}
MachOper *R1RegPOper::clone() const {
  return new R1RegPOper();
}
MachOper *R2RegPOper::clone() const {
  return new R2RegPOper();
}
MachOper *RExceptionRegPOper::clone() const {
  return new RExceptionRegPOper();
}
MachOper *RthreadRegPOper::clone() const {
  return new RthreadRegPOper();
}
MachOper *IPRegPOper::clone() const {
  return new IPRegPOper();
}
MachOper *LRRegPOper::clone() const {
  return new LRRegPOper();
}
MachOper *R0RegIOper::clone() const {
  return new R0RegIOper();
}
MachOper *R1RegIOper::clone() const {
  return new R1RegIOper();
}
MachOper *R2RegIOper::clone() const {
  return new R2RegIOper();
}
MachOper *R3RegIOper::clone() const {
  return new R3RegIOper();
}
MachOper *R12RegIOper::clone() const {
  return new R12RegIOper();
}
MachOper *iRegLOper::clone() const {
  return new iRegLOper();
}
MachOper *iRegLdOper::clone() const {
  return new iRegLdOper();
}
MachOper *R0R1RegLOper::clone() const {
  return new R0R1RegLOper();
}
MachOper *R2R3RegLOper::clone() const {
  return new R2R3RegLOper();
}
MachOper *flagsRegOper::clone() const {
  return new flagsRegOper();
}
MachOper *flagsReg_EQNELTGEOper::clone() const {
  return new flagsReg_EQNELTGEOper();
}
MachOper *flagsRegUOper::clone() const {
  return new flagsRegUOper();
}
MachOper *flagsRegPOper::clone() const {
  return new flagsRegPOper();
}
MachOper *flagsRegL_LTGEOper::clone() const {
  return new flagsRegL_LTGEOper();
}
MachOper *flagsRegL_EQNEOper::clone() const {
  return new flagsRegL_EQNEOper();
}
MachOper *flagsRegL_LEGTOper::clone() const {
  return new flagsRegL_LEGTOper();
}
MachOper *flagsRegFOper::clone() const {
  return new flagsRegFOper();
}
MachOper *vecDOper::clone() const {
  return new vecDOper();
}
MachOper *vecXOper::clone() const {
  return new vecXOper();
}
MachOper *regDOper::clone() const {
  return new regDOper();
}
MachOper *regFOper::clone() const {
  return new regFOper();
}
MachOper *regD_lowOper::clone() const {
  return new regD_lowOper();
}
MachOper *inline_cache_regPOper::clone() const {
  return new inline_cache_regPOper();
}
MachOper *interpreter_method_oop_regPOper::clone() const {
  return new interpreter_method_oop_regPOper();
}
MachOper *indirectOper::clone() const {
  return new indirectOper();
}
MachOper *indOffset12Oper::clone() const {
  return new indOffset12Oper(_c0);
}
MachOper *indOffsetFPOper::clone() const {
  return new indOffsetFPOper(_c0);
}
MachOper *indOffsetHDOper::clone() const {
  return new indOffsetHDOper(_c0);
}
MachOper *indOffsetFPx2Oper::clone() const {
  return new indOffsetFPx2Oper(_c0);
}
MachOper *indOffset12x2Oper::clone() const {
  return new indOffset12x2Oper(_c0);
}
MachOper *indIndexOper::clone() const {
  return new indIndexOper();
}
MachOper *indIndexScaleOper::clone() const {
  return new indIndexScaleOper(_c0);
}
MachOper *cmpOpOper::clone() const {
  return new cmpOpOper(_c0);
}
MachOper *cmpOp0Oper::clone() const {
  return new cmpOp0Oper(_c0);
}
MachOper *cmpOpUOper::clone() const {
  return new cmpOpUOper(_c0);
}
MachOper *cmpOpPOper::clone() const {
  return new cmpOpPOper(_c0);
}
MachOper *cmpOpLOper::clone() const {
  return new cmpOpLOper(_c0);
}
MachOper *cmpOpL_commuteOper::clone() const {
  return new cmpOpL_commuteOper(_c0);
}
MachOper *shiftedXOper::clone() const {
  return new shiftedXOper(_c0);
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
