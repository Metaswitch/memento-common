/**
 * @file call_list_store.h Call list cassandra store.
 *
 * Copyright (C) Metaswitch Networks 2016
 * If license terms are provided to you in a COPYING file in the root directory
 * of the source code repository by which you are accessing this code, then
 * the license outlined in that COPYING file applies to your use.
 * Otherwise no rights are granted except for those provided to you by
 * Metaswitch Networks in a separate written agreement.
 */

#ifndef CALL_LIST_STORE_H_
#define CALL_LIST_STORE_H_

#include "cassandra_store.h"

namespace CallListStore
{

/// Structure representing a call record fragment in the store.
struct CallFragment
{
  // Types of call fragment. These are logged to SAS so:
  // -  Each element must have an explicit value.
  // -  If you change the enum you must also update the resource bundle.
  enum Type
  {
    BEGIN = 0,
    END = 1,
    REJECTED = 2
  };

  /// Timestamp representing the time that the call started. In the form
  /// YYYYMMDDHHMMSS.
  std::string timestamp;

  /// Application specific ID for the call. This is transparent to the store.
  std::string id;

  /// The type of fragment.
  Type type;

  /// The contents of the fragment in cassandra.  This is transparent to the
  /// store.
  std::string contents;
};


/// Operation that adds a new call record fragment to the store.
class WriteCallFragment : public CassandraStore::Operation
{
public:
  /// Constructor.
  ///
  /// @param impu             - The IMPU to write a fragment for.
  /// @param fragment         - The fragment object to write.
  /// @param ttl              - The TTL (in seconds) for the column.
  /// @param cass_timestamp   - The timestamp to use on the cassandra write.
  WriteCallFragment(const std::string& impu,
                    const CallFragment& record,
                    const int64_t cass_timestamp,
                    const int32_t ttl);
  virtual ~WriteCallFragment();

protected:
  bool perform(CassandraStore::Client* client, SAS::TrailId trail);
  void unhandled_exception(CassandraStore::ResultCode status,
                           std::string& description,
                           SAS::TrailId trail);

  const std::string _impu;
  const CallFragment _fragment;
  const int64_t _cass_timestamp;
  const int32_t _ttl;
};


/// Operation that gets call fragments for a particular IMPU.
class GetCallFragments : public CassandraStore::HAOperation
{
public:
  /// Constructor.
  /// @param impu     - The IMPU whose call fragments to retrieve.
  GetCallFragments(const std::string& impu);

  /// Virtual destructor.
  virtual ~GetCallFragments();

  /// Get the fetched call fragments.  These are guaranteed to be ordered first
  /// by timestamp, then by id, then by type.
  ///
  /// @param fragments  - (out) A vector of call fragments.
  void get_result(std::vector<CallFragment>& fragments);

protected:
  bool perform(CassandraStore::Client* client, SAS::TrailId trail);
  void unhandled_exception(CassandraStore::ResultCode status,
                           std::string& description,
                           SAS::TrailId trail);

  const std::string _impu;

  std::vector<CallFragment> _fragments;
};


/// Operation that deletes all fragments for an IMPU that occurred before a given
/// timestamp.
class DeleteOldCallFragments : public CassandraStore::Operation
{
public:
  /// Constructor
  ///
  /// @param impu             - The IMPU whose old fragments to delete.
  /// @param fragments        - Fragments to be deleted
  /// @param cass_timestamp   - The timestamp to use on the cassandra write.
  DeleteOldCallFragments(const std::string& impu,
                         const std::vector<CallFragment> fragments,
                         const int64_t cass_timestamp);

  /// Virtual destructor.
  virtual ~DeleteOldCallFragments();

protected:
  bool perform(CassandraStore::Client* client, SAS::TrailId trail);
  void unhandled_exception(CassandraStore::ResultCode status,
                           std::string& description,
                           SAS::TrailId trail);

  const std::string _impu;
  const std::vector<CallFragment> _fragments;
  const int64_t _cass_timestamp;
};


/// Call List store class.
///
/// This is a thin layer on top of a CassandraStore that provides some
/// additional utility methods.
class Store : public CassandraStore::Store
{
public:

  /// Constructor
  Store();

  /// Virtual destructor.
  virtual ~Store();

  //
  // Methods to create new operation objects.
  //
  // These should be used in preference to creating operations directly (using
  // 'new') as this makes the store easier to mock out in UT.
  //
  virtual WriteCallFragment*
    new_write_call_fragment_op(const std::string& impu,
                               const CallFragment& fragment,
                               const int64_t cass_timestamp,
                               const int32_t ttl);
  virtual GetCallFragments*
    new_get_call_fragments_op(const std::string& impu);
  virtual DeleteOldCallFragments*
    new_delete_old_call_fragments_op(const std::string& impu,
                                     const std::vector<CallFragment> fragments,
                                     const int64_t cass_timestamp);

  //
  // Utility methods to perform synchronous operations more easily.
  //
  virtual CassandraStore::ResultCode
    write_call_fragment_sync(const std::string& impu,
                             const CallFragment& fragment,
                             const int64_t cass_timestamp,
                             const int32_t ttl,
                             SAS::TrailId trail);
  virtual CassandraStore::ResultCode
    get_call_fragments_sync(const std::string& impu,
                            std::vector<CallFragment>& fragments,
                            SAS::TrailId trail);
  virtual CassandraStore::ResultCode
    delete_old_call_fragments_sync(const std::string& impu,
                                   const std::vector<CallFragment> fragments,
                                   const int64_t cass_timestamp,
                                   SAS::TrailId trail);
};

} // namespace CallListStore

#endif
