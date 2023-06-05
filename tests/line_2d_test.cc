/*
* Filename: line_2d_test.cc
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "doctest.h"
#include "line_2d.h"

TEST_CASE("Overload operador de igualdade") {
    geom::Line2D r1 = geom::Line2D(1, 1, 4, 4);
    geom::Line2D r2 = geom::Line2D(1, 2, 3, 4);
    geom::Line2D r3 = geom::Line2D(1, 1, 4, 4);

    SUBCASE("Pontos iguais") {
        CHECK(r1 == r3);
        CHECK(r3 == r1);
    }

    SUBCASE("Pontos diferentes") {
        CHECK(!(r1 == r2));
    }
}
