/*
* Filename: convex_hull.cc
* Created on: June  7, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "convex_hull.h"

namespace geom {
    void ConvexHull::GrahamScan(Vector<Point2D> &points, Vector<Point2D> &convex, void (*SortFunc)(Vector<Point2D>&)) {
        SortFunc(points);

        convex.Clear();

        int clockwise;

        convex.PushBack(points[0]);
        convex.PushBack(points[1]);

        for (unsigned int i = 2; i < points.Size(); i++) {
            while (convex.Size() > 2) {
                clockwise = Utils::Clockwise(convex[convex.Size() - 2], convex[convex.Size() - 1], points[i]);

                if (clockwise != ANTICLOCKWISE) {
                    convex.PopBack();
                    continue;
                }
                break;
            }
            convex.PushBack(points[i]);
        }
        convex.PushBack(points[0]);
    }

    void ConvexHull::GrahamScan(Vector<Point2D> &points, Vector<Point2D> &convex, void (*SortFunc)(Vector<Point2D>&), AnimationController &anim) {
        SortFunc(points);

        convex.Clear();

        int clockwise;

        convex.PushBack(points[0]);
        convex.PushBack(points[1]);

        for (unsigned int i = 2; i < points.Size(); i++) {
            while (convex.Size() > 2) {
                clockwise = Utils::Clockwise(convex[convex.Size() - 2], convex[convex.Size() - 1], points[i]);

                anim.Refresh(points, convex);

                if (clockwise != ANTICLOCKWISE) {
                    convex.PopBack();
                    continue;
                }
                break;
            }
            convex.PushBack(points[i]);
        }
        convex.PushBack(points[0]);

        anim.Refresh(points, convex);
    }

    void ConvexHull::JarvisMarch(Vector<Point2D> &points, Vector<Point2D> &convex) {
        convex.Clear();

        unsigned int lowestPointIndex = Utils::FindLowestPoint(points);
        Point2D lowestPoint = points[lowestPointIndex];
        int clockwise;

        unsigned int currentPointIndex = lowestPointIndex;
        unsigned int nextPointIndex;

        do {
            convex.PushBack(points[currentPointIndex]);

            nextPointIndex = (currentPointIndex + 1) % points.Size();

            for (unsigned int i = 0; i < points.Size(); i++) {
                clockwise = Utils::Clockwise(points[currentPointIndex], points[i], points[nextPointIndex]);

                if (clockwise == ANTICLOCKWISE) {
                    nextPointIndex = i;
                }
            }
            currentPointIndex = nextPointIndex;
        } while (currentPointIndex != lowestPointIndex);

        convex.PushBack(lowestPoint);
    }

    void ConvexHull::JarvisMarch(Vector<Point2D> &points, Vector<Point2D> &convex, AnimationController &anim) {
        convex.Clear();

        unsigned int lowestPointIndex = Utils::FindLowestPoint(points);
        Point2D lowestPoint = points[lowestPointIndex];
        int clockwise;

        unsigned int currentPointIndex = lowestPointIndex;
        unsigned int nextPointIndex;

        do {
            convex.PushBack(points[currentPointIndex]);

            anim.Refresh(points, convex);

            nextPointIndex = (currentPointIndex + 1) % points.Size();

            for (unsigned int i = 0; i < points.Size(); i++) {
                clockwise = Utils::Clockwise(points[currentPointIndex], points[i], points[nextPointIndex]);

                anim.Refresh(points, convex, points[i]);

                if (clockwise == ANTICLOCKWISE)
                    nextPointIndex = i;
            }

            currentPointIndex = nextPointIndex;
        } while (currentPointIndex != lowestPointIndex);

        convex.PushBack(lowestPoint);
        anim.Refresh(points, convex);
    }
}
