/*
* Filename: analyzer.cc
* Created on: June 12, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "analyzer.h"

double Analyzer::m_timeGrahamMerge[TESTS_AMOUNT][ROUNDS];
double Analyzer::m_timeGrahamInsertion[TESTS_AMOUNT][ROUNDS];
double Analyzer::m_timeGrahamBucket[TESTS_AMOUNT][ROUNDS];
double Analyzer::m_timeJarvis[TESTS_AMOUNT][ROUNDS];
double Analyzer::m_timeAverage[TESTS_AMOUNT][5];

void Analyzer::DummyTime() {
    volatile int __attribute__((unused)) dummy;
    for (int i = 0; i < SIN_CICLES; i++)
        dummy = sin(1);
}

void Analyzer::TimeAverage() {
    std::cout << "Calculando tempos médios de execução..." << std::endl;

    double sum;

    for (int i = 0; i < TESTS_AMOUNT; i++) {
        sum = 0;

        for (int j = 0; j < ROUNDS; j++) {
            sum += Analyzer::m_timeGrahamMerge[i][j];
        }

        Analyzer::m_timeAverage[i][3] = sum / ROUNDS;
    }

    for (int i = 0; i < TESTS_AMOUNT; i++) {
        sum = 0;

        for (int j = 0; j < ROUNDS; j++) {
            sum += Analyzer::m_timeGrahamInsertion[i][j];
        }

        Analyzer::m_timeAverage[i][2] = sum / ROUNDS;
    }

    for (int i = 0; i < TESTS_AMOUNT; i++) {
        sum = 0;

        for (int j = 0; j < ROUNDS; j++) {
            sum += Analyzer::m_timeGrahamBucket[i][j];
        }

        Analyzer::m_timeAverage[i][0] = GAP_BETWEEN_TESTS * (i + 1);
        Analyzer::m_timeAverage[i][1] = sum / ROUNDS;
    }

    for (int i = 0; i < TESTS_AMOUNT; i++) {
        sum = 0;

        for (int j = 0; j < ROUNDS; j++) {
            sum += Analyzer::m_timeJarvis[i][j];
        }

        Analyzer::m_timeAverage[i][4] = sum / ROUNDS;
    }
}

void Analyzer::PlotAnalysis() {
    Analyzer::TimeAverage();

    std::ofstream data("data.dat");
    std::cout << "Organizando dados..." << std::endl;

    for (int i = 0; i < TESTS_AMOUNT; i++) {
        // QUANTIDADE_PONTOS - MEDIA_TEMPO_GRAHAM_MERGE - MEDIA_TEMPO_GRAHAM_INSERTION - MEDIA_TEMPO_GRAHAM_BUCKET - MEDIA_TEMPO_JARVIS
        data << Analyzer::m_timeAverage[i][0] << " "
             << Analyzer::m_timeAverage[i][1] << " "
             << Analyzer::m_timeAverage[i][2] << " "
             << Analyzer::m_timeAverage[i][3] << " "
             << Analyzer::m_timeAverage[i][4] << " "
             << std::endl;
    }

    data.close();

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Tempo execução algoritmos de fecho convexo'\n");
        fprintf(gnuplotPipe, "set xlabel 'Quantidade de pontos'\n");
        fprintf(gnuplotPipe, "set ylabel 'Tempo para encontrar o fecho convexo (s)'\n");
        fprintf(gnuplotPipe, "set terminal png\n");
        fprintf(gnuplotPipe, "set output 'grafico.png'\n");
        fprintf(gnuplotPipe, "plot 'data.dat' using 1:2 with lines title 'Graham+Merge', ");
        fprintf(gnuplotPipe, "'data.dat' using 1:3 with lines title 'Graham+Insertion', ");
        fprintf(gnuplotPipe, "'data.dat' using 1:4 with lines title 'Graham+Bucket', ");
        fprintf(gnuplotPipe, "'data.dat' using 1:5 with lines title 'Jarvis'\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);
        std::cout << "Gráfico gerado" << std::endl;
    }
    else {
        std::cerr << "ERRO ao executar o gnuplot" << std::endl;
    }
}

void Analyzer::Analysis() {
    Vector<geom::Point2D> points, convex;
    unsigned int pointsAmount;

    std::cout << "Testando Graham+Merge..." << std::endl;

    for (int i = 0; i < TESTS_AMOUNT; i++) {

        pointsAmount = GAP_BETWEEN_TESTS * (i + 1);
        std::cout << "\rQuantidade de pontos: " << pointsAmount << std::flush;

        for (int j = 0; j < ROUNDS; j++) {
            geom::Utils::CreateRandomPoints(pointsAmount, 0, pointsAmount, points);

            auto start = std::chrono::high_resolution_clock::now();

            Analyzer::DummyTime();
            geom::ConvexHull::GrahamScan(points, convex, geom::Utils::MergeSort);
            Analyzer::DummyTime();

            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

            Analyzer::m_timeGrahamMerge[i][j] = time.count(); // Tempo em segundos
        }
    }

    std::cout << std::endl;

    std::cout << "Testando Graham+Insertion..." << std::endl;

    for (int i = 0; i < TESTS_AMOUNT; i++) {

        pointsAmount = GAP_BETWEEN_TESTS * (i + 1);
        std::cout << "\rQuantidade de pontos: " << pointsAmount << std::flush;

        for (int j = 0; j < ROUNDS; j++) {
            geom::Utils::CreateRandomPoints(pointsAmount, 0, pointsAmount, points);

            auto start = std::chrono::high_resolution_clock::now();

            Analyzer::DummyTime();
            geom::ConvexHull::GrahamScan(points, convex, geom::Utils::InsertionSort);
            Analyzer::DummyTime();

            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

            Analyzer::m_timeGrahamInsertion[i][j] = time.count(); // Tempo em segundos
        }
    }

    std::cout << std::endl;

    std::cout << "Testando Graham+Bucket..." << std::endl;

    for (int i = 0; i < TESTS_AMOUNT; i++) {

        pointsAmount = GAP_BETWEEN_TESTS * (i + 1);
        std::cout << "\rQuantidade de pontos: " << pointsAmount << std::flush;

        for (int j = 0; j < ROUNDS; j++) {
            geom::Utils::CreateRandomPoints(pointsAmount, 0, pointsAmount, points);

            auto start = std::chrono::high_resolution_clock::now();

            Analyzer::DummyTime();
            geom::ConvexHull::GrahamScan(points, convex, geom::Utils::BucketSort);
            Analyzer::DummyTime();

            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

            Analyzer::m_timeGrahamBucket[i][j] = time.count(); // Tempo em segundos
        }
    }

    std::cout << std::endl;

    std::cout << "Testando Jarvis March..." << std::endl;

    for (int i = 0; i < TESTS_AMOUNT; i++) {

        pointsAmount = GAP_BETWEEN_TESTS * (i + 1);
        std::cout << "\rQuantidade de pontos: " << pointsAmount << std::flush;

        for (int j = 0; j < ROUNDS; j++) {
            geom::Utils::CreateRandomPoints(pointsAmount, 0, pointsAmount, points);

            auto start = std::chrono::high_resolution_clock::now();

            Analyzer::DummyTime();
            geom::ConvexHull::JarvisMarch(points, convex);
            Analyzer::DummyTime();

            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

            Analyzer::m_timeJarvis[i][j] = time.count(); // Tempo em segundos
        }
    }

    std::cout << std::endl;

    Analyzer::PlotAnalysis();
}
