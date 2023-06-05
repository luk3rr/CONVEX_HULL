/*
* Filename: analyzer.h
* Created on: June 12, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "convex_hull.h"
#include "vector.h"
#include "point_2d.h"

#define ROUNDS 10 // Número de testes
#define POINTS_MAX_AMOUNT 2000
#define GAP_BETWEEN_TESTS 100
#define TESTS_AMOUNT POINTS_MAX_AMOUNT/GAP_BETWEEN_TESTS
#define SIN_CICLES 1000000

class Analyzer {
    private:
        static double m_timeGrahamMerge[TESTS_AMOUNT][ROUNDS];
        static double m_timeGrahamInsertion[TESTS_AMOUNT][ROUNDS];
        static double m_timeGrahamBucket[TESTS_AMOUNT][ROUNDS];
        static double m_timeJarvis[TESTS_AMOUNT][ROUNDS];
        static double m_timeAverage[TESTS_AMOUNT][5];

        /**
        @brief Função de carga, ou seja, ela é utilizada para aumentar o tempo de execução de outras funções, de forma
        que esse tempo esteja próximo de segundos
        */
        static void DummyTime();

        /**
        @brief Calcula a média dos tempos armazenados
        */
        static void TimeAverage();

        /**
        @brief Gera um gráfico de linha com os dados de avaliação armazenados nos atributos desta classe
        */
        static void PlotAnalysis();

    public:
        /**
        @brief Responsável pela avaliação do tempo de execução dos métodos da classe ConvexHull
        */
        static void Analysis();
};

#endif // ANALYZER_H_
