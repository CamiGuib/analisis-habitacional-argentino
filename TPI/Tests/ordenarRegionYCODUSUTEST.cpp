#include "../definiciones.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;

TEST(ordenarRegionYCODUSUTEST, regionesDistintas) {

    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                {22866, 2020,   3,  317157, 627217, 2,  1, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  40, 0,  1,  3,  1,  2}};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    eph_h th_esperado = {   {22866, 2020,   3,  317157, 627217, 2,  1, 1,  1,  2,  2,  2},
                            {20957, 2020,   3,  313965, 623297, 1,  40, 0,  1,  3,  1,  2},
                            {31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                            {22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};

    eph_i ti_esperado = { {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                          {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                          {20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                          {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                          {31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                          {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                          {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                          {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                          {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                          {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                          {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                          {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                          {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                          {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};


    ASSERT_TRUE(esEncuestaValida(th,ti));
    ASSERT_TRUE(esEncuestaValida(th_esperado,ti_esperado));

    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}

// TEST DE GRUPO


TEST(ordenarRegionYCODUSUTEST, mismaRegion) {

    eph_h th = {{17922,2018,3,329513,639028,1,40,0,1,5,4,2},
                {2140,2018,3,330602,640796,3,40,1,1,4,2,2},
                {7549,2018,3,336594,646969,1,40,1,1,2,2,2}};

    eph_i ti = {{7549,2018,4,0,3,2,42,1,3,3300,8},
                {2140,2018,3,1,3,2,26,1,3,12000,1},
                {7549,2018,3,0,3,1,69,1,2,13600,8},
                {2140,2018,2,0,3,1,62,1,3,14100,3},
                {17922,2018,6,0,3,2,1,0,0,0,10},
                {2140,2018,1,0,3,2,60,1,3,13000,1},
                {17922,2018,5,0,3,2,17,0,0,0,10},
                {17922,2018,2,0,3,2,39,1,3,14000,1},
                {7549,2018,1,0,3,2,89,0,0,7600,10},
                {7549,2018,2,0,3,1,72,1,2,13600,8},
                {17922,2018,4,0,3,2,20,1,3,4000,0},
                {17922,2018,1,0,3,1,51,1,3,14000,1}};

    eph_h th_esperado = {{2140,2018,3,330602,640796,3,40,1,1,4,2,2},
                         {7549,2018,3,336594,646969,1,40,1,1,2,2,2},
                         {17922,2018,3,329513,639028,1,40,0,1,5,4,2}};

    eph_i ti_esperado = { {2140,2018,1,0,3,2,60,1,3,13000,1},
                          {2140,2018,2,0,3,1,62,1,3,14100,3},
                          {2140,2018,3,1,3,2,26,1,3,12000,1},
                          {7549,2018,1,0,3,2,89,0,0,7600,10},
                          {7549,2018,2,0,3,1,72,1,2,13600,8},
                          {7549,2018,3,0,3,1,69,1,2,13600,8},
                          {7549,2018,4,0,3,2,42,1,3,3300,8},
                          {17922,2018,1,0,3,1,51,1,3,14000,1},
                          {17922,2018,2,0,3,2,39,1,3,14000,1},
                          {17922,2018,4,0,3,2,20,1,3,4000,0},
                          {17922,2018,5,0,3,2,17,0,0,0,10},
                          {17922,2018,6,0,3,2,1,0,0,0,10}};

    ASSERT_TRUE(esEncuestaValida(th,ti));
    ASSERT_TRUE(esEncuestaValida(th_esperado,ti_esperado));

    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}