// Модуль тестирования

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "globalmap.h"


TEST_CASE( "First_use", "[test]" ) {
    globalMap GM1(50, 7);
    globalMap GM2(40, 6);
    globalMap GM3;


    // Верные
    CHECK ( GM1.getBigMapSize() == 50 );
    CHECK ( GM1.getLocalMapSize() == 7 );

    CHECK ( GM2.getBigMapSize() == 40 );
    CHECK ( GM2.getLocalMapSize() == 6 );

    CHECK ( GM3.getBigMapSize() == 30 );
    CHECK ( GM3.getLocalMapSize() == 5 );

    // Неверные
    CHECK ( GM3.getBigMapSize() == 8 );
    CHECK ( GM3.getLocalMapSize() == 1 );

}
