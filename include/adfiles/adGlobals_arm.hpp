#line 1 "adGlobals_arm.hpp"
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


#ifndef GENERATED_ADFILES_ADGLOBALS_HPP
#define GENERATED_ADFILES_ADGLOBALS_HPP


// the number of reserved registers + machine registers.
#define REG_COUNT    82

// the number of save_on_entry + always_saved registers.
#define MAX_SAVED_ON_ENTRY_REG_COUNT    24
#define     SAVED_ON_ENTRY_REG_COUNT    0
#define   C_SAVED_ON_ENTRY_REG_COUNT    24

// Enumerate machine register numbers starting after reserved regs.
// in the order of occurrence in the register block.
enum MachRegisterNumbers {
  R_R4_num,                 // enum   0, regnum   0, reg encode   4
  R_R5_num,                 // enum   1, regnum   1, reg encode   5
  R_R6_num,                 // enum   2, regnum   2, reg encode   6
  R_R7_num,                 // enum   3, regnum   3, reg encode   7
  R_R8_num,                 // enum   4, regnum   4, reg encode   8
  R_R9_num,                 // enum   5, regnum   5, reg encode   9
  R_R11_num,                // enum   6, regnum   6, reg encode  11
  R_R12_num,                // enum   7, regnum   7, reg encode  12
  R_R10_num,                // enum   8, regnum   8, reg encode  10
  R_R13_num,                // enum   9, regnum   9, reg encode  13
  R_R14_num,                // enum  10, regnum  10, reg encode  14
  R_R15_num,                // enum  11, regnum  11, reg encode  15
  R_R0_num,                 // enum  12, regnum  12, reg encode   0
  R_R1_num,                 // enum  13, regnum  13, reg encode   1
  R_R2_num,                 // enum  14, regnum  14, reg encode   2
  R_R3_num,                 // enum  15, regnum  15, reg encode   3
  R_S16_num,                // enum  16, regnum  16, reg encode  16
  R_S17_num,                // enum  17, regnum  17, reg encode  17
  R_S18_num,                // enum  18, regnum  18, reg encode  18
  R_S19_num,                // enum  19, regnum  19, reg encode  19
  R_S20_num,                // enum  20, regnum  20, reg encode  20
  R_S21_num,                // enum  21, regnum  21, reg encode  21
  R_S22_num,                // enum  22, regnum  22, reg encode  22
  R_S23_num,                // enum  23, regnum  23, reg encode  23
  R_S24_num,                // enum  24, regnum  24, reg encode  24
  R_S25_num,                // enum  25, regnum  25, reg encode  25
  R_S26_num,                // enum  26, regnum  26, reg encode  26
  R_S27_num,                // enum  27, regnum  27, reg encode  27
  R_S28_num,                // enum  28, regnum  28, reg encode  28
  R_S29_num,                // enum  29, regnum  29, reg encode  29
  R_S30_num,                // enum  30, regnum  30, reg encode  30
  R_S31_num,                // enum  31, regnum  31, reg encode  31
  R_S0_num,                 // enum  32, regnum  32, reg encode   0
  R_S1_num,                 // enum  33, regnum  33, reg encode   1
  R_S2_num,                 // enum  34, regnum  34, reg encode   2
  R_S3_num,                 // enum  35, regnum  35, reg encode   3
  R_S4_num,                 // enum  36, regnum  36, reg encode   4
  R_S5_num,                 // enum  37, regnum  37, reg encode   5
  R_S6_num,                 // enum  38, regnum  38, reg encode   6
  R_S7_num,                 // enum  39, regnum  39, reg encode   7
  R_S8_num,                 // enum  40, regnum  40, reg encode   8
  R_S9_num,                 // enum  41, regnum  41, reg encode   9
  R_S10_num,                // enum  42, regnum  42, reg encode  10
  R_S11_num,                // enum  43, regnum  43, reg encode  11
  R_S12_num,                // enum  44, regnum  44, reg encode  12
  R_S13_num,                // enum  45, regnum  45, reg encode  13
  R_S14_num,                // enum  46, regnum  46, reg encode  14
  R_S15_num,                // enum  47, regnum  47, reg encode  15
  R_D16_num,                // enum  48, regnum  48, reg encode  32
  R_D16x_num,               // enum  49, regnum  49, reg encode 255
  R_D17_num,                // enum  50, regnum  50, reg encode  34
  R_D17x_num,               // enum  51, regnum  51, reg encode 255
  R_D18_num,                // enum  52, regnum  52, reg encode  36
  R_D18x_num,               // enum  53, regnum  53, reg encode 255
  R_D19_num,                // enum  54, regnum  54, reg encode  38
  R_D19x_num,               // enum  55, regnum  55, reg encode 255
  R_D20_num,                // enum  56, regnum  56, reg encode  40
  R_D20x_num,               // enum  57, regnum  57, reg encode 255
  R_D21_num,                // enum  58, regnum  58, reg encode  42
  R_D21x_num,               // enum  59, regnum  59, reg encode 255
  R_D22_num,                // enum  60, regnum  60, reg encode  44
  R_D22x_num,               // enum  61, regnum  61, reg encode 255
  R_D23_num,                // enum  62, regnum  62, reg encode  46
  R_D23x_num,               // enum  63, regnum  63, reg encode 255
  R_D24_num,                // enum  64, regnum  64, reg encode  48
  R_D24x_num,               // enum  65, regnum  65, reg encode 255
  R_D25_num,                // enum  66, regnum  66, reg encode  50
  R_D25x_num,               // enum  67, regnum  67, reg encode 255
  R_D26_num,                // enum  68, regnum  68, reg encode  52
  R_D26x_num,               // enum  69, regnum  69, reg encode 255
  R_D27_num,                // enum  70, regnum  70, reg encode  54
  R_D27x_num,               // enum  71, regnum  71, reg encode 255
  R_D28_num,                // enum  72, regnum  72, reg encode  56
  R_D28x_num,               // enum  73, regnum  73, reg encode 255
  R_D29_num,                // enum  74, regnum  74, reg encode  58
  R_D29x_num,               // enum  75, regnum  75, reg encode 255
  R_D30_num,                // enum  76, regnum  76, reg encode  60
  R_D30x_num,               // enum  77, regnum  77, reg encode 255
  R_D31_num,                // enum  78, regnum  78, reg encode  62
  R_D31x_num,               // enum  79, regnum  79, reg encode 255
  APSR_num,                 // enum  80, regnum  80, reg encode   0
  FPSCR_num,                // enum  81, regnum  81, reg encode   0
  _last_Mach_Reg            // 82
};

// Size of register-mask in ints
#define RM_SIZE 6
// Unroll factor for loops over the data in a RegMask
#define FORALL_BODY BODY(0) BODY(1) BODY(2) BODY(3) BODY(4) BODY(5) 

class RegMask;

#endif // GENERATED_ADFILES_ADGLOBALS_HPP
