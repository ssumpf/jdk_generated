#line 1 "ad_arm_format.cpp"
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

#ifndef PRODUCT
void UniverseOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("$$univ");
}
void UniverseOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("$$univ");
}
#endif

#ifndef PRODUCT
void sRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void immIRotOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immIRotOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immIRotnOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immIRotnOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immIRotnegOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immIRotnegOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immU31RotOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immU31RotOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immPRotOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immPRotOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immLlowRotOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immLlowRotOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immLRot2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immLRot2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immI12Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI12Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI10x2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI10x2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI12x2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI12x2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immU8Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immU8Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI16Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI16Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immIHDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immIHDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immIFPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immIFPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immU5Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immU5Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immU6BigOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immU6BigOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_3Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_3Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_4Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_4Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_8Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_8Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immU31Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immU31Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_32_63Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_32_63Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_16Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_16Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_24Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_24Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_255Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_255Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_65535Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void immI_65535Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void aimmIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void aimmIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void aimmInegOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void aimmInegOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void aimmU31Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void aimmU31Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void limmIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void limmIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void limmIlow8Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void limmIlow8Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void limmU31Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void limmU31Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void limmInOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%d", _c0);
}
void limmInOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immL_FFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immL_FFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immL_FFFFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immL_FFFFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immP0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immP0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immP_pollOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immP_pollOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immNOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immNOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immNKlassOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immNKlassOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immN0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
void immN0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  if (_c0) _c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immL0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immL0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immL16Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immL16Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immL_32bitsOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
void immL_32bitsOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#" INT64_FORMAT, (int64_t)_c0);
}
#endif

#ifndef PRODUCT
void immDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%f", _c0);
}
void immDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immD0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%f", _c0);
}
void immD0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void imm8DOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%f", _c0);
}
void imm8DOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%f", _c0);
}
void immFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immF0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%f", _c0);
}
void immF0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void imm8FOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("#%f", _c0);
}
void imm8FOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void iRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void iRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void iRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void iRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void sp_ptr_RegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void sp_ptr_RegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R0RegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R0RegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R1RegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R1RegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R2RegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R2RegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void RExceptionRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void RExceptionRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void RthreadRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void RthreadRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void IPRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void IPRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void LRRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void LRRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R0RegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R0RegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R1RegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R1RegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R2RegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R2RegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R3RegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R3RegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R12RegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R12RegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void iRegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void iRegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void iRegLdOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void iRegLdOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R0R1RegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R0R1RegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void R2R3RegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void R2R3RegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void flagsRegOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr");
}
void flagsRegOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr");
}
#endif

#ifndef PRODUCT
void flagsReg_EQNELTGEOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr_EQNELTGE");
}
void flagsReg_EQNELTGEOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr_EQNELTGE");
}
#endif

#ifndef PRODUCT
void flagsRegUOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr_U");
}
void flagsRegUOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr_U");
}
#endif

#ifndef PRODUCT
void flagsRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr_P");
}
void flagsRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr_P");
}
#endif

#ifndef PRODUCT
void flagsRegL_LTGEOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr_L_LTGE");
}
void flagsRegL_LTGEOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr_L_LTGE");
}
#endif

#ifndef PRODUCT
void flagsRegL_EQNEOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr_L_EQNE");
}
void flagsRegL_EQNEOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr_L_EQNE");
}
#endif

#ifndef PRODUCT
void flagsRegL_LEGTOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("apsr_L_LEGT");
}
void flagsRegL_LEGTOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("apsr_L_LEGT");
}
#endif

#ifndef PRODUCT
void flagsRegFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("fpscr_F");
}
void flagsRegFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("fpscr_F");
}
#endif

#ifndef PRODUCT
void vecDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void vecDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void vecXOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void vecXOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void regDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void regDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void regFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void regFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void regD_lowOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void regD_lowOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void inline_cache_regPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void inline_cache_regPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void interpreter_method_oop_regPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
}
void interpreter_method_oop_regPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
}
#endif

#ifndef PRODUCT
void indirectOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw("]");
}
void indirectOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indOffset12Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
void indOffset12Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indOffsetFPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
void indOffsetFPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indOffsetHDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
void indOffsetHDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indOffsetFPx2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
void indOffsetFPx2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indOffset12x2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
void indOffset12x2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indIndexOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw("]");
}
void indIndexOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  { char reg_str[128];
    ra->dump_register(node->in(idx+1),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void indIndexScaleOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" << ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
void indIndexScaleOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("[");
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" + ");
  { char reg_str[128];
    ra->dump_register(node->in(idx+1),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" << ");
  st->print("#%d", _c0);
  st->print_raw("]");
}
#endif

#ifndef PRODUCT
void cmpOpOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
void cmpOpOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
#endif

#ifndef PRODUCT
void cmpOp0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
void cmpOp0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
#endif

#ifndef PRODUCT
void cmpOpUOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("u");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
void cmpOpUOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("u");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
#endif

#ifndef PRODUCT
void cmpOpPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("p");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
void cmpOpPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("p");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
#endif

#ifndef PRODUCT
void cmpOpLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("L");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
void cmpOpLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("L");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
#endif

#ifndef PRODUCT
void cmpOpL_commuteOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print_raw("L");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
void cmpOpL_commuteOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print_raw("L");
       if( _c0 == BoolTest::eq ) st->print_raw("eq");
  else if( _c0 == BoolTest::ne ) st->print_raw("ne");
  else if( _c0 == BoolTest::le ) st->print_raw("le");
  else if( _c0 == BoolTest::ge ) st->print_raw("ge");
  else if( _c0 == BoolTest::lt ) st->print_raw("lt");
  else if( _c0 == BoolTest::gt ) st->print_raw("gt");
  else if( _c0 == BoolTest::overflow ) st->print_raw("o");
  else if( _c0 == BoolTest::no_overflow ) st->print_raw("no");
}
#endif

