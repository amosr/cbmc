/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#ifndef CPROVER_UTIL_COUT_MESSAGE_H
#define CPROVER_UTIL_COUT_MESSAGE_H

#include "message.h"

class cout_message_handlert:public stream_message_handlert
{
public:
  // all messages go to stdout
  cout_message_handlert();
};

class cerr_message_handlert:public stream_message_handlert
{
public:
  // all messages go to stderr
  cerr_message_handlert();
};

class console_message_handlert:public message_handlert
{
public:
  // level 4 and upwards go to cout, level 1-3 to cerr
  virtual void print(
    unsigned level,
    const std::string &message) override;
};

class gcc_message_handlert:public message_handlert
{
public:
  // aims to imitate the messages gcc prints
  virtual void print(
    unsigned level,
    const std::string &message) override;

  virtual void print(
    unsigned level,
    const std::string &message,
    int sequence_number,
    const source_locationt &location) override;
};

#endif // CPROVER_UTIL_COUT_MESSAGE_H
