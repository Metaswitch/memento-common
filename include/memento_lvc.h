/**
 * @file memento_lvc.h
 *
 * Copyright (C) Metaswitch Networks 2016
 * If license terms are provided to you in a COPYING file in the root directory
 * of the source code repository by which you are accessing this code, then
 * the license outlined in that COPYING file applies to your use.
 * Otherwise no rights are granted except for those provided to you by
 * Metaswitch Networks in a separate written agreement.
 */

#ifndef MEMENTO_LVC_H__
#define MEMENTO_LVC_H__

#include "zmq_lvc.h"

class MementoLVC : public LastValueCache
{
private:
  const static std::string KNOWN_STATS[];
  const static int NUM_KNOWN_STATS;
  const static std::string SOCKET_NAME;

public:
  MementoLVC(long poll_timeout_ms = 1000) :
    LastValueCache(NUM_KNOWN_STATS,
                   KNOWN_STATS,
                   SOCKET_NAME,
                   poll_timeout_ms)
  {}
};

#endif
