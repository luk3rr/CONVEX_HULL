/*
 * Filename: main.cc
 * Created on: June  8, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <SFML/Graphics.hpp>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#include "analyzer.h"
#include "animation_controller.h"
#include "convex_hull.h"
#include "point_2d.h"
#include "utils.h"
#include "vector.h"

void Usage()
{
    std::cout << "FECHO CONVEXO\n" << std::endl;
    std::cout << "  -f, --file <string>   Caminho do arquivo" << std::endl;
    std::cout << "  -r, --random          Gera pontos aleatórios" << std::endl;
    std::cout << "  -p, --points <int>    Número de pontos aleatórios" << std::endl;
    std::cout << "  -g, --graphic         Habilita o modo gráfico" << std::endl;
    std::cout << "  -a, --analyzer        Realiza uma bateria de testes" << std::endl;
    std::cout << "  -h, --help            Mensagem de ajuda" << std::endl;
}

void SfmlUsage()
{
    std::cout << "\n---------------" << std::endl;
    std::cout << "Modo gráfico ativado\nUSAGE:" << std::endl;
    std::cout << "- Click botão direito do mouse:" << std::endl;
    std::cout << "      Ativa o modo de arrastar a tela (não precisa segurar)"
              << std::endl;
    std::cout << "      Click novamente para desativar esse modo" << std::endl;
    std::cout << "- Role a roda do mouse para aumentar ou diminuir o zoom" << std::endl;
    std::cout << "- Executar as animações:" << std::endl;
    std::cout << "      Pressione a tecla 'g' para executar a animação do Graham Scan"
              << std::endl;
    std::cout << "      Pressione a tecla 'j' para executar a animação do "
                 "Jarvis March"
              << std::endl;
    std::cout << "- Pressione a tecla 'q' para fechar a janela de animação"
              << std::endl;
    std::cout << "- DICA:" << std::endl;
    std::cout << "      Enquanto a animação do Graham Scan ou do Jarvis "
                 "estiver rodando o zoom e o arrasto de tela não funcionam ;-;"
              << std::endl;
    std::cout << "      Posicione a tela antes de executar as animações" << std::endl;
    std::cout << "---------------" << std::endl;
}

void MeasureAlgorithms(Vector<geom::Point2D>& points)
{
    Vector<geom::Point2D> convex1, convex2, convex3, convex4;
    Vector<geom::Point2D> copyPoints1, copyPoints2, copyPoints3, copyPoints4;

    for (unsigned int i = 0; i < points.Size(); i++)
    {
        copyPoints1.PushBack(points[i]);
        copyPoints2.PushBack(points[i]);
        copyPoints3.PushBack(points[i]);
        copyPoints4.PushBack(points[i]);
    }

    auto start = std::chrono::high_resolution_clock::now();
    geom::ConvexHull::GrahamScan(copyPoints1, convex1, geom::Utils::MergeSort);

    auto end = std::chrono::high_resolution_clock::now();
    auto duracaoGrahamMerge =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    start = std::chrono::high_resolution_clock::now();
    geom::ConvexHull::GrahamScan(copyPoints2, convex2, geom::Utils::InsertionSort);

    end = std::chrono::high_resolution_clock::now();
    auto duracaoGrahamInsertion =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    start = std::chrono::high_resolution_clock::now();
    geom::ConvexHull::GrahamScan(copyPoints3, convex3, geom::Utils::BucketSort);

    end = std::chrono::high_resolution_clock::now();
    auto duracaoGrahamBucket =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    start = std::chrono::high_resolution_clock::now();
    geom::ConvexHull::JarvisMarch(copyPoints4, convex4);

    end = std::chrono::high_resolution_clock::now();
    auto duracaoJarvis =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    std::cout << "FECHO CONVEXO:" << std::endl;
    for (unsigned int i = 0; i < convex4.Size(); i++)
    {
        std::cout << convex4[i].GetX() << "\t" << convex4[i].GetY() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "GRAHAM+MERGESORT: " << duracaoGrahamMerge << std::endl;
    std::cout << "GRAHAM+INSERTION: " << duracaoGrahamInsertion << std::endl;
    std::cout << "GRAHAM+BUCKETSORT: " << duracaoGrahamBucket << std::endl;
    std::cout << "JARVIS: " << duracaoJarvis << std::endl;
};

int main(int argc, char* argv[])
{
    bool useRandom, useGraph, useInterative, useAnalyzer, run;
    useRandom = useGraph = useAnalyzer = false;
    useInterative = run = true;

    int         numRandomPoints = 15;
    std::string filePath;

    const char* const shortOptions  = "f:ghp:ra";
    const option      longOptions[] = { { "file", required_argument, nullptr, 'f' },
                                        { "graphic", no_argument, nullptr, 'g' },
                                        { "help", required_argument, nullptr, 'h' },
                                        { "points", required_argument, nullptr, 'p' },
                                        { "random", no_argument, nullptr, 'r' },
                                        { "analyzer", no_argument, nullptr, 'a' },
                                        { nullptr, 0, nullptr, 0 } };

    int opt;
    int optIndex;
    while ((opt = getopt_long(argc, argv, shortOptions, longOptions, &optIndex)) != -1)
    {
        switch (opt)
        {
            case 'f':
                filePath      = optarg;
                useInterative = false;
                break;

            case 'r':
                useRandom   = true;
                useAnalyzer = false;
                break;

            case 'p':
                numRandomPoints = std::stoi(optarg);
                break;

            case 'h':
                Usage();
                return EXIT_SUCCESS;

            case 'g':
                useGraph = true;
                break;

            case 'a':
                useAnalyzer = true;
                run = useRandom = useGraph = false;
                break;

            default:
                Usage();
                return EXIT_FAILURE;
        }
    }

    Vector<geom::Point2D> points;

    if (useRandom)
    {
        geom::Utils::CreateRandomPoints(numRandomPoints, 0, numRandomPoints, points);
        if (geom::Utils::IsPolygon(points))
        {
            MeasureAlgorithms(points);
        }
        else
        {
            std::cout << "Erro: O conjunto de pontos gerados não forma um "
                         "polígono válido"
                      << std::endl;
        }
    }
    else
    {
        while (run)
        {
            if (useInterative)
            {
                std::string cmd, substring;
                std::cout << "Digite: 'fecho caminho/arquivo/entrada' ou "
                             "apenas 'caminho/arquivo/entrada'.\nPressione "
                             "ENTER ou digite 'EXIT', 'exit' para fechar."
                          << std::endl;
                std::getline(std::cin, cmd);

                if (cmd.empty() or cmd == "EXIT" or cmd == "exit")
                    break;

                else if (cmd == "HELP" or cmd == "help")
                {
                    Usage();
                    continue;
                }

                std::istringstream iss(cmd);

                iss >> substring;

                if (substring == "fecho")
                    iss >> filePath;

                else
                    filePath = substring;
            }

            std::ifstream file(filePath);

            if (!file.is_open())
            {
                std::cout << "Erro: Não foi possível ler o arquivo '" << filePath << "'"
                          << std::endl;
                return EXIT_FAILURE;
            }
            std::cout << "Arquivo aberto: '" << filePath << "'" << std::endl;

            int a, b;
            while (file >> a >> b)
            {
                points.PushBack(geom::Point2D(a, b));
            }

            if (geom::Utils::IsPolygon(points))
            {
                MeasureAlgorithms(points);
            }
            else
            {
                std::cout << "Erro: O conjunto de pontos não forma um polígono válido"
                          << std::endl;
                return EXIT_FAILURE;
            }

            if (!useInterative)
                break;
        }
    }

    if (useAnalyzer)
    {
        Analyzer::Analysis();
    }

    if (useGraph)
    {
        SfmlUsage();
        AnimationController anim;
        anim.Start(points);
    }

    return EXIT_SUCCESS;
}
