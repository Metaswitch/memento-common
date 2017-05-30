/**
 * @file memento_lvc.cpp
 *
 * Copyright (C) Metaswitch Networks 2016
 * If license terms are provided to you in a COPYING file in the root directory
 * of the source code repository by which you are accessing this code, then
 * the license outlined in that COPYING file applies to your use.
 * Otherwise no rights are granted except for those provided to you by
 * Metaswitch Networks in a separate written agreement.
 */

#include "memento_lvc.h"

const std::string MementoLVC::KNOWN_STATS[] = {
  "http_latency_us",
  "http_incoming_requests",
  "http_rejected_overload",
  "connected_homesteads",
  "auth_challenges",
  "auth_attempts",
  "auth_successes",
  "auth_failures",
  "auth_stales",
  "cassandra_read_latency",
  "record_size",
  "record_length",
};

const int MementoLVC::NUM_KNOWN_STATS = sizeof(MementoLVC::KNOWN_STATS) / sizeof(std::string);

const std::string MementoLVC::SOCKET_NAME = "memento";
