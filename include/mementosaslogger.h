/**
 * @file mementosaslogger.cpp SAS logger for memento
 *
 * Copyright (C) Metaswitch Networks 2016
 * If license terms are provided to you in a COPYING file in the root directory
 * of the source code repository by which you are accessing this code, then
 * the license outlined in that COPYING file applies to your use.
 * Otherwise no rights are granted except for those provided to you by
 * Metaswitch Networks in a separate written agreement.
 */

#ifndef MEMENTOSASLOGGER_H_
#define MEMENTOSASLOGGER_H_

#include "sas.h"
#include "httpstack.h"

class MementoSasLogger : public HttpStack::DefaultSasLogger
{
public:
    // Log a transmitted HTTP response, omitting the body.
    //
    // @param trail SAS trail ID to log on.
    // @param req request to log.
    // @param rc the HTTP response code.
    // @instance_id unique instance ID for the event.
    void sas_log_tx_http_rsp(SAS::TrailId trail,
                             HttpStack::Request& req,
                             int rc,
                             uint32_t instance_id = 0);
};

#endif
