/*
 * satk - SIM application toolkit
 * Copyright © 2011, Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Written by - Luc Yriarte <luc.yriarte@linux.intel.com>
 */


#ifndef STKDEFINES_H
#define STKDEFINES_H

typedef enum {
    Yes,
    No,
    Ok,
    Back,
    End
} AgentResponse;

#define STK_ERR_BACK    "org.ofono.Error.GoBack"
#define STK_ERR_END     "org.ofono.Error.EndSession"
#define STK_ERR_BUSY    "org.ofono.Error.Busy"

#define STK_AGENT_PATH  "/satk/agent"

#define VALID_ICON_ID(id) ((id)>0)
#define TEST_PIXMAP QPixmap(32,32)
#define TEST_ICON_URL "qrc:/images/sim_32x32.png"


#endif // STKDEFINES_H
