#line 1 "ad_arm_pipeline.cpp"
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

//------------------Pipeline Methods-----------------------------------------
#ifndef PRODUCT
const char * Pipeline::stageName(uint s) {
  static const char * const _stage_names[] = {
    "undefined", "A", "P", "F", "B", "I", "J", "S", "R", "E", "C", "M", "W", "X", "T", "D"
  };

  return (s <= 15 ? _stage_names[s] : "???");
}
#endif

uint Pipeline::functional_unit_latency(uint start, const Pipeline *pred) const {
  // See if the functional units overlap
  uint mask = resourcesUsedExclusively() & pred->resourcesUsedExclusively();
  if (mask == 0)
    return (start);

  for (uint i = 0; i < pred->resourceUseCount(); i++) {
    const Pipeline_Use_Element *predUse = pred->resourceUseElement(i);
    if (predUse->multiple())
      continue;

    for (uint j = 0; j < resourceUseCount(); j++) {
      const Pipeline_Use_Element *currUse = resourceUseElement(j);
      if (currUse->multiple())
        continue;

      if (predUse->used() & currUse->used()) {
        Pipeline_Use_Cycle_Mask x = predUse->mask();
        Pipeline_Use_Cycle_Mask y = currUse->mask();

        for ( y <<= start; x.overlaps(y); start++ )
          y <<= 1;
      }
    }
  }

  // There is the potential for overlap
  return (start);
}

// The following two routines assume that the root Pipeline_Use entity
// consists of exactly 1 element for each functional unit
// start is relative to the current cycle; used for latency-based info
uint Pipeline_Use::full_latency(uint delay, const Pipeline_Use &pred) const {
  for (uint i = 0; i < pred._count; i++) {
    const Pipeline_Use_Element *predUse = pred.element(i);
    if (predUse->_multiple) {
      uint min_delay = 78;
      // Multiple possible functional units, choose first unused one
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        const Pipeline_Use_Element *currUse = element(j);
        uint curr_delay = delay;
        if (predUse->_used & currUse->_used) {
          Pipeline_Use_Cycle_Mask x = predUse->_mask;
          Pipeline_Use_Cycle_Mask y = currUse->_mask;

          for ( y <<= curr_delay; x.overlaps(y); curr_delay++ )
            y <<= 1;
        }
        if (min_delay > curr_delay)
          min_delay = curr_delay;
      }
      if (delay < min_delay)
      delay = min_delay;
    }
    else {
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        const Pipeline_Use_Element *currUse = element(j);
        if (predUse->_used & currUse->_used) {
          Pipeline_Use_Cycle_Mask x = predUse->_mask;
          Pipeline_Use_Cycle_Mask y = currUse->_mask;

          for ( y <<= delay; x.overlaps(y); delay++ )
            y <<= 1;
        }
      }
    }
  }

  return (delay);
}

void Pipeline_Use::add_usage(const Pipeline_Use &pred) {
  for (uint i = 0; i < pred._count; i++) {
    const Pipeline_Use_Element *predUse = pred.element(i);
    if (predUse->_multiple) {
      // Multiple possible functional units, choose first unused one
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        Pipeline_Use_Element *currUse = element(j);
        if ( !predUse->_mask.overlaps(currUse->_mask) ) {
          currUse->_used |= (1 << j);
          _resources_used |= (1 << j);
          currUse->_mask.Or(predUse->_mask);
          break;
        }
      }
    }
    else {
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        Pipeline_Use_Element *currUse = element(j);
        currUse->_used |= (1 << j);
        _resources_used |= (1 << j);
        currUse->_mask.Or(predUse->_mask);
      }
    }
  }
}

uint Pipeline::operand_latency(uint opnd, const Pipeline *pred) const {
  int const default_latency = 1;

  assert(this, "NULL pipeline info");
  assert(pred, "NULL predecessor pipline info");

  if (pred->hasFixedLatency())
    return (pred->fixedLatency());

  // If this is not an operand, then assume a dependence with 0 latency
  if (opnd > _read_stage_count)
    return (0);

  uint writeStage = pred->_write_stage;
  uint readStage  = _read_stages[opnd-1];

  if (writeStage == stage_undefined || readStage == stage_undefined)
    return (default_latency);

  int delta = writeStage - readStage;
  if (delta < 0) delta = 0;

  return (delta);
}

Pipeline_Use_Cycle_Mask operator&(const Pipeline_Use_Cycle_Mask &in1, const Pipeline_Use_Cycle_Mask &in2) {
  return Pipeline_Use_Cycle_Mask(in1._mask1 & in2._mask1, 
in1._mask2 & in2._mask2, 
in1._mask3 & in2._mask3
);
}

Pipeline_Use_Cycle_Mask operator|(const Pipeline_Use_Cycle_Mask &in1, const Pipeline_Use_Cycle_Mask &in2) {
  return Pipeline_Use_Cycle_Mask(in1._mask1 | in2._mask1, in1._mask2 | in2._mask2, in1._mask3 | in2._mask3);
}

void Pipeline_Use_Cycle_Mask::Or(const Pipeline_Use_Cycle_Mask &in2) {
  _mask1 |= in2._mask1; _mask2 |= in2._mask2; _mask3 |= in2._mask3;
}

static const Pipeline pipeline_class_Zero_Instructions(0, 0, true, 0, 0, false, false, false, false, NULL, NULL, NULL, Pipeline_Use(0, 0, 0, NULL));

static const Pipeline pipeline_class_Unknown_Instructions(0, 0, true, 0, 0, false, true, true, false, NULL, NULL, NULL, Pipeline_Use(0, 0, 0, NULL));

const Pipeline_Use_Element Pipeline_Use::elaborated_elements[8] = {
  Pipeline_Use_Element(0, 0, 0, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 1, 1, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 2, 2, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 3, 3, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 4, 4, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 5, 5, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 6, 6, false, Pipeline_Use_Cycle_Mask(0, 0, 0)),
  Pipeline_Use_Element(0, 7, 7, false, Pipeline_Use_Cycle_Mask(0, 0, 0))
};

const Pipeline_Use Pipeline_Use::elaborated_use(0, 0, 8, (Pipeline_Use_Element *)&elaborated_elements[0]);


// Pipeline Class "ialu_reg_reg"
static const enum machPipelineStages pipeline_reads_001[2] = {
  stage_R,
  stage_R 
};

static const enum machPipelineStages pipeline_res_stages_001[8] = {
  stage_R,         // A0
  stage_R,         // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_001[8] = {
  1, // A0
  1, // A1
  0, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_001[1] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_001((uint)stage_E, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_reg_2"
static const Pipeline_Use_Element pipeline_res_mask_002[2] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_002((uint)stage_E, 2, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 2, (Pipeline_Use_Element *)&pipeline_res_mask_002[0]));

// Pipeline Class "ialu_reg_reg_2_dep"
static const enum machPipelineStages pipeline_reads_002[3] = {
  stage_R,
  stage_R,
  stage_E 
};

static const uint pipeline_res_cycles_002[8] = {
  2, // A0
  2, // A1
  0, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_003[1] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)) 
};

static const Pipeline pipeline_class_003((uint)stage_E, 3, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_002,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_002,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_003[0]));

// Pipeline Class "ialu_reg_imm"
static const enum machPipelineStages pipeline_reads_003[1] = {
  stage_R 
};

