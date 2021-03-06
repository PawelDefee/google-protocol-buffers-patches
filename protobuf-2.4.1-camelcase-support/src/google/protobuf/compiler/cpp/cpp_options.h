// Copyright 2012 Pawel Defée.  All rights reserved.
// Author: pawel.defee@iki.fi (Pawel Defée)

#ifndef PROTOBUF_COMPILER_CPP_OPTIONS_H__
#define PROTOBUF_COMPILER_CPP_OPTIONS_H__

#include <map>
#include <string>
#include <vector>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/descriptor.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace cpp {

class Options {
 public:

  // This class is a singleton.  The caller must not delete the object.
  static Options* options();

  explicit Options();
  ~Options();

  // Sets options from a string
  void setOptions(const vector< pair<string,string> >* options);

  // Returns a possible error from parsing
  const string& error() const;

  // Return the dllexport_decl option.
  const string& dllexport_decl() const;

  // Return the use_lower_case option.
  const bool use_lower_case() const;

 private:

  // error_ holds any error messages from parsing
  string error_;

  // options
  string dllexport_decl_;
  bool use_lower_case_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(Options);
};

}  // namespace cpp
}  // namespace compiler
}  // namespace protobuf

}  // namespace google
#endif  // PROTOBUF_COMPILER_CPP_OPTIONS_H__
