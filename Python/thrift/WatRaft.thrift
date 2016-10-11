enum WatRaftErrorType {
  KEY_NOT_FOUND,              // Key not found.
  NOT_LEADER,                 // Node is not the leader.
  LEADER_NOT_AVAILABLE        // Leader is not available. An election is
                              // currently in progress. I suggest that, for 
                              // simplicity, a node only returns this error if 
                              // it is a candidate (not a follower) and has 
                              // evidence that the leader is not available.
}

exception WatRaftException {
  1: WatRaftErrorType error_code,
  2: string error_message,
  3: optional i32 node_id     // Specify the leader node ID if the error is 
                              // NOT_LEADER. This will allow the caller to 
                              // re-issue its request to the leader.
}

// Return value of an append_entries RPC request.
struct AEResult {
  1: i32 term,
  2: bool success
}

// Return value of a request_vote RPC request.
struct RVResult {
  1: i32 term,
  2: bool vote_granted
}

// A log entry containing a key/value pair.
struct Entry {
  1: string key,
  2: string val
}

service WatRaft {
  // Lookup a key and return its associated value. Throws a WatRaftException
  // if the key does not exist or the node is not the leader.
  string get(1: string key) throws (1: WatRaftException err),

  // Add/update a key/value pair. Throws an error is the node is not the 
  // leader.
  void put(1: string key, 2: string val) throws (1: WatRaftException err),

  // See Figure 2 in the Raft paper for a detailed description of the
  // following functions.
  AEResult append_entries(1: i32 term,
                          2: i32 leader_id,
                          3: i32 prev_log_index,
                          4: i32 prev_log_term,
                          5: list<Entry> entries,
                          6: i32 leader_commit_index),

  RVResult request_vote(1: i32 term,
                        2: i32 candidate_id,
                        3: i32 last_log_index,
                        4: i32 last_log_term),

  // Provided to illustrate how RPCs are implemented in Thrift.
  string debug_echo(1: string msg)
}
