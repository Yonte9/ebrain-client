/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef announcelist_H
#define announcelist_H

#include <thrift/TDispatchProcessor.h>
#include "ebp_proto_types.h"



class announcelistIf {
 public:
  virtual ~announcelistIf() {}
  virtual bool sendlist(const applist& apps) = 0;
};

class announcelistIfFactory {
 public:
  typedef announcelistIf Handler;

  virtual ~announcelistIfFactory() {}

  virtual announcelistIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(announcelistIf* /* handler */) = 0;
};

class announcelistIfSingletonFactory : virtual public announcelistIfFactory {
 public:
  announcelistIfSingletonFactory(const boost::shared_ptr<announcelistIf>& iface) : iface_(iface) {}
  virtual ~announcelistIfSingletonFactory() {}

  virtual announcelistIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(announcelistIf* /* handler */) {}

 protected:
  boost::shared_ptr<announcelistIf> iface_;
};

class announcelistNull : virtual public announcelistIf {
 public:
  virtual ~announcelistNull() {}
  bool sendlist(const applist& /* apps */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _announcelist_sendlist_args__isset {
  _announcelist_sendlist_args__isset() : apps(false) {}
  bool apps;
} _announcelist_sendlist_args__isset;

class announcelist_sendlist_args {
 public:

  announcelist_sendlist_args() {
  }

  virtual ~announcelist_sendlist_args() throw() {}

  applist apps;

  _announcelist_sendlist_args__isset __isset;

  void __set_apps(const applist& val) {
    apps = val;
  }

  bool operator == (const announcelist_sendlist_args & rhs) const
  {
    if (!(apps == rhs.apps))
      return false;
    return true;
  }
  bool operator != (const announcelist_sendlist_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const announcelist_sendlist_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class announcelist_sendlist_pargs {
 public:


  virtual ~announcelist_sendlist_pargs() throw() {}

  const applist* apps;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _announcelist_sendlist_result__isset {
  _announcelist_sendlist_result__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _announcelist_sendlist_result__isset;

class announcelist_sendlist_result {
 public:

  announcelist_sendlist_result() : success(0) {
  }

  virtual ~announcelist_sendlist_result() throw() {}

  bool success;
  applistfailure ouch;

  _announcelist_sendlist_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  void __set_ouch(const applistfailure& val) {
    ouch = val;
  }

  bool operator == (const announcelist_sendlist_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const announcelist_sendlist_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const announcelist_sendlist_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _announcelist_sendlist_presult__isset {
  _announcelist_sendlist_presult__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _announcelist_sendlist_presult__isset;

class announcelist_sendlist_presult {
 public:


  virtual ~announcelist_sendlist_presult() throw() {}

  bool* success;
  applistfailure ouch;

  _announcelist_sendlist_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class announcelistClient : virtual public announcelistIf {
 public:
  announcelistClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  announcelistClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool sendlist(const applist& apps);
  void send_sendlist(const applist& apps);
  bool recv_sendlist();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class announcelistProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<announcelistIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (announcelistProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_sendlist(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  announcelistProcessor(boost::shared_ptr<announcelistIf> iface) :
    iface_(iface) {
    processMap_["sendlist"] = &announcelistProcessor::process_sendlist;
  }

  virtual ~announcelistProcessor() {}
};

class announcelistProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  announcelistProcessorFactory(const ::boost::shared_ptr< announcelistIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< announcelistIfFactory > handlerFactory_;
};

class announcelistMultiface : virtual public announcelistIf {
 public:
  announcelistMultiface(std::vector<boost::shared_ptr<announcelistIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~announcelistMultiface() {}
 protected:
  std::vector<boost::shared_ptr<announcelistIf> > ifaces_;
  announcelistMultiface() {}
  void add(boost::shared_ptr<announcelistIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool sendlist(const applist& apps) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendlist(apps);
    }
    return ifaces_[i]->sendlist(apps);
  }

};



#endif