static const Pipeline pipeline_class_004((uint)stage_E, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cc_reg_reg"
static const Pipeline pipeline_class_005((uint)stage_E, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_002,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_zero_reg"
static const enum machPipelineStages pipeline_reads_004[2] = {
  stage_undefined,
  stage_R 
};

static const Pipeline pipeline_class_006((uint)stage_E, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_004,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cconly_zero_reg"
static const Pipeline pipeline_class_007((uint)stage_E, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cconly_reg_reg"
static const Pipeline pipeline_class_008((uint)stage_E, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cconly_reg_imm"
static const Pipeline pipeline_class_009((uint)stage_E, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cconly_reg_reg_zero"
static const enum machPipelineStages pipeline_reads_005[3] = {
  stage_R,
  stage_R,
  stage_undefined 
};

static const Pipeline pipeline_class_010((uint)stage_E, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_005,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cconly_reg_imm_zero"
static const enum machPipelineStages pipeline_reads_006[2] = {
  stage_R,
  stage_undefined 
};

static const Pipeline pipeline_class_011((uint)stage_E, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cc_rwreg_reg"
static const Pipeline pipeline_class_012((uint)stage_E, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "cmpL_reg"
static const enum machPipelineStages pipeline_res_stages_002[8] = {
  stage_R,         // A0
  stage_R,         // A1
  stage_undefined, // MS
  stage_R,         // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_003[8] = {
  3, // A0
  3, // A1
  0, // MS
  2, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_004[2] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000001c0)),
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)) 
};

static const Pipeline pipeline_class_013(((uint)stage_E)+4, 3, false, 0, 0, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_002,
   (enum machPipelineStages * const) pipeline_res_stages_002,
  (uint * const) pipeline_res_cycles_003,
  Pipeline_Use(0x0b, 0x08, 2, (Pipeline_Use_Element *)&pipeline_res_mask_004[0]));

// Pipeline Class "ialu_none"
static const Pipeline pipeline_class_014((uint)stage_E, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg"
static const Pipeline pipeline_class_015((uint)stage_E, 1, false, 0, 1, false, false, false, true,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_flags"
static const enum machPipelineStages pipeline_reads_007[3] = {
  stage_undefined,
  stage_R,
  stage_R 
};

static const enum machPipelineStages pipeline_res_stages_003[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_R,         // MS
  stage_R,         // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_004[8] = {
  0, // A0
  0, // A1
  2, // MS
  2, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_005[2] = {
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)),
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)) 
};

static const Pipeline pipeline_class_016((uint)stage_C, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_007,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_004,
  Pipeline_Use(0x0c, 0x0c, 2, (Pipeline_Use_Element *)&pipeline_res_mask_005[0]));

// Pipeline Class "ialu_move_reg_L_to_I"
static const Pipeline pipeline_class_017((uint)stage_E, 1, false, 0, 1, false, false, false, true,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_move_reg_I_to_L"
static const Pipeline pipeline_class_018((uint)stage_E, 1, false, 0, 1, false, false, false, true,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_2"
static const Pipeline_Use_Element pipeline_res_mask_006[2] = {
  Pipeline_Use_Element(0x01,  0,  0, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x02,  1,  1, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_019((uint)stage_E, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x03, 2, (Pipeline_Use_Element *)&pipeline_res_mask_006[0]));

// Pipeline Class "ialu_move_reg_L_to_L"
static const Pipeline pipeline_class_020((uint)stage_E, 1, false, 0, 2, false, false, false, true,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x03, 2, (Pipeline_Use_Element *)&pipeline_res_mask_006[0]));

// Pipeline Class "ialu_imm"
static const Pipeline pipeline_class_021((uint)stage_E, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_imm_n"
static const Pipeline pipeline_class_022((uint)stage_E, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_reg_cy"
static const Pipeline pipeline_class_023((uint)stage_E, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_005,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cc"
static const Pipeline pipeline_class_024((uint)stage_E, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_ialu"
static const Pipeline pipeline_class_025(((uint)stage_E)+1, 1, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_reg_ialu"
static const Pipeline pipeline_class_026(((uint)stage_E)+1, 2, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_hi_lo_reg"
static const enum machPipelineStages pipeline_reads_008[1] = {
  stage_undefined 
};

static const Pipeline pipeline_class_027(((uint)stage_E)+1, 1, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_002,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_003[0]));

// Pipeline Class "loadConL"
static const Pipeline_Use_Element pipeline_res_mask_007[2] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)),
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)) 
};

static const Pipeline pipeline_class_028(((uint)stage_E)+1, 1, false, 0, 2, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_002,
  Pipeline_Use(0x03, 0x00, 2, (Pipeline_Use_Element *)&pipeline_res_mask_007[0]));

// Pipeline Class "loadConP"
static const enum machPipelineStages pipeline_res_stages_004[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_005[8] = {
  0, // A0
  0, // A1
  0, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline pipeline_class_029((uint)stage_undefined, 1, true, 6, 0, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_004,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x00, 0x00, 0, (Pipeline_Use_Element *)NULL));

// Pipeline Class "loadConP_poll"
static const Pipeline pipeline_class_030((uint)stage_E, 1, false, 0, 0, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "loadConLlo"
static const Pipeline pipeline_class_031((uint)stage_E, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 2, (Pipeline_Use_Element *)&pipeline_res_mask_002[0]));

// Pipeline Class "loadConFD"
static const enum machPipelineStages pipeline_res_stages_005[8] = {
  stage_R,         // A0
  stage_R,         // A1
  stage_E,         // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_006[8] = {
  1, // A0
  1, // A1
  1, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_009[2] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000080)) 
};

static const Pipeline pipeline_class_032(((uint)stage_M)+1, 2, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_005,
  (uint * const) pipeline_res_cycles_006,
  Pipeline_Use(0x07, 0x04, 2, (Pipeline_Use_Element *)&pipeline_res_mask_009[0]));

// Pipeline Class "ialu_nop"
static const Pipeline pipeline_class_033((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_nop_A0"
static const enum machPipelineStages pipeline_res_stages_006[8] = {
  stage_R,         // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_007[8] = {
  1, // A0
  0, // A1
  0, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_010[1] = {
  Pipeline_Use_Element(0x01,  0,  0, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_034((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_006,
  (uint * const) pipeline_res_cycles_007,
  Pipeline_Use(0x01, 0x01, 1, (Pipeline_Use_Element *)&pipeline_res_mask_010[0]));

// Pipeline Class "ialu_nop_A1"
static const enum machPipelineStages pipeline_res_stages_007[8] = {
  stage_undefined, // A0
  stage_R,         // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_008[8] = {
  0, // A0
  1, // A1
  0, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_011[1] = {
  Pipeline_Use_Element(0x02,  1,  1, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_035((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_007,
  (uint * const) pipeline_res_cycles_008,
  Pipeline_Use(0x02, 0x02, 1, (Pipeline_Use_Element *)&pipeline_res_mask_011[0]));

// Pipeline Class "imul_reg_reg"
static const enum machPipelineStages pipeline_res_stages_008[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_R,         // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_009[8] = {
  0, // A0
  0, // A1
  5, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_012[1] = {
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000007c0)) 
};

static const Pipeline pipeline_class_036((uint)stage_E, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_009,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_012[0]));

// Pipeline Class "mulL_reg_reg"
static const uint pipeline_res_cycles_010[8] = {
  0, // A0
  0, // A1
  6, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_013[1] = {
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000fc0)) 
};

static const Pipeline pipeline_class_037(((uint)stage_E)+4, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_010,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_013[0]));

// Pipeline Class "sdiv_reg_reg"
static const enum machPipelineStages pipeline_reads_009[4] = {
  stage_R,
  stage_R,
  stage_R,
  stage_undefined 
};

static const uint pipeline_res_cycles_011[8] = {
   0, // A0
   0, // A1
  38, // MS
   0, // BR
   0, // FA
   0, // FM
   0, // IDIV
   0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_014[1] = {
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000fff, 0xffffffc0)) 
};

static const Pipeline pipeline_class_038((uint)stage_E, 4, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_009,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_011,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_014[0]));

// Pipeline Class "divL_reg_reg"
static const uint pipeline_res_cycles_012[8] = {
   0, // A0
   0, // A1
  70, // MS
   0, // BR
   0, // FA
   0, // FM
   0, // IDIV
   0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_015[1] = {
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000fff, 0xffffffff, 0xffffffc0)) 
};

static const Pipeline pipeline_class_039(((uint)stage_E)+71, 2, false, 0, 0, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_012,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_015[0]));

// Pipeline Class "faddF_reg_reg"
static const enum machPipelineStages pipeline_reads_010[2] = {
  stage_E,
  stage_E 
};

static const enum machPipelineStages pipeline_res_stages_009[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_R,         // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_013[8] = {
  0, // A0
  0, // A1
  0, // MS
  0, // BR
  1, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_016[1] = {
  Pipeline_Use_Element(0x10,  4,  4, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_040((uint)stage_X, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "faddD_reg_reg"
static const Pipeline pipeline_class_041((uint)stage_X, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "int_conditional_float_move"
static const enum machPipelineStages pipeline_reads_011[3] = {
  stage_R,
  stage_X,
  stage_E 
};

static const enum machPipelineStages pipeline_res_stages_010[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_R,         // BR
  stage_R,         // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_014[8] = {
  0, // A0
  0, // A1
  0, // MS
  2, // BR
  2, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_017[2] = {
  Pipeline_Use_Element(0x10,  4,  4, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)),
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)) 
};

static const Pipeline pipeline_class_042((uint)stage_X, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_011,
   (enum machPipelineStages * const) pipeline_res_stages_010,
  (uint * const) pipeline_res_cycles_014,
  Pipeline_Use(0x18, 0x18, 2, (Pipeline_Use_Element *)&pipeline_res_mask_017[0]));

// Pipeline Class "int_conditional_double_move"
static const Pipeline pipeline_class_043((uint)stage_X, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_011,
   (enum machPipelineStages * const) pipeline_res_stages_010,
  (uint * const) pipeline_res_cycles_014,
  Pipeline_Use(0x18, 0x18, 2, (Pipeline_Use_Element *)&pipeline_res_mask_017[0]));

// Pipeline Class "fmulF_reg_reg"
static const enum machPipelineStages pipeline_res_stages_011[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_R,         // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_015[8] = {
  0, // A0
  0, // A1
  0, // MS
  0, // BR
  0, // FA
  1, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_018[1] = {
  Pipeline_Use_Element(0x20,  5,  5, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_044((uint)stage_X, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_011,
  (uint * const) pipeline_res_cycles_015,
  Pipeline_Use(0x20, 0x20, 1, (Pipeline_Use_Element *)&pipeline_res_mask_018[0]));

// Pipeline Class "fmulD_reg_reg"
static const Pipeline pipeline_class_045((uint)stage_X, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_011,
  (uint * const) pipeline_res_cycles_015,
  Pipeline_Use(0x20, 0x20, 1, (Pipeline_Use_Element *)&pipeline_res_mask_018[0]));

// Pipeline Class "fdivF_reg_reg"
static const enum machPipelineStages pipeline_res_stages_012[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_undefined, // BR
  stage_undefined, // FA
  stage_R,         // FM
  stage_undefined, // IDIV
  stage_C          // FDIV
};

static const uint pipeline_res_cycles_016[8] = {
   0, // A0
   0, // A1
   0, // MS
   0, // BR
   0, // FA
   1, // FM
   0, // IDIV
  14  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_019[2] = {
  Pipeline_Use_Element(0x20,  5,  5, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x80,  7,  7, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x003fff00)) 
};

static const Pipeline pipeline_class_046((uint)stage_X, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_012,
  (uint * const) pipeline_res_cycles_016,
  Pipeline_Use(0xa0, 0xa0, 2, (Pipeline_Use_Element *)&pipeline_res_mask_019[0]));

// Pipeline Class "fdivD_reg_reg"
static const uint pipeline_res_cycles_017[8] = {
   0, // A0
   0, // A1
   0, // MS
   0, // BR
   0, // FA
   1, // FM
   0, // IDIV
  17  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_020[2] = {
  Pipeline_Use_Element(0x20,  5,  5, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x80,  7,  7, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x01ffff00)) 
};

static const Pipeline pipeline_class_047((uint)stage_X, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_012,
  (uint * const) pipeline_res_cycles_017,
  Pipeline_Use(0xa0, 0xa0, 2, (Pipeline_Use_Element *)&pipeline_res_mask_020[0]));

// Pipeline Class "faddF_reg"
static const enum machPipelineStages pipeline_reads_012[1] = {
  stage_E 
};

static const Pipeline pipeline_class_048((uint)stage_W, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "faddD_reg"
static const Pipeline pipeline_class_049((uint)stage_W, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtF2D"
static const Pipeline pipeline_class_050((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtI2D"
static const Pipeline pipeline_class_051((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtLHi2D"
static const Pipeline pipeline_class_052((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtL2D"
static const Pipeline pipeline_class_053((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtL2F"
static const Pipeline pipeline_class_054((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtD2F"
static const Pipeline pipeline_class_055((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtI2L"
static const Pipeline pipeline_class_056((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtD2I"
static const enum machPipelineStages pipeline_reads_013[2] = {
  stage_E,
  stage_undefined 
};

static const Pipeline pipeline_class_057(((uint)stage_X)+6, 2, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_013,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtD2L"
static const Pipeline pipeline_class_058(((uint)stage_X)+6, 2, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_013,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtF2I"
static const Pipeline pipeline_class_059(((uint)stage_X)+6, 2, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_013,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtF2L"
static const Pipeline pipeline_class_060(((uint)stage_X)+6, 2, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_013,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fcvtI2F"
static const Pipeline pipeline_class_061((uint)stage_X, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_012,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "faddF_fcc_reg_reg_zero"
static const enum machPipelineStages pipeline_reads_014[3] = {
  stage_E,
  stage_E,
  stage_undefined 
};

static const Pipeline pipeline_class_062((uint)stage_X, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_014,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "faddD_fcc_reg_reg_zero"
static const Pipeline pipeline_class_063((uint)stage_X, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_014,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fadd_nop"
static const Pipeline pipeline_class_064((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x10, 0x10, 1, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "istore_mem_reg"
static const enum machPipelineStages pipeline_reads_015[2] = {
  stage_R,
  stage_C 
};

static const uint pipeline_res_cycles_018[8] = {
  0, // A0
  0, // A1
  1, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_021[1] = {
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_065((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_015,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "istore_mem_spORreg"
static const Pipeline pipeline_class_066((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_015,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "fstoreF_mem_reg"
static const Pipeline pipeline_class_067((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_015,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "fstoreF_mem_zero"
static const Pipeline pipeline_class_068((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "fstoreD_mem_reg"
static const Pipeline pipeline_class_069((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_015,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "fstoreD_mem_zero"
static const Pipeline pipeline_class_070((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "iload_mem"
static const Pipeline pipeline_class_071((uint)stage_C, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "iload_mask_mem"
static const Pipeline pipeline_class_072((uint)stage_M, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "floadF_mem"
static const Pipeline pipeline_class_073((uint)stage_M, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "floadD_mem"
static const Pipeline pipeline_class_074((uint)stage_M, 1, false, 0, 1, false, true, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "mem_nop"
static const Pipeline pipeline_class_075((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "sethi"
static const Pipeline pipeline_class_076((uint)stage_E, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "loadPollP"
static const Pipeline pipeline_class_077((uint)stage_undefined, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "br"
static const enum machPipelineStages pipeline_res_stages_013[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_undefined, // MS
  stage_R,         // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_019[8] = {
  0, // A0
  0, // A1
  0, // MS
  1, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_022[1] = {
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_078((uint)stage_undefined, 1, false, 0, 1, true, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_013,
  (uint * const) pipeline_res_cycles_019,
  Pipeline_Use(0x08, 0x08, 1, (Pipeline_Use_Element *)&pipeline_res_mask_022[0]));

// Pipeline Class "br_cc"
static const enum machPipelineStages pipeline_reads_016[3] = {
  stage_undefined,
  stage_E,
  stage_undefined 
};

static const Pipeline pipeline_class_079((uint)stage_undefined, 3, false, 0, 1, true, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_016,
   (enum machPipelineStages * const) pipeline_res_stages_013,
  (uint * const) pipeline_res_cycles_019,
  Pipeline_Use(0x08, 0x08, 1, (Pipeline_Use_Element *)&pipeline_res_mask_022[0]));

// Pipeline Class "br_reg"
static const uint pipeline_res_cycles_020[8] = {
  0, // A0
  0, // A1
  1, // MS
  1, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_023[2] = {
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_080((uint)stage_undefined, 3, false, 0, 1, true, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_016,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_020,
  Pipeline_Use(0x0c, 0x0c, 2, (Pipeline_Use_Element *)&pipeline_res_mask_023[0]));

// Pipeline Class "br_nop"
static const Pipeline pipeline_class_081((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_013,
  (uint * const) pipeline_res_cycles_019,
  Pipeline_Use(0x08, 0x08, 1, (Pipeline_Use_Element *)&pipeline_res_mask_022[0]));

// Pipeline Class "simple_call"
static const enum machPipelineStages pipeline_res_stages_014[8] = {
  stage_R,         // A0
  stage_undefined, // A1
  stage_R,         // MS
  stage_R,         // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_021[8] = {
  1, // A0
  0, // A1
  1, // MS
  1, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_024[3] = {
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x01,  0,  0, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_082((uint)stage_undefined, 0, true, 100, 2, false, true, true, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_014,
  (uint * const) pipeline_res_cycles_021,
  Pipeline_Use(0x0d, 0x0d, 3, (Pipeline_Use_Element *)&pipeline_res_mask_024[0]));

// Pipeline Class "compiled_call"
static const Pipeline pipeline_class_083((uint)stage_undefined, 0, true, 100, 1, false, true, true, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "call"
static const Pipeline pipeline_class_084((uint)stage_undefined, 0, true, 100, 0, false, true, true, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_004,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x00, 0x00, 0, (Pipeline_Use_Element *)NULL));

// Pipeline Class "tail_call"
static const Pipeline pipeline_class_085((uint)stage_undefined, 1, true, 100, 1, true, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_020,
  Pipeline_Use(0x0c, 0x0c, 2, (Pipeline_Use_Element *)&pipeline_res_mask_023[0]));

// Pipeline Class "ret"
static const Pipeline pipeline_class_086((uint)stage_undefined, 0, false, 0, 1, true, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_020,
  Pipeline_Use(0x0c, 0x0c, 2, (Pipeline_Use_Element *)&pipeline_res_mask_023[0]));

// Pipeline Class "empty"
static const Pipeline pipeline_class_087((uint)stage_undefined, 0, false, 0, 0, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_004,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x00, 0x00, 0, (Pipeline_Use_Element *)NULL));

// Pipeline Class "long_memory_op"
static const Pipeline pipeline_class_088((uint)stage_undefined, 0, true, 25, 0, false, true, true, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x04, 0x04, 1, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "partial_subtype_check_pipe"
static const enum machPipelineStages pipeline_res_stages_015[8] = {
  stage_R,         // A0
  stage_R,         // A1
  stage_R,         // MS
  stage_R,         // BR
  stage_undefined, // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_022[8] = {
  2, // A0
  2, // A1
  1, // MS
  2, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_025[3] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)),
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)),
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_089((uint)stage_undefined, 2, false, 0, 0, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_015,
  (uint * const) pipeline_res_cycles_022,
  Pipeline_Use(0x0f, 0x0c, 3, (Pipeline_Use_Element *)&pipeline_res_mask_025[0]));

// Pipeline Class "floating_cmp"
static const enum machPipelineStages pipeline_res_stages_016[8] = {
  stage_undefined, // A0
  stage_undefined, // A1
  stage_R,         // MS
  stage_R,         // BR
  stage_R,         // FA
  stage_undefined, // FM
  stage_undefined, // IDIV
  stage_undefined  // FDIV
};

static const uint pipeline_res_cycles_023[8] = {
  0, // A0
  0, // A1
  2, // MS
  2, // BR
  1, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_026[3] = {
  Pipeline_Use_Element(0x10,  4,  4, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x04,  2,  2, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)),
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000000c0)) 
};

static const Pipeline pipeline_class_090((uint)stage_E, 2, false, 0, 0, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_016,
  (uint * const) pipeline_res_cycles_023,
  Pipeline_Use(0x1c, 0x1c, 3, (Pipeline_Use_Element *)&pipeline_res_mask_026[0]));

// Pipeline Class "cadd_cmpltmask"
static const enum machPipelineStages pipeline_reads_017[3] = {
  stage_E,
  stage_E,
  stage_E 
};

static const uint pipeline_res_cycles_024[8] = {
  3, // A0
  3, // A1
  0, // MS
  0, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_027[1] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x000001c0)) 
};

static const Pipeline pipeline_class_091((uint)stage_undefined, 3, false, 0, 0, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_017,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_024,
  Pipeline_Use(0x03, 0x00, 1, (Pipeline_Use_Element *)&pipeline_res_mask_027[0]));

// Pipeline Class "min_max"
static const uint pipeline_res_cycles_025[8] = {
  1, // A0
  1, // A1
  0, // MS
  1, // BR
  0, // FA
  0, // FM
  0, // IDIV
  0  // FDIV
};

static const Pipeline_Use_Element pipeline_res_mask_028[2] = {
  Pipeline_Use_Element(0x03,  0,  1, true,  Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)),
  Pipeline_Use_Element(0x08,  3,  3, false, Pipeline_Use_Cycle_Mask(0x00000000, 0x00000000, 0x00000040)) 
};

static const Pipeline pipeline_class_092((uint)stage_undefined, 2, false, 0, 0, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_002,
  (uint * const) pipeline_res_cycles_025,
  Pipeline_Use(0x0b, 0x08, 2, (Pipeline_Use_Element *)&pipeline_res_mask_028[0]));

//------------------Inter-Instruction Latency--------------------------------
uint Node::latency(uint i) {
  uint j;
  // verify in legal range for inputs
  assert(i < len(), "index not in range");

  // verify input is not null
  Node *pred = in(i);
  if (!pred)
    return 0;

  if (pred->is_Proj())
    pred = pred->in(0);

  // if either node does not have pipeline info, use default
  const Pipeline *predpipe = pred->pipeline();
  assert(predpipe, "no predecessor pipeline info");

  if (predpipe->hasFixedLatency())
    return predpipe->fixedLatency();

  const Pipeline *currpipe = pipeline();
  assert(currpipe, "no pipeline info");

  if (!is_Mach())
    return 0;

  const MachNode *m = as_Mach();
  j = m->oper_input_base();
  if (i < j)
    return currpipe->functional_unit_latency(0, predpipe);

  // determine which operand this is in
  uint n = m->num_opnds();
  int delta = 0;

  uint k;
  for (k = 1; k < n; k++) {
    j += m->_opnds[k]->num_edges();
    if (i < j)
      break;
  }
  if (k < n)
    delta = currpipe->operand_latency(k,predpipe);

  return currpipe->functional_unit_latency(delta, predpipe);
}

// Descriptions for emitting different functional unit nops
void Bundle::initialize_nops(MachNode * nop_list[5]) {
  nop_list[0] = (MachNode *) new Nop_A0Node();
  nop_list[1] = (MachNode *) new Nop_A1Node();
  nop_list[2] = (MachNode *) new Nop_MSNode();
  nop_list[3] = (MachNode *) new Nop_FANode();
  nop_list[4] = (MachNode *) new Nop_BRNode();
};

#ifndef PRODUCT
void Bundle::dump(outputStream *st) const {
  static const char * bundle_flags[] = {
    "",
    "use nop delay",
    "use unconditional delay",
    "use conditional delay",
    "used in conditional delay",
    "used in unconditional delay",
    "used in all conditional delays",
  };

  static const char *resource_names[8] = { "A0", "A1", "MS", "BR", "FA", "FM", "IDIV", "FDIV" };

  bool needs_comma = false;

  if (_flags) {
    st->print("%s", bundle_flags[_flags]);
    needs_comma = true;
  };
  if (instr_count()) {
    st->print("%s%d instr%s", needs_comma ? ", " : "", instr_count(), instr_count() != 1 ? "s" : "");
    needs_comma = true;
  };
  uint r = resources_used();
  if (r) {
    st->print("%sresource%s:", needs_comma ? ", " : "", (r & (r-1)) != 0 ? "s" : "");
    for (uint i = 0; i < 8; i++)
      if ((r & (1 << i)) != 0)
        st->print(" %s", resource_names[i]);
    needs_comma = true;
  };
  st->print("\n");
}
#endif
const Pipeline *                         Node::pipeline_class() { return (&pipeline_class_Zero_Instructions); }
const Pipeline *                         Node::pipeline() const { return (&pipeline_class_Zero_Instructions); }

const Pipeline *                     MachNode::pipeline_class() { return (&pipeline_class_Unknown_Instructions); }
const Pipeline *                     MachNode::pipeline() const { return pipeline_class(); }

const Pipeline * MachNopNode::pipeline() const { return (&pipeline_class_033); }


const Pipeline *                       Nop_A0Node::pipeline_class() { return (&pipeline_class_034); }
const Pipeline *                       Nop_A0Node::pipeline() const { return (&pipeline_class_034); }

const Pipeline *                       Nop_A1Node::pipeline_class() { return (&pipeline_class_035); }
const Pipeline *                       Nop_A1Node::pipeline() const { return (&pipeline_class_035); }

const Pipeline *                       Nop_MSNode::pipeline_class() { return (&pipeline_class_075); }
const Pipeline *                       Nop_MSNode::pipeline() const { return (&pipeline_class_075); }

const Pipeline *                       Nop_FANode::pipeline_class() { return (&pipeline_class_064); }
const Pipeline *                       Nop_FANode::pipeline() const { return (&pipeline_class_064); }

const Pipeline *                       Nop_BRNode::pipeline_class() { return (&pipeline_class_081); }
const Pipeline *                       Nop_BRNode::pipeline() const { return (&pipeline_class_081); }

const Pipeline *                        loadBNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                        loadBNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                      loadB2LNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                      loadB2LNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                       loadUBNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                       loadUBNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                     loadUB2LNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                     loadUB2LNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *               loadUB2L_limmINode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *               loadUB2L_limmINode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                        loadSNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                        loadSNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                      loadS2BNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                      loadS2BNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                      loadS2LNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                      loadS2LNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                       loadUSNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                       loadUSNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                     loadUS2BNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                     loadUS2BNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                     loadUS2LNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                     loadUS2LNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *            loadUS2L_immI_255Node::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *            loadUS2L_immI_255Node::pipeline() const { return (&pipeline_class_071); }

const Pipeline *               loadUS2L_limmINode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *               loadUS2L_limmINode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                        loadINode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                        loadINode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                      loadI2BNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                      loadI2BNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                     loadI2UBNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                     loadI2UBNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                      loadI2SNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                      loadI2SNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                     loadI2USNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                     loadI2USNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *                      loadI2LNode::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *                      loadI2LNode::pipeline() const { return (&pipeline_class_072); }

const Pipeline *             loadI2L_immI_255Node::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *             loadI2L_immI_255Node::pipeline() const { return (&pipeline_class_071); }

const Pipeline *           loadI2L_immI_65535Node::pipeline_class() { return (&pipeline_class_072); }
const Pipeline *           loadI2L_immI_65535Node::pipeline() const { return (&pipeline_class_072); }

const Pipeline *              loadI2L_limmU31Node::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *              loadI2L_limmU31Node::pipeline() const { return (&pipeline_class_071); }

const Pipeline *               loadI2L_immU31Node::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *               loadI2L_immU31Node::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                     loadUI2LNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                     loadUI2LNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                        loadLNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                        loadLNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                 loadL_2instrNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                 loadL_2instrNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *               loadL_volatileNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *               loadL_volatileNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *            loadL_volatile_fpNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *            loadL_volatile_fpNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *              loadL_unalignedNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *              loadL_unalignedNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                    loadRangeNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                    loadRangeNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                        loadPNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                        loadPNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                    loadKlassNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                    loadKlassNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                        loadDNode::pipeline_class() { return (&pipeline_class_074); }
const Pipeline *                        loadDNode::pipeline() const { return (&pipeline_class_074); }

const Pipeline *              loadD_unalignedNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *              loadD_unalignedNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                        loadFNode::pipeline_class() { return (&pipeline_class_073); }
const Pipeline *                        loadFNode::pipeline() const { return (&pipeline_class_073); }

const Pipeline *                     loadConINode::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *                     loadConINode::pipeline() const { return (&pipeline_class_027); }

const Pipeline *                  loadConIMovNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                  loadConIMovNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                 loadConIMovnNode::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *                 loadConIMovnNode::pipeline() const { return (&pipeline_class_022); }

const Pipeline *                   loadConI16Node::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *                   loadConI16Node::pipeline() const { return (&pipeline_class_022); }

const Pipeline *                     loadConPNode::pipeline_class() { return (&pipeline_class_029); }
const Pipeline *                     loadConPNode::pipeline() const { return (&pipeline_class_029); }

const Pipeline *                loadConP_pollNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                loadConP_pollNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                     loadConLNode::pipeline_class() { return (&pipeline_class_028); }
const Pipeline *                     loadConLNode::pipeline() const { return (&pipeline_class_028); }

const Pipeline *                   loadConL16Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                   loadConL16Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                loadConF_imm8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                loadConF_imm8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                     loadConFNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                     loadConFNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                loadConD_imm8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                loadConD_imm8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                     loadConDNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                     loadConDNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *             prefetchAlloc_mpNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *             prefetchAlloc_mpNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *             prefetchAlloc_spNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *             prefetchAlloc_spNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                       storeBNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *                       storeBNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *                      storeCMNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *                      storeCMNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *                       storeCNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *                       storeCNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *                       storeINode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *                       storeINode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *                       storeLNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *                       storeLNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *                storeL_2instrNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *                storeL_2instrNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *              storeL_volatileNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *              storeL_volatileNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *           storeL_volatile_fpNode::pipeline_class() { return (&pipeline_class_065); }
const Pipeline *           storeL_volatile_fpNode::pipeline() const { return (&pipeline_class_065); }

const Pipeline *                       storePNode::pipeline_class() { return (&pipeline_class_066); }
const Pipeline *                       storePNode::pipeline() const { return (&pipeline_class_066); }

const Pipeline *                       storeDNode::pipeline_class() { return (&pipeline_class_069); }
const Pipeline *                       storeDNode::pipeline() const { return (&pipeline_class_069); }

const Pipeline *                       storeFNode::pipeline_class() { return (&pipeline_class_067); }
const Pipeline *                       storeFNode::pipeline() const { return (&pipeline_class_067); }

const Pipeline *            membar_storestoreNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *            membar_storestoreNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *               membar_acquireNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *               membar_acquireNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *             membar_acquire_0Node::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *             membar_acquire_0Node::pipeline() const { return (&pipeline_class_088); }

const Pipeline *          membar_acquire_lockNode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *          membar_acquire_lockNode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *               membar_releaseNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *               membar_releaseNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *             membar_release_0Node::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *             membar_release_0Node::pipeline() const { return (&pipeline_class_088); }

const Pipeline *          membar_release_lockNode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *          membar_release_lockNode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *              membar_volatileNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *              membar_volatileNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *  unnecessary_membar_volatileNode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *  unnecessary_membar_volatileNode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *                      castX2PNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                      castX2PNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                      castP2XNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                      castP2XNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   cmovIP_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   cmovIP_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                cmovIP_immMovNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                cmovIP_immMovNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                 cmovIP_imm16Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                 cmovIP_imm16Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                    cmovI_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                    cmovI_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                 cmovI_immMovNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                 cmovI_immMovNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                 cmovII_imm16Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                 cmovII_imm16Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *          cmovII_reg_EQNELTGENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *          cmovII_reg_EQNELTGENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *       cmovII_immMov_EQNELTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *       cmovII_immMov_EQNELTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *        cmovII_imm16_EQNELTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *        cmovII_imm16_EQNELTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                  cmovIIu_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                  cmovIIu_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *               cmovIIu_immMovNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovIIu_immMovNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                cmovIIu_imm16Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                cmovIIu_imm16Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                   cmovPP_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   cmovPP_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   cmovPP_immNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                   cmovPP_immNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                   cmovPI_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   cmovPI_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *          cmovPI_reg_EQNELTGENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *          cmovPI_reg_EQNELTGENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  cmovPIu_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                  cmovPIu_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   cmovPI_immNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                   cmovPI_immNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *          cmovPI_imm_EQNELTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *          cmovPI_imm_EQNELTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                  cmovPIu_immNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                  cmovPIu_immNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                   cmovFP_regNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *                   cmovFP_regNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *                   cmovFI_regNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *                   cmovFI_regNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *          cmovFI_reg_EQNELTGENode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *          cmovFI_reg_EQNELTGENode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *                  cmovFIu_regNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *                  cmovFIu_regNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *                   cmovDP_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   cmovDP_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   cmovDI_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   cmovDI_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *          cmovDI_reg_EQNELTGENode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *          cmovDI_reg_EQNELTGENode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  cmovDIu_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  cmovDIu_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   cmovLP_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   cmovLP_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                cmovLP_immRotNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                cmovLP_immRotNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                 cmovLP_imm16Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                 cmovLP_imm16Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                   cmovLI_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   cmovLI_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *          cmovLI_reg_EQNELTGENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *          cmovLI_reg_EQNELTGENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                cmovLI_immRotNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                cmovLI_immRotNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *       cmovLI_immRot_EQNELTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *       cmovLI_immRot_EQNELTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                 cmovLI_imm16Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                 cmovLI_imm16Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *        cmovLI_imm16_EQNELTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *        cmovLI_imm16_EQNELTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                  cmovLIu_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                  cmovLIu_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                     tlsLoadPNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                     tlsLoadPNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                  checkCastPPNode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *                  checkCastPPNode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *                       castPPNode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *                       castPPNode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *                       castIINode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *                       castIINode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *                 addI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 addI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        addshlI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        addshlI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addshlI_reg_imm_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addshlI_reg_imm_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        addshlI_reg_imm_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        addshlI_reg_imm_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        addsarI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        addsarI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addsarI_reg_imm_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addsarI_reg_imm_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        addsarI_reg_imm_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        addsarI_reg_imm_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        addshrI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        addshrI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addshrI_reg_imm_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addshrI_reg_imm_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        addshrI_reg_imm_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        addshrI_reg_imm_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *               addI_reg_aimmINode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *               addI_reg_aimmINode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 addP_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 addP_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          addshlP_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          addshlP_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *               addP_reg_aimmXNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *               addP_reg_aimmXNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 addL_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 addL_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *              addL_reg_immRotNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *              addL_reg_immRotNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                  loadPLockedNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *                  loadPLockedNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *            storePConditionalNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *            storePConditionalNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *            storeXConditionalNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *            storeXConditionalNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *         compareAndSwapL_boolNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *         compareAndSwapL_boolNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *         compareAndSwapI_boolNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *         compareAndSwapI_boolNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *         compareAndSwapP_boolNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *         compareAndSwapP_boolNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *           xaddI_aimmI_no_resNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *           xaddI_aimmI_no_resNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *             xaddI_reg_no_resNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *             xaddI_reg_no_resNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                  xaddI_aimmINode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                  xaddI_aimmINode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                    xaddI_regNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                    xaddI_regNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *             xaddL_reg_no_resNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *             xaddL_reg_no_resNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *          xaddL_immRot_no_resNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *          xaddL_immRot_no_resNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                    xaddL_regNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                    xaddL_regNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                 xaddL_immRotNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                 xaddL_immRotNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                        xchgINode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                        xchgINode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                        xchgLNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                        xchgLNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                        xchgPNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                        xchgPNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                 subI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 subI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          subshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          subshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          subshlI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          subshlI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          subsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          subsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          subsarI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          subsarI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          subshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          subshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          subshrI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          subshrI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          rsbshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          rsbshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          rsbshlI_reg_imm_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          rsbshlI_reg_imm_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          rsbsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          rsbsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          rsbsarI_reg_imm_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          rsbsarI_reg_imm_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          rsbshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          rsbshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          rsbshrI_reg_imm_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          rsbshrI_reg_imm_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *               subI_reg_aimmINode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *               subI_reg_aimmINode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *           subI_reg_immRotnegNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *           subI_reg_immRotnegNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *              subI_immRot_regNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *              subI_immRot_regNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                 subL_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 subL_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *              subL_reg_immRotNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *              subL_reg_immRotNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 negL_reg_regNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                 negL_reg_regNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                 mulI_reg_regNode::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *                 mulI_reg_regNode::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                 mulL_lo1_hi2Node::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *                 mulL_lo1_hi2Node::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                 mulL_hi1_lo2Node::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *                 mulL_hi1_lo2Node::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                 mulL_lo1_lo2Node::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *                 mulL_lo1_lo2Node::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                 divI_reg_regNode::pipeline_class() { return (&pipeline_class_038); }
const Pipeline *                 divI_reg_regNode::pipeline() const { return (&pipeline_class_038); }

const Pipeline *                 divL_reg_regNode::pipeline_class() { return (&pipeline_class_039); }
const Pipeline *                 divL_reg_regNode::pipeline() const { return (&pipeline_class_039); }

const Pipeline *                 modI_reg_regNode::pipeline_class() { return (&pipeline_class_038); }
const Pipeline *                 modI_reg_regNode::pipeline() const { return (&pipeline_class_038); }

const Pipeline *                 modL_reg_regNode::pipeline_class() { return (&pipeline_class_039); }
const Pipeline *                 modL_reg_regNode::pipeline() const { return (&pipeline_class_039); }

const Pipeline *                 shlI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 shlI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                shlI_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shlI_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *        shlL_reg_reg_merge_hiNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        shlL_reg_reg_merge_hiNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        shlL_reg_reg_merge_loNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        shlL_reg_reg_merge_loNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         shlL_reg_reg_overlapNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         shlL_reg_reg_overlapNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                shlL_reg_imm6Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shlL_reg_imm6Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                shlL_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shlL_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 sarI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 sarI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                sarI_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                sarI_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *        sarL_reg_reg_merge_loNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        sarL_reg_reg_merge_loNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        sarL_reg_reg_merge_hiNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        sarL_reg_reg_merge_hiNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         sarL_reg_reg_overlapNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         sarL_reg_reg_overlapNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                sarL_reg_imm6Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                sarL_reg_imm6Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                sarL_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                sarL_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 shrI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 shrI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                shrI_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shrI_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *        shrL_reg_reg_merge_loNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        shrL_reg_reg_merge_loNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        shrL_reg_reg_merge_hiNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        shrL_reg_reg_merge_hiNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         shrL_reg_reg_overlapNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         shrL_reg_reg_overlapNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                shrL_reg_imm6Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shrL_reg_imm6Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                shrL_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shrL_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                shrP_reg_imm5Node::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                shrP_reg_imm5Node::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 addF_reg_regNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                 addF_reg_regNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                 addD_reg_regNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                 addD_reg_regNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                 subF_reg_regNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                 subF_reg_regNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                 subD_reg_regNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                 subD_reg_regNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                 mulF_reg_regNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                 mulF_reg_regNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                 mulD_reg_regNode::pipeline_class() { return (&pipeline_class_045); }
const Pipeline *                 mulD_reg_regNode::pipeline() const { return (&pipeline_class_045); }

const Pipeline *                 divF_reg_regNode::pipeline_class() { return (&pipeline_class_046); }
const Pipeline *                 divF_reg_regNode::pipeline() const { return (&pipeline_class_046); }

const Pipeline *                 divD_reg_regNode::pipeline_class() { return (&pipeline_class_047); }
const Pipeline *                 divD_reg_regNode::pipeline() const { return (&pipeline_class_047); }

const Pipeline *                     absD_regNode::pipeline_class() { return (&pipeline_class_049); }
const Pipeline *                     absD_regNode::pipeline() const { return (&pipeline_class_049); }

const Pipeline *                     absF_regNode::pipeline_class() { return (&pipeline_class_048); }
const Pipeline *                     absF_regNode::pipeline() const { return (&pipeline_class_048); }

const Pipeline *                     negF_regNode::pipeline_class() { return (&pipeline_class_048); }
const Pipeline *                     negF_regNode::pipeline() const { return (&pipeline_class_048); }

const Pipeline *                     negD_regNode::pipeline_class() { return (&pipeline_class_049); }
const Pipeline *                     negD_regNode::pipeline() const { return (&pipeline_class_049); }

const Pipeline *                sqrtF_reg_regNode::pipeline_class() { return (&pipeline_class_046); }
const Pipeline *                sqrtF_reg_regNode::pipeline() const { return (&pipeline_class_046); }

const Pipeline *                sqrtD_reg_regNode::pipeline_class() { return (&pipeline_class_047); }
const Pipeline *                sqrtD_reg_regNode::pipeline() const { return (&pipeline_class_047); }

const Pipeline *                 andI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 andI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          andshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          andshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        andshlI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        andshlI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          andshlI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          andshlI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        andshlI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        andshlI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          andsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          andsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        andsarI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        andsarI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          andsarI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          andsarI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        andsarI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        andsarI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          andshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          andshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        andshrI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        andshrI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          andshrI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          andshrI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        andshrI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        andshrI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                andI_reg_limmNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                andI_reg_limmNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *               andI_reg_limmnNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *               andI_reg_limmnNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 andL_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 andL_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *              andL_reg_immRotNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *              andL_reg_immRotNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                  orI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  orI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           orshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           orshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         orshlI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         orshlI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           orshlI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           orshlI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         orshlI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         orshlI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           orsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           orsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         orsarI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         orsarI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           orsarI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           orsarI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         orsarI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         orsarI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           orshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           orshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         orshrI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         orshrI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           orshrI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           orshrI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *         orshrI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *         orshrI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 orI_reg_limmNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                 orI_reg_limmNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                  orL_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  orL_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *               orL_reg_immRotNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *               orL_reg_immRotNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 xorI_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 xorI_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          xorshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          xorshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        xorshlI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        xorshlI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          xorshlI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          xorshlI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        xorshlI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        xorshlI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          xorsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          xorsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        xorsarI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        xorsarI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          xorsarI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          xorsarI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        xorsarI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        xorsarI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          xorshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          xorshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        xorshrI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        xorshrI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *          xorshrI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *          xorshrI_reg_reg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        xorshrI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        xorshrI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 xorI_reg_immNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                 xorI_reg_immNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                 xorL_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 xorL_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *              xorL_reg_immRotNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *              xorL_reg_immRotNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                      convI2BNode::pipeline_class() { return (&pipeline_class_025); }
const Pipeline *                      convI2BNode::pipeline() const { return (&pipeline_class_025); }

const Pipeline *                      convP2BNode::pipeline_class() { return (&pipeline_class_025); }
const Pipeline *                      convP2BNode::pipeline() const { return (&pipeline_class_025); }

const Pipeline *            cmpLTMask_reg_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *            cmpLTMask_reg_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *            cmpLTMask_reg_immNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *            cmpLTMask_reg_immNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *              cadd_cmpLTMask3Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *              cadd_cmpLTMask3Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *            cadd_cmpLTMask3_1Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *            cadd_cmpLTMask3_1Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *            cadd_cmpLTMask3_0Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *            cadd_cmpLTMask3_0Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *            cadd_cmpLTMask3_2Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *            cadd_cmpLTMask3_2Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *              cadd_cmpLTMask4Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *              cadd_cmpLTMask4Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *            cadd_cmpLTMask4_1Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *            cadd_cmpLTMask4_1Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *            cadd_cmpLTMask4_0Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *            cadd_cmpLTMask4_0Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *            cadd_cmpLTMask4_2Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *            cadd_cmpLTMask4_2Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *               cadd_cmpLTMaskNode::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *               cadd_cmpLTMaskNode::pipeline() const { return (&pipeline_class_091); }

const Pipeline *             cadd_cmpLTMask_1Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *             cadd_cmpLTMask_1Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *             cadd_cmpLTMask_0Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *             cadd_cmpLTMask_0Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *             cadd_cmpLTMask_2Node::pipeline_class() { return (&pipeline_class_091); }
const Pipeline *             cadd_cmpLTMask_2Node::pipeline() const { return (&pipeline_class_091); }

const Pipeline *                  convD2F_regNode::pipeline_class() { return (&pipeline_class_055); }
const Pipeline *                  convD2F_regNode::pipeline() const { return (&pipeline_class_055); }

const Pipeline *              convD2I_reg_regNode::pipeline_class() { return (&pipeline_class_057); }
const Pipeline *              convD2I_reg_regNode::pipeline() const { return (&pipeline_class_057); }

const Pipeline *                  convD2L_regNode::pipeline_class() { return (&pipeline_class_058); }
const Pipeline *                  convD2L_regNode::pipeline() const { return (&pipeline_class_058); }

const Pipeline *                  convF2D_regNode::pipeline_class() { return (&pipeline_class_050); }
const Pipeline *                  convF2D_regNode::pipeline() const { return (&pipeline_class_050); }

const Pipeline *              convF2I_reg_regNode::pipeline_class() { return (&pipeline_class_059); }
const Pipeline *              convF2I_reg_regNode::pipeline() const { return (&pipeline_class_059); }

const Pipeline *                  convF2L_regNode::pipeline_class() { return (&pipeline_class_060); }
const Pipeline *                  convF2L_regNode::pipeline() const { return (&pipeline_class_060); }

const Pipeline *              convI2D_reg_regNode::pipeline_class() { return (&pipeline_class_051); }
const Pipeline *              convI2D_reg_regNode::pipeline() const { return (&pipeline_class_051); }

const Pipeline *              convI2F_reg_regNode::pipeline_class() { return (&pipeline_class_061); }
const Pipeline *              convI2F_reg_regNode::pipeline() const { return (&pipeline_class_061); }

const Pipeline *                  convI2L_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  convI2L_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *              convI2L_reg_zexNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *              convI2L_reg_zexNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   zerox_longNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   zerox_longNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *              MoveF2I_reg_regNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *              MoveF2I_reg_regNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *              MoveI2F_reg_regNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *              MoveI2F_reg_regNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *              MoveD2L_reg_regNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *              MoveD2L_reg_regNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *              MoveL2D_reg_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *              MoveL2D_reg_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           loadConI_x43300000Node::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *           loadConI_x43300000Node::pipeline() const { return (&pipeline_class_014); }

const Pipeline *           loadConI_x41f00000Node::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *           loadConI_x41f00000Node::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                  loadConI_x0Node::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                  loadConI_x0Node::pipeline() const { return (&pipeline_class_014); }

const Pipeline *        regDHi_regDLo_to_regDNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *        regDHi_regDLo_to_regDNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *          convI2D_regDHi_regDNode::pipeline_class() { return (&pipeline_class_052); }
const Pipeline *          convI2D_regDHi_regDNode::pipeline() const { return (&pipeline_class_052); }

const Pipeline *               addD_regD_regDNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *               addD_regD_regDNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *               subD_regD_regDNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *               subD_regD_regDNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *               mulD_regD_regDNode::pipeline_class() { return (&pipeline_class_045); }
const Pipeline *               mulD_regD_regDNode::pipeline() const { return (&pipeline_class_045); }

const Pipeline *                 regL_to_regDNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 regL_to_regDNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *            regI_regI_to_regDNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *            regI_regI_to_regDNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  convL2I_regNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                  convL2I_regNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *            shrL_reg_imm6_L2INode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *            shrL_reg_imm6_L2INode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                   compI_iRegNode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *                   compI_iRegNode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *                   compU_iRegNode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *                   compU_iRegNode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *            compI_iReg_immnegNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *            compI_iReg_immnegNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *               compI_iReg_immNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *               compI_iReg_immNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                testI_reg_regNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                testI_reg_regNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *         testshlI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *         testshlI_reg_reg_regNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *       testshlI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *       testshlI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *         testshlI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *         testshlI_reg_reg_immNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *       testshlI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *       testshlI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *         testsarI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *         testsarI_reg_reg_regNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *       testsarI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *       testsarI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *         testsarI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *         testsarI_reg_reg_immNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *       testsarI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *       testsarI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *         testshrI_reg_reg_regNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *         testshrI_reg_reg_regNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *       testshrI_reg_reg_reg_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *       testshrI_reg_reg_reg_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *         testshrI_reg_reg_immNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *         testshrI_reg_reg_immNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *       testshrI_reg_reg_imm_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *       testshrI_reg_reg_imm_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                testI_reg_immNode::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                testI_reg_immNode::pipeline() const { return (&pipeline_class_011); }

const Pipeline *           compL_reg_reg_LTGENode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *           compL_reg_reg_LTGENode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *           compL_reg_reg_EQNENode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *           compL_reg_reg_EQNENode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *           compL_reg_reg_LEGTNode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *           compL_reg_reg_LEGTNode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *           compL_reg_con_LTGENode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *           compL_reg_con_LTGENode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *           compL_reg_con_EQNENode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *           compL_reg_con_EQNENode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *           compL_reg_con_LEGTNode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *           compL_reg_con_LEGTNode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *               compU_iReg_immNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *               compU_iReg_immNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                  compP_iRegPNode::pipeline_class() { return (&pipeline_class_008); }
const Pipeline *                  compP_iRegPNode::pipeline() const { return (&pipeline_class_008); }

const Pipeline *              compP_iRegP_immNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *              compP_iRegP_immNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                 cmovI_reg_ltNode::pipeline_class() { return (&pipeline_class_016); }
const Pipeline *                 cmovI_reg_ltNode::pipeline() const { return (&pipeline_class_016); }

const Pipeline *                 cmovI_reg_gtNode::pipeline_class() { return (&pipeline_class_016); }
const Pipeline *                 cmovI_reg_gtNode::pipeline() const { return (&pipeline_class_016); }

const Pipeline *                      cmpF_ccNode::pipeline_class() { return (&pipeline_class_062); }
const Pipeline *                      cmpF_ccNode::pipeline() const { return (&pipeline_class_062); }

const Pipeline *                     cmpF0_ccNode::pipeline_class() { return (&pipeline_class_062); }
const Pipeline *                     cmpF0_ccNode::pipeline() const { return (&pipeline_class_062); }

const Pipeline *                      cmpD_ccNode::pipeline_class() { return (&pipeline_class_063); }
const Pipeline *                      cmpD_ccNode::pipeline() const { return (&pipeline_class_063); }

const Pipeline *                     cmpD0_ccNode::pipeline_class() { return (&pipeline_class_063); }
const Pipeline *                     cmpD0_ccNode::pipeline() const { return (&pipeline_class_063); }

const Pipeline *                     cmpF_regNode::pipeline_class() { return (&pipeline_class_090); }
const Pipeline *                     cmpF_regNode::pipeline() const { return (&pipeline_class_090); }

const Pipeline *                    cmpF0_regNode::pipeline_class() { return (&pipeline_class_090); }
const Pipeline *                    cmpF0_regNode::pipeline() const { return (&pipeline_class_090); }

const Pipeline *                     cmpD_regNode::pipeline_class() { return (&pipeline_class_090); }
const Pipeline *                     cmpD_regNode::pipeline() const { return (&pipeline_class_090); }

const Pipeline *                    cmpD0_regNode::pipeline_class() { return (&pipeline_class_090); }
const Pipeline *                    cmpD0_regNode::pipeline() const { return (&pipeline_class_090); }

const Pipeline *                     jumpXtndNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     jumpXtndNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                       branchNode::pipeline_class() { return (&pipeline_class_078); }
const Pipeline *                       branchNode::pipeline() const { return (&pipeline_class_078); }

const Pipeline *                    branchConNode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *                    branchConNode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *           branchCon_EQNELTGENode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *           branchCon_EQNELTGENode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *                   branchConUNode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *                   branchConUNode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *                   branchConPNode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *                   branchConPNode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *              branchConL_LTGENode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *              branchConL_LTGENode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *              branchConL_EQNENode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *              branchConL_EQNENode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *              branchConL_LEGTNode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *              branchConL_LEGTNode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *                branchLoopEndNode::pipeline_class() { return (&pipeline_class_079); }
const Pipeline *                branchLoopEndNode::pipeline() const { return (&pipeline_class_079); }

const Pipeline *                cmpL3_reg_regNode::pipeline_class() { return (&pipeline_class_013); }
const Pipeline *                cmpL3_reg_regNode::pipeline() const { return (&pipeline_class_013); }

const Pipeline *              cmovLL_reg_LTGENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovLL_reg_LTGENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovLL_reg_EQNENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovLL_reg_EQNENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovLL_reg_LEGTNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovLL_reg_LEGTNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovLL_imm_LTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovLL_imm_LTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovLL_imm_EQNENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovLL_imm_EQNENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovLL_imm_LEGTNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovLL_imm_LEGTNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovIL_reg_LTGENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovIL_reg_LTGENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovIL_reg_EQNENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovIL_reg_EQNENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovIL_reg_LEGTNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovIL_reg_LEGTNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovIL_imm_LTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovIL_imm_LTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovIL_imm_EQNENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovIL_imm_EQNENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovIL_imm_LEGTNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovIL_imm_LEGTNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovPL_reg_LTGENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovPL_reg_LTGENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovPL_reg_EQNENode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovPL_reg_EQNENode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovPL_reg_LEGTNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              cmovPL_reg_LEGTNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              cmovPL_imm_LTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovPL_imm_LTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovPL_imm_EQNENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovPL_imm_EQNENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovPL_imm_LEGTNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *              cmovPL_imm_LEGTNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *              cmovFL_reg_LTGENode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *              cmovFL_reg_LTGENode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *              cmovFL_reg_EQNENode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *              cmovFL_reg_EQNENode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *              cmovFL_reg_LEGTNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *              cmovFL_reg_LEGTNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *              cmovDL_reg_LTGENode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *              cmovDL_reg_LTGENode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *              cmovDL_reg_EQNENode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *              cmovDL_reg_EQNENode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *              cmovDL_reg_LEGTNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *              cmovDL_reg_LEGTNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *               safePoint_pollNode::pipeline_class() { return (&pipeline_class_077); }
const Pipeline *               safePoint_pollNode::pipeline() const { return (&pipeline_class_077); }

const Pipeline *         CallStaticJavaDirectNode::pipeline_class() { return (&pipeline_class_082); }
const Pipeline *         CallStaticJavaDirectNode::pipeline() const { return (&pipeline_class_082); }

const Pipeline *         CallStaticJavaHandleNode::pipeline_class() { return (&pipeline_class_082); }
const Pipeline *         CallStaticJavaHandleNode::pipeline() const { return (&pipeline_class_082); }

const Pipeline *        CallDynamicJavaDirectNode::pipeline_class() { return (&pipeline_class_084); }
const Pipeline *        CallDynamicJavaDirectNode::pipeline() const { return (&pipeline_class_084); }

const Pipeline *            CallRuntimeDirectNode::pipeline_class() { return (&pipeline_class_082); }
const Pipeline *            CallRuntimeDirectNode::pipeline() const { return (&pipeline_class_082); }

const Pipeline *               CallLeafDirectNode::pipeline_class() { return (&pipeline_class_082); }
const Pipeline *               CallLeafDirectNode::pipeline() const { return (&pipeline_class_082); }

const Pipeline *           CallLeafNoFPDirectNode::pipeline_class() { return (&pipeline_class_082); }
const Pipeline *           CallLeafNoFPDirectNode::pipeline() const { return (&pipeline_class_082); }

const Pipeline *               TailCalljmpIndNode::pipeline_class() { return (&pipeline_class_085); }
const Pipeline *               TailCalljmpIndNode::pipeline() const { return (&pipeline_class_085); }

const Pipeline *                          RetNode::pipeline_class() { return (&pipeline_class_078); }
const Pipeline *                          RetNode::pipeline() const { return (&pipeline_class_078); }

const Pipeline *                   tailjmpIndNode::pipeline_class() { return (&pipeline_class_085); }
const Pipeline *                   tailjmpIndNode::pipeline() const { return (&pipeline_class_085); }

const Pipeline *              CreateExceptionNode::pipeline_class() { return (&pipeline_class_087); }
const Pipeline *              CreateExceptionNode::pipeline() const { return (&pipeline_class_087); }

const Pipeline *             RethrowExceptionNode::pipeline_class() { return (&pipeline_class_085); }
const Pipeline *             RethrowExceptionNode::pipeline() const { return (&pipeline_class_085); }

const Pipeline *           ShouldNotReachHereNode::pipeline_class() { return (&pipeline_class_085); }
const Pipeline *           ShouldNotReachHereNode::pipeline() const { return (&pipeline_class_085); }

const Pipeline *          partialSubtypeCheckNode::pipeline_class() { return (&pipeline_class_089); }
const Pipeline *          partialSubtypeCheckNode::pipeline() const { return (&pipeline_class_089); }

const Pipeline *                  cmpFastLockNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                  cmpFastLockNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                cmpFastUnlockNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                cmpFastUnlockNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *                  clear_arrayNode::pipeline_class() { return (&pipeline_class_088); }
const Pipeline *                  clear_arrayNode::pipeline() const { return (&pipeline_class_088); }

const Pipeline *           countLeadingZerosINode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *           countLeadingZerosINode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *           countLeadingZerosLNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *           countLeadingZerosLNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *          countTrailingZerosINode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *          countTrailingZerosINode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *          countTrailingZerosLNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *          countTrailingZerosLNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                    popCountINode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                    popCountINode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                    popCountLNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                    popCountLNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *            bytes_reverse_intNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *            bytes_reverse_intNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *           bytes_reverse_longNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *           bytes_reverse_longNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline * bytes_reverse_unsigned_shortNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline * bytes_reverse_unsigned_shortNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *          bytes_reverse_shortNode::pipeline_class() { return (&pipeline_class_071); }
const Pipeline *          bytes_reverse_shortNode::pipeline() const { return (&pipeline_class_071); }

const Pipeline *                       loadV8Node::pipeline_class() { return (&pipeline_class_074); }
const Pipeline *                       loadV8Node::pipeline() const { return (&pipeline_class_074); }

const Pipeline *                      loadV16Node::pipeline_class() { return (&pipeline_class_074); }
const Pipeline *                      loadV16Node::pipeline() const { return (&pipeline_class_074); }

const Pipeline *                      storeV8Node::pipeline_class() { return (&pipeline_class_069); }
const Pipeline *                      storeV8Node::pipeline() const { return (&pipeline_class_069); }

const Pipeline *                     storeV16Node::pipeline_class() { return (&pipeline_class_069); }
const Pipeline *                     storeV16Node::pipeline() const { return (&pipeline_class_069); }

const Pipeline *                   Repl8B_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl8B_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              Repl8B_reg_simdNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              Repl8B_reg_simdNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  Repl16B_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                  Repl16B_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  Repl8B_immINode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                  Repl8B_immINode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                 Repl8B_immU8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                 Repl8B_immU8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                Repl16B_immU8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                Repl16B_immU8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                   Repl4S_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl4S_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              Repl4S_reg_simdNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              Repl4S_reg_simdNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   Repl8S_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl8S_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  Repl4S_immINode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                  Repl4S_immINode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                 Repl4S_immU8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                 Repl4S_immU8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                 Repl8S_immU8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                 Repl8S_immU8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                   Repl2I_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl2I_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   Repl4I_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl4I_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              Repl2I_reg_simdNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              Repl2I_reg_simdNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              Repl4I_reg_simdNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              Repl4I_reg_simdNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  Repl2I_immINode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                  Repl2I_immINode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                 Repl2I_immU8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                 Repl2I_immU8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                 Repl4I_immU8Node::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                 Repl4I_immU8Node::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                   Repl2L_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl2L_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  Repl2F_regINode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                  Repl2F_regINode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              Repl2F_reg_simdNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              Repl2F_reg_simdNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   Repl4F_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl4F_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *              Repl4F_reg_simdNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *              Repl4F_reg_simdNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  Repl2F_immINode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                  Repl2F_immINode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                   Repl2D_regNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                   Repl2D_regNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                   vadd8B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vadd8B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vadd16B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vadd16B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vadd4S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vadd4S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vadd8S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vadd8S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vadd2I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vadd2I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vadd4I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vadd4I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vadd2L_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vadd2L_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vadd2F_regNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                   vadd2F_regNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *               vadd2F_reg_vfpNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *               vadd2F_reg_vfpNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *              vadd4F_reg_simdNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *              vadd4F_reg_simdNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *               vadd4F_reg_vfpNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *               vadd4F_reg_vfpNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *               vadd2D_reg_vfpNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *               vadd2D_reg_vfpNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                   vsub8B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsub8B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsub16B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsub16B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsub4S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsub4S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsub16S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsub16S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsub2I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsub2I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsub4I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsub4I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsub2L_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsub2L_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsub2F_regNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                   vsub2F_regNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *               vsub2F_reg_vfpNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *               vsub2F_reg_vfpNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                   vsub4F_regNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                   vsub4F_regNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *               vsub4F_reg_vfpNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *               vsub4F_reg_vfpNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *               vsub2D_reg_vfpNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *               vsub2D_reg_vfpNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                   vmul4S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vmul4S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vmul8S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vmul8S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vmul2I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vmul2I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vmul4I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vmul4I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vmul2F_regNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                   vmul2F_regNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *               vmul2F_reg_vfpNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *               vmul2F_reg_vfpNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                   vmul4F_regNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                   vmul4F_regNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *               vmul4F_reg_vfpNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *               vmul4F_reg_vfpNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *               vmul2D_reg_vfpNode::pipeline_class() { return (&pipeline_class_045); }
const Pipeline *               vmul2D_reg_vfpNode::pipeline() const { return (&pipeline_class_045); }

const Pipeline *               vdiv2F_reg_vfpNode::pipeline_class() { return (&pipeline_class_046); }
const Pipeline *               vdiv2F_reg_vfpNode::pipeline() const { return (&pipeline_class_046); }

const Pipeline *               vdiv4F_reg_vfpNode::pipeline_class() { return (&pipeline_class_046); }
const Pipeline *               vdiv4F_reg_vfpNode::pipeline() const { return (&pipeline_class_046); }

const Pipeline *               vdiv2D_reg_vfpNode::pipeline_class() { return (&pipeline_class_047); }
const Pipeline *               vdiv2D_reg_vfpNode::pipeline() const { return (&pipeline_class_047); }

const Pipeline *                   vneg8B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vneg8B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vneg16B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vneg16B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                      vsrcntDNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                      vsrcntDNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                      vsrcntXNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                      vsrcntXNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    vsh8B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    vsh8B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsh16B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsh16B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    vsh4S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    vsh4S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    vsh8S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    vsh8S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    vsh2I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    vsh2I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    vsh4I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    vsh4I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    vsh2L_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    vsh2L_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsl8B_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsl8B_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsl16B_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsl16B_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsl4S_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsl4S_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsl8S_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsl8S_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsl2I_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsl2I_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsl4I_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsl4I_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsl2L_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsl2L_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsrl4S_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsrl4S_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsrl8S_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsrl8S_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsrl2I_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsrl2I_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsrl4I_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsrl4I_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsrl2L_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsrl2L_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsha8B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsha8B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsha16B_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsha16B_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsha4S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsha4S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsha8S_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsha8S_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsha2I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsha2I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsha4I_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsha4I_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                   vsha2L_regNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   vsha2L_regNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsrl8B_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsrl8B_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 vsrl16B_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 vsrl16B_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsra4S_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsra4S_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsra8S_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsra8S_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsra2I_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsra2I_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsra4I_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsra4I_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  vsra2L_immINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  vsra2L_immINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                        vandDNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                        vandDNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                        vandXNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                        vandXNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                         vorDNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                         vorDNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                         vorXNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                         vorXNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                        vxorDNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                        vxorDNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                        vxorXNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                        vxorXNode::pipeline() const { return (&pipeline_class_001); }
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
