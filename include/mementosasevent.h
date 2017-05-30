/**
 * @file mementosasevent.h Memento-specific SAS event IDs
 *
 * Copyright (C) Metaswitch Networks 2016
 * If license terms are provided to you in a COPYING file in the root directory
 * of the source code repository by which you are accessing this code, then
 * the license outlined in that COPYING file applies to your use.
 * Otherwise no rights are granted except for those provided to you by
 * Metaswitch Networks in a separate written agreement.
 */

#ifndef MEMENTOSASEVENT_H__
#define MEMENTOSASEVENT_H__

#include "sasevent.h"

namespace SASEvent
{
  //----------------------------------------------------------------------------
  // Memento events.
  //----------------------------------------------------------------------------
  const int HTTP_HS_DIGEST_LOOKUP = MEMENTO_BASE + 0x000000;
  const int HTTP_HS_DIGEST_LOOKUP_SUCCESS = MEMENTO_BASE + 0x000001;
  const int HTTP_HS_DIGEST_LOOKUP_FAILURE = MEMENTO_BASE + 0x000002;

  const int AUTHSTORE_GET_SUCCESS = MEMENTO_BASE + 0x000010;
  const int AUTHSTORE_GET_FAILURE = MEMENTO_BASE + 0x000011;
  const int AUTHSTORE_SET_SUCCESS = MEMENTO_BASE + 0x000012;
  const int AUTHSTORE_SET_FAILURE = MEMENTO_BASE + 0x000013;
  const int AUTHSTORE_DESERIALIZATION_FAILURE = MEMENTO_BASE + 0x000014;

  const int NO_AUTHENTICATION_PRESENT = MEMENTO_BASE + 0x000020;
  const int AUTHENTICATION_PRESENT = MEMENTO_BASE + 0x000021;
  const int AUTHENTICATION_OUT_OF_DATE = MEMENTO_BASE + 0x000022;
  const int AUTHENTICATION_REJECTED = MEMENTO_BASE + 0x000023;
  const int AUTHENTICATION_ACCEPTED = MEMENTO_BASE + 0x000024;
  const int AUTHENTICATION_WRONG_IMPU = MEMENTO_BASE + 0x000025;

  const int CALL_LIST_REQUEST_RX = MEMENTO_BASE + 0x000030;
  const int CALL_LIST_RSP_TX = MEMENTO_BASE + 0x000031;
  const int CALL_LIST_DB_RETRIEVAL_SUCCESS = MEMENTO_BASE + 0x000032;
  const int CALL_LIST_DB_RETRIEVAL_FAILED = MEMENTO_BASE + 0x000033;
  const int CALL_LIST_DB_INVALID_RECORD_1 = MEMENTO_BASE + 0x000034;
  const int CALL_LIST_DB_INVALID_RECORD_2 = MEMENTO_BASE + 0x000035;
  const int CALL_LIST_DB_INVALID_RECORD = MEMENTO_BASE + 0x000036;

  const int CALL_LIST_WRITE_STARTED = MEMENTO_BASE + 0x000200;
  const int CALL_LIST_WRITE_OK      = MEMENTO_BASE + 0x000201;
  const int CALL_LIST_WRITE_FAILED  = MEMENTO_BASE + 0x000202;
  const int CALL_LIST_READ_STARTED  = MEMENTO_BASE + 0x000203;
  const int CALL_LIST_READ_OK       = MEMENTO_BASE + 0x000204;
  const int CALL_LIST_READ_FAILED   = MEMENTO_BASE + 0x000205;
  const int CALL_LIST_TRIM_STARTED  = MEMENTO_BASE + 0x000206;
  const int CALL_LIST_TRIM_OK       = MEMENTO_BASE + 0x000207;
  const int CALL_LIST_TRIM_FAILED   = MEMENTO_BASE + 0x000208;

  const int CALL_LIST_BEGIN_FRAGMENT = MEMENTO_BASE + 0x000300;
  const int CALL_LIST_REJECTED_FRAGMENT = MEMENTO_BASE + 0x000301;
  const int CALL_LIST_END_FRAGMENT = MEMENTO_BASE + 0x000302;
  const int CALL_LIST_TRIM_NEEDED = MEMENTO_BASE + 0x000303;
  const int CALL_LIST_OVERLOAD = MEMENTO_BASE + 0x000304;
} //namespace SASEvent

#endif


