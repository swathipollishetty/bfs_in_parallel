/**********************************************************************
filename: naive/bfs.cpp
author: onesuper
email: onesuperclark@gmail.com

the single-core implemenation of bfs algorithm

***********************************************************************/

#include <stdio.h>
#include <deque>
#include <sys/time.h>



float bfs(void) 
{
	 struct timeval start, end;
	 float time_used;
	 std::deque<unsigned int> current;

	 gettimeofday(&start, 0);

	 // visiting the source node now
	 color[source_node_no] = GREY;
	 current.push_back(source_node_no);
	 cost[source_node_no] = 0;
	 
	 unsigned int index;
	 while(!current.empty()) {
		  // dequeue
		  index = current.front();
		  current.pop_front();
		  
		  // put all its neighbours in the current queue
		  for (int i = node_list[index].start;
			   i < (node_list[index].start + node_list[index].edge_num);
			   i ++) {
			   unsigned int id = edge_list[i].dest;
			   //unsigned int weight = edge_list[i].cost;
			   
			   if (color[id] == WHITE) {
					cost[id] = cost[index] + 1; // expand the cost, assuming all the edge cost is 1
					current.push_back(id);
					color[id] = GREY;

			   } // only if its neighbour is has not been visited
		  }
		  //visit
		  color[index] = BLACK;
		  
	 }
	 
	 gettimeofday(&end, 0);
	 time_used = 1000000 * (end.tv_sec - start.tv_sec) +
		  end.tv_usec - start.tv_usec;
	 time_used /= 1000000;
	 printf("used time: %f\n", time_used);
	 
	 return time_used;
	 
}