#ifndef PRODUCT
void shiftedXOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node,reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" << ");
  st->print("#%d", _c0);
}
void shiftedXOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  { char reg_str[128];
    ra->dump_register(node->in(idx),reg_str);
    st->print("%s",reg_str);
  }
  st->print_raw(" << ");
  st->print("#%d", _c0);
}
#endif
#ifndef PRODUCT
void Nop_A0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void Nop_A1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void Nop_MSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void Nop_FANode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void Nop_BRNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void loadBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRSB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! byte -> int");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadB2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRSB ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! byte -> long\n\t");
  st->print_raw("ASR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,31");
}
#endif
#ifndef PRODUCT
void loadUBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ubyte -> int");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadUB2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRB  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ubyte -> long\n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void loadUB2L_limmINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRB  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ubyte -> long\n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,0\n\t");
  st->print_raw("AND  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // mask
}
#endif
#ifndef PRODUCT
void loadSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRSH   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! short");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadS2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// twentyfour
  st->print_raw("LDRSB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! short -> byte");
}
#endif
#ifndef PRODUCT
void loadS2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRSH ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! short -> long\n\t");
  st->print_raw("ASR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,31");
}
#endif
#ifndef PRODUCT
void loadUSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRH   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ushort/char");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadUS2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// twentyfour
  st->print_raw("LDRSB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ushort -> byte");
}
#endif
#ifndef PRODUCT
void loadUS2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDRH  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! short -> long\n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void loadUS2L_immI_255Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRB  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! \n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void loadUS2L_limmINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRH   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ushort/char & mask -> long\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0\n\t");
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // mask
}
#endif
#ifndef PRODUCT
void loadINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("ldr_s32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadI2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// twentyfour
  st->print_raw("LDRSB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int -> byte");
}
#endif
#ifndef PRODUCT
void loadI2UBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int -> ubyte");
}
#endif
#ifndef PRODUCT
void loadI2SNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// sixteen
  st->print_raw("LDRSH   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int -> short");
}
#endif
#ifndef PRODUCT
void loadI2USNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRH   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int -> ushort/char");
}
#endif
#ifndef PRODUCT
void loadI2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int -> long\n\t");
  st->print_raw("ASR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,31\t! int->long");
}
#endif
#ifndef PRODUCT
void loadI2L_immI_255Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRB   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int & 0xFF -> long\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void loadI2L_immI_65535Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDRH   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int & 0xFFFF -> long\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void loadI2L_limmU31Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! int -> long\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0\n\t");
  st->print_raw("AND   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // mask
}
#endif
#ifndef PRODUCT
void loadI2L_immU31Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("LDR      ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw("\t! int & 31-bit mask -> long\n\t");
  st->print_raw("MOV      ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi, 0\n\t");
  st->print_raw("MOV_SLOW ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // mask
  st->print_raw("\n\t");
  st->print_raw("AND      ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
}
#endif
#ifndef PRODUCT
void loadUI2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("LDR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! uint -> long\n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void loadLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  st->print_raw("ldr_64  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! long");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadL_2instrNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw(" \t! long order of instrs reversed if ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo == base(");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw(")\n\t");
  st->print_raw("LDR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("+4 or ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadL_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDMIA    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! long");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadL_volatile_fpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("FLDD      S14, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("FMRRD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", S14\t! long \n't");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadL_unalignedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! long order of instrs reversed if ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo == base(");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw(")\n\t");
  st->print_raw("LDR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("+4");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadRangeNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDR_u32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! range");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ptr");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadKlassNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! klass ptr");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("FLDD   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadD_unalignedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("FLDS    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! misaligned double\n");
  st->print_raw("\tFLDS    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("+4\t!");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("FLDS    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadConINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV_SLOW    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadConIMovNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadConIMovnNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MVN    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ~");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadConI16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOVW    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadConPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV_SLOW    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t!ptr");
}
#endif
#ifndef PRODUCT
void loadConP_pollNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV_SLOW    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t!ptr");
}
#endif
#ifndef PRODUCT
void loadConLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV_SLOW   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" & 0x0FFFFFFFFL \t! long\n\t");
  st->print_raw("MOV_SLOW   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" >> 32");
}
#endif
#ifndef PRODUCT
void loadConL16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOVW    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" \n\t");
  st->print_raw("MOVW    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0 \n\t");
}
#endif
#ifndef PRODUCT
void loadConF_imm8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FCONSTS      ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadConFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("MOV_SLOW  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("FMSR      ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void loadConD_imm8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FCONSTD      ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadConDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("FLDD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", [");
  char reg[128];  ra->dump_register(in(mach_constant_base_node_input()), reg);
    st->print("%s", reg);
  st->print_raw(" + ");
  st->print("#%d", constant_offset_unchecked());
  st->print_raw("]\t! load from constant table: double=");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void prefetchAlloc_mpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// 
  st->print_raw("PLDW ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! Prefetch allocation");
}
#endif
#ifndef PRODUCT
void prefetchAlloc_spNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// 
  st->print_raw("PLD ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! Prefetch allocation");
}
#endif
#ifndef PRODUCT
void storeBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("STRB    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! byte");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeCMNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("STRB    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! CMS card-mark byte");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeCNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("STRH    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! short");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("str_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("str_64  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! long\n\t");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeL_2instrNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("STR    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! long\n\t");
  st->print_raw("STR    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("+4");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeL_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("STMIA    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! long");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeL_volatile_fpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("FMDRR    S14, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw("\t! long \n\t");
  st->print_raw("FSTD     S14, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storePNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("STR    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! ptr");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("FSTD   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("FSTS    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void membar_storestoreNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MEMBAR-storestore");
}
#endif
#ifndef PRODUCT
void membar_acquireNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MEMBAR-acquire");
}
#endif
#ifndef PRODUCT
void membar_acquire_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MEMBAR-acquire");
}
#endif
#ifndef PRODUCT
void membar_acquire_lockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("!MEMBAR-acquire (CAS in prior FastLock so empty encoding)");
}
#endif
#ifndef PRODUCT
void membar_releaseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MEMBAR-release");
}
#endif
#ifndef PRODUCT
void membar_release_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MEMBAR-release");
}
#endif
#ifndef PRODUCT
void membar_release_lockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("!MEMBAR-release (CAS in succeeding FastUnlock so empty encoding)");
}
#endif
#ifndef PRODUCT
void membar_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MEMBAR-volatile");
}
#endif
#ifndef PRODUCT
void unnecessary_membar_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("!MEMBAR-volatile (unnecessary so empty encoding)");
}
#endif
#ifndef PRODUCT
void castX2PNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! IntX->Ptr if ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" != ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void castP2XNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! Ptr->IntX if ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" != ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void cmovIP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void cmovIP_immMovNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIP_imm16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVw");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovI_immMovNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovII_imm16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVw");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovII_reg_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovII_immMov_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovII_imm16_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIIu_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIIu_immMovNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIIu_imm16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPP_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovPI_reg_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovPIu_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovPI_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovPI_imm_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovPIu_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovFP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovFI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovFI_reg_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovFIu_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDI_reg_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDIu_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovLP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void cmovLP_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void cmovLP_imm16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// pcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void cmovLI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void cmovLI_reg_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void cmovLI_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void cmovLI_immRot_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void cmovLI_imm16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void cmovLI_imm16_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw("\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void cmovLIu_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".hi,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void tlsLoadPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  st->print_raw("! TLS is in ");
  opnd_array(0)->int_format(ra, this, st); // dst
}
#endif
#ifndef PRODUCT
void checkCastPPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// dst
  st->print_raw("! checkcastPP of ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
}
#endif
#ifndef PRODUCT
void castPPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// dst
  st->print_raw("! castPP of ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
}
#endif
#ifndef PRODUCT
void castIINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// dst
  st->print_raw("! castII of ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
}
#endif
#ifndef PRODUCT
void addI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshlI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src3
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshlI_reg_imm_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshlI_reg_imm_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src3
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addsarI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src3
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addsarI_reg_imm_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addsarI_reg_imm_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src3
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshrI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src3
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshrI_reg_imm_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addshrI_reg_imm_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src3
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src1
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src3
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addI_reg_aimmINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("add_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void addP_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ADD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void addshlP_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ADD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void addP_reg_aimmXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ADD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void addL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ADDS    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("ADC     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void addL_reg_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  st->print_raw("ADDS    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t! long\n\t");
  st->print_raw("ADC     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void loadPLockedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("LDREX  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storePConditionalNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// heap_top_ptr
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("STREX  ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // heap_top_ptr
  st->print_raw("\n\t");
  st->print_raw("CMP    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0");
}
#endif
#ifndef PRODUCT
void storeXConditionalNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! If ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("==[");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("] Then store ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(" into [");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("], DOESN'T set ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw("=[");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("] in any case\n\t");
  st->print_raw("XORS     ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("\n\t");
  st->print_raw("STREX.eq ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP.eq   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 1 \n\t");
  st->print_raw("B.eq     loop \n\t");
  st->print_raw("TEQ      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0\n\t");
  st->print_raw("membar   LoadStore|LoadLoad");
}
#endif
#ifndef PRODUCT
void compareAndSwapL_boolNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREXD   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! If ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("==[");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("] Then store ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(" into [");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("]\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(".lo, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw(".lo\n\t");
  st->print_raw("CMP.eq   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(".hi, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw(".hi\n\t");
  st->print_raw("STREXD.eq ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("MOV.ne   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0 \n\t");
  st->print_raw("XORS.eq  ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 1 \n\t");
  st->print_raw("B.eq     loop \n\t");
  st->print_raw("MOV      ");
  opnd_array(0)->int_format(ra, this, st); // res
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
}
#endif
#ifndef PRODUCT
void compareAndSwapI_boolNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! If ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("==[");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("] Then store ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(" into [");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("]\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("\n\t");
  st->print_raw("STREX.eq ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("MOV.ne   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0 \n\t");
  st->print_raw("XORS.eq  ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 1 \n\t");
  st->print_raw("B.eq     loop \n\t");
  st->print_raw("MOV      ");
  opnd_array(0)->int_format(ra, this, st); // res
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
}
#endif
#ifndef PRODUCT
void compareAndSwapP_boolNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// oldval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// newval
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! If ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("==[");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("] Then store ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(" into [");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("]\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // oldval
  st->print_raw("\n\t");
  st->print_raw("STREX.eq ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("MOV.ne   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0 \n\t");
  st->print_raw("EORS.eq  ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 1 \n\t");
  st->print_raw("B.eq     loop \n\t");
  st->print_raw("MOV      ");
  opnd_array(0)->int_format(ra, this, st); // res
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
}
#endif
#ifndef PRODUCT
void xaddI_aimmI_no_resNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADD      ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw("\n\t");
  st->print_raw("STREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddI_reg_no_resNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADD      ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw("\n\t");
  st->print_raw("STREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddI_aimmINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADD      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw("\n\t");
  st->print_raw("STREX    ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADD      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw("\n\t");
  st->print_raw("STREX    ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddL_reg_no_resNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREXD   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADDS     ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".lo, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".lo, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw(".lo\n\t");
  st->print_raw("ADC      ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".hi, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".hi, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw(".hi\n\t");
  st->print_raw("STREXD   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddL_immRot_no_resNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREXD   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADDS     ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".lo, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".lo, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw("\n\t");
  st->print_raw("ADC      ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".hi, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(".hi, 0\n\t");
  st->print_raw("STREXD   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddL_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREXD   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADDS     ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(".lo, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(".lo, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw(".lo\n\t");
  st->print_raw("ADC      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(".hi, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(".hi, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw(".hi\n\t");
  st->print_raw("STREXD   ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xaddL_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// add
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp1
  unsigned idx5 = idx4 + opnd_array(4)->num_edges(); 	// tmp2
  st->print_raw("loop: \n\t");
  st->print_raw("LDREXD   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("ADDS     ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(".lo, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(".lo, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // add
  st->print_raw("\n\t");
  st->print_raw("ADC      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(".hi, ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(".hi, 0\n\t");
  st->print_raw("STREXD   ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xchgINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// newval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("STREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xchgLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// newval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREXD   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("STREXD   ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void xchgPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// newval
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// res
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// tmp
  st->print_raw("loop: \n\t");
  st->print_raw("LDREX    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // res
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("STREX    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // newval
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\n\t");
  st->print_raw("CMP      ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
  st->print_raw(", 0 \n\t");
  st->print_raw("B.ne     loop \n\t");
}
#endif
#ifndef PRODUCT
void subI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("sub_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void subshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("SUB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void subshlI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("sub_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void subsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("SUB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void subsarI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("sub_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void subshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("SUB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void subshrI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("sub_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void rsbshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void rsbshlI_reg_imm_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void rsbsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void rsbsarI_reg_imm_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void rsbshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void rsbshrI_reg_imm_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void subI_reg_aimmINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("sub_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void subI_reg_immRotnegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("sub_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",-(");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(")\t! int");
}
#endif
#ifndef PRODUCT
void subI_immRot_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("RSB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(",src1");
}
#endif
#ifndef PRODUCT
void subL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("SUBS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("SBC    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void subL_reg_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  st->print_raw("SUB    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t! long\n\t");
  st->print_raw("SBC    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void negL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// zero
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("RSBS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo,0\t! long\n\t");
  st->print_raw("RSC    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void mulI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("mul_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void mulL_lo1_hi2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("MUL  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi\t! long");
}
#endif
#ifndef PRODUCT
void mulL_hi1_lo2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("MLA  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".hi,");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi\t! long\n\t");
  st->print_raw("MOV  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".lo, 0");
}
#endif
#ifndef PRODUCT
void mulL_lo1_lo2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("UMLAL  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw("\t! long");
}
#endif
#ifndef PRODUCT
void mulL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void divI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("DIV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" ! call to StubRoutines::Arm::idiv_irem_entry()");
}
#endif
#ifndef PRODUCT
void divL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("DIVL  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(",");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw("\t! long ! call to SharedRuntime::ldiv");
}
#endif
#ifndef PRODUCT
void modI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("MODI   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t ! call to StubRoutines::Arm::idiv_irem_entry");
}
#endif
#ifndef PRODUCT
void modL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("modL    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t ! call to SharedRuntime::lrem");
}
#endif
#ifndef PRODUCT
void shlI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSL  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
}
#endif
#ifndef PRODUCT
void shlI_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSL    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void shlL_reg_reg_merge_hiNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("OR  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi,(");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".hi << ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(")");
}
#endif
#ifndef PRODUCT
void shlL_reg_reg_merge_loNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("LSL  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".lo,");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(" \n\t");
}
#endif
#ifndef PRODUCT
void shlL_reg_reg_overlapNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("SUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(",32 \n\t");
  st->print_raw("LSLpl ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi \n\t");
  st->print_raw("RSBmi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,0 \n\t");
  st->print_raw("LSRmi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void shlL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void shlL_reg_imm6Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSL   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("-32\t! or mov if ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("==32\n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, 0");
}
#endif
#ifndef PRODUCT
void shlL_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSL   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo >> 32-");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("LSL   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void sarI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ASR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void sarI_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ASR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void sarL_reg_reg_merge_loNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("OR  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".lo,(");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".lo >> ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(")");
}
#endif
#ifndef PRODUCT
void sarL_reg_reg_merge_hiNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("ASR  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".hi,");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(" \n\t");
}
#endif
#ifndef PRODUCT
void sarL_reg_reg_overlapNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("SUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(",32 \n\t");
  st->print_raw("ASRpl ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo \n\t");
  st->print_raw("RSBmi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,0 \n\t");
  st->print_raw("LSLmi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo");
}
#endif
#ifndef PRODUCT
void sarL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void sarL_reg_imm6Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("ASR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("-32\t! or mov if ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("==32\n\t");
  st->print_raw("ASR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void sarL_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi << 32-");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("ASR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void shrI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void shrI_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void shrL_reg_reg_merge_loNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("OR   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(",(");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".lo >>> ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(")");
}
#endif
#ifndef PRODUCT
void shrL_reg_reg_merge_hiNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("LSR  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  st->print_raw(".hi,");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src2
  st->print_raw(" \n\t");
}
#endif
#ifndef PRODUCT
void shrL_reg_reg_overlapNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("SUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(",32 \n\t");
  st->print_raw("LSRpl ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" \n\t");
  st->print_raw("RSBmi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",0 \n\t");
  st->print_raw("LSLmi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(0)->int_format(ra, this, st); // dst
}
#endif
#ifndef PRODUCT
void shrL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void shrL_reg_imm6Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("-32\t! or mov if ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("==32\n\t");
  st->print_raw("MOV   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void shrL_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi << 32-");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("LSR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void shrP_reg_imm5Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("LSR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! Cast ptr ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(" to int and shift");
}
#endif
#ifndef PRODUCT
void addF_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void addD_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FADDD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void subF_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void subD_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FSUBD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void mulF_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void mulD_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMULD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void divF_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void divD_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FDIVD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void absD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FABSd  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void absF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FABSs  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void negF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FNEGs  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void negD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FNEGd  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void sqrtF_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FSQRTS ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void sqrtD_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FSQRTD ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void andI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void andshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void andshlI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void andshlI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void andshlI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void andsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void andsarI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void andsarI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void andsarI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void andshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void andshrI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void andshrI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void andshrI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void andI_reg_limmNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("and_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void andI_reg_limmnNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("bic    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",~");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void andL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! long");
}
#endif
#ifndef PRODUCT
void andL_reg_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  st->print_raw("AND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t! long");
}
#endif
#ifndef PRODUCT
void orI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void orshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void orshlI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void orshlI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void orshlI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void orsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void orsarI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void orsarI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void orsarI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void orshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void orshrI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("OR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void orshrI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void orshrI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("orr_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void orI_reg_limmNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("orr_32  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void orL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void orL_reg_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t! long\n\t");
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
}
#endif
#ifndef PRODUCT
void xorI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void xorshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("XOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void xorshlI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("XOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void xorshlI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void xorshlI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void xorsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("XOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void xorsarI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("XOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void xorsarI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void xorsarI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void xorshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("XOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void xorshrI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("XOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void xorshrI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src3
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(">>>");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src3
}
#endif
#ifndef PRODUCT
void xorshrI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// src1
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  st->print_raw(">>>");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src3
}
#endif
#ifndef PRODUCT
void xorI_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("eor_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void xorL_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("XOR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi\t! long\n\t");
  st->print_raw("XOR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo\t! long");
}
#endif
#ifndef PRODUCT
void xorL_reg_immRotNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  st->print_raw("XOR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t! long\n\t");
  st->print_raw("XOR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo,0\t! long");
}
#endif
#ifndef PRODUCT
void convI2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("TST    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" \n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0   \n\t");
  st->print_raw("MOV.ne ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 1");
}
#endif
#ifndef PRODUCT
void convP2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("TST    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" \n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0   \n\t");
  st->print_raw("MOV.ne ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 1");
}
#endif
#ifndef PRODUCT
void cmpLTMask_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", #0\n\t");
  st->print_raw("MOV.lt ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", #-1");
}
#endif
#ifndef PRODUCT
void cmpLTMask_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", #0\n\t");
  st->print_raw("MOV.lt ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", #-1");
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask3Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // y
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask3_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// y
  st->print_raw("CMP    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask3_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// y
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  st->print_raw("CMP    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // y
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask3_2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// y
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// p
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// q
  st->print_raw("CMP    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // p
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask4Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // y
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask4_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// y
  st->print_raw("CMP    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask4_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// y
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// z
  st->print_raw("CMP    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // y
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask4_2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// z
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// y
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// p
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// q
  st->print_raw("CMP    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // p
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // z
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMaskNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  st->print_raw("SUBS   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  st->print_raw("SUBS   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// y
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// p
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// q
  st->print_raw("SUBS   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // y
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // p
}
#endif
#ifndef PRODUCT
void cadd_cmpLTMask_2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// p
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// q
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// y
  st->print_raw("SUBS   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // q
  st->print_raw("\n\t");
  st->print_raw("ADD.lt ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // y
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // p
}
#endif
#ifndef PRODUCT
void convD2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FCVTSD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void convD2I_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("FTOSIZD  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("FMRS     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void convD2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("convD2L    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t ! call to SharedRuntime::d2l");
}
#endif
#ifndef PRODUCT
void convF2D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FCVTDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void convF2I_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("FTOSIZS  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("FMRS     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void convF2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("convF2L  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! call to SharedRuntime::f2l");
}
#endif
#ifndef PRODUCT
void convI2D_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMSR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" \n\t");
  st->print_raw("FSITOD   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" ");
  opnd_array(0)->int_format(ra, this, st); // dst
}
#endif
#ifndef PRODUCT
void convI2F_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMSR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" \n\t");
  st->print_raw("FSITOS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
}
#endif
#ifndef PRODUCT
void convI2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo, ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(" \n\t");
  st->print_raw("ASR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",31\t! int->long");
}
#endif
#ifndef PRODUCT
void convI2L_reg_zexNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo\t! zero-extend int to long\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void zerox_longNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// mask
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo\t! zero-extend long\n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi, 0");
}
#endif
#ifndef PRODUCT
void MoveF2I_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMRS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! MoveF2I");
}
#endif
#ifndef PRODUCT
void MoveI2F_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMSR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! MoveI2F");
}
#endif
#ifndef PRODUCT
void MoveD2L_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMRRD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! MoveD2L");
}
#endif
#ifndef PRODUCT
void MoveL2D_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMDRR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! MoveL2D");
}
#endif
#ifndef PRODUCT
void loadConI_x43300000Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  st->print_raw("MOV_SLOW  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",0x43300000\t! 2^52");
}
#endif
#ifndef PRODUCT
void loadConI_x41f00000Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  st->print_raw("MOV_SLOW  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0x41f00000\t! 2^32");
}
#endif
#ifndef PRODUCT
void loadConI_x0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  st->print_raw("MOV  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0x0\t! 0");
}
#endif
#ifndef PRODUCT
void regDHi_regDLo_to_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCPYS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi\n\t");
  st->print_raw("FCPYS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo");
}
#endif
#ifndef PRODUCT
void convI2D_regDHi_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FSITOD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void addD_regD_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FADDD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void subD_regD_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FSUBD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void mulD_regD_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMULD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
}
#endif
#ifndef PRODUCT
void regL_to_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMDRR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t! regL to regD");
}
#endif
#ifndef PRODUCT
void regI_regI_to_regDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMDRR   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! regI,regI to regD");
}
#endif
#ifndef PRODUCT
void convL2D_reg_slow_fxtofNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void convL2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo\t! long->int");
}
#endif
#ifndef PRODUCT
void shrL_reg_imm6_L2INode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// cnt
  st->print_raw("ASR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi,(");
  opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
  st->print_raw(" - 32)\t! long->int or mov if ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
  st->print_raw("==32");
}
#endif
#ifndef PRODUCT
void compI_iRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("cmp_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void compU_iRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("cmp_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! unsigned int");
}
#endif
#ifndef PRODUCT
void compI_iReg_immnegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("cmn_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",-");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void compI_iReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("cmp_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! int");
}
#endif
#ifndef PRODUCT
void testI_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
}
#endif
#ifndef PRODUCT
void testshlI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("TST   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op3
}
#endif
#ifndef PRODUCT
void testshlI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("TST   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op3
}
#endif
#ifndef PRODUCT
void testshlI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op3
}
#endif
#ifndef PRODUCT
void testshlI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op3
}
#endif
#ifndef PRODUCT
void testsarI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("TST   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op3
}
#endif
#ifndef PRODUCT
void testsarI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("TST   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op3
}
#endif
#ifndef PRODUCT
void testsarI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op3
}
#endif
#ifndef PRODUCT
void testsarI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op3
}
#endif
#ifndef PRODUCT
void testshrI_reg_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("TST   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op3
}
#endif
#ifndef PRODUCT
void testshrI_reg_reg_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("TST   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op3
}
#endif
#ifndef PRODUCT
void testshrI_reg_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op3
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw("<<");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op3
}
#endif
#ifndef PRODUCT
void testshrI_reg_reg_imm_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op2
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op3
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// op1
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // op1
  st->print_raw("<<");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op3
}
#endif
#ifndef PRODUCT
void testI_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// zero
  st->print_raw("tst_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
}
#endif
#ifndef PRODUCT
void compL_reg_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  st->print_raw("SUBS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".low,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(".low\t\t! long\n\t");
  st->print_raw("SBCS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void compL_reg_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("TEQ    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".hi,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(".hi\t\t! long\n\t");
  st->print_raw("TEQ.eq ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(".lo");
}
#endif
#ifndef PRODUCT
void compL_reg_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  st->print_raw("SUBS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(".low,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".low\t\t! long\n\t");
  st->print_raw("SBCS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void compL_reg_con_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  st->print_raw("SUBS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".low,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t\t! long\n\t");
  st->print_raw("SBCS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void compL_reg_con_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  st->print_raw("TEQ    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".hi,0\t\t! long\n\t");
  st->print_raw("TEQ.eq ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".lo,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
}
#endif
#ifndef PRODUCT
void compL_reg_con_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// con
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  st->print_raw("RSBS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".low,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // con
  st->print_raw("\t\t! long\n\t");
  st->print_raw("RSCS    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(".hi,0");
}
#endif
#ifndef PRODUCT
void compU_iReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("cmp_32 ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! unsigned");
}
#endif
#ifndef PRODUCT
void compP_iRegPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void compP_iRegP_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// op2
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  st->print_raw("\t! ptr");
}
#endif
#ifndef PRODUCT
void cmovI_reg_ltNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("MOV.lt  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op1
  st->print_raw("\t! min");
}
#endif
#ifndef PRODUCT
void minI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void cmovI_reg_gtNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// op1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// icc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("MOV.gt  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // op2
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // op1
  st->print_raw("\t! max");
}
#endif
#ifndef PRODUCT
void maxI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void cmpF_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPs  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("FMSTAT");
}
#endif
#ifndef PRODUCT
void cmpF0_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPs  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\n\t");
  st->print_raw("FMSTAT");
}
#endif
#ifndef PRODUCT
void cmpD_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPd  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
  st->print_raw("FMSTAT");
}
#endif
#ifndef PRODUCT
void cmpD0_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPZd  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
  st->print_raw("FMSTAT");
}
#endif
#ifndef PRODUCT
void cmpF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPs  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
  st->print_raw("VMRS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", FPSCR \n\t");
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0x08000000 \n\t");
  st->print_raw("EOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" << 3 \n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" >> 30");
}
#endif
#ifndef PRODUCT
void cmpF0_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPZs ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
  st->print_raw("VMRS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", FPSCR \n\t");
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0x08000000 \n\t");
  st->print_raw("EOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" << 3 \n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" >> 30");
}
#endif
#ifndef PRODUCT
void cmpD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPd  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
  st->print_raw("VMRS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", FPSCR \n\t");
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0x08000000 \n\t");
  st->print_raw("EOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" << 3 \n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" >> 30");
}
#endif
#ifndef PRODUCT
void cmpD0_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FCMPZd ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(" \n\t");
  st->print_raw("VMRS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", FPSCR \n\t");
  st->print_raw("OR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0x08000000 \n\t");
  st->print_raw("EOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" << 3 \n\t");
  st->print_raw("MOV    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(" >> 30");
}
#endif
#ifndef PRODUCT
void jumpXtndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// tmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// 
  st->print_raw("ADD    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  char reg[128];  ra->dump_register(in(mach_constant_base_node_input()), reg);
    st->print("%s", reg);
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // switch_val
  st->print_raw("\n\t");
  st->print_raw("LDR    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",[");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(" + ");
  st->print("#%d", constant_offset_unchecked());
  st->print_raw("]\n\t");
  st->print_raw("BX     ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void branchNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// 
  st->print_raw("B     ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // labl
}
#endif
#ifndef PRODUCT
void branchConNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // icc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchCon_EQNELTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // icc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchConUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // icc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchConPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// pcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // pcc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchConL_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// xcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // xcc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchConL_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// xcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // xcc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchConL_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// xcc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // xcc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void branchLoopEndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// icc
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// labl
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// 
  st->print_raw("B");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // icc
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // labl
  st->print_raw("\t! Loop end");
  st->print("  P=%f C=%f",_prob,_fcnt);
}
#endif
#ifndef PRODUCT
void cmpL3_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("CMP    ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".hi, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".hi\t\t! long\n");
  st->print_raw("\tMOV.gt ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 1\n");
  st->print_raw("\tmvn.lt ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0\n");
  st->print_raw("\tB.ne   done\n");
  st->print_raw("\tSUBS   ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".lo, ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".lo\n");
  st->print_raw("\tMOV.hi ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 1\n");
  st->print_raw("\tmvn.lo ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(", 0\n");
  st->print_raw("done:");
}
#endif
#ifndef PRODUCT
void cmovLL_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void cmovLL_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void cmovLL_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".lo\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void cmovLL_imm_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,0\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",0");
}
#endif
#ifndef PRODUCT
void cmovLL_imm_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,0\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",0");
}
#endif
#ifndef PRODUCT
void cmovLL_imm_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(".lo,0\t! long\n\t");
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",0");
}
#endif
#ifndef PRODUCT
void cmovIL_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIL_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIL_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIL_imm_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIL_imm_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovIL_imm_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPL_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPL_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPL_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOV");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPL_imm_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPL_imm_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovPL_imm_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("MOVW");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw("  ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovFL_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovFL_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovFL_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYS");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDL_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDL_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void cmovDL_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cmp
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// xcc
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// dst
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// src
  st->print_raw("FCPYD");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
  st->print_raw(" ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // dst
  st->print_raw(",");
  opnd_array(4)->ext_format(ra, this,idx4, st); // src
}
#endif
#ifndef PRODUCT
void safePoint_pollNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// tmp
  st->print_raw("LDR   ");
      st->print_raw("R_R12");
  st->print_raw(",[");
  opnd_array(1)->ext_format(ra, this,idx1, st); // poll
  st->print_raw("]\t! Safepoint: poll for GC");
  st->print_raw("");
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void CallStaticJavaDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("CALL,static ==> ");
  if( _method ) _method->print_short_name(st);
  else st->print(" wrapper for: %s", _name);
  if( !_method ) dump_trap_args(st);
  st->cr();
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void CallStaticJavaHandleNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("CALL,static/MethodHandle ==> ");
  if( _method ) _method->print_short_name(st);
  else st->print(" wrapper for: %s", _name);
  if( !_method ) dump_trap_args(st);
  st->cr();
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void CallDynamicJavaDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("MOV_OOP    (empty),R_R8\n\t");
  st->print_raw("CALL,dynamic  ; NOP ==> ");
  _method->print_short_name(st);
  st->cr();
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void CallRuntimeDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("CALL,runtime");
  st->print(" %s", _name);  st->cr();
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void CallLeafDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("CALL,runtime leaf");
  st->print(" %s", _name);  st->cr();
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void CallLeafNoFPDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("CALL,runtime leaf nofp");
  st->print(" %s", _name);  st->cr();
  if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
  st->print("        # ");
  if( _jvms && _oop_map ) _oop_map->print_on(st);
}
#endif
#ifndef PRODUCT
void TailCalljmpIndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// method_oop
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// 
  st->print_raw("MOV    Rexception_pc, LR\n\t");
  st->print_raw("jump   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // jump_target
  st->print_raw("  \t! ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // method_oop
  st->print_raw(" holds method oop");
}
#endif
#ifndef PRODUCT
void RetNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("ret LR");
}
#endif
#ifndef PRODUCT
void tailjmpIndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 5;
  unsigned idx1 = 5; 	// ex_oop
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// 
  st->print_raw("MOV    Rexception_pc, LR\n\t");
  st->print_raw("jump   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // jump_target
  st->print_raw(" \t! ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // ex_oop
  st->print_raw(" holds exc. oop");
}
#endif
#ifndef PRODUCT
void CreateExceptionNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("! exception oop is in Rexception_obj; no code emitted");
}
#endif
#ifndef PRODUCT
void RethrowExceptionNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("b    rethrow_stub");
}
#endif
#ifndef PRODUCT
void ShouldNotReachHereNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("breakpoint   ; ShouldNotReachHere");
}
#endif
#ifndef PRODUCT
void partialSubtypeCheckNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  st->print_raw("CALL   PartialSubtypeCheck");
}
#endif
#ifndef PRODUCT
void cmpFastLockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// object
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// box
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// scratch2
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// scratch
  st->print_raw("FASTLOCK  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // object
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // box
  st->print_raw("; KILL ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // scratch
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // scratch2
}
#endif
#ifndef PRODUCT
void cmpFastUnlockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// object
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// box
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// scratch2
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// scratch
  st->print_raw("FASTUNLOCK  ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // object
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // box
  st->print_raw("; KILL ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // scratch
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // scratch2
}
#endif
#ifndef PRODUCT
void clear_arrayNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// cnt
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// base
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// temp
  unsigned idx4 = idx3 + opnd_array(3)->num_edges(); 	// zero
  st->print_raw("MOV    ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // zero
  st->print_raw(",0\n");
  st->print_raw("        MOV    ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // temp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cnt
  st->print_raw("\n");
  st->print_raw("loop:   SUBS   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // temp
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // temp
  st->print_raw(",4\t! Count down a dword of bytes\n");
  st->print_raw("        STR.ge ");
  opnd_array(4)->ext_format(ra, this,idx4, st); // zero
  st->print_raw(",[");
  opnd_array(2)->ext_format(ra, this,idx2, st); // base
  st->print_raw("+");
  opnd_array(3)->ext_format(ra, this,idx3, st); // temp
  st->print_raw("]\t! delay slot");
  st->print_raw("        B.gt   loop\t\t! Clearing loop\n");
}
#endif
#ifndef PRODUCT
void countLeadingZerosINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("CLZ_32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void countLeadingZerosLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  st->print_raw("CLZ    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi\n\t");
  st->print_raw("TEQ    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",32\n\t");
  st->print_raw("CLZ.eq ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo\n\t");
  st->print_raw("ADD.eq ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(", ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw("\n\t");
}
#endif
#ifndef PRODUCT
void countTrailingZerosINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("RBIT_32 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("CLZ_32  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void countTrailingZerosLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  unsigned idx3 = idx2 + opnd_array(2)->num_edges(); 	// tmp
  st->print_raw("RBIT   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo\n\t");
  st->print_raw("CLZ    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("TEQ    ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",32\n\t");
  st->print_raw("RBIT   ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi\n\t");
  st->print_raw("CLZ.eq ");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("ADD.eq ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(",");
  opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  st->print_raw("\n\t");
}
#endif
#ifndef PRODUCT
void popCountINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("FMSR       ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("VCNT.8     ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("VPADDL.U8  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("VPADDL.U16 ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("FMRS       ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void popCountLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("FMDRR       ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi\n\t");
  st->print_raw("VCNT.8      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("VPADDL.U8   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("VPADDL.U16  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("VPADDL.U32  ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("FMRS        ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
}
#endif
#ifndef PRODUCT
void bytes_reverse_intNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("REV32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void bytes_reverse_longNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// dst
  st->print_raw("REV ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo\n\t");
  st->print_raw("REV ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void bytes_reverse_unsigned_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("REV16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void bytes_reverse_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("REVSH ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void loadV8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("FLDD   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw(",");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw("\t! load vector (8 bytes)");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void loadV16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  st->print_raw("VLD1   ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw(",");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q\t! load vector (16 bytes)");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeV8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("FSTD   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! store vector (8 bytes)");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void storeV16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 2;
  unsigned idx1 = 2; 	// mem
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src
  st->print_raw("VST1   ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  st->print_raw("\t! store vector (16 bytes)");
  if (ra->C->alias_type(adr_type())->field() != NULL) {
    ciField* f = ra->C->alias_type(adr_type())->field();
    st->print(" ! Field: ");
    if (f->is_volatile())
      st->print("volatile ");
    f->holder()->name()->print_symbol_on(st);
    st->print(".");
    f->name()->print_symbol_on(st);
    if (f->is_constant())
      st->print(" (constant)");
  } else {
    if (ra->C->alias_type(adr_type())->is_volatile())
      st->print(" volatile!");
  }
}
#endif
#ifndef PRODUCT
void Repl8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("LSL      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(", 24 \n\t");
  st->print_raw("OR       ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", (");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(" >> 8) \n\t");
  st->print_raw("OR       ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", (");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(" >> 16) \n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl8B_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl8B_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("MOV      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", Repl4(");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("))\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl8B_immU8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VMOV.U8  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl16B_immU8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VMOV.U8  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("LSL      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(", 16 \n\t");
  st->print_raw("OR       ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", (");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(" >> 16) \n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl4S_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl4S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("MOV      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", Repl2(");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("))\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl4S_immU8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VMOV.U16  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl8S_immU8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VMOV.U16  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".hi,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl2I_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl4I_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl2I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("MOV      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", Repl1(");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("))\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl2I_immU8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VMOV.I32  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl4I_immU8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VMOV.I32  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
}
#endif
#ifndef PRODUCT
void Repl2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMDRR ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi\t\n");
  st->print_raw("FMDRR ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.next,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".lo,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".hi");
}
#endif
#ifndef PRODUCT
void Repl2F_regINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl2F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void Repl2F_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.32  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D\t");
}
#endif
#ifndef PRODUCT
void Repl4F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("FMRS     ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.next,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl4F_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VDUP.32  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D\t");
}
#endif
#ifndef PRODUCT
void Repl2F_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// tmp
  st->print_raw("MOV      ");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(", Repl1(");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("))\n\t");
  st->print_raw("FMDRR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void Repl2D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("FCPYD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\n\t");
  st->print_raw("FCPYD    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw("\t");
}
#endif
#ifndef PRODUCT
void vadd8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! add packed8B");
}
#endif
#ifndef PRODUCT
void vadd16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! add packed16B");
}
#endif
#ifndef PRODUCT
void vadd4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! add packed4S");
}
#endif
#ifndef PRODUCT
void vadd8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! add packed8S");
}
#endif
#ifndef PRODUCT
void vadd2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D\t! add packed2I");
}
#endif
#ifndef PRODUCT
void vadd4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! add packed4I");
}
#endif
#ifndef PRODUCT
void vadd2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.I64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! add packed2L");
}
#endif
#ifndef PRODUCT
void vadd2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.F32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! add packed2F");
}
#endif
#ifndef PRODUCT
void vadd2F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b");
}
#endif
#ifndef PRODUCT
void vadd4F_reg_simdNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VADD.F32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! add packed4F");
}
#endif
#ifndef PRODUCT
void vadd4F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b\n\t");
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".c,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".c,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".c\n\t");
  st->print_raw("FADDS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".d,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".d,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".d");
}
#endif
#ifndef PRODUCT
void vadd2D_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FADDD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FADDD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b");
}
#endif
#ifndef PRODUCT
void vsub8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! sub packed8B");
}
#endif
#ifndef PRODUCT
void vsub16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! sub packed16B");
}
#endif
#ifndef PRODUCT
void vsub4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! sub packed4S");
}
#endif
#ifndef PRODUCT
void vsub16S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! sub packed8S");
}
#endif
#ifndef PRODUCT
void vsub2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! sub packed2I");
}
#endif
#ifndef PRODUCT
void vsub4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! sub packed4I");
}
#endif
#ifndef PRODUCT
void vsub2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.I64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! sub packed2L");
}
#endif
#ifndef PRODUCT
void vsub2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.F32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! sub packed2F");
}
#endif
#ifndef PRODUCT
void vsub2F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b");
}
#endif
#ifndef PRODUCT
void vsub4F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VSUB.F32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! sub packed4F");
}
#endif
#ifndef PRODUCT
void vsub4F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b\n\t");
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".c,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".c,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".c\n\t");
  st->print_raw("FSUBS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".d,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".d,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".d");
}
#endif
#ifndef PRODUCT
void vsub2D_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FSUBD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FSUBD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b");
}
#endif
#ifndef PRODUCT
void vmul4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VMUL.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! mul packed4S");
}
#endif
#ifndef PRODUCT
void vmul8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VMUL.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! mul packed8S");
}
#endif
#ifndef PRODUCT
void vmul2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VMUL.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! mul packed2I");
}
#endif
#ifndef PRODUCT
void vmul4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VMUL.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! mul packed4I");
}
#endif
#ifndef PRODUCT
void vmul2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VMUL.F32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(",");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(",");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw("\t! mul packed2F");
}
#endif
#ifndef PRODUCT
void vmul2F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b");
}
#endif
#ifndef PRODUCT
void vmul4F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VMUL.F32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! mul packed4F");
}
#endif
#ifndef PRODUCT
void vmul4F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b\n\t");
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".c,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".c,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".c\n\t");
  st->print_raw("FMULS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".d,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".d,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".d");
}
#endif
#ifndef PRODUCT
void vmul2D_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FMULD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D.a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D.a\n\t");
  st->print_raw("FMULD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D.b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D.b");
}
#endif
#ifndef PRODUCT
void vdiv2F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b");
}
#endif
#ifndef PRODUCT
void vdiv4F_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".a\n\t");
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".b\n\t");
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".c,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".c,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".c\n\t");
  st->print_raw("FDIVS  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".d,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".d,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".d");
}
#endif
#ifndef PRODUCT
void vdiv2D_reg_vfpNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("FDIVD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.a,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D.a,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D.a\n\t");
  st->print_raw("FDIVD  ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D.b,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D.b,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D.b");
}
#endif
#ifndef PRODUCT
void vneg8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VNEG.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D\t! neg packed8B");
}
#endif
#ifndef PRODUCT
void vneg16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  st->print_raw("VNEG.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q\t! neg0 packed16B");
}
#endif
#ifndef PRODUCT
void vslcntDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vslcntXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsrcntDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cnt
  st->print_raw("VDUP.8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cnt
  st->print_raw("\n\t");
  st->print_raw("VNEG.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D\t! neg packed8B");
}
#endif
#ifndef PRODUCT
void vsrcntXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// cnt
  st->print_raw("VDUP.8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // cnt
  st->print_raw("\n\t");
  st->print_raw("VNEG.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q\t! neg packed16B");
}
#endif
#ifndef PRODUCT
void vsh8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".D\t! logical left/right shift packed8B");
}
#endif
#ifndef PRODUCT
void vsh16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! logical left/right shift packed16B");
}
#endif
#ifndef PRODUCT
void vsh4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".D\t! logical left/right shift packed4S");
}
#endif
#ifndef PRODUCT
void vsh8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! logical left/right shift packed8S");
}
#endif
#ifndef PRODUCT
void vsh2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".D\t! logical left/right shift packed2I");
}
#endif
#ifndef PRODUCT
void vsh4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! logical left/right shift packed4I");
}
#endif
#ifndef PRODUCT
void vsh2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.U64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! logical left/right shift packed2L");
}
#endif
#ifndef PRODUCT
void vsl8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl8B_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed8B");
}
#endif
#ifndef PRODUCT
void vsl16B_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed16B");
}
#endif
#ifndef PRODUCT
void vsl4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl4S_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl8S_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl4S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed4S");
}
#endif
#ifndef PRODUCT
void vsl8S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed8S");
}
#endif
#ifndef PRODUCT
void vsl2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl2I_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl4I_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl2I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed2I");
}
#endif
#ifndef PRODUCT
void vsl4I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed4I");
}
#endif
#ifndef PRODUCT
void vsl2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl2L_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsl2L_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.I64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical left shift packed2L");
}
#endif
#ifndef PRODUCT
void vsrl4S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.U16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed4S");
}
#endif
#ifndef PRODUCT
void vsrl8S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.U16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed8S");
}
#endif
#ifndef PRODUCT
void vsrl2I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.U32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed2I");
}
#endif
#ifndef PRODUCT
void vsrl4I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.U32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed4I");
}
#endif
#ifndef PRODUCT
void vsrl2L_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.U64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed2L");
}
#endif
#ifndef PRODUCT
void vsha8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".D\t! arithmetic right shift packed8B");
}
#endif
#ifndef PRODUCT
void vsha16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! arithmetic right shift packed16B");
}
#endif
#ifndef PRODUCT
void vsha4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".D\t! arithmetic right shift packed4S");
}
#endif
#ifndef PRODUCT
void vsha8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! arithmetic right shift packed8S");
}
#endif
#ifndef PRODUCT
void vsha2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".D\t! arithmetic right shift packed2I");
}
#endif
#ifndef PRODUCT
void vsha4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! arithmetic right shift packed4I");
}
#endif
#ifndef PRODUCT
void vsha2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHL.S64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw(".Q\t! arithmetic right shift packed2L");
}
#endif
#ifndef PRODUCT
void vsra8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsrl16B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsrl8B_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed8B");
}
#endif
#ifndef PRODUCT
void vsrl16B_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S8 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed16B");
}
#endif
#ifndef PRODUCT
void vsra4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsra8S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsra4S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed4S");
}
#endif
#ifndef PRODUCT
void vsra8S_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S16 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed8S");
}
#endif
#ifndef PRODUCT
void vsra2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsra4I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsra2I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed2I");
}
#endif
#ifndef PRODUCT
void vsra4I_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S32 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed4I");
}
#endif
#ifndef PRODUCT
void vsra2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
}
#endif
#ifndef PRODUCT
void vsra2L_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// shift
  st->print_raw("VSHR.S64 ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  st->print_raw("\t! logical right shift packed2L");
}
#endif
#ifndef PRODUCT
void vandDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VAND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D\t! and vectors (8 bytes)");
}
#endif
#ifndef PRODUCT
void vandXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VAND    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! and vectors (16 bytes)");
}
#endif
#ifndef PRODUCT
void vorDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VOR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D\t! and vectors (8 bytes)");
}
#endif
#ifndef PRODUCT
void vorXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VOR     ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! and vectors (16 bytes)");
}
#endif
#ifndef PRODUCT
void vxorDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VXOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".D,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".D,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".D\t! and vectors (8 bytes)");
}
#endif
#ifndef PRODUCT
void vxorXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  // Start at oper_input_base() and count operands
  unsigned idx0 = 1;
  unsigned idx1 = 1; 	// src1
  unsigned idx2 = idx1 + opnd_array(1)->num_edges(); 	// src2
  st->print_raw("VXOR    ");
  opnd_array(0)->int_format(ra, this, st); // dst
  st->print_raw(".Q,");
  opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  st->print_raw(".Q,");
  opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  st->print_raw(".Q\t! and vectors (16 bytes)");
}
#endif
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
