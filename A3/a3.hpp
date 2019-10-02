#ifndef A3_HPP
#define A3_HPP

#include "Maze.hpp"

// implement your function distance
int distance(Maze& maze, int sx, int sy, int fx, int fy) {
		maze.mark(sx,sy);
		int boole=0;
		int min=1234641;
		if(sx==fx&&sy==fy){
			maze.unmark(sx,sy);
			return 0; 
		} 
		// if((maze.is_visited(sx,sy+1))&&(maze.is_visited(sx+1,sy))&&
		// 	(maze.is_visited(sx,sy-1))&&(maze.is_visited(sx-1,sy))) {
		// 	maze.unmark(sx,sy);
		// 	return 1640;
		// }  
		if(!maze.is_visited(sx,sy+1) && maze.is_open(sx,sy+1)){ //right
			int num=distance(maze,sx,sy+1,fx,fy);
			boole=1;
			if(num<min){
				min=num;
			}
		} 
		if(!maze.is_visited(sx+1,sy) && maze.is_open(sx+1,sy)){//down
			int num=distance(maze,sx+1,sy,fx,fy);
			boole=1;
			if(num<min){
				min=num;
			} 
		}
		if(!maze.is_visited(sx,sy-1)&&maze.is_open(sx,sy-1)){ //left
			int num=distance(maze,sx,sy-1,fx,fy);
			boole=1;
			if(num<min){
				min=num;
			}
		}     
		
		if(!maze.is_visited(sx-1,sy)&&maze.is_open(sx-1,sy)){//up
			boole=1;
			int num=distance(maze,sx-1,sy,fx,fy);
			if(num<min){
				min=num;
			}
		}
		maze.unmark(sx,sy);
		if(!boole){
			//maze.unmark(sx,sy);
			return 1234640;
		}
		
		return 1+min;   
} // distance

#endif // A3_HPP
