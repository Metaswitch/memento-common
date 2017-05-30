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

#include "mementosaslogger.h"

void MementoSasLogger::sas_log_tx_http_rsp(SAS::TrailId trail,
                                           HttpStack::Request& req,
                                           int rc,
                                           uint32_t instance_id)
{
  log_rsp_event(trail, req, rc, instance_id, SASEvent::HttpLogLevel::PROTOCOL, true);
}

