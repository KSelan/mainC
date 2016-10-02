#ifndef GRAPH_TEST_H
#define GRAPH_TEST_H

#include "graph.h"

void run_test(std::stringstream & s)
{
    Graph<int> graph4(4);
    Graph<int> graph5(5);
    Graph<int> graph6(6);
    Graph<int> graph3(3);
    Graph<int> graph2(2);
    Graph<int> graph1(1);

    graph4.add(&graph6);
    graph4.add(&graph3);
    graph3.add(&graph2);
    graph6.add(&graph5);
    graph6.add(&graph5);
    graph2.add(&graph6);
    graph2.add(&graph1);
    graph5.add(&graph1);

	graph4.display(s);
}

#endif // GRAPH_TEST_H

