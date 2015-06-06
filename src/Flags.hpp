
#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <string>

class Flags
{
 public:
  static Flags& get()
  {
    static Flags instance;
    return instance;
  }

  enum OperationMode
  {
    CLIENT,
    MIRROR,
    HIDDEN_SERVICE
  };

  enum Command
  {
    CREATE_RECORD
  };

  bool parse(int argc, char** argv);
  OperationMode getMode() const;
  Command getCommand() const;
  bool verbosityEnabled() const;
  std::string getKeyPath() const;
  std::string getMirrorIP() const;

 private:
  Flags() {}
  Flags(Flags const&) = delete;
  void operator=(Flags const&) = delete;

  OperationMode mode_;
  Command command_;
  bool verbosity_;
  std::string keyPath_, mirrorIP_;
};

#endif
