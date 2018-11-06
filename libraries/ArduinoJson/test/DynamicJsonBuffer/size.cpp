// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#include <ArduinoJson/Memory/DynamicJsonBuffer.hpp>
#include <catch.hpp>

using namespace ArduinoJson::Internals;

TEST_CASE("DynamicJsonBuffer::size()") {
  DynamicJsonBuffer buffer;

  SECTION("Initial size is 0") {
    REQUIRE(0 == buffer.size());
  }

  SECTION("Increases after alloc()") {
    buffer.alloc(1);
    REQUIRE(1U <= buffer.size());
    buffer.alloc(1);
    REQUIRE(2U <= buffer.size());
  }

  SECTION("Goes back to 0 after clear()") {
    buffer.alloc(1);
    buffer.clear();
    REQUIRE(0 == buffer.size());
  }
}
