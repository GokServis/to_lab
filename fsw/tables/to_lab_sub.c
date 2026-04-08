/************************************************************************
 * NASA Docket No. GSC-19,200-1, and identified as "cFS Draco"
 *
 * Copyright (c) 2023 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/**
 * \file
 *  Define TO Lab CPU specific subscription table
 */

#include "cfe_tbl_filedef.h" /* Required to obtain the CFE_TBL_FILEDEF macro definition */
#include "cfe_sb_api_typedefs.h"
#include "to_lab_tbl.h"
#include "cfe_msgids.h"

/*
** Add the proper include file for the message IDs below
*/
#include "to_lab_msgids.h"

/*
 * CF End-of-Transaction telemetry MID.
 *
 * This mission uses the default cFE msgid mapping:
 *   MID = 0x0800 | topicid
 * and CF's default EOT topicid is 0xB3 (see `apps/cf/fsw/inc/cf_topicids.h`).
 */
#define BRIDGE_CF_EOT_TLM_MID 0x08B3u

TO_LAB_Subs_t Subscriptions = {
    .Subs = {
        /* Ground / rust-cfs-bridge: ES HK is the primary parsed downlink product. */
        {CFE_SB_MSGID_WRAP_VALUE(CFE_ES_HK_TLM_MID), {0, 0}, 4},
        /* Lab apps on this mission (see docs/AVAILABLE_TELEMETRY.md). */
        {CFE_SB_MSGID_WRAP_VALUE(TO_LAB_HK_TLM_MID), {0, 0}, 4},
        /* EVS event messages (long format) for operator-friendly logs. */
        {CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_LONG_EVENT_MSG_MID), {0, 0}, 4},
        /* CF end-of-transaction telemetry for brain-upload gating. */
        {CFE_SB_MSGID_WRAP_VALUE(BRIDGE_CF_EOT_TLM_MID), {0, 0}, 4},

        /* CFE_SB_MSGID_RESERVED entry to mark the end of valid MsgIds */
        {CFE_SB_MSGID_RESERVED, {0, 0}, 0}
    }
};

CFE_TBL_FILEDEF(Subscriptions, TO_LAB.Subscriptions, TO Lab Sub Tbl, to_lab_sub.tbl)
