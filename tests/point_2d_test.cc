/*
* Filename: point_2d_test.cc
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "doctest.h"
#include "point_2d.h"

TEST_CASE("Overload operador de igualdade") {
    geom::Point2D A = geom::Point2D(1, 5);
    geom::Point2D B = geom::Point2D(1, 3);
    geom::Point2D C = geom::Point2D(1, 5);

    SUBCASE("Pontos iguais") {
        CHECK(A == C);
        CHECK(C == A);
    }

    SUBCASE("Pontos diferentes") {
        CHECK(!(A == B));
    }
}

TEST_CASE("Overload operador menor") {
    geom::Point2D A = geom::Point2D(1, 5);
    geom::Point2D B = geom::Point2D(1, 3);
    geom::Point2D C = geom::Point2D(1, 5);
    geom::Point2D D = geom::Point2D(2, -1);
    geom::Point2D E = geom::Point2D(-1, -1);

    SUBCASE("Pontos iguais") {
        CHECK(!(A < C));
    }

    SUBCASE("Pontos diferentes") {
        CHECK(!(A < B));
        CHECK(D < B);
        CHECK(E < D);
    }
}

TEST_CASE("Overload operador menor ou igual") {
    geom::Point2D A = geom::Point2D(1, 5);
    geom::Point2D B = geom::Point2D(1, 3);
    geom::Point2D C = geom::Point2D(1, 5);
    geom::Point2D D = geom::Point2D(2, -1);
    geom::Point2D E = geom::Point2D(-1, -1);

    SUBCASE("Pontos iguais") {
        CHECK(A <= C);
    }

    SUBCASE("Pontos diferentes") {
        CHECK(!(A <= B));
        CHECK(D <= B);
        CHECK(E <= D);
    }
}
