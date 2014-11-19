// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "announcelist.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ;

class announcelistHandler : virtual public announcelistIf {
 public:
  announcelistHandler() {
    // Your initialization goes here
  }

  bool sendlist(const applist& apps) {
    // Your implementation goes here
    printf("sendlist\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<announcelistHandler> handler(new announcelistHandler());
  shared_ptr<TProcessor> processor(new announcelistProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
