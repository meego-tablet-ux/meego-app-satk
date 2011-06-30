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

#define STK_AGENT_PATH  "/"

#define SIM_IMAGE_PROVIDER "sim"
#define SIM_ICON_PREFIX "image://" SIM_IMAGE_PROVIDER "/"
#define VALID_ICON_ID(id) ((id)>0)

#define SATK_USAGE "usage: satk [menu|agent]"

#endif // STKDEFINES_H
