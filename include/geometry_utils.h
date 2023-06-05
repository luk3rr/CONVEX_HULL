/*
* Filename: geometry_utils.h
* Created on: June  7, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <numbers>

#include "point_2d.h"
#include "vector.h"

#define CLOCKWISE 1
#define ANTICLOCKWISE -1
#define COLLINEAR 0
#define GEN_NUM std::rand() % (max - min + 1) + min // Gera um número no intervalo [min, max]
#define PI std::numbers::pi

namespace geom {
    class Utils {
        private:
            /**
            @brief Une os vetores ordenados
            @param subvector Subvector que será ordenado
            @param ref Ponto de referência para os cálculos de ângulo polar e distância
            @param left, middle, right Índices do início, meio e fim do subvector
            */
            static void MergeSortedSubarrays(Vector<Point2D> &subvector, const Point2D &ref, int left, int middle, int right);

            /**
            @brief Auxilia o algoritmo de MergeSort dividindo o vector de forma recursiva
            @param subvector Subvector que será ordenado
            @param ref Ponto de referência para os cálculos de ângulo polar e distância
            @param left, right Índices de onde começa e termina o subvector
            */
            static void MergeSortHelper(Vector<Point2D> &subvector, const Point2D &ref, int left, int right);

        public:
            /**
            @brief Dado dois pontos, calcula a distância entre eles
            @param a, b Pontos que serão utilizados no cálculo da distância
            @return Double que representa a distância entre os dois pontos
            */
            static double Distance(Point2D a, Point2D b);

            /**
            @brief Calcula o ângulo polar do ponto 'a'
            @param ref Ponto de referência para o cálculo do ângulo polar
            @param a Ponto que será utilizando no cálculo do ângulo
            @return Double com o valor do ângulo em radianos
            */
            static double PolarAngle(Point2D ref, Point2D a);

            /**
            @brief Cria um conjunto pseudo-aleatório de pontos no plano
            @param amount Quantidade de pontos que devem ser criados
            @param min, max Valores mínimos e máximos para as coordenadas X,Y dos pontos
            @param points Vetor onde serão armazenados os pontos gerados
            */
            static void CreateRandomPoints(int amount, int min, int max, Vector<Point2D> &points);

            /**
            @brief Verifica se o ângulo polar do ponto 'a' é menor do que o ponto polar do ponto 'b'
            Para pontos colineares, leva em consideração a menor distância quando o ângulo é menor ou igual a 90°
            @param ref Ponto de referência para os cálculos de ângulo polar e distância
            @param a, b Pontos que serão comparados
            @return True se o ângulo polar de 'a' for menor que o de 'b', False caso contrário
            */
            static bool ComparePoints(const Point2D &ref, const Point2D &a, const Point2D &b);

            /**
            @brief Implementação do algoritmo Bucket Sort para ordenar um vector de pontos no plano cartesiano de acordo
            com o ângulo polar
            @param vector Vetor de pontos que será ordenado
            */
            static void BucketSort(Vector<Point2D> &vector);

            /**
            @brief Implementação do algoritmo Insertion Sort para ordenar um vector de pontos no plano cartesiano de
            acordo com o ângulo polar
            @param array Array de pontos que será ordenado
            @param ref Ponto de referência para os cálculos de ângulo polar e distância
            @param size Tamanho do array
            */
            static void InsertionSort(Point2D array[], const Point2D &ref, unsigned int size);

            /**
            @brief Implementação do algoritmo Insertion Sort para ordenar um vector de pontos no plano cartesiano de
            acordo com o ângulo polar
            @param vector Vetor de pontos que será ordenado
            */
            static void InsertionSort(Vector<Point2D> &vector);

            /**
            @brief Implementação do algoritmo Merge Sort para ordenar um vector de pontos no plano cartesiano de
            acordo com o ângulo polar
            @param vector Vetor de pontos que será ordenado
            */
            static void MergeSort(Vector<Point2D> &vector);

            /**
            @brief Dado um conjunto de pontos, encontra o que tem a coordenada Y mais baixa. Em caso de empate, o ponto
            que tiver a menor coordenada X será o escolhido
            @param points Conjunto de pontos na qual a busca será realizada
            @return O índice do ponto mais baixo
            */
            static unsigned int FindLowestPoint(Vector<Point2D> &points);

            /**
            @brief Determina se o vetor ref->b está no sentido do relógio em relação ao vetor ref->a
            @param ref, a, b Pontos que serão utilizados no cálculo
            @return CLOCKWISE, ANTICLOCKWISE ou COLLINEAR
            */
            static int Clockwise(Point2D &ref, Point2D &a, Point2D &b);

            /**
            @brief Determina se um conjunto de pontos forma um polígono válido
            @param points Vector de pontos que serão avaliados
            @return True se o conjunto forma um polígono válido, False caso contrário
            */
            static bool IsPolygon(Vector<Point2D> &points);
    };
}
