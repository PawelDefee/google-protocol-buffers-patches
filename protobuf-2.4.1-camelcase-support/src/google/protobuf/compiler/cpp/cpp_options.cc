// Copyright 2012 Pawel Defée.  All rights reserved.
// Author: pawel.defee@iki.fi (Pawel Defée)

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/compiler/cpp/cpp_options.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace cpp {

void Options::setOptions(const vector<pair<string,string> >* options) {

  // -----------------------------------------------------------------
  // parse generator options

  // If the dllexport_decl option is passed to the compiler, we need to write
  // it in front of every symbol that should be exported if this .proto is
  // compiled into a Windows DLL.  E.g., if the user invokes the protocol
  // compiler as:
  //   protoc --cpp_out=dllexport_decl=FOO_EXPORT:outdir foo.proto
  // then we'll define classes like this:
  //   class FOO_EXPORT Foo {
  //     ...
  //   }
  // FOO_EXPORT is a macro which should expand to __declspec(dllexport) or
  // __declspec(dllimport) depending on what is being compiled.

  // If the use_lower_case option is passed to the compiler,
  // we will generate code as follows for its values:
  // * value equal to true: default Google behavior, force lowercase
  // * value equal to false: do not convert camelCase to lowercase

  for (int i = 0; i < (*options).size(); i++) {
    if ((*options)[i].first == "dllexport_decl") {
      dllexport_decl_ = (*options)[i].second;
    } else if ((*options)[i].first == "use_lower_case") {
      if( (*options)[i].second == "false" ) {
        use_lower_case_ = false;
      } else if( (*options)[i].second == "true" ) {
        use_lower_case_ = true;
      } else {
        error_ = "Unknown generator option value: " + (*options)[i].second + " for option: " + (*options)[i].first;
      }
    } else {
      error_ = "Unknown generator option: " + (*options)[i].first;
    }
  }
    }

Options::Options()
  : use_lower_case_(true) {}

Options::~Options() {}

const string& Options::error() const {
  return error_;
}

const string& Options::dllexport_decl() const {
  return dllexport_decl_;
}

const bool Options::use_lower_case() const {
  return use_lower_case_;
}

Options* options_ = NULL;
GOOGLE_PROTOBUF_DECLARE_ONCE(options_once_init_);

void ShutdownOptions() {
  delete options_;
  options_ = NULL;
}

void InitOptions() {
  options_ = new Options;
  internal::OnShutdown(&ShutdownOptions);
}

Options* Options::options() {
  ::google::protobuf::GoogleOnceInit(&options_once_init_,
                 &InitOptions);
  return options_;
}


}  // namespace cpp
}  // namespace compiler
}  // namespace protobuf
}  // namespace google
