/*
* Filename: geometry_utils.cc
* Created on: June  7, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "geometry_utils.h"

namespace geom {
    double Utils::Distance(Point2D a, Point2D b) {
        return std::sqrt(std::pow(b.GetX() - a.GetX(), 2) + std::pow(b.GetY() - a.GetY(), 2));
    }

    double Utils::PolarAngle(Point2D ref, Point2D a) {
        if (ref == a)
            return 0;

        double angle = std::atan2(a.GetY() - ref.GetY(), a.GetX() - ref.GetX());

        // Ajusta o ângulo em radianos para que fique entre 0 e 2pi
        if (angle < 0) {
            angle += 2 * PI;
        }

        return angle;
    }

    void Utils::CreateRandomPoints(int amount, int min, int max, Vector<Point2D> &points) {
        std::srand(time(nullptr));

        points.Clear();

        for (int i = 0; i < amount; i++) {
            points.PushBack(Point2D(GEN_NUM, GEN_NUM));
        }
    }

    bool Utils::ComparePoints(const Point2D &ref, const Point2D &a, const Point2D &b) {
        double polarAngleA = Utils::PolarAngle(ref, a);
        double polarAngleB = Utils::PolarAngle(ref, b);

        if (polarAngleA < polarAngleB) {
            return true;
        }
        else if (polarAngleA == polarAngleB) {
            if (polarAngleA <= PI / 2)
                return Utils::Distance(ref, a) < Utils::Distance(ref, b);

            else
                return Utils::Distance(ref, a) > Utils::Distance(ref, b);
        }
        return false;
    }

    void Utils::BucketSort(Vector<Point2D> &vector) {
        const unsigned int numBuckets = 10;
        const double maxAngle = 2 * PI;

        Point2D** bucketsPoints = new Point2D*[numBuckets]; // Array de ponteiros para arrays (estouro da piha quando vector.size era maior que 2320)

        for (unsigned int i = 0; i < numBuckets; i++) {
            bucketsPoints[i] = new Point2D[vector.Size()];
        }

        Point2D refPoint = vector[Utils::FindLowestPoint(vector)];

        int *bucketSizes = new int[numBuckets](); // Cria um array preenchido com 0's

        double* polarAngles = new double[vector.Size()];

        for (unsigned int i = 0; i < vector.Size(); i++) {
            polarAngles[i] = Utils::PolarAngle(refPoint, vector[i]);
        }

        // Faz a distribuição das chaves nos baldes
        unsigned int index;
        for (unsigned int i = 0; i < vector.Size(); i++) {
            index = polarAngles[i] / (maxAngle / numBuckets);
            bucketsPoints[index][bucketSizes[index]] = vector[i];
            bucketSizes[index]++;
        }

        // Ordena os elementos em cada balde
        for (unsigned int i = 0; i < numBuckets; i++)
            Utils::InsertionSort(bucketsPoints[i], refPoint, bucketSizes[i]);

        // Junta os trem que foram ordenados
        index = 0;
        for (unsigned int i = 0; i < numBuckets; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                vector[index++] = bucketsPoints[i][j];
            }
        }

        delete[] bucketSizes;
        delete[] polarAngles;
        for (unsigned int i = 0; i < numBuckets; i++) {
            delete[] bucketsPoints[i];
        }
        delete[] bucketsPoints;
    }

    void Utils::InsertionSort(Point2D array[], const Point2D &ref, unsigned int size) {
        int j;
        Point2D point;

        for (unsigned int i = 1; i < size; i++) {
            point = array[i];
            j = i - 1;

            while (j >= 0 and Utils::ComparePoints(ref, point, array[j])) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = point;
        }
    }

    void Utils::InsertionSort(Vector<Point2D> &vector) {
        int j;
        Point2D refPoint = vector[Utils::FindLowestPoint(vector)];
        Point2D point;

        for (unsigned int i = 1; i < vector.Size(); i++) {
            point = vector[i];
            j = i - 1;

            while (j >= 0 and Utils::ComparePoints(refPoint, point, vector[j])) {
                vector[j + 1] = vector[j];
                j--;
            }
            vector[j + 1] = point;
        }
    }

    void Utils::MergeSortedSubarrays(Vector<Point2D> &subvector, const Point2D &ref, int left, int middle, int right) {
        unsigned int firstHalf = middle - left + 1;
        unsigned int secondHalf = right - middle;

        Point2D *leftArray = new Point2D[firstHalf];
        Point2D *rightArray = new Point2D[secondHalf];

        for (unsigned int i = 0; i < firstHalf; i++)
            leftArray[i] = subvector[left + i];

        for (unsigned int j = 0; j < secondHalf; j++)
            rightArray[j] = subvector[middle + 1 + j];

        unsigned int i, j, k;
        i = j = 0;
        k = left;

        while (i < firstHalf and j < secondHalf) {
            if (Utils::ComparePoints(ref, leftArray[i], rightArray[j]))
                subvector[k++] = leftArray[i++];

            else
                subvector[k++] = rightArray[j++];
        }

        while (i < firstHalf)
            subvector[k++] = leftArray[i++];

        while (j < secondHalf)
            subvector[k++] = rightArray[j++];

        delete[] leftArray;
        delete[] rightArray;
    }

    void Utils::MergeSortHelper(Vector<Point2D> &subvector, const Point2D &ref, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2; // Evita overflow para valores de left e right grandes
            Utils::MergeSortHelper(subvector, ref, left, middle);
            Utils::MergeSortHelper(subvector, ref, middle + 1, right);
            Utils::MergeSortedSubarrays(subvector, ref, left, middle, right);
        }
    }

    void Utils::MergeSort(Vector<Point2D> &vector) {
        Point2D refPoint = vector[Utils::FindLowestPoint(vector)];

        Utils::MergeSortHelper(vector, refPoint, 0, vector.Size() - 1);
    }

    unsigned int Utils::FindLowestPoint(Vector<Point2D> &points) {
        int lowest = 0;

        for (unsigned int i = 1; i < points.Size(); i++) {
            if (points[i] < points[lowest])
                lowest = i;
        }
        return lowest;
    }

    int Utils::Clockwise(Point2D &ref, Point2D &a, Point2D &b) {
        // Cross product a x b
        double magnitude = (a.GetX() - ref.GetX()) * (b.GetY() - ref.GetY()) - (a.GetY() - ref.GetY()) * (b.GetX() - ref.GetX());

        if (magnitude > 0)
            return ANTICLOCKWISE;

        else if (magnitude < 0)
            return CLOCKWISE;

        return COLLINEAR;
    }

    bool Utils::IsPolygon(Vector<Point2D> &points) {
        if (points.Size() < 3)
            return false;

        for (unsigned int i = 0; i < points.Size() - 2; i++) {
            if (Utils::Clockwise(points[i], points[i + 1], points[i + 2]) != COLLINEAR)
                return true;
        }
        return false;
    }
}
