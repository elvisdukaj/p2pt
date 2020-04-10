/*
This file is part of p2pt.

p2pt is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

p2pt is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with p2pt.  If not, see <http://www.gnu.org/licenses/>.
*/

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <string>
#include <vector>

class Server
{
public:
  int connections() { return 0; }

private:
  std::string mPath;
};

struct ServerDescription
{};

class FakeUDPClient
{
public:
  std::vector<ServerDescription> search() { return {}; };
  void connect(ServerDescription){};
};

SCENARIO("Server can accept from broadcast", "[Server]")
{
  GIVEN("the server")
  {
    Server server;

    WHEN("client send a message in broadcast")
    {
      FakeUDPClient client;
      auto serverLists = client.search();
      REQUIRE(serverLists.size() == 1);
      REQUIRE_NOTHROW(client.connect(serverLists[0]));
      THEN("conncetion is established") { REQUIRE(server.connections() == 1); }
    }
  }
}